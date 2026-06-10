#include <stdio.h>
#include <stdlib.h>
 

#define ROWS    25     
#define COLS    70    
#define BLANK   '_'     
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

int main(void)
{
    clear_canvas();
    show_canvas();
    return 0;
    
}