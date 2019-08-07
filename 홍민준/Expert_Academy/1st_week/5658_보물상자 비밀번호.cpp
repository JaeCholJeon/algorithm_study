//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int T, N, K;
int answer;

int numbers[29]; // 가능한 모든 16진수를 변환하여 10진수 형태로 저장하는 배열
int next_num;
char input[29];

inline int convert(char c)
{
	if (c >= '0' && c <= '9') { // 16진수를 나타내는 문자(c)가 숫자일 때(=0~9)
		return c - '0';
	}
	else { // 16진수를 나타내는 문자(c)가 문자일 때(=A~F)
		return c - 'A' + 10;
	}
}

int main()
{
	FILE *f = freopen("sample_input.txt", "r", stdin);
	int len;
	int j;

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		// Implement your algorithm here.
		cin >> N >> K;
		answer = 0;
		next_num = 1;

		for (int i = 1; i <= N; i++) {
			cin >> input[i];
		}

		len = N / 4; // 한 변의 16진수 길이

		for (int k = 0; k < len; k++) { // 총 len-1회 회전하며 나올 수 있는 모든 숫자를 numbers 배열에 10진수로 바꿔 저장한다.
			for (int i = 1; i <= N; i++) { // 현재 전체 16진수의 배열 중 한 변에 올 수 있는 16진수들 끼리 나눠서 10진수로 바꾼다.
				if (i % len == 0) {
					int shift = 1;
					int sum = 0;
					for (j = i; j > i - len; j--) {
						sum += (shift * convert(input[j])); // 해당 16진수는 문자 타입이고, 이 값을 10진수로 바꾼 다음 자리값과 곱해서 더한다.
						shift <<= 4; // 16진수는 자리 마다 2^4 만큼 곱해지는 값(=자리값)이 커진다.
					}
					for (j = 1; j < next_num; j++) { // 숫자가 중복되는 경우를 확인 한다.
						if (numbers[j] == sum) {
							break;
						}
					}
					if (j == next_num) { // 이전까지 저장 된 숫자들의 배열을 다 도는 동안 중복된 숫자가 없다면,
						numbers[next_num] = sum; // 새로운 숫자를 배열에 추가한다.
						next_num++;
					}
				}
			}

			// 회전
			int tmp = input[1];
			input[1] = input[N];
			for (int i = N - 1; i > 1; i--) {
				input[i + 1] = input[i];
			}
			input[2] = tmp;
		}
		sort(numbers + 1, numbers + next_num);
		answer = numbers[next_num - K]; // 오름차순 정렬이 되어 있으므로, 가장 큰 값에서 K만큼 떨어진 값이 답이 된다.

		cout << "#" << test_case + 1 << " " << answer << endl;
	}

	fclose(f);

	return 0;
}