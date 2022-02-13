// [21608] 상어 초등학교
// https://www.acmicpc.net/problem/21608

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, ans;
int map[21][21], order[401];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> favoriteStudentList[401];

typedef struct info {
	int favoriteNum;
	int emptyNum;
	int x;
	int y;
}info;

bool cmp(info a, info b) {
	if (a.favoriteNum > b.favoriteNum) {
        return true;
    }
	else if (a.favoriteNum == b.favoriteNum) {
		if (a.emptyNum > b.emptyNum) {
            return true;
        }
		else if (a.emptyNum == b.emptyNum) {
			if (a.x < b.x) {
                return true;
            }
			else if (a.x == b.x) {
				if (a.y < b.y) return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

void input()
{
    int student, favoriteStudent;
    cin >> n;
	for (int i = 0; i < n*n; i++) {
		cin >> student;
		for (int j = 0; j < 4; j++) {
			cin >> favoriteStudent;
			favoriteStudentList[student].push_back(favoriteStudent);
		}
		order[i] = student;
	}
}

void selectSeat(int student) {
	vector<info> options;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
            if(map[i][j] != 0) {
                continue;
            }
			info curInfo = { 0,0,i,j };
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    continue;
                }
                if (map[nx][ny] == 0) {
                    curInfo.emptyNum++;
                }
                else if (map[nx][ny] != 0) {
                    for (int l = 0; l < 4; l++) {
                        if (map[nx][ny] == favoriteStudentList[student][l]) {
                            curInfo.favoriteNum++;
                            break;
                        }
                    }
                }
            }
            options.push_back(curInfo);
		}
	}
	sort(options.begin(), options.end(), cmp);
	map[options[0].x][options[0].y] = student;
}

void getSatisfaction(int x, int y) 
{
    int satisfaction = 0;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
        }
        for (int l = 0; l < 4; l++) {
            if (favoriteStudentList[map[x][y]][l] == map[nx][ny]) {
                satisfaction++;
                break;
            }
        }
    }
    ans += pow(10, satisfaction - 1);
}

void solve() {
	for (int i = 0; i < n*n; i++) {
		selectSeat(order[i]);
	}
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            getSatisfaction(i, j);
        }
    }
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    input();
	solve();
	return 0;
}