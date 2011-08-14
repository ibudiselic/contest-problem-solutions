#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int dx[] = { -1, +1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, -1, +1, 0, 0 };
const int dz[] = { 0, 0, 0, 0, -1, +1 };
int a[40][40][40], b[40][40][40];
bool ok(int x, int N) {
	return x>=0 && x<N;
}
bool valid(int x, int y, int z, int N) {
	return ok(x,N)&&ok(y,N)&&ok(z,N);
}
class LightsCube {
	public:
	vector <int> count(int N, vector <string> lights) {
		memset(a, 0xff, sizeof a);
		memset(b, 0xff, sizeof b);
		for (int i=0; i<(int)lights.size(); ++i) {
			istringstream is(lights[i]);
			int x, y, z;
			is >> x >> y >> z;
			a[x][y][z] = b[x][y][z] = i;
		}

		int (*A)[40][40], (*B)[40][40];
		A = a;
		B = b;
		while (1) {
			bool repeat = false;
			for (int i=0; i<N; ++i)
				for (int j=0; j<N; ++j)
					for (int k=0; k<N; ++k)
						if (B[i][j][k] == -1) {
							for (int d=0; d<6; ++d) {
								const int x = i+dx[d];
								const int y = j+dy[d];
								const int z = k+dz[d];
								if (valid(x, y, z, N) && A[x][y][z]!=-1)
									if (B[i][j][k] == -1)
										B[i][j][k] = A[x][y][z];
									else
										B[i][j][k] = min(A[x][y][z], B[i][j][k]);
							}
							if (B[i][j][k] == -1)
								repeat = true;
						}
			memmove(a, b, sizeof a);
			if (!repeat)
				break;
		}

		vector<int> sol(lights.size(), 0);
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				for (int k=0; k<N; ++k)
					++sol[A[i][j][k]];

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = {"0 0 0", "0 0 1", "0 1 0", "0 1 1", "1 0 0", "1 0 1", "1 1 0", "1 1 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 1, 1, 1, 1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"1 1 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {27 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; string Arr1[] = {"0 0 0", "3 3 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {32, 32 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; string Arr1[] = {"0 2 4", "2 0 0", "3 4 4", "4 1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {38, 28, 32, 27 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12; string Arr1[] = {"4 7 6", "8 0 0", "3 2 3", "7 7 2", "7 5 1",
 "10 11 5", "4 9 7", "6 1 0", "10 1 1", "9 7 11",
 "11 3 11", "9 0 3", "10 2 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {264, 18, 303, 236, 105, 124, 216, 44, 53, 146, 126, 80, 13 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 40; string Arr1[] = {"29 13 9", "4 10 34", "11 26 16", "2 33 22", "27 31 14", "36 20 8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {14657, 12834, 12364, 5902, 12678, 5565 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LightsCube ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
