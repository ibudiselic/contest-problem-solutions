#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (a==0 && b==0)
		return 1;
	if (a < b) {
		int t = a;
		a = b;
		b = t;
	}
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}
template<class T> struct iPoint {
	T x, y;
	iPoint(T xx, T yy): x(xx), y(yy) {}

	iPoint& operator+=(const iPoint &rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	iPoint& operator-=(const iPoint &rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	void norm() {
		const T t = gcd(abs(x), abs(y));
		x /= t;
		y /= t;
	}
};
template<class T> bool operator<(const iPoint<T> &lhs, const iPoint<T> &rhs) {
	if (lhs.x != rhs.x)
		return lhs.x < rhs.x;
	else
		return lhs.y < rhs.y;
}
template<class T> const iPoint<T> operator+(const iPoint<T> &lhs, const iPoint<T> &rhs) {
	iPoint<T> t = lhs;
	t += rhs;
	return t;
}
template<class T> const iPoint<T> operator-(const iPoint<T> &lhs, const iPoint<T> &rhs) {
	iPoint<T> t = lhs;
	t -= rhs;
	return t;
}
template<class T> bool operator!=(const iPoint<T> &lhs, const iPoint<T> &rhs) {
	return lhs.x!=rhs.x || lhs.y!=rhs.y;
}

template<class T> int nhits(const iPoint<T> &p) {
	int ret = 0;
	if (p.x > 0)
		ret += p.x/2000;
	else
		ret += 1+(-p.x)/2000;

	if (p.y > 0)
		ret += p.y/1000;
	else
		ret += 1+(-p.y)/1000;

	return ret;
}

struct Entry {
	iPoint<int> p;
	int cnt;
	Entry(const iPoint<int> &pp, int c): p(pp), cnt(c) {}
};
bool operator<(const Entry &lhs, const Entry &rhs) {
	if (lhs.p != rhs.p)
		return lhs.p < rhs.p;
	else
		return lhs.cnt < rhs.cnt;
}
class NCushion {
	public:
	int numShots(vector <int> cue, vector <int> opponent, int N) {
		vector<Entry> t;

		iPoint<int> white(cue[0], cue[1]);
		vector<iPoint<int> > black;

		for (int i=-1; i<=1; ++i)
			if (i != 0)
				for (int j=-1; j<=1; ++j)
					if (j != 0)
						black.push_back(iPoint<int>(i*opponent[0], j*opponent[1]));


		for (int d1=-N; d1<=N; ++d1)
			for (int d2=-N; d2<=N; ++d2)
				for (int i=0; i<4; ++i) {
					const iPoint<int> cur = black[i]+iPoint<int>(d1*4000, d2*2000);

					int cnt = nhits(cur);
					if (cnt <= N) {
						iPoint<int> tt = white-cur;
						tt.norm();
						t.push_back(Entry(tt, cnt));
					}
				}

		sort(t.begin(), t.end());

		int sol = 0;
		for (int i=0; i<(int)t.size(); ++i)
			if ((i==0 || t[i].p!=t[i-1].p) && t[i].cnt==N)
				++sol;
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1900,900}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 4; verify_case(0, Arg3, numShots(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1900,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 3; verify_case(1, Arg3, numShots(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {500,500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1500,500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 6; verify_case(2, Arg3, numShots(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1222,440}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {276,566}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 445; int Arg3 = 1779; verify_case(3, Arg3, numShots(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {20,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 8; verify_case(4, Arg3, numShots(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NCushion ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
