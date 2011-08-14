#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector< vector<int> > G;
int n;
int S, C;
vector<double> go(int x, int p) {
    vector<double> ret(S+1, 0);
    ret[0] = 1.0;

    for (int i=0; i<(int)G[x].size(); ++i) {
        const int y = G[x][i];
        if (y != p) {
            vector<double> next = go(y, x);
            vector<double> nret(S+1, 0);

            for (int c=0; c<=C; ++c) {
                for (int a=0; a+c<=S; ++a) {
                    for (int b=0; a+b+c<=S; ++b) {
                        nret[max(a, b+c)] += ret[a]*next[b];
                    }
                }
            }

            for (int i=0; i<=S; ++i) {
                ret[i] = nret[i]/(C+1);
            }
        }
    }

    return ret;
}

class PseudoRandomKingdom {
	public:
	double probabilityOfHappiness(vector <string> g, int cost, int savings) {
        n = g.size();
        G.assign(n, vector<int>());
        S = savings;
        C = cost;
        for (int i=0; i<n; ++i) {
            istringstream is(g[i]);
            int x;
            while (is >> x) {
                G[i].push_back(x);
            }
        }

        vector<double> p = go(0, -1);
        double sol = 0;
        for (int i=0; i<=S; ++i) {
            sol += p[i];
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2",
 "0",
 "0 3",
 "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.875; verify_case(0, Arg3, probabilityOfHappiness(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"1 2 3 4 5 6",
 "0",
 "0",
 "0",
 "0",
 "0",
 "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 19; double Arg3 = 0.903158288086044; verify_case(1, Arg3, probabilityOfHappiness(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1 2 3 4 5 6",
 "0",
 "0",
 "0",
 "0",
 "0",
 "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 0; double Arg3 = 5.644739300537775E-7; verify_case(2, Arg3, probabilityOfHappiness(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1",
 "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 500; double Arg3 = 1.0000000000000002; verify_case(3, Arg3, probabilityOfHappiness(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"9 6",
 "6 4",
 "8",
 "5",
 "7 1",
 "8 3",
 "1 0 8",
 "4",
 "2 5 6",
 "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 26; double Arg3 = 0.350862063; verify_case(4, Arg3, probabilityOfHappiness(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PseudoRandomKingdom ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
