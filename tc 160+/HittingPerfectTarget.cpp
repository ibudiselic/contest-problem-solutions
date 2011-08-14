#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

inline int cross(int x1, int y1, int x2, int y2) {
	return x1*y2 - y1*x2;
}
inline int cross(int a, int b, int c, const vector<int> &x, const vector<int> &y) {
	return cross(x[b]-x[a], y[b]-y[a], x[c]-x[a], y[c]-y[a]);
}
bool inside(int x, int y, const vector<int> &o, const vector<int> &X, const vector<int> &Y) {
	for (int i=0; i+1<(int)o.size(); ++i)
		if (cross(x-X[o[i]], y-Y[o[i]], X[o[i+1]]-X[o[i]], Y[o[i+1]]-Y[o[i]]) > 0)
			return false;
	return true;
}

vector<int> get_poly(vector<int> &x, vector<int> &y) {
	vector<int> S1, S2;
	vector< pair<int, int> > P;
	for (int i=0; i<(int)x.size(); ++i)
		P.push_back(make_pair(x[i], y[i]));

	sort(P.begin(), P.end());

	for (int i=0; i<(int)x.size(); ++i) {
		x[i] = P[i].first;
		y[i] = P[i].second;
	}

	for (int i=0; i<(int)P.size(); ++i) {
		while (S1.size()>1 && cross(S1[S1.size()-2], S1.back(), i, x, y)<0)
			S1.pop_back();
		S1.push_back(i);
	}
	for (int i=0; i<(int)P.size(); ++i) {
		while (S2.size()>1 && cross(S2[S2.size()-2], S2.back(), i, x, y)>0)
			S2.pop_back();
		S2.push_back(i);
	}

	copy(S2.rbegin()+1, S2.rend(), back_inserter(S1));
	return S1;
}
class HittingPerfectTarget {
	public:
	double getProbability(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2) {
		vector<int> o1 = get_poly(x1, y1);
		vector<int> o2 = get_poly(x2, y2);

		int cnt = 0;
		for (int x=-100; x<=100; ++x)
			for (int y=-100; y<=100; ++y)
				cnt += (inside(x, y, o1, x1, y1) && inside(x, y, o2, x2, y2));

		return cnt/(201.0*201.0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-100, -100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-100, 100, -100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-100, -100, 100, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-100, 100, -100, 100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 1.0; verify_case(0, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {-99, -98, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-99, 99, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {99, 98, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-99, 99, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.475186257765897E-5; verify_case(1, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0, 0, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-54, -99, -100, -100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-54, 99, 100, -100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.0; verify_case(2, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {-1, 1, -30, 30, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, -1, 30, 30, 50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-2, 2, -60, 60, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-2, -2, 60, 60, 100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.03895943169723522; verify_case(3, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HittingPerfectTarget ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
