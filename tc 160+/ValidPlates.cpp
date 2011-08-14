#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

long long M1[11][11], M2[11][11], M3[11][11], I[11][11];
long long init[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };
long long res[11];

void matMul(long long C_[11][11], long long A_[11][11], long long B_[11][11]) { // C_ = A_*B_
	for (int i=0; i<11; ++i)
		for (int j=0; j<11; ++j) {
			C_[i][j] = 0;
			for (int k=0; k<11; ++k)
				C_[i][j] += A_[i][k] * B_[k][j];
		}
}
void matMul2(long long y[11], long long A[11][11], long long x[11]) { // y^T = A*x^T
	for (int i=0; i<11; ++i) {
		y[i] = 0;
		for (int k=0; k<11; ++k)
			y[i] += A[i][k]*x[k];
	}
}
void fastexp(long long A[11][11], long long n) { // calc A^n in O(log n) time, result in A
	long long B[11][11];
	memcpy(B, I, sizeof B);

	while (n > 0) {
		if (n & 1) {
			matMul(M3, B, A);
			memcpy(B, M3, sizeof B);
		}
		matMul(M3, A, A);
		memcpy(A, M3, sizeof M3);

		n >>= 1;
	}

	memcpy(A, B, sizeof B);
}

long long calc(long long n) { // return the number of legal plates with n or less digits
	memcpy(M2, M1, sizeof M2);
	fastexp(M2, n);
	matMul2(res, M2, init);

	return accumulate(res+1, res+11, 0LL);
}

class ValidPlates {
	public:
	string getPlate(vector <string> profane, int seqno) {
		for (int i=0; i<10; ++i)
			for (int j=0; j<10; ++j)
				M1[i][j] = 1;

		M1[10][0] = 0;
		for (int j=1; j<11; ++j)
			M1[10][j] = 1;

		for (int i=0; i<10; ++i)
			M1[i][10] = 0;

		for (int i=0; i<(int)profane.size(); ++i) {
			istringstream is(profane[i]);
			string w;

			while (is >> w) {
				int r = w[0]-'0';
				int c = w[1]-'0';

				M1[r][c] = 0;
			}
		}

		memset(I, 0, sizeof I); // unit matrix
		for (int i=0; i<11; ++i)
			I[i][i] = 1;

		long long lo = 0;
		long long hi = 1;
		long long last = 0;
		long long t = 0;

		while ((t = calc(hi)) < seqno) {
			if (t == last)
				return "";
			last = t;
			hi *= 2;
		}

		if (last != 0)
			lo = hi/2;

		while (lo < hi) {
			long long mid = lo + (hi-lo)/2;
			if (calc(mid) >= seqno)
				hi = mid;
			else
				lo = mid+1;
		}

		int len = lo+1;

		string sol;
		if (len <= 50) {
			sol.assign(len, ' ');
		} else {
			sol.assign(50, ' ');
			for (int i=47; i<50; ++i)
				sol[i] = '.';
			len = 47;
		}

		int lastDig = 10;
		for (int i=0; i<len; ++i) {
			calc(lo-i);
			if (i == 0)
				seqno -= res[10];
			// res has the result...

			for (int j=(i ? 0 : 1); j<10; ++j)
				if (M1[lastDig][j])
					if (res[j]>=seqno) {
						sol[i] = j+'0';
						lastDig = j;
						break;
					} else {
						seqno -= res[j];
					}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; string Arg2 = "1000"; verify_case(0, Arg2, getPlate(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; string Arg2 = "11"; verify_case(1, Arg2, getPlate(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000000000; string Arg2 = "2277659869"; verify_case(2, Arg2, getPlate(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"00 01 02 03 04 05 06 07 08 09 11 12 13 14 15 16 17",
 "18 19 22 23 24 25 26 27 28 29 33 34 35 36 37 38 39",
 "44 45 46 47 48 49 55 56 57 58 59 66 67 68 69 77 78",
 "79 88 89 99 99 99 99 99"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1023; string Arg2 = ""; verify_case(3, Arg2, getPlate(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"00 01 02 03 04 05 07 08 09",
 "10 11 12 13 14 15 17 18 19",
 "20 21 22 24 25 26 27 28 29",
 "30 31 32 33 34 36 37 38 39",
 "41 43 45 46 48",
 "52 53 54 55 56 58 59",
 "60 61 63 64 66 67 68 69",
 "70 72 73 74 75 76 77 78",
 "80 81 82 83 84 86 87 88 89",
 "90 91 92 94 95 96 97 98"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000000000; string Arg2 = "79999999351623516571657999935799993"; verify_case(4, Arg2, getPlate(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"00 01 02 03 04 05 06 07 08 09",
 "10 11 12 13 14 16 17 19",
 "20 21 22 23 24 25 26 27 28 29",
 "30 31 32 33 34 35 36 38 39",
 "41 42 43 44 45 46 49",
 "50 52 53 54 55 57 58 59",
 "60 61 62 63 64 65 66 67 68 69",
 "70 72 73 74 75 76 77 78 79",
 "80 81 82 83 84 85 86 87 88 89",
 "90 91 92 93 94 95 98 99"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000000000; string Arg2 = "37151515151515151515151515151515151515151515151..."; verify_case(5, Arg2, getPlate(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ValidPlates ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
