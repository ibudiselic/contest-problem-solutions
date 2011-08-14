#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool used[10][10];
vector<string> A;
int M, N;

bool valid(int i, int j) {
	if (i<0 || j<0 || i>=M || j>=N) {
		return false;
	}
	return true;
}
void go(int i, int j, int f, int pi=1000, int pj=1000) {
	used[i][j] = 1;
	if (f == 0) {
		return;
	}
	
	assert(A[i][j] != '.');
	if (A[i][j]=='S' || A[i][j]=='+') {
		for (int di=-1; di<2; ++di) {
			for (int dj=-1; dj<2; ++dj) {
				if (abs(di) + abs(dj) == 1) {
					int r = i + di;
					int c = j + dj;
					if (valid(r, c) && A[r][c]!='.') {
						if (A[r][c]=='+' || A[r][c]=='S' || (di!=0 && A[r][c]=='|') || (dj!=0 && A[r][c]=='-')) {
							go(r, c, f-1, di, dj);
						}
					}
				}
			}
		}
	} else {
		int r = i + pi;
		int c = j + pj;
		if (valid(r, c) && A[r][c]!='.') {
			if (A[r][c]=='+' || A[r][c]=='S' || (pi!=0 && A[r][c]=='|') || (pj!=0 && A[r][c]=='-')) {
				go(r, c, f-1, pi, pj);
			}
		}
	}
}

class Trainyard {
	public:
	int reachableSquares(vector <string> layout, int fuel) {
		A = layout;
		M = A.size();
		N = A[0].size();
		memset(used, 0, sizeof used);	

		for (int i=0; i<M; ++i) {
			for (int j=0; j<N; ++j) {
				if (A[i][j] == 'S') {
					go(i, j, fuel);
					goto END;
				}
			}
		}
		END: ;

		int sol = 0;
		for (int i=0; i<M; ++i) {
			for (int j=0; j<N; ++j) {
				cerr << (A[i][j]!='S' ? (used[i][j] ? '1' : '0') : 'S');
				if (used[i][j]) {
					++sol;
				}
			}
			cerr << '\n';
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
".-....",
"-S---.",
"......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, reachableSquares(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {
"..+-+.",
"..|.|.",
"S-+-+."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 10; verify_case(1, Arg2, reachableSquares(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {
"-....-",
"|....+",
"+-S++|",
"|.|..|",
"..+-++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 15; verify_case(2, Arg2, reachableSquares(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {
".|...",
"-+S+|",
".|..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 6; verify_case(3, Arg2, reachableSquares(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Trainyard ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
