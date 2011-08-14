#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int B[25][25];
int dist[25*25][25*25];
inline int sqr(int x) { return x*x; }
class HillWalker {
	public:
	int highestPoint(vector <string> A, int D, int time) {
		int m = A.size();
		int n = A[0].size();

		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				B[i][j] = (A[i][j]<='Z' ? A[i][j]-'A' : 26 + A[i][j]-'a');
			}
		}

		int SZ = m*n;
		memset(dist, 0x3f, sizeof dist);
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				int x = i*n + j;
				dist[x][x] = 0;
				for (int di=-1; di<2; ++di) {
					for (int dj=-1; dj<2; ++dj) {
						if (abs(di) + abs(dj) == 1) {
							int r = i + di;
							int c = j + dj;
							if (r<0 || c<0 || r>=m || c>=n) {
								continue;
							}
							int y = r*n + c;
							if (y != x) {
								int d = B[r][c] - B[i][j];
								if (abs(d) > D) {
									continue;
								}
								if (d > 0) {
									dist[x][y] = min(dist[x][y], sqr(d));
								} else {
									dist[x][y] = min(dist[x][y], 1);
								}
							}
						}
					}
				}
			}
		}

		for (int k=0; k<SZ; ++k) {
			for (int i=0; i<SZ; ++i) {
				if (dist[i][k] < 1000000000) {
					for (int j=0; j<SZ; ++j) {
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
		}

		int sol = 0;
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				int x = i*n + j;
				if (dist[0][x] + dist[x][0] <= time) {
					sol = max(sol, B[i][j]);
				}
			}
		}
	
		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AD"
,"JG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 10000; int Arg3 = 9; verify_case(0, Arg3, highestPoint(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"AD"
,"JG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 29; int Arg3 = 6; verify_case(1, Arg3, highestPoint(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"AABCDE"
,"GJIHGF"
,"MKLMNO"
,"STSRQP"
,"YUVWXY"
,"edcbaZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 36; int Arg3 = 30; verify_case(2, Arg3, highestPoint(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"BCDE"
,"AJKF"
,"AIHG"
,"AAAA"
,"AOMK"
,"AQSI"
,"ACEG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 14; int Arg3 = 10; verify_case(3, Arg3, highestPoint(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"BCDE"
,"AJKF"
,"AIHG"
,"AAAA"
,"AOMK"
,"AQSI"
,"ACEG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 57; int Arg3 = 18; verify_case(4, Arg3, highestPoint(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"ABCDEFK"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1000; int Arg3 = 5; verify_case(5, Arg3, highestPoint(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"TRRVUXefk"
,"bSNMOWcff"
,"bRPNNQZip"
,"XSRUTVcfj"
,"WbZQPXZbV"
,"XdYSRWVOP"
,"feedVVcZR"
,"XhfdZZefg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 50; int Arg3 = 28; verify_case(6, Arg3, highestPoint(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HillWalker ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
