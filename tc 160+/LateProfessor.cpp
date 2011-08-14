#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class LateProfessor {
	public:
	double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival) {
		int ok = 0;
        int period = waitTime + walkTime;
        int p_start = bestArrival/period*period;
        if (bestArrival == worstArrival) {
            return p_start+waitTime>=bestArrival || p_start+period-bestArrival<lateTime ? 0.0 : 1.0;
        }
        for (int i=bestArrival; i<worstArrival; ++i) {
            if (p_start + period == i) {
                p_start += period;
            }
            if (p_start+waitTime>i || p_start+period-i<=lateTime) {
                ++ok;
            }
        }
        
        return 1.0 - double(ok)/(worstArrival-bestArrival);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 0; int Arg4 = 50; double Arg5 = 0.4; verify_case(0, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 30; int Arg4 = 100; double Arg5 = 0.42857142857142855; verify_case(1, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 40; int Arg2 = 50; int Arg3 = 0; int Arg4 = 300; double Arg5 = 0.0; verify_case(2, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 101; int Arg1 = 230; int Arg2 = 10; int Arg3 = 654; int Arg4 = 17890; double Arg5 = 0.6637270828498492; verify_case(3, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 90; int Arg4 = 90; double Arg5 = 1.0; verify_case(4, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 600; int Arg2 = 1; int Arg3 = 17000; int Arg4 = 17000; double Arg5 = 0.0; verify_case(5, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LateProfessor ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
