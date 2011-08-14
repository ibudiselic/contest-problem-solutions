#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> makeCounts(const vector<int> &dice) {
	vector<int> cnt(7, 0);
	for (int i=0; i<(int)dice.size(); ++i)
		++cnt[dice[i]];

	return cnt;
}
bool isY(const vector<int> &dice) {
	for (int i=1; i<(int)dice.size(); ++i)
		if (dice[i] != dice[0])
			return false;

	return true;
}
bool isLS(const vector<int> &dice) {
	vector<int> cnt = makeCounts(dice);

	bool gotIt = true;
	for (int i=1; i<=5; ++i)
		if (cnt[i] == 0) {
			gotIt = false;
			break;
		}
	if (gotIt)
		return true;

	for (int i=2; i<=6; ++i)
		if (cnt[i] == 0)
			return false;

	return true;
}
bool isSS(const vector<int> &dice) {
	vector<int> cnt = makeCounts(dice);

	bool gotIt = true;
	for (int i=1; i<=4; ++i)
		if (cnt[i] == 0) {
			gotIt = false;
			break;
		}
	if (gotIt)
		return true;

	gotIt = true;
	for (int i=2; i<=5; ++i)
		if (cnt[i] == 0) {
			gotIt = false;
			break;
		}
	if (gotIt)
		return true;

	for (int i=3; i<=6; ++i)
		if (cnt[i] == 0)
			return false;

	return true;
}
bool isFH(const vector<int> &dice) {
	if (isY(dice))
		return true;

	vector<int> cnt = makeCounts(dice);

	for (int i=1; i<=6; ++i)
		for (int j=1; j<=6; ++j)
			if (cnt[i]==3 && cnt[j]==2)
				return true;

	return false;
}
bool (*fun[4])(const vector<int> &);
int order[4];
vector<int> S;
vector<int> D, D2;
vector<int> take;
vector<int> cur;
double val;
int cntOnes;
double curScore;

int eval(const vector<int> &dice) {
	for (int i=0; i<4; ++i)
		if (fun[order[i]](dice))
			return S[order[i]];
	return 0;
}
void go2(int pos) {
	if (pos == (int)cur.size()) {
		val += eval(D2)/(pow(6.0, cntOnes));
		return;
	}

	if (cur[pos]) {
		D2[pos] = D[pos];
		go2(pos+1);
	} else {
		for (D2[pos]=1; D2[pos]<=6; ++D2[pos])
			go2(pos+1);
	}
}

vector<int> make(const vector<int> &v) {
	vector<int> ret;
	for (int i=0; i<5; ++i)
		if (!v[i])
			ret.push_back(i);
	return ret;
}
bool manje(const vector<int> &a, const vector<int> &b) {
	for (int i=0; i<(int)min(a.size(), b.size()); ++i)
		if (a[i] != b[i])
			return a[i] < b[i];

	return a.size() <= b.size();
}

void go(int pos) {
	if (pos == (int)D.size()) {
		if (cntOnes >= 2) {
			val = 0;
			go2(0);
			if (val<curScore-1e-9 || (val>=curScore-1e-9 && val<=curScore+1e-9) && manje(make(cur), make(take))) {
				curScore = val;
				take = cur;
			}
		}
		return;
	}

	++cntOnes;
	cur[pos] = 0;
	go(pos+1);
	--cntOnes;
	cur[pos] = 1;
	go(pos+1);
}
class YahtzeeAdversary {
	public:
	vector <int> reRollDice(vector <int> scores, vector <int> dice) {
		fun[0] = isY; fun[1] = isLS; fun[2] = isSS; fun[3] = isFH;

		for (int i=0; i<4; ++i)
			order[i] = i;

		S = scores;
		for (int i=0; i<3; ++i)
			for (int j=i+1; j<4; ++j)
				if (S[order[i]] < S[order[j]])
					swap(order[i], order[j]);

		D = dice;
		D2.assign(D.size(), 0);
		cur.assign(D.size(), 0);
		curScore = 1234567890;

		cntOnes = 0;
		go(0);

		return make(take);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {50, 40, 30, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, reRollDice(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {50, 40, 30, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, reRollDice(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {50, 40, 30, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 4, 3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, reRollDice(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10000, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, reRollDice(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0, 0, 10000, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2, 3, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, reRollDice(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0, 0, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 3, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, reRollDice(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    YahtzeeAdversary ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
