#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calc(int A, int B, const string &number) {
    int i = 2;
    A *= 10;
    while (i<(int)number.size() && A/B==number[i]-'0') {
        A = A%B*10;
        ++i;
    }
    return i-2;
}
class BestApproximationDiv2 {
	public:
	string findFraction(int maxDen, string number) {
	    int AA, BB;
        int best = -1;
        for (int B=1; B<=maxDen; ++B) {
            int A = 0;
            int p10 = 10;
            int i = 2;
            while (B*9 >= p10) {
                A += B*(number[i]-'0')/p10;
                p10 *= 10;
                ++i;
            }
            i = 0;
            while (i++<10 && A<B) {
                int t = calc(A, B, number);
                if (t > best) {
                    best = t;
                    AA = A;
                    BB = B;
                }
                ++A;
            }
        }
        
        ostringstream os;
        os << AA << '/' << BB << " has " << best+1 << " exact digits";
        return os.str();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 42; string Arg1 = "0.141592658"; string Arg2 = "1/7 has 3 exact digits"; verify_case(0, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "0.1337"; string Arg2 = "0/1 has 1 exact digits"; verify_case(1, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 80000; string Arg1 = "0.1234567891011121314151617181920"; string Arg2 = "10/81 has 8 exact digits"; verify_case(2, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000; string Arg1 = "0.42"; string Arg2 = "3/7 has 3 exact digits"; verify_case(3, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; string Arg1 = "0.420"; string Arg2 = "21/50 has 4 exact digits"; verify_case(4, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 115; string Arg1 = "0.141592658"; string Arg2 = "16/113 has 7 exact digits"; verify_case(5, Arg2, findFraction(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BestApproximationDiv2 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
