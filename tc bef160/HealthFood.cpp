#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
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

class HealthFood {
    public:
    vector<int> p, c, f, t;
    bool f1(vector<int> &a, int x, int y)
    {
    	return a[x] < a[y];
    }
    bool better(int x, int y, string &s)
    {
    	for (int i=0; i<(int)s.length(); ++i)
    		switch (s[i]) {
    			case 'c': if (c[x] != c[y]) return  f1(c, x, y); break;
    			case 'C': if (c[x] != c[y]) return !f1(c, x, y); break;
    			case 'f': if (f[x] != f[y]) return  f1(f, x, y); break;
    			case 'F': if (f[x] != f[y]) return !f1(f, x, y); break;
    			case 'p': if (p[x] != p[y]) return  f1(p, x, y); break;
    			case 'P': if (p[x] != p[y]) return !f1(p, x, y); break;
    			case 't': if (t[x] != t[y]) return  f1(t, x, y); break;
    			case 'T': if (t[x] != t[y]) return !f1(t, x, y); break;
    		}
    	return x < y;
    }
    vector <int> selectMeals(vector <int> protein, vector <int> carbs, vector <int> fat, vector <string> dietPlans) {
        vector<int> cal;
        p = protein; c = carbs; f = fat;
        for (int i=0; i<(int)p.size(); ++i)
        	cal.push_back(9*f[i] + 5*(c[i]+p[i]));
        t = cal;
        
        vector<int> sol;
        for (int i=0; i<(int)dietPlans.size(); ++i) {
        	int t=0;
        	for (int j=1; j<(int)p.size(); ++j)
        		if (better(j, t, dietPlans[i]))
        			t = j;
        	sol.push_back(t);
        }
        return sol;
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"P", "p", "C", "c", "F", "f", "T", "t"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 1,  0,  1,  0,  0,  1,  1,  0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {3, 4, 1, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 8, 5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 2, 4, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"tFc", "tF", "Ftc"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 3,  2,  0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {18, 86, 76,  0, 34, 30, 95, 12, 21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {26, 56,  3, 45, 88,  0, 10, 27, 53}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {93, 96, 13, 95, 98, 18, 59, 49, 86}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"f", "Pt", "PT", "fT", "Cp", "C", "t", "",
 "cCp", "ttp", "PCFt", "P", "pCt", "cP", "Pc"}
; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 2,  6,  6,  2,  4,  4,  5,  0,  5,  5,  6,  6,  3,  5,  6 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HealthFood ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
