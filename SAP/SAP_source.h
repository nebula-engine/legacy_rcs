template <class U> void SAP<U>::sortSAP()
{
	sortSAPSub(x);
	sortSAPSub(y);
	sortSAPSub(z);
}
template <class U> void SAP<U>::sortSAPSub( std::vector<ENDPOINT*> &ep )
{
	std::vector<ENDPOINT*>::iterator it = ep.begin();
	ENDPOINT* temp;
	bool repeat = false;
	
	while ( true )
	{
		if ( (*(it))->val > (*(it+1))->val )
		{
			repeat = true;
			temp = *(it);
			*(it) = *(it+1);
			*(it+1) = temp;
			if ( ( !(*(it))->isMin ) && ( (*(it+1))->isMin ) )
			{
				// add pair
				pm->add( (*(it))->parent_object, (*(it+1))->parent_object );
			}
			else if ( ( (*(it))->isMin ) && ( !(*(it+1))->isMin ) )
			{
				// remove pair
				pm->add( (*(it))->parent_object, (*(it+1))->parent_object );
			}
		}
		if ( (it + 2) == ep.end() )
		{
			if ( repeat )
			{
				it = ep.begin();
				repeat = false;
			}
			else
			{ return; }
		}
		else
		{
			it++;
		}
	}
}
template <class U> void SAP<U>::ENDPOINT::update( int axis )
{
	if ( isMin )
	{
		val = parent->AABB.getMin(axis);
	}
	else
	{
		val = parent->AABB.getMax(axis);
	}
}
template <class U> void SAP<U>::add      (U* u)
{
	addSub( x, u );
	addSub( y, u );
	addSub( z, u );
}
template <class U> void SAP<U>::addSub   ( std::vector<ENDPOINT*> &ep, U* u )
{
	ENDPOINT* epTemp = NULL;

	epTemp = new ENDPOINT;
	epTemp->parent = u;
	epTemp->isMin = true;
	ep.push_back(epTemp);

	epTemp = new ENDPOINT;
	epTemp->parent = u;
	epTemp->isMin = false;
	ep.push_back(epTemp);
}
template <class U> void SAP<U>::remove   ( U* u )
{
	removeSub( x, u );
	removeSub( y, u );
	removeSub( z, u );

	pm->remove( u );
}
template <class U> void SAP<U>::removeSub( std::vector<ENDPOINT*> &ep, U* u )
{
	std::vector<ENDPOINT*>::iterator it = ep.begin();
	for ( ; it != ep.end(); it++ )
	{
		if ( (*it)->parent == u )
		{
			ep.erase(it);
		}
	}
}
template <class U> void SAP<U>::updateSAP()
{
	updateSAPSub(x,0);
	updateSAPSub(y,1);
	updateSAPSub(z,2);
}
template <class U> void SAP<U>::updateSAPSub( std::vector<ENDPOINT*> &ep, int axis )
{
	for ( int i = 0; i < ep.size(); i++ )
	{
		ep.at(i)->update(axis);
	}
}
