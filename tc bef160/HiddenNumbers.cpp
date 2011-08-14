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
bool cmp(const string &a, const string &b)
   	{
   		long long x, y;
   		istringstream is1(a);
   		istringstream is2(b);
   		is1 >> x;
   		is2 >> y;
   		if (x==y) 
   			return a.length() < b.length();
   	    else 
   			return x < y;
   	}

class HiddenNumbers {
    public:
    vector <string> findAll(vector <string> text) {
        vector<string> tmp;
        string s;
        
        for (int i=0; i<(int)text.size(); ++i) {
        	string &t = text[i];
        	int n = t.length();
        	int j = 0;
        	do {
        		if (t.length()==0) {
        			if (i==(int)text.size()-1 && s.length()!=0)
        				tmp.push_back(s);
        			continue;
 				}
        		while (j<n && !isdigit(t[j]))
        			++j;
        		if (j!=0 && s.size()!=0) {
        			tmp.push_back(s);
        			s.erase();
        		}
        		if (j == n) {
        			s.erase();
        			continue;
        		}
        		while (j<n && isdigit(t[j]))
        			s += t[j++];
        		
        		if (j<n || i==(int)text.size()-1 && s.size()!=0) {
        			tmp.push_back(s);
        			s.erase();
        		}
        	} while (j < n);
        }
        sort(tmp.begin(), tmp.end(), cmp);
       	
       	vector<string> sol;
       	for (int i=(int)tmp.size()/2; i<(int)tmp.size(); ++i)
       		sol.push_back(tmp[i]);
       	return sol;
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"098m03r9f80239802389f0m9KDKLKLJDKLJm0983m890DMOm03",
 "dlkfj3hljf4h3klhl  4j4 444 44  rjhkrrkr34534539893",
 " 390804980498409480 dkldjkl djkl djkl d00000002998"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "9",  "44",  "098",  "444",  "890",  "0983",  "00000002998",  "34534539893",  "80239802389",  "390804980498409480" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findAll(Arg0)); }
	void test_case_1() { string Arr0[] = {"39 000220 30 skldjdije939939slkk 3090 2912kjdk3949",
 "dlkjd dkljsl098 dkd3 23kdkdkl 0000002222kdjdie9000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0000002222",  "2912",  "3090",  "3949",  "9000",  "939939" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findAll(Arg0)); }
	void test_case_2() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findAll(Arg0)); }
	void test_case_3() { string Arr0[] = {"0022 22k00022a022"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0022",  "00022" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findAll(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HiddenNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
