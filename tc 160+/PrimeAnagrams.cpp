#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Sieve {
	public:
	Sieve(long long maxx) {
		maxx = max(maxx, 32ll);
		v.assign((maxx+32-1)/32, 0); // 0 means is_prime

		mark_nonprime(0);
		mark_nonprime(1);
		for (long long x=2; x<=maxx; ++x)
			if (is_prime(x))
				for (long long y=2*x; y<=maxx; y+=x)
					mark_nonprime(y);
	}
	bool is_prime(long long x) {
		long long cell = x/32;
		int offset = x%32;
		return !((v[cell]>>offset)&1);
	}
	private:
	void mark_prime(long long x) {
		long long cell = x/32;
		int offset = x%32;
		v[cell] &= ~(1<<offset);
	}
	void mark_nonprime(long long x) {
		long long cell = x/32;
		int offset = x%32;
		v[cell] |= (1<<offset);
	}

	vector<int> v;
};
int parseInt(const string &s) {
	int ret = 0;
	for (int i=0; i<(int)s.size(); ++i)
		ret = ret*10 + s[i]-'0';

	return ret;
}

class PrimeAnagrams {
	public:
	vector <int> primes(string anagram) {
		Sieve S(1000000);

		sort(anagram.begin(), anagram.end());

		vector<int> sol;
		int prod = 1234567890;
		vector<int> v(3, -1);
		do {
			if (anagram[0] != '0')
				for (int i=1; i+1<(int)anagram.size(); ++i)
					if (anagram[i] != '0') {
						v[0] = parseInt(anagram.substr(0, i));
						for (int j=i+1; j<(int)anagram.size(); ++j)
							if (anagram[j] != '0') {
								v[1] = parseInt(anagram.substr(i, j-i));
								if (v[0] > v[1])
									continue;

								v[2] = parseInt(anagram.substr(j));
								if (v[1]>v[2] || v[0]*v[1]*v[2] >= prod)
									continue;

								bool ok = true;
								for (int i=0; i<(int)v.size(); ++i)
									if (!S.is_prime(v[i])) {
										ok = false;
										break;
									}
								if (ok) {
									sol = v;
									prod = v[0]*v[1]*v[2];
								}
							}
					}
		} while (next_permutation(anagram.begin(), anagram.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "39151"; int Arr1[] = { 5,  13,  19 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, primes(Arg0)); }
	void test_case_1() { string Arg0 = "921179"; int Arr1[] = { 2,  17,  199 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, primes(Arg0)); }
	void test_case_2() { string Arg0 = "01123"; int Arr1[] = { 2,  3,  101 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, primes(Arg0)); }
	void test_case_3() { string Arg0 = "0707070"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, primes(Arg0)); }
	void test_case_4() { string Arg0 = "222"; int Arr1[] = { 2,  2,  2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, primes(Arg0)); }
	void test_case_5() { string Arg0 = "123"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, primes(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PrimeAnagrams ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
