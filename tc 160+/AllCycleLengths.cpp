#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

const int SZ = 1000;
bool eq(const string &s, int a, int b, int len) {
    len = min(len, SZ-b);
    for (int i=0; i<len; ++i) {
        if (s[a+i] != s[b+i]) {
            return false;
        }
    }

    return true;
}
class AllCycleLengths {
	public:
	string findAll(vector <string> arcs) {
		string t(SZ, '0');
        int n = arcs.size();
        for (int i=0; i<n; ++i) {
            set<int> S;
            S.insert(i);
            for (int m=0; m<SZ; ++m) {
                set<int> SS;
                for (set<int>::const_iterator it=S.begin(); it!=S.end(); ++it) {
                    const int x = *it;
                    for (int y=0; y<n; ++y) {
                        if (arcs[x][y] == 'Y') {
                            SS.insert(y);
                        }
                    }
                }
                if (t[m]=='0' && SS.count(i)) {
                    t[m] = '1';
                }
                S.swap(SS);
            }
        }

        string sol = t;
        for (int len=1; len<=n; ++len) {
            for (int start=0; start+len+2<(int)sol.size(); ++start) {
                bool ok = true;
                for (int next=start+len; next<SZ; next+=len) {
                    if (!eq(t, start, next, len)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    sol = t.substr(0, start) + "(" + t.substr(start, len) + ")";
                }
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNN", "NNYY", "NNNY", "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "00110(1)"; verify_case(0, Arg1, findAll(Arg0)); }
	void test_case_1() { string Arr0[] = {"NY", "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "(01)"; verify_case(1, Arg1, findAll(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYYYY", "NNYYY", "NNNYY", "NNNNY", "YNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0(1)"; verify_case(2, Arg1, findAll(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNNN", "NNYNN", "NNNYN", "NNNNY", "YNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "010(1)"; verify_case(3, Arg1, findAll(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AllCycleLengths ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
