#include <iostream>

using namespace std;
 
int price[4];
int month[13];
int mMonth[12];
int mPrice[12];
 
int min(int a, int b) {
    return (a < b) ? a : b;
}
 
int main() {
	freopen("input1952.txt", "r", stdin);
    int T, K, answer;
	cin >> T;
 
    for(int t_case=1; t_case<=T; t_case++) {
        for (int i = 0; i < 4; i++) {
			cin >> price[i];
        }
 
        for (int i = 1; i <= 12; i++) {
			cin >> month[i];
        }

        for (int i = 1; i <= 12; i++) {
            mMonth[i] = min(price[0] * month[i], price[1]);
			//cout << mMonth[i] << " ";
        }
		//cout << endl;

        for (int i = 1; i <= 12; i++) {
            mPrice[i] = mPrice[i-1] + mMonth[i];
            if (i - 3 >= 0) {
                if (mPrice[i] > mPrice[i - 3] + price[2]) {
                    mPrice[i] = mPrice[i - 3] + price[2];
                }
            }
        }

        if (mPrice[12] > price[3]) {
            mPrice[12] = price[3];
        }
	
		cout << "#" << t_case << " " << mPrice[12] << endl;
    }
}
