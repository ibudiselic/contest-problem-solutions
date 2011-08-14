#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Bag {
	int ind;
	vector<Bag> inside;
	Bag(int ind_): ind(ind_) {}
};
int getInd(int x, const vector<Bag> &v) {
	for (int i=0; i<(int)v.size(); ++i)
		if (v[i].ind == x)
			return i;

	return -1;
}
bool startsWith(const string &a, const string &b) {
	if (a.size() < b.size())
		return false;

	for (int i=0; i<(int)b.size(); ++i)
		if (a[i] != b[i])
			return false;

	return true;
}
bool isProper(const Bag &b) {
	for (int i=0; i<(int)b.inside.size(); ++i)
		if (b.ind<b.inside[i].ind || !isProper(b.inside[i]))
			return false;
	return true;
}
bool isProper(const vector<Bag> &v) {
	for (int i=0; i<(int)v.size(); ++i)
		if (!isProper(v[i]))
			return false;

	return true;
}
class BagsQuiz {
	public:
	int checkIfProper(int n, vector <string> actions) {
		vector<Bag> v;
		for (int i=1; i<=n; ++i)
			v.push_back(Bag(i));

		for (int i=0; i<(int)actions.size(); ++i) {
			if (startsWith(actions[i], "PUT")) {
				int x, y;
				sscanf(actions[i].c_str(), "PUT %d INSIDE %d", &x, &y);
				int a = getInd(x, v);
				int b = getInd(y, v);
				if (a==-1 || b==-1)
					return -1;

				v[b].inside.push_back(v[a]);
				v.erase(v.begin()+a);
			} else if (startsWith(actions[i], "SET")) {
				int x;
				sscanf(actions[i].c_str(), "SET %d LOOSE", &x);
				int a = getInd(x, v);
				if (a == -1)
					return -1;

				while (v[a].inside.size() > 0) {
					v.push_back(v[a].inside.back());
					v[a].inside.pop_back();
				}
			} else {
				int x, y;
				sscanf(actions[i].c_str(), "SWAP %d WITH %d", &x, &y);
				int a = getInd(x, v);
				int b = getInd(y, v);
				if (a==-1 || b==-1)
					return -1;

				swap(v[a].inside, v[b].inside);
			}
		}

		return isProper(v) ? (int)v.size() : -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = {"PUT 1 INSIDE 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, checkIfProper(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"PUT 1 INSIDE 2", "SET 2 LOOSE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, checkIfProper(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; string Arr1[] = {"PUT 2 INSIDE 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, checkIfProper(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; string Arr1[] = {"PUT 3 INSIDE 2", "SWAP 4 WITH 2", "PUT 2 INSIDE 4", "SET 1 LOOSE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, checkIfProper(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 3; string Arr1[] = {"PUT 1 INSIDE 2", "PUT 3 INSIDE 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(4, Arg2, checkIfProper(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BagsQuiz ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
