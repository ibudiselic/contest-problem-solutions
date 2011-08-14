#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

bool is_sorted(const vector<int> &v) {
    for (int i=1; i<(int)v.size(); ++i) {
        if (v[i-1] > v[i]) {
            return false;
        }
    }

    return true;
}

class SortingGame {
	public:
	int fewestMoves(vector <int> board, int k) {
        if (is_sorted(board)) {
            return 0;
        }
        queue< vector<int> > Q;
        set< vector<int> > done;
        done.insert(board);
        Q.push(board);
        int sol = 0;
        int t = 0;

        while (!Q.empty()) {
            if (t == 0) {
                t = Q.size();
                ++sol;
            }
            --t;
            board = Q.front();
            Q.pop();

            for (int i=0; i+k<=board.size(); ++i) {
                vector<int> v = board;
                reverse(v.begin()+i, v.begin()+i+k);
                if (done.count(v)) {
                    continue;
                }
                if (is_sorted(v)) {
                    return sol;
                }
                done.insert(v);
                Q.push(v);
            }
        }

        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(0, Arg2, fewestMoves(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; verify_case(1, Arg2, fewestMoves(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 10; verify_case(2, Arg2, fewestMoves(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3,2,4,1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = -1; verify_case(3, Arg2, fewestMoves(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {7,2,1,6,8,4,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 7; verify_case(4, Arg2, fewestMoves(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SortingGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
