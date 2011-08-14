#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct tri {
	int y, x1, x2;
};
bool operator<(const tri &a, const tri &b) {
	if (a.y != b.y) return a.y > b.y;
	else if (a.x1 != b.x1) return a.x1 < b.x1;
	else return a.x2 < b.x2;
}
class ObjectFall {
	public:
	int howLong(int x, int y, vector <string> obstacles) {
		vector<tri> o(obstacles.size());
		for (int i=0; i<(int)obstacles.size(); ++i) {
			istringstream is(obstacles[i]);
			is >> o[i].y >> o[i].x1 >> o[i].x2;
		}
		sort(o.begin(), o.end());
		o.push_back((tri) { -100, 0, 0 });
		int sol = 0;
		int t = 0;
		while (y > 0) {
			while (t<(int)o.size() && y<o[t].y) ++t;
			if (y==o[t].y && x>=o[t].x1 && x<=o[t].x2) {
				sol += 5;
				x = o[t].x2;
			}
			--y;
			++sol;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 15; int Arg1 = 10; string Arr2[] = {"005 010 020"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 15; verify_case(0, Arg3, howLong(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 15; int Arg1 = 12; string Arr2[] = {"010 010 020","015 010 020","005 020 050"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 22; verify_case(1, Arg3, howLong(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 85; string Arr2[] = {"020 001 100","010 100 100","005 100 200"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 100; verify_case(2, Arg3, howLong(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 1000; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000; verify_case(3, Arg3, howLong(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 500; int Arg1 = 800; string Arr2[] = {"800 001 500","400 001 499","401 501 999"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 805; verify_case(4, Arg3, howLong(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 645; int Arg1 = 802; string Arr2[] = {"739 038 799","916 169 791","822 372 911","162 125 992","261 307 545",
 "510 031 765","592 723 742","477 315 676","566 143 617","337 114 664",
 "986 648 883","116 230 680","254 746 943","742 948 988","060 117 401",
 "634 035 433","288 741 864","819 626 730","906 071 222","554 100 121",
 "573 051 551","949 528 915","562 151 223","857 135 243","621 115 474",
 "588 405 615","895 812 919","052 378 836","858 116 505","285 428 469",
 "792 244 250","109 265 637","714 804 885","625 150 410","518 593 921",
 "282 235 339","081 212 659","663 047 982","556 194 345","798 150 938",
 "391 026 813","886 348 796","975 007 743","053 854 895","243 561 875"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 817; verify_case(5, Arg3, howLong(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ObjectFall ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
