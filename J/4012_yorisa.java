import java.io.*;
import java.util.*;
public class Solution {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer st;
	int t = 0,n=0,map[][] = new int[17][17],arr[][] = new int[2][17];
	long ans=0;
	long a= 0,b=0;
	public Solution() throws IOException {
		// TODO Auto-generated constructor stub
		st = new StringTokenizer(br.readLine());
		t= Integer.parseInt(st.nextToken());
		for(int T=1;T<=t;T++) {
			ans = Integer.MAX_VALUE;
			a= 0;b=0;
			st = new StringTokenizer(br.readLine());
			n= Integer.parseInt(st.nextToken());
			for(int i = 0 ; i <n ; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0 ; j<n ; j++) 
					map[i][j] = Integer.parseInt(st.nextToken());
			}
			dfs(0,0,0,0,0);
			System.out.println("#"+T+" "+ans);
		}
	}
	void dfs(int i,int cnt_a ,int cnt_b,long a ,long b) {
		if(i>=n) {
			ans = Math.min(ans, Math.abs(a-b));
			return;
		}
		long tmp = a;
		for(int c = 0 ; c<cnt_a;c++) {
			tmp+=map[i][arr[0][c]];
			tmp+=map[arr[0][c]][i];
		}
		arr[0][cnt_a]=i;
		dfs(i+1,cnt_a+1,cnt_b,tmp,b);
		arr[1][cnt_b]=i;
		tmp=b;
		for(int c = 0 ; c<cnt_b;c++) {
			tmp+=map[i][arr[1][c]];
			tmp+=map[arr[1][c]][i];
		}
		dfs(i+1,cnt_a,cnt_b+1,a,tmp);
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		new Solution();
	}
}
