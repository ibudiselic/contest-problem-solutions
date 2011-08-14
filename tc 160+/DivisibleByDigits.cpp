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

vector<int> digs(int x) {
	set<int> S;
	while (x > 0) {
		if (x%10 > 0) {
			S.insert(x%10);
		}
		x /= 10;
	}

	return vector<int>(S.begin(), S.end());
}

bool test(long long x, const vector<int> &D) {
	for (int i=0; i<(int)D.size(); ++i) {
		if (x % D[i]) {
			return false;
		}
	}

	return true;
} 

void inc(string &s) {
	for (int i=0; i<(int)s.size(); ++i) {
		if (s[i]-'0' + 1 < 10) {
			++s[i];
			return;
		} else {
			s[i] = '0';
		}
	}
	s.push_back('0');
}

long long compose(long long x, const string &s) {
	for (int i=(int)s.size()-1; i>=0; --i) {
		x = x*10 + (s[i]-'0');
	}
	
	return x;
}
class DivisibleByDigits {
	public:
	long long getContinuation(int n) {
		long long x = n;
		vector<int> D = digs(n);

		if (test(x, D)) {
			return n;
		}

		string add = "0";
		while (1) {
			long long t = compose(x, add);
			if (test(t, D)) {
				return t;
			}
			inc(add);
		}

		return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 13; long long Arg1 = 132LL; verify_case(0, Arg1, getContinuation(Arg0)); }
	void test_case_1() { int Arg0 = 648; long long Arg1 = 648LL; verify_case(1, Arg1, getContinuation(Arg0)); }
	void test_case_2() { int Arg0 = 566; long long Arg1 = 56610LL; verify_case(2, Arg1, getContinuation(Arg0)); }
	void test_case_3() { int Arg0 = 1000000000; long long Arg1 = 1000000000LL; verify_case(3, Arg1, getContinuation(Arg0)); }
	void test_case_4() { int Arg0 = 987654321; long long Arg1 = 987654321360LL; verify_case(4, Arg1, getContinuation(Arg0)); }
	void test_case_5() { int Arg0 = 83; long long Arg1 = 8304LL; verify_case(5, Arg1, getContinuation(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DivisibleByDigits ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
