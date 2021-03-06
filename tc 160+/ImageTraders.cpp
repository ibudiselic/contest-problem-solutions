#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> P;
int n;
int dp[15][10][1<<15];
int go(int owner, int p, int mask) {
    int &ret = dp[owner][p][mask];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    for (int i=0; i<n; ++i) {
        if (((mask>>i)&1) && P[owner][i]-'0'>=p) {
            ret = max(ret, go(i, P[owner][i]-'0', mask ^ (1<<i)));
        }
    }
    ++ret;
    
    return ret;
}
    
class ImageTraders {
	public:
	int maxOwners(vector <string> price) {
		P = price;
        n = P.size();
        memset(dp, 0xff, sizeof dp);
        
        return go(0, 0, (1<<n)-2);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"01",
"10"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, maxOwners(Arg0)); }
	void test_case_1() { string Arr0[] = {
"022",
"101",
"110"
}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, maxOwners(Arg0)); }
	void test_case_2() { string Arr0[] = {
"01231",
"00231",
"00031",
"00002",
"00000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, maxOwners(Arg0)); }
	void test_case_3() { string Arr0[] = {
"15555",
"11111",
"15111",
"11111",
"11111"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, maxOwners(Arg0)); }
	void test_case_4() { string Arr0[] = {
"0100000000",
"0020000000",
"0003000000",
"0000400000",
"0000050000",
"0000006000",
"0000000700",
"0000000080",
"0000000009",
"1111111111"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(4, Arg1, maxOwners(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ImageTraders ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
