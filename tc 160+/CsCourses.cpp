#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

struct Course {
	int ind, tv, pv, ex;
	Course(int a, int b, int c, int d): ind(a), tv(b), pv(c), ex(d) {}
};
struct State {
	int mnth, tv, pv;
	State(int a, int b, int c): mnth(a), tv(b), pv(c) {}
};
bool operator<(const State &a, const State &b) {
	if (a.mnth != b.mnth)
		return a.mnth < b.mnth;
	else if (a.tv != b.tv)
		return a.tv < b.tv;
	else
		return a.pv < b.pv;
}

vector<Course> avail[50][50];
map<State, vector<int> > M;
bool done[50][51][51]; // [time][tv][pv]
int SB;

vector<int> go(int mnth, int tv, int pv) {
	if (tv>=SB && pv>=SB)
		return vector<int> ();

	if (mnth == 50)
		return vector<int> (1, -1);

	if (done[mnth][tv][pv])
		return M[State(mnth, tv, pv)];

	done[mnth][tv][pv] = 1;
	const vector<Course> &v = avail[tv][pv];

	vector<int> &ret = M[State(mnth, tv, pv)];
	ret.push_back(-1);

	for (int i=0; i<(int)v.size(); ++i)
		if (v[i].ex > mnth) {
			vector<int> temp = go(mnth+1, max(tv, v[i].tv), max(pv, v[i].pv));
			if (temp.size()>0 && temp[0]==-1)
				continue;

			temp.insert(temp.begin(), v[i].ind);
			if (ret[0]==-1 || ret.size()>temp.size() || ret.size()==temp.size() && temp<ret)
				ret = temp;
		}

	return ret;
}
class CsCourses {
	public:
	vector <int> getOrder(vector <int> theoreticalValue, vector <int> practicalValue, vector <int> expire, int skillBound) {
		SB = skillBound;

		for (int tv=0; tv<50; ++tv)
			for (int pv=0; pv<50; ++pv) {
				avail[tv][pv].clear();
				for (int i=0; i<(int)theoreticalValue.size(); ++i)
					if (theoreticalValue[i]-1==tv && practicalValue[i]-1<=pv
						||
						theoreticalValue[i]-1<=tv && practicalValue[i]-1==pv)
						avail[tv][pv].push_back(Course(i, theoreticalValue[i], practicalValue[i], expire[i]));
			}

		memset(done, 0, sizeof done);
		M.clear();

		const vector<int> sol = go(0, 0, 0);

		if (sol.size()>0 && sol[0]==-1)
			return vector<int>();
		else
			return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arr4[] = {0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, getOrder(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 5, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arr4[] = {2, 0, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, getOrder(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arr4[] = { }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, getOrder(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arr4[] = {2, 1, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, getOrder(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; int Arr4[] = {0, 1, 2, 3, 4, 5, 6 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, getOrder(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0, 1, 2, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9, 9, 9, 9, 9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arr4[] = {4, 3 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, getOrder(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CsCourses ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
