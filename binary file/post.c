#include <stdio.h>
#include <stdlib.h>
typedef struct child
{
    int i;
    struct child *left, *right;
} root;

void print_preorder(root * parent, FILE * a)
{
    if (parent!=0)
    {
        fprintf(a,"%d\t",parent->i);
        print_preorder(parent->left, a);
        print_preorder(parent->right, a);
    }
    return;
}
void print_inorder(root * parent, FILE * a)
{
    if (parent!=0)
    {
        print_inorder(parent->left, a);
        fprintf(a,"%d\t",parent->i);
        print_inorder(parent->right, a);
    }
    return;
}
void print_postorder(root * parent, FILE * a)
{
    if (parent!=0)
    {
        print_postorder(parent->left, a);
        print_postorder(parent->right, a);
        fprintf(a,"%d\t",parent->i);
    }
    return;
}
void main()
{
    root *head = (root *) malloc(sizeof (root));
    head->i = 1;
    root *new1 = (root *) malloc(sizeof (root));
    new1->i=2;
    root *new2 = (root *) malloc(sizeof (root));
    new2->i=4;
    root *new3 = (root *) malloc(sizeof (root));
    new3->i = 8;
    root *new4 = (root *) malloc(sizeof (root));
    new4->i = 9;
    root *new5 = (root *) malloc(sizeof (root));
    new5->i=5;
    root *new6 = (root *) malloc(sizeof (root));
    new6->i=10;
    root *new7 = (root *) malloc(sizeof (root));
    new7->i = 11;
    root *new8 = (root *) malloc(sizeof (root));
    new8->i = 3;
    root *new9 = (root *) malloc(sizeof (root));
    new9->i = 6;
    root *new10 = (root *) malloc(sizeof (root));
    new10->i = 12;
    root *new11 = (root *) malloc(sizeof (root));
    new11->i= 13;
    root *new12 = (root *) malloc(sizeof (root));
    new12->i =7;
    root *new13 = (root *) malloc(sizeof (root));
    new13->i = 14;
    root *new14 = (root *) malloc(sizeof (root));
    new14->i = 15;
    head->left = new1;
    new1->left = new2;
    new2->left = new3;
    new3->left = 0;
    new3->right = 0;
    new2->right = new4;
    new4->right=0;
    new4->left=0;
    new1->right = new5;
    new5->left= new6;
    new6->left=0;
    new6->right =0;
    new5->right = new7;
    new7->left=0;
    new7->right =0;
    head->right = new8;
    new8->left = new9;
    new9->left = new10;
    new10->left =0;
    new10->right =0;
    new9->right =new11;
    new11->left =0;
    new11->right =0;
    new8->right =  new12;
    new12->left = new13;
    new13->left =0;
    new13 ->right =0;
    new12->right = new14;
    new14->left =0;
    new14->right =0;
    FILE *the = fopen("HW09_MUAZ_KURT_151044062_Binaryparent.txt", "w");
    fprintf(the,"Pre Order: \n");
    print_preorder(head, the);
    fprintf(the, "\nIn Order: \n");
    print_inorder(head, the);
    fprintf(the, "\nPost Order: \n");
    print_postorder(head, the);
    return;
}