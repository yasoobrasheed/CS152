/*
 * Yasoob Rasheed, yasoobr
 * CS152, Winter 2018
 * Homework 3
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hw3.h"

/* Create a new heap-allocated copy of the given string
 *
 * Inputs:
 * s: (char*) char pointer to some char[]
 *
 * Variables:
 * len: (int) length of s and the null terminator
 * duplicate: (char*) allocated space in the heap for duplicate
 *
 * Returns:
 * (char*) duplicate filled in with chars from s
 */
char *str_duplicate(char *s) {
    int len = strlen(s) + 1;
    char *duplicate = malloc(len * sizeof(char));
    if (duplicate == NULL) {
        fprintf(stderr, "heap has no more space");
        exit(1);
    }
    
    for (int i = 0; i < len; i++) {
        duplicate[i] = s[i];
    }
    return duplicate;
}
 
/* Build a new string that consists of s1 followed by s2. 
 *
 * Inputs:
 * s1: (char*) char pointer to some char[]
 * s2: (char*) char pointer to some char[]
 *
 * Variables:
 * len: (int) length of s1, s2, and the null terminator
 * s3: (char*) allocated space in the heap for concat
 *
 * Returns:
 * (char*) concat filled in with chars from s1 and s2
 */
char *cat(char *s1, char *s2) {
    int len = strlen(s1) + strlen(s2) + 1;
    char* s3 = malloc(len * sizeof(char));
    if (s3 == NULL) {
        fprintf(stderr, "heap has no more space");
        exit(1);
    }
    
    for (int i = 0; i < strlen(s1); i++) {
        s3[i] = s1[i];
    }
    for (int j = 0; j < strlen(s2); j++) {
        s3[strlen(s1) + j] = s2[j];
    }
    s3[strlen(s1) + strlen(s2)] = '\0';
    return s3;
}

/* Build a new string with s1, the separator, then s2
 *
 * Inputs:
 * s1: (char*) char pointer to some char[]
 * sep: (char) char of seperator
 * s2: (char*) char pointer to some char[]
 *
 * Variables:
 * SEP_LEN: (int) length of the seperator
 * len: (int) length of s1, sep, s2, and the null terminator
 * s3: (char*) allocated space in the heap for concat
 *
 * Returns:
 * (char*) concat filled in with chars from s1, sep, and s2
 */
char *catw(char *s1, char sep, char *s2) {
    int SEP_LEN = 1;
    int len = strlen(s1) + strlen(s2) + SEP_LEN + 1;
    char* s3 = malloc(len * sizeof(char));
    if (s3 == NULL) {
        fprintf(stderr, "heap has no more space");
        exit(1);
    }
    
    for (int i = 0; i < strlen(s1); i++) {
        s3[i] = s1[i];
    }
    s3[strlen(s1)] = sep;
    for (int j = 0; j < strlen(s2); j++) {
        s3[strlen(s1) + SEP_LEN + j] = s2[j];
    }
    s3[strlen(s1) + SEP_LEN + strlen(s2)] = '\0';
    return s3;
}

/* Concatenate an array of strings with the separator in between
 *
 * Inputs:
 * ss: (char*) array of char pointers to char[]
 * slen: (int) length of ss
 * sep: (char) char of seperator
 *
 * Variables:
 * SEP_LEN: (int) length of the seperator
 * len: (int) length of s1, sep, s2, and the null terminator
 * final_string: (char*) allocated space in the heap for concat
 * counter: (int) keeps track of char place in final_string
 *
 * Returns:
 * (char*) concat filled in with chars from ss with sep in between
 */
char *catw_arr(char *ss[], int slen, char sep) {
    int SEP_LEN = 1;
    int len = SEP_LEN + 1;
    for (int i = 0; i < slen; i++) {
        len += strlen(ss[i]);
    }
    char* final_string = malloc(len * sizeof(char));
    if (final_string == NULL) {
        fprintf(stderr, "heap has no more space");
        exit(1);
    }

    int counter = 0;
    for (int x = 0; x < slen; x++) {
        for (int y = 0; y < strlen(ss[x]); y++) {
            final_string[counter + y] = ss[x][y];      
        }
        counter += strlen(ss[x]);
        if (x != slen - 1) {
            final_string[counter] = sep;
            counter++;
        } else {
            final_string[counter] = '\0';
        }
    }
    return final_string;
}

/* Build a new heap-allocated point from two doubles
 *
 * Inputs:
 * x: (double)
 * y: (double)
 *
 * Variables:
 * t: (point_t*) pointer to the point struct allocated space in heap
 *
 * Returns:
 * (point_t*) pointer that is already allocated
 */
point_t *point_new(double x, double y) {
    point_t* t = malloc(sizeof(point_t));
    if (t == NULL) {
        fprintf(stderr, "heap has no more space");
        exit(1);
    }

    t->x = x;
    t->y = y;
    return t;
}

