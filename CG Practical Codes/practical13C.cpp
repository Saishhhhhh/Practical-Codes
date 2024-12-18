// Aim: Write OpenGL program to draw Sun Rise and Sunset.
//CHANGE CODE
#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() 
{
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, NULL);
    int midx, midy, sunRadius = 30, sunY, sunMaxY = 150, groundY = 350;
    midx = getmaxx() / 2; // Middle X-coordinate
    midy = getmaxy() / 2; // Middle Y-coordinate
    sunY = groundY; // Start sun from the ground (sunrise position)

    while (sunY >= sunMaxY) // Sunrise loop
    {
        cleardevice(); // Clear previous frame
        // Draw Ground
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        rectangle(0, groundY, getmaxx(), getmaxy());
        floodfill(1, groundY + 10, GREEN);
        // Draw Sky
        setcolor(LIGHTBLUE);
        setfillstyle(SOLID_FILL, LIGHTBLUE);
        rectangle(0, 0, getmaxx(), groundY);
        floodfill(1, 10, LIGHTBLUE);
        // Draw Mountains
        setcolor(DARKGRAY);
        setfillstyle(SOLID_FILL, DARKGRAY);
        line(0, groundY, 150, 200);   // Left mountain
        line(150, 200, 300, groundY);
        line(300, groundY, 500, 150); // Middle mountain
        line(500, 150, 700, groundY);
        line(700, groundY, getmaxx(), 200); // Right mountain
        line(getmaxx(), 200, getmaxx(), groundY);
        floodfill(2, groundY - 10, DARKGRAY);
        // Draw Sun
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(midx, sunY, sunRadius, sunRadius);
        sunY -= 2; // Move sun upwards
        delay(50); // Delay for animation
    }
    while (sunY <= groundY) // Sunset loop
    {
        cleardevice(); // Clear previous frame
        // Draw Ground
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        rectangle(0, groundY, getmaxx(), getmaxy());
        floodfill(1, groundY + 10, GREEN);
        // Draw Sky
        setcolor(LIGHTRED);
        setfillstyle(SOLID_FILL, LIGHTRED);
        rectangle(0, 0, getmaxx(), groundY);
        floodfill(1, 10, LIGHTRED);
        // Draw Mountains
        setcolor(DARKGRAY);
        setfillstyle(SOLID_FILL, DARKGRAY);
        line(0, groundY, 150, 200);   // Left mountain
        line(150, 200, 300, groundY);
        line(300, groundY, 500, 150); // Middle mountain
        line(500, 150, 700, groundY);
        line(700, groundY, getmaxx(), 200); // Right mountain
        line(getmaxx(), 200, getmaxx(), groundY);
        floodfill(2, groundY - 10, DARKGRAY);
        // Draw Sun
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        fillellipse(midx, sunY, sunRadius, sunRadius);
        sunY += 2; // Move sun downwards
        delay(50); // Delay for animation
    }
    getch(); 
    closegraph(); 
    return 0;
}

//    command to run the code in terminal
//    gcc filename.cpp -o sample -lgraph
//    ./sample
/* No input required */