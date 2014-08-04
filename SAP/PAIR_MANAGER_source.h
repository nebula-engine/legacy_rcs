template <class U> PAIR_MANAGER<U>::PAIR::PAIR( U* param1, U* param2 )
{
	o1 = param1;
	o2 = param2;
	count = 1;
}
template <class U> void PAIR_MANAGER<U>::add      ( U* o1, U* o2 )
{
	if ( o1 < o2 )
	{ addSub( o1, o2 ); }
	else
	{ addSub( o2, o1 ); }
}
template <class U> void PAIR_MANAGER<U>::addSub   ( U* o1, U* o2 )
{
	for ( int i = 0; i < pairs.size(); i++ )
	{
		if ( o1 == pairs.at(i).o1 )
		{
			if ( o2 == pairs.at(i).o2 )
			{
				pairs.at(i).count++;
				return;
			}
		}
	}
	pairs.push_back(PAIR(o1,o2));
}
template <class U> void PAIR_MANAGER<U>::remove   ( U* o1, U* o2 )
{
	if ( o1 < o2 )
	{ removeSub( o1, o2 ); }
	else
	{ removeSub( o2, o1 ); }
}
template <class U> void PAIR_MANAGER<U>::removeSub( U* o1, U* o2 )
{
	std::vector<PAIR>::iterator it;
	for ( it = pairs.begin(); it != pairs.end(); it++ )
	{
		if ( o1 == (*it).o1 )
		{
			if ( o2 == (*it).o2 )
			{
				if ( ( --(*(it)).count ) == 0 )
				{
					pairs.erase(it);
				}
				return;
			}
		}
	}
}
template <class U> void PAIR_MANAGER<U>::remove   ( U* u )
{
	std::vector<PAIR>::iterator it;
	for ( it = pairs.begin(); it != pairs.end(); it++ )
	{
		if ( ( u == (*it).o1 ) || ( u == (*it).o2 ) )
		{
			pairs.erase(it);
		}
	}
}