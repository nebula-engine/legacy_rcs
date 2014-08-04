enum GEOMETRY_FEATURE_TYPE {
	GEOMETRY_FEATURE_TYPE_VERTEX,
	GEOMETRY_FEATURE_TYPE_EDGE, GEOMETRY_FEATURE_TYPE_FACE, GEOMETRY_FEATURE_TYPE_ALL, GEOMETRY_FEATURE_TYPE_NONE };
enum GEOMETRY_TYPE
{
	GEOMETRY_TYPE_CUBE,
	GEOMETRY_TYPE_RECTANGULAR_PARALLELEPIPED,
	GEOMETRY_TYPE_CIRCULAR_CYLINDER
};

template <class U> class VERTEX;
template <class U> class EDGE;
template <class U> class FACE;
template <class U> class POLYHEDRON;

template <class U> class VERTEX
{
public:
	POLYHEDRON<U> * poly;
	
	Vector3 x;
	Vector3 xRel;
	
	std::vector<EDGE<U>*> E;

	VERTEX()
	{
		poly = NULL;
	};
};
template <class U> class EDGE
{
public:
	POLYHEDRON<U>* poly;
	
	VERTEX<U>* h;
	VERTEX<U>* t;
	FACE<U>* F1;
	FACE<U>* F2;
	
	std::vector<VERTEX<U>*> V;
	std::vector<FACE<U>*> F;

	EDGE()
	{
		poly = NULL;
		h = NULL;
		t = NULL;
		F1 = NULL;
		F2 = NULL;
	}
	EDGE( POLYHEDRON<U>* polyParam, VERTEX<U>* hParam, VERTEX<U>* tParam )
	{
		poly = polyParam;
		h = hParam;
		t = tParam;
		F1 = NULL;
		F2 = NULL;
	}

	Vector3 e(float lambda)
	{
		Vector3 ret = (t->x)*(1.0f-lambda) + (h->x)*lambda;
		return ret;
	}

	Vector3 u()
	{
		return ( h->x - t->x );
	}
};
template <class U> class FACE
{
public:
	POLYHEDRON<U> * poly;
	
	Vector3 n;
	Vector3 x; // reference point on face for determining normal of VP(F,E)
	float w;

	std::vector<EDGE<U>*> E;

	FACE()
	{
		poly = NULL;
	}

	void update()
	{
		n = E.at(1)->u().cross(E.at(0)->u());
		n.normalize();
		x = ( E.at(0)->e(0.5f) + E.at(1)->t->x ) * 0.5f;

		w = n.dot(x);
	}
};
template <class U> class PLANE
{
public:
	Vector3 n;
	float w;
	
	PLANE(){}

	PLANE( VERTEX<U>* V, EDGE<U>* E )
	{
		if ( V == E->t )
		{
			n = V->x - E->h->x;
		}
		else if ( V == E->h )
		{
			n = V->x - E->t->x;
		}
		else
		{
			MessageBox(NULL, _T("problem!!!!!!"), NULL, MB_OK);
		}
		n.normalize();
		w = n.dot(V->x);
	}
	PLANE( EDGE<U>* E, VERTEX<U>* V )
	{
		if ( V == E->t )
		{
			n = E->h->x - V->x;
		}
		else
		{
			n = E->t->x - V->x;
		}
		n.normalize();
		w = n.dot(V->x);
	}
	PLANE( EDGE<U>* E, FACE<U> *F )
	{
		n = F->n.cross( E->u() );
		n.normalize();
		w = n.dot( E->h->x );
		if ( ( n.dot( F->x ) - w ) > 0 )
		{
			n *= -1.0f; w *= -1.0f;
		}
	}
	PLANE( FACE<U> *F, EDGE<U> *E )
	{
		n = F->n.cross( E->u() );
		n.normalize();
		w = n.dot( E->h->x );
		if ( ( n.dot( F->x ) - w ) < 0 )
		{
			n *= -1.0f; w *= -1.0f;
		}
	}
	
};
template <class U> class POLYHEDRON
{
public:
	U * parent;
	
	std::vector<VERTEX<U>*> V;
	std::vector<EDGE<U>*>   E;
	std::vector<FACE<U>*>   F;

	bool penetrating;

	VERTEX<U>* VHighlight;
	EDGE<U>*   EHighlight;
	FACE<U>*   FHighlight;

	GEOMETRY_FEATURE_TYPE highlight_type;

	GEOMETRY_TYPE geometry_type;
	
	float m;
	float density;

	// shape, convert to part by calculate_constants
	Matrix3 I;

	// part
	Vector3 offset;

	// part to shape
	Quaternion q;
	

	POLYHEDRON()
	{
		highlight_type = GEOMETRY_FEATURE_TYPE_NONE;

		VHighlight = NULL;
		EHighlight = NULL;
		FHighlight = NULL;

		penetrating = false;
	};


	// construction
	void quad( int a,int b,int c,int d);

	void recalculate_constants();
	void globalize_vertex();
	void render_poly();

	// virtuals
	virtual void collision( POLYHEDRON<U> * polyhedron ){};
	//virtual bool interact( INTERACT_TYPE type, const Vector3 &O, const Vector3 &vn, float &dist ){ return false; };
	virtual void render(){};
	virtual void physics(){};
};
template <class U> class GEOMETRY_SET
{
public:
	std::vector<VERTEX<U>*> V;
	std::vector<EDGE<U>*>   E;
	std::vector<FACE<U>*>   F;

	void clear()
	{
		V.clear();
		E.clear();
		F.clear();
	}
	bool find( VERTEX<U>* Vparam )
	{
		for ( int i = 0; i < V.size(); i++ )
		{
			if ( V.at(i) == Vparam ){ return true; }
		}
		return false;
	}
	bool find( EDGE  <U>* Eparam )
	{
		for ( int i = 0; i < E.size(); i++ )
		{
			if ( E.at(i) == Eparam ){ return true; }
		}
		return false;
	}
	bool find( FACE  <U>* Fparam )
	{
		for ( int i = 0; i < F.size(); i++ )
		{
			if ( F.at(i) == Fparam ){ return true; }
		}
		return false;
	}
};
template <class U> class RECTANGULAR_PARALLELEPIPED: public POLYHEDRON<U>
{
public:
	float a;
	float b;
	float c;

	RECTANGULAR_PARALLELEPIPED(){};
	RECTANGULAR_PARALLELEPIPED( float offset_x, float offset_y, float offset_z, float p, float n, float s, float width, float depth, float height, float rho );
	
	// virtuals
	void collision( POLYHEDRON * polyhedron );
	//bool interact( INTERACT_TYPE type, const Vector3 &O, const Vector3 &vn, float &dist );
	void render();
	void physics();
};
template <class U> class CIRCULAR_CYLINDER: public POLYHEDRON<U>
{
public:
	float r;
	float h;
	CIRCULAR_CYLINDER( float offset_x, float offset_y, float offset_z, float p, float n, float s, float radius, float height, float rho );
};
template <class U> class SQUARE: public POLYHEDRON<U>
{
public:
	float a;
	float b;
	float c;

	SQUARE(){};
	SQUARE( float offset_x, float offset_y, float offset_z, float p, float n, float s, float width, float depth, float height, float rho ){};
	
	int get_point_collision( U * p, float * n, float * r, float * A, float &penetration );

	bool interact( const Vector3 &O, const Vector3 &vn, float &dist );
	void render();
	void collision( POLYHEDRON<U> * polyhedron );
};

#include "POLYHEDRON_source.h"
#include "RECTANGULAR_PARALLELEPIPED_source.h"
#include "CIRCULAR_CYLINDER_source.h"
#include "SQUARE_source.h"
