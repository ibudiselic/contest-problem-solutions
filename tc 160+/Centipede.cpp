#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> PII;

int m, n;
bool valid(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}
class Centipede {
	public:
	vector <string> simulate(vector <string> screen, int time) {
		m = screen.size();
		n = screen[0].size();
		int dir = 1;
		vector<PII> a(10);
		for (int i=0; i<10; ++i)
			a[i] = make_pair(0, 10-i);

		int cyct = 0;
		int leaving = 10;
		for (int t=0; t<time && leaving>0; ++t, ++cyct) {
			if (leaving < 10)
				--leaving;
			for (int i=9; i>0; --i)
				a[i] = a[i-1];
			if (valid(a[0].first, a[0].second+dir) && screen[a[0].first][a[0].second+dir] == '#') {
				dir = -dir;
				if (!valid(a[0].first+1, a[0].second) || screen[a[0].first+1][a[0].second]!='#')
					++a[0].first;
				if (!valid(a[0].first, a[0].second))
					--leaving;
			} else {
				a[0].second += dir;
			}
		}

		if (leaving == 0) {
			dir = 1;
			cyct = time%cyct;
			for (int i=0; i<10; ++i)
				a[i] = make_pair(0, 10-i);

			for (int t=0; t<cyct; ++t) {
				for (int i=9; i>0; --i)
					a[i] = a[i-1];
				if (valid(a[0].first, a[0].second+dir) && screen[a[0].first][a[0].second+dir] == '#') {
					dir = -dir;
					if (!valid(a[0].first+1, a[0].second) || screen[a[0].first+1][a[0].second]!='#')
						++a[0].first;
				} else {
					a[0].second += dir;
				}
			}
		}

		for (int i=0; i<10; ++i)
			if (valid(a[i].first, a[i].second))
				screen[a[i].first][a[i].second] = 'x';

		return screen;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"#                #",
 "# #      #       #",
 "#   #    #   #   #",
 "#           #    #",
 "#   ##         # #",
 "# #      ##      #",
 "#    #           #",
 "#                #"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; string Arr2[] = { "#                #",  "# #      #       #",  "#   #    #xxx#   #",  "#         xx#    #",  "#   ##   xxx   # #",  "# #      ##      #",  "#    #           #",  "#                #" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, simulate(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"#          #",
 "#          #"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; string Arr2[] = { "#          #",  "#xxxx      #" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, simulate(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"#            #",
 "#     #      #",
 "#            #"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; string Arr2[] = { "#xxxxxxxxxx  #",  "#     #      #",  "#            #" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, simulate(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"#                        #",
 "#      #                 #",
 "#                 #      #",
 "#  ##    #               #",
 "#              #    #    #",
 "#     #                  #",
 "#       #          #     #",
 "#          #             #",
 "#              #         #"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 74607; string Arr2[] = { "#                        #",  "#      #                 #",  "#                 #      #",  "#  ##    #               #",  "#              #    #    #",  "#     #xxxxxxx           #",  "#      x#          #     #",  "#     xx   #             #",  "#              #         #" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, simulate(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#                            #",
 "#   #     # # #           # ##",
 "#   #       #                #",
 "#                          # #",
 "#                   #        #",
 "##    #           #        # #",
 "#    #    #   #              #",
 "#  #    #  #          #      #",
 "#     #   #       #          #",
 "#                            #",
 "#     #        #         #   #",
 "#   ###          #        #  #",
 "#           ##             # #",
 "#                     #      #",
 "##           #               #",
 "#     #     #   #     # #    #",
 "#          #  ##   #         #",
 "#                    #       #",
 "#                    #  #    #"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 598273167; string Arr2[] = { "#                            #",  "#   #     # # #           # ##",  "#   #       #                #",  "#                          # #",  "#                   #        #",  "##    #           #        # #",  "#    #    #   #              #",  "#  #    #  #          #      #",  "#     #   #       #          #",  "#                         xxx#",  "#     #        #         #xxx#",  "#   ###          #        # x#",  "#           ##             # #",  "#                     #      #",  "##           #               #",  "#     #     #   #     # #    #",  "#          #  ##   #         #",  "#                    #       #",  "#                    #  #    #" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, simulate(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Centipede ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
