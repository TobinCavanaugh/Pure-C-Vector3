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

char *Vector3_ToString(const Vector3 *a);

float Vector3_Distance(const Vector3 *a, const Vector3 *b);

float Vector3_Dot(const Vector3 *v1, const Vector3 *v2);

float Vector3_Magnitude(const Vector3 *v);

Vector3 *Vector3_Add(const Vector3 *a, const Vector3 *b);

Vector3 *Vector3_Create(float x, float y, float z);

Vector3 *Vector3_Cross(const Vector3 *v1, const Vector3 *v2);

Vector3 *Vector3_Divide(const Vector3 *a, float b);

Vector3 *Vector3_Multiply(const Vector3 *a, float b);

Vector3 *Vector3_Normalize(const Vector3 *a);

Vector3 *Vector3_Subtract(const Vector3 *a,const  Vector3 *b);

void Vector3_Destroy(Vector3 *a);

void Vector3_Print(const const Vector3 *a);