#include "obj.h"

/* ivec2 functions */
void ivec2_print(ivec2 coord) {
    printf("coordinate: (%i|%i)\n", coord.x, coord.y);
}


ivec2 ivec2_add(ivec2 a, ivec2 b) {
    ivec2 res = {
        .x = a.x + b.x,
        .y = a.y + b.y
    };
    return res;
}
ivec2 ivec2_mul_s(ivec2 v, int32_t s) {
    ivec2 res = {
        .x = v.x * s,
        .y = v.y * s
    };
    return res;
}

double ivec2_distance(ivec2 a, ivec2 b) {
    ivec2 temp = ivec2_add(a, ivec2_mul_s(b, -1));
    return sqrt((double) (temp.x * temp.x + temp.y * temp.y));
}


/* circle functions */
char Circle_check_collision(Circle a, Circle b) {
    int32_t dist = ivec2_distance(a.center, b.center);
    dist -= a.radius + b.radius;

    return dist < 0 ? 1 : 0;
}

Circle Circle_init_rand(int32_t maxCoord, int32_t maxRadius) {
    Circle newCircle;
    newCircle.center.x = rand() % (maxCoord * 2) - maxCoord;
    newCircle.center.y = rand() % (maxCoord * 2) - maxCoord;
    newCircle.radius = rand() % (maxRadius);

    return newCircle;
}

void Circle_print_array(Circle* arr, uint32_t arr_length, int32_t width, int32_t height) {
    ivec2 pos;

    for(pos.y = height/2; pos.y > -height/2; pos.y--) {
        for(pos.x = -width/2; pos.x < width/2; pos.x++) {

            char symbol = ' ';
            for(uint32_t i = 0; i < arr_length; i++) {
                double dist = ivec2_distance(arr[i].center, pos);
                
                if(dist < 1.0) {
                    if(i < 10) printf("%i ", i);
                    else printf("%i", i);
                    goto Printed;
                }
                else if(symbol == ' ' && dist < (double)arr[i].radius) {
                    if((double)arr[i].radius - dist < 1.1)
                        symbol = '#';
                    else
                        symbol = '.';
                }
            }
            printf("%c ", symbol);

            Printed:
        }
        printf("\n");
    }
}