#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<set<string> > memo;
int sol;
class BinaryQuipu {
	public:
	void go(const set<string> &s) {
		memo.insert(s);
		++sol;

		set<string> ss, sb;
		for (set<string>::const_iterator it=s.begin(); it!=s.end(); ++it) {
			if (it->size() > 1)
				if ((*it)[1] == 'b')
					sb.insert(it->substr(1));
				else
					ss.insert(it->substr(1));
		}
		if (!sb.empty() && memo.find(sb)==memo.end())
			go(sb);
		if (!ss.empty() && memo.find(ss)==memo.end())
			go(ss);
	}
	int fewestKnots(vector <string> inventory) {
		memo.clear();

		sol = 0;
		set<string> t;
		for (int i=0; i<(int)inventory.size(); ++i)
			t.insert('s'+inventory[i]);

		go(t);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"bsb", "bbs", "sbbs", "sbs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, fewestKnots(Arg0)); }
	void test_case_1() { string Arr0[] = {"s", "b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, fewestKnots(Arg0)); }
	void test_case_2() { string Arr0[] = {"bs", "sb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, fewestKnots(Arg0)); }
	void test_case_3() { string Arr0[] = {"bs", "sb", "bb", "ss"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, fewestKnots(Arg0)); }
	void test_case_4() { string Arr0[] = {"bssbs", "ssbs", "sbb", "bbs", "sbs", "ssbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(4, Arg1, fewestKnots(Arg0)); }
	void test_case_5() { string Arr0[] = {"bbbsssbbsbbssbbbbs",
"bssssbbbbsbbsbbbbbbsbbsbsssbbbsbbbbbsbbssbsb",
"sbbbbbsbbbsbsssbssssbssbbsssssssbbssss",
"sbbbbbsbsbssbssbsssbsbbsbssbsbbbsbsbs",
"bsbbbbbssbsbbbbsbbs",
"bbsbbsbsssbsbbsbbssbbbsbsssbsbbsbsbssbsbsssbsbsbs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 181; verify_case(5, Arg1, fewestKnots(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BinaryQuipu ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
