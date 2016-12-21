#include "HW09_MUAZ_KURT_151044062_CircularList.h"
node *head = { NULL };
int size_list()
{
    node *counter;
    int i = 0;
    if(head != 0)
        for(counter = head; counter->next != head; counter = counter->next)
            ++i;
    else
        ;
    return i;
}
void insert_node(char *current, int volts, int position)
{
    node *count = head;
    int i;
    if(position <  size_list() || position > 0)
    {
        for(i = 1; i < position - 1; ++i)
           count = count->next;
        node *init = (node *) malloc(sizeof ( node ));
        strncpy(init->cur, current, 3);
        init->v = volts;
        init->next = count->next;
        count->next = init;
    }
    else
        printf("There is not enough element to put this position.");
    return;
}
void delete_node(node *n)
{
    if(size_list() > 0)
    {
        node *counter = head;
        while(counter->next != n)
            counter = counter->next;
        counter->next = n->next;
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
        do
        {
            printf("%d) Current = %s\tVolts = %d\n", i++, counter->cur, counter->v);
            counter = counter->next;
        } while(counter != head);
    }
    else
        printf("There is not any items exist to display");
    return;
}