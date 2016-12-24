#include "HW09_MUAZ_KURT_151044062_DoubleList.h"
circuit *head = { NULL };
int size_list()
{
	int i = 0;
	if (head != 0)
	{
		++i;
		circuit *counter;
		for (counter = head; counter->next != 0; counter = (circuit *) counter->next)
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
			init->prew = 0;
			if (head != 0)
			{
				init->next = (struct circuit_a*) head;
				head = init;
			}
			else
			{
				init->next = 0;
				head = init;
			}
			return head;
		}
		else if (position > 1)
		{
			circuit *count = head;
			int i;
			for (i = 1; i < position - 1; ++i)
				count = (circuit *) count->next;
			if (count == head)
			{
				init->prew = (struct circuit_a *) count;
				init->next = count->next;
				count->next = (struct circuit_a *) init;
			}
			else
			{
				init->prew = (struct circuit_a *) count;
				init->next = count->next;
				count->next = (struct circuit_a *) init;
				if (init->next == 0)
					;
				else
					init->next->prew = (struct circuit_a *) init;
			}
		}
		return init;
    }
    else
        printf("There is not enough element to put this position.\n");
    return 0;
}
void delete_node(circuit *n)
{
	if (size_list() > 0)
	{
		if (n->prew != 0)
		{
			if (n->next != 0)
			{
				n->prew->next = n->next;
			}
			else
				n->prew->next = 0;
		}
		else
		{
			if (n->next != 0)
			{
				n->next->prew = 0;
				head = (circuit *) n->next;
			}
			else
				;
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
        while(counter != 0)
        {
            printf("%d) Current = %s\tVolts = %d\n", i++, counter->cur, counter->v);
            counter = counter->next;
        }
    }
    else
        printf("There is not any items exist to display\n");
    return;
}
