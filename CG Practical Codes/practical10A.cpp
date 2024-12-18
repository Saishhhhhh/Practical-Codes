// Aim: Write C++ program to draw the following pattern. Use DDA line
// and Bresenham's circle drawing algorithm. Apply the concept of encapsulation.
#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

class Circle {
private:
    int x0, y0;

public:
    Circle() : x0(0), y0(0) {}

    void setOffset(int xOffset, int yOffset) {
        x0 = xOffset;
        y0 = yOffset;
    }

    void drawCircle(int xc, int yc, int radius) {
        int x = 0, y = radius;
        int decision = 3 - 2 * radius;

        while (x <= y) {
            // Draw points in all octants
            putpixel(x0 + xc + x, y0 - yc + y, 15);
            putpixel(x0 + xc - x, y0 - yc + y, 15);
            putpixel(x0 + xc + x, y0 - yc - y, 15);
            putpixel(x0 + xc - x, y0 - yc - y, 15);
            putpixel(x0 + xc + y, y0 - yc + x, 15);
            putpixel(x0 + xc - y, y0 - yc + x, 15);
            putpixel(x0 + xc + y, y0 - yc - x, 15);
            putpixel(x0 + xc - y, y0 - yc - x, 15);

            if (decision < 0) {
                decision += 4 * x + 6;
            } else {
                decision += 4 * (x - y) + 10;
                y--;
            }
            x++;
        }
    }
};

class Point {
protected:
    int x, y, color;

public:
    Point() : x(0), y(0), color(15) {}

    void setCoordinates(int xCoord, int yCoord) {
        x = xCoord;
        y = yCoord;
    }

    void setColor(int c) {
        color = c;
    }

    void drawPoint() {
        putpixel(x, y, color);
    }
};

class Line : public Point {
private:
    int x2, y2;

public:
    Line() : Point(), x2(0), y2(0) {}

    void setLine(int x1, int y1, int x2Coord, int y2Coord) {
        setCoordinates(x1, y1);
        x2 = x2Coord;
        y2 = y2Coord;
    }

    void drawLine(int lineColor) {
        float dx = abs(x2 - x);
        float dy = abs(y2 - y);
        float length = max(dx, dy);
        float xIncrement = (x2 - x) / length;
        float yIncrement = (y2 - y) / length;

        float xCurrent = x + 0.5, yCurrent = y + 0.5;

        setColor(lineColor);

        for (int i = 0; i <= length; i++) {
            putpixel(xCurrent, yCurrent, color);
            xCurrent += xIncrement;
            yCurrent += yIncrement;
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x, y, r, x1, y1, x2, y2, xmax, ymax, xmid, ymid, n;

    // Initialize graphical boundaries
    xmax = getmaxx();
    ymax = getmaxy();
    xmid = xmax / 2;
    ymid = ymax / 2;

    // Draw Cartesian axes
    setcolor(1);
    line(xmid, 0, xmid, ymax); // Y-axis
    line(0, ymid, xmax, ymid); // X-axis

    // Circle Input
    Circle c;
    c.setOffset(xmid, ymid);

    cout << "\nEnter coordinates of the center of the circle:\n";
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << "Enter radius of the circle: ";
    cin >> r;

    setcolor(15);
    c.drawCircle(x, y, r);

    // Line Input
    Line l;
    cout << "\nEnter total number of lines: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter coordinates of the first point (x1, y1): ";
        cin >> x1 >> y1;
        cout << "Enter coordinates of the second point (x2, y2): ";
        cin >> x2 >> y2;

        l.setLine(x1 + xmid, ymid - y1, x2 + xmid, ymid - y2);
        l.drawLine(15);
    }

    // Optional: Draw another circle
    cout << "\nEnter coordinates of another circle's center:\n";
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << "Enter radius of the circle: ";
    cin >> r;

    setcolor(5);
    c.drawCircle(x, y, r);

    getch();
    closegraph();
    return 0;
}

/*
Sample Input:

Enter coordinates of centre of circle:
Enter the value of x: 0
Enter the value of y: 0
Enter the value of radius: 150

Enter Total Number of lines: 3
Enter coordinates of point x1: -130
Enter coordinates of point y1: -75
Enter coordinates of point x2: 130
Enter coordinates of point y2: -75

Enter coordinates of point x1: 130
Enter coordinates of point y1: -75
Enter coordinates of point x2: 0
Enter coordinates of point y2: 150

Enter coordinates of point x1: 0
Enter coordinates of point y1: 150
Enter coordinates of point x2: -130
Enter coordinates of point y2: -75

Enter coordinates of centre of circle:
Enter the value of x: 0
Enter the value of y: 0
Enter the value of radius: 75


*/
