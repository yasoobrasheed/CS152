#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

/*
int main() {
    draw_waves(500, 0, 0, 0.14, 0.15, 0.11);
    return 0;
}
*/

int main(int argc, char *argv[]) {
    
    int s_l = 200;
    int x_o = 0;
    int y_o = 0;
    double red = 1.0;
    double green = 1.0;
    double blue = 1.0;
    
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-') {
                switch (argv[i][1]) {
                    case 's':
                        s_l = atoi(argv[i + 1]);
                        break;
                    case 'x':
                        x_o = atoi(argv[i + 1]);
                        break;
                    case 'y':
                        y_o = atoi(argv[i + 1]);
                        break;
                    case 'r':
                        red = atof(argv[i + 1]);
                        break;
                    case 'g':
                        green = atof(argv[i + 1]);
                        break;
                    case 'b':
                        blue = atof(argv[i + 1]);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    draw_waves(s_l, x_o, y_o, red, green, blue);
    return 0;
}

