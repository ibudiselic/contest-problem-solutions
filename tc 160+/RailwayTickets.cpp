#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void sortedInsert(int x, vector<int> &v) {
	v.push_back(0);
	int n = v.size();

	int i = n-2;
	for (i=n-2; i>=0 && v[i]>x; --i)
		v[i+1] = v[i];

	v[i+1] = x;
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
class RailwayTickets {
	public:
	int minRejects(vector <string> travel, int seats) {
		vector<int> start;
		vector<int> end;

		for (int i=0; i<(int)travel.size(); ++i) {
			vector<string> t = cutUp(travel[i]);

			for (int j=0; j<(int)t.size(); ++j) {
				int a, b;
				sscanf(t[j].c_str(), "%d-%d", &a, &b);
				start.push_back(a);
				end.push_back(b);
			}
		}

		int n = start.size();
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				if (start[i] > start[j]) {
					swap(start[i], start[j]);
					swap(end[i], end[j]);
				}

		vector<int> cur;
		int sol = 0;
		int first = 0;
		for (int i=1; i<=10000; ++i) {
			while (!cur.empty() && cur[0]==i)
				cur.erase(cur.begin());

			for (int j=first; j<n; ++j)
				if (start[j] == i) {
					sortedInsert(end[j], cur);
				} else if (start[j] > i) {
					first = j;
					break;
				}

			while ((int)cur.size() > seats) {
				++sol;
				cur.pop_back();
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1-3 3-5",
 "2-4 4-6",
 "1-2 2-3 3-4 4-5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, minRejects(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1-10000","2-10000","1-9999","2-9999","5000-5001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(1, Arg2, minRejects(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1-2 2-5 2-8 234-236 56-878 6-34",
 "234-776 3242-8000 999-1000 3-14",
 "121-122 435-3455 123-987 77-999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 0; verify_case(2, Arg2, minRejects(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1-2 2-3 3-4 4-5 5-6 6-7 1-3 2-7 1-2 1-4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; verify_case(3, Arg2, minRejects(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RailwayTickets ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
