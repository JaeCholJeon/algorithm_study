import java.util.*;
import java.io.*;

public class n5658 {

	static int n, k, cir;
	static String s;
	static ArrayList<Character> arr;
	static ArrayList<Integer> check;
	static ArrayList<Integer> result;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcase = Integer.parseInt(br.readLine());
		for (int t = 1; t <= testcase; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			s = br.readLine();
			check = new ArrayList<Integer>();
			cir = n / 4;
			arr = new ArrayList<Character>();
			for (int i = 0; i < s.length(); i++) {
				arr.add(s.charAt(i));
			}
			init(t);
		}
	}

	public static void init(int t) {
		int cnt = 0;
		while (cnt < cir) {
			change();
			rotation();
			cnt++;
		}
		remove();
		Collections.sort(result);
		Collections.reverse(result);
		System.out.println("#" + t + " " + result.get(k - 1));
	}

	public static void remove() {
		result = new ArrayList<Integer>();
		for (int i = 0; i < check.size(); i++) {
			if (!result.contains(check.get(i))) {
				result.add(check.get(i));
			}
		}
	}

	public static void change() {
		String change = "";
		int cnt = 0;
		char c;
		for (int i = 0; i < arr.size(); i++) {
			if (cnt == cir) {
				cnt = 0;
				calc(change, i);
				change = "";
			} else if (i == arr.size() - 1) {
				c = arr.get(i);
				change += Character.toString(c);
				calc(change, i);
				change = "";
			}
			cnt++;
			c = arr.get(i);
			change += Character.toString(c);
		}
	}

	public static void rotation() {
		char c = arr.get(arr.size() - 1);
		arr.remove(arr.size() - 1);
		arr.add(0, c);
	}

	public static void calc(String change, int i) {
		int num = Integer.parseInt(change, 16);
		// System.out.println(num + " " + change+" "+ i);
		check.add(num);
	}
}
