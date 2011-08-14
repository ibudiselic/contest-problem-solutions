#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> v;
int used[50];
bool can_beat(const string &s, int start) {
	for (int i=(int)v.size()-1; i>=0; --i) {
		if (!used[i]) {
			if (s.size()>v[i].size() && s.substr(0, v[i].size())==v[i]) {
				used[i] = 1;
				bool ret = can_beat(s.substr(v[i].size()), start);
				used[i] = 0;
				if (ret) {
					return true;
				}
			} else if (v[i].size()>s.size() && v[i].substr(0, s.size())==s) {
				if (v[i].substr(s.size(), v[start].size()) > v[start]) {
					return true;
				}
			} else if (s < v[i]) {
				return true;
			} 
		}
	}
	return false;
}

string go() {
	for (int i=(int)v.size()-1; i>=0; --i) {
		if (!used[i]) {
			if (!can_beat(v[i], i)) {
				used[i] = 1;
				return v[i] + go();
			}
		}
	}
	return "";
}

class TheNumbersLord {
	public:
	string create(vector <int> numbers, int n) {
		v.clear();
		int len = 0;
		string best = "";
		for (int i=0; i<(int)numbers.size(); ++i) {
			ostringstream os;
			os << numbers[i];
			v.push_back(os.str());
			if ((int)v.back().size()>len || (int)v.back().size()==len && v.back()>best) {
				len = v.back().size();
				best = v.back();
			}
		}

		while ((int)v.size() < n) {
			v.push_back(best);
		}

		sort(v.begin(), v.end());

		memset(used, 0, sizeof used);

		return go();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,2,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "732"; verify_case(0, Arg2, create(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; string Arg2 = "7774"; verify_case(1, Arg2, create(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 10, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; string Arg2 = "110100100"; verify_case(2, Arg2, create(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; string Arg2 = "444444444"; verify_case(3, Arg2, create(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "211"; verify_case(4, Arg2, create(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheNumbersLord ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
