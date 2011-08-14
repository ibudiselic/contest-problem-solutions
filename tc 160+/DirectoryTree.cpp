#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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
struct Dir {
	string name;
	int subcnt;
	map<string, Dir *> sub;
	Dir(const string &s, int sc=0): name(s), subcnt(sc), sub() {}
};
bool operator<(const Dir &a, const Dir &b) {
	return a.name < b.name;
}
vector<string> sol;
string space;

void ispisi_(const Dir *d, bool vert_line) {
	sol.push_back(space + "+-" + d->name);
	int cnt = 0;
	if (vert_line)
		space += "| ";
	else space += "  ";
	for (map<string, Dir *>::const_iterator it=d->sub.begin(); it!=d->sub.end(); ++it, ++cnt)
		ispisi_(it->second, d->subcnt>1 && cnt<d->subcnt-1);
	space.erase(space.size()-2);
}
void ispisi(const Dir *d) {
	sol.push_back(d->name);
	int cnt = 0;
	for (map<string, Dir *>::const_iterator it=d->sub.begin(); it!=d->sub.end(); ++it, ++cnt)
		ispisi_(it->second, d->subcnt>1 && cnt<d->subcnt-1);
}

void obrisi(Dir *d) {
	for (map<string, Dir *>::iterator it=d->sub.begin(); it!=d->sub.end(); ++it)
		obrisi(it->second);
	delete d;
}
class DirectoryTree {
	public:
	vector <string> display(vector <string> files) {
		sol.clear();
		space = "";
		Dir *root = new Dir("ROOT");

		vector<int> sz(files.size(), 1);
		for (int i=0; i<(int)files.size(); ++i) {
			Dir *d = root;
			vector<string> t = tokenize<string>(files[i].substr(1), "/");
			for (int j=0; j<(int)t.size(); ++j)
				if (d->sub.count(t[j]))
					d = d->sub[t[j]];
				else {
					++d->subcnt;
				  Dir *dd = new Dir(t[j]);
				  d->sub[t[j]] = dd;
				  d = dd;
				}
		}

		ispisi(root);

		obrisi(root);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"/usr/lib/libc", "/usr/bin/find", "/home/schveiguy/bashrc",
 "/usr/bin/bash", "/usr/local/bin/ssh"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ROOT",  "+-home",  "| +-schveiguy",  "|   +-bashrc",  "+-usr",  "  +-bin",  "  | +-bash",  "  | +-find",  "  +-lib",  "  | +-libc",  "  +-local",  "    +-bin",  "      +-ssh" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, display(Arg0)); }
	void test_case_1() { string Arr0[] = {"/dir/dir/file", "/dir/file", "/file",
 "/dir/sharedname/dir", "/dir/dir/sharedname"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ROOT",  "+-dir",  "| +-dir",  "| | +-file",  "| | +-sharedname",  "| +-file",  "| +-sharedname",  "|   +-dir",  "+-file" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, display(Arg0)); }
	void test_case_2() { string Arr0[] = {"/a/a/a/a/a/a/a","/a/b/a/a/a/a/a","/a/a/a/a/b/a/a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ROOT",  "+-a",  "  +-a",  "  | +-a",  "  |   +-a",  "  |     +-a",  "  |     | +-a",  "  |     |   +-a",  "  |     +-b",  "  |       +-a",  "  |         +-a",  "  +-b",  "    +-a",  "      +-a",  "        +-a",  "          +-a",  "            +-a" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, display(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DirectoryTree ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
