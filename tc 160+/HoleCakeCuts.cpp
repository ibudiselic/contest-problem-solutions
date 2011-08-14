#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int base = 250;
bool cake[500][500];
int C[500][500];
void bfs(int i, int j, int c) {
    queue< pair<int, int> > Q;
    Q.push(make_pair(i, j));
    while (!Q.empty()) {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        C[i][j] = c;

        for (int di=-1; di<2; ++di) {
            for (int dj=-1; dj<2; ++dj) {
                if (abs(di) + abs(dj) == 1) {
                    const int ii = i + di;
                    const int jj = j + dj;
                    if (ii<0 || jj<0 || ii>=500 || j>=500) {
                        continue;
                    }
                    if (C[ii][jj]==-1 && cake[ii][jj]) {
                        Q.push(make_pair(ii, jj));
                        C[ii][jj] = c;
                    }
                }
            }
        }
    }
}

class HoleCakeCuts {
	public:
	int cutTheCake(int cl, int hl, vector <int> h, vector <int> v) {
		memset(cake, 0, sizeof cake);
        cl *= 2;
        hl *= 2;
        for (int i=-cl; i<=cl; ++i) {
            for (int j=-cl; j<=cl; ++j) {
                cake[base+i][base+j] = 1;
            }
        }
        for (int i=-hl; i<=hl; ++i) {
            for (int j=-hl; j<=hl; ++j) {
                cake[base+i][base+j] = 0;
            }
        }

        for (int i=0; i<(int)h.size(); ++i) {
            int t = h[i]*2;
            for (int j=0; j<500; ++j) {
                cake[base+t][j] = 0;
            }
        }
        for (int i=0; i<(int)v.size(); ++i) {
            int t = v[i]*2;
            for (int j=0; j<500; ++j) {
                cake[j][base+t] = 0;
            }
        }

        memset(C, 0xff, sizeof C);
        int c = 0;
        for (int i=0; i<500; ++i) {
            for (int j=0; j<500; ++j) {
                if (cake[i][j] && C[i][j]==-1) {
                    bfs(i, j, c++);
                }
            }
        }

        return c;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arr2[] = {1, -4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; verify_case(0, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-2, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(1, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-5, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; verify_case(2, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 5; int Arr2[] = {40, -40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {20, 0, -20}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 12; verify_case(3, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HoleCakeCuts ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
