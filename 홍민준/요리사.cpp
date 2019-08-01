//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
int answer;

int synergy[17][17];
int A_sel; // 현재까지 선택한 A요리의 식재료 수
int A[8]; // 현재까지 선택한 A요리의 식재료 목록
int B_sel; // 현재까지 선택한 B요리의 식재료 수
int B[8]; // 현재까지 선택한 B요리의 식재료 목록

void DFS(int idx, int a, int b) // turn: 0일 경우 A가 선택, 1일 경우 B가 선택
{
	int diff = abs(a - b);

	if ((A_sel + B_sel) >= N) { // 모든 식재료를 다 선택 했으면
		if (diff < answer) { // A 요리의 시너지와 B의 시너지의 차이를 비교한다.
			answer = diff;
		}
		return;
	}

	int a_back, b_back;

	if (A_sel < N / 2) { // A요리에 idx번째 식재료를 사용
		a_back = a; // idx번째 식재료를 A요리에 추가하는 경우를 따져 보고, A요리의 중간 시너지 값을 원래대로 돌리기 위한 backup 값
		A[A_sel] = idx; // A요리에 idx번째를 추가 한다.
		A_sel += 1;
		for (int j = 0; j < A_sel - 1; j++) { // idx번째 식재료를 A요리에 추가 하기 위해,
											// 이전까지 선택된 식재료로 만든 요리의 시너지(a)에 idx번째 식재료를 더한 시너지만 추가로 계산한다.
			a += synergy[A[j]][A[A_sel - 1]];
			a += synergy[A[A_sel - 1]][A[j]];
		}
		DFS(idx + 1, a, b);
		A_sel -= 1; // idx번째 식재료를 A요리에 추가한 경우를 따져보고, 원래대로 복구한다.
		a = a_back;
	}
	if (B_sel < N / 2) { // B 요리에 i번째 식재료를 사용
		b_back = b; // idx번째 식재료를 B요리에 추가하는 경우를 따져 보고, B요리의 중간 시너지 값을 원래대로 돌리기 위한 backup 값
		B[B_sel] = idx; // B요리에 idx번째를 추가 한다.
		B_sel += 1;
		for (int j = 0; j < B_sel - 1; j++) { // idx번째 식재료를 B요리에 추가 하기 위해,
											// 이전까지 선택된 식재료로 만든 요리의 시너지(b)에 idx번째 식재료를 더한 시너지만 추가로 계산한다.
			b += synergy[B[j]][B[B_sel - 1]];
			b += synergy[B[B_sel - 1]][B[j]];
		}
		DFS(idx + 1, a, b);
		B_sel -= 1; // idx번째 식재료를 B요리에 추가한 경우를 따져보고, 원래대로 복구한다.
		b = b_back;
	}
}

int main()
{
	FILE *f = freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		// Implement your algorithm here.
		cin >> N;
		answer = 1e9;
		A_sel = B_sel = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >>  synergy[i][j];
			}
		}

		DFS(1, 0, 0);

		cout << "#" << test_case + 1 << " " << answer << endl;
	}

	fclose(f);

	return 0;
}