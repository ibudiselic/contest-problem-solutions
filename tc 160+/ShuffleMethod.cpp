#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Cyc {
	vector<int> x;
};
bool operator<(const Cyc &a, const Cyc &b) {
	return a.x.size() < b.x.size();
}
class ShuffleMethod {
	public:
	vector <int> oneTime(vector <int> twoShuffle) {
		vector<Cyc> cycles;
		vector<bool> used(twoShuffle.size(), false);

		for (int i=0; i<(int)twoShuffle.size(); ++i)
			--twoShuffle[i];

		for (int i=0; i<(int)twoShuffle.size(); ++i)
			if (!used[i]) {
				Cyc t_;
				vector<int> &t = t_.x;
				int poc = i;
				int next = twoShuffle[i];
				t.push_back(poc);
				used[i] = true;
				while (next != poc) {
					used[next] = true;
					t.push_back(next);
					next = twoShuffle[next];
				}
				cycles.push_back(t_);
			}
		stable_sort(cycles.begin(), cycles.end());

		vector<Cyc> orig;
		for (int i=0; i<(int)cycles.size(); ++i) {
			if (cycles[i].x.size() == 1)
				orig.push_back(cycles[i]);
			else if (cycles[i].x.size() % 2 == 0) {
				if (i==(int)cycles.size()-1 || cycles[i].x.size()!=cycles[i+1].x.size())
					return vector<int>();
				Cyc t_;
				vector<int> &t = t_.x;
				for (int j=0; j<(int)cycles[i].x.size(); ++j) {
					t.push_back(cycles[i].x[j]);
					t.push_back(cycles[i+1].x[j]);
				}
				++i;
				orig.push_back(t_);
			} else {
				if (i<(int)cycles.size()-1 && cycles[i].x.size()==cycles[i+1].x.size() && cycles[i+1].x[0]<cycles[i].x[cycles[i].x.size()/2+1]) {
					Cyc t_;
					vector<int> &t = t_.x;
					for (int j=0; j<(int)cycles[i].x.size(); ++j) {
						t.push_back(cycles[i].x[j]);
						t.push_back(cycles[i+1].x[j]);
					}
					++i;
					orig.push_back(t_);
				} else {
					Cyc t_;
					vector<int> &t = t_.x;
					t.push_back(cycles[i].x[0]);
					const int mid = cycles[i].x.size()/2;
					for (int j=0; j<mid; ++j) {
						t.push_back(cycles[i].x[1+mid+j]);
						t.push_back(cycles[i].x[1+j]);
					}
					orig.push_back(t_);
				}
			}
		}

		vector<int> sol(twoShuffle.size(), -1);

		for (int i=0; i<(int)orig.size(); ++i) {
			for (int j=0; j<(int)orig[i].x.size()-1; ++j)
				sol[orig[i].x[j]] = orig[i].x[j+1]+1;
			sol[orig[i].x[orig[i].x.size()-1]] = orig[i].x[0]+1;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {3,4,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  3,  4,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, oneTime(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  2,  3,  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, oneTime(Arg0)); }
	void test_case_2() { int Arr0[] = {5,1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3,  4,  5,  1,  2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, oneTime(Arg0)); }
	void test_case_3() { int Arr0[] = {2,4,6,5,1,8,10,9,3,12,11,13,7,15,16,17,14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3,  6,  2,  8,  9,  4,  14,  5,  1,  15,  11,  16,  17,  10,  12,  13,  7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, oneTime(Arg0)); }
	void test_case_4() { int Arr0[] = {2,4,6,5,1,8,10,9,3,12,11,13,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, oneTime(Arg0)); }
	void test_case_5() { int Arr0[] = {10,9,12,8,13,3,4,1,5,11,6,2,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 9,  1,  4,  12,  11,  7,  3,  2,  10,  5,  13,  8,  6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, oneTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ShuffleMethod ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
