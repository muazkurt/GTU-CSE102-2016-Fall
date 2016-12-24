#include "ll/ll.h"

typedef struct
{
	node *(*IF)(char *current, int volts);
	node *(*IB)(char *current, int volts);
	void (*DN)(node *nd);
	void (*FA)();
	void (*PL)();
} ll_t;

int main()
{
	ll_t ll;

	ll.IF = &insert_front;
	ll.IB = &insert_back;
	ll.DN = &delete_node;
	ll.FA = &free_all;
	ll.PL = &print_list;

	node *n1 = ll.IF("AC", 220);
	node *n2 = ll.IF("DC", 110);
	node *n3 = ll.IF("DC", 220);
	node *n4 = ll.IF("AC", 220);
	node *n5 = ll.IF("DC", 220);
	node *n6 = ll.IF("DC", 120);
	
	node *n11 = ll.IB("AC", 210);
	node *n12 = ll.IB("DC", 120);
	node *n13 = ll.IB("DC", 210);
	node *n14 = ll.IB("AC", 210);
	node *n15 = ll.IB("DC", 210);
	node *n16 = ll.IB("DC", 110);

	ll.PL();
	ll.DN(n1);
	ll.PL();
	ll.FA();
}
