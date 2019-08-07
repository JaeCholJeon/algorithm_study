import java.io.*;
import java.util.*;

public class n5644 {
	static int m, a, max;
	static int [][] move;
	static boolean [][] map;
	static node[] info;
	static int [] dx = {0,0,1,0,-1};
	static int [] dy = {0,-1,0,1,0};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcase = Integer.parseInt(br.readLine());
		for (int t = 1; t <= testcase; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			m = Integer.parseInt(st.nextToken());
			a = Integer.parseInt(st.nextToken());
			move = new int[2][m+1];
			info = new node[a];
			max = 0;
			st = new StringTokenizer(br.readLine());
			for(int i = 1; i <= m; i++) move[0][i] = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i = 1; i <= m; i++) move[1][i] = Integer.parseInt(st.nextToken());
			for(int i = 0; i < a; i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				int p = Integer.parseInt(st.nextToken());
				info[i] = new node(x,y,c,p);
			}
			init();
			System.out.println("#"+t+" "+max);
		}
	}
	public static void init() {
		int ax = 1, ay = 1, bx = 10, by = 10;
		for(int i = 0; i <= m; i++) {
			int nax = ax + dx[move[0][i]];
			int nay = ay + dy[move[0][i]];
			int nbx = bx + dx[move[1][i]];
			int nby = by + dy[move[1][i]];
			map = new boolean[2][a];
			for(int j = 0; j < a; j++) {
				if(Math.abs(nax-info[j].x) + Math.abs(nay-info[j].y) <= info[j].c) {
					map[0][j] = true;
				}
				if(Math.abs(nbx-info[j].x) + Math.abs(nby-info[j].y) <= info[j].c) {
					map[1][j] = true;
				}
			}
			max += calc();
			ax = nax;
			ay = nay;
			bx = nbx;
			by = nby;
		}
	}
	
	public static int calc() {
		int sum = 0;
		for(int i = 0; i < a; i++) {
			for(int j = 0; j < a; j++) {
				int energy = 0;
				if(map[0][i]) {
					if(map[1][j]) {
						if(i == j) energy = info[i].p;
						else energy = info[i].p + info[j].p;
					}else energy = info[i].p;
				}else {
					if(map[1][j]) energy = info[j].p;
				}
				sum = Math.max(sum, energy);
			}
		}
		return sum;
	}
	
	public static class node{
		int x,y,c,p;
		public node(int x, int y, int c, int p) {
			this.x = x;
			this.y = y;
			this.c = c;
			this.p = p;
		}
	}
}