import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.*;


public class Main {
	public static long INF = (long)1e18;
	
	public static void main(String[] argv)throws IOException {
		
		InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        int[][] dist = new int[n][m];
        int[][] pcount = new int[n][m];
        for (int i=0; i<n; i++) {
        	for (int j=0; j<m; j++)
        		dist[i][j] = in.nextInt();
        }
        
        for (int i=0; i<n; i++) {
        	for (int j=0; j<m; j++)
        		pcount[i][j] = in.nextInt();
        }
        long[][][] mem = new long[n][m][k+1];
        for (int i=0; i<n; i++) {
        	for (int j=0; j<m; j++) {
        		for (int h=0; h<k+1; h++)
        			mem[i][j][h] = -1;
        	}
        }
        long result = minDist(n-1, m-1, k, dist, pcount, mem);
        if (result < INF)
        	System.out.println(result);
        else
        	System.out.println("-1");
	}
	
	
	public static long minDist(int r, int c, int k, int[][] dist, int[][] pcount, long[][][] mem) {
		if (k < 0) return INF;
		if (r == 0 && c == 0) return 0;
		if (r < 0 || c < 0 || r >= mem.length || c >= mem[0].length) return INF;
		if (mem[r][c][k] != -1) return mem[r][c][k];
		int[][] directions = {
				{-1, 1, 0, 0},
				{0, 0, -1, 1}
		};
		mem[r][c][k] = INF;
		for (int i=0; i< directions[0].length; i++) {
			mem[r][c][k] = Math.min(mem[r][c][k], dist[r][c] + 
					minDist(r+directions[0][i], c+directions[1][i], k-pcount[r][c], dist, pcount, mem));
		}
		return mem[r][c][k];
	}
	

	static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}