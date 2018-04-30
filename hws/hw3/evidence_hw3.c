/*
 * Yasoob Rasheed, yasoobr
 * CS152, Winter 2018
 * Homework 3
 */

#include <stdio.h>
#include "hw3.h"

int main() {
    // String Method Tests
    char foo[] = "hello";
    char *bar = foo;
    printf("%s\n", str_duplicate(bar));
    
    char x[] = "world";
    char *y = x;
    printf("%s\n", cat(bar, y));
    printf("%s\n", catw(bar, ' ', y));
    
    char* ch_arr[3] = {"a", "bb", "c"};
    printf("%s\n", catw_arr(ch_arr, 3, '|'));
    
    // Point Tests
    point_t *p1 = point_new(1.0, 1.0);
    point_show(stdout, p1); 
    
    // Segment Tests
    point_t *p2 = point_new(2.0, 2.0);
    segment_t *seg = segment_new(p1, p2);
    segment_show(stdout, seg);
    
    // Circle Tests + Operations
    point_t *p3 = point_new(0.0, 0.0);
    double radius = 3;
    circle_t *c = circle_new(p3, radius);
    circle_show(stdout, c);
    printf("Circle Area: %f\n", circle_area(c));
    
    point_t *p_in = point_new(1.0, 1.0);
    printf("Inside the Circle - Contains?: %d\n", contains(c, p_in));
    point_t *p_on = point_new(0, 3.0);
    printf("On the Circle - Contains?: %d\n", contains(c, p_on));
    point_t *p_out = point_new(4.0, 4.0);
    printf("Outside the Circle - Contains?: %d\n", contains(c, p_out));

    segment_t *h_diam = horiz_diameter(c); 
    segment_show(stdout, h_diam);
    printf("Segment Length: %f\n", segment_length(h_diam));

    point_t *p_thru = point_new(-1.0, -1.0);
    segment_t *diam_thru = diameter_through(c, p_thru);
    segment_show(stdout, diam_thru);
    printf("Segment Length: %f\n", segment_length(h_diam));
    
    // Same Circle
    point_t *p_same = point_new(0.0, 0.0);
    double r2 = 3;
    circle_t *c2 = circle_new(p_same, r2);
    printf("Overlap?: %d\n", overlap(c, c2));

    // Concentric Circle
    point_t *p_conc = point_new(0.0, 0.0);
    double r3 = 2;
    circle_t *c3 = circle_new(p_conc, r3);
    printf("Overlap?: %d\n", overlap(c, c3));

    // Two Intersection Points
    point_t *p_two = point_new(2.0, 0.0);
    double r4 = 3;
    circle_t *c4 = circle_new(p_two, r4);
    printf("Overlap?: %d\n", overlap(c, c4));

    // One Intersection Point
    point_t *p_one = point_new(6.0, 0.0);
    double r5 = 3;
    circle_t *c5 = circle_new(p_one, r5);
    printf("Overlap?: %d\n", overlap(c, c5));

    // No Intersection Points
    point_t *p_none = point_new(6.0, 0.0);
    double r6 = 2;
    circle_t *c6 = circle_new(p_none, r6);
    printf("Overlap?: %d\n", overlap(c, c6));

    // Translate Circle
    circle_t *c7 = circle_translate(c, 1.0, 1.0);
    circle_show(stdout, c7);

    // Free Everything
    segment_free(seg);
    segment_free(h_diam);
    segment_free(diam_thru);
    circle_free(c);
    circle_free(c2);
    circle_free(c3);
    circle_free(c4);
    circle_free(c5);
    circle_free(c6);
    circle_free(c7);
    return 0;
}
