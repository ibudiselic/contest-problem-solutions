#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class BestApproximationDiv1 {
	public:
	string findFraction(int maxDen, string number) {
		int best = -1;
        int AA, BB;
        char buff[50];
        for (int B=1; B<=maxDen; ++B) {
            for (int A=0; A<B; ++A) {
                sprintf(buff, "%06d", A*1000000/B);
                int i = 0;
                while (i<6 && number[i+2]==buff[i]) {
                    ++i;
                }
                if (i > best) {
                    best = i;
                    AA = A;
                    BB = B;
                }
            }
        }
        ostringstream os;
        os << AA << "/" << BB << " has " << best+1 << " exact digits";
        return os.str();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 42; string Arg1 = "0.141592"; string Arg2 = "1/7 has 3 exact digits"; verify_case(0, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "0.133700"; string Arg2 = "0/1 has 1 exact digits"; verify_case(1, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000; string Arg1 = "0.123456"; string Arg2 = "10/81 has 7 exact digits"; verify_case(2, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000; string Arg1 = "0.420000"; string Arg2 = "21/50 has 7 exact digits"; verify_case(3, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; string Arg1 = "0.909999"; string Arg2 = "10/11 has 4 exact digits"; verify_case(4, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 115; string Arg1 = "0.141592"; string Arg2 = "16/113 has 7 exact digits"; verify_case(5, Arg2, findFraction(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BestApproximationDiv1 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
