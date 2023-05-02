//
// Created by tobin on 5/1/2023.
//

#ifndef VECTORMATH_VECTOR3_H
#define VECTORMATH_VECTOR3_H

#endif //VECTORMATH_VECTOR3_H

typedef struct Vector3 {
    float x;
    float y;
    float z;
} Vector3;

char *Vector3_ToString(Vector3 *a);

void Vector3_Destroy(Vector3 *a);

Vector3 *Vector3_Create(float x, float y, float z);

Vector3 *Vector3_Add(Vector3 *a, Vector3 *b);

Vector3 *Vector3_Subtract(Vector3 *a, Vector3 *b);

Vector3 *Vector3_Multiply(Vector3 *a, float b);

Vector3 *Vector3_Cross(Vector3 *v1, Vector3 *v2);

float Vector3_Dot(Vector3 *v1, Vector3 *v2);

float Vector3_Distance(Vector3 *a, Vector3 *b);

float Vector3_Magnitude(Vector3 *v);

Vector3 *Vector3_Normalize(Vector3 *a);

Vector3 *Vector3_Divide(Vector3 *a, float b);
