// Aim is
// Write C++ program to generate Bouncing ball.
#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    int i, x, y, flag = 1;
    initgraph(&gd, &gm, NULL);
    x = getmaxx() / 2;
    y = getmaxx() / 2;
    while (1)
    {
        if (y >= getmaxy() - 30 || y <= getmaxx() / 4){
            flag = !flag;
        }
            
        setcolor(RED);
        circle(x, y, 30); 
        floodfill(x, y, RED);
        delay(50);
        cleardevice();
        if (flag)
        {
            y = y + 5;
        }
        else
        {
            y = y - 5;
        }
    }

    getch();
    closegraph();
    return 0;
}
//    command to run the code in terminal
//    gcc filename.cpp -o sample -lgraph
//    ./sample
/* No input required */