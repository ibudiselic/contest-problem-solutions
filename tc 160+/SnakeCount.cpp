#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <set>

using namespace std;
const int di[] = { -1,  0,  1,  0 };
const int dj[] = {  0,  1,  0, -1 };
const int diagi[] = {-1, -1,  1,  1};
const int diagj[] = {-1,  1,  1, -1};
int m, n, cnt;
int used[50][50];
typedef pair<int, int> PII;
inline bool valid(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}
void probaj(const set<PII> &s, const vector<string> &image) {
	for (set<PII>::const_iterator it=s.begin(); it!=s.end(); ++it) {
		const int i=it->first;
		const int j=it->second;
		for (int dir=0; dir<4; ++dir)
			if (valid(i+diagi[dir], j+diagj[dir]) && image[i+diagi[dir]][j+diagj[dir]]=='1' && s.count(make_pair(i+diagi[dir], j+diagj[dir]))==0)
				return;
	}
	++cnt;
	for (set<PII>::const_iterator it=s.begin(); it!=s.end(); ++it) {
		const int i=it->first;
		const int j=it->second;
		used[i][j] = cnt;
	}
}

class SnakeCount {
	public:
	int number(vector <string> image) {
		memset(used, 0, sizeof used);
		m = image.size();
		n = image[0].size();
		cnt = 0;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (!used[i][j] && image[i][j]=='1') {
					int ii = i;
					int jj = j;
					int sz = 0;
					set<PII> snake;
					for(;;) {
						++sz;
						if (sz > 20) break;
						snake.insert(make_pair(ii, jj));
						int t = 0;
						int d = -1;
						for (int dir=0; dir<4; ++dir) if (valid(ii+di[dir], jj+dj[dir]) && image[ii+di[dir]][jj+dj[dir]]=='1' && snake.count(make_pair(ii+di[dir], jj+dj[dir]))==0) { d=dir; ++t; }
						if (t==0 && sz>=3) probaj(snake, image);
						if (t != 1) break;
						ii += di[d];
						jj += dj[d];
					}
				}
		return cnt;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"11111111",
 "00000010",
 "11100000",
 "00010001",
 "10110011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, number(Arg0)); }
	void test_case_1() { string Arr0[] = {"110111",
 "110101",
 "000110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, number(Arg0)); }
	void test_case_2() { string Arr0[] = {"111","101","111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, number(Arg0)); }
	void test_case_3() { string Arr0[] = {
"11111111111111111111111111111111111111111111111111",
"00000000000000000000000000000000000000000000000001",
"11111111111111111111111111111111111111111111111111"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, number(Arg0)); }
	void test_case_4() { string Arr0[] = {
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"00000000000000000000000000000000000000000000000000",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"00000000000000000000000000000000000000000000000000",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"00000000000000000000000000000000000000000000000000",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"00000000000000000000000000000000000000000000000000",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"00000000000000000000000000000000000000000000000000",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"00000000000000000000000000000000000000000000000000",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"00000000000000000000000000000000000000000000000000",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"00000000000000000000000000000000000000000000000000",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"00000000000000000000000000000000000000000000000000",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"00000000000000000000000000000000000000000000000000",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"00000000000000000000000000000000000000000000000000",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"00000000000000000000000000000000000000000000000000",
"11011011011011011011011011011011011011011011011011",
"10010010010010010010010010010010010010010010010001"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 317; verify_case(4, Arg1, number(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SnakeCount ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
