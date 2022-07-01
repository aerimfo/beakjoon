// [1713] 후보 추천하기
// 구현, 시뮬레이션
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector <pair<int, int> > photo; // <학생번호, 추천 수>

void removePhoto()
{
	int minRecommend = photo[0].second;
   
    for(int i = 0; i < photo.size(); i++) {
		minRecommend = min(minRecommend, photo[i].second);
	}

	for(int i = 0; i < photo.size(); i++){
		if (minRecommend == photo[i].second) {
			photo.erase(photo.begin() + i); 
			break;
		}
	}
}

void solution(int student)
{
    bool flag = false;
    for(int i = 0; i < photo.size(); i++) { 
        if(student == photo[i].first) { // 이미 추천된 후보
            flag = true; 
            photo[i].second++; 
            return;
        }
    }

    if(flag == false) { // 새로운 후보
        if(photo.size() <= n) {
            if(photo.size() == n) { // 빈 사진틀 없는 경우
                removePhoto(); 
            }
            photo.push_back(make_pair(student, 1));
        }
    }
}

void input()
{
    int student;
    cin >> n;
	cin >> k;
    for(int i = 0; i < k; i++) {
		cin >> student;
        solution(student);
    }
}

void output()
{
    sort(photo.begin(), photo.end());
    for(int i = 0; i < photo.size(); i++) {
		cout << photo[i].first << " ";
	}
}

int main()
{
    input();
    output();
	return 0;
}