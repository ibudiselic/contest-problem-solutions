#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

class TheSoccerDivTwo {
	public:
	int find(vector <int> points) {
		vector< pair<int, int> > v;
        for (int i=0; i<(int)points.size(); ++i) {
            v.push_back(make_pair(-points[i], i));
        }
        sort(v.begin(), v.end());
        
        if (v[0].second == 0) {
            return 1;
        } else {
            int me = -1;
            for (int i=1; i<(int)v.size(); ++i) {
                if (v[i].second == 0) {
                    me = i;
                    break;
                }
            }
            assert(me != -1);
            int can_win = (int)v.size() - me;
            int j = me-1;
            while (j>=0 && points[0]+3 >= points[v[j].second]+1) {
                --j;
            }
            if (j < 0) {
                return 1;
            }
            int can_draw = me - j - 1;
            if (can_draw & 1) {
                ++j;
                --can_draw;
            }
            
            int must_lose = 0;
            while (j>=0 && points[0]+3 >= points[v[j].second]) {
                --j;
                ++must_lose;
            }
            can_win += max(0, j + 1);
            if (can_win >= must_lose) {
                return max(0, me - can_draw - must_lose) + 1;
            } else {
                return max(0, me - can_draw - can_win - (must_lose-can_win+1)/2) + 1;
            }
        }
        
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 7, 7, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arr0[] = {5, 9, 11, 9, 10, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arr0[] = {2, 1, 3, 7, 6, 5, 3, 4, 2, 6, 5, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheSoccerDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
