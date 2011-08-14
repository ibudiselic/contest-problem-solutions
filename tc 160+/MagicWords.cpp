#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int t[161];
class MagicWords {
	public:
	int count(vector <string> S, int K) {
		vector<int> order;
        for (int i=0; i<(int)S.size(); ++i) {
            order.push_back(i);
        }
        int sol = 0;
        
        do {
            string s;
            s.reserve(320);
            for (int i=0; i<(int)S.size(); ++i) {
                s += S[order[i]];
            }
            string p = s;
            t[0] = -1;
            t[1] = 0;
            int len = 0;
            int i = 2;
            while (i <= (int)p.size()) {
                if (p[i-1] == p[len]) {
                    t[i++] = ++len;                   
                } else if (len > 0) {
                    len = t[len];
                } else {
                    t[i++] = 0;
                }
            }
            
            p += char(0);
            s += s;
            int k = 0;
            int m = 0;
            i = 1;
            while (i+m < (int)s.size()) {
                if (p[m] == s[i+m]) {
                    ++m;
                    if (m+1 == (int)p.size()) {
                        ++k;
                    }
                } else {
                    i += m - t[m];
                    if (m > 0) {
                        m = t[m];
                    }
                }
            }
            
            sol += (k == K);
        } while (next_permutation(order.begin(), order.end()));
            
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"CAD","ABRA","ABRA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AB","RAAB","RA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AA","AA","AAA","A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AA","AA","AAA","A","AAA","AAAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 720; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ABC","AB","ABC","CA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"A","B","C","A","B","C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 672; verify_case(5, Arg2, count(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 40320; verify_case(6, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MagicWords ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
