// game
//int game_create          ( GAME *g , int org_lvl );
//int game_create_recursive( int current_level, int * tag, int, ORG_MAP_LEVEL *, int *, int, GAME * g );

// gl_primitive
void client_gl_basic_plane_XZ();
void client_gl_basic_cube();

// interact
int interact_detect_sub( INTERACT_TYPE interact_type, GAME * g, float &dist, OBJECT * o, Vector3 O, Vector3 v, std::vector<OBJECT*> * thing_pointer, std::vector<INTERACT_HIT> &hits );
// lookup
MARINE * lookup_marine_tag_2_pointer( GAME * g, TAG tag );
MARINE * lookup_marine_id_2_pointer( GAME * g, int id );

// map
int map_load( GAME * g, std::vector<SPAWN> &spawn );

// math
float math_abs ( float );
template <class T> void cubic_solve( T * Ip, T ** I );

// objective
int objective_create              ( OBJECTIVE * o, MARINE * creator, MARINE * lower, GAME * g );
int objective_create_move_at_level( OBJECTIVE * o, MARINE * creator, MARINE * lower, GAME * g );

// objective_check
int objective_check              ( GAME * g, OBJECTIVE * o );
int objective_check_move_at_level( GAME * g, OBJECTIVE * o );
int objective_check_move         ( GAME * g, OBJECTIVE * o );

// physics
//bool physics_box_ray_hit( float * dist, float * v, float * r, PART * part, RECTANGULAR_PARALLELEPIPED * rp, BOX * box );

// region
int region_assign           ( GAME * g, OBJECT * o );
int region_remove           ( GAME * g, OBJECT * o );
int region_detect_change    ( GAME * g, OBJECT * o );
template <class T> int region_detect_change_all( GAME * g, T object_pointer_vector );
template <class T> int region_assign_all       ( GAME * g, T object_pointer_vector );
int region_initialize       ( GAME * g );
int region_neighbor         ( GAME * g, OBJECT * o, REGION ** region_array );

// vector
/*
float vector_distance  ( float *, float * );
void vector_x_transform( float *, float );
void vector_y_transform( float *, float );
void vector_subtract   ( float *, float *, float * );
void vector_subtract   ( float * a, float * b );
void vector_add         ( float *, float *, float * );
void vector_add         ( float *, float * );
void vector_normalize  ( float *, float * );
void vector_normalize  ( float * a );
void vector_cross      ( float *, float *, float * );
float vector_dot( float * a, float * b );
void vector_scale      ( float *, float *, float );
void vector_scale      ( float *, float );
float vector_magnitude ( float * );
void vector_copy       ( float *, float * );
void vector_projection ( float * a1, float * a, float * b );
void vector_nan_inf    ( const TCHAR * name, float * v, int size );
void vector_project_XY ( float * a, float * b );
float vector_angle     ( float * a, float * b , float * c );
void matrix_vector_multiplication( float * c, float ** a, float * b );
void transformation_matrix( float ** t, float * a, float angle );
void matrix_normalize( float ** a );
void matrix_identity( float ** a );
void vector_multiplication_elementwise( float * a, float * b );
void vector_multiplication_elementwise( float * a, float * b, float * c );
void matrix_add( float ** a, float ** b );
void matrix_zero( float ** a );

// matrix
namespace matrix
{
	template <class T> T determinant( T ** A );

	template <class T> void cofactor( T ** A, T ** C );

	template <class T> T minor_determinant( T ** A, int row, int col );

	template <class T> void transpose( T ** A, T ** AT );

	template <class T> void scale( T ** A, T k );

	template <class T> void inverse( T ** A, T ** invA );

	template <class T> void multiply( T ** C, T ** A, T ** B );

	template <class T> void pns_to_matrix( T ** A, T p, T n, T s );
}
*/

void solveRBC( POLYHEDRON<PART> * poly1, POLYHEDRON<PART> * poly2, const Vector3 &nParam, Vector3 &x, float penetration );
void solveSingleSolid( PART * part, Vector6 J, float penetration );
void solveSingle( PART * part1, PART * part2, Vector6 J1, Vector6 J2, Vector3 n, float penetration );