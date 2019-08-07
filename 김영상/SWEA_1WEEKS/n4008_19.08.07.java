import java.io.*;
import java.util.*;

public class n4008 {

	static int n, maxNum, minNum;
	static int[] oper = new int[4];
	static int[] num = new int[12];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcase = Integer.parseInt(br.readLine());
		for (int t = 1; t <= testcase; t++) {
			n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 4; i++) oper[i] = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) num[i] = Integer.parseInt(st.nextToken());
			maxNum = Integer.MIN_VALUE;
			minNum = Integer.MAX_VALUE;
			calc(oper[0], oper[1], oper[2], oper[3], num[0], 1);
			System.out.println("#" + t + " " + (maxNum - minNum));
		}
	}

	// + - * / 순서로 oper 배열에 들어가 있음
	public static void calc(int add, int sub, int mul, int div, int sum, int depth) {
		if (add == 0 && sub == 0 && mul == 0 && div == 0) {
			maxNum = Math.max(maxNum, sum);
			minNum = Math.min(minNum, sum);
			return;
		}
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				if (add > 0) calc(add - 1, sub, mul, div, sum + num[depth], depth + 1);
			} else if (i == 1) {
				if (sub > 0) calc(add, sub - 1, mul, div, sum - num[depth], depth + 1);	
			} else if (i == 2) {
				if (mul > 0) calc(add, sub, mul - 1, div, sum * num[depth], depth + 1);
			} else if (i == 3) {
				if (div > 0) calc(add, sub, mul, div - 1, sum / num[depth], depth + 1);
			}
		}
	}
}
