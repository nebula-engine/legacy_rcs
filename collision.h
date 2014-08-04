

void solveRBC( POLYHEDRON<PART> * poly1, POLYHEDRON<PART> * poly2, const Vector3 &nParam, Vector3 &x, float penetration )
{
	Vector3 r1; // part
	Vector3 r2; // part

	Vector3 n = nParam; // global
	Vector3 n1; // part
	Vector3 n2; // part

	Vector6 J1; // [ global | part ]
	Vector6 J2; // [ global | part ]

	/*
	swprintf_s( msgbox_tchar, _T("solveRBC %p %p"),poly1->parent->object,poly2->parent->object);
	MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
	*/
	
	
	if ( poly1->parent->object->fixed )
	{
		MessageBox(NULL, _T("1"), NULL, MB_OK);
		
		n *= -1.0f;

		n2 = poly2->parent->q * n;

		Vector3 r2 = poly2->parent->q * ( x - poly2->parent->x );

		J2 = Vector6(n,r2.cross(n2));

		solveSingleSolid( poly2->parent, J2, penetration );
	}
	else if ( poly2->parent->object->fixed )
	{
		MessageBox(NULL, _T("2"), NULL, MB_OK);
		
		n1 = poly1->parent->q * n;

		Vector3 r1 = poly1->parent->q * ( x - poly1->parent->x );

		J1 = Vector6(n,r1.cross(n1));

		solveSingleSolid( poly1->parent, J1, penetration );
	}
	else
	{
		n1 = poly1->parent->q * n;

		Vector3 r1 = poly1->parent->q * ( x - poly1->parent->x );

		J1 = Vector6(n,r1.cross(n1));

		//n *= -1.0f;

		n2 = poly2->parent->q * n;

		Vector3 r2 = poly2->parent->q * ( x - poly2->parent->x );

		J2 = Vector6(n,r2.cross(n2));
		/*
		swprintf_s( msgbox_tchar, _T("n  %f %f %f"),n.col[0],n.col[1],n.col[2]);
		MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
		swprintf_s( msgbox_tchar, _T("n1 %f %f %f"),n1.col[0],n1.col[1],n1.col[2]);
		MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
		swprintf_s( msgbox_tchar, _T("r1 %f %f %f"),r1.col[0],r1.col[1],r1.col[2]);
		MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
		swprintf_s( msgbox_tchar, _T("J1 %f %f %f %f %f %f"),J1.col[0],J1.col[1],J1.col[2],J1.col[3],J1.col[4],J1.col[5]);
		MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
		*/
		/*
		swprintf_s( msgbox_tchar, _T("x  %f %f %f"),x.col[0],x.col[1],x.col[2]);
		MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
		swprintf_s( msgbox_tchar, _T("n1 %f %f %f"),n1.col[0],n1.col[1],n1.col[2]);
		MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
		
		swprintf_s( msgbox_tchar, _T("r1 %f %f %f"),r1.col[0],r1.col[1],r1.col[2]);
		MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
		
		*/

		solveSingle( poly1->parent, poly2->parent, J1, J2, n, penetration );
	}
	
}

void solveSingleSolid( PART * part, Vector6 J, float penetration )
{
	float lambda = -1.0 / ( J.dot( part->Minv * J ) ) * ( J.dot( part->v ) );

	if ( lambda <= 0 ){ return; }

	part->v += ( part->Minv * J ) * lambda;
}

void solveSingle( PART * part1, PART * part2, Vector6 J1, Vector6 J2, Vector3 n, float penetration )
{
	float lambda = ( J2.dot( part2->v ) - J1.dot( part1->v ) ) / ( J2.dot( part2->Minv * J2 ) + J1.dot( part1->Minv * J1 ) );

	/*
	swprintf_s( msgbox_tchar, _T("v1 %f %f %f %f %f %f"),part1->v.col[0],part1->v.col[1],part1->v.col[2],part1->v.col[3],part1->v.col[4],part1->v.col[5]);
	MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
	swprintf_s( msgbox_tchar, _T("penetration %f"), penetration );
	MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
	swprintf_s( msgbox_tchar, _T("J1.v1 J2.v2 %f %f"), J1.dot( part1->v ), J2.dot( part2->v )  );
	MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
	swprintf_s( msgbox_tchar, _T("solveSingle %f\n%f %f"),lambda,J2.dot( part2->Minv * J2 ),J1.dot( part1->Minv * J1 ));
	MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
	*/

	

	if ( lambda <= 0 ){ return; }
	
	part1->x -= n * ( penetration * 0.5 );
	part2->x += n * ( penetration * 0.5 );

	part1->v += ( part1->Minv * J1 ) * lambda;
	part2->v -= ( part2->Minv * J2 ) * lambda;
}