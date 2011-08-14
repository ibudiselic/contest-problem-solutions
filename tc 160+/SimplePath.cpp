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

typedef pair<int, int> point;

struct segment {
	point a, b;
	segment(const point &a_, const point &b_): a(a_), b(b_) {}
};

bool between(int a, int b, int c) {
	return min(b, c) <= a && a <= max(b, c);
}

bool test(const segment &s1, const segment &s2) {
	if (s1.a.first==s1.b.first && s2.a.first==s2.b.first)
		return s1.a.first==s2.a.first && (between(max(s1.a.second, s1.b.second), s2.a.second, s2.b.second) || between(max(s2.a.second, s2.b.second), s1.a.second, s1.b.second));
	else if (s1.a.second==s1.b.second && s2.a.second==s2.b.second)
		return s1.a.second==s2.a.second && (between(max(s1.a.first, s1.b.first), s2.a.first, s2.b.first) || between(max(s2.a.first, s2.b.first), s1.a.first, s1.b.first));
	else if (s1.a.first == s1.b.first)
		return between(s1.a.first, s2.a.first, s2.b.first) && between(s2.a.second, s1.a.second, s1.b.second);
	else
		return between(s2.a.first, s1.a.first, s1.b.first) && between(s1.a.second, s2.a.second, s2.b.second);
}

class SimplePath {
	public:
	int trouble(string direction, vector <int> length) {
		vector<segment> v;

		int x=0, y=0, x2=0, y2=0;

		char lastdir = 0;
		int ret = 1234567890;

		for (int i=0; i<(int)direction.size(); ++i) {
			x2 = x;
			y2 = y;
			switch (direction[i]) {
				case 'N': y2 += length[i]; if (lastdir=='S') ret = min(ret, i-1); break;
				case 'S': y2 -= length[i]; if (lastdir=='N') ret = min(ret, i-1); break;
				case 'W': x2 -= length[i]; if (lastdir=='E') ret = min(ret, i-1); break;
				case 'E': x2 += length[i]; if (lastdir=='W') ret = min(ret, i-1); break;
				default: assert(0); break;
			}
			lastdir = direction[i];
			v.push_back(segment(point(x, y), point(x2, y2)));
			x = x2;
			y = y2;
		}


		for (int i=0; i<ret && i<(int)direction.size(); ++i)
			for (int j=i+2; j<(int)direction.size(); ++j)
				if (test(v[i], v[j]))
					return i;

		return ret==1234567890 ? -1 : ret;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "NWSEEN"; int Arr1[] = {5,5,3,2,5,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, trouble(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "NWWS"; int Arr1[] = {10,3,7,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, trouble(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "NWES"; int Arr1[] = {2,2,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, trouble(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "NWSE"; int Arr1[] = {100,100,100,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, trouble(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "EEEEEW"; int Arr1[] = {1,1,1,1,1,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, trouble(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SimplePath ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
