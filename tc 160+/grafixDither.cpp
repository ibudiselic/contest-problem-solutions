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
vector<string> G;
int N;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

/*
The error is added to the current source pixel. If the source pixel now has a negative value, we set it to 0,
and if it is greater than 255, we set it to 255. Otherwise, we leave the source pixel as it was after adding the error.
If the source pixel is 127 or less, we set the corresponding target pixel to 0. Otherwise, we set the target pixel to 255.
Now we subtract the value of the target pixel from that of the source pixel, and this difference becomes the new error value.
*/

int getVal(char c) {
	if (islower(c))
		return (c-'a')*5;
	else
		return 130 + (c-'A')*5;
}
int error;
void go(int sz, int si, int sj, int d, int dir) {
	if (sz == 2) {
		for (int step=0; step<4; ++step) {
			int val = getVal(G[si][sj]);
			val += error;

			if (val < 0)
				val = 0;
			else if (val > 255)
				val = 255;

			int nval = (val<=127 ? 0 : 255);
			error = val - nval;

			G[si][sj] = (nval ? 'W':'B');

			si += di[d];
			sj += dj[d];
			d = (d+dir+4)%4;
		}
		/*cerr << si << ' ' << sj << '\n';
		for (int step=1; step<4; ++step, d = (d+dir+4)%4) {
			si += di[d];
			sj += dj[d];
			cerr << si << ' ' << sj << '\n';
		}*/
	} else {
		go(sz/2, si, sj, (d+dir+4)%4, -dir);
		go(sz/2, si + sz/2 * di[d], sj + sz/2 * dj[d], d, dir);
		go(sz/2, si + sz/2 * (di[d]+di[(d+dir+4)%4]), sj + sz/2 * (dj[d]+dj[(d+dir+4)%4]), d, dir);
		go(sz/2, si + sz/2 * (di[d] + 2*di[(d+dir+4)%4]) - (di[d] + di[(d+dir+4)%4]), sj + sz/2 * (dj[d] + 2*dj[(d+dir+4)%4]) - (dj[d] + dj[(d+dir+4)%4]), (d-dir+4)%4, -dir);
	}
}
class grafixDither {
	public:
	vector <string> gray2bwRiemersma(vector <string> grays) {
		G = grays;
		N = G.size();

		error = 0;
		go(N, 0, 0, 2, -1);

		return G;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"yy",
 "AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "BW",  "WB" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, gray2bwRiemersma(Arg0)); }
	void test_case_1() { string Arr0[] = {"bbgg",
 "bggg",
 "ggGG",
 "CGGG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "BBBB",  "BBBB",  "BWBW",  "WBWB" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, gray2bwRiemersma(Arg0)); }
	void test_case_2() { string Arr0[] = {"gggggjjj",
 "ggggjjjj",
 "gggjjjjj",
 "ggjjjjQQ",
 "jjjjQQQR",
 "jjQQQRRR",
 "QQQQRRRR",
 "QQRRRRRR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "BBWBBWBW",  "BBBBBBBB",  "WBBWWBBB",  "BBBBBBWW",  "BBBBWWWW",  "BWWWBWBW",  "WWWBWWBW",  "WBWWWWWW" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, gray2bwRiemersma(Arg0)); }
	void test_case_3() { string Arr0[] = {"aaaaaaaaaaaaaaaa",
 "dddddddddddddddd",
 "gggggggggggggggg",
 "jjjjjjjjjjjjjjjj",
 "nnnnnnnnnnnnnnnn",
 "qqqqqqqqqqqqqqqq",
 "tttttttttttttttt",
 "wwwwwwwwwwwwwwww",
 "AAAAAAAAAAAAAAAA",
 "DDDDDDDDDDDDDDDD",
 "GGGGGGGGGGGGGGGG",
 "JJJJJJJJJJJJJJJJ",
 "NNNNNNNNNNNNNNNN",
 "QQQQQQQQQQQQQQQQ",
 "TTTTTTTTTTTTTTTT",
 "WWWWWWWWWWWWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "BBBBBBBBBBBBBBBB",  "BBBBBBBBBBBBBWBW",  "BBBWWBBWBBBBBWBB",  "BWBBBBBBBWBBBBBB",  "WBBBBBWBBBWWBWWB",  "BBWWWBWBWBBBBBBB",  "BWBBBBBBWBBWWBBW",  "WBWBWWBWBBWBWBBW",  "BWBWWBWWBWBWWBWB",  "WBWBBWBWWBWBBWBW",  "BWWBWBWBBWBWBWWW",  "WBWWWBWWWWBWWWBB",  "WWBWWWBWWBWWWBWW",  "WBWWWBWWWWBWWWBW",  "WWWWWWWWWBWWWBWW",  "WWBWWWBWWWWWWWWW" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, gray2bwRiemersma(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    grafixDither ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
