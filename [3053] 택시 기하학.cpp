//[3053] 택시 기하학
// https://www.acmicpc.net/problem/3053
// 택시 기하학 -> 원은 마름모 모양 -> 원의 넓이 = 2*r*r

#include <iostream>
#include <cstdio>
using namespace std;

#define M_PI 3.14159265358979323846

int main(void)
{
	double r; //r은 100000보다 같거나 작은 자연수

	cin >> r;

	printf("%.6f\n", M_PI*r*r);
	printf("%.6f\n", 2 * r*r);
}