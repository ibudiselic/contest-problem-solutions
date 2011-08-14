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

struct Name {
	int p, pos;
	string name;
	Name(int p_, int pos_, const string &name_): p(p_), pos(pos_), name(name_) {}
};
bool operator<(const Name &a, const Name &b) {
	if (a.p != b.p)
		return a.p > b.p;
	else
		return a.pos < b.pos;
}

class Popularity {
	public:
	vector <string> sort(vector <string> reply) {
		map<string, int> M;
		for (int i=0; i<(int)reply.size(); ++i) {
			istringstream is(reply[i]);
			string n;
			is >> n;
			++M[n];
		}

		vector<Name> v;
		for (int i=0; i<(int)reply.size(); ++i) {
			istringstream is(reply[i]);
			string n;
			is >> n;
			v.push_back(Name(M[n], i, reply[i]));
		}

		::sort(v.begin(), v.end());
		for (int i=0; i<(int)v.size(); ++i)
			reply[i] = v[i].name;

		return reply;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"DON XI","EAGER TOPLEASE","BJ SMITH","BJ JONES","BJ BJ","DON SMITH","EAGER SMITH"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BJ SMITH", "BJ JONES", "BJ BJ", "DON XI", "EAGER TOPLEASE", "DON SMITH", "EAGER SMITH" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sort(Arg0)); }
	void test_case_1() { string Arr0[] = {"BOB JONES", "BOB ADAMS", "BOBBY ADAMS", "BOB ADAMS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BOB JONES", "BOB ADAMS", "BOB ADAMS", "BOBBY ADAMS" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sort(Arg0)); }
	void test_case_2() { string Arr0[] = {"FRED EVANS","AL BAKER","CAL ADAMS","ED FARMER","AL ADAMS","CAL DETROIT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AL BAKER", "CAL ADAMS", "AL ADAMS", "CAL DETROIT", "FRED EVANS", "ED FARMER" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sort(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Popularity ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
