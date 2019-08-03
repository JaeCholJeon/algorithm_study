#include <bits/stdc++.h>

using namespace std;

int T, N;
int MIN, MAX, answer;
int ops[4];
int numbers[13];

inline int operate(int idx, int current, int op)
{
	if (op == 0) { // '+'
		return current + numbers[idx + 1];
	}
	else if (op == 1) { // '-'
		return current - numbers[idx + 1];
	}
	else if (op == 2) { // '*'
		return current * numbers[idx + 1];
	}
	else if (op == 3) { // '/'
		return current / numbers[idx + 1];
	}
}

void DFS(int idx, int current)
{
	if (idx >= N) { // 종료 조건
		if (current < MIN) {
			MIN = current;
		}
		if (current > MAX) {
			MAX = current;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (ops[i] > 0) { // 현재 연산자가 남아있을 경우만 해당 연산을 진행한다.
			ops[i] -= 1;
			DFS(idx+1, operate(idx, current, i)); // operate 함수를 통해, 연산자를 나타내는 번호와 실재 연산을 연결한다. 
												//예를 들어, i가 0일때 해당 연산자는 '+'인데, 이 동작을 operate 함수에서 수행 하는 식.
			ops[i] += 1;
		}
	}
}

int main()
{
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		// Implement your algorithm here.
		cin >> N;
		for (int i = 0; i < 4; i++) {
			cin >> ops[i];
		}
		for (int i = 1; i <= N; i++) {
			cin >> numbers[i];
		}
		
		MIN = 1e9; // 1 * 10^9
		MAX = -1e9; // -1 * 10^9
		DFS(1, numbers[1]);

		answer = MAX - MIN;
		cout << "#" << test_case + 1 << " " << answer << endl;
	}

	return 0;
}