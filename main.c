#include <stdio.h>
#include <stdlib.h>
 

#define ROWS    25     
#define COLS    70    
#define BLANK   ' '     
#define DOT     '*'     
#define MAX     64
 

#define CIRCLE    1
#define RECTANGLE 2
#define LINE      3
#define TRIANGLE  4
 


struct Shape {
    int id;       
    int type;     
    int alive;    
    int x, y;     
    int a, b;     
};
 

char         canvas[ROWS][COLS];      
struct Shape shapes[MAX];             
int          total   = 0;             
int          next_id = 1;            
 

void clear_canvas(void)
{
    int r, c;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            canvas[r][c] = BLANK;
}
 

void show_canvas(void)
{
    int r, c;
 
    
    printf("+");
    for (c = 0; c < COLS; c++) printf("-");
    printf("+\n");
 
    
    for (r = 0; r < ROWS; r++) {
        printf("|");
        for (c = 0; c < COLS; c++)
            printf("%c", canvas[r][c]);
        printf("|\n");
    }
 
    
    printf("+");
    for (c = 0; c < COLS; c++) printf("-");
    printf("+\n");
}
 

void put_dot(int row, int col)
{
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
        canvas[row][col] = DOT;
}
 

void remove_dot(int row, int col)
{
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
        canvas[row][col] = BLANK;
}
void draw_rectangle(int x, int y, int width, int height)
{
    int i;

    
    for(i = x; i < x + width; i++)
        put_dot(y, i);

    
    for(i = x; i < x + width; i++)
        put_dot(y + height - 1, i);

    
    for(i = y; i < y + height; i++)
        put_dot(i, x);

    
    for(i = y; i < y + height; i++)
        put_dot(i, x + width - 1);
}


void draw_line(int x1, int y1, int x2, int y2)
{
    int i;

    if(y1 == y2) 
    {
        for(i = x1; i <= x2; i++)
            put_dot(y1, i);
    }

    else if(x1 == x2) 
    {
        for(i = y1; i <= y2; i++)
            put_dot(i, x1);
    }
}


int main(void)
{
    clear_canvas();
    draw_rectangle(55, 8, 6, 10);
    draw_line(5,15,25,15);
    show_canvas();
    return 0;
}