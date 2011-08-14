#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct State {
	int pos;
	int t;
	State (int pos_, int t_): pos(pos_), t(t_) {}
};
bool operator<(const State &a, const State &b) {
	if (a.t != b.t)
		return a.t < b.t;
	else return a.pos < b.pos;
}
int gcd(int a, int b) {
	if (b==0) return a;
	else return gcd(b, a%b);
}
int lcm(int a, int b) {
	return a/gcd(a, b) * b;
}
int n;

class Jumper {
	public:
	bool inbounds(int i, int j) {
		return i>=0 && i<n && j>=0 && j<20;
	}
	int minTime(vector <string> pattern, vector <int> speed, string rows) {
		int mod = 5;
		for (int i=0; i<(int)speed.size(); ++i)
			if (speed[i]%5)
				mod = lcm(mod, lcm(5, speed[i]));

		pattern.push_back("#####");
		speed.push_back(0);
		vector<int> r;
		r.push_back(speed.size()-1);
		for (int i=0; i<(int)rows.size(); ++i)
			r.push_back(rows[i]-'0');
		n = (int)r.size();

		queue<State> q;
		q.push(State(0, 0));
		set<State> s;
		s.insert(State(0, 0));

		while (!q.empty()) {
			State t = q.front();
			q.pop();
			int i = t.pos/20;
			int j = t.pos%20;

			for (int di=-1; di<=1; ++di)
				for (int dj=-1; dj<=1; ++dj) {
					if (abs(di)+abs(dj)==2) continue;
					int x = i+di;
					int y = j+dj;
					if (!inbounds(x, y)) continue;
					int pomak = (y - t.t%mod * speed[r[x]])%5;
					if (pomak < 0) pomak += 5;
					if (pattern[r[x]][pomak] != '#') continue;
					if (!inbounds(x, y+speed[r[x]])) continue;
					if (x==n-1) return t.t+2;
					State next = State(x*20+y+speed[r[x]], (t.t+1)%mod);
					if (s.find(next) != s.end()) continue;
					s.insert(next);
					q.push(State(x*20+y+speed[r[x]], t.t+1));
				}
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"###..", "..###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "01"; int Arg3 = 5; verify_case(0, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"###..", "..###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "01"; int Arg3 = 5; verify_case(1, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"....#", "....#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "0111"; int Arg3 = 9; verify_case(2, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"#....", "#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-4,-5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "0111"; int Arg3 = 24; verify_case(3, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"#####","#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "01"; int Arg3 = -1; verify_case(4, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"#####","#####","....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,-1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "01010101010101010102"; int Arg3 = -1; verify_case(5, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"#....", "#....", "#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,-5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "2012"; int Arg3 = 12; verify_case(6, Arg3, minTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Jumper ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
