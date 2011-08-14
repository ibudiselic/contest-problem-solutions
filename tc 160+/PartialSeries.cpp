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

vector<int> S, A;
vector<int> L;

enum compData {
	EQ, LT, GT
};
char best[16][1<<15][12][3];
char choice[16][1<<15][12][3];
char interVal[16];
char calcInter(int pos) {
	char &ret = interVal[pos];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i=L[pos]+2; i+1<L[pos+1]; ++i)
		if (S[i-1]>S[i] && S[i]<S[i+1] || S[i-1]<S[i] && S[i]>S[i+1])
			++ret;
	return ret;
}
char go(int pos, int mask, int last, compData rel) {
	if (pos == (int)L.size()-1)
		return 0;
	assert(S[L[pos]] == -1);
	char &ret = best[pos][mask][last][rel];
	if (ret != -1)
		return ret;

	ret = 60;
	char intermediate = calcInter(pos);

	for (int i=0; i<(int)A.size(); ++i)
		if (mask & (1<<i)) {
			char cur = intermediate;
			if (rel==LT && last<A[i] || rel==GT && last>A[i])
				++cur;
			int newLast = 11;
			compData newRel = EQ;
			if (L[pos+1] == L[pos]+1) {
				newLast = A[i];
				if (last!=11 && last!=A[i])
					newRel = (A[i]>last ? GT : LT);
			} else {
				if (last != 11)
					if (last>A[i] && A[i]<S[L[pos]+1] || last<A[i] && A[i]>S[L[pos]+1])
						++cur;
				if (L[pos+1] == L[pos]+2) {
					newLast = S[L[pos]+1];
					if (S[L[pos]+1] != A[i])
						newRel = (S[L[pos]+1]>A[i] ? GT : LT);
				} else {
					if (A[i]>S[L[pos]+1] && S[L[pos]+1]<S[L[pos]+2] || A[i]<S[L[pos]+1] && S[L[pos]+1]>S[L[pos]+2])
						++cur;
					newLast = S[L[pos+1]-1];
					if (newLast != S[L[pos+1]-2])
						newRel = (newLast>S[L[pos+1]-2] ? GT : LT);
				}
			}

			cur += go(pos+1, mask^(1<<i), newLast, newRel);
			if (cur < ret) {
				ret = cur;
				choice[pos][mask][last][rel] = i;
			}
		}
	return ret;
}

class PartialSeries {
	public:
	vector <int> getFirst(vector <int> series, vector <int> available) {
		S = series;
		A = available;
		sort(A.begin(), A.end());
		L.clear();
		for (int i=0; i<(int)S.size(); ++i)
			if (S[i] == -1)
				L.push_back(i);
		L.push_back(S.size());

		memset(best, 0xff, sizeof best);
		memset(interVal, 0xff, sizeof interVal);
		memset(choice, 0xff, sizeof choice);

		if (L[0] == 0)
			go(0, (1<<A.size())-1, 11, EQ);
		else if (L[0] == 1)
			go(0, (1<<A.size())-1, S[0], EQ);
		else
			go(0, (1<<A.size())-1, S[L[0]-1], (S[L[0]-1]==S[L[0]-2] ? EQ : (S[L[0]-1]>S[L[0]-2] ? GT : LT)));

		int mask = (1<<A.size())-1;
		for (int pos=0; pos+1<(int)L.size(); ++pos) {
			int last = (L[pos]==0 ? 11 : S[L[pos]-1]);
			compData rel = (L[pos]<2||last==S[L[pos]-2] ? EQ : (last>S[L[pos]-2] ? GT : LT));

			S[L[pos]] = A[choice[pos][mask][last][rel]];
			mask ^= (1<<choice[pos][mask][last][rel]);
		}
		return S;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {-1,-1,-1,-1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getFirst(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,-1,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 10, 4, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getFirst(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,-1,6,2,4,-1,2,7,-1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,4,7,8,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 6, 2, 4, 2, 2, 7, 7, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getFirst(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {8,-1,6,4,-1,-1,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 6, 6, 4, 2, 3, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getFirst(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-1, 5, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 5, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getFirst(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PartialSeries ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
