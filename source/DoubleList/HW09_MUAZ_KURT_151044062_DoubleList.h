#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct circuit_a{
    char cur[3];
    int v;
    struct circuit_a *next;
    struct circuit_a *prew; 
} circuit;
int size_list();
circuit *insert_node(char *current, int volts, int position);
void delete_node(circuit *n);
void display_list();