import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class n4013 {
	static int[] chain1 = new int[8];
	static int[] chain2 = new int[8];
	static int[] chain3 = new int[8];
	static int[] chain4 = new int[8];
	static int[] ch, dr;
	static int n;
	static int[][] chain = new int[4][8];

// N±ÿ 0 S±ÿ 1 Ω√∞ËπÊ«‚ 1 π›Ω√∞Ë -1
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcase = Integer.parseInt(br.readLine());
		for (int j = 1; j <= testcase; j++) {
			n = Integer.parseInt(br.readLine());
			String s1 = br.readLine().replaceAll(" ", "");
			String s2 = br.readLine().replaceAll(" ", "");
			String s3 = br.readLine().replaceAll(" ", "");
			String s4 = br.readLine().replaceAll(" ", "");
			make1(s1);
			make2(s2);
			make3(s3);
			make4(s4);
			for (int i = 0; i < n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int num = Integer.parseInt(st.nextToken());
				int d = Integer.parseInt(st.nextToken());
				ch = new int[4];
				dr = new int[4];
				find(num);
				finddir(num, d);
				rotation();
			}
			print(j);
		}
	}

	public static void find(int num) {
		if (num == 1)
			check1();
		if (num == 2)
			check2();
		if (num == 3)
			check3();
		if (num == 4)
			check4();
	}

	public static void finddir(int num, int d) {
		if (num == 1) {
			if (d == 1) {
				dr[0] = 1;
				dr[1] = -1;
				dr[2] = 1;
				dr[3] = -1;
			} else {
				dr[0] = -1;
				dr[1] = 1;
				dr[2] = -1;
				dr[3] = 1;
			}
		}
		if (num == 2) {
			if (d == 1) {
				dr[0] = -1;
				dr[1] = 1;
				dr[2] = -1;
				dr[3] = 1;
			} else {
				dr[0] = 1;
				dr[1] = -1;
				dr[2] = 1;
				dr[3] = -1;
			}
		}
		if (num == 3) {
			if (d == 1) {
				dr[0] = 1;
				dr[1] = -1;
				dr[2] = 1;
				dr[3] = -1;
			} else {
				dr[0] = -1;
				dr[1] = 1;
				dr[2] = -1;
				dr[3] = 1;
			}
		}
		if (num == 4) {
			if (d == 1) {
				dr[0] = -1;
				dr[1] = 1;
				dr[2] = -1;
				dr[3] = 1;
			} else {
				dr[0] = 1;
				dr[1] = -1;
				dr[2] = 1;
				dr[3] = -1;
			}
		}
	}

	public static void rotation() {
		if (ch[0] == 1)
			move(chain1, dr[0]);
		if (ch[1] == 1)
			move(chain2, dr[1]);
		if (ch[2] == 1)
			move(chain3, dr[2]);
		if (ch[3] == 1)
			move(chain4, dr[3]);
	}

	public static void check1() {
		ch[0] = 1;
		if (chain1[2] != chain2[6]) {
			ch[1] = 1;
			if (chain2[2] != chain3[6]) {
				ch[2] = 1;
				if (chain3[2] != chain4[6]) {
					ch[3] = 1;
				}
			}
		}
	}

	public static void check2() {
		ch[1] = 1;
		if (chain2[6] != chain1[2]) {
			ch[0] = 1;
		}
		if (chain2[2] != chain3[6]) {
			ch[2] = 1;
			if (chain3[2] != chain4[6]) {
				ch[3] = 1;
			}
		}
	}

	public static void check3() {
		ch[2] = 1;
		if (chain3[2] != chain4[6]) {
			ch[3] = 1;
		}
		if (chain3[6] != chain2[2]) {
			ch[1] = 1;
			if (chain2[6] != chain1[2]) {
				ch[0] = 1;
			}
		}
	}

	public static void check4() {
		ch[3] = 1;
		if (chain4[6] != chain3[2]) {
			ch[2] = 1;
			if (chain3[6] != chain2[2]) {
				ch[1] = 1;
				if (chain2[6] != chain1[2]) {
					ch[0] = 1;
				}
			}
		}
	}

	public static void move(int[] chain, int dir) {
		int temp = 0;
		if (dir == 1) {
			temp = chain[7];
			for (int i = 7; i >= 1; i--) {
				chain[i] = chain[i - 1];
			}
			chain[0] = temp;
		}
		if (dir == -1) {
			temp = chain[0];
			for (int i = 1; i <= 7; i++) {
				chain[i - 1] = chain[i];
			}
			chain[7] = temp;
		}
	}

	public static void make1(String s) {
		for (int i = 0; i < s.length(); i++)
			chain1[i] = s.charAt(i) - '0';
	}

	public static void make2(String s) {
		for (int i = 0; i < s.length(); i++)
			chain2[i] = s.charAt(i) - '0';
	}

	public static void make3(String s) {
		for (int i = 0; i < s.length(); i++)
			chain3[i] = s.charAt(i) - '0';
	}

	public static void make4(String s) {
		for (int i = 0; i < s.length(); i++)
			chain4[i] = s.charAt(i) - '0';
	}

	public static void print(int j) {
		int sum = 0;
		if (chain1[0] == 1)
			sum += 1;
		if (chain2[0] == 1)
			sum += 2;
		if (chain3[0] == 1)
			sum += 4;
		if (chain4[0] == 1)
			sum += 8;
		System.out.println("#" +j+ " " + sum);
	}
}
