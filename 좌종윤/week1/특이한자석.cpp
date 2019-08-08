#include <iostream>
 
using namespace std;
 
bool wheel[4][8];

 
void rotWheel(int wheelNum, int direction, bool isStart, bool isRight) {
    if(isStart) {
        if(wheelNum < 3) {
            if(wheel[wheelNum][2] != wheel[wheelNum+1][6])
                rotWheel(wheelNum+1, -direction, false, true);
        }
 
        if(wheelNum > 0) {
            if(wheel[wheelNum][6] != wheel[wheelNum-1][2])
                rotWheel(wheelNum-1, -direction, false, false);
        }
    } else {
        if(isRight) {
            if(wheelNum < 3) {
                if(wheel[wheelNum][2] != wheel[wheelNum+1][6])
                    rotWheel(wheelNum+1, -direction, false, true);
            }
        } else {
            if(wheelNum > 0) {
                if(wheel[wheelNum][6] != wheel[wheelNum-1][2])
                    rotWheel(wheelNum-1, -direction, false, false);
            }
        }
    }
 
    if(direction == 1) {
        bool temp = wheel[wheelNum][7];
        for(int i=7; i>0; i--) {
            wheel[wheelNum][i] = wheel[wheelNum][i-1];
        } 
        wheel[wheelNum][0] = temp;
    } else {
        bool temp = wheel[wheelNum][0];
        for(int i=0; i<7; i++) {
            wheel[wheelNum][i] = wheel[wheelNum][i+1];
        }
        wheel[wheelNum][7] = temp;
    }
}
 
int main(void) {
	//freopen("input4013.txt", "r", stdin);
    int T, K, answer;
	cin >> T;
 
    for(int t_case=1; t_case<=T; t_case++) {
		cin >> K;
        int turn[20][2];
 
        for(int i=0; i<4; i++) {
            for(int j=0; j<8; j++) {
				cin >> wheel[i][j];
            }
        }
 
        for(int i=0; i<K; i++){
			cin >> turn[i][0] >> turn[i][1];
		}
 
        for(int i=0; i<K; i++) {
            rotWheel(turn[i][0] - 1, turn[i][1], true, false);
        }
 
        answer = (int)wheel[0][0] + (int)wheel[1][0] * 2 + (int)wheel[2][0] * 4 + (int)wheel[3][0] * 8;

		cout << "#" << t_case << " " << answer << endl;
    }
 
    return 0;
}