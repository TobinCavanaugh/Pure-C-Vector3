//
// Created by tobin on 5/1/2023.
//

#include <malloc.h>
#include "Vector3.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

#define var __auto_type

/// This is slow as hell, but too bad
/// \param n
/// \return
int DigitCount(float n) {

    //Get the size of float
    int size = snprintf(NULL, 0, "%d", n);

    //Allocate the string into array_buf
    char *array_buf = malloc(size + 1);

    //Convert to a string
    sprintf(array_buf, "%d", n);

    //Get the length of the string of the float
    int digits = strlen(array_buf);

    // free memory allocated for string
    free(array_buf);
    return digits;
}

void Vector3_Destroy(Vector3 *a) {
    free(a);
}

char *Vector3_ToString(Vector3 *a) {

    const int xSize = DigitCount(a->x);
    const int ySize = DigitCount(a->y);
    const int zSize = DigitCount(a->z);

    //                   parenthesis \/      \/ null terminator
    int val = xSize + ySize + zSize + 2 + 3 + 1;
    //                             commas ^


    char *dat = malloc(val);

    sprintf(dat, "(%g,%g,%g)", a->x, a->y, a->z);

    dat[val - 1] = '\0';

    return dat;
}

Vector3 *Vector3_Add(Vector3 *a, Vector3 *b) {
    var v = Vector3_Create(a->x + b->x, a->y + b->y, a->z + b->z);
    return v;
}

Vector3 *Vector3_Subtract(Vector3 *a, Vector3 *b) {
    var v = Vector3_Create(a->x - b->x, a->y - b->y, a->z - b->z);
    return v;
}


Vector3 *Vector3_Normalize(Vector3 *a) {

    float val = Vector3_Magnitude(a);

    return Vector3_Create(a->x / val, a->y / val, a->z / val);
}

Vector3 *Vector3_Cross(Vector3 *v1, Vector3 *v2) {

    var x = v1->y * v2->z - v1->z * v2->y;
    var y = v1->z * v2->x - v1->x * v2->z;
    var z = v1->x * v2->y - v1->y * v2->x;

    var v = Vector3_Create(x, y, z);
    return v;
}

float Vector3_Dot(Vector3 *v1, Vector3 *v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}


float Vector3_Magnitude(Vector3 *v) {
    return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
}

float Vector3_Distance(Vector3 *a, Vector3 *b) {
    return Vector3_Magnitude(Vector3_Subtract(a, b));
}


Vector3 *Vector3_Multiply(Vector3 *a, float b) {
    var v = Vector3_Create(a->x * b, a->y * b, a->z * b);
    return v;
}


Vector3 *Vector3_Divide(Vector3 *a, float b) {
    var v = Vector3_Create(a->x / b, a->y / b, a->z / b);
    return v;
}


Vector3 *Vector3_Create(float x, float y, float z) {
    Vector3 *vec = malloc(sizeof(Vector3));

    vec->x = x;
    vec->y = y;
    vec->z = z;

    return vec;
}
