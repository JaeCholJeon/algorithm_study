import java.io.*;
import java.util.*;

public class n4012 {

	static int n;
	static int[][] map;
	static boolean[] food;
	static int minVar;
	static LinkedList<Integer> foodA;
	static LinkedList<Integer> foodB;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcase = Integer.parseInt(br.readLine());
		for (int t = 1; t <= testcase; t++) {
			n = Integer.parseInt(br.readLine());
			map = new int[n][n];
			food = new boolean[n];
			minVar = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			dfs(0, 0);
			System.out.println("#" + t + " " + minVar);
		}
	}

	public static void dfs(int depth, int foodcnt) {
		if (depth >= n) return;
		if (foodcnt == n / 2) {
			init();
			return;
		}
		food[depth] = true;
		dfs(depth + 1, foodcnt + 1);
		food[depth] = false;
		dfs(depth + 1, foodcnt);
	}

	public static void init() {
		foodA = new LinkedList<Integer>();
		foodB = new LinkedList<Integer>();
		for (int i = 0; i < n; i++) {
			if (food[i]) foodA.add(i);
			else foodB.add(i);
		}
		int x = 0, y = 0;
		for (int i = 0; i < foodA.size(); i++) {
			for (int j = 0; j < foodA.size(); j++) {
				if (i == j) continue;
				x += map[foodA.get(i)][foodA.get(j)];
				y += map[foodB.get(i)][foodB.get(j)];
			}
		}
		minVar = Math.min(minVar, Math.abs(x - y));
	}
}
