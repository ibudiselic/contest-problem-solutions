#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const long long mod = 1000000007;
void fix(long long &x) {
    if (x < 0) {
        x += (-x+mod-1)/mod * mod;
    }
    x %= mod;
}
class MegaSum {
	public:
	int calculate(long long N) {
		long long L = int(sqrt(N-1) + 1e-9);
        const long long M = L * L;
        long long diff = N - M;
        int r, c;
        if (diff <= L) {
            r = L + 1;
            c = diff;
        } else {
            r = 2*(L+1) - diff;
            c = L + 1;
        }
        if (L & 1) {
            swap(r, c);
        }
        
        long long S = 1; // S(0, 0)
        long long V = 0, H = 0, C = 1;
        const int sq_lim = min(r, c);
        for (long long i=1; i<sq_lim; ++i) {
            if (i & 1) {
                H = (H + C + i*(i+1)/2*(i+1)%mod*(i+1) - i*i*(i-1)/2 + (i-1)*i*(2*i-1)/6);
                fix(H);
                V = (V + C + i*(i+1)/2*i%mod*i + i*(i+1)*(i+1)/2 - i*(i+1)*(2*i+1)/6);
                fix(V);
            } else {
                V = (V + C + i*(i+1)/2*(i+1)%mod*(i+1) - i*i*(i-1)/2 + (i-1)*i*(2*i-1)/6);
                fix(V);
                H = (H + C + i*(i+1)/2*i%mod*i + i*(i+1)*(i+1)/2 - i*(i+1)*(2*i+1)/6);
                fix(H);
            }
            C = (C + ((i+1) + i*i) * (2*i + 1)) % mod;
            S = (S + C + V + H) % mod;
        }
        
        const long long j = sq_lim;
        if (r > sq_lim) {
            long long h = H + C;
            for (long long i=j; i<r; ++i) {
                if (i & 1) {
                    h = (h + j*(j+1)/2*(i+1)%mod*(i+1) - j*j*(j-1)/2 + (j-1)*j*(2*j-1)/6);
                } else {
                    h = (h + j*(j+1)/2*i%mod*i + j*(j+1)*(j+1)/2 - j*(j+1)*(2*j+1)/6);
                }
                fix(h);
                S = (S + h) % mod;
            }
        } else if (c > sq_lim) {
            long long v = V + C;
            for (long long i=j; i<c; ++i) {
                if (i & 1) {
                    v = (v + j*(j+1)/2*i%mod*i + j*(j+1)*(j+1)/2 - j*(j+1)*(2*j+1)/6);
                } else {
                    v = (v + j*(j+1)/2*(i+1)%mod*(i+1) - j*j*(j-1)/2 + (j-1)*j*(2*j-1)/6);
                }
                fix(v);
                S = (S + v) % mod;
            }
        }
        
        return S;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 8LL; int Arg1 = 58; verify_case(0, Arg1, calculate(Arg0)); }
	void test_case_1() { long long Arg0 = 12LL; int Arg1 = 282; verify_case(1, Arg1, calculate(Arg0)); }
	void test_case_2() { long long Arg0 = 11LL; int Arg1 = 128; verify_case(2, Arg1, calculate(Arg0)); }
	void test_case_3() { long long Arg0 = 6LL; int Arg1 = 50; verify_case(3, Arg1, calculate(Arg0)); }
	void test_case_4() { long long Arg0 = 34539LL; int Arg1 = 437909839; verify_case(4, Arg1, calculate(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MegaSum ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
