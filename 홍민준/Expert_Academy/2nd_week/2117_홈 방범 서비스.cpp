//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M;
int answer;

int MAT[21][21];
pair<int, int> houses[400]; // 도시에 있는 집 목록
int n_house; // 집의 수

int main()
{
	FILE *f = freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		// Implement your algorithm here.
		n_house = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> MAT[i][j];
				if (MAT[i][j] == 1) {
					houses[n_house] = make_pair(i, j);
					n_house += 1;
				}
			}
		}

		// max_K값을 구한다.
		int max_K = (N / 2) * 2 + 1; // NxN 크기의 도시는 정사각형 이므로, 홈방범 서비스의 범위에서 정사각형 영역이 도시 전체를 다 덮을 때가 되어서야 도시 전체에 서비스를 제공할 수 있다.
									// 따라서, 이 때의 K값이 따져봐야할 K값의 최대치가 된다.
								   // 예를 들어, K 값 3일 때, 홈방범 서비스의 영역 중 가장 큰 정사각형 모양의 크기는 3x3 이다. 따라서, 3x3 크기의 도시는 K값이 3인 경우까지만 따져보면 된다.
								  // 이를 일반화 시키면, N이 홀수 일때, N와 max_K를 같게 두면 되고, N이 짝수일 때는 N보다 큰 가장 작은 홀수가 max_K가 된다.

		int profit, maintenance;
		int max, y, x;
		answer = 1;
		for (int K=2; K<=max_K; K++) {
			max = 0;
			maintenance = K * K + (K - 1)*(K - 1); // 운영비

			for (int i = 1; i <= N; i++) { // 도시의 모든 영역을 중심으로, 홈방범 서비스를 구축했을 때, 가장 많은 집을 포함한 경우를 찾는다.
				for (int j = 1; j <= N; j++) {
					int tmp = 0;
					for (int l = 0; l < n_house; l++) {
						y = houses[l].first;
						x = houses[l].second;
						
						if ((abs(i - y) + abs(j - x)) <= (K - 1)) { // 'D = |서비스중심_y - 집_y| + |서비스중심_x - 집_x|' 라고 두면, D <= (K-1) 인 경우만 해당 집이 중심지 (i, j)인 서비스의 영역에 들어 온다.
							tmp += 1;
						}
					}
					if (tmp > max) {
						max = tmp;
					}
				}
			}
			profit = (max*M) - maintenance; // K값 마다 가장 집을 많이 포함하는 경우를 찾고, 그 경우의 수익을 따져본다.
			if (profit >= 0 && max > answer) { // 손해는 보지 않고, 집을 가장 많이 포함하는 경우
				answer = max;
			}
		}

		cout << "#" << test_case + 1 << " " << answer << endl;
	}

	fclose(f);

	return 0;
}