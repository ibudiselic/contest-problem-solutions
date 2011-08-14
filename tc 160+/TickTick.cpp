#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

typedef unsigned long long ull;
class TickTick {
	public:
	int get_insignificant(const string &s) {
		for (int i=0; i<(int)s.size(); ++i)
			if (s[i] == '.')
				return (int)s.size()-1 - i;
		return -1;
	}
	ull get_number(const string &s, int x) {
		ull ret = 0;
		int i;
		for (i=0; i<(int)s.size() && s[i]!='.'; ++i)
			ret = ret*10 + s[i]-'0';
		assert(i<(int)s.size() && s[i]=='.');
		for (++i; i<(int)s.size(); ++i, --x)
			ret = ret*10 + s[i]-'0';
		assert(x >= 0);
		while (x--)
			ret *= 10;
		return ret;
	}
	int count(vector <string> events) {
		vector<ull> a(events.size()+1);
		int most = -1;
		for (int i=0; i<(int)events.size(); ++i) {
			const int t = get_insignificant(events[i]);
			most = max(most, t);
		}

		assert(most != -1);
		for (int i=0; i<(int)events.size(); ++i)
			a[i+1] = get_number(events[i], most)*10;

		ull one = 1;
		for (int i=0; i<most; ++i)
			one *= 10;

		one *= 10;
		set<ull> sol;
		for (int i=0; i<(int)a.size(); ++i) {
			const ull time = a[i]+1;
			ull t = time - (time/one)*one;
			ull x = 0;
			int tick = 0;
			for (int i=0; i<(int)a.size(); ++i) {
				if (a[i] == t + tick*one) goto kraj;
				if (a[i] < t + tick*one) {
					x |= (1ull<<i);
					continue;
				}
				tick = (a[i]-t)/one+1;
			}
			sol.insert(x);
			kraj: ;
		}
		return sol.size();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".222","00.223","1.221","4.220"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"4.220112","4.221","4.222","4.223"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"123456.1","123456.7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TickTick ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
