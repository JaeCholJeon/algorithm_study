#include<iostream>
#include<algorithm>

using namespace std;

int n;
int calc[4];
int number[12];
int maxnum;
int minnum;

void dfs(int v, int	num){
	if(v==n){
		maxnum = max(maxnum, num);
		minnum = min(minnum, num);
	}else{
		if(calc[0] > 0){
			calc[0] --;
			dfs(v+1, num + number[v]);
			calc[0] ++;
		}
		if(calc[1] > 0){
			calc[1] --;
			dfs(v+1, num - number[v]);
			calc[1] ++;
		}
		if(calc[2] > 0){
			calc[2] --;
			dfs(v+1, num * number[v]);
			calc[2] ++;
		}
		if(calc[3] > 0){
			calc[3] --;
			dfs(v+1, num / number[v]);
			calc[3] ++;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		maxnum=-1e9;
		minnum = 1e9;
		cin >> n;
		for(int i=0; i<4; i++){
			cin >> calc[i];
		}
		for(int i=0; i<n; i++){
			cin >> number[i];
		}
		
		dfs(1,number[0]);

		cout << "#" << test_case << " " << maxnum- minnum <<endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

