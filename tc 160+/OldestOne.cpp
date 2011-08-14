#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class OldestOne {
	public:
	int get_number(const string &s) {
		bool num = false;
		int ret = 0;
		for (int i=0; i<(int)s.size(); ++i) {
			if (num) {
				if (!isdigit(s[i]))
					return ret;
				ret = ret*10 + s[i] - '0';
			} else {
				if (isdigit(s[i])) {
					num = true;
					ret = s[i] - '0';
				}
			}
		}
		return ret;
	}
	string get_name(const string &s) {
		int i=0;
		while (isspace(s[i]))
			++i;
		string ret;
		while (!isdigit(s[i]))
			ret += s[i++];
		i = ret.size()-1;
		while (isspace(ret[i])) {
			--i;
			ret = ret.substr(0, ret.size()-1);
		}
		return ret;
	}

	string oldest(vector <string> data) {
		int oldest = -1;
		int age = -1;

		for (int i=0; i<(int)data.size(); ++i) {
			int d = get_number(data[i]);
			if (d > age) {
				oldest = i;
				age = d;
			}
		}
		return get_name(data[oldest]);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"DOUG JONES 22 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BOB     A SMITH"; verify_case(0, Arg1, oldest(Arg0)); }
	void test_case_1() { string Arr0[] = {"DOUG JONES 102 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST",
 "A 1 999ELM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DOUG JONES"; verify_case(1, Arg1, oldest(Arg0)); }
	void test_case_2() { string Arr0[] = {"DOUG JONES 122 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST",
 "A 199 ELM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; verify_case(2, Arg1, oldest(Arg0)); }
	void test_case_3() { string Arr0[] = {"   DOUG                 JONES   122 213 ALDEN LANE",
"   BOB     A SMITH                       102  3",
 " J O H N N Y           199 ELM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "J O H N N Y"; verify_case(3, Arg1, oldest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OldestOne ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
