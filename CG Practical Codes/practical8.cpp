// Aim: Write C++ program to draw a concave polygon and fill it with desired color using scan fill algorithm.
#include<graphics.h> 
#include<iostream> 
#include<stdlib.h> 
using namespace std; 
void ffill(int x,int y,int o_col,int n_col) 
{ 
    int current = getpixel(x,y); 
    if(current==o_col) 
    { 
        delay(1); 
        putpixel(x,y,n_col); 
        ffill(x+1,y,o_col,n_col); 
        ffill(x-1,y,o_col,n_col); 
        ffill(x,y+1,o_col,n_col); 
        ffill(x,y-1,o_col,n_col); 
    } 
} 
int main() 
{ 
    int x1,y1,x2,y2,x3,y3,xavg,yavg; 
    int gdriver = DETECT,gmode; 
    initgraph(&gdriver,&gmode,NULL); 
    
    cout << " \n\t Enter the points of triangle (x1 y1 x2 y2 x3 y3): "; 
    setcolor(1); 
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; 
    
    xavg = (int)(x1+x2+x3)/3; 
    yavg = (int)(y1+y2+y3)/3;  
    
    line(x1,y1,x2,y2); 
    line(x2,y2,x3,y3); 
    line(x3,y3,x1,y1);
    ffill(xavg,yavg,BLACK,RED); 
    
    getch(); 
    closegraph(); 
    return 0; 
} 
//    command to run the code in terminal
//    gcc filename.cpp -o sample -lgraph
//    ./sample
/* 
Input required:
Enter the points of the triangle as coordinates in the following format:
x1 y1 x2 y2 x3 y3
Example input:
100 100 200 50 150 200
This input will draw a triangle with vertices at (100, 100), (200, 50), and (150, 200), and fill it with a red color.
*/