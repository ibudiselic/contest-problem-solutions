#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> G;
bool is1(int i, int j) {
    if (G[i][j] == 'X') {
        return false;
    }

    for (int di=-1; di<2; ++di) {
        for (int dj=-1; dj<2; ++dj) {
            if (abs(di) + abs(dj) > 0) {
                int r = i + di;
                int c = j + dj;
                if (r>=0 && c>=0 && r<(int)G.size() && c<(int)G[0].size() && G[r][c]=='.') {
                    return false;
                }
            }
        }
    }

    return true;
}

bool is2(int i, int j) {
    if (G[i][j] == 'X') {
        return false;
    }
    for (int di=-1; di<2; ++di) {
        for (int dj=-1; dj<2; ++dj) {
            if (abs(di) + abs(dj) == 1) {
                int r = i + di;
                int c = j + dj;
                if (r>=0 && c>=0 && r<(int)G.size() && c<(int)G[0].size() && G[r][c]=='.') {
                    return false;
                }
            }
        }
    }
    for (int di=-1; di<2; ++di) {
        for (int dj=-1; dj<2; ++dj) {
            if (abs(di) + abs(dj) == 2) {
                int r = i + di;
                int c = j + dj;
                if (r>=0 && c>=0 && r<(int)G.size() && c<(int)G[0].size() && G[r][c]=='.') {
                    return true;
                }
            }
        }
    }

    return false;
}

bool is3(int i, int j) {
    if (G[i][j] == 'X') {
        return false;
    }
    for (int di=-1; di<2; ++di) {
        for (int dj=-1; dj<2; ++dj) {
            if (abs(di) + abs(dj) == 2) {
                int r = i + di;
                int c = j + dj;
                if (r>=0 && c>=0 && r<(int)G.size() && c<(int)G[0].size() && G[r][c]=='.') {
                    return false;
                }
            }
        }
    }
    for (int di=-1; di<2; ++di) {
        for (int dj=-1; dj<2; ++dj) {
            if (abs(di) + abs(dj) == 1) {
                int r = i + di;
                int c = j + dj;
                if (r>=0 && c>=0 && r<(int)G.size() && c<(int)G[0].size() && G[r][c]=='.') {
                    return true;
                }
            }
        }
    }

    return false;
}
class HappyCells {
	public:
	vector <int> getHappy(vector <string> grid) {
		vector<int> sol(3, 0);
        G = grid;
        for (int i=0; i<(int)grid.size(); ++i) {
            for (int j=0; j<(int)grid[0].size(); ++j) {
                if (is1(i, j)) {
                    ++sol[0];
                } else if (is2(i, j)) {
                    ++sol[1];
                } else if (is3(i, j)) {
                    ++sol[2];
                }
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"XXX",
"X.X",
"XXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getHappy(Arg0)); }
	void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getHappy(Arg0)); }
	void test_case_2() { string Arr0[] = {
"XXXXXX",
"X.XXXX",
"XXX.XX",
"X..XXX",
"XXXXXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getHappy(Arg0)); }
	void test_case_3() { string Arr0[] = {"..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getHappy(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HappyCells ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
