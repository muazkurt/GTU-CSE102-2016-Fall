#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*MY BINARY TREE*/
typedef struct childs{
    char OorZ;                      /*ONE OR ZERO CHARS     */
    struct childs *down, *right;    /*DOWN AND RIGHT CHILDS */
}root;

int howLong(FILE* input)
{
    int a = 0;
    char x;
    do
    {
        x = fgetc( input );
        if(x == '0' || x == '1' )
            ++a;
    }while( !feof(input) );
    fseek(input, SEEK_SET, 0);
    return a;
}

root *insertonDown(root *top, char in)
{
    root *counter, *new = (root *) malloc(sizeof(root));
    if(top != 0)
    {
        for(counter = top; counter->down != 0; counter=counter->down);
        counter->down = new;
    }
    else
    {
        top = new;
        new->right = 0;
    }
    new->OorZ = in;
    new->down = 0;
    return new;
}

root *insertonRight(root *top, char in)
{
    root *counter, *new = (root *)malloc(sizeof(root));
    if(top!=0)
    {
        for(counter=top; counter->right!=0; counter=counter->right);
        counter->right=new;
    }
    else
    {
        top=new;
        new->down = 0;
    }
    new->OorZ = in;
    new->right = 0;
    return new;
}

root *readingfile(FILE* input, root *maze)
{
    int start,
        total,
        column = (int) sqrt(howLong(input));
    char x;
    root *wait = maze;
    for(total = 0; total < column; ++total)
    {
        for(start = 0; start < column;)
        {
            x = fgetc(input);
            if(x == '0' || x == '1')
            {
                insertonRight(wait, x);
                ++start;
            }
        }
        for(x = fgetc(input);
            x != '0' && x != '1';
            x = fgetc(input));
        wait = insertonDown(maze, x); 
    }
    return maze;
}

char *theGame(char* maze, int colomn)
{
    return maze;
}

void main()
{
    FILE* input = fopen( "maze.txt", "r" );
    root *maze = { NULL };
    readingfile(input, maze);
    return;
}