#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

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
template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

/*** real code starts here ***/

struct Entry {
	int cnt[50];
	bool at[50];
	Entry(): cnt(), at() {}
};
int con[50][50];
int n;
int nadji(const Entry &a, int x) {
	int y = 0;
	int next = 0;
	
	if (a.at[x]) return x;
	if (x>=n) return -1;
	for (int i=x+1; i<n; ++i)
		if (con[x][i] && a.cnt[i]) {
			++y; next = i;
		}
	if (y == 1) 
		return nadji(a, next);
	return x;
}
class PermissionTree {
    public:
    vector <int> findHome(vector <string> folders, vector <string> users) {
        map<string, Entry> m;
        vector<int> sol;
       	char par[50];
       	
        n = (int)folders.size();
        memset(con, false, sizeof con);
        memset(par, -1, sizeof par);
        for (int i=0; i<n; ++i) {
        	int t;
        	vector<string> name;
        	
        	name = tokenize<string>(folders[i], ",");
        	t = atoi(name[0].c_str());
        	if (i!=0)
        		par[i] = t;
        	con[t][i] = true;
        	for (int j=1; j<(int)name.size(); ++j) {
        		Entry &a = m[name[j]];
        		a.at[i] = true;
        		t = i;
        		while (t != -1) {
        			++a.cnt[t];
        			t = par[t];
        		}
        	}	
        }
        for (int i=0; i<(int)users.size(); ++i) {
        	if (!m.count(users[i])) {
        		sol.push_back(-1);
        		continue;
        	}
        	const Entry &a = m[users[i]];
        	sol.push_back(nadji(a, 0));
        }
        return sol;
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0 Admin", "0 Joe,Phil", "0 Joe"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Admin", "Joe", "Phil"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  0,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findHome(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0 Admin"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Peter", "Paul", "Mary"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { -1,  -1,  -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findHome(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0 Admin", "2 John", "0 Peter,John", "0 Tim", "1 John"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findHome(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"0 Admin",
"0 Jeff", "1 Mark,Tim", "1 Tim,Jeff",
"0 Dan", "4 Ed", "4 Tom", "4 Kyle,Ed",
"0 Ben", "8 Rich", "8 Sam", "8 Tim"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Jeff", "Ed", "Tim", "Steve"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  4,  0,  -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findHome(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"0 Admin", "0 Bob,Joe,Bob", "0 Joe"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Joe", "Bob"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, findHome(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PermissionTree ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
