#include <iostream>
#include <cmath>
#include <graphics.h> // Note: Ensure graphics.h is properly set up or replace it with modern libraries.
using namespace std;

class Transform {
private:
    int m;               // Number of vertices
    int a[20][3];        // Original coordinates
    int c[20][3];        // Transformed coordinates

public:
    void accept();
    void drawObject();
    void applyTransformation(float b[3][3]);
};

void Transform::accept() {
    cout << "\nEnter the Number of Edges: ";
    cin >> m;
    cout << "\nEnter the Coordinates (x y):\n";
    for (int i = 0; i < m; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = 1; // Homogeneous coordinate
    }
}

void Transform::drawObject() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw Cartesian axes
    line(300, 0, 300, 600); // Y-axis
    line(0, 300, 600, 300); // X-axis

    // Draw original object
    for (int i = 0; i < m - 1; i++) {
        line(300 + a[i][0], 300 - a[i][1], 300 + a[i + 1][0], 300 - a[i + 1][1]);
    }
    line(300 + a[m - 1][0], 300 - a[m - 1][1], 300 + a[0][0], 300 - a[0][1]);

    // Draw transformed object
    for (int i = 0; i < m - 1; i++) {
        line(300 + c[i][0], 300 - c[i][1], 300 + c[i + 1][0], 300 - c[i + 1][1]);
    }
    line(300 + c[m - 1][0], 300 - c[m - 1][1], 300 + c[0][0], 300 - c[0][1]);

    cout << "Press any key to exit...";
    getch();
    closegraph();
}

void Transform::applyTransformation(float b[3][3]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    Transform t;
    int choice;
    float b[3][3] = {0}; // Transformation matrix
    t.accept();

    cout << "\nChoose a Transformation:";
    cout << "\n1. Translation\n2. Scaling\n3. Rotation\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int tx, ty;
            cout << "\nTRANSLATION OPERATION\nEnter tx and ty: ";
            cin >> tx >> ty;
            b[0][0] = b[1][1] = b[2][2] = 1;
            b[2][0] = tx;
            b[2][1] = ty;
            break;
        }
        case 2: {
            int sx, sy;
            cout << "\nSCALING OPERATION\nEnter sx and sy: ";
            cin >> sx >> sy;
            b[0][0] = sx;
            b[1][1] = sy;
            b[2][2] = 1;
            break;
        }
        case 3: {
            float deg, theta;
            cout << "\nROTATION OPERATION\nEnter angle (in degrees): ";
            cin >> deg;
            theta = deg * (M_PI / 180); // Convert to radians
            b[0][0] = cos(theta);
            b[0][1] = -sin(theta);
            b[1][0] = sin(theta);
            b[1][1] = cos(theta);
            b[2][2] = 1;
            break;
        }
        default:
            cout << "\nInvalid choice!";
            return 1;
    }

    t.applyTransformation(b);
    t.drawObject();
    return 0;
}

//    command to run the code in terminal
//    gcc filename.cpp -o sample -lgraph
//    ./sample

/*
Sample Inputs:

1. Translation:
   Number of edges: 4
   Coordinates:
   50 50
   150 50
   150 150
   50 150
   Choice: 1 (Translation)
   Translation values:
   tx = 100
   ty = 50

2. Scaling:
   Number of edges: 3
   Coordinates:
   50 50
   100 50
   75 100
   Choice: 2 (Scaling)
   Scaling values:
   sx = 2
   sy = 2

3. Rotation:
   Number of edges: 4
   Coordinates:
   100 100
   200 100
   200 200
   100 200
   Choice: 3 (Rotation)
   Rotation angle:
   45
*/
