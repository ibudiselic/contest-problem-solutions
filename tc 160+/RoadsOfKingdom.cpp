#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double P[16][16];
int bc[1<<16];
double tree[1<<16];
double conn[1<<16][50], nconn[1<<16][50];
int lg[1<<16];
class RoadsOfKingdom {
	public:
	double getProbability(vector <string> roads) {
        for (int i=0; i<(int)roads.size(); ++i) {
            for (int j=0; j<(int)roads.size(); ++j) {
                P[i][j] = (roads[i][j]-'0')/8.0;
            }
        }
        int n = roads.size();
        bc[0] = 0;
        for (int m=1; m<(1<<n); ++m) {
            bc[m] = bc[m>>1] + (m&1);
        }
        
        for (int i=0; i<n; ++i) {
            tree[1<<i] = 1.0;
            lg[1<<i] = i;
        }
        
        for (int m=0; m<(1<<n); ++m) {
            for (int i=0; i<n; ++i) {
                if (((m>>i) & 1) == 0) {
                    double c = 0.0;
                    double nc = 1.0;
                    for (int j=0; j<n; ++j) {
                        if ((m>>j) & 1) {
                            c = c*(1.0 - P[i][j]) + nc*P[i][j];
                            nc *= 1.0 - P[i][j];
                        }
                    }
                    conn[m][i] = c;
                    nconn[m][i] = nc;
                }
            }
        }

        for (int m=0; m<(1<<n); ++m) {
            if (bc[m] < 2) {
                continue;
            }
            tree[m] = 0.0;
            
            for (int s=(m-1)&m; s>0; s=(s-1)&m) {
                int t = m - s;
                if (t > s) {
                    break;
                }
                
                double c = 0.0;
                double nc = 1.0;
                int tt = t;
                while (tt > 0) {
                    int i = lg[tt&(-tt)];
                    c = c*nconn[s][i] + nc*conn[s][i];
                    nc *= nconn[s][i];
                    tt &= tt - 1;
                }
                
                double add = tree[s] * tree[t] * c;
                tree[m] += add;
            }
            
            tree[m] /= bc[m] - 1;
        }
        
        return tree[(1<<n) - 1];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"04",
 "40"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.5; verify_case(0, Arg1, getProbability(Arg0)); }
	void test_case_1() { string Arr0[] = {"08",
 "80"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(1, Arg1, getProbability(Arg0)); }
	void test_case_2() { string Arr0[] = {"00",
 "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, getProbability(Arg0)); }
	void test_case_3() { string Arr0[] = {"088",
 "808",
 "880"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(3, Arg1, getProbability(Arg0)); }
	void test_case_4() { string Arr0[] = {"044",
 "404",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.375; verify_case(4, Arg1, getProbability(Arg0)); }
	void test_case_5() { string Arr0[] = {"0701",
 "7071",
 "0708",
 "1180"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.622314453125; verify_case(5, Arg1, getProbability(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RoadsOfKingdom ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
