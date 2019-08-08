#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

#include <functional>

using namespace std;



int N, K;

string s;



int main() {
	//freopen("input5658.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		cin >> N >> K;

		vector<int>v; int ans = 0;

		cin >> s; int tmp;

		cout << s << endl;

		for (int i = 0; i < ((N / 4)-1); i++) s += s.at(i);

		cout << s << endl;

		for (int i = 0; i < N; i++) {

			tmp = (int)std::stol(s.substr(i, (N / 4)),nullptr,16);

			v.push_back(tmp);

		}

		sort(v.begin(), v.end(), greater<int>());



		int cnt = 0; tmp = 0;

		for (int j = 0; j < v.size(); j++) {

			if (v[j] != tmp) {

				cnt++; tmp = v[j];

			}



			if (cnt == K) {

				ans = v[j]; break;

			}

		}



		cout << "#" << tc << " " << ans << endl;

	}

	return 0;

}