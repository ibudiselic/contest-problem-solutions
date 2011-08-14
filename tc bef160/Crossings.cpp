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

class Crossings {
    public:
    vector <int> getOut(vector <int> positions, vector <int> angles) {
		vector<int> sol;
		int i, j, k;
		
		for (i=0; i<(int)positions.size(); ++i) {
			for (j=0; j<(int)positions.size(); ++j)
				if (i!=j) {
					if (angles[i]==angles[j]) continue;
					if (positions[i]<positions[j] && angles[i]>angles[j]
						||
						positions[i]>positions[j] && angles[i]<angles[j])
						continue;
					if (abs(90-angles[i])==abs(90-angles[j])) {
						if (i<j) continue;
						for (k=0; k<j; ++k)
							if (positions[k] > min(positions[i], positions[j]) && positions[k] < max(positions[i], positions[j]) && angles[i]==angles[k])
								break;
						if (k==j) break;
						continue;
					}
					if (abs(90-angles[i]) > abs(90-angles[j])) break;
				}
			if (j==(int)positions.size()) sol.push_back(i);
		}				
					
		return sol;
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0, 40, 20, 10, 30, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {90, 40, 30, 75, 135, 75}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  3,  5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getOut(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 40, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40, 40, 140}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getOut(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {89, 91}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getOut(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Crossings ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
