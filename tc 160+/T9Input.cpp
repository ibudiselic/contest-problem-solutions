#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

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
const char *t9[] = { "2", "2", "2",
										 "3", "3", "3",
										 "4", "4", "4",
										 "5", "5", "5",
										 "6", "6", "6",
										 "7", "7", "7", "7",
										 "8", "8", "8",
										 "9", "9", "9", "9" };
map<string, set<string> > m;

string encode(const string &s) {
	string ret;
	for (int i=0; i<(int)s.size(); ++i)
		ret += t9[s[i]-'a'];

	return ret;
}
string decode(const string &s) {
	string ret = encode(s);
	const set<string> &t = m[ret];
	assert(t.size() > 0);
	int i=0;
	for (set<string>::const_iterator it=t.begin(); it!=t.end(); ++it, ++i) {
		if (*it == s) {
			break;
		}
	}

	assert(i<(int)t.size());
	while (i--) {
		ret += '0';
	}
	return ret;
}

class T9Input {
	public:
	vector <string> getKeypresses(vector <string> messages) {
		m.clear();
		for (int i=0; i<(int)messages.size(); ++i) {
			vector<string> t = tokenize<string>(messages[i]);

			if (t.size()>0)
				for (int j=0; j<(int)t.size(); ++j) {
					string s = encode(t[j]);
					m[s].insert(t[j]);
				}
		}
		vector<string> sol(messages.size());
		for (int i=0; i<(int)messages.size(); ++i) {
			string cur;
			for (int j=0; j<(int)messages[i].size(); ++j) {
				if (messages[i][j] == ' ') {
					if (cur.size() > 0) {
						sol[i] += decode(cur);
						cur.clear();
					}
					sol[i] += '#';
				} else {
					cur += messages[i][j];
				}
			}
			if (cur.size() > 0) {
				sol[i] += decode(cur);
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"the tie", "the tie"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "843#8430",  "843#8430" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getKeypresses(Arg0)); }
	void test_case_1() { string Arr0[] = {" hey joe   ", "   "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "#439#563###",  "###" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getKeypresses(Arg0)); }
	void test_case_2() { string Arr0[] = {"cba cba cba cba cba cba cba cba", "abc acb bac bca cab cba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "22200000#22200000#22200000#22200000#22200000#22200000#22200000#22200000",  "222#2220#22200#222000#2220000#22200000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getKeypresses(Arg0)); }
	void test_case_3() { string Arr0[] = { "the longest case for t nine is probably when",
  "you enter seven two letter sequences from the",
  "same key and then repeat the alphabetically",
  "last case over and over again for the entire",
  "list of messages",
  "",
  "these paragraphs demonstrate how efficient t",
  "nine is since there is only one time where you",
  "must use the zero key"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "843#5664378#2273#367#8#6463#47#77622259#9436",  "968#36837#73836#896#538837#737836237#3766#843",  "7263#539#263#8436#737328#843#25742238422559",  "5278#2273#6837#263#6837#24246#367#843#368473",  "5478#63#63772437",  "",  "843730#7272472747#33666787283#469#333424368#8",  "6463#47#74623#84373#47#6659#663#8463#94373#968",  "6878#873#843#9376#539" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getKeypresses(Arg0)); }
	void test_case_4() { string Arr0[] = {"cca ccc c cccb ccca cccc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "222#2220#2#22220#2222#222200" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getKeypresses(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    T9Input ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
