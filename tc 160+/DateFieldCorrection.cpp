#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

string months[] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
int days[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

string a = "1234567890";
string b = "qwertyuiop";
string c = "asdfghjkl";
string d = "zxcvbnm";

int ind[256];
vector<vector<int> > G;
void match(char a, char b, int w=1) {
	int x = ind[a];
	int y = ind[b];
	if (x!=-1 && y!=-1) {
		G[x][y] = G[y][x] = w;
	}
}

void nm(const string &s) {
	for (int i=1; i<(int)s.size(); ++i) {
		match(s[i-1], s[i]);
	}
}

bool bet(int a, int b, int c) {
	return b<=a && a<c;
}

void dm(const string &a, const string &b) {
	for (int i=0; i<(int)a.size(); ++i) {
		for (int di=-1; di<1; ++di) {
			int x = i + di;
			if (bet(x, 0, (int)b.size())) {
				match(a[i], b[x]);
			}
		}
	}
}

int dist(const string &a, const string &b) {
	if (a.size() != b.size()) {
		return 123456789;
	}
	int ret = 0;
	for (int i=0; i<(int)a.size(); ++i) {
		ret += G[ind[a[i]]][ind[b[i]]];
	}

	return ret;
}

class DateFieldCorrection {
	public:
	string correctDate(string input) {
		int n = 0;
		memset(ind, 0xff, sizeof ind);
		for (int i=0; i<(int)a.size(); ++i) {
			ind[a[i]] = n++;
		}
		for (int i=0; i<(int)b.size(); ++i) {
			ind[b[i]] = n++;
		}
		for (int i=0; i<(int)c.size(); ++i) {
			ind[c[i]] = n++;
		}
		for (int i=0; i<(int)d.size(); ++i) {
			ind[d[i]] = n++;
		}
		ind[' '] = n++;

		G = vector< vector<int> > (n, vector<int>(n, 12345678));
		for (int i=0; i<n; ++i) {
			G[i][i] = 0;
		}
		
		nm(a);
		nm(b);
		nm(c);
		nm(d);

		
		dm(a, b);
		dm(b, c);
		dm(c, d);
		
		for (int i=1; i<(int)d.size(); ++i) {
			match(d[i], ' ', 3);
		}
		

		for (int k=0; k<n; ++k) {
			for (int i=0; i<n; ++i) {
				for (int j=0; j<n; ++j) {
					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
				}
			}
		}

		for (int i=0; i<(int)input.size(); ++i) {
			input[i] = tolower(input[i]);
		}
		

		string sol;
		int d = 123456789;
		for (int i=0; i<12; ++i) {
			for (int j=1; j<=days[i]; ++j) {
				ostringstream os;
				os << months[i] << ' ' << j;
				const string s = os.str();
				int t = dist(input, s);
				if (t < d) {
					d = t;
					sol = s;
				}
			}
		}
		

		sol[0] = toupper(sol[0]);
		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Novebmer 10"; string Arg1 = "November 10"; verify_case(0, Arg1, correctDate(Arg0)); }
	void test_case_1() { string Arg0 = "September 15"; string Arg1 = "September 15"; verify_case(1, Arg1, correctDate(Arg0)); }
	void test_case_2() { string Arg0 = "Juny 4"; string Arg1 = "June 4"; verify_case(2, Arg1, correctDate(Arg0)); }
	void test_case_3() { string Arg0 = "Juny 31"; string Arg1 = "July 31"; verify_case(3, Arg1, correctDate(Arg0)); }
	void test_case_4() { string Arg0 = "TopCoder"; string Arg1 = "April 24"; verify_case(4, Arg1, correctDate(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DateFieldCorrection ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
