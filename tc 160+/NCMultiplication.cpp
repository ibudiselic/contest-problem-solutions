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

long long A, B;
int digA[30], digB[30];
vector<int> D;

long long eval(int *v) {
	long long ret = 0;
	for (int i=15; i>=0; --i)
		ret = ret*10 + v[i];

	return ret;
}
bool valid() {
	for (int i=0; i<(int)D.size(); ++i) {
		int t = 0;
		for (int j=0; j<=i; ++j) {
			const int k = i-j;
			t += digA[j]*digB[k];
		}
		if (t != D[i])
			return false;
	}
	for (int i=(int)D.size(); i<30; ++i) {
		int t = 0;
		for (int j=0; j<=i; ++j) {
			const int k = i-j;
			t += digA[j]*digB[k];
		}
		if (t != 0)
			return false;
	}
	return true;
}
void go(int pos) {
	if (pos == (int)D.size()) {
		long long curA = eval(digA);
		long long curB = eval(digB);
		if (curA < curB)
			swap(curA, curB);

		if ((A==-1 || (A-B) > (curA-curB)) && valid()) {
			A = curA;
			B = curB;
			/*for (int i=29; i>=0; --i)
				cerr << digA[i];
			cerr << ' ';
			for (int i=29; i>=0; --i)
				cerr << digB[i];
			cerr << '\n';*/
		}

		return;
	}

	int t = 0;
	for (int i=1; i<pos; ++i)
		t += digA[i]*digB[pos-i];
	if (t > D[pos])
		return;

	t = D[pos] - t;

	int xFactor = digB[0];
	int yFactor = digA[0];

	if (xFactor+yFactor == 0) {
		if (t != 0)
			return;
		for (int i=0; i<10; ++i) {
			digA[pos] = i;
			for (int j=0; j<10; ++j) {
				digB[pos] = j;
				go(pos+1);
			}
		}
	} else if (xFactor == 0) {
		if (t%yFactor!=0 || t/yFactor>=10)
			return;

		digB[pos] = t/yFactor;
		for (digA[pos]=0; digA[pos]<10; ++digA[pos])
			go(pos+1);
	} else if (yFactor == 0) {
		if (t%xFactor!=0 || t/xFactor>=10)
			return;

		digA[pos] = t/xFactor;
		for (digB[pos]=0; digB[pos]<10; ++digB[pos])
			go(pos+1);
	} else {
		for (digA[pos]=0; digA[pos]<10 && digA[pos]*xFactor<=t; ++digA[pos]) {
			const int tt = t-digA[pos]*xFactor;
			if (tt%yFactor==0 && tt/yFactor<10) {
				digB[pos] = tt/yFactor;
				go(pos+1);
			}
		}
	}
}

class NCMultiplication {
	public:
	long long findFactors(vector <int> digits) {
		memset(digA, 0, sizeof digA);
		memset(digB, 0, sizeof digB);

		D = digits;
		reverse(D.begin(), D.end());

		A = B = -1;

		if (D[0] == 0) {
			for (int i=0; i<10; ++i) {
				digA[0] = i;
				for (int j=0; j<10; ++j) {
					digB[0] = j;
					go(1);
				}
			}
		} else {
			for (int i=1; i<=D[0]; ++i)
				if (D[0]%i == 0) {
					digA[0] = i;
					digB[0] = D[0]/i;
					go(1);
				}
		}

		//cerr << A << ' ' << B << '\n';
		return A;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,21,30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 36LL; verify_case(0, Arg1, findFactors(Arg0)); }
	void test_case_1() { int Arr0[] = {15,3,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 512LL; verify_case(1, Arg1, findFactors(Arg0)); }
	void test_case_2() { int Arr0[] = {4,20,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 25LL; verify_case(2, Arg1, findFactors(Arg0)); }
	void test_case_3() { int Arr0[] = {6,61,124,129,90,27}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6773LL; verify_case(3, Arg1, findFactors(Arg0)); }
	void test_case_4() { int Arr0[] = {8,14,22,95,125,120,73,9,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = -1LL; verify_case(4, Arg1, findFactors(Arg0)); }
	void test_case_5() { int Arr0[] = {6, 5, 32, 68, 113, 143, 143, 124, 100, 75, 48, 23, 7, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 65864431LL; verify_case(5, Arg1, findFactors(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NCMultiplication ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
