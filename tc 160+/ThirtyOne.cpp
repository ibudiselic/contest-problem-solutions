#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int to_int(const string &s) {
	istringstream is(s);
	int x;
	is >> x;
	return x;
}
void process(const string &s, int &sum, int &aces) {
	aces += s=="A";
	switch (s[0]) {
		case 'J': case 'Q': case 'K':
			sum += 20;
			break;
		case 'A':
			sum += 2;
			break;
		default:
			sum += 2*to_int(s);
			break;
	}
}
int eval(const string &s) {
	istringstream is(s);
	string a, b, c;
	is >> a >> b >> c;

	if (a==b && b==c)
		return 61;

	int aces = 0;
	int sum = 0;
	process(a, sum, aces);
	process(b, sum, aces);
	process(c, sum, aces);

	if (sum > 62)
		return 0;

	while (aces-- && sum+20<=62)
		sum += 20;

	return sum;
}
class ThirtyOne {
	public:
	int findWinner(vector <string> hands) {
		int sol = -1;
		int val = 0;

		for (int i=0; i<(int)hands.size(); ++i) {
			const int t = eval(hands[i]);
			if (t > val) {
				sol = i;
				val = t;
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10 A A", "K 2 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, findWinner(Arg0)); }
	void test_case_1() { string Arr0[] = {"2 3 4", "10 6 8", "A K 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, findWinner(Arg0)); }
	void test_case_2() { string Arr0[] = {"J 5 2","2 7 5","10 J 2","J 6 2","J Q K"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, findWinner(Arg0)); }
	void test_case_3() { string Arr0[] = {"Q K K", "10 J Q", "A 8 A", "2 2 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, findWinner(Arg0)); }
	void test_case_4() { string Arr0[] = {"Q 6 6","7 8 3","3 7 2","K Q 6","Q 6 3","5 3 8","10 J Q","4 8 4","Q 2 5","8 A 8",
"9 10 10","2 K 5","10 4 5","Q 4 Q","3 J 2","7 4 4","3 9 7","A 4 4","Q 7 7","10 9 A",
"J 3 5","5 8 9","Q Q 7"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, findWinner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ThirtyOne ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
