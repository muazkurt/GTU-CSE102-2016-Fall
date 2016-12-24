#include "HW09_MUAZ_KURT_151044062_DoubleList.h"
node *head = { NULL };
int size_list()
{
    node *counter;
    int i = 0;
    if(head != 0)
    {
        for(counter = head; counter->next != 0; counter = counter->next)
            ++i;
    }
    else
        ;
    return i;
}
void insert_node(char *current, int volts, int position)
{
    node *count = head;
    int i;
    if(i <  size_list() || i > 0)
    {
        for(i = 1; i < position; ++i)
           count = count->next;
        node *init = (node *) malloc(sizeof ( node ));
        strncpy(init->cur, current, 3);
        init->v = volts;
        init->next = count->next;
        init->prew = count->prew;
        count->prew->next = init;
        count->next->prew = init;
    }
    else
        printf("There is not enough element to put this position.");
    return;
}
void delete_node(node *n)
{
    if(size_list() > 0)
    {
        n->prew->next = n->next;
        n->next->prew = n->prew;
        free(n);
    }
    else
        printf("There is not enough element for delete operation.");
    return;
}
void display_list()
{
    node *counter = head;
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
        printf("There is not any items exist to display");
    return;
}