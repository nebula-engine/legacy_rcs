template <class U> class PAIR_MANAGER
{
public:
	class PAIR
	{
	public:
		U * o1;
		U * o2;
		int count;

		PAIR( U* param1, U* param2 );
	};
	
	std::vector<PAIR> pairs;
	
	void add      ( U* o1, U* o2 );
	void addSub   ( U* o1, U* o2 );
	void remove   ( U* o1, U* o2 );
	void removeSub( U* o1, U* o2 );
	void remove   ( U* u );
};
template <class U> class SAP
{
public:
	PAIR_MANAGER* pm;

	class ENDPOINT
	{
	public:
		float val;
		bool isMin;
		U* parent;

		void update(int axis);
	};

	std::vector<ENDPOINT*> x;
	std::vector<ENDPOINT*> y;
	std::vector<ENDPOINT*> z;

	void add      ( U* u );
	void addSub   ( std::vector<ENDPOINT*> &ep, U* u );
	void remove   ( U* u );
	void removeSub( std::vector<ENDPOINT*> &ep, U* u );

	void updateSAP();
	void updateSAPSub( std::vector<ENDPOINT*> &ep, int axis );
	void sortSAP();
	void sortSAPSub( std::vector<ENDPOINT*> &ep );
};

#include "PAIR_MANAGER_source.h"
#include "SAP_source.h"
