#include <stdio.h>
#include <math.h>
#include "lab3.h"

/* dist: compute Euclidean distance from (x0,y0) to (x1,y1) */
double dist(double x0, double y0, double x1, double y1) {
    double distance1 = x0 - x1;
    double distance2 = y0 - y1;
    double sq_distance1 = pow(distance1, 2.0);
    double sq_distance2 = pow(distance2, 2.0);
                        
    return sqrt(sq_distance1 + sq_distance2);
}

/* draw_waves: PPM waves image with side length and offset center */
void draw_waves(int side_length, int x_offset, int y_offset, double r, double g, double b) {
    double x_center = side_length / 2.0 + x_offset;
    double y_center = side_length / 2.0 + y_offset;

    printf("P3\n");
    printf("%d %d\n", side_length, side_length);
    printf("255\n");

    for (int y = 0; y < side_length; y++) {
        for (int x = 0; x < side_length; x++) {
            double distance = dist(x, y, x_center, y_center);
        
            double red = (sin(distance * r) + 1.0) / 2.0 * 255.0;
            double green = (sin(distance * g) + 1.0) / 2.0 * 255.0;
            double blue = (sin(distance * b) + 1.0) / 2.0 * 255.0;
            printf("%d %d %d ", (int) red, (int) green, (int) blue);
        }
        printf("\n");
    }  
}
