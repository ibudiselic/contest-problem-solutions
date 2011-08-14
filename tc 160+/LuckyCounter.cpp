#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class LuckyCounter {
	public:
	int countLuckyMoments(vector <string> moments) {
		int sol = 0;
        for (int i=0; i<(int)moments.size(); ++i) {
            const string &s = moments[i];
            sol += (s[0]==s[3] && s[1]==s[4]) || (s[0]==s[1] && s[3]==s[4]) || (s[0]==s[4] && s[1]==s[3]);
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12:21", "11:10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countLuckyMoments(Arg0)); }
	void test_case_1() { string Arr0[] = {"00:00", "00:59", "23:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, countLuckyMoments(Arg0)); }
	void test_case_2() { string Arr0[] = {"12:34"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countLuckyMoments(Arg0)); }
	void test_case_3() { string Arr0[] = {"12:11", "22:22", "00:01", "03:30", "15:15", "16:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, countLuckyMoments(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LuckyCounter ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
