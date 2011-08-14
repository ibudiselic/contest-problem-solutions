#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool valid(int i, int n) {
	return (i>=0 && i<n);
}
struct Part {
	int pos, dir;
	Part(int p, int d): pos(p), dir(d) {}
};
class Animation {
	public:
	vector <string> animate(int speed, string init) {
		const int n = (int)init.size();

		vector<Part> a;
		for (int i=0; i<n; ++i)
			if (init[i]=='R')
				a.push_back(Part(i, 1));
			else if (init[i]=='L')
				a.push_back(Part(i, -1));

		const int k = (int)a.size();
		vector<string> sol;
		for (;;) {
			string s(n, '.');
			for (int i=0; i<k; ++i)
				if (valid(a[i].pos, n))
					s[a[i].pos] = 'X';
			sol.push_back(s);
			if (s == string(n, '.'))
				return sol;
			for (int i=0; i<k; ++i)
				a[i].pos += a[i].dir*speed;
		}
		return vector<string>();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; string Arg1 =  "..R...." ; string Arr2[] = { "..X....",  "....X..",  "......X",  "......." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, animate(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "RR..LRL" ; string Arr2[] = { "XX..XXX",  ".X.XX..",  "X.....X",  "......." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, animate(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; string Arg1 = "LRLR.LRLR"; string Arr2[] = { "XXXX.XXXX",  "X..X.X..X",  ".X.X.X.X.",  ".X.....X.",  "........." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, animate(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; string Arg1 = "RLRLRLRLRL"; string Arr2[] = { "XXXXXXXXXX",  ".........." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, animate(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; string Arg1 = "..."; string Arr2[] = { "..." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, animate(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1; string Arg1 = "LRRL.LR.LRR.R.LRRL."; string Arr2[] = { "XXXX.XX.XXX.X.XXXX.",  "..XXX..X..XX.X..XX.",  ".X.XX.X.X..XX.XX.XX",  "X.X.XX...X.XXXXX..X",  ".X..XXX...X..XX.X..",  "X..X..XX.X.XX.XX.X.",  "..X....XX..XX..XX.X",  ".X.....XXXX..X..XX.",  "X.....X..XX...X..XX",  ".....X..X.XX...X..X",  "....X..X...XX...X..",  "...X..X.....XX...X.",  "..X..X.......XX...X",  ".X..X.........XX...",  "X..X...........XX..",  "..X.............XX.",  ".X...............XX",  "X.................X",  "..................." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, animate(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Animation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
