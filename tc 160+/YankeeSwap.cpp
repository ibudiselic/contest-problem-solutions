#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool test(string cur, int x, const string &get) {
	for (int i=x+1; i<(int)cur.size(); ++i)
		for (int j=0; j<(int)cur.size(); ++j)
			if (cur[j] == get[i]) {
				swap(cur[i], cur[j]);
				break;
			}

	return (cur == get);
}
class YankeeSwap {
	public:
	string sequenceOfSwaps(vector <string> pref) {
		int n = pref.size();
		string get(n, ' ');
		vector<bool> used(26, false);

		for (int i=n-1; i>=0; --i)
			for (int j=0; j<(int)pref[i].size(); ++j)
				if (!used[pref[i][j]-'A']) {
					used[pref[i][j]-'A'] = true;
					get[i] = pref[i][j];
					break;
				}

		string cur;
		for (int i=0; i<n; ++i)
			cur += char('A'+i);

		string sol(n, ' ');
		for (int i=0; i<n; ++i) {
			if (test(cur, i, get)) {
				sol[i] = '-';
				continue;
			}
			for (int j=0; j<n; ++j)
				if (j != i) {
					swap(cur[i], cur[j]);
					if (test(cur, i, get)) {
						sol[i] = char('a'+j);
						break;
					}
					swap(cur[i], cur[j]);
				}
			assert(sol[i] != ' ');
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BAC",
 "ACB",
 "BCA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-aa"; verify_case(0, Arg1, sequenceOfSwaps(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABC",
 "BCA",
 "CAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "---"; verify_case(1, Arg1, sequenceOfSwaps(Arg0)); }
	void test_case_2() { string Arr0[] = {"AECDBF",
 "BAEDCF",
 "DEBACF",
 "BEDCAF",
 "CEABDF",
 "CBDEAF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-aac-a"; verify_case(2, Arg1, sequenceOfSwaps(Arg0)); }
	void test_case_3() { string Arr0[] = {"FDBHMAIELGKNJC",
 "KGMDJBAFLECNHI",
 "FKLJCADBEHNGIM",
 "JMHNICABFKEGDL",
 "IKFCDNJBLEGAMH",
 "FDNLJGCKHMBIEA",
 "MBKJAHDNIGECLF",
 "KNADLFGBJIMHCE",
 "AIFMGEBDHKJNCL",
 "MCDALIJGNKBFHE",
 "AJHMDLEIFKNCGB",
 "IJLKBCMDGNHFEA",
 "EAKFLJBDGMHCIN",
 "JEMANBDFGICHKL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "--acacbdcahcja"; verify_case(3, Arg1, sequenceOfSwaps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    YankeeSwap ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
