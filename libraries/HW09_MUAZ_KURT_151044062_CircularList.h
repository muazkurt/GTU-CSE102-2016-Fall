#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_p {
    char cur[3];
    int v;
    struct node_p *next, *prew; 
} node;
int size_list();
void insert_node(char *current, int volts, int position);
void delete_node(node *n);
void display_list();