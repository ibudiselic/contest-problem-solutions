#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class BirdsCounting {
	public:
	double computeProbability(int birdsNumber, int caughtPerDay, int daysNumber, int birdsMarked) {
	    double p[6][21] = {0};
        p[0][0] = 1.0;
        
        long long total = 1;
        for (int i=0; i<caughtPerDay; ++i) {
            total *= birdsNumber-i;
            total /= i+1;
        }
        for (int d=1; d<=daysNumber; ++d) {
            for (int old=0; old<=birdsNumber; ++old) {
                int um = birdsNumber - old;
                for (int add=0; add<=caughtPerDay; ++add) {
                    long long cnt = 1;
                    for (int i=0; i<add; ++i) {
                        cnt *= um-i;
                        cnt /= i+1;
                    }
                    for (int i=0; i<caughtPerDay-add; ++i) {
                        cnt *= old-i;
                        cnt /= i+1;
                    }
                    if (cnt > 0) {
                        p[d][old+add] += p[d-1][old] * double(cnt)/total;
                    }
                }
            }
        }
        
        return p[daysNumber][birdsMarked];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; double Arg4 = 0.6666666666666666; verify_case(0, Arg4, computeProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 5; int Arg3 = 1; double Arg4 = 0.012345679012345678; verify_case(1, Arg4, computeProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 3; int Arg2 = 3; int Arg3 = 7; double Arg4 = 0.2582908163265306; verify_case(2, Arg4, computeProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; int Arg3 = 4; double Arg4 = 0.6; verify_case(3, Arg4, computeProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 20; int Arg1 = 6; int Arg2 = 5; int Arg3 = 17; double Arg4 = 0.30035494805367574; verify_case(4, Arg4, computeProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BirdsCounting ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
