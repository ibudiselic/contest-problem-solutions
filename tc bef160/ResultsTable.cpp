#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
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

VI srt;
string ord;
const int INFTY = 100000;
int n;

struct dude {
	string name;
	int score[50]; // from 1 to n<=49
	int count[50]; // matching count for score
	
	dude(): name(), count()
	{
		for (int i=1; i<=n; ++i)
			score[i] = (ord[i-1]=='L' ? INFTY : -INFTY);
	}
			
	
	bool operator<(const dude &a)
	{	
		for (vector<int>::const_iterator i=srt.begin(); i!=srt.end(); ++i) {
			bool lt = true;
			int t = abs(*i);
			
			if (*i<0) lt = !lt;
			if (t==1) {
				if (name < a.name) return lt;
				if (name > a.name) return !lt;
			} else {
				if (ord[t-2] == 'H') lt = !lt;
				if (score[t-1] < a.score[t-1]) return lt;
				if (score[t-1] > a.score[t-1]) return !lt;
			}
		}
		assert(0);
		return false;
	}
};
class ResultsTable {
    public:
	    vector <string> generateTable(vector <string> results, vector <int> sort, string order) {
		
		map<string, dude> memo;
		srt = sort;
		ord = order;
		n = (int)order.size();
		
		for (vector<string>::const_iterator i=results.begin(); i!=results.end(); ++i) {
			VS tmp = tokenize<string>(*i);
			dude &a = memo[tmp[0]];
			a.name = tmp[0];
			// "NAME METRIC COUNT SCORE"
			if (atoi(tmp[2].c_str()) > a.count[atoi(tmp[1].c_str())]) {
				a.count[atoi(tmp[1].c_str())] = atoi(tmp[2].c_str());
				a.score[atoi(tmp[1].c_str())] = atoi(tmp[3].c_str());
			}
		}
		vector<dude> tmprry;
		for (map<string, dude>::const_iterator i=memo.begin(); i!=memo.end(); ++i)
			tmprry.push_back(i->second);
		
		for (vector<dude>::iterator i=tmprry.begin(); i!=tmprry.end(); ++i)
			for (vector<dude>::iterator j=i+1; j!=tmprry.end(); ++j)
				if (*j < *i) {
					dude a = *i; *i = *j; *j = a;
				}
			
		VS sol;
		for (vector<dude>::const_iterator i=tmprry.begin(); i!=tmprry.end(); ++i) {
			string t = i->name;
			for (int j=1; j<=n; ++j) {
				if (abs(i->score[j]) < INFTY)
					t += ' '+to_str<int>(i->score[j]);
				else t += " -";
			}
			sol.push_back(t);
		}
		return sol;	
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"A 1 1 54","A 2 1 20","a 1 1 23","a 2 1 50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,2,-3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "HL"; string Arr3[] = { "a 23 50",  "A 54 20" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, generateTable(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"A 1 1 54","A 2 1 20","B 1 1 23","B 2 1 50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,-3,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "HL"; string Arr3[] = { "B 23 50",  "A 54 20" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, generateTable(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"A 1 1 54","A 2 1 20","B 1 1 54"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4,-3,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "HLH"; string Arr3[] = { "B 54 - -",  "A 54 20 -" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, generateTable(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"q 3 90 444","J 2 6 347","b 3 17 -543","I 2 13 897","M 3 55 -439"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,-2,-1,-3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "LHH"; string Arr3[] = { "q - - 444",  "M - - -439",  "b - - -543",  "J - 347 -",  "I - 897 -" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, generateTable(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"f 1 37 -861","s 1 92 -829","v 2 78 247","M 1 30 -31","E 1 45 -646"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "LL"; string Arr3[] = { "v - 247",  "E -646 -",  "M -31 -",  "f -861 -",  "s -829 -" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, generateTable(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ResultsTable ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
