#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef long long i64;

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
template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

/*** real code starts here ***/

class Thesaurus {
    public:
    vector <string> edit(vector <string> entry) {
    	VS sol;
    	bool used[50];
    	bool done;
    	
    	for (int i=0; i<(int)entry.size(); ++i) {
    		VS a = tokenize<string>(entry[i]);
    		sort(a.begin(), a.end());
    		string tmp;
    		for (int j=0; j<(int)a.size(); ++j)
    			tmp += a[j]+' ';
    		sol.push_back(tmp.erase(tmp.size()-1, 1));
    	}
    	entry.clear();
    	entry = sol;
    	sol.clear();
    	sort(entry.begin(), entry.end());
    	do {
    		done = true;
    		memset(used, false, sizeof used);
    		for (int i=0; i<(int)entry.size()-1; ++i) {
    			if (used[i]) continue;
    			VS a = tokenize<string>(entry[i]);
    			for (int j=i+1; j<(int)entry.size(); ++j)
    				if (!used[j]) {
    					int count = 0;
    					bool mrg = false;
    					VS b = tokenize<string>(entry[j]);
    					for (int k=0; k<(int)a.size(); ++k)
    						for (int l=0; l<(int)b.size(); ++l) {
    							if (a[k]==b[l])
    								++count;
    							if (count == 2) {
    								mrg = true;
    								goto doit;
    							}
    						}
    					doit:
    					if (mrg) {
    						done = false;
    						used[i] = used[j] = true;
    						string tmp;
    						VS c;
    						merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
    						tmp += c[0]+' ';
    						for (int k=1; k<(int)c.size(); ++k)
    							if (c[k] != c[k-1])
    								tmp += c[k]+' ';
    						sol.push_back(tmp.erase(tmp.size()-1, 1));
    					}
    				}
    		}
    		for (int i=0; i<(int)entry.size(); ++i)
    			if (!used[i])
    				sol.push_back(entry[i]);
    		entry.clear();
    		entry = sol;
    		sol.clear();
    	} while (!done);
    	sort(entry.begin(), entry.end());
    	
    	return entry;				
    				
        
  }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ape monkey wrench", "wrench twist strain"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ape monkey wrench",  "strain twist wrench" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, edit(Arg0)); }
	void test_case_1() { string Arr0[] = {"ape monkey wrench", "wrench twist strain", "monkey twist frugue"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ape monkey wrench",  "frugue monkey twist",  "strain twist wrench" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, edit(Arg0)); }
	void test_case_2() { string Arr0[] = {"ape monkey wrench", "wrench twist strain", "monkey twist frugue strain"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ape frugue monkey strain twist wrench" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, edit(Arg0)); }
	void test_case_3() { string Arr0[] = {"point run score","point dot","cut run tear score","cut valley","cute pretty"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "cut point run score tear",  "cut valley",  "cute pretty",  "dot point" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, edit(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Thesaurus ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
