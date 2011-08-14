#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool has_one(const string &s) {
	return s.find('1') != string::npos;
}
long long start_zero(const string &s) {
	int ret = 0;
	for (int i=0; i<(int)s.size(); ++i) {
		ret += (s[i]=='0');
		if (s[i] != '0')
			break;
	}
	return ret;
}
long long end_zero(const string &s) {
	int ret = 0;
	for (int i=(int)s.size()-1; i>=0; --i) {
		ret += (s[i]=='0');
		if (s[i] != '0')
			break;
	}
	return ret;
}
long long index(const string &s, const string &pattern) {
	string::size_type t = s.find(pattern);

	return (t==string::npos ? -1ll : t);
}
long long len(long long x, long long y, long long n) {
	return n*1000000ll*x + n*(n+1)/2*y;
}
class RepeatedPatterns {
	public:
	long long findZeroSegment(string P1, string P2, string zeroCount) {
		long long zc;
		{
			istringstream is(zeroCount);
			is >> zc;
		}

		bool ho1 = has_one(P1);
		bool ho2 = has_one(P2);

		if (!ho1 && !ho2)
			return 0;

		if (ho1 && ho2) {
			if (zc > 100)
				return -1;
			const string pattern(zc, '0');
			long long sol = -1ll;
			sol = index(P1+P1, pattern);
			long long t = index(P1+P2+P1, pattern);
			if (sol==-1ll && t!=-1ll || sol>t+999999ll*P1.size())
				sol = t+999999ll*P1.size();
			t = index(P2+P2, pattern);
			if (sol==-1ll && t!=-1ll || sol>2000000ll*P1.size()+P2.size()+t)
				sol = 2000000ll*P1.size()+P2.size()+t;

			return sol;
		}

		if (!ho1 && ho2) {
			long long sz = start_zero(P2);
			long long ez = end_zero(P2);

			if (zc <= 1000000ll*P1.size()+sz)
				return 0;
			if (zc <= ez+sz+1000000ll*P1.size())
				return 1000000ll*P1.size()+P2.size()-ez;

			return -1;
		}

		long long sol = -1;
		if (zc < 100) {
			const string pattern(zc, '0');
			sol = index(P1+P1, pattern);
			if (sol != -1ll)
				return sol;
		}
		long long ez = end_zero(P1);
		long long sz = start_zero(P1);

		long long end = 10000000000000000ll;

		long long lo = 1;
		long long hi = 1;
		while (len(P1.size(), P2.size(), hi) < end)
			hi *= 2;

		while (lo < hi) {
			long long mid = lo + (hi-lo+1)/2;
			if (len(P1.size(), P2.size(), mid) > end)
				hi = mid-1;
			else
				lo = mid;
		}

		long long need = (zc-ez-sz+P2.size()-1)/P2.size();
		if (need > lo)
			return -1;

		long long index = need*1000000ll*P1.size() + need*(need-1)/2 * P2.size() - ez;
		if (index + zc > end)
			return -1;

		return index;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "111010100001010"; string Arg1 = "010000001000"; string Arg2 = "3"; long long Arg3 = 7LL; verify_case(0, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "1101010010"; string Arg1 = "0001000"; string Arg2 = "3"; long long Arg3 = 9999999LL; verify_case(1, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "1101010010"; string Arg1 = "0001000"; string Arg2 = "5"; long long Arg3 = 20000011LL; verify_case(2, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "10101010"; string Arg1 = "101010101010"; string Arg2 = "9876543219876"; long long Arg3 = -1LL; verify_case(3, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "11111111111111111111111111"; string Arg1 = "0"; string Arg2 = "9876543219876"; long long Arg3 = -1LL; verify_case(4, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RepeatedPatterns ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
