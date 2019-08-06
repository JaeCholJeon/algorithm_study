
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
  
public class Solution {
    static int N,ans,sx,sy;
    static int[][] map;
    static int[] dx = {1,1,-1,-1} , dy = {1,-1,-1,1};
    static boolean [] dessert;
      
    static void dfs( int x, int y, int d, int cnt ){
          
        if ( d == 4 ) return;
          
        int nx = x + dx[d];
        int ny = y + dy[d];
          
        if ( 0 <= nx && nx < N && 0 <= ny && ny < N ) {
            if ( sx == nx && sy == ny ) {
                ans = ( ans > cnt+1 ) ? ans : cnt+1;
            }
            if ( !dessert[map[nx][ny]] ) {
                dessert[map[nx][ny]] = true;
                dfs(nx,ny,d,cnt+1);
                dfs(nx,ny,d+1,cnt+1);
                dessert[map[nx][ny]] = false;
            }
        }
    }
    public static void main ( String [] args ) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringTokenizer st =null;
        for ( int tc=1 ; tc <= T ; tc++ ) {
            N = Integer.parseInt(br.readLine());
            map = new int[N][N];
            ans = -1;
            dessert = new boolean[101];
            for ( int i=0 ; i < N ; i++ ) {
                st = new StringTokenizer(br.readLine());
                for ( int j=0 ; j < N ; j++ ) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            for ( int i=0 ; i < N ; i++ ) {
                for ( int j=0 ; j < N ; j++ ) {
                    sx = i;
                    sy = j;
                    dessert[map[i][j]] = true;
                    dfs(i,j,0,0);
                    dessert[map[i][j]] = false;
                }
            }
            System.out.println("#" + tc + " " + ans);
        }
    }
}