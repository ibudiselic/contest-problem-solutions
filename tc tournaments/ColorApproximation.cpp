#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define maximize(x, y) ((x) = max((x), (y)))
#define minimize(x, y) ((x) = min((x), (y)))
class ColorApproximation {
	public:
	string bestApproximation(vector <string> colors) {
		vector<int> hi(3, 0);
		vector<int> lo(3, 255);
		for (int i=0; i<(int)colors.size(); ++i) {
			istringstream is(colors[i]);
			string w;

			while (is >> w) {
				int r, g, b;
				sscanf(w.c_str(), "%2X%2X%2X", &r, &g, &b);
				maximize(hi[0], r);
				maximize(hi[1], g);
				maximize(hi[2], b);
				minimize(lo[0], r);
				minimize(lo[1], g);
				minimize(lo[2], b);
			}
		}

		int solR=0, solG=0, solB=0;
		int dist = 1234567890;

		for (int r=0; r<256; ++r) {
			int dr = max(abs(r-hi[0]), abs(r-lo[0]));
			if (dr >= dist)
				continue;
			for (int g=0; g<256; ++g) {
				int dg = max(dr, max(abs(g-hi[1]), abs(g-lo[1])));
				if (dg >= dist)
					continue;
				for (int b=0; b<256; ++b) {
					int d = max(dg, max(abs(b-hi[2]), abs(b-lo[2])));
					if (d < dist) {
						dist = d;
						solR = r;
						solG = g;
						solB = b;
					}
				}
			}
		}

		char buff[16];
		sprintf(buff, "%02X%02X%02X", solR, solG, solB);
		return string(buff);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"F36F4E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "F36F4E"; verify_case(0, Arg1, bestApproximation(Arg0)); }
	void test_case_1() { string Arr0[] = {"7A946B","3B6473"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "5A7453"; verify_case(1, Arg1, bestApproximation(Arg0)); }
	void test_case_2() { string Arr0[] = {"40FE20", "800040"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "017F00"; verify_case(2, Arg1, bestApproximation(Arg0)); }
	void test_case_3() { string Arr0[] = {"626848 321D3A 60EACA 521A88 9C188F",
 "94F0B3 B55795 B34004 20983C 7A644B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "49845E"; verify_case(3, Arg1, bestApproximation(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ColorApproximation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
