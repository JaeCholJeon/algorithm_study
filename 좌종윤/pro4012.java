package test;
import java.io.IOException;
import java.util.Scanner;
 
class Solution {
    static int n;
    static int[][] arr;
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        for(int i=1;i<=tc;i++) {
            n = sc.nextInt();
            arr = new int[n][n];
            for(int j=0;j<n;j++) {
                for(int k=0;k<n;k++)
                    arr[j][k] = sc.nextInt();
            }
            visited = new boolean[n];
            result = Integer.MAX_VALUE;
            solve(0,0);
            sb.append("#"+i+" "+result+"\n");
        }
        System.out.print(sb);
    }
    
    static boolean visited[];
    static int result;
    private static void solve(int idx,int cnt) {
        if(cnt>n/2) return;
        if(idx>=n) return;
        if(cnt==n/2) {
            int sum = 0;
            int sum2 = 0;
            for(int i=0;i<n;i++) {
                if(visited[i]) {
                    for(int j=0;j<n;j++) {
                        if(visited[j]) sum+=arr[i][j];
                    }
                }else {
                    for(int j=0;j<n;j++) {
                        if(!visited[j]) sum2+=arr[i][j];
                    }
                }
            }
            result = Math.min(result,Math.abs(sum-sum2));
            return;
        }
        // 해당 식재료 고르기
        visited[idx] = true;
        solve(idx+1,cnt+1);
        visited[idx] = false;
        // 해당 식재료 안고르기
        solve(idx+1,cnt);        
    }
}
