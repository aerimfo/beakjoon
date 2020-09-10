// [2437] 저울
// https://www.acmicpc.net/problem/2437
// 그리디 알고리즘

#include <cstdio> 
#include <vector> 
#include <algorithm> 
using namespace std; 

int main() 
{ 
	int n, tmp, sum = 1; 
	scanf("%d", &n);
	vector<int> weight; 
	for (int i = 0; i < n; i++) { 
		scanf("%d", &tmp);
		weight.push_back(tmp); 
	} 
	
	sort(weight.begin(), weight.end()); 

	if (weight[0] != 1) {
		printf("1\n");
	}
	else { 
		for (int i = 1; i < n; ++i) { 
			if (weight[i] > sum + 1) {
				break; 
			}
			sum += weight[i]; 
		} 
		
		printf("%d\n", sum + 1);
	} 
}
