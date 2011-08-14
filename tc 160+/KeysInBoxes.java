import java.util.*;
import java.math.BigInteger;

public class KeysInBoxes {
    
    boolean[][][] done;
    BigInteger[][][] dp;
    BigInteger[][] C;
    BigInteger[] F;

    private BigInteger go(int start, int n, int cyc) {
        if (cyc<0 || n<0) {
            return BigInteger.ZERO;
        }
        if (n == 0) {
            return BigInteger.ONE;
        }
        if (cyc == 0) {
            return BigInteger.ZERO;
        }
        if (start > n) {
            return BigInteger.ZERO;
        }
        if (done[start][n][cyc]) {
            return dp[start][n][cyc];
        }
        done[start][n][cyc] = true;
        BigInteger ret = BigInteger.ZERO;

        for (int i=start; i<=n; ++i) {
            BigInteger f = BigInteger.ONE;
            BigInteger x = BigInteger.ONE;
            for (int br=1; br<=cyc && br*i<=n; ++br) {
                f = f.multiply(C[n-(br-1)*i][i]);
                x = x.multiply(F[i-1]);
                ret = ret.add(go(i+1, n-br*i, cyc-br).multiply(f).multiply(x).divide(F[br]));
            }
        }

        dp[start][n][cyc] = ret;
        return ret;
    }
        
	public String getAllKeys(int N, int M) {
		done = new boolean[21][21][21];
        dp = new BigInteger[21][21][21];
        C = new BigInteger[21][21];
        F = new BigInteger[21];
        for (int n=0; n<21; ++n) {
            C[n][0] = BigInteger.ONE;
            C[n][n] = BigInteger.ONE;
            for (int k=1; k<n; ++k) {
                C[n][k] = C[n-1][k].add(C[n-1][k-1]);
            }
        }
        F[0] = BigInteger.ONE;
        for (Integer i=1; i<21; ++i) {
            F[i] = F[i-1].multiply(new BigInteger(i.toString()));
        }

        BigInteger num = go(1, N, M);

        BigInteger d = num.gcd(F[N]);
        return num.divide(d).toString() + "/" + F[N].divide(d).toString();
	}
 
}
