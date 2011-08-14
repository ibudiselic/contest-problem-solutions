#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

bool inside(long long x, int a, int b) {
	return a<=x && x<=b;
}
bool f(long long x1, long long x2, long long y1, long long y2, long long z1, long long z2, const vector<int> &v) {
	/*cerr << x1 << ' ' << y1 << ' ' << z1 << " | " << x2 << ' ' << y2 << ' ' << z2;*/
	for (int i=0; i<(int)v.size()/6; ++i)
		if (inside(x1, v[i*6], v[i*6+3]) && inside(x2, v[i*6], v[i*6+3])
		&&
			inside(y1, v[i*6+1], v[i*6+4]) && inside(y2, v[i*6+1], v[i*6+4])
		&&
			inside(z1, v[i*6+2], v[i*6+5]) && inside(z2, v[i*6+2], v[i*6+5])) {
			/*cerr << " true\n";*/
			return true;
		}
	/*cerr << " false\n";*/
	return false;
}
class CuboidJoin {
	public:
	long long totalVolume(vector <int> cuboids) {
		set<long long> x, y, z;
		int n = cuboids.size()/6;

		for (int i=0; i<2*n; ++i) {
			x.insert(cuboids[i*3]);
			y.insert(cuboids[i*3+1]);
			z.insert(cuboids[i*3+2]);
		}

		vector<long long> X(x.begin(), x.end());
		vector<long long> Y(y.begin(), y.end());
		vector<long long> Z(z.begin(), z.end());

		long long sol = 0;
		/*for (int i=0; i<(int)X.size(); ++i)
			cerr << X[i] << ' ';
		cerr << '\n';
		for (int i=0; i<(int)Y.size(); ++i)
			cerr << Y[i] << ' ' ;
		cerr << '\n';
		for (int i=0; i<(int)Z.size(); ++i)
			cerr << Z[i] << ' ' ;
		cerr << '\n';*/

		for (int i=0; i<(int)X.size()-1; ++i)
			for (int j=0; j<(int)Y.size()-1; ++j)
				for (int k=0; k<(int)Z.size()-1; ++k)
					sol += f(X[i], X[i+1], Y[j], Y[j+1], Z[k], Z[k+1], cuboids)*(X[i+1]-X[i])*(Y[j+1]-Y[j])*(Z[k+1]-Z[k]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,0,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, totalVolume(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,0,1,1,1,1,1,1,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(1, Arg1, totalVolume(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,4,4,4,0,0,0,1,1,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 64LL; verify_case(2, Arg1, totalVolume(Arg0)); }
	void test_case_3() { int Arr0[] = {-5000,-5000,-5000,5000,5000,5000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1000000000000LL; verify_case(3, Arg1, totalVolume(Arg0)); }
	void test_case_4() { int Arr0[] = {0,0,0,1,2,3,5,5,5,6,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(4, Arg1, totalVolume(Arg0)); }
	void test_case_5() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(5, Arg1, totalVolume(Arg0)); }
	void test_case_6() { int Arr0[] = {0,0,0,1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(6, Arg1, totalVolume(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CuboidJoin ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
