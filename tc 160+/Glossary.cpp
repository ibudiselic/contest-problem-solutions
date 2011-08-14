#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

bool lt(const string &a, const string &b) {
	for (int i=0; i<(int)min(a.size(), b.size()); ++i)
		if (tolower(a[i]) != tolower(b[i]))
			return tolower(a[i]) < tolower(b[i]);
	return a.size() < b.size();
}
class Glossary {
	public:
	vector <string> buildGlossary(vector <string> items) {
		for (int i=0; i<(int)items.size(); ++i)
			for (int j=i+1; j<(int)items.size(); ++j)
				if (lt(items[j], items[i]))
					items[i].swap(items[j]);

		vector<string> left, right;
		for (char c='a'; c<='m'; ++c) {
			bool first = true;
			for (int i=0; i<(int)items.size(); ++i)
				if (tolower(items[i][0]) == c) {
					if (first) {
						left.push_back(string(1, toupper(c)) + string(18, ' '));
						left.push_back(string(19, '-'));
						first = false;
					}
					left.push_back("  " + items[i]);
				}
		}

		for (char c='n'; c<='z'; ++c) {
			bool first = true;
			for (int i=0; i<(int)items.size(); ++i)
				if (tolower(items[i][0]) == c) {
					if (first) {
						right.push_back(string(1, toupper(c)) + string(18, ' '));
						right.push_back(string(19, '-'));
						first = false;
					}
					right.push_back("  " + items[i]);
				}
		}

		vector<string> sol;
		for (int i=0; i<(int)max(left.size(), right.size()); ++i) {
			sol.push_back(string());
			if (i < (int)left.size())
				sol.back() += left[i] + string(19-left[i].size(), ' ');
			else
				sol.back() += string(19, ' ');

			sol.back() += "  ";

			if (i < (int)right.size())
				sol.back() += right[i] + string(19-right[i].size(), ' ');
			else
				sol.back() += string(19, ' ');
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Canada", "France", "Germany", "Italy", "Japan", "Russia",
 "United Kingdom", "United States"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"C                    R                  ", "-------------------  -------------------", "  Canada               Russia           ", "F                    U                  ", "-------------------  -------------------", "  France               United Kingdom   ", "G                      United States    ", "-------------------                     ", "  Germany                               ", "I                                       ", "-------------------                     ", "  Italy                                 ", "J                                       ", "-------------------                     ", "  Japan                                 " }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, buildGlossary(Arg0)); }
	void test_case_1() { string Arr0[] = {"alpha", "beta", "gamma", "delta", "omega"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A                    O                  ", "-------------------  -------------------", "  alpha                omega            ", "B                                       ", "-------------------                     ", "  beta                                  ", "D                                       ", "-------------------                     ", "  delta                                 ", "G                                       ", "-------------------                     ", "  gamma                                 " }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, buildGlossary(Arg0)); }
	void test_case_2() { string Arr0[] = {"AVL tree", "backtracking", "array", "balanced tree", "binary search"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A                                       ", "-------------------                     ", "  array                                 ", "  AVL tree                              ", "B                                       ", "-------------------                     ", "  backtracking                          ", "  balanced tree                         ", "  binary search                         " }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, buildGlossary(Arg0)); }
	void test_case_3() { string Arr0[] = {"XXXXXXXXXXXXXXXXX",
 "YYYYYYYYYYYYYYYYY",
 "ZZZZZZZZZZZZZZZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"                     X                  ", "                     -------------------", "                       XXXXXXXXXXXXXXXXX", "                     Y                  ", "                     -------------------", "                       YYYYYYYYYYYYYYYYY", "                     Z                  ", "                     -------------------", "                       ZZZZZZZZZZZZZZZZZ" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, buildGlossary(Arg0)); }
	void test_case_4() { string Arr0[] = {"Asteria", "Astraeus", "Atlas", "Clymene", "Coeus", "Crius",
 "Cronus", "Dione", "Epimetheus", "Helios", "Hyperion", "Iapetus",
 "Leto", "Mnemosyne", "Oceanus", "Ophion", "Phoebe", "Prometheus",
 "Rhea", "Tethys", "Theia", "Themis"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A                    O                  ", "-------------------  -------------------", "  Asteria              Oceanus          ", "  Astraeus             Ophion           ", "  Atlas              P                  ", "C                    -------------------", "-------------------    Phoebe           ", "  Clymene              Prometheus       ", "  Coeus              R                  ", "  Crius              -------------------", "  Cronus               Rhea             ", "D                    T                  ", "-------------------  -------------------", "  Dione                Tethys           ", "E                      Theia            ", "-------------------    Themis           ", "  Epimetheus                            ", "H                                       ", "-------------------                     ", "  Helios                                ", "  Hyperion                              ", "I                                       ", "-------------------                     ", "  Iapetus                               ", "L                                       ", "-------------------                     ", "  Leto                                  ", "M                                       ", "-------------------                     ", "  Mnemosyne                             " }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, buildGlossary(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Glossary ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
