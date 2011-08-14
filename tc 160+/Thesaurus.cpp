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

class Thesaurus {
	public:
	vector <string> edit(vector <string> entry) {
		vector< set<string> > w;

		for (int i=0; i<(int)entry.size(); ++i) {
			istringstream is(entry[i]);
			string t;
			w.push_back(set<string>());
			while (is >> t)
				w.back().insert(t);
		}

		while (1) {
			for (int i=0; i<(int)w.size()-1; ++i)
				for (int j=i+1; j<(int)w.size(); ++j) {
					vector<string> s;
					set_intersection(w[i].begin(), w[i].end(), w[j].begin(), w[j].end(), back_inserter(s));
					if (s.size() >= 2) {
						w[i].insert(w[j].begin(), w[j].end());
						w.erase(w.begin()+j);
						goto NEXT;
					}
				}
			break;

			NEXT:;
		}

		vector<string> sol;
		for (int i=0; i<(int)w.size(); ++i) {
			string s;
			for (set<string>::const_iterator it=w[i].begin(); it!=w[i].end(); ++it)
				s += *it + ' ';
			sol.push_back(s.substr(0, s.size()-1));
		}

		sort(sol.begin(), sol.end());

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ape monkey wrench", "wrench twist strain"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ape monkey wrench",  "strain twist wrench" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, edit(Arg0)); }
	void test_case_1() { string Arr0[] = {"ape monkey wrench", "wrench twist strain", "monkey twist frugue"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ape monkey wrench",  "frugue monkey twist",  "strain twist wrench" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, edit(Arg0)); }
	void test_case_2() { string Arr0[] = {"ape monkey wrench", "wrench twist strain", "monkey twist frugue strain"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ape frugue monkey strain twist wrench" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, edit(Arg0)); }
	void test_case_3() { string Arr0[] = {"point run score","point dot","cut run tear score","cut valley","cute pretty"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "cut point run score tear",  "cut valley",  "cute pretty",  "dot point" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, edit(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Thesaurus ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
