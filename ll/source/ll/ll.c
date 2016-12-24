#include "ll.h"

node *head;

node *insert_front(char *current, int volts)
{
	node *n;

	n = (node *)malloc(sizeof(node));
	strcpy(n->current, current);
	n->volts = volts;

	if (head != 0)
	{
		n->next = (struct node *)head;
		head = n;
	}
	else
	{
		n->next = 0;
		head = n;
	}

	return n;
}

node *insert_back(char *current, int volts)
{

	node *n = head;
	node *prev = head;
	while (n != 0)
	{
		prev = n;
		n = (node *)n->next;
	}
	n = (node *)malloc(sizeof(node));
	strcpy(n->current, current);
	n->volts = volts;

	if (head != 0)
		prev->next = (struct node *)n;
	else
		head = n;
	n->next = 0;

	return n;
}

void delete_node(node *nd)
{
	node *n = head;
	node *prev = head;
	while (n != 0)
	{
		if (n == nd)
		{
			if (n == head)
				head = (node *)n->next;
			prev->next = n->next;
			free(n);
			break;
		}
		prev = n;
		n = (node *)n->next;
	}
}

void free_all()
{
	node *n = head;
	while (n != 0)
	{
		head = (node *)n->next;
		free (n);
		n = head;
	}
}

void print_list()
{
	int i = 0;
	node *n = head;
	printf("Printing Node List:\n");
	while (n != 0)
	{
		printf("Node %5d --> Current: %3s Volts: %3d\n", i, n->current, n->volts);
		n = (node *)n->next;
		i++;
	}
}
