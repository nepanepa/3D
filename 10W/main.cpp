#include <iostream>
#include <stdio.h>
#include "Musoenmath.h"

using namespace std;

int main()
{
    //�ﰢ�Լ� ����
    const float sam = 3.1415926;
    double abc = sin(30 * sam / 180);
    double efg = cos(30 * sam / 180);

    //��ǥ �ʱⰪ(1,1,1) �ʱ�ȭ
    vec3 vec = vec3(1, 1, 1);

    //(3,5)�̵���� �ʱ�ȭ
    mat3 Translate = mat3(1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        3.0, 5.0, 1.0);
    //30�� ȸ����� �ʱ�ȭ
    mat3 Rotate = mat3(efg, -abc, 0.0,
        abc, efg, 0.0,
        0.0, 0.0, 1.0);
    //2�� Ȯ�� ������ ��� �ʱ�ȭ
    mat3 Scale = mat3(2.0, 0.0, 0.0,
        0.0, 2.0, 0.0,
        0.0, 0.0, 1.0);

    //����� ��ǥ = �ʱⰪ * �̵���� * ȸ����� * ���������
    vec3 p = vec * Translate * Rotate * Scale;
    //���� ��ǥ�� ���
    cout << p.x << " " << p.y << " " << " " << p.z << endl;

}