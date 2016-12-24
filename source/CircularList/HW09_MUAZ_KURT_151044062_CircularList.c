#include "HW09_MUAZ_KURT_151044062_CircularList.h"
#define circulative 1
circuit *head = { NULL };
int size_list()
{
    int i = 0;
	if (head != 0)
	{
		++i;
		circuit *counter;
		for (counter = head; counter->next != head; counter = (circuit *) counter->next)
			++i;
	}
	else
		;
    return i;
}
circuit * insert_node(char *current, int volts, int position)
{
	if (position <= size_list() + 1 && position >= 1)
    {
		circuit *init = (circuit *)malloc(sizeof(circuit));
		strncpy(init->cur, current, 3);
		init->v = volts;
		if (position == 1)
		{
			if (head != 0)
			{
				init->next = (struct circuit_a*) head;
				circuit *tester;
				for (tester = head; tester->next != head;
					tester = (struct circuit_a*) tester);
				tester->next = init;
				head = init;
			}
			else
			{
				head = init;
				init->next = (struct circuit_a*) head;
			}
			return head;
		}
		else if (position > 1)
		{
			circuit *count = head;
			int i;
			for (i = 1; i < position - 1; ++i)
				count = count->next;
			init->next = count->next;
			count->next = (struct circuit_a *) init;
		}
		return init;
	}
	else
		printf("There is not enough element to put this position.\n");
    return 0;
}
void delete_node(circuit *n)
{
    if(size_list() > 0)
    {
		circuit *counter = head;
		if (n != head)
		{	
			while (counter->next != n)
				counter = counter->next;
			counter->next = n->next;
		}
		else
		{
			while (counter->next != head)
				counter = (circuit *)counter->next;
			counter->next = head->next;
			head = (circuit *)head->next;
		}
		free(n);
    }
    else
        printf("There is not enough element for delete operation.\n");
    return;
}
void display_list()
{
    circuit *counter = head;
    int i = 1;
    if(size_list() > 0)
    {
        do
        {
            printf("%d) Current = %s\tVolts = %d\n", i++, counter->cur, counter->v);
            counter = counter->next;
        } while(counter != head);
    }
    else
        printf("There is not any items exist to display.\n");
    return;
}
