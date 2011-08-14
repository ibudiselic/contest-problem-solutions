#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <cctype>
#include <map>

using namespace std;

#define ERR 2000000000

map<string, set<int> > m;
class DotNotation {
	public:
	inline bool sgn(int x) {
		return x>0;
	}
	set<int> doit(string s) {
		if (m.count(s))
			return m[s];
		vector<int> l, r;
		vector<int> pos;
		set<int> &sol = m[s];
		for (string::size_type i=0; i<s.size(); ++i)
			if (s[i]!='.' && !isdigit(s[i])) {
				int cntl, cntr;
				cntl = cntr = 0;
				for (string::size_type j=i; j>0 && s[j-1]=='.'; --j)
					++cntl;
				for (string::size_type j=i; j<s.size()-1 && s[j+1]=='.'; ++j)
					++cntr;
				l.push_back(cntl);
				r.push_back(cntr);
				pos.push_back(i);
			}
		if (pos.size() == 0) {
			istringstream is(s);
			int t;
			is >> t;
			sol.insert(t);
			return sol;
		}
		for (vector<int>::size_type i=0; i<pos.size(); ++i) {
			bool ok = true;
			for (vector<int>::size_type j=0; j<i; ++j)
				if (r[j] > l[i]) {
					ok = false;
					break;
				}
			for (vector<int>::size_type j=i+1; ok && j<pos.size(); ++j)
				if (l[j] > r[i]) {
					ok = false;
					break;
				}
			if (!ok) continue;
			set<int> op1 = doit(s.substr(0, pos[i]-l[i]));
			set<int> op2 = doit(s.substr(pos[i]+r[i]+1));
				for (set<int>::const_iterator x=op1.begin(); x!=op1.end(); ++x)
					for (set<int>::const_iterator y=op2.begin(); y!=op2.end(); ++y)
						switch (s[pos[i]]) {
							case '+':
								if (sgn(*x)==sgn(*y)) {
									if (*y>0 && ERR-*y<=*x)
										break;
									if (*y<0 && -ERR-*y>=*x)
										break;
								}
								sol.insert(*x+*y);
								break;
							case '-':
								if (sgn(*x)!=sgn(*y)) {
									if (*y>0 && -ERR+*y>=*x)
										break;
									if (*y<0 && ERR+*y<=*x)
										break;
								}
								sol.insert(*x-*y);
								break;
							case '*':
								if (*x==0 || *y==0)
									sol.insert(0);
								else if (ERR / abs(*x) < abs(*y))
									break;
								else
									sol.insert(*x * *y);
								break;
							case '/':
								if (*y!=0)
									sol.insert(*x / *y);
								break;
							default:
								cerr << "greska";
								break;
						}
		}
		return sol;
	}

	int countAmbiguity(string dotForm) {
		m.clear();
		set<int> a = doit(dotForm);

		return a.size();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "2"; int Arg1 = 1; verify_case(0, Arg1, countAmbiguity(Arg0)); }
	void test_case_1() { string Arg0 = "9+5*3"; int Arg1 = 2; verify_case(1, Arg1, countAmbiguity(Arg0)); }
	void test_case_2() { string Arg0 = "9+5.*3"; int Arg1 = 1; verify_case(2, Arg1, countAmbiguity(Arg0)); }
	void test_case_3() { string Arg0 = "1+2.*.3+4"; int Arg1 = 1; verify_case(3, Arg1, countAmbiguity(Arg0)); }
	void test_case_4() { string Arg0 = "9*8+7*6-5+4*3/2./9"; int Arg1 = 99; verify_case(4, Arg1, countAmbiguity(Arg0)); }
	void test_case_5() { string Arg0 = "1+...2....*.8..+7"; int Arg1 = 0; verify_case(5, Arg1, countAmbiguity(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DotNotation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
