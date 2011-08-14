#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool dead[50][50][50];
bool alive[50][50][50];
class ThreePhotos {
	public:
	int removeCubes(vector <string> xy, vector <string> xz, vector <string> yz) {
		memset(dead, 0, sizeof dead);
        int n = xy.size();

        for (int t=0; t<2; ++t) {
        for (int x=0; x<n; ++x) {
            for (int y=0; y<n; ++y) {
                if (xy[x][y] == 'N') {
                    for (int z=0; z<n; ++z) {
                        if (alive[x][y][z]) {
                            return -1;
                        }
                        dead[x][y][z] = 1;
                    }
                } else {
                    bool all_dead = true;
                    for (int z=0; z<n; ++z) {
                        if (!dead[x][y][z]) {
                            all_dead = false;
                            break;
                        }
                    }
                    if (all_dead) {
                        return -1;
                    }
                }
            }
            for (int z=0; z<n; ++z) {
                if (xz[x][z] == 'N') {
                    for (int y=0; y<n; ++y) {
                        if (alive[x][y][z]) {
                            return -1;
                        }
                        dead[x][y][z] = 1;
                    }
                } else {
                    bool all_dead = true;
                    for (int y=0; y<n; ++y) {
                        if (!dead[x][y][z]) {
                            all_dead = false;
                            break;
                        }
                    }
                    if (all_dead) {
                        return -1;
                    }
                }
            }
        }

        for (int y=0; y<n; ++y) {
            for (int z=0; z<n; ++z) {
                if (yz[y][z] == 'N') {
                    for (int x=0; x<n; ++x) {
                        if (alive[x][y][z]) {
                            return -1;
                        }
                        dead[x][y][z] = 1;
                    }
                } else {
                    bool all_dead = true;
                    for (int x=0; x<n; ++x) {
                        if (!dead[x][y][z]) {
                            all_dead = false;
                            break;
                        }
                    }
                    if (all_dead) {
                        return -1;
                    }
                }
            }
        }
        }

        int sol = 0;
        for (int x=0; x<n; ++x) {
            for (int y=0; y<n; ++y) {
                for (int z=0; z<n; ++z) {
                    if (dead[x][y][z] && alive[x][y][z]) {
                        return -1;
                    }
                    sol += dead[x][y][z];
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YY","YY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YY","YY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YY","YY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(0, Arg3, removeCubes(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"NNN","NNN","NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN","NNN","NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNN","NNN","NNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 27; verify_case(1, Arg3, removeCubes(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"NNNNN","NNNNN","NNNNN","YYNNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNNN","NNNNN","NNNNN","NNYNY","NNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNYNN","NNNNY","NNNNN","NNNNN","NNNNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 123; verify_case(2, Arg3, removeCubes(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"YY","YY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YY","YY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","YN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, removeCubes(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ThreePhotos ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
