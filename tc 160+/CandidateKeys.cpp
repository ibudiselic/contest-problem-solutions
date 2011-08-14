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

int bc[1<<10];
bool valid(int mask, const vector<string> &T) {
	vector<string> s(T.size());
	for (int j=0; j<(int)T[0].size(); ++j) {
		if ((mask>>j) & 1) {
			for (int i=0; i<(int)T.size(); ++i) {
				s[i] += T[i][j];
			}
		}
	}

	sort(s.begin(), s.end());
	return (unique(s.begin(), s.end()) == s.end());
}

set<int> cand;
bool add(int mask) {
	for (set<int>::const_iterator it=cand.begin(); it!=cand.end(); ++it) {
		if ((mask & (*it)) == *it) {
			return false;
		}
	}
	cand.insert(mask);
	return true;
}
	
class CandidateKeys {
	public:
	vector <int> getKeys(vector <string> table) {
		bc[0] = 0;
		for (int i=0; i<(1<<10); ++i) {
			bc[i] = bc[i>>1] + (i&1);
		}
		cand.clear();

		vector<int> sol(2, -1);
		sol[0] = 1234;
		for (int m=0; m<(1<<table[0].size()); ++m) {
			if (valid(m, table) && add(m)) {
				sol[0] = min(sol[0], bc[m]);
				sol[1] = max(sol[1], bc[m]);
			}
		}

		if (sol[1] == -1) {
			return vector<int> ();
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"ABC",
"ABC",
"ABC"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getKeys(Arg0)); }
	void test_case_1() { string Arr0[] = {
"ABC",
"ABD",
"ABE"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getKeys(Arg0)); }
	void test_case_2() { string Arr0[] = {
"ABC",
"ACD",
"BBE"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getKeys(Arg0)); }
	void test_case_3() { string Arr0[] = {"A","B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getKeys(Arg0)); }
	void test_case_4() { string Arr0[] = {
"AABB",
"BABA",
"CAAB",
"DAAA",
"EBBB",
"FBBA",
"GBAB",
"HBAA"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getKeys(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CandidateKeys ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
