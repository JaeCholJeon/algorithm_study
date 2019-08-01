#include <bits/stdc++.h>

using namespace std;

int T;
long long answer;

int plans[13];
int costs[4];

void DFS(int month, long long current)
{
	if (month > 12) {
		if (current < answer) {
			answer = current;
		}
		return;
	}

	if (plans[month] != 0) {
		if (current + plans[month] * costs[0] < answer) { // 해당 달에서 1일 이용권을 이용하는 경우
			DFS(month + 1, current + plans[month] * costs[0]);
		}
		if (current + costs[1] < answer) { // 해당 달에서 1달 이용권을 이용하는 경우
			DFS(month + 1, current + costs[1]);
		}
		if (current + costs[2] < answer) { // 해당 달에서 3달 이용권을 이용하는 경우
			DFS(month + 3, current + costs[2]);
		}
	}
	else {
		DFS(month + 1, current);
	}
}

int main()
{
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		// Implement your algorithm here.
		for (int i = 0; i < 4; i++) {
			cin >> costs[i];
		}
		
		for (int i = 1; i <= 12; i++) {
			cin >> plans[i];
		}

		answer = costs[3]; // 1년 이용권은 매년 1월 1일에만 사용할 수 있으므로, 다른 경우를 따지기 전에 비용 초기 값으로 넣는다.
		int i = 1;
		while (plans[i] == 0) {
			i++;
		}
		DFS(i, 0);

		cout << "#" << test_case + 1 << " " << answer << endl;
	}

	return 0;
}