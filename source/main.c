#include "CircularList/HW09_MUAZ_KURT_151044062_CircularList.h"
#ifndef circulative
	#include "DoubleList/HW09_MUAZ_KURT_151044062_DoubleList.h"
#endif
typedef struct
{
	int (*S)();
	circuit *(*I)(char *current, int volts, int p);
	void (*DN)(circuit *nd);
	void (*PL)();
} list_type;

void main()
{
	list_type movements;

	movements.S = &size_list;
	movements.I = &insert_node;
	movements.DN = &delete_node;
	movements.PL = &display_list;
	circuit *n1 = movements.I("AC", 220, 1);
	circuit *n2 = movements.I("DC", 110, 2);
	circuit *n3 = movements.I("DC", 220, 3);
	circuit *n4 = movements.I("AC", 220, 4);
	circuit *n5 = movements.I("DC", 220, 5);
	circuit *n6 = movements.I("DC", 120, 6);
	movements.PL();
	movements.DN(n1);
	movements.PL();
	return;
}