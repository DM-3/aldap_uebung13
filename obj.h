#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int32_t x;
    int32_t y;
} ivec2;

void ivec2_print(ivec2);

ivec2 ivec2_add(ivec2, ivec2);
ivec2 ivec2_mul_s(ivec2, int32_t);

double ivec2_distance(ivec2, ivec2);



typedef struct {
    ivec2 center;
    int32_t radius;
} Circle;

char Circle_check_collision(Circle, Circle);

Circle Circle_init_rand(int32_t, int32_t);

void Circle_print_array(Circle*, uint32_t, int32_t, int32_t);