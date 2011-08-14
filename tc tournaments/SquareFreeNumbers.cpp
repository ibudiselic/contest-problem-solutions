#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool T[1000001];
class SquareFreeNumbers {
	public:
	int getCount(long long min, long long max) {
        vector<long long> primes;
        vector<long long> psqr;

        primes.push_back(2);
        psqr.push_back(4);
        long long cand = 3;
        while (cand*cand <= max) {
            bool ok = true;
            for (int i=1; i<(int)primes.size(); ++i) {
                if (cand % primes[i] == 0) {
                    ok = false;
                    break;
                }
                if (psqr[i] > cand) {
                    break;
                }
            }
            if (ok) {
                primes.push_back(cand);
                psqr.push_back(cand * cand);
            }
            
            cand += 2;
        }

        memset(T, 0, sizeof T);
        for (int i=0; i<(int)psqr.size(); ++i) {
            long long num = (min+psqr[i]-1)/psqr[i] * psqr[i];
            while (num <= max) {
                T[num-min] = 1;
                num += psqr[i];
            }
        }

        int sol = 0;
        for (int i=0; i<max-min+1; ++i) {
            sol += (T[i]==0);
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 10LL; int Arg2 = 7; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 15LL; long long Arg1 = 15LL; int Arg2 = 1; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 1000LL; int Arg2 = 608; verify_case(2, Arg2, getCount(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SquareFreeNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
