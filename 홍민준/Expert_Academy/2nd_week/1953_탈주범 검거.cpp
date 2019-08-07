//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T, N, M, R, C, L;
int MAT[50][50];
int visited[50][50]; // 중복 탐색을 막기 위해 사용하는 배열. 해당 위치의 값이 1이면 그 위치는 이미 방문한 것이다.
int answer;

struct Info {
	int y;
	int x;
	int left; // 남은 시간
};

// 상->우->하->좌 순서로 이동하기 위한 offset을 넣은 배열. e.g. 배열의 index가 0이면 y값이 1 감소 하므로 상단으로 이동하는 것임
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

queue<Info> Q;

// 현재 위치의 관이 뚫려 있는 방향의 관과 연결될 수 있는지 확인하는 함수
// e.g. 현재 위치의 관이 2(상,하)라면, 상단의 관은 1, 2, 5, 6만 가능하다.
bool is_connected(int nxt_y, int nxt_x, int shape)
{
	bool ret = false;

	if (MAT[nxt_y][nxt_x] == 1) { // 1 관은 무조건 연결 된다.
		ret = true;
	}
	else {
		switch (shape) {
		case 0: // 상단의 관을 확인
			if (MAT[nxt_y][nxt_x] == 2 || MAT[nxt_y][nxt_x] == 5 || MAT[nxt_y][nxt_x] == 6) {
				ret = true;
			}
			break;
		case 1: // 우측의 관을 확인
			if (MAT[nxt_y][nxt_x] == 3 || MAT[nxt_y][nxt_x] == 6 || MAT[nxt_y][nxt_x] == 7) {
				ret = true;
			}
			break;
		case 2: // 하단의 관을 확인
			if (MAT[nxt_y][nxt_x] == 2 || MAT[nxt_y][nxt_x] == 4 || MAT[nxt_y][nxt_x] == 7) {
				ret = true;
			}
			break;
		case 3: // 좌측의 관을 확인
			if (MAT[nxt_y][nxt_x] == 3 || MAT[nxt_y][nxt_x] == 4 || MAT[nxt_y][nxt_x] == 5) {
				ret = true;
			}
			break;
		}
	}

	return ret;
}

int main()
{
	FILE *f = freopen("sample_input.txt", "r", stdin);
	struct Info a, b;

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		// Implement your algorithm here.
		while (!Q.empty()) { // Queue를 비우는 함수를 따로 지원하지 않으므로, 수동으로 비워준다.
			Q.pop();
		}
		memset(visited, 0, sizeof(int) * 50 * 50);

		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> MAT[i][j];
			}
		}

		answer = 0;
		a.y = R;
		a.x = C;
		a.left = L;
		Q.push(a);
		visited[a.y][a.x] = 1;
		answer += 1;
		int nxt_y, nxt_x;
		while (!Q.empty()) {
			b = Q.front();
			Q.pop();

			if (b.left > 1) { // 이 문제에서는 시간이 1시간 남았을 때, 더 이상 못움직이는 것으로 조건이 주어졌다.
				switch (MAT[b.y][b.x]) { // 현재 위치의 관의 종류가
				case 1: // 상,하,좌,우
					for (int i = 0; i < 4; i++) {
						nxt_y = b.y + dr[i];
						nxt_x = b.x + dc[i];
						// BFS 탐색을 계속 하는 조건은,
						// 1.이동할 위치가 MAP을 벗어나지 않을 것, 2. 이동할 위치의 관과 현재 위치의 관이 연결 되는 종류일 것, 3. 중복 탐색을 막기 위해 방문하지 않은 위치일 것
						if (nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < M && is_connected(nxt_y, nxt_x, i) && visited[nxt_y][nxt_x] != 1) {
							visited[nxt_y][nxt_x] = 1;
							answer += 1;
							a.y = nxt_y;
							a.x = nxt_x;
							a.left = b.left - 1; // 남은 시간을 1 줄이고
							Q.push(a); // Q에 push 한다.
						}
					}
					break;
				case 2: // 상,하
					for (int i = 0; i < 4; i++) {
						if (i == 1 || i == 3)
							continue;
						nxt_y = b.y + dr[i];
						nxt_x = b.x + dc[i];
						if (nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < M && is_connected(nxt_y, nxt_x, i) && visited[nxt_y][nxt_x] != 1) {
							visited[nxt_y][nxt_x] = 1;
							answer += 1;
							a.y = nxt_y;
							a.x = nxt_x;
							a.left = b.left - 1;
							Q.push(a);
						}
					}
					break;
				case 3: // 좌,우
					for (int i = 0; i < 4; i++) {
						if (i == 0 || i == 2)
							continue;
						nxt_y = b.y + dr[i];
						nxt_x = b.x + dc[i];
						if (nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < M && is_connected(nxt_y, nxt_x, i) && visited[nxt_y][nxt_x] != 1) {
							visited[nxt_y][nxt_x] = 1;
							answer += 1;
							a.y = nxt_y;
							a.x = nxt_x;
							a.left = b.left - 1;
							Q.push(a);
						}
					}
					break;
				case 4: // 상,우
					for (int i = 0; i < 4; i++) {
						if (i == 2 || i == 3)
							continue;
						nxt_y = b.y + dr[i];
						nxt_x = b.x + dc[i];
						if (nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < M && is_connected(nxt_y, nxt_x, i) && visited[nxt_y][nxt_x] != 1) {
							visited[nxt_y][nxt_x] = 1;
							answer += 1;
							a.y = nxt_y;
							a.x = nxt_x;
							a.left = b.left - 1;
							Q.push(a);
						}
					}
					break;
				case 5: // 하,우
					for (int i = 0; i < 4; i++) {
						if (i == 0 || i == 3)
							continue;
						nxt_y = b.y + dr[i];
						nxt_x = b.x + dc[i];
						if (nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < M && is_connected(nxt_y, nxt_x, i) && visited[nxt_y][nxt_x] != 1) {
							visited[nxt_y][nxt_x] = 1;
							answer += 1;
							a.y = nxt_y;
							a.x = nxt_x;
							a.left = b.left - 1;
							Q.push(a);
						}
					}
					break;
				case 6: // 하,좌
					for (int i = 0; i < 4; i++) {
						if (i == 0 || i == 1)
							continue;
						nxt_y = b.y + dr[i];
						nxt_x = b.x + dc[i];
						if (nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < M && is_connected(nxt_y, nxt_x, i) && visited[nxt_y][nxt_x] != 1) {
							visited[nxt_y][nxt_x] = 1;
							answer += 1;
							a.y = nxt_y;
							a.x = nxt_x;
							a.left = b.left - 1;
							Q.push(a);
						}
					}
					break;
				case 7: // 상,좌
					for (int i = 0; i < 4; i++) {
						if (i == 1 || i == 2)
							continue;
						nxt_y = b.y + dr[i];
						nxt_x = b.x + dc[i];
						if (nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < M && is_connected(nxt_y, nxt_x, i) && visited[nxt_y][nxt_x] != 1) {
							visited[nxt_y][nxt_x] = 1;
							answer += 1;
							a.y = nxt_y;
							a.x = nxt_x;
							a.left = b.left - 1;
							Q.push(a);
						}
					}
					break;
				}
			}
		}

		cout << "#" << test_case + 1 << " " << answer << endl;
	}

	fclose(f);

	return 0;
}