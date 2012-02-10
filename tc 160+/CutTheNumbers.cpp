#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> B;
int m, n;
bool used[4][4];
int go(int i, int j) {
    if (j == n) {
        return go(i+1, 0);
    }
    if (i == m) {
        return 0;
    }
    if (used[i][j]) {
        return go(i, j+1);
    }
    int ret = 0;
    int num = 0;
    bool cleared = false;
    for (int a=i; a<m; ++a) {
        if (used[a][j]) {
            for (int aa=i; aa<a; ++aa) {
                used[aa][j] = 0;
            }
            cleared = true;
            break;
        }
        used[a][j] = 1;
        num = 10*num + B[a][j]-'0';
        ret = max(ret, num + go(i, j+1));
    }
    if (!cleared) {
        for (int a=i; a<m; ++a) {
            used[a][j] = 0;
        }
    }
    
    num = 0;
    cleared = false;
    for (int b=j; b<n; ++b) {
        if (used[i][b]) {
            for (int bb=j; bb<b; ++bb) {
                used[i][bb] = 0;
            }
            cleared = true;
            break;
        }
        used[i][b] = 1;
        num = 10*num + B[i][b]-'0';
        ret = max(ret, num + go(i, j+1));
    }
    if (!cleared) {
        for (int b=j; b<n; ++b) {
            used[i][b] = 0;
        }
    }
    
    return ret;
}
class CutTheNumbers {
	public:
	int maximumSum(vector <string> board) {
		memset(used, 0, sizeof used);
        B = board;
        m = B.size();
        n = B[0].size();
        return go(0, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"123",
 "312"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 435; verify_case(0, Arg1, maximumSum(Arg0)); }
	void test_case_1() { string Arr0[] = {"99",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 182; verify_case(1, Arg1, maximumSum(Arg0)); }
	void test_case_2() { string Arr0[] = {"001",
 "010",
 "111",
 "100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1131; verify_case(2, Arg1, maximumSum(Arg0)); }
	void test_case_3() { string Arr0[] = {"8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, maximumSum(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CutTheNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
