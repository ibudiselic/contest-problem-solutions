#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
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

stack<int> ind;
stack<int> mon;

class PayBill {
    public:
    vector <int> whoPaid(vector <int> meals, int totalMoney) {
        vector<int> sol;
        int i, j, money;
        
        money = totalMoney;
        i = (int)meals.size();
        
L1:     for(;;) {
     		for (j=i-1; j>=0; --j) {
        		if (money == meals[j]) {
        			sol.push_back(j);
        			while (!ind.empty()) {
        				sol.push_back(ind.top());
        				ind.pop();
        			}
        			return sol;
        		}
        		if (money > meals[j]) {
        			mon.push(money);
        			ind.push(j);
        			money -= meals[j];
        			i = j;
        			goto L1;
        		}
        	}
        	if (!ind.empty()) {
        		i = ind.top(); ind.pop();
        		money = mon.top(); mon.pop();
        	} else break;
        }
        return vector<int>();	
    }






// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = { 1000, 1200, 1300 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2500; int Arr2[] = { 1,  2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, whoPaid(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 100, 200, 350 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 300; int Arr2[] = { 0,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, whoPaid(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 150, 200, 350, 400 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 900; int Arr2[] = { 0,  2,  3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, whoPaid(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {6584,6733,6018,5840,2723,4902,4260,
 5375,6745,1234,3000,8222,2472,
 4348,1716,9995,415,1234,2345,5679}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 70630; int Arr2[] = { 0,  1,  3,  4,  5,  6,  8,  9,  11,  13,  14,  15,  16,  17,  19 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, whoPaid(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PayBill ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
