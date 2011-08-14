#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
template<class T> vector<T> tokenize(string s, const string &delim=" ") {
  vector<T> ret;
  string::size_type i=0;
  string::size_type len = delim.length();
  if (delim != " ")
    while ((i=s.find(delim)) != string::npos)
      s.replace(i, len, " ");

  istringstream is(s);
  T val;
  while (is >> val)
    ret.push_back(val);
  return ret;
}

map<string, int> names;

struct Item {
	string name, type;
	vector<string> args;
	Item(const string &n, const string &t, const vector<string> &a): name(n), type(t), args(a) {}
};
vector<Item> a;

class MonomorphicTyper {
	public:
	string type_of(const string &e) {
		string n;
		int i = 0;
		for (i=0; i<(int)e.size() && e[i]!='('; ++i)
			n += e[i];
		if (names.count(n) == 0)
			return "";
		if (i == (int)e.size()) {
			const Item &x = a[names[n]];
			if ((int)x.args.size() == 0)
				return a[names[n]].type;
			else return "";
		}

		assert(e[i] == '(');
		vector<string> t;
		string cur;
		int b = 1;
		for (++i; i<(int)e.size(); ++i) {
			b += (e[i]=='(') - (e[i]==')');
			if (b==1 && e[i]==',') {
				t.push_back(cur);
				cur.clear();
			} else {
				cur += e[i];
			}
		}
		t.push_back(cur.substr(0, cur.size()-1));
		vector<string> arg;
		for (int j=0; j<(int)t.size(); ++j)
			arg.push_back(type_of(t[j]));

		const vector<string> &v = a[names[n]].args;
		return (v==arg ? a[names[n]].type : "");
	}

	string infer(string expression, vector <string> definitions) {
		names.clear();
		a.clear();

		for (int i=0; i<(int)definitions.size(); ++i) {
			vector<string> t = tokenize<string>(definitions[i], ":");
			assert((int)t.size() == 2);
			string n;
			int j = 0;
			for (j=0; j<(int)t[0].size() && t[0][j]!='('; ++j)
				n += t[0][j];
			vector<string> arg;
			if (j < (int)t[0].size()) {
				assert(t[0][j] == '(');
				arg = tokenize<string>(t[0].substr(j+1, (int)t[0].size()-1-j-1), ",");
			}
			a.push_back(Item(n, t[1], arg));
			names[n] = a.size()-1;
		}
		/*for (int i=0; i<(int)a.size(); ++i) {
			cerr << a[i].name << ' ' << a[i].type;
			for (int j=0; j<(int)a[i].args.size(); ++j)
				cerr << ' ' << a[i].args[j];
			cerr << '\n';
		}*/

		return type_of(expression);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "x"; string Arr1[] = {"x:Char"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Char"; verify_case(0, Arg2, infer(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "upper(x)"; string Arr1[] = {"x:Char","upper(Char):Char"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Char"; verify_case(1, Arg2, infer(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ord(upper(letter))"; string Arr1[] = {"ord(Char):Int","upper(Char):Char","letter:Char","Letter:String"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Int"; verify_case(2, Arg2, infer(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "id(id)"; string Arr1[] = {"id(Int):Int"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(3, Arg2, infer(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "f(unknown)"; string Arr1[] = {"f(A):B"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(4, Arg2, infer(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "fst(zero)"; string Arr1[] = {"fst(Int,Int):Int","zero:Int"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(5, Arg2, infer(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "Func(Int,Char,a)"; string Arr1[] = {"Int:Char", "Func(Char,Char,Int):Int", "Char:Char", "a:Int"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Int"; verify_case(6, Arg2, infer(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MonomorphicTyper ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
