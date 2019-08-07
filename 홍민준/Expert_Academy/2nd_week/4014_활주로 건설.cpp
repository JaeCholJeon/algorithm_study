//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int T, N, X;
int MAT[21][21];
int slope[21][21]; // 해당 위치에 경사로를 설치 했는지를 나타 냄(1이면 경사로가 설치 된 위치)
int answer;

int main()
{
	FILE *f = freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		// Implement your algorithm here.
		cin >> N >> X;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> MAT[i][j];
			}
		}

		memset(slope, 0, sizeof(int) * 21 * 21);
		answer = 0;
		for (int i = 1; i <= N; i++) { // 가로방향 확인
			int j = 1;
			int diff;
			while (j < N) {
				diff = MAT[i][j] - MAT[i][j + 1];
				if (diff == 0) { // 다음 위치와 높이가 같은 경우
					j++;
				}
				else if (diff == 1) { // 다음 위치의 높이가 1 낮은 경우
					int k;
					for (k = 1; k < X; k++) {
						if ((j + 1 + k) > N) { // (i, j+1)부터 시작하는 경사로가 지도를 벗어나면 안됨
							break;
						}
						if ((MAT[i][j] - MAT[i][j + 1 + k]) != diff) { // 경사로를 설치 하기 위해서는 (i, j)보다 1 낮은 평지가 X만큼 연속 되어야 함
							break;
						}
					}
					if (k < X) { // 경사로 설치를 위한 평지가 없는 경우
						break;
					}
					else { // 내려가는 경사로를 설치할 수 있는 경우
						for (k = 1; k <= X; k++) {
							slope[i][j + k] = 1;
						}
						j += X;
					}
				}
				else if (diff == -1) { // 다음 위치의 높이가 1 높은 경우
					int k;
					for (k = 1; k < X; k++) { // 위로 올라가는 경사로를 설치하기 위해서는 (i, j)에서 X-1 칸 뒤로 가야 한다.
						if (j - k < 1) {
							break;
						}
						if (MAT[i][j] != MAT[i][j - k] || slope[i][j - k] == 1) { // (i, j)에서 X-1 칸 뒤까지 (i, j)와 동일한 높이의 평지가 이어지지 않거나, 
																				// 이미 다른 경사로가 있다면 추가로 경사로를 설치 할 수 없다.
							break;
						}
					}

					if (k < X) { // 경사로 설치를 위한 평지가 없는 경우
						break;
					}
					else {
						for (k = 0; k < X; k++) {
							slope[i][j - k] = 1;
						}
						j += 1;
					}
				}
				else {
					break;
				}
			}

			if (j == N) {
				answer += 1;
			}

			memset(slope, 0, sizeof(int) * 21 * 21);
		}

		for (int j = 1; j <= N; j++) { // 세로방향 확인
			int i = 1;
			int diff;
			while (i < N) {
				diff = MAT[i][j] - MAT[i + 1][j];
				if (diff == 0) { // 다음 위치와 높이가 같은 경우
					i++;
				}
				else if (diff == 1) { // 다음 위치의 높이가 1 낮은 경우
					int k;
					for (k = 1; k < X; k++) {
						if ((i + 1 + k) > N) { // (i+1, j)부터 시작하는 경사로가 지도를 벗어나면 안됨
							break;
						}
						if ((MAT[i][j] - MAT[i + 1 + k][j]) != diff) { // 경사로를 설치 하기 위해서는 (i, j)보다 1 낮은 평지가 X만큼 연속 되어야 함
							break;
						}
					}
					if (k < X) { // 경사로 설치를 위한 평지가 없는 경우
						break;
					}
					else { // 내려가는 경사로를 설치할 수 있는 경우
						for (k = 1; k <= X; k++) {
							slope[i + k][j] = 1;
						}
						i += X;
					}
				}
				else if (diff == -1) { // 다음 위치의 높이가 1 높은 경우
					int k;
					for (k = 1; k < X; k++) { // 위로 올라가는 경사로를 설치하기 위해서는 (i, j)에서 X-1 칸 뒤로 가야 한다.
						if (i - k < 1) {
							break;
						}
						if (MAT[i][j] != MAT[i - k][j] || slope[i - k][j] == 1) { // (i, j)에서 X-1 칸 뒤까지 (i, j)와 동일한 높이의 평지가 이어지지 않거나, 
																				// 이미 다른 경사로가 있다면 추가로 경사로를 설치 할 수 없다.
							break;
						}
					}

					if (k < X) { // 경사로 설치를 위한 평지가 없는 경우
						break;
					}
					else {
						for (k = 0; k < X; k++) {
							slope[i - k][j] = 1;
						}
						i += 1;
					}
				}
				else {
					break;
				}
			}

			if (i == N) {
				answer += 1;
			}

			memset(slope, 0, sizeof(int) * 21 * 21);
		}

		cout << "#" << test_case + 1 << " " << answer << endl;
	}

	fclose(f);

	return 0;
}