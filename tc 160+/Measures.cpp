#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Measures {
	public:
	int beatsPerM(vector <int> loudness) {
		for (int m=2; m<=10; ++m) {
			for (int beg=0; beg<m; ++beg) {
				int good = 0;
				int fm = 0;
				for (int i=beg; i<(int)loudness.size(); i+=m) {
					if ((int)loudness.size()-i < m) break;
					++fm;
					int best = loudness[i];
					for (int j=1; j<m; ++j) best = max(best, loudness[i+j]);
					if (best == loudness[i]) ++good;
				}
				//cerr << m << ' ' << beg << ' ' << fm << ' ' << good << '\n';
				if (fm && 80*fm<=100*good) return m;
			}
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,9,3,0,9,3,1,9,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, beatsPerM(Arg0)); }
	void test_case_1() { int Arr0[] = {3,9,3,0,9,3,1,9,11,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, beatsPerM(Arg0)); }
	void test_case_2() { int Arr0[] = {5,2,5,2,8,6,3,5,5,1,9,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, beatsPerM(Arg0)); }
	void test_case_3() { int Arr0[] = {3,9,65,2,8,7,66,22,11,43,26,77,78,79,80,81,82,83,3,5,8,9,4,20,21,22,23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, beatsPerM(Arg0)); }
	void test_case_4() { int Arr0[] = {1,6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, beatsPerM(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Measures ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
