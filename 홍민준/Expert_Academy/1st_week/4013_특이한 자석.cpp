//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int T, K;
int answer;
int magnet[5][9]; // 각 자석의 극 방향
int avail[5]; // 각 자석의 회전여부

inline void clockwise_rotate(int m) // 시계 방향 회전의 구현.
{
	int tmp;

	tmp = magnet[m][1]; // 첫 번째 날의 값은 먼저 마지막날의 값으로 덮어 써지므로, 미리 값을 저장해 두고, 마지막에 두번째 날의 위치로 옮겨준다.
	magnet[m][1] = magnet[m][8]; // 자석의 맨 마지막 날의 값은 자석의 맨 처음 날의 위치(화살표 위치)로 가야 하므로, 미리 옮겨 준다.
	for (int j = 7; j >= 2; j--) {
		magnet[m][j + 1] = magnet[m][j];
	}
	magnet[m][2] = tmp;
}

inline void counter_clockwise_rotate(int m) // 반시계 방향 회전의 구현.
{
	int tmp;

	tmp = magnet[m][1]; // 맨 처음 날의 값은 두번째 날의 값으로 덮어 써지므로, 미리 값을 저장해 두고, 마지막에 마지막 날의 위치로 옮겨준다.
	for (int j = 2; j <= 8; j++) {
		magnet[m][j - 1] = magnet[m][j];
	}
	magnet[m][8] = tmp;
}

inline void calculate() // 현재 화살표 위치의 극의 방향에 따라 점수 계산
{
	int p = 1;

	for (int i = 1; i <= 4; i++) {
		if (magnet[i][1] == 1) {
			answer += p;
		}
		p <<= 1;
	}
}

int main()
{
	FILE *f = freopen("sample_input.txt", "r", stdin);
	int m, dir, cur;

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		// Implement your algorithm here.
		cin >> K;
		answer = 0;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 8; j++) {
				cin >> magnet[i][j];
			}
		}

		for (int i = 0; i < K; i++) {
			cin >> m >> dir;

			memset(avail, 0, sizeof(int) * 5);

			// 접해있는 자석들이 회전해야 할지 확인 한다.
			for (int j = m - 1; j >= 1; j--) { // 회전할 자석(m)의 좌측부터 확인
				if (magnet[j][3] == magnet[j + 1][7]) {
					break;
				}
				avail[j] = 1;
			}
			for (int j = m + 1; j <= 4; j++) { // 회전할 자석의 우측도 확인
				if (magnet[j-1][3] == magnet[j][7]) {
					break;
				}
				avail[j] = 1;
			}

			cur = dir;
			for (int j = m - 1; j >= 1; j--) { // 회전할 자석(m)의 좌측에 있는 자석 부터 회전 시킨다.
				if (avail[j] == 0) { // 이번에 돌릴 자석(i)과 그 오른쪽에 있는 자석의 극이 같은 위치 부터는 회전하지 않는다.
					break;
				}

				cur *= -1;
				if (cur == 1) { // 회전할 자석(m)을 기준으로, 회전 방향이 반대로 계속 바뀐다. e.g. m이 시계 방향이면 m+1은 반시계 방향 m+2는 시계 방향
					clockwise_rotate(j);
				}
				else { // cur == -1
					counter_clockwise_rotate(j);
				}
			}

			cur = dir;
			for (int j = m + 1; j <= 4; j++) { // 돌릴 자석의 우측에 있는 자석도 회전 시킨다.
				if (avail[j] == 0) { // 이번에 돌릴 자석(j)과 그 왼쪽에 있는 자석의 극이 같은 위치 부터는 회전하지 않는다.
					break;
				}

				cur *= -1;
				if (cur == 1) {
					clockwise_rotate(j);
				}
				else { // cur == -1
					counter_clockwise_rotate(j);
				}
			}

			// 돌릴 자석의 좌, 우에 있는 자석들을 모두 회전 시켰으므로, 이제 돌릴 자석(m)도 회전 시킨다.
			if (dir == 1) {
				clockwise_rotate(m);
			}
			else {
				counter_clockwise_rotate(m);
			}
		}
		calculate();

		cout << "#" << test_case + 1 << " " << answer << endl;
	}

	fclose(f);

	return 0;
}