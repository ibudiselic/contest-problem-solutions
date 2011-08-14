#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <set>
#include <utility>

using namespace std;

int cnt(const string &s, char c) {
	return count(s.begin(), s.end(), c);
}
string trim(const string &s) {
	int i = 0;
	while (i<(int)s.size() && s[i]==' ')
		++i;
	int j = (int)s.size()-1;
	while (j>=0 && s[j]==' ')
		--j;

	if (j < 0)
		return "";

	string ret;
	while (i <= j)
		ret += s[i++];

	return ret;
}
bool hasDigit(const string &s) {
	for (int i=0; i<(int)s.size(); ++i)
		if (isdigit(s[i]))
			return true;
	return false;
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
bool gt(const pair<int, int> &a, const vector<int> &b) {
	return a.first*b[1] > a.second*b[0];
}
bool gt(const vector<int> &a, const pair<int, int> &b) {
	return a[0]*b.second > a[1]*b.first;
}
bool test(const set< pair<int, int> > &A, const vector<int> &l, const vector<int> &r) {
	// true if there is an entry strictly between l and r in A
	if (l[0]*r[1] >= l[1]*r[0])
		return false;

	for (set< pair<int, int> >::const_iterator it=A.begin(); it!=A.end(); ++it)
		if (gt(*it, l) && gt(r, *it))
			return true;

	return false;
}
class GradingGridIns {
	public:
	vector <string> score(vector <string> answer, vector <int> lower, vector <int> upper) {
		set< pair<int, int> > A; // all
		for (int i=0; i<10000; ++i)
			A.insert(make_pair(i, 1));

		for (int i=0; i<1000; ++i)
			A.insert(make_pair(i, 1000));

		for (int i=0; i<10; ++i)
			for (int j=0; j<100; ++j) {
				A.insert(make_pair(i*100+j, 100));
				A.insert(make_pair(j*10+i, 10));
				if (j != 0)
					A.insert(make_pair(i, j));
				if (i != 0)
					A.insert(make_pair(j, i));
			}

		for (int i=0; i<(int)answer.size(); ++i)
			answer[i] = trim(answer[i]);

		vector<string> sol;
		for (int i=0; i<(int)answer.size(); ++i) {
			string s = answer[i];
			if (s.size() == 0) {
				sol.push_back("MALFORMED");
				continue;
			}
			int cntPeriod = cnt(s, '.');
			if (cntPeriod > 1) {
				sol.push_back("MALFORMED");
				continue;
			}
			int cntSlash = cnt(s, '/');
			if (cntSlash>1 || cntPeriod>0 && cntSlash>0 || s[s.size()-1]=='/' || s[0]=='/') {
				sol.push_back("MALFORMED");
				continue;
			}
			if (!hasDigit(s)) {
				sol.push_back("MALFORMED");
				continue;
			}
			if (cnt(s, ' ')) {
				sol.push_back("MALFORMED");
				continue;
			}

			if (cntPeriod) {
				if (s[0] == '.')
					s = '0' + s;
				if (s[s.size()-1] == '.')
					s += '0';
				vector<string> t = cutUp(s, ".");
				assert(t.size() == 2);
				int a, b;
				sscanf(t[0].c_str(), "%d", &a);
				sscanf(t[1].c_str(), "%d", &b);

				int pot10 = 1;
				for (int j=0; j<(int)t[1].size(); ++j)
					pot10 *= 10;

				vector<int> x(2, 0);
				x[0] = a*pot10 + b;
				x[1] = pot10;

				if (lower[0]*x[1]<=x[0]*lower[1] && upper[0]*x[1]>=x[0]*upper[1] || !test(A, x, lower) && !test(A, upper, x))
					sol.push_back("CORRECT");
				else
					sol.push_back("INCORRECT");
			} else if (cntSlash) {
				int a, b;
				sscanf(s.c_str(), "%d/%d", &a, &b);
				if (b == 0) {
					sol.push_back("MALFORMED");
					continue;
				}
				vector<int> x(2, 0);
				x[0] = a;
				x[1] = b;
				if (lower[0]*x[1]<=x[0]*lower[1] && upper[0]*x[1]>=x[0]*upper[1] || !test(A, x, lower) && !test(A, upper, x))
					sol.push_back("CORRECT");
				else
					sol.push_back("INCORRECT");
			} else {
				vector<int> x(2, 0);
				sscanf(s.c_str(), "%d", &x[0]);
				x[1] = 1;

				if (lower[0]*x[1]<=x[0]*lower[1] && upper[0]*x[1]>=x[0]*upper[1] || !test(A, x, lower) && !test(A, upper, x))
					sol.push_back("CORRECT");
				else
					sol.push_back("INCORRECT");
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"4/7 "," 4/7","4/07","8/14",".571",".572"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"CORRECT", "CORRECT", "CORRECT", "CORRECT", "CORRECT", "CORRECT" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, score(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {" 4/7","1.01","1.02"," 000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"CORRECT", "CORRECT", "INCORRECT", "CORRECT" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, score(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1.15","1 14","1.14"," 8/7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1142,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1142,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"INCORRECT", "MALFORMED", "CORRECT", "CORRECT" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, score(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"    ","...."," .  ","1 23","8//5","9.4.","85/ ","/123","123/"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"MALFORMED", "MALFORMED", "MALFORMED", "MALFORMED", "MALFORMED", "MALFORMED", "MALFORMED", "MALFORMED", "MALFORMED" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, score(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"1/0 "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9999,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"MALFORMED" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, score(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GradingGridIns ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
