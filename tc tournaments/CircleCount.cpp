#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <map>

using namespace std;

int N;
int mustHaveFinished[26][2];
int mustNotHaveFinished[26][2];
map<int, int> M;
int startTime;

int go(int mask, int timeout) {
	if (mask == 0)
		return 1;
	if (timeout >= 10) {
		if (double(clock()-startTime)/CLOCKS_PER_SEC >= 1.8)
			throw 0;
	}

	if (M.count(mask))
		return M[mask];

	long long ret = 0;
	for (int i=0; i<N; ++i)
		if (mask & (1<<i)) {
			if ((mustHaveFinished[i][0]&mask)==0 && (mustNotHaveFinished[i][0]&mask)==mustNotHaveFinished[i][0]
				||
				(mustHaveFinished[i][1]&mask)==0 && (mustNotHaveFinished[i][1]&mask)==mustNotHaveFinished[i][1]) {
				ret += go(mask ^ (1<<i), timeout-1);
				if (ret > 2000000000)
					throw -1;
			}
		}

	return (M[mask] = ret);
}
class CircleCount {
	public:
	int countOrder(string circle) {
		startTime = clock();

		vector<char> c;
		for (int i=0; i<(int)circle.size(); ++i)
			if (islower(circle[i]))
				c.push_back(circle[i]);

		random_shuffle(c.begin(), c.end());

		string circle_ = circle;
		for (int i=0; i<(int)c.size(); ++i)
			for (int j=0; j<(int)circle.size(); ++j)
				if (circle_[j] == c[i])
					circle[j] = 'a' + i;
				else if (tolower(circle_[j]) == c[i])
					circle[j] = 'A' + i;

		N = (int)c.size();
		memset(mustHaveFinished, 0, sizeof mustHaveFinished);
		memset(mustNotHaveFinished, 0, sizeof mustNotHaveFinished);

		string s = circle+circle+circle;
		for (int i=(int)circle.size(); i<2*(int)circle.size(); ++i)
			if (islower(s[i])) {
				int j = 0;

				j = i-1;
				while (tolower(s[j]) != s[i])
					--j;
				for (int k=j+1; k<i; ++k)
					if (islower(s[k]))
						mustHaveFinished[s[i]-'a'][0] |= (1<<(s[k]-'a'));
					else
						mustNotHaveFinished[s[i]-'a'][0] |= (1<<(s[k]-'A'));

				j = i+1;
				while (tolower(s[j]) != s[i])
					++j;
				for (int k=i+1; k<j; ++k)
					if (islower(s[k]))
						mustHaveFinished[s[i]-'a'][1] |= (1<<(s[k]-'a'));
					else
						mustNotHaveFinished[s[i]-'a'][1] |= (1<<(s[k]-'A'));
			}

		M.clear();
		int sol = 0;

		try {
			sol = go((1<<N)-1, N);
		} catch (int val) {
			return val;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BACacb"; int Arg1 = 3; verify_case(0, Arg1, countOrder(Arg0)); }
	void test_case_1() { string Arg0 = "ABCacb"; int Arg1 = 0; verify_case(1, Arg1, countOrder(Arg0)); }
	void test_case_2() { string Arg0 = "xX"; int Arg1 = 1; verify_case(2, Arg1, countOrder(Arg0)); }
	void test_case_3() { string Arg0 = "ABCabc"; int Arg1 = 2; verify_case(3, Arg1, countOrder(Arg0)); }
	void test_case_4() { string Arg0 = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPp"; int Arg1 = -1; verify_case(4, Arg1, countOrder(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CircleCount ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