/* Use fprintf to print a representation of the point to f
 *
 * Inputs:
 * f: (FILE*) file to output fprintf to
 * p: (point_t*) pointer to the point struct allocated space in heap
 *
 * Returns:
 * (void) prints the point to the file given
 */
void point_show(FILE *f, point_t *p) {
    fprintf(f, "New point: (%f, %f)\n", p->x, p->y);
}

/* Build a new segment from two points. 
 *
 * Inputs:
 * a: (point_t*) pointer to the point struct in heap
 * b: (point_t*) pointer to the point struct in heap
 *
 * Variables:
 * segment: (segment_t*) pointer to the segment struct in the heap
 *
 * Returns:
 * (segment_t) the segment made from the two points a and b
 */
segment_t *segment_new(point_t *a, point_t *b) {
    segment_t* segment = malloc(sizeof(segment_t));
    if (segment == NULL) {
        fprintf(stderr, "heap has no more space");
        exit(1);
    }

    if (a == b) {
        fprintf(stderr, "points are identical, cannot create a struct");
        exit(1);
    }
    segment->a = point_new(a->x, a->y);
    segment->b = point_new(b->x, b->y);
    return segment;
}

/* Print a representation of the segment to f. 
 * 
 * Inputs:
 * f: (FILE*) file to output fprintf to
 * s: (segment_t*) line segment struct
 *
 * Returns:
 * (void) prints each point in the segment to f
 */
void segment_show(FILE *f, segment_t *s) {
    fprintf(f, "Segment: ");
    fprintf(f, "A: (%f, %f) ", s->a->x, s->a->y);
    fprintf(f, "B: (%f, %f)\n", s->b->x, s->b->y);
}

/* Free the segment and the points it points to
 *
 * Inputs:
 * s: (segment_t*) line segment struct
 *
 * Returns:
 * (void) frees the deep copy from the heap
 */
void segment_free(segment_t *s) {
    free(s->a);
    free(s->b);
    free(s);
}

/* Build a new circle from a center and a radius.
 * 
 * Inputs:
 * center: (point_t*) pointer to the point representing the center of the
 * circle
 * r: (double) positive radius of the circle
 *
 * Variables:
 * circ: (circle_t*) pointer to the circle allocated struct in the heap
 * 
 * Returns:
 * (circle_t*) circle struct in the heap
 */
circle_t *circle_new(point_t *center, double r) {
    circle_t* circ = malloc(sizeof(circle_t));
    if (circ == NULL) {
        fprintf(stderr, "heap has no more space");
        exit(1);
    }

    circ->center = point_new(center->x, center->y);
    if (r > 0) {
        circ->r = r;
    } else {
        fprintf(stderr, "inputted negative radius");
        exit(1);
    }
    return circ;
}
  
/* Print a representation of the circle to f. 
 * 
 * Inputs:
 * f: (FILE*) file to output fprintf to
 * c: (circle_t*) circle struct
 *
 * Returns:
 * (void) prints the center and radius of the circle c
 */
void circle_show(FILE *f, circle_t *c) {
    fprintf(f, "Center: (%f, %f), Radius: %f\n", c->center->x, c->center->y, c->r);
}
  
/* Free the circle and its center 
 *
 * Inputs:
 * circ: (circ_t*) circle struct
 *
 * Returns:
 * (void) frees the deep copy from the heap
 */
void circle_free(circle_t *circ) {
    free(circ->center);
    free(circ);
}
  
/* Compute the length of the segment.
 *
 * Inputs:
 * s: (segment_t*) pointer to the segment struct in the heap
 *
 * Variables:
 * s_x: (double) the difference between the x's of both points in the segment
 * s_y: (double) the difference between the y's of both points in the segment
 *
 * Returns:
 * (double) distance formula applied to struct segment
 */
double segment_length(segment_t *s) {
    double s_x = s->b->x - s->a->x;
    double s_y = s->b->y - s->a->y;
    return sqrt(s_x*s_x + s_y*s_y);    
}
  
/* Compute the area of the circle using M_PI.
 * 
 * Inputs:
 * circ: (circle_t*) pointer to the circle struct in the heap
 *
 * Variables:
 * rad: (double) radius of circ
 *
 * Returns:
 * (double) pi * radius^2 of the circle - the area
 */
double circle_area(circle_t *circ) {
    double rad = circ->r;
    return M_PI * (rad*rad);
}
  
/* Test whether the point is strictly inside the circle.
 *
 * Inputs:
 * circ: (circle_t*) pointer to the circle struct in the heap
 * p: (point_t*) pointer to the point struct in the heap
 *
 * Variables:
 * d_x: (double) change in x of point and center of circle
 * d_y: (double) change in y of point and center of circle
 * dist: (double) distance formula applied to d_x and d_y
 *
 * Returns:
 * (int) pseudo boolean signifying truth value of contains
 */
