#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <climits>
using namespace std;

class InstantRunoff {
	public:
	string outcome(string candidates, vector <string> ballots) {
		while (candidates.size() > 0) {
			vector<int> win(26, 0);
			int best = -1;
			char who = 0;
			for (int i=0; i<(int)ballots.size(); ++i) {
				++win[ballots[i][0] - 'A'];
				if (best < win[ballots[i][0]-'A']) {
					who = ballots[i][0];
					best = win[ballots[i][0]-'A'];
				}
			}
			if (best*2 > (int)ballots.size())
				return string(1, who);

			int worst = INT_MAX;
			for (int i=0; i<26; ++i)
				if (candidates.find(char('A'+i)) != string::npos)
					worst = min(worst, win[i]);
			for (int i=0; i<26; ++i)
				if (candidates.find(char('A'+i)) != string::npos && win[i]==worst) {
					for (int j=0; j<(int)ballots.size(); ++j)
						ballots[j].erase(ballots[j].find(char('A'+i)), 1);
					candidates.erase(candidates.find(char('A'+i)), 1);
				}
		}
		return string();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABC"; string Arr1[] = {"ACB", "BCA", "ACB", "BCA", "CBA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "B"; verify_case(0, Arg2, outcome(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "DCBA"; string Arr1[] = {"ACBD", "ACBD", "ACBD", "BCAD", "BCAD", "DBCA", "CBDA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "B"; verify_case(1, Arg2, outcome(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ACB"; string Arr1[] = {"ACB", "BCA", "ACB", "BCA", "ACB", "BCA", "CBA", "CAB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(2, Arg2, outcome(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "CAB"; string Arr1[] = {"ACB", "BCA", "ACB", "BCA", "ACB", "BCA", "CAB", "CAB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "A"; verify_case(3, Arg2, outcome(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "Z"; string Arr1[] = {"Z"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Z"; verify_case(4, Arg2, outcome(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    InstantRunoff ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
