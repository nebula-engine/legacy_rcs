TOY_PART::TOY_PART()
{
	rp = RECTANGULAR_PARALLELEPIPED<PART>(0,0,0,0,0,0,1,1,1,1);
	rp.parent = this;
	
	calcuate_constants(1,&rp);
}
