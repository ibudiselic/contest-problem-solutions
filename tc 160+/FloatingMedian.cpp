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
/*int tree[17][1u<<16];
void insert(int x) { for (int i=0; i<17; ++i) { ++tree[i][x]; x /= 2; } }
void erase(int x) { for (int i=0; i<17; ++i) { --tree[i][x]; x /= 2; } }
int kth_element(int k) {
	int x=0, i=16;
	while (i--) { x *= 2; if (k > tree[i][x]) k -= tree[i][x++]; }
	return x;
}*/

int pop_first(multiset<int> &ms) {
	int ret = *ms.begin();
	ms.erase(ms.begin());
	return ret;
}
int pop_last(multiset<int> &ms) {
	multiset<int>::iterator it = ms.end();
	--it;
	int ret = *it;
	ms.erase(it);
	return ret;
}
int get_last(const multiset<int> &ms) {
	multiset<int>::const_iterator it = ms.end();
	--it;
	int ret = *it;
	return ret;
}
class FloatingMedian {
	public:
	long long sumOfMedians(int seed, int mul, int add, int N, int K) {
		/*memset(tree, 0, sizeof tree);*/
		vector<int> t;
		t.push_back(seed);
		for (int i=1; i<N; ++i)
			t.push_back(((long long)t.back()*mul + add) % 65536);

		multiset<int> lo, hi;
		long long sol = 0;

		for (int i=0; i<N; ++i) {
			if ((int)lo.size()==(K+1)/2 && t[i]>=get_last(lo))
				hi.insert(t[i]);
			else
				lo.insert(t[i]);

			if (i >= K)
				if (t[i-K] <= get_last(lo))
					lo.erase(lo.find(t[i-K]));
				else
					hi.erase(hi.find(t[i-K]));

			while ((int)lo.size() > (K+1)/2)
				hi.insert(pop_last(lo));
			while ((int)hi.size() > K/2)
				lo.insert(pop_first(hi));

			if (i >= K-1)
				sol += get_last(lo);
		}
		/*for (int i=0; i<N; ++i) {
			insert(t[i]);
			if (i >= K) erase(t[i-K]);
			if (i >= K-1) sol += kth_element((K+1)/2);
		}*/
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 10; int Arg4 = 3; long long Arg5 = 60LL; verify_case(0, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 0; int Arg2 = 13; int Arg3 = 5; int Arg4 = 2; long long Arg5 = 49LL; verify_case(1, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 4123; int Arg1 = 2341; int Arg2 = 1231; int Arg3 = 7; int Arg4 = 3; long long Arg5 = 102186LL; verify_case(2, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 5621; int Arg2 = 1; int Arg3 = 125000; int Arg4 = 1700; long long Arg5 = 4040137193LL; verify_case(3, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 32321; int Arg1 = 46543; int Arg2 = 32552; int Arg3 = 17; int Arg4 = 17; long long Arg5 = 25569LL; verify_case(4, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FloatingMedian ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
