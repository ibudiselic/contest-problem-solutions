#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
class SequenceOfCommands {
	public:
	string whatHappens(vector <string> commands) {
		int i = 0;
        int j = 0;
        int d = 0;
        for (int iter=0; iter<10; ++iter) {
            for (int k=0; k<(int)commands.size(); ++k) {
                for (int l=0; l<(int)commands[k].size(); ++l) {
                    if (commands[k][l] == 'S') {
                        i += di[d];
                        j += dj[d];
                    } else if (commands[k][l] == 'L') {
                        d = (d+1)%4;
                    } else {
                        d = (d+3)%4;
                    }
                }
            }
            if (i==0 && j==0) {
                return "bounded";
            }
        }
        return "unbounded";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"L"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bounded"; verify_case(0, Arg1, whatHappens(Arg0)); }
	void test_case_1() { string Arr0[] = {"SRSL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "unbounded"; verify_case(1, Arg1, whatHappens(Arg0)); }
	void test_case_2() { string Arr0[] = {"SSSS","R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bounded"; verify_case(2, Arg1, whatHappens(Arg0)); }
	void test_case_3() { string Arr0[] = {"SRSL","LLSSSSSSL","SSSSSS","L"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "unbounded"; verify_case(3, Arg1, whatHappens(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SequenceOfCommands ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
