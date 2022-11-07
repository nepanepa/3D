#include <iostream>
#include <stdio.h>
#include "Musoenmath.h"

using namespace std;

int main()
{
    //삼각함수 선언
    const float sam = 3.1415926;
    double abc = sin(30 * sam / 180);
    double efg = cos(30 * sam / 180);

    //좌표 초기값(1,1,1) 초기화
    vec3 vec = vec3(1, 1, 1);

    //(3,5)이동행렬 초기화
    mat3 Translate = mat3(1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        3.0, 5.0, 1.0);
    //30도 회전행렬 초기화
    mat3 Rotate = mat3(efg, -abc, 0.0,
        abc, efg, 0.0,
        0.0, 0.0, 1.0);
    //2배 확대 스케일 행렬 초기화
    mat3 Scale = mat3(2.0, 0.0, 0.0,
        0.0, 2.0, 0.0,
        0.0, 0.0, 1.0);

    //결과값 좌표 = 초기값 * 이동행렬 * 회전행렬 * 스케일행렬
    vec3 p = vec * Translate * Rotate * Scale;
    //최종 좌표값 출력
    cout << p.x << " " << p.y << " " << " " << p.z << endl;

}