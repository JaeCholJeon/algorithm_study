#include <bits/stdc++.h>

using namespace std;

int T, N;
int answer;
int MAT[20][20];
int d_kinds[101];
pair<int, int> sp;

int dr[4] = { 1, 1, -1, -1 };
int dc[4] = { 1, -1, -1, 1 };

void DFS(int row, int col, int step, int n_dessert)
{
	if (row == sp.first && col == sp.second) {
		if (n_dessert > answer) {
			answer = n_dessert;
		}
		return;
	}

	int nr, nc;
	
	nr = row + dr[step];
	nc = col + dc[step];

	if ((nr >= 0 && nr < N && nc >= 0 && nc < N && d_kinds[MAT[nr][nc]] == 0) || (nr == sp.first && nc == sp.second)) {
		d_kinds[MAT[nr][nc]] = 1;
		if (nr == sp.first && nc == sp.second) {
			DFS(nr, nc, step, n_dessert);
		}
		else {
			DFS(nr, nc, step, n_dessert + 1);
		}

		if (nr != sp.first || nc != sp.second) {
			d_kinds[MAT[nr][nc]] = 0;
		}
	}
	
	if (step < 3) {
		step += 1;
		nr = row + dr[step];
		nc = col + dc[step];

		if ((nr >= 0 && nr < N && nc >= 0 && nc < N && d_kinds[MAT[nr][nc]] == 0) || (nr == sp.first && nc == sp.second)) {
			d_kinds[MAT[nr][nc]] = 1;
			if (nr == sp.first && nc == sp.second) {
				DFS(nr, nc, step, n_dessert);
			}
			else {
				DFS(nr, nc, step, n_dessert + 1);
			}
			if (nr != sp.first || nc != sp.second) {
				d_kinds[MAT[nr][nc]] = 0;
			}
		}
	}
}

int main()
{
	int nr, nc;

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		// Implement your algorithm here.
		cin >> N;
		answer = -1;
		memset(d_kinds, 0, sizeof(int) * 100);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> MAT[i][j];
			}
		}

		for (int i = 0; i < N-2; i++) {
			for (int j = 1; j < N - 1; j++) {
				d_kinds[MAT[i][j]] = 1;
				sp = make_pair(i, j);

				nr = i + dr[0];
				nc = j + dr[0];

				if (d_kinds[MAT[nr][nc]] == 0) {
					d_kinds[MAT[nr][nc]] = 1;
					DFS(nr, nc, 0, 2);
					d_kinds[MAT[nr][nc]] = 0;
				}
				d_kinds[MAT[i][j]] = 0;
			}
		}

		cout << "#" << test_case + 1 << " " << answer << endl;
	}

	return 0;
}