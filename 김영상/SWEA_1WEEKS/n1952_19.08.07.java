import java.io.*;
import java.util.*;

public class n1952 {
	static int[] ticket = new int[4];
	static int[] month = new int[12];
	static int n;
	static int result;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcase = Integer.parseInt(br.readLine());
		for (int t = 1; t <= testcase; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 4; i++) ticket[i] = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 12; i++) month[i] = Integer.parseInt(st.nextToken());
			result = ticket[3];
			calc(0,0);
			System.out.println("#"+t+" "+result);
		}
	}
	
	public static void calc(int depth, int sum) {
		if(depth >= 12) {
			result = Math.min(result, sum);
			return;
		}
		if(month[depth] == 0) calc(depth+1, sum);
		else {
			calc(depth+1, sum + month[depth]*ticket[0]);
			calc(depth+1, sum + ticket[1]);
			calc(depth+3, sum + ticket[2]);
		}
	}
}
