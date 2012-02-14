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

int idx[24], C[24], P[24], nP[24];
bool done[24][2][4];
double dp[24][2][4];
double go(int day, int swords, int mask) {
    if (day==24 || swords==0) {
        return 0.0;
    }
    double &ret = dp[day][swords][mask];
    if (done[day][swords][mask]) {
        return ret;
    }
    done[day][swords][mask] = 1;
    if (idx[day]==-1 || (mask & (1<<idx[day]))) {
        ret = go(day+1, swords, mask);
    } else {
        ret = P[day]*max(go(day+1, swords-1, mask | (1<<idx[day])) + C[day],
                         go(day+1, swords, mask | (1<<idx[day])))
              + nP[day]*go(day+1, swords, mask);
        ret /= P[day] + nP[day];
    }
    return ret;
}
class NewItemShopTwo {
	public:
	double getMaximum(vector <string> customers) {
		fill(idx, idx+24, -1);
        for (int i=0; i<2; ++i) {
            istringstream is(customers[i]);
            string s;
            int pleft = 100;
            while (is >> s) {
                int t, c, p;
                sscanf(s.c_str(), "%d,%d,%d", &t, &c, &p);
                idx[t] = i;
                C[t] = c;
                P[t] = p;
                pleft -= p;
                nP[t] = pleft;
            }
        }
        
        memset(done, 0, sizeof done);
        return go(0, 1, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "8,1,80 16,100,11", "12,10,100" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 19.0; verify_case(0, Arg1, getMaximum(Arg0)); }
	void test_case_1() { string Arr0[] = { "8,1,80 16,100,11", "12,10,90 13,30,5" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 19.4; verify_case(1, Arg1, getMaximum(Arg0)); }
	void test_case_2() { string Arr0[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,80" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 90.0; verify_case(2, Arg1, getMaximum(Arg0)); }
	void test_case_3() { string Arr0[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,95" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 95.0; verify_case(3, Arg1, getMaximum(Arg0)); }
	void test_case_4() { string Arr0[] = { "0,3,1 2,4,1 4,5,9 6,2,6 8,5,3 10,5,8 12,9,7 14,9,3", 
  "1,2,3 3,8,4 5,6,2 7,6,4 9,3,3 11,8,3 13,2,7 15,9,5" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0692999999999997; verify_case(4, Arg1, getMaximum(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NewItemShopTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
