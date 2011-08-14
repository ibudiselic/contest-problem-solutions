#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

const int rot[24][6] = {
{0,1,2,3,4,5},
{0,4,2,5,3,1},
{0,3,2,1,5,4},
{0,5,2,4,1,3},
{1,2,3,0,4,5},
{1,4,3,5,0,2},
{1,0,3,2,5,4},
{1,5,3,4,2,0},
{2,3,0,1,4,5},
{2,4,0,5,1,3},
{2,1,0,3,5,4},
{2,5,0,4,3,1},
{3,0,1,2,4,5},
{3,4,1,5,2,0},
{3,2,1,0,5,4},
{3,5,1,4,0,2},
{4,2,5,0,3,1},
{4,3,5,1,0,2},
{4,0,5,2,1,3},
{4,1,5,3,2,0},
{5,3,4,1,2,0},
{5,2,4,0,1,3},
{5,1,4,3,0,2},
{5,0,4,2,3,1}
};

set<string> S;
class ColoredBricks {
	public:
	int calc(const string &s, const string& t, const int *r) {
		int ret = 0;
		for (int i=0; i<6; ++i)
			ret += (s[i] != t[r[i]]);
		return ret;
	}
	string code(const string &s) {
		string t = s;
		for (int i=1; i<24; ++i) {
			string v(6, ' ');
			for (int j=0; j<6; ++j)
				v[j] = s[rot[i][j]];
			if (v < t)
				t = v;
		}
		return t;
	}
	int minRepaints(vector <string> bricks) {
		int sol = 1000000000;
		S.clear();
		string cur(6, ' ');
		for (int i1=0; i1<7; ++i1) {
			cur[0] = '0'+i1;
			for (int i2=0; i2<7; ++i2) {
				cur[1] = '0'+i2;
				for (int i3=0; i3<7; ++i3) {
					cur[2] = '0'+i3;
					for (int i4=0; i4<7; ++i4) {
						cur[3] = '0'+i4;
						for (int i5=0; i5<7; ++i5) {
							cur[4] = '0'+i5;
							for (int i6=0; i6<7; ++i6) {
								cur[5] = '0'+i6;
								const string s = code(cur);
								if (S.count(s) != 0) continue;
								S.insert(s);
								int x = 0;
								for (int i=0; i<(int)bricks.size(); ++i) {
									int xx = 1000000000;
									for (int j=0; j<24; ++j)
										xx = min(xx, calc(cur, bricks[i], rot[j]));
									x += xx;
								}
								sol = min(sol, x);
							}
						}
					}
				}
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
	void test_case_0() { string Arr0[] = {"012345", "012354"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minRepaints(Arg0)); }
	void test_case_1() { string Arr0[] = {"012345", "301245"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minRepaints(Arg0)); }
	void test_case_2() { string Arr0[] = {"012012", "345345"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, minRepaints(Arg0)); }
	void test_case_3() { string Arr0[] = {"000000", "111111", "222222", "333333"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(3, Arg1, minRepaints(Arg0)); }
	void test_case_4() { string Arr0[] = {"062413", "041246", "043134", "125611"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(4, Arg1, minRepaints(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ColoredBricks ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
