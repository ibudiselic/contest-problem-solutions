#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int n;
const int INF = 123456789;
int p[50];
bool done[50];
int cnt[256];
int calc(const string &a, const string &b) {
    memset(cnt, 0, sizeof cnt);
    for (int i=0; i<n; ++i) {
        if (++cnt[b[i]] > 1) {
            return INF;
        }
    }
    for (int i=0; i<n; ++i) {
        p[i] = -1;
        done[i] = 0;
        for (int j=0; j<n; ++j) {
            if (b[j] == a[i]) {
                p[i] = j;
                break;
            }
        }
        if (p[i] == -1) {
            return INF;
        }
    }
    
    int ret = 0;
    for (int i=0; i<n; ++i) {
        if (!done[i]) {
            int j = i;
            int len = 0;
            do {
                done[j] = 1;
                j = p[j];
                ++len;
            } while (j != i);
            ret += len - 1;
        }
    }
    return ret;
}
class WordsGame {
	public:
	int minimumSwaps(vector <string> grid, string word) {
        int sol = INF;
		n = grid.size();
        for (int i=0; i<n; ++i) {
            sol = min(sol, calc(word, grid[i]));
        }
        vector<string> grid2 = grid;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                grid2[i][j] = grid[j][i];
            }
        }
        for (int i=0; i<n; ++i) {
            sol = min(sol, calc(word, grid2[i]));
        }
        
        return sol==INF ? -1 : sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Mu",
 "uM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Mu"; int Arg2 = 0; verify_case(0, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"sdf",
 "bca",
 "hgf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; int Arg2 = 2; verify_case(1, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"cdf",
 "bca",
 "agf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; int Arg2 = 1; verify_case(2, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"xSZB",
 "gbHk",
 "kbgH",
 "WFSg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bkHg"; int Arg2 = 2; verify_case(3, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"eKUNGHktLB",
 "EtBFDndTlG",
 "RRFHmjwrDs",
 "eKYsHlYhlu",
 "ljxyJSwTds",
 "dUQToyWHvl",
 "azDPWRwioE",
 "EARdktoDBh",
 "dmIqcGSvCE",
 "wXypNQEMxz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "oDmWcJHGNk"; int Arg2 = 6; verify_case(4, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"ab",
 "bA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aB"; int Arg2 = -1; verify_case(5, Arg2, minimumSwaps(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    WordsGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
