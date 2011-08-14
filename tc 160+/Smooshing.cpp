#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <cctype>

using namespace std;

struct Entry {
	string name;
	int freq;
	Entry(const string &s, int f): name(s), freq(f) {}
};
bool operator<(const Entry &a, const Entry &b) {
	return a.freq > b.freq;
}
enum q {
	IDENT, SEARCH, KEYWORD
};

int get_index(const vector<Entry> &a, const string &s) {
	for (int i=0; i<(int)a.size(); ++i)
		if (s == a[i].name)
			return i;
	return -1;
}
class Smooshing {
	public:
	int savings(vector <string> program) {
		vector<Entry> a;
		string cur;
	  enum q state = SEARCH;
		for (int i=0; i<(int)program.size(); ++i) {
	  	for (int j=0; j<(int)program[i].size(); ++j)
	  		if (state == IDENT) {
	  			if (isalpha(program[i][j])) {
	  				cur += program[i][j];
	  			} else {
	  				int k = get_index(a, cur);
	  				if (k == -1) {
	  					a.push_back(Entry(cur, 0));
	  					k = a.size()-1;
	  				}
	  				++a[k].freq;
	  				cur.clear();
	  				state = SEARCH;
	  			}
	  		} else if (state == SEARCH) {
	  			if (isupper(program[i][j])) {
	  				cur += program[i][j];
	  				state = IDENT;
	  			} else if (islower(program[i][j])) {
	  				state = KEYWORD;
	  			}
	  		} else if (state == KEYWORD) {
	  			if (!isalpha(program[i][j])) state = SEARCH;
	  		}
	  	if (state == IDENT) {
	  		int k = get_index(a, cur);
	  		if (k == -1) {
	  			a.push_back(Entry(cur, 0));
	 				k = a.size()-1;
	 			}
	 			++a[k].freq;
	 			cur.clear();
	 		}
	 		state = SEARCH;
	 	}

	  stable_sort(a.begin(), a.end());

	/*for (int i=0; i<(int)a.size(); ++i)
			cerr << a[i].name << ' ' << a[i].freq << '\n';*/

	  set<string> used;
	  int sol = 0;
	  for (int i=0; i<(int)a.size(); ++i) {
	  	string cur(1, a[i].name[0]);
	  	int j=0;
	  	while (used.count(cur) > 0) {
	  		j = j==(int)a[i].name.size()-1 ? 0:j+1;
	  		cur += a[i].name[j];
	  	}
	  	used.insert(cur);
	  	/*cerr << a[i].name << ' ' << a[i].freq << " -> " << cur << '\n';*/
	  	sol += a[i].freq * ((int)a[i].name.size()-(int)cur.size());
	  }
	  return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"MyInt = YrInt; if(MyInt==2*That) MyInt++;",
    "while(MyInt>3){",
    "    MyDouble = MyShort+MyLong;",
    "}",
    "return MyDouble;",
    "end" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; verify_case(0, Arg1, savings(Arg0)); }
	void test_case_1() { string Arr0[] = {"MyInt3 = MyInt","MyIntMyInt"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, savings(Arg0)); }
	void test_case_2() { string Arr0[] = {"C = Cda; CdC=CdCd+2*Cd;"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -2; verify_case(2, Arg1, savings(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Smooshing ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
