#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

pair<int, int> calc(const string &a, const string &p, const string &s) {
    pair<int, int> ret(0, 0);
    int i = 1;
    while (i<=(int)a.size() && i<=(int)p.size()) {
        if (a.substr(0, i) == p.substr((int)p.size()-i)) {
            ret.first = i;
        }
        ++i;
    }
    i = 1;
    while (i<=(int)a.size() && i<=(int)s.size()) {
        if (a.substr((int)a.size()-i) == s.substr(0, i)) {
            ret.second = i;
        }
        ++i;
    }

    return ret;
}

class TemplateMatching {
	public:
	string bestMatch(string text, string prefix, string suffix) {
		int n = text.size();
        int best_score = -1;
        int best_first = -1;
        string sol(51, 'z');
        for (int i=0; i<n; ++i) {
            for (int j=1; i+j<=n; ++j) {
                pair<int, int> score = calc(text.substr(i, j), prefix, suffix);
                if (score.first+score.second>best_score || score.first+score.second==best_score && (score.first>best_first || score.first==best_first && text.substr(i, j)<sol)) {
                    best_score = score.first + score.second;
                    best_first = score.first;
                    sol = text.substr(i, j);
                }
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "something"; string Arg1 = "awesome"; string Arg2 = "ingenious"; string Arg3 = "something"; verify_case(0, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "havka"; string Arg1 = "eto"; string Arg2 = "papstvo"; string Arg3 = "a"; verify_case(1, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "abracadabra"; string Arg1 = "habrahabr"; string Arg2 = "bracket"; string Arg3 = "abrac"; verify_case(2, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "mississippi"; string Arg1 = "promise"; string Arg2 = "piccolo"; string Arg3 = "ippi"; verify_case(3, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "a a a a a a"; string Arg1 = "a a"; string Arg2 = "a"; string Arg3 = "a a"; verify_case(4, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "ab"; string Arg1 = "b"; string Arg2 = "a"; string Arg3 = "b"; verify_case(5, Arg3, bestMatch(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TemplateMatching ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
