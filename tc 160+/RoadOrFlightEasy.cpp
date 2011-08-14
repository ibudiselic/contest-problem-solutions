#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

class RoadOrFlightEasy {
	public:
	int minTime(int N, vector <int> roadTime, vector <int> flightTime, int K) {
        int sol = accumulate(roadTime.begin(), roadTime.end(), 0);
        vector<int> d;
        for (int i=0; i<(int)roadTime.size(); ++i) {
            d.push_back(roadTime[i] - flightTime[i]);
        }
        sort(d.begin(), d.end());
        reverse(d.begin(), d.end());
        for (int i=0; i<K; ++i) {
            if (d[i] > 0) {
                sol -= d[i];
            } else {
                break;
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {4, 6, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 13; verify_case(0, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {4, 6, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 9; verify_case(1, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {4, 6, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 6; verify_case(2, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 3, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 6; verify_case(3, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 7; int Arr1[] = {50, 287, 621, 266, 224, 68, 636}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {797, 661, 644, 102, 114, 452, 420}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 1772; verify_case(4, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RoadOrFlightEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
