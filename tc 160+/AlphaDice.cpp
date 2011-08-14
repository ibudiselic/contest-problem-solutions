#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Dice {
	char top, bottom;
	char left, front, right, back;
	Dice(string s, char c1='*', char c2='*', char c3='*'): top(s[0]), bottom(c1), left(c2), front(s[1]), right(s[2]), back(c3) {}
};
bool comp(const Dice &a, const Dice &b) {
	return (b.top=='*'||a.top==b.top) && (b.bottom=='*'||a.bottom==b.bottom)
				 && (b.left=='*'||a.left==b.left) && (b.front=='*'||a.front==b.front)
				 && (b.right=='*'||a.right==b.right) && (b.back=='*'||a.back==b.back);
}
void rot_h(Dice &a) {
	char c = a.right;
	a.right = a.front;
	a.front = a.left;
	a.left = a.back;
	a.back = c;
}
void rot_v(Dice &a) {
	char c = a.top;
	a.top = a.back;
	a.back = a.bottom;
	a.bottom = a.front;
	a.front = c;
}
/*ostream &operator<<(ostream &os, const Dice &a) {
	os << ' ' << a.top << '\n';
	os << a.left << a.front << a.right << ' ' << a.back << '\n';
	os << ' ' << a.bottom <<'\n';
	return os;
}*/
inline bool test(const string &s) {
	return (s[0]!=s[1]&&s[1]!=s[2]&&s[2]!=s[0]);
}
bool operator==(Dice &a, const Dice &b) {
	int i=0, j;

	do {
		j = 0;
		do {
			if (comp(a, b)) return true;
			rot_h(a);
		} while (++j<4);
		rot_v(a);
	} while (++i<4);
	rot_h(a);
	rot_v(a);
	i = 0;
	do {
		if (comp(a, b)) return true;
		rot_h(a);
	} while (++i<4);
	rot_v(a);
	rot_v(a);
	i = 0;
	do {
		if (comp(a, b)) return true;
		rot_h(a);
	} while (++i<4);
	return false;
}

class AlphaDice {
	public:
	int badData(vector <string> roll) {
		if (!test(roll[0])) return false;
		string s(3, '*');
		vector<bool> used(26, false);
		int cnt = 0;
		int sol = -1;
		used[roll[0][0]-'A']=used[roll[0][1]-'A']=used[roll[0][2]-'A'] = true;
		for (int i=1; i<(int)roll.size(); ++i)
			for (int j=0; j<(int)roll[i].size(); ++j)
				if (!used[roll[i][j]-'A']) {
					used[roll[i][j]-'A'] = true;
					s[cnt++] = roll[i][j];
				}
		vector<int> order;
		for (int i=0; i<3; ++i)
			order.push_back(i);
		do {
			const char c1 = s[order[0]];
			const char c2 = s[order[1]];
			const char c3 = s[order[2]];
			Dice d(roll[0], c1, c2, c3);
			int t = -1;
			for (int i=1; i<(int)roll.size(); ++i)
				if (!test(roll[i]) || !(d==Dice(roll[i]))) {
					t = i;
					sol >?= i;
					break;
				}
			if (t==-1)
				return -1;
		} while (next_permutation(order.begin(), order.end()));
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABC","ZCB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(0, Arg1, badData(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABC","DEF","BCA","GHI","ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, badData(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABA","CDE","CDE","CDE","CDE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, badData(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABC","DEF","BCF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, badData(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AlphaDice ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
