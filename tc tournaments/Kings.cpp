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

string to_str(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
class Kings {
	public:
	vector <string> enumerate(vector <string> names) {
		map<string, vector<int> > m;

		for (int i=0; i<(int)names.size(); ++i)
			m[names[i]].push_back(i);

		for (map<string, vector<int> >::const_iterator it=m.begin(); it!=m.end(); ++it)
			if (it->second.size() > 1)
				for (int j=0; j<(int)it->second.size(); ++j)
					names[it->second[j]] += ' ' + to_str(j+1);

		return names;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"WILLIAM", "GEORGE", "PAUL", "GEORGE", "GEORGE", "WILLIAM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"WILLIAM 1", "GEORGE 1", "PAUL", "GEORGE 2", "GEORGE 3", "WILLIAM 2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, enumerate(Arg0)); }
	void test_case_1() { string Arr0[] = {"OLE", "BJORN", "OLE", "GUNNAR", "LUDVIG", "CHRISTIAN", "LUDWIG",
"KARL", "CHRISTIAN", "LUDWIG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"OLE 1", "BJORN", "OLE 2", "GUNNAR", "LUDVIG", "CHRISTIAN 1", "LUDWIG 1", "KARL", "CHRISTIAN 2", "LUDWIG 2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, enumerate(Arg0)); }
	void test_case_2() { string Arr0[] = {"BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB",
"BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB",
"BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB",
"BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB",
"BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB", "BOB",
"BOB", "BOB", "BOB", "BOB", "BOB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BOB 1", "BOB 2", "BOB 3", "BOB 4", "BOB 5", "BOB 6", "BOB 7", "BOB 8", "BOB 9", "BOB 10", "BOB 11", "BOB 12", "BOB 13", "BOB 14", "BOB 15", "BOB 16", "BOB 17", "BOB 18", "BOB 19", "BOB 20", "BOB 21", "BOB 22", "BOB 23", "BOB 24", "BOB 25", "BOB 26", "BOB 27", "BOB 28", "BOB 29", "BOB 30", "BOB 31", "BOB 32", "BOB 33", "BOB 34", "BOB 35", "BOB 36", "BOB 37", "BOB 38", "BOB 39", "BOB 40", "BOB 41", "BOB 42", "BOB 43", "BOB 44", "BOB 45", "BOB 46", "BOB 47", "BOB 48", "BOB 49", "BOB 50" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, enumerate(Arg0)); }
	void test_case_3() { string Arr0[] = {"SEAN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SEAN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, enumerate(Arg0)); }
	void test_case_4() { string Arr0[] = {"IAMUNIQUE", "METOO", "ANDME", "ANDMETOO"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"IAMUNIQUE", "METOO", "ANDME", "ANDMETOO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, enumerate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Kings ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
