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

class PairwiseSums {
	public:
	vector <int> reverse(vector <string> sums) {
		string S_;
		for (int i=0; i<(int)sums.size(); ++i)
			S_ += sums[i] + ' ';

		istringstream is(S_);
		vector<int> P;
		int x;
		while (is >> x)
			P.push_back(x);
		sort(P.begin(), P.end());

		vector<int> sol;
		for (int smallestA=0; smallestA<=P[0]/2; ++smallestA) {
			vector<int> A;
			A.push_back(smallestA);

			multiset<int> MS(P.begin(), P.end());
			while (!MS.empty()) {
				const int next = *MS.begin() - smallestA;
				if (next < A[A.size()-1])
					goto fail;

				for (int i=0; i<(int)A.size(); ++i) {
					const multiset<int>::const_iterator it = MS.find(A[i] + next);
					if (it == MS.end())
						goto fail;
					else
						MS.erase(it);
				}
				A.push_back(next);
			}

			if (sol.size() != 0)
				return vector<int>();
			else
				sol = A;
			fail: ;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"3 5 4 7 6 5"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  2,  3,  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, reverse(Arg0)); }
	void test_case_1() { string Arr0[] = {"0", "1000", "1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  0,  1000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, reverse(Arg0)); }
	void test_case_2() { string Arr0[] = {"15 30 45 60"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, reverse(Arg0)); }
	void test_case_3() { string Arr0[] = {"5 6 7 9 10 11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, reverse(Arg0)); }
	void test_case_4() { string Arr0[] = {"910 689 882 565 922 815 457 674 495 653 755 948",
 "631 988 881 523 740 561 719 727 410 767 660 302",
 "519 340 498 603 960 853 495 712 533 691 643 536",
 "178 395 216 374 893 535 752 573 731 428 645 466",
 "624 287 108 266 325 483 304"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 35,  73,  143,  231,  252,  267,  393,  422,  460,  488,  500 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, reverse(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PairwiseSums ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
