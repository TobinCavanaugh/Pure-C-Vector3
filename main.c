#include <stdio.h>
#include "Vector3.h"
#include <math.h>

#define var __auto_type

#include <assert.h>
#include <malloc.h>

void AddTest() {
    printf("Adding: \n");

    Vector3 a = {1.0f, 2.0f, 3.0f};
    Vector3 b = {4.0f, 5.0f, 6.0f};
    Vector3 *result = Vector3_Add(&a, &b);
    printf("%d", result->x == 5.0f);
    printf("%d", result->y == 7.0f);
    printf("%d", result->z == 9.0f);

    free(result);
}

void SubtractTest() {
    printf("\nSubtracting\n");

    Vector3 a = {1.0f, 2.0f, 3.0f};
    Vector3 b = {4.0f, 5.0f, 6.0f};
    Vector3 *result = Vector3_Subtract(&a, &b);
    printf("%d",result->x == -3.0f);
    printf("%d",result->y == -3.0f);
    printf("%d",result->z == -3.0f);

    free(result);
}

void MultiplyTest() {
    printf("\nMultiplying\n");

    Vector3 a = {1.0f, 2.0f, 3.0f};
    float scalar = 2.0f;
    Vector3 *result = Vector3_Multiply(&a, scalar);
    printf("%d",result->x == 2.0f);
    printf("%d",result->y == 4.0f);
    printf("%d",result->z == 6.0f);
    free(result);
}

void DivideTest() {
    printf("\nDividing\n");

    Vector3 a = {1.0f, 2.0f, 3.0f};
    float scalar = 2.0f;
    Vector3 *result = Vector3_Divide(&a, scalar);
    printf("%d",result->x == 0.5f);
    printf("%d",result->y == 1.0f);
    printf("%d",result->z == 1.5f);
    free(result);
}

void DotTest(){

    printf("\nDot product\n");

    Vector3 a = {1.0f, 2.0f, 3.0f};
    Vector3 b = {4.0f, 5.0f, 6.0f};
    float result = Vector3_Dot(&a, &b);
    printf("%d",result == 32.0f);
}

void MagTest(){

    printf("\nMagnitude\n");

    Vector3 a = {1.0f, 2.0f, 3.0f};
    float result = Vector3_Magnitude(&a);
    printf("%d",result == sqrtf(14.0f));

}

void NormalizeTest(){
    Vector3 a = {1.0f, 2.0f, 3.0f};
    Vector3 * result = Vector3_Normalize(&a);
    float magnitude = Vector3_Magnitude(result);
    printf("%d",magnitude == 1.0f);

}

int main() {

    AddTest();
    SubtractTest();
    MultiplyTest();
    DivideTest();
    DotTest();
    MagTest();

    //Yay passing all tests
    //Yipee

    return 0;
}
