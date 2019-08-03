import java.io.*;
import java.util.*;
public class Solution {
	BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer st;
	int t,n,map[][] =  new int[21][21];
	int dx[] = {1,-1,-1,1};
	int dy[] = {1,1,-1,-1};
	boolean visited[][] = new boolean[21][21],digit[]= new boolean[101];
	int ans = 0;
	public Solution() throws IOException {
		// TODO Auto-generated constructor stub
		st = new StringTokenizer(br.readLine());
		t = Integer.parseInt(st.nextToken());
		for(int T=1;T<=t;T++) {
			ans = 0;
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			for(int i = 0 ; i < n ; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0 ; j <n ; j++) 
					map[i][j] = Integer.parseInt(st.nextToken());
			}
			for(int i = 0 ; i < n ; i++) {
				for(int j = 0 ; j <n ; j++) 
					dfs(i,j,0,i,j,0);
			}
			System.out.println("#"+T+" "+(ans==0?-1:ans));
		}
	}
	void dfs(int y,int x,int d ,int oy,int ox ,int cnt) {
		if(y==oy&&x==ox&&cnt>1) {
			ans  = Math.max(ans, cnt);
			return;
		}
		if(digit[map[y][x]])return;
		visited[y][x] =true;
		digit[map[y][x]]=true;
		for(int i = d ; i<4&&i<d+2; i++) {
			int newy =  y+dy[i];
			int newx =  x+dx[i];
			if(newy>=0&&newy<n&&newx>=0&&newx<n&&((newy==oy&&newx==ox)||!visited[newy][newx])) 
				dfs(newy,newx,i,oy,ox,cnt+1);
		}
		visited[y][x] =false;
		digit[map[y][x]]=false;
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		new Solution();
	}
}
