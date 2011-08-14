#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
struct Stud {
	string name;
	int h;
	Stud(const string &s, int h_): name(s), h(h_) {}
};
bool operator<(const Stud &a, const Stud &b) {
	if (a.h != b.h)
		return a.h < b.h;
	else
		return a.name < b.name;
}
class StudentsOrdering {
	public:
	string findOrder(vector <string> students) {
		vector<Stud> A[2];
		for (int i=0; i<(int)students.size(); ++i) {
			string n, s;
			int h;
			istringstream is(students[i]);
			is >> n >> h >> s;
			A[(s=="boy" ? 0:1)].push_back(Stud(n, h));
		}
		sort(A[0].begin(), A[0].end());
		sort(A[1].begin(), A[1].end());

		if (abs((int)A[0].size()-(int)A[1].size()) > 1)
			return "";

		int start = 0;
		string sol = string(1, char('z'+1));
		string cur;
		int ind[2] = {0};
		int last = 0;
		while (ind[start]<(int)A[start].size()) {
			if (A[start][ind[start]].h >= last) {
				last = A[start][ind[start]].h;
				cur += A[start][ind[start]].name + '-';
				++ind[start];
				start = 1-start;
			} else {
				break;
			}
		}
		if (ind[0]==(int)A[0].size() && ind[1]==(int)A[1].size())
			sol = min(sol, cur);

		ind[0] = ind[1] = 0;
		last = 0;
		cur.clear();
		start = 1;
		while (ind[start]<(int)A[start].size()) {
			if (A[start][ind[start]].h >= last) {
				last = A[start][ind[start]].h;
				cur += A[start][ind[start]].name + '-';
				++ind[start];
				start = 1-start;
			} else {
				break;
			}
		}
		if (ind[0]==(int)A[0].size() && ind[1]==(int)A[1].size())
			sol = min(sol, cur);

		return sol[0]<='z' ? sol.substr(0, sol.size()-1) : "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Alex 180 boy",
 "Josh 181 boy",
 "Mary 158 girl",
 "An 158 girl",
 "Tanya 180 girl",
 "Ted 158 boy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "An-Ted-Mary-Alex-Tanya-Josh"; verify_case(0, Arg1, findOrder(Arg0)); }
	void test_case_1() { string Arr0[] = {"Alex 180 boy",
 "Josh 158 boy",
 "Mary 180 girl",
 "An 158 girl",
 "Mary 180 girl",
 "Ted 158 boy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Josh-An-Ted-Mary-Alex-Mary"; verify_case(1, Arg1, findOrder(Arg0)); }
	void test_case_2() { string Arr0[] = {"Alex 180 boy",
 "Josh 170 boy",
 "An 158 girl",
 "Mary 180 girl",
 "Ted 175 boy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(2, Arg1, findOrder(Arg0)); }
	void test_case_3() { string Arr0[] = {"Mary 175 girl"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Mary"; verify_case(3, Arg1, findOrder(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StudentsOrdering ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
