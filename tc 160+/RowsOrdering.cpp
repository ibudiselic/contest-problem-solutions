#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

const long long mod = 1000000007;

long long pow_mod(long long n, long long k) {
    long long ret = 1;
    while (k > 0) {
        if (k & 1) {
            ret = ret*n % mod;
        }
        n = n*n % mod;
        k >>= 1;
    }
    return ret;
}
class RowsOrdering {
	public:
	int order(vector <string> rows) {
		int m = rows.size();
        int n = rows[0].size();
        
        vector<int> vals;
        for (int j=0; j<n; ++j) {
            int cnt[51] = {0};
            for (int i=0; i<m; ++i) {
                ++cnt[rows[i][j]<='Z' ? rows[i][j]-'A'+26 : rows[i][j]-'a'];
            }
            sort(cnt, cnt+50, greater<int>());
            int val = 0;
            for (int i=1; cnt[i]>0; ++i) {
                val += i*cnt[i];
            }
            vals.push_back(val);
        }
        sort(vals.begin(), vals.end());
        
        long long ret = m;
        for (int i=0; i<n; ++i) {
            ret = ret + vals[i]*pow_mod(50, n-1-i) % mod;
        }
        return int(ret % mod); 
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"bb", "cb", "ca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 54; verify_case(0, Arg1, order(Arg0)); }
	void test_case_1() { string Arr0[] = {"abcd", "ABCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 127553; verify_case(1, Arg1, order(Arg0)); }
	void test_case_2() { string Arr0[] = {"Example", "Problem"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 943877448; verify_case(2, Arg1, order(Arg0)); }
	void test_case_3() { string Arr0[] = {"a", "b", "c", "d", "e", "f", "g"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, order(Arg0)); }
	void test_case_4() { string Arr0[] = {"a", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, order(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RowsOrdering ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
