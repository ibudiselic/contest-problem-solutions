#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SequenceSums {
	public:
	vector <int> sequence(int N, int L) {
		for (int i=L; i<=100; ++i) {
            int t = (N - i*(i-1)/2) / i;
            if (t>=0 && N==i*t+i*(i-1)/2) {
                vector<int> sol;
                for (int j=0; j<i; ++j) {
                    sol.push_back(t+j);
                }
                return sol;
            }
        }

        return vector<int>();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 18; int Arg1 = 2; int Arr2[] = {5, 6, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, sequence(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 18; int Arg1 = 4; int Arr2[] = {3, 4, 5, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, sequence(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 18; int Arg1 = 5; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, sequence(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 45; int Arg1 = 10; int Arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, sequence(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 2; int Arr2[] = {199999998, 199999999, 200000000, 200000001, 200000002 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, sequence(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SequenceSums ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
