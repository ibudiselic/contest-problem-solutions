#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string str(long long x) {
	ostringstream os;
	os << x;
	return os.str();
}
long long gcd(long long m, long long n) {
	return m==0 ? n : gcd(n%m, m);
}
long long number(const string &s) {
	istringstream is(s);
	long long x;
	is >> x;
	return x;
}
class ArithmeticProgressions {
	public:
	vector <string> maxAptitude(vector <string> numbers) {
		vector<long long> V;
		int n = numbers.size();
		for (int i=0; i<n; ++i)
			V.push_back(number(numbers[i]));
		sort(V.begin(), V.end());

		if (n < 3) {
			vector<string> sol(2, "0");
			sol[1] = "1";
			return sol;
		}

		long long num = 0, denom = 1;
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				for (int k=j+1; k<n; ++k) {
					long long d = gcd(V[j]-V[i], V[k]-V[j]);
					long long cn = 0;
					for (int l=0; l<n; ++l)
						if (abs(V[i]-V[l])%d == 0)
							++cn;
					assert(cn >= 3);
					long long p = (V[i]-V[0])/d;
					long long start = V[i] - p*d;
					long long cd = (V.back()-start)/d + 1;

					if (cn*denom > num*cd) {
						num = cn;
						denom = cd;
					}
				}

		long long d = gcd(num, denom);
		num /= d;
		denom /= d;

		vector<string> sol;
		sol.push_back(str(num));
		sol.push_back(str(denom));
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1", "3", "5", "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3", "4" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, maxAptitude(Arg0)); }
	void test_case_1() { string Arr0[] = {"1", "3", "5", "7", "9", "11", "13", "15", "17", "19"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1", "1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, maxAptitude(Arg0)); }
	void test_case_2() { string Arr0[] = {"1", "999999999999999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0", "1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, maxAptitude(Arg0)); }
	void test_case_3() { string Arr0[] = {"1", "7", "13", "3511", "1053", "10", "5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3", "391" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, maxAptitude(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ArithmeticProgressions ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
