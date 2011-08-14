#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> sol;
int M, N;

void draw_frame(int u, int l, int szi, int szj) {
	int d = u + szi - 1;
	int r = l + szj - 1;

	if (u>=0 && u<M) {
		int a = max(0, l);
		int b = min(r, N-1);
		for (int j=a; j<=b; ++j)
			sol[u][j] = '-';

		if (l>=0 && l<N)
			sol[u][l] = '+';
		if (r>=0 && r<N)
			sol[u][r] = '+';
	}
	if (d>=0 && d<M) {
		int a = max(0, l);
		int b = min(r, N-1);
		for (int j=a; j<=b; ++j)
			sol[d][j] = '-';

		if (l>=0 && l<N)
			sol[d][l] = '+';
		if (r>=0 && r<N)
			sol[d][r] = '+';
	}

	if (l>=0 && l<N) {
		int a = max(0, u+1);
		int b = min(d-1, M-1);
		for (int i=a; i<=b; ++i)
			sol[i][l] = '|';
	}
	if (r>=0 && r<N) {
		int a = max(0, u+1);
		int b = min(d-1, M-1);
		for (int i=a; i<=b; ++i)
			sol[i][r] = '|';
	}
}
void draw_fill(int u, int l, int szi, int szj, char fill) {
	int d = u + szi - 1;
	int r = l + szj - 1;

	++u;
	--d;
	++l;
	--r;

	int x = max(0, u);
	int y = min(d, M-1);
	int z = max(0, l);
	int w = min(r, N-1);

	for (int i=x; i<=y; ++i)
		for (int j=z; j<=w; ++j)
			sol[i][j] = fill;
}
class WindowManager {
	public:
	vector <string> screen(int height, int width, vector <string> windows) {
		M = height;
		N = width;
		sol.assign(M, string(N, ' '));

		for (int i=0; i<(int)windows.size(); ++i) {
			istringstream is(windows[i]);
			int offi, offj, szi, szj;
			char fill;
			is >> offi >> offj >> szi >> szj >> fill;
			draw_frame(offi, offj, szi, szj);
			draw_fill(offi, offj, szi, szj, fill);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 6; string Arr2[] = {"-5 -5 20 20 O", "0 0 2 2 Y", "0 0 4 6 X"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "+----+",  "|XXXX|",  "|XXXX|",  "+----+" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, screen(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 7; string Arr2[] = {"-5 -5 20 12 9", "2 2 15 15 @", "2 2 3 3 *"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "999999|",  "999999|",  "99+-+--",  "99|*|@@",  "99+-+@@",  "99|@@@@",  "99|@@@@" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, screen(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {"-20000 -20000 5 5 X"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { " " }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, screen(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; string Arr2[] = {"-1000000 -1000000 2000000 2000000 L"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "LLLLL",  "LLLLL",  "LLLLL",  "LLLLL",  "LLLLL" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, screen(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WindowManager ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
