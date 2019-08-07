//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct BC {
	int y;
	int x;
	int c; // 충전 범위
	int p; // 성능
};

int T;
int M; // 총 이동 시간
int A; // BC(Battery Chager)의 숫자
struct BC chargers[8];
long long answer;

int A_M[101];
int A_valid[9];
int A_y, A_x;
int B_M[101];
int B_valid[9];
int B_y, B_x;

int dr[5] = {0, -1, 0, 1, 0};
int dc[5] = {0, 0, 1, 0, -1};

void find_BC()
{
	int diff;
	// A의 현재 위치에서 충전 가능한 BC를 찾는다.
	for (int i = 0; i < A; i++) {
		diff = (abs(chargers[i].y - A_y) + abs(chargers[i].x - A_x));
		if (diff <= chargers[i].c) { // 현재 위치에서 i번째 BC의 영역에 들어 가는 경우
			A_valid[i] = 1;
		}
		else {
			A_valid[i] = 0;
		}
	}

	// B의 현재 위치에서 충전 가능한 BC를 찾는다.
	for (int i = 0; i < A; i++) {
		diff = (abs(chargers[i].y - B_y) + abs(chargers[i].x - B_x));
		if (diff <= chargers[i].c) { // 현재 위치에서 i번째 BC의 영역에 들어 가는 경우
			B_valid[i] = 1;
		}
		else {
			B_valid[i] = 0;
		}
	}
}

int find_max()
{
	int max = 0;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			if (A_valid[i] && B_valid[j]) { // A와 B가 둘 다 한 곳 이상의 BC에서 충전이 가능한 경우
				if (i == j) { // A와 B가 둘 다 같은 BC에서 충전하는 경우
					if (max < chargers[i].p) {
						max = chargers[i].p;
					}
				}
				else {
					if (max < (chargers[i].p + chargers[j].p)) {
						max = (chargers[i].p + chargers[j].p);
					}
				}
			}
			else if (A_valid[i]) { // A만 한 곳 이상의 BC에서 충전이 가능한 경우
				if (max < chargers[i].p) {
					max = chargers[i].p;
				}
			}
			else if (B_valid[j]) { // B만 한 곳 이상의 BC에서 충전이 가능한 경우
				if (max < chargers[j].p) {
					max = chargers[j].p;
				}
			}
		}
	}

	return max;
}

int main()
{
	FILE *f = freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		// Implement your algorithm here.
		cin >> M >> A;

		for (int i = 0; i < M; i++) {
			cin >> A_M[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> B_M[i];
		}

		for (int i = 0; i < A; i++) {
			cin >> chargers[i].x;
			cin >> chargers[i].y;
			cin >> chargers[i].c;
			cin >> chargers[i].p;
		}

		A_y = A_x = 1;
		B_y = B_x = 10;

		answer = 0;

		find_BC();
		answer += find_max();
		for (int i = 0; i < M; i++) {
			// 이동
			A_y += dr[A_M[i]];
			A_x += dc[A_M[i]];
			B_y += dr[B_M[i]];
			B_x += dc[B_M[i]];

			// 현재 A와 B의 위치에서 충전 가능한 BC를 찾는다.
			find_BC();
			// 사용 가능한 BC들로 만들수 있는 모든 경우의 수 중에서, 가장 많은 전력을 충전할 수 있는 경우를 찾는다.
			answer += find_max();
		}
		
		cout << "#" << test_case + 1 << " " << answer << endl;
	}

	fclose(f);

	return 0;
}