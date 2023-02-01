#include "obj.h"

#define MAX_COORD  50
#define MAX_RADIUS 20

int main(void) {
    // a
    ivec2 p1 = {
        .x = 10, .y = 20
    };

    ivec2 p2 = {
        .x = -4, .y = 3
    };

    printf("distance(p1, p2): %.3lf\n", ivec2_distance(p1, p2));


    // b
    // c
    srand(time(NULL));

    uint32_t n;
    printf("Please enter a number of circles to generate: ");
    scanf("%i", &n);

    Circle* circle_array = malloc(n * sizeof(Circle));
    for(uint32_t i = 0; i < n; i++) {
        circle_array[i] = Circle_init_rand(MAX_COORD, MAX_RADIUS);
        printf("radius: %i ", circle_array[i].radius);
        ivec2_print(circle_array[i].center);
    }

    for(uint32_t i = 0; i < n; i++) {
        for(uint32_t j = i + 1; j < n; j++) {
            if(Circle_check_collision(circle_array[i], circle_array[j]))
                printf("Collision between elements %i and %i\n", i, j);
        }
    }

    Circle_print_array(circle_array, n, MAX_COORD * 2, MAX_COORD * 2);

    free(circle_array);

    return 1;
}