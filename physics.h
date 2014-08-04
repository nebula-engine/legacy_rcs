void physics( GAME * game )
{
	// calculate time step


	// for each object
	// apply forces


	// for each pair
	// do collisions


	// for each object
	// apply velocity

}

/*
void physics_plane_intersect( float * d, float * r, float * v, float * n, float c )
{
     float k = (c - vector_dot(r,n))/vector_dot(v,n);
     d[0] = r[0] + k*v[0];
     d[1] = r[1] + k*v[1];
     d[2] = r[2] + k*v[2];
}
*/
/*
float physics_plane_distance( float * d, float * r, float * n, float c )
{
     return ( c - vector_dot(r,n));
}


*/