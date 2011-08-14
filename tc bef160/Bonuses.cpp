#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Emp {
	int pts, orig;
	Emp(int pts_, int orig_): pts(pts_), orig(orig_) {}
};
bool operator<(const Emp &a, const Emp &b) {
	if (a.pts!=b.pts)
		return a.pts > b.pts;
	else return false;
}

class Bonuses {
	public:
	vector <int> getDivision(vector <int> points) {
		vector<Emp> a;
		int sum = 0;

		for (int i=0; i<(int)points.size(); ++i) {
			a.push_back(Emp(points[i], i));
			sum += points[i];
		}
		stable_sort(a.begin(), a.end());
		vector<int> sol(points.size(), 0);
		int t = 100;
		for (int i=0; i<(int)a.size(); ++i) {
			sol[a[i].orig] = a[i].pts*100/sum;
			t -= sol[a[i].orig];
		}
		int i=0;
		while (t--) {
			if (i==(int)a.size()) return vector<int>();
			++sol[a[i++].orig];
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 6,  13,  20,  27,  34 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getDivision(Arg0)); }
	void test_case_1() { int Arr0[] = {5,5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 17,  17,  17,  17,  16,  16 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getDivision(Arg0)); }
	void test_case_2() { int Arr0[] = {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,
 255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 8,  6,  4,  2,  8,  5,  5,  3,  1,  4,  5,  4,  6,  3,  5,  4,  1,  8,  1,  6,  3,  8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getDivision(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Bonuses ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
