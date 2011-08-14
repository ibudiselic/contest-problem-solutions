#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int A[5][5];
bool F[5][5];
bool used[26];
bool allowed[26][5][5];
long long cnt;

vector< vector<int> > dp[7776];
bool done[7776];
void decode(int state, vector<int> &v) {
	for (int i=4; i>=0; --i) {
		v[i] = state%6;
		state /= 6;
	}
}
int encode(const vector<int> &v) {
	int state = 0;
	for (int i=0; i<5; ++i)
		state = state*6 + v[i];

	return state;
}
vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}
vector< vector<int> > go(int x, int state) {
	if (x == 26)
		return vector< vector<int> > (5, vector<int> (5, 0));
	if (done[state])
		return dp[state];

	vector<int> j(5, 0);
	decode(state, j);

	done[state] = 1;
	vector< vector<int> > &ret = dp[state];

	ret = vector< vector<int> > ();

	vector<vector<int> > curBest(5, vector<int> (5, 1000));
	for (int i=0; i<5; ++i)
		if (j[i]<5 && allowed[x][i][j[i]]) {
			++j[i];
			const vector<vector<int> > t = go(x+1, encode(j));
			if (t.size()>0 && t<curBest) {
				curBest = t;
				ret = curBest;
				ret[i][j[i]-1] = x;
			}
			--j[i];
		}

	return ret;
}
class NewMagicSquare {
	public:
	vector <string> completeTheSquare(vector <string> square) {
		memset(used, 0, sizeof used);
		memset(F, 0, sizeof F);
		for (int i=0; i<5; ++i) {
			istringstream is(square[i]);
			for (int j=0; j<5; ++j) {
				string w;
				is >> w;
				if (w[0] == '?')
					continue;
				sscanf(w.c_str(), "%d", &A[i][j]);
				used[A[i][j]] = 1;
				F[i][j] = 1;
			}
		}

		memset(allowed, 0, sizeof allowed);
		for (int i=0; i<5; ++i) {
			int j = 0;
			while (j<5 && !F[i][j])
				++j;
			int lim = (j<5 ? A[i][j] : 26);
			for (int k=0; k<j; ++k)
				for (int x=1; x<lim; ++x)
					allowed[x][i][k] = true;
			for (int k=j+1; k<5; ++k)
				for (int x=lim; x<=25; ++x)
					allowed[x][i][k] = true;
			if (j < 5)
				allowed[A[i][j]][i][j] = true;
		}

		memset(done, 0, sizeof done);
		vector< vector<int> > ret = go(1, 0);

		if (ret.size() == 0)
			return vector<string>();

		vector<string> sol;
		for (int i=0; i<5; ++i) {
			char buff[100];
			sprintf(buff, "%02d %02d %02d %02d %02d", ret[i][0], ret[i][1], ret[i][2], ret[i][3], ret[i][4]);
			sol.push_back(string(buff));
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"?? ?? ?? ?? ??",
 "?? ?? ?? ?? ??",
 "?? ?? ?? ?? ??",
 "?? ?? ?? ?? ??",
 "?? ?? ?? ?? ??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"01 02 03 04 05", "06 07 08 09 10", "11 12 13 14 15", "16 17 18 19 20", "21 22 23 24 25" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, completeTheSquare(Arg0)); }
	void test_case_1() { string Arr0[] = {"?? ?? 20 ?? ??",
 "?? ?? ?? ?? ??",
 "?? ?? ?? 05 ??",
 "?? ?? ?? ?? ??",
 "?? ?? ?? ?? ??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"01 06 20 21 22", "07 08 09 10 11", "02 03 04 05 12", "13 14 15 16 17", "18 19 23 24 25" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, completeTheSquare(Arg0)); }
	void test_case_2() { string Arr0[] = {"?? ?? ?? ?? ??",
 "?? ?? ?? ?? 24",
 "?? ?? ?? ?? ??",
 "?? ?? ?? ?? ??",
 "21 ?? ?? ?? ??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, completeTheSquare(Arg0)); }
	void test_case_3() { string Arr0[] = {"?? ?? 15 ?? ??",
 "02 ?? ?? ?? ??",
 "?? ?? ?? 07 ??",
 "?? ?? 16 ?? ??",
 "?? ?? ?? ?? 21"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"01 03 15 17 18", "02 08 09 10 22", "04 05 06 07 23", "11 12 16 24 25", "13 14 19 20 21" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, completeTheSquare(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NewMagicSquare ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
