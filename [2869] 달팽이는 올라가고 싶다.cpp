#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
	long a, b, v; /*낮에 올라감, 밤에 내려옴, 나무 막대의 길이*/
	long now = 0; /*현재 달팽이의 위치*/
	int day;
	scanf("%d %d %d", &a, &b, &v);
	day = (v - b - 1) / (a - b) + 1;
	printf("%d", day);
}