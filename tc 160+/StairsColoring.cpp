#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class StairsColoring {
	public:
	int coloringCount(int N, int K) {
		// C: The number of stairways is Catalan(N):
        // P: X....Y
        //    ....Y
        //    ...Y
        //    ..Y
        //    .Y
        //    Y
        // Every rectangle must include exactly one Y (since there can only be N rectangles).
        // One of the N rectangles must include X. Call that rectangle A.
        // Therefore, f(N) = f(0)*f(N-1) {if A contains the Y in the zeroth row} +
        //                   f(1)*f(N-2) {if A contains the Y in the second row} +
        //                   ...
        //                   f(k)*f(N-1-k) {if A contains the Y in the k-th row} +
        //                   ...
        //                   f(N-1)*f(0) {if A contains the Y in the last row}
        // Here, f(0) = 1 (there is one way to "do nothing"). Every term comes from 
        // selecting a row for the bottom right corner of A and solving the "down" 
        // and "right" subproblems (in the figure).
        // QED.
        // 
        // Common formulas for the Catalan numbers:
        // Catalan(N) = choose(2N, N)/(N+1) = choose(2N, N) - choose(2N, N-1) = (2n)!/(n!*(n+1)!)
        //
        // In this problem, the solution is K ^ Catalan(N). Since this number can be very large, 
        // we are given a modulus MOD = 1000000123 and should return (K ^ Catalan(N)) mod MOD.
        //
        // The problem is however that Catalan(N) can itself be a very large number so we can't 
        // compute it directly (and we obviously can't use the given modulus to calculate it, as 
        // that is completely meaningless). Thankfully, Fermat's little theorem states
        //    a^(p-1) = 1 (mod p).
        // Our modulus is prime, so we have
        //    K ^ Catalan(N) = (K ^ (MOD-1))*(K ^ (Catalan(N) mod (MOD-1)) = {by FLT} K ^ (Catalan(N) mod (MOD-1)) (mod MOD).
        // Therefore, we must calculate Catalan(N) mod (MOD-1) and then raise K to that power modulo MOD.
        const int MOD = 1000000123;
        return my_pow(K, catalan_mod_m(N, MOD-1), MOD);
	}
    
    int catalan_mod_m(int n, int m) {
        // We will use the formula choose(2n, n)/(n+1) to find the Catalan number.
        // To handle the binomial coefficient, we will use Lucas' theorem.
        // For the denominator, we will find the multiplicative inverse of N+1 w.r.t. m.
        // Unfortunately, m is composite, so we can't use Fermat's little theorem to find its inverse.
        // Had m been prime, we would have had (by FLT): 
        //    (n+1)^(m-1) = 1 (mod m) => (n+1) * (n+1)^(m-2) = 1 (mod m) => inv(n+1, m) = (n+1)^(m-2).
        // Since this is not the case, we will use the extended greater common divisor algorithm to find the inverse.
        
        // this doesn't work because multiplicative inverse of n+1 might not exist! (since m is composite)
        //return (long long)choose_mod_m(2*n, n, m) * mul_inv(n+1, m) % m;
        
        return int(((long long)choose_mod_m(2*n, n, m) - choose_mod_m(2*n, n-1, m) + m)%m);
    }
    
    int my_pow(int n, int k, int mod) { // n^k % mod
        if (k == 0) {
            return 1;
        } else {
            long long t = my_pow(n, k/2, mod);
            t = t*t % mod;
            if (k & 1) {
                t = t*n % mod;
            }
            return int(t);
        }
    }
    
    struct egcds {
        int s, t, d;
    };
    egcds egcd(int m, int n) {
        if (m == 0) {
            return (egcds){0, 1, n};
        }
        egcds next = egcd(n%m, m);
        int temp = next.s;
        next.s = next.t - temp*(n/m);
        next.t = temp;

        assert(next.s*m + next.t*n == next.d);
        return next;
    }
    
    int choose_mod_m(int n, int k, int m) {
        // To calculate choose(n, k) mod m, we will use Lucas' theorem.
        // Lucas's theorem states that
        //    choose(n, k) = PROD choose(n_i, k_i) (mod p)
        // where n_i and k_i are factors of the decomposition of n and k in base p
        //    n = n_j*p^j + ... + n_1*p + n_0
        //    k = k_j*p^j + ... + k_1*p + k_0
        // and p is a prime number.
        //
        // However, m might not be a prime number (it is not in this problem).
        // Therefore, to find our solution, we will use the Chinese remainder theorem.
        //
        // The Chinese remainder theorem states that given n1, n2, ..., nk pairwise coprime 
        // (which is true if all n are prime), then there exists an integer x for any 
        // integers a1, a2, ..., ak such that
        //
        // x = a1 (mod n1)
        // x = a2 (mod n2)
        // ...
        // x = ak (mod nk)
        //
        // and if N = n1*n2*...*nk, x is uniquely determined modulo N.
        //
        // Here, we are looking for choose(n, k) mod m, so we will decompose 
        // m to prime factors to get a set of congruences. To solve each congruence 
        // we will use Lucas' theorem (to get a1, a2, ..., ak).
        //
        // Once we've found the as, we need to find choose(n, k) mod m. There are 
        // more then one way to do this, as discussed below.
        //
        // It is easy to find that MOD-1 = 1000000122 = 7253 * 2089 * 11 * 3 * 2
        
        vector<int> prime_factors;
        int mm = m;
        for (int d=2; d*d<=mm; ++d) {
            if (mm%d == 0) {
                prime_factors.push_back(d);
                do {
                    mm /= d;
                } while (mm%d == 0);
            }
        }
        if (mm > 1) {
            prime_factors.push_back(mm);
        }
        
        vector<int> as;
        for (int i=0; i<(int)prime_factors.size(); ++i) {
            as.push_back(lucas(n, k, prime_factors[i]));
        }
        
        // From the as, we will find choose(n, k) mod m. A simple but not very fast way
        // to find the solution is the following.
        // Working from the largest factor downwards, increase the current value of x
        // by the multiple of all processed factors until all congruences are satisfied.
        // 
        // It is important to note that the construciton guarantees that the solution will 
        // be less than  the modulus (m).
        // The complexity of this solution is O(n1+n2+n3+...+nk), but will probably be 
        // better in practice.
        int ret = as.back();
        int factor = prime_factors.back();
        for (int i=(int)as.size()-2; i>=0; --i) {
            while (ret % prime_factors[i] != as[i]) {
                ret += factor;
            }
            factor *= prime_factors[i];
        }
        
        // A more mathematical approach is to use the extended greatest common divisor algorithm.
        // First, by assumption of pairwise coprimeness of n1, n2, ..., nk, each n_i is coprime 
        // with N/n_i. Therefore, by the extended greatest common divisor algorithm, we can find 
        // integers s and t such that s*n_i + t*N/n_i = 1. Let e_i := t*N/n_i. Now it follows that 
        //    e_i = 1 (mod n_i)
        // and by definition of e_i, it is divisible by all n_j where j != i so
        //    e_i = 0 (mod n_j), j != i.
        // These two congruences make the es "selector variables" and allow us to write 
        //    x = (SUM e_j*a_j) (mod n_i) for all i (this is because for every i, only one term in the sum 
        // survives).
        // This implies that
        //    x = (SUM e_j*a_j) (mod N)
        // so the first solution (found earlier with a simpler method) is 
        //    x = (SUM e_j*a_j) mod N.
        
        long long ret2 = 0;
        for (int i=0; i<(int)as.size(); ++i) {
            egcds temp = egcd(prime_factors[i], m/prime_factors[i]);
            const long long e = (long long)temp.t * m / prime_factors[i];
            ret2 += e*as[i];
            if (ret2 < 0) { // make positive
                const long long temp2 = (-ret2+m-1)/m;
                ret2 += temp2 * m;
            }
            assert(ret2 >= 0);
            ret2 %= m;
        }
        
        // Both approaches give the same answer, the first one is simpler to understand but slower.
        assert(ret == ret2);
        
        return ret2;
    }
    
    int lucas(int n, int k, int p) {
        // Lucas's theorem states that
        //    choose(n, k) = PROD choose(n_i, k_i) (mod p)
        // where n_i and k_i are factors of the decomposition of n and k in base p
        //    n = n_j*p^j + ... + n_1*p + n_0
        //    k = k_j*p^j + ... + k_1*p + k_0
        // and p is a prime number.
        
        long long ret = 1;
        while (n>0 || k>0) {
            int n_i = n%p;
            int k_i = k%p;
            n /= p;
            k /= p;
            
            // choose(n_i, k_i) mod p = n_i!/(n_i-k_i)! mod p * multiplicative_inverse(k_i!, p) mod p
            // This only works because both n_i and k_i are relatively prime with p (i.e. they are both 
            // less than p and p is prime. Therefore, there are no common factors in these factorials 
            // that will be divisible by p and force the result to zero even though the common factors 
            // cancel in the numerator and the denominator.
            // 
            // It is very important not to calculate n_i!/k_i! mod p * mul_inv((n_i-k_i)!, p), as is 
            // done in the comment, because in cases where k>n, num and denom will be 1! (instead of num being 0)
            /*long long num = 1;
            for (long long x=k_i+1; x<=n_i; ++x) {
                num = (num * x) % p;
            }
            long long denom = 1;
            for (long long x=2; x<=n_i-k_i; ++x) {
                denom = (denom * x) % p;
            }*/
            
            // If k>n, then there will be a 0 factor in the first loop making num 0.
            long long num = 1;
            for (long long x=n_i-k_i+1; x<=n_i; ++x) {
                num = (num * x) % p;
            }
            long long denom = 1;
            for (long long x=2; x<=k_i; ++x) {
                denom = (denom * x) % p;
            }
            
            // We can use Fermat's little theorem here since p is prime so the 
            // inverse of denom is denom^(p-2) mod p
            ret = ret * (num * my_pow(denom, p-2, p) % p) % p;
        }
        
        return int(ret); // will be less than p
    }






   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 32; verify_case(0, Arg2, coloringCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; verify_case(1, Arg2, coloringCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(2, Arg2, coloringCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 103514887; verify_case(3, Arg2, coloringCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 77; int Arg2 = 747707397; verify_case(4, Arg2, coloringCount(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StairsColoring ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
