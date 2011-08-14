#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <map>
#include <cstdio>

using namespace std;

template<class T>
vector<T> tokenize(string s, const string &delim=" ")
{
    vector<T> ret_val;
    string::size_type i=0;
    string::size_type len = delim.length();
    if (delim != " ")
        while ((i=s.find(delim)) != string::npos)
            s.replace(i, len, " ");

    istringstream is(s);
    T val;

    while (is >> val)
        ret_val.push_back(val);
    return ret_val;
}

vector<vector<bool> > dep;
vector<int> times;
vector<bool> used;
int n;
struct Entry {
	int cur, time_left;
	int mask;
	Entry(int c, int t, int m): cur(c), time_left(t), mask(m) {}
};
bool operator<(const Entry &a, const Entry &b) {
	if (a.cur != b.cur)
		return a.cur < b.cur;
	else if (a.time_left != b.time_left)
		return a.time_left < b.time_left;
	else
		return a.mask < b.mask;
}
map<Entry, int> memo;
int make_mask(const vector<bool> &a) {
	int ret = 0;
	for (int i=0; i<(int)a.size(); ++i)
		if (a[i])
			ret |= (1<<i);
	return ret;
}
int go(int cur, int time_left, int tasks_left) {
	if (tasks_left == 0)
		return time_left;
	int mask = make_mask(used);
	Entry t(cur, time_left, mask);
	if (memo.count(t) != 0)
		return memo[t];
	int &ret = memo[t];

	vector<int> ready;
	for (int i=0; i<n; ++i) {
		if (used[i]) continue;
		bool ok = true;
		for (int j=0; j<n; ++j)
			if ((!used[j] || (cur==j && time_left!=0)) && dep[i][j]) {
				ok = false;
				break;
			}
		if (ok)
			ready.push_back(i);
	}

	ret = 2000;
	for (int i=0; i<(int)ready.size(); ++i) {
		const int index = ready[i];
		assert(!used[index]);
		used[index] = true;
		int t;
		if (times[index] > time_left)
			t = time_left + go(index, times[index]-time_left, tasks_left-1);
		else
			t = times[index] + go(cur, time_left-times[index], tasks_left-1);
		used[index] = false;
		ret <?= t;
	}
	if (cur != -1)
		ret <?= time_left + go(-1, 0, tasks_left);
	return ret;
}
int get_time(const string &s) {
	if (s[1]==':')
		return s[0]-'0';
	else return 10;
}
class Scheduling {
	public:
	int fastest(vector <string> dag) {
		n = (int)dag.size();
		dep.clear();
		times.clear();
		for (int i=0; i<n; ++i) {
			times.push_back(get_time(dag[i]));
			vector<int> t = tokenize<int>(dag[i].substr(dag[i].find(':')+1, string::npos), ",");
			vector<bool> tt(n, false);
			for (int j=0; j<(int)t.size(); ++j)
				tt[t[j]] = true;
			dep.push_back(tt);
		}

		used.assign(n, false);
		memo.clear();

		return go(-1, 0, n);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3:","2:","4:","7:0,1,2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, fastest(Arg0)); }
	void test_case_1() { string Arr0[] = {"9:","8:","6:","4:","7:","7:0,1,2,3,4","3:2,3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(1, Arg1, fastest(Arg0)); }
	void test_case_2() { string Arr0[] = { "10:", "5:", "5:1", "5:1", "5:2,3" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(2, Arg1, fastest(Arg0)); }
	void test_case_3() { string Arr0[] = {"1:","2:","4:","8:","6:","3:","7:","5:","9:","5:","10:","3:"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(3, Arg1, fastest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Scheduling ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
