import java.util.*;
import java.io.*;

public class n2105 {
	static int n, sx, sy, result = Integer.MIN_VALUE;
	static int[][] map;
	static boolean[][] visit;
	static boolean[] check;
	static int[] dx = { 1, 1, -1, -1 };
	static int[] dy = { 1, -1, -1, 1 };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcase = Integer.parseInt(br.readLine());
		for (int k = 0; k < testcase; k++) {
			n = Integer.parseInt(br.readLine());
			map = new int[n][n];
			for (int i = 0; i < n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			visit = new boolean[n][n];
			check = new boolean[101];
			result = 0;
			for (int i = 0; i < n - 2; i++) {
				for (int j = 1; j < n - 1; j++) {

					check[map[i][j]] = true;
					visit[i][j] = true;
					sx = i;
					sy = j;
					//System.out.println("시작 !!!!! : " + sx + " " + sy);
					dfs(i, j, 0, 1);
					check[map[i][j]] = false;
					visit[i][j] = false;
				}
			}
			if (result < 4)
				System.out.println("#" + (k + 1) + " " + -1);
			else
				System.out.println("#" + (k + 1) + " " + result);

		}
	}

	public static void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(visit[i][j] + " ");
			}
			System.out.println();
		}
		for (int i = 0; i < 100; i++) {
			if (check[i])
				System.out.println(i + " 디저트");
		}
	}

	public static void dfs(int x, int y, int dir, int cnt) {
		if (dir == 4) return;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		//System.out.println(nx + " " + ny);
		//print();
		if (!range(nx, ny)) return;
		if (visit[nx][ny] || check[map[nx][ny]]) {
			if (nx == sx && ny == sy) {
				result = Math.max(result, cnt);
			}
			return;
		}

		visit[nx][ny] = true;
		check[map[nx][ny]] = true;
		dfs(nx, ny, dir, cnt + 1);
		dfs(nx, ny, dir + 1, cnt + 1);
		visit[nx][ny] = false;
		check[map[nx][ny]] = false;
	}

	public static boolean range(int x, int y) {
		if (0 <= x && x < n && 0 <= y && y < n) {
			return true;
		}
		return false;
	}
}
