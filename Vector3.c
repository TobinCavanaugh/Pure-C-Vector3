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
    int digits = (long) strlen(array_buf);

    //If theres a negative symbol
    if(n < 0){
        digits++;
    }

    // free memory allocated for string
    free(array_buf);
    return digits;
}

void Vector3_Destroy(Vector3 *a) {
    free(a);
}

char *Vector3_ToString(const Vector3 *a) {

    const int xSize = DigitCount(a->x);
    const int ySize = DigitCount(a->y);
    const int zSize = DigitCount(a->z);

    //This slightly overallocates but tbh its not a concern, at worst it'll be 3 or so extra chars

    //                   parenthesis \/      \/ null terminator
    int val = xSize + ySize + zSize + 2 + 3 + 1 + 3;
    //                             commas ^ _____ ^ decimals


    char *dat = malloc(val);

    sprintf(dat, "(%g,%g,%g)", a->x, a->y, a->z);

    dat[val - 1] = '\0';

    return dat;
}


void Vector3_Print(const Vector3 *a) {
    char * str = Vector3_ToString(a);
    printf("%s\n", str);
    free(str);
}

Vector3 *Vector3_Add(const Vector3 *a, const Vector3 *b) {
    var v = Vector3_Create(a->x + b->x, a->y + b->y, a->z + b->z);
    return v;
}

Vector3 *Vector3_Subtract(const Vector3 *a, const Vector3 *b) {
    var v = Vector3_Create(a->x - b->x, a->y - b->y, a->z - b->z);
    return v;
}


Vector3 *Vector3_Normalize(const Vector3 *a) {

    float val = Vector3_Magnitude(a);

    return Vector3_Create(a->x / val, a->y / val, a->z / val);
}

Vector3 *Vector3_Cross(const Vector3 *v1, const Vector3 *v2) {

    var x = v1->y * v2->z - v1->z * v2->y;
    var y = v1->z * v2->x - v1->x * v2->z;
    var z = v1->x * v2->y - v1->y * v2->x;

    var v = Vector3_Create(x, y, z);
    return v;
}

float Vector3_Dot(const Vector3 *v1, const Vector3 *v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}


float Vector3_Magnitude(const Vector3 *v) {
    return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
}

float Vector3_Distance(const Vector3 *a, const Vector3 *b) {
    var sub = Vector3_Subtract(a, b);
    float mag = Vector3_Magnitude(sub);
    free(sub);
    return mag;
}


Vector3 *Vector3_Multiply(const Vector3 *a, float b) {
    var v = Vector3_Create(a->x * b, a->y * b, a->z * b);
    return v;
}



Vector3 *Vector3_Divide(const Vector3 *a, float b) {
    var v = Vector3_Create(a->x / b, a->y / b, a->z / b);
    return v;
}


Vector3 *Vector3_Create(const float x, const float y, const float z) {
    Vector3 *vec = malloc(sizeof(Vector3));

    vec->x = x;
    vec->y = y;
    vec->z = z;

    return vec;
}
