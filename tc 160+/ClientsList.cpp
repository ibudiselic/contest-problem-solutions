#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

/*
Some of the names are in "First Last" format, while the rest are in "Last, First" format.
You are to return a vector <string> with all of the names in "First Last" format, sorted by last name, then by first name.
*/
class ClientsList {
	public:
	vector <string> dataCleanup(vector <string> names) {
		vector< pair<string, string> > v;

		for (int i=0; i<(int)names.size(); ++i) {
			if (names[i].find(',') == string::npos) {
				v.push_back(make_pair("", ""));
				istringstream is(names[i]);
				is >> v.back().second >> v.back().first;
			} else {
				v.push_back(make_pair(names[i].substr(0, names[i].find(',')), names[i].substr(names[i].find(',')+2)));
			}
		}
		sort(v.begin(), v.end());

		vector<string> sol;
		for (int i=0; i<(int)v.size(); ++i)
			sol.push_back(v[i].second + " " + v[i].first);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Joe Smith", "Brown, Sam", "Miller, Judi"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Sam Brown",  "Judi Miller",  "Joe Smith" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, dataCleanup(Arg0)); }
	void test_case_1() { string Arr0[] = {"Campbell, Phil", "John Campbell", "Young, Warren"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "John Campbell",  "Phil Campbell",  "Warren Young" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, dataCleanup(Arg0)); }
	void test_case_2() { string Arr0[] = {"Kelly, Anthony", "Kelly Anthony", "Thompson, Jack"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Kelly Anthony",  "Anthony Kelly",  "Jack Thompson" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, dataCleanup(Arg0)); }
	void test_case_3() { string Arr0[] = {"Trevor Alvarez", "Jackson, Walter", "Mandi Stuart",
 "Martin, Michael", "Peters, Tammy", "Richard Belmont",
 "Carl Thomas", "Ashton, Roger", "Jamie Martin"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Trevor Alvarez",  "Roger Ashton",  "Richard Belmont",  "Walter Jackson",  "Jamie Martin",  "Michael Martin",  "Tammy Peters",  "Mandi Stuart",  "Carl Thomas" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, dataCleanup(Arg0)); }
	void test_case_4() { string Arr0[] = {"Banks, Cody", "Cody Banks", "Tod Wilson"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Cody Banks",  "Cody Banks",  "Tod Wilson" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, dataCleanup(Arg0)); }
	void test_case_5() { string Arr0[] = {"Mill, Steve", "Miller, Jane"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Steve Mill",  "Jane Miller" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, dataCleanup(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ClientsList ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
