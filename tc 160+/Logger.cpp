#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

template<class T>
vector<T> tokenize(string s, const string &delim=" ")
{
    vector<T> ret_val;
    string::size_type i=0;
    string::size_type len = delim.length();
    if (delim != " ")
        while ((i=s.find(delim)) != string::npos)
            s.replace(i, len, " ");

    istringstream is(s);
    T val;

    while (is >> val)
        ret_val.push_back(val);
    return ret_val;
}
map<string, int> indexof;
struct Priority {
	string name;
	int val;
	Priority(const string &s, int v=0): name(s), val(v) {}
};
bool operator<=(const Priority &a, const Priority &b) {
	if (a.name!=b.name)
		return indexof[a.name] <= indexof[b.name];
	else
		return a.val <= b.val;
}
string uppercase(const string &s) {
	string ret;
	for (int i=0; i<(int)s.size(); ++i)
		ret += toupper(s[i]);
	return ret;
}
class Logger {
	public:
	vector <string> log(vector <string> messages, vector <string> priorities, vector <string> precedence, string loggingPriority) {
		vector<string> sol;

		vector<Priority> p;
		for (int i=0; i<(int)priorities.size(); ++i) {
			vector<string> t = tokenize<string>(priorities[i]);
			p.push_back(Priority(uppercase(t[0]), (t.size()==2 ? atoi(t[1].c_str()) : 0)));
		}
		indexof.clear();
		for (int i=0; i<(int)precedence.size(); ++i)
			indexof[uppercase(precedence[i])] = i;

		vector<string> t = tokenize<string>(loggingPriority);
		Priority log(uppercase(t[0]), (t.size()==2 ? atoi(t[1].c_str()) : 0));

		for (int i=0; i<(int)messages.size(); ++i)
			if (log <= p[i])
				sol.push_back(messages[i]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"in doit()...","n=9","n=13","x=-3","divide by 0",
 "index out of bounds","n=-1","this shouldn't happen","bailing out"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"info 3","debug","debug","debug 3","error","ERROR 5","debug 2","critical","fatal 100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"info","debug","exceptional","error","critical","fatal"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "error 1"; string Arr4[] = { "index out of bounds",  "this shouldn't happen",  "bailing out" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, log(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"in doit()...","n=9","n=13","x=-3","divide by 0",
 "index out of bounds","n=-1","this shouldn't happen","bailing out"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"info 3","debug","debug","debug 3","error","ERROR 5","debug 2","critical","fatal 100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"info","debug","exceptional","error","critical","fatal"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "debug 2"; string Arr4[] = { "x=-3",  "divide by 0",  "index out of bounds",  "n=-1",  "this shouldn't happen",  "bailing out" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, log(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"1","2","3",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A","b","C","d"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a","b","c","D"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "C"; string Arr4[] = { "3",  "" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, log(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Logger ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
