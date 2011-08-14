#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

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

string norm(string s) {
    if (s == "/") {
        return s;
    }
    while (s[s.size()-1] == '/') {
        s = s.substr(0, s.size()-1);
    }
    return s;
}
class RelativePath {
	public:
	string makeRelative(string path, string cur) {
		if (cur == "/") {
            return path.substr(1);
        }
        vector<string> c = cutUp(cur, "/");
        vector<string> p = cutUp(path, "/");
        string sol;
        string rem;
        while (c.size() > p.size()) {
            sol += "../";
            c.pop_back();
        }
        if (c == vector<string>(p.begin(), p.begin()+c.size())) {
            for (int i=(int)c.size(); i<(int)p.size(); ++i) {
                sol += p[i] + '/';
            }
            return norm(sol);
        }
        while (p.size() > c.size()) {
            rem = "/" + p.back() + rem;
            p.pop_back();
        }
        while (c != p) {
            rem = "/" + p.back() + rem;
            p.pop_back();
            sol += "../";
            c.pop_back();
        }
        return norm(norm(sol) + rem);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "/home/top/data/file"; string Arg1 = "/home/user/pictures"; string Arg2 = "../../top/data/file"; verify_case(0, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "/home/user/movies/title"; string Arg1 = "/home/user/pictures"; string Arg2 = "../movies/title"; verify_case(1, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "/file"; string Arg1 = "/"; string Arg2 = "file"; verify_case(2, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "/a/b/a/b/a/b"; string Arg1 = "/a/b/a/a/b/a/b"; string Arg2 = "../../../../b/a/b"; verify_case(3, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "/root/root/root"; string Arg1 = "/root"; string Arg2 = "root/root"; verify_case(4, Arg2, makeRelative(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RelativePath ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
