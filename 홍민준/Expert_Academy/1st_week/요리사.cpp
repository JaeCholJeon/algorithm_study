//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
int answer;

int synergy[17][17];
int A_sel; // ������� ������ A�丮�� ����� ��
int A[8]; // ������� ������ A�丮�� ����� ���
int B_sel; // ������� ������ B�丮�� ����� ��
int B[8]; // ������� ������ B�丮�� ����� ���

void DFS(int idx, int a, int b) // turn: 0�� ��� A�� ����, 1�� ��� B�� ����
{
	int diff = abs(a - b);

	if ((A_sel + B_sel) >= N) { // ��� ����Ḧ �� ���� ������
		if (diff < answer) { // A �丮�� �ó����� B�� �ó����� ���̸� ���Ѵ�.
			answer = diff;
		}
		return;
	}

	int a_back, b_back;

	if (A_sel < N / 2) { // A�丮�� idx��° ����Ḧ ���
		a_back = a; // idx��° ����Ḧ A�丮�� �߰��ϴ� ��츦 ���� ����, A�丮�� �߰� �ó��� ���� ������� ������ ���� backup ��
		A[A_sel] = idx; // A�丮�� idx��°�� �߰� �Ѵ�.
		A_sel += 1;
		for (int j = 0; j < A_sel - 1; j++) { // idx��° ����Ḧ A�丮�� �߰� �ϱ� ����,
											// �������� ���õ� ������ ���� �丮�� �ó���(a)�� idx��° ����Ḧ ���� �ó����� �߰��� ����Ѵ�.
			a += synergy[A[j]][A[A_sel - 1]];
			a += synergy[A[A_sel - 1]][A[j]];
		}
		DFS(idx + 1, a, b);
		A_sel -= 1; // idx��° ����Ḧ A�丮�� �߰��� ��츦 ��������, ������� �����Ѵ�.
		a = a_back;
	}
	if (B_sel < N / 2) { // B �丮�� i��° ����Ḧ ���
		b_back = b; // idx��° ����Ḧ B�丮�� �߰��ϴ� ��츦 ���� ����, B�丮�� �߰� �ó��� ���� ������� ������ ���� backup ��
		B[B_sel] = idx; // B�丮�� idx��°�� �߰� �Ѵ�.
		B_sel += 1;
		for (int j = 0; j < B_sel - 1; j++) { // idx��° ����Ḧ B�丮�� �߰� �ϱ� ����,
											// �������� ���õ� ������ ���� �丮�� �ó���(b)�� idx��° ����Ḧ ���� �ó����� �߰��� ����Ѵ�.
			b += synergy[B[j]][B[B_sel - 1]];
			b += synergy[B[B_sel - 1]][B[j]];
		}
		DFS(idx + 1, a, b);
		B_sel -= 1; // idx��° ����Ḧ B�丮�� �߰��� ��츦 ��������, ������� �����Ѵ�.
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