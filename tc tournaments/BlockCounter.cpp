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

string W;
struct retVal {
	long long cnt;
	char sw, ew;
	retVal(long long cnt_, char sw_, char ew_): cnt(cnt_), sw(sw_), ew(ew_) {}
};
retVal go(int l, int r) {
	if (W[l] != '(') {
		if (l == r) {
			return retVal(0, W[l], W[r]);
		} else {
			retVal next = go(l+1, r);
			if (next.sw!=W[l] && (next.cnt>0 || next.sw!=next.ew))
				++next.cnt;
			next.sw = W[l];
			return next;
		}
	} else {
		int i = l+3;
		int bc = 0;
		while (bc>0 || W[i]!=')') {
			bc += (W[i]=='(') - (W[i]==')');
			++i;
		}
		int cnt = W[l+1]-'0';
		retVal left = go(l+3, i-1);
		left.cnt *= cnt;
		if (left.cnt == 0) {
			if (left.sw != left.ew)
				left.cnt += 2*cnt - 2;
		} else {
			if (left.sw == left.ew)
				left.cnt += cnt-1;
			else
				left.cnt += 2*(cnt-1);
		}
		if (i == r)
			return left;
		retVal right = go(i+1, r);
		if (left.ew==right.sw && (right.cnt>0 && left.cnt>0 || left.sw!=left.ew && right.ew!=right.sw)) {
			left.cnt += right.cnt+1;
		} else if (left.ew != right.sw) {
			if (left.cnt==0 && right.cnt==0)
				left.cnt += right.cnt + (left.sw!=left.ew) + (right.sw!=right.ew);
			else if (left.cnt>0 && right.cnt>0)
				left.cnt += right.cnt+2;
			else if (left.cnt == 0)
				left.cnt += right.cnt + 1 + (left.sw!=left.ew);
			else if (right.cnt == 0)
				left.cnt += right.cnt + 1 + (right.sw!=right.ew);
		} else {
			left.cnt += right.cnt;
		}
		left.ew = right.ew;
		return left;
	}
}

class BlockCounter {
	public:
	long long countBlocks(string word) {
		W = word;
		retVal t = go(0, W.size()-1);
		if (t.cnt == 0)
			return t.sw != t.ew ? 2 : 1;
		else
			return t.cnt + 2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(2,A(3,AB))"; long long Arg1 = 12LL; verify_case(0, Arg1, countBlocks(Arg0)); }
	void test_case_1() { string Arg0 = "A(1,A)A(5,AAA)"; long long Arg1 = 1LL; verify_case(1, Arg1, countBlocks(Arg0)); }
	void test_case_2() { string Arg0 = "ABA(2,ABA)(3,ABA)"; long long Arg1 = 13LL; verify_case(2, Arg1, countBlocks(Arg0)); }
	void test_case_3() { string Arg0 = "(3,(2,(1,AB)))B"; long long Arg1 = 12LL; verify_case(3, Arg1, countBlocks(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BlockCounter ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
