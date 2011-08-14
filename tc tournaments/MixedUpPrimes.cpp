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

/*const string code_ = "+-/*";
class OP_t {
	public:
	OP_t() {}
	OP_t(int n) { reset(n); }

	void reset(int n) { op_num.assign(n, 0); }
	int size() const { return op_num.size(); }
	bool next() {
		int i = (int)op_num.size()-1;
		++op_num.at(i);
		while (i>0 && op_num.at(i)==cnt) {
			op_num.at(i) = 0;
			++op_num.at(--i);
		}
		if (i==0 && op_num.at(0)==cnt) {
			op_num.at(0) = 0;
			return false;
		} else {
			return true;
		}
	}

	char operator[](int i) const { return code_[op_num.at(i)]; }

	private:
	static const int cnt = 4;
	vector<int> op_num;
};
ostream& operator<<(ostream &os, const OP_t &op) {
	for (int i=0; i<op.size(); ++i) {
		if (i) os << ' ';
		os << op[i];
	}

	return os;
}

int mp, Mp;
int N;
vector<int> V;
vector<int> G;
OP_t OP;

bool is_prime(int x) {
	if (x == 2) return true;
	if (x%2 == 0)
		return false;
	for (int d=3; d*d<=x; d+=2)
		if (x%d == 0)
			return false;
	return true;
}
void update(int x) {
	if (x>1 && (x<mp || x>Mp) && is_prime(x)) {
		mp = min(mp, x);
		Mp = max(Mp, x);
	}
}
bool do_op(int &x, char op, int y) {
	switch (op) {
		case '+': x += y; break;
		case '-': x -= y; break;
		case '*': x *= y; break;
		case '/': if (y != 0) x /= y; else return false; break;
		default: x = y; break;
	}
	return true;
}
void calc() {
	int left = 0;
	int i = 0;
	while (i < N) {
		const int g = G[i];
		const char lr_op = (i==0 ? '=' : OP[i-1]);
		int right = V[i];
		++i;
		while (i<N && G[i]==g) {
			const char op = OP[i-1];
			if (!do_op(right, op, V[i++]))
				return;
		}
		if (!do_op(left, lr_op, right))
			return;
	}
	update(left);
}
void go(int x, int start) {
	if (x == N) {
		calc();
		return;
	}
	if (start > x) {
		go(x+1, start);
		return;
	}
	assert(start == x);
	const int max_len = N-x;
	for (int len=0; len<max_len; ++len) {
		G[x+len] = x;
		go(x+1, x+1+len);
	}
}*/
bool is_prime(int x) {
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x%2 == 0)
		return false;
	for (int d=3; d*d<=x; d+=2)
		if (x%d == 0)
			return false;
	return true;
}
vector< set<int> > vals;
bool done[1u<<6];
int n;
void go(unsigned mask) {
	if (done[mask])
		return;

	done[mask] = 1;
	for (unsigned m1=1; m1<(1u<<n); ++m1) {
		if ((m1 & (~mask)) == 0) {
		const unsigned m2 = ~m1 & mask;
		assert((m1|m2) == mask);
		assert((m1&m2) == 0);

		go(m1); go(m2);
		for (set<int>::const_iterator it1=vals[m1].begin(); it1!=vals[m1].end(); ++it1)
			for (set<int>::const_iterator it2=vals[m2].begin(); it2!=vals[m2].end(); ++it2) {
				vals[mask].insert(*it1 + *it2);
				vals[mask].insert(*it1 - *it2);
				vals[mask].insert(*it1 * *it2);
				if (*it2 != 0) vals[mask].insert(*it1 / *it2);
			}
		}
	}
}
class MixedUpPrimes {
	public:
	vector <int> findPrimes(vector <int> values) {
		/*mp = 1234567890;
		Mp = 0;
		V = values;
		N = V.size();
		sort(V.begin(), V.end());
		G.assign(N, 0);
		OP.reset(N-1);

		if (V.size() == 1) {
			update(V[0]);
		} else {
			do {
				do {
					go(0, 0);
				} while (OP.next());
			} while (next_permutation(V.begin(), V.end()));
		}
		if (Mp == 0) {
			return vector<int>();
		} else {
			vector<int> sol(2, 0);
			sol[0] = mp;
			sol[1] = Mp;
			return sol;
		}*/

		n = values.size();
		vals.assign(1u<<n, set<int>());
		memset(done, 0, sizeof done);
		for (int i=0; i<n; ++i) {
			vals[1u<<i].insert(values[i]);
			done[1u<<i] = 1;
		}

		const unsigned all = (1u<<n) - 1;
		go(all);

		int mp = 1234567890;
		int Mp = 0;

		for (set<int>::const_iterator it=vals[all].begin(); it!=vals[all].end(); ++it)
			if (is_prime(*it)) {
				mp = min(mp, *it);
				Mp = max(Mp, *it);
			}

		if (Mp == 0) {
			return vector<int>();
		} else {
			vector<int> sol(2, 0);
			sol[0] = mp;
			sol[1] = Mp;
			return sol;
		}
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findPrimes(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findPrimes(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 719 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findPrimes(Arg0)); }
	void test_case_3() { int Arr0[] = {2,3,5,7,11,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 15017 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findPrimes(Arg0)); }
	void test_case_4() { int Arr0[] = {2,2,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 17 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findPrimes(Arg0)); }
	void test_case_5() { int Arr0[] = {8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, findPrimes(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MixedUpPrimes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
