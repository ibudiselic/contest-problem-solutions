#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long mod = 1000000003;
string D;
int lcp[2510][2510];
int next_nz[2510];
bool lt(int a, int b, int x, int y) {
    a = next_nz[a];
    if (a >= b) {
        a = b - 1;
    }

    x = next_nz[x];
    if (x >= y) {
        x = y - 1;
    }
    
    if (b-a != y-x) {
        return b-a < y-x;
    }
    const int sz = b-a;
    const int t = lcp[a][x];
    if (t >= sz) {
        return false;
    } else {
        assert(D[a+t] != D[x+t]);
        return D[a+t] < D[x+t];
    }
}

int min_last[2510];
int max_next[2510];
class IncreasingSequence {
	public:
	int getProduct(vector <string> digits) {
		D = digits[0];
        for (int i=1; i<(int)digits.size(); ++i) {
            D += digits[i];
        }
        int n = D.size();
        next_nz[n] = n;
        for (int i=n-1; i>=0; --i) {
            if (D[i] == '0') {
                next_nz[i] = next_nz[i+1];
            } else {
                next_nz[i] = i;
            }
        }

        memset(lcp, 0, sizeof lcp);
        for (int i=n-1; i>=0; --i) {
            for (int j=(int)D.size()-1; j>=0; --j) {
                if (D[i] == D[j]) {
                    lcp[i][j] = lcp[i+1][j+1] + 1;
                }
            }
        }

        min_last[0] = -1;
        min_last[1] = 0;
        for (int i=2; i<=n; ++i) {
            min_last[i] = 0;
            for (int start=i-1; start>=1; --start) {
                if (lt(min_last[start], start, start, i)) {
                    min_last[i] = start;
                    break;
                }
            }
        }

        memset(max_next, 0xff, sizeof max_next);
        max_next[min_last[n]] = n;
        for (int start=min_last[n]-1; start>=0 && D[start]=='0'; --start) {
            max_next[start] = n;
        }

        for (int i=n-1; i>0; --i) {
            if (max_next[i] != -1) {
                for (int j=0; j<i; ++j) {
                    if (lt(j, i, i, max_next[i])) {
                        max_next[j] = max(max_next[j], i);
                    }
                }
            }
        }

        long long ret = 1;
        int p = 0;
        while (p < n) {
            int q = max_next[p];
            long long t = 0;
            for (int i=p; i<q; ++i) {
                t = (t*10 + D[i]-'0') % mod;
            }
            ret = (ret * t) % mod;
            p = q;
        }

        return ret;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12345"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 120; verify_case(0, Arg1, getProduct(Arg0)); }
	void test_case_1() { string Arr0[] = {"543210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 45150; verify_case(1, Arg1, getProduct(Arg0)); }
	void test_case_2() { string Arr0[] = {"20210222"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 932400; verify_case(2, Arg1, getProduct(Arg0)); }
	void test_case_3() { string Arr0[] = {"1111111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1356531; verify_case(3, Arg1, getProduct(Arg0)); }
	void test_case_4() { string Arr0[] = {"171829294246"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 385769340; verify_case(4, Arg1, getProduct(Arg0)); }
	void test_case_5() { string Arr0[] = {"3","235","236"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 264320; verify_case(5, Arg1, getProduct(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    IncreasingSequence ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
