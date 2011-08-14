#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
template<class T> inline bool get_bit(T x, int index) {
	return (x>>index) & 1;
}
template<class T> inline void set_bit(T &x, int index) {
	const T one = 1;
	x |= (one<<index);
}
template<class T> int bit_diff(T x, T y) {
	const T one = 1;
	int ret = 0;
	for (int i=0; (one<<i) <= x; ++i)
		ret += (get_bit(x, i) && !get_bit(y, i));
	return ret;
}
int get_index(const vector<int> &a, int x) {
	for (int i=0; i<(int)a.size(); ++i)
		if (a[i] == x)
			return i;
	return -1;
}

class ExtraBall {
	public:
	double expectedPayout(vector <int> card, vector <int> balls, vector <string> patterns, vector <int> prizes) {
		vector<unsigned> p(patterns.size(), 0);
		for (int i=0; i<(int)patterns.size(); ++i)
			for (int j=0; j<(int)patterns[i].size(); ++j)
				if (patterns[i][j]=='X')
					set_bit(p[i], j);

		unsigned final = 0;
		for (int i=0; i<(int)balls.size(); ++i) {
			const int t = get_index(card, balls[i]);
			if (t != -1)
				set_bit(final, t);
		}

		vector<bool> win(p.size(), false);
		for (int i=0; i<(int)p.size(); ++i)
			win[i] = ((p[i]&final) == p[i]);

		if ((int)balls.size() == 75) return 0.0;

		double sol = 0.0;
		for (int i=0; i<(int)p.size(); ++i)
			if (!win[i]) {
				const int t = bit_diff(p[i], final);
				sol += (t!=1 ? 0 : (double)t/(75-(int)balls.size())) * prizes[i];
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"XXX"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 138.88888888888889; verify_case(0, Arg4, expectedPayout(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"X.X.X"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.0; verify_case(1, Arg4, expectedPayout(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {29,16,2,35,75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {75,4,16,3,21,44,2,38,11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"X....","X.X.X","XXX..","XXXXX"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,100,300,1000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 6.212121212121213; verify_case(2, Arg4, expectedPayout(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {75}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"X.........",".X........","..X.......","...X......","....X.....","XXXXXXXXXX"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50,40,30,20,10,1000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.027027027027027; verify_case(3, Arg4, expectedPayout(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12,34,45,56,67,1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"X..X","XXXX"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.0; verify_case(4, Arg4, expectedPayout(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ExtraBall ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
