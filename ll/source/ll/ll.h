#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char current[3];
	int volts;
	struct node *next;
} node;

node *insert_front(char *current, int volts);
node *insert_back(char *current, int volts);
void delete_node(node *nd);
void free_all();
void print_list();
