#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

class ItemizedList {
	public:
	vector <string> generateList(vector <string> items) {
		map<string, int> m;

		for (int i=0; i<(int)items.size(); ++i)
			++m[items[i]];

		vector<string> sol;
		for (map<string, int>::const_iterator it=m.begin(); it!=m.end(); ++it) {
			ostringstream os;
			os << it->first << " - " << it->second;
			sol.push_back(os.str());
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"apple", "orange", "apple", "banana", "apple", "orange"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"apple - 3", "banana - 1", "orange - 2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, generateList(Arg0)); }
	void test_case_1() { string Arr0[] = {"apple", "apple", "apple", "apple"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"apple - 4" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, generateList(Arg0)); }
	void test_case_2() { string Arr0[] = {"apple", "orange", "banana"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"apple - 1", "banana - 1", "orange - 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, generateList(Arg0)); }
	void test_case_3() { string Arr0[] = {"apple", "orange", "apple", "banana", "apple",
 "apple", "orange", "apple", "banana", "apple",
 "apple", "orange", "apple", "banana", "apple"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"apple - 9", "banana - 3", "orange - 3" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, generateList(Arg0)); }
	void test_case_4() { string Arr0[] = {"apple"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"apple - 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, generateList(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ItemizedList ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