int contains(circle_t *circ, point_t *p) {
    double d_x = p->x - circ->center->x;
    double d_y = p->y - circ->center->y;
    double dist = sqrt(d_x*d_x + d_y*d_y);
    if (dist < circ->r) {
        return 1;
    }
    return 0;
}
  
/* Return the horizontal diameter of the circle. 
 * 
 * Inputs:
 * circ: (circle_t*) pointer to the circle struct in heap
 *
 * Variables:
 * p1x: (double) left point x value of horizontal diameter
 * p2x: (double) right point x value of horizontal diameter
 * p1: (point_t*) pointer to left point of horizontal diameter
 * p2: (point_t*) pointer to right point of horizontal diameter
 * h_diam: (segment_t*) pointer to the segment struct created with p1 and p2
 *
 * Returns:
 * (segment_t*) h_diam - horizontal diameter
 */
segment_t *horiz_diameter(circle_t *circ) {
    double p1x = circ->center->x - circ->r;
    double p2x = circ->center->x + circ->r;
    point_t* p1 = point_new(p1x, circ->center->y);
    point_t* p2 = point_new(p2x, circ->center->y);
    segment_t* h_diam = segment_new(p1, p2);
    return h_diam;
}
  
/* Return the diameter that passes through the given point.
 * 
 * Inputs:
 * circ: (circle_t*) pointer to circle struct in heap
 * p: (point_t*) pointer to point struct in heap
 *
 * Variables:
 * diam: (segment_t*) pointer to the segment struct in the heap
 * center_x: (double) x coor of center of circ
 * center_y: (double) y coor of center of circ
 * delta_x: (double) change in x of p and center of circ
 * delta_y: (double) change in y of p and center of circ
 * theta: (double) angle formed by x-axis and diameter segment
 * _a: (double) x coor of point on circle of diameter
 * _b: (double) y coor of point on circle of diameter
 *
 * Returns:
 * (segment_t*) diameter through given point p
 */
segment_t *diameter_through(circle_t *circ, point_t *p) {
    segment_t* diam = malloc(sizeof(segment_t));
    if (diam == NULL) {
        fprintf(stderr, "heap has no more space");
        exit(1);
    }
    
    double center_x = circ->center->x;
    double center_y = circ->center->y;
    double delta_x = p->x - center_x;
    double delta_y = p->y - center_y;
    if (sqrt(delta_x*delta_x - delta_y*delta_y) > circ->r) {
        fprintf(stderr, "point does not lie on or in circle");
        exit(1);
    }

    double theta = atan(delta_y / delta_x);
    double _a = circ->r * cos(theta);
    double _b = circ->r * sin(theta);
    diam->a = point_new(_a + center_x, _b + center_y);
    diam->b = point_new(center_x - _a, center_y - _b);
    return diam;
}
  
/* Test whether the circles overlap one another.
 *
 * Inputs:
 * circ1: (circle_t*) pointer to circle struct in the heap
 * circ2: (circle_t*) pointer to circle struct in the heap
 *
 * Variables:
 * d_x: (double) x distance between centers of two circles
 * d_y: (double) y distance between centers of two circles
 * dist: (double) distance formula on the two differences
 *
 * Returns:
 * (int) pseudo boolean if circles overlap
 */
int overlap(circle_t *circ1, circle_t *circ2) {
    double r1 = circ1->r;
    double r2 = circ2->r;

    double d_x = circ2->center->x - circ1->center->x;
    double d_y = circ2->center->y - circ1->center->y;
    double dist = sqrt(d_x*d_x + d_y*d_y);

    if (dist < fabs(r1 - r2)) {
        // Concentric
        return 1;
    } else if (fabs(r1 - r2) < dist && dist < r1 + r2) {
        // Intersect at 2 Points
        return 1;
    } else if (dist == fabs(r1 - r2) || dist == r1 + r2) {
        // Intersect at 1 Point
        return 1;
    }
    return 0;
}

/* Build a new translated circle
 *
 * Inputs:
 * circ: (circle_t*) pointer to circle struct in heap
 * dx: (double) x translation
 * dy: (double) y translation
 *
 * Variables:
 * new_c: (circle_t*) new heap memory allocation for circle struct
 *
 * Returns:
 * (circle_t*) translated circle
 */
circle_t *circle_translate(circle_t *circ, double dx, double dy) {
    circle_t* new_c = malloc(sizeof(circle_t));
    if (new_c == NULL) {
        fprintf(stderr, "heap has no more space");
        exit(1);
    }

    new_c->center = point_new(circ->center->x + dx, circ->center->y + dy);
    new_c->r = circ->r;
    return new_c;
}
