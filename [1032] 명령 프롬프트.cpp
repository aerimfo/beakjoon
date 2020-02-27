// [1032] 명령 프롬프트
// https://www.acmicpc.net/problem/1032

#include <iostream>
#include <cstring>
using namespace std;
int n; // number of files(n <= 50)
char fileName[51][51];
void compare();

int main(void)
{
	int temp;
	cin >> n;
	temp = n;
	while (temp--)
		cin >> fileName[temp];

	if (n == 1)
		cout << fileName[0];
	else
		compare();
}

void compare()
{
	char pattern[51];
	int length = strlen(fileName[0]); // length of filename

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < n - 1; j++) {
			// 문자가 모두 같은 경우
			if (fileName[j][i] == fileName[j + 1][i]) {
				if (j == n - 2)
					pattern[i] = fileName[0][i];
			}
			else {
				pattern[i] = '?';
				break;
			}

		}
		cout << pattern[i];
	}

	cout << endl;
}