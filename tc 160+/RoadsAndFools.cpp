#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

class RoadsAndFools {
	public:
	string determineOrientation(int length, vector <int> front) {
		int n = front.size();
		for (int i=1; i<n; ++i)
			if (front[i] <= front[i-1]) {
				int t = length - front[i-1];
				if ((i==1 || t>front[i-2]) && front[i]>t)
					front[i-1] = t;
				else {
					t = length - front[i];
					if (t > front[i-1])
						front[i] = t;
					else
						return "NO SOLUTION";
				}
			}

		for (int i=0; i<n; ++i) {
			const int t = length - front[i];
			if (t!=front[i] && (i==0 || front[i-1]<t) && (i==n-1 || front[i+1]>t))
				return "MULTIPLE SOLUTIONS";
		}

		ostringstream os;
		for (int i=0; i<n; ++i) {
			if (i)
				os << ' ';
			os << front[i];
		}
		return os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1 2 3"; verify_case(0, Arg2, determineOrientation(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {5, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "MULTIPLE SOLUTIONS"; verify_case(1, Arg2, determineOrientation(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1 4"; verify_case(2, Arg2, determineOrientation(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {4, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO SOLUTION"; verify_case(3, Arg2, determineOrientation(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "MULTIPLE SOLUTIONS"; verify_case(4, Arg2, determineOrientation(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 10; int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "5"; verify_case(5, Arg2, determineOrientation(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RoadsAndFools ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
