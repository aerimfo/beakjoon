// [1931] 회의실배정
// https://www.acmicpc.net/problem/1931
// 그리디 알고리즘

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, cnt = 1; // 회의의 수, 사용할 수 있는 회의 수
	vector<pair<int, int> > meet; // 회의의 정보
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int start, end; // 회의 시작 시간, 끝나는 시간
		scanf("%d %d", &start, &end);
		meet.push_back(make_pair(start, end));
	}

	sort(meet.begin(), meet.end()); // 회의 시작 시간 기준으로 오름차순 정렬
	/*vector<pair<int, int>> v 꼴인 경우 sort는 디폴트로 first 기준 오름차순 정렬*/

	int tmp = meet[n-1].first;
	for (int i = n - 2; i >= 0; i--) { // 시작 시간이 가장 늦은 것부터 탐색
		if (tmp >= meet[i].second) { // 현재 회의 시작 시간 >= 이전 회의 종료 시간
			cnt++;
			tmp = meet[i].first;
		}
	}
	printf("%d\n", cnt);
}