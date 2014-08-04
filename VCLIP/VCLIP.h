enum VCLIP_RETURN
{
	VC_CONTINUE,
	VC_PENETRATION_EF,
	VC_PENETRATION_VF,
	VC_DONE_VV,
	VC_DONE_VE,
	VC_DONE_VF,
	VC_DONE_EE
};
template <class U> class VCLIP
{
public:
	TCHAR msgbox_tchar[64];
	
	VERTEX<U> * V1final;
	EDGE<U>   * E1final;
	FACE<U>   * F1final;
	VERTEX<U> * V2final;
	EDGE<U>   * E2final;
	FACE<U>   * F2final;

	bool flipped;
	bool track;

	GEOMETRY_SET<U> S1;
	GEOMETRY_SET<U> S2;

	VCLIP()
	{ 
		track = true;
	}

	Vector3 x;
	float penetration;

	std::vector<FACE<U>*> allFaces;

	void algorithm( POLYHEDRON<U> * poly1, POLYHEDRON<U> * poly2 );
	float D( FACE<U>* F, VERTEX<U>* V );
	float D( FACE<U>* F, const Vector3 &y );
	float D( PLANE<U>* P, VERTEX<U>* V );
	bool Dprime( EDGE<U>* E, VERTEX<U>* V, float lambda );
	bool Dprime( EDGE<U>* E, FACE<U>* F, float lambda );
	template <class T, class W> bool clipEdge( EDGE<U>* E, T* X, const std::vector<W*> &S, float &lambdaMin, float &lambdaMax, W* &NMin, W* &NMax );
	VCLIP_RETURN handleLocalMin( VERTEX<U>* V, FACE<U>* F );
	VCLIP_RETURN VVstate   ( VERTEX<U> * V1, VERTEX<U> * V2 );
	VCLIP_RETURN VVstateSub( VERTEX<U> * V1, VERTEX<U> * V2 );
	VCLIP_RETURN VEstate   ( VERTEX<U>* V, EDGE<U> * E );
	VCLIP_RETURN VFstate   ( VERTEX<U>* V, FACE<U>* F );
	VCLIP_RETURN EEstate   ( EDGE<U>* E1, EDGE<U> * E2 );
	VCLIP_RETURN EEstateSub( EDGE<U>* E1, EDGE<U> * E2 );
	VCLIP_RETURN EFstate   ( EDGE<U>* E, FACE<U>* F );
	bool         Vpenetrate( VERTEX<U>* V, POLYHEDRON<U>* poly );
	bool         Epenetrate( EDGE<U>*   E, POLYHEDRON<U>* poly );
	bool         Fpenetrate( FACE<U>*   F, POLYHEDRON<U>* poly );
	void         CheckNeighbors( VERTEX<U>* V, GEOMETRY_SET<U> &S, POLYHEDRON<U>* poly );
	void         CheckNeighbors( EDGE  <U>* E, GEOMETRY_SET<U> &S, POLYHEDRON<U>* poly );
	void         CheckNeighbors( FACE  <U>* F, GEOMETRY_SET<U> &S, POLYHEDRON<U>* poly );
};

#include "VCLIP_source.h"

/*
swprintf_s( msgbox_tchar, _T("%d"), GetLastError());
MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
*/
/*

class DERIVED_POLYHEDRON
{


	// virtuals
	void collision( POLYHEDRON * polyhedron );
	bool interact( INTERACT_TYPE type, const Vector3 &O, const Vector3 &vn, float &dist );
	void render();
	void physics();


}



void DERIVED_POLYHEDRON::collision( POLYHEDRON * polyhedron )
{
}

bool DERIVED_POLYHEDRON::interact( INTERACT_TYPE type, const Vector3 &O, const Vector3 &vn, float &dist )
{
	return false;
}

void DERIVED_POLYHEDRON::render()
{
}

void DERIVED_POLYHEDRON::physics()
{
}


*/