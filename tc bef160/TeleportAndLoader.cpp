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

vector<int> box;
long long tc, lc;
map<int, long long> memo;

long long doit(int b)
{
	if (b==(int)box.size())
		return 0;
	
	long long &ret_val = memo[b];
	if (ret_val) return ret_val;
	
	ret_val = lc*box[b] + doit(b+1);
	for (int i=b; i<(int)box.size(); ++i) {
		for (int j=i; j<(int)box.size(); ++j) {
			long long t = tc;
			for (int k=b; k<=j; ++k)
				t += abs(box[i]-box[k])*lc;
			ret_val <?= t + doit(j+1);
		}
	}
	return ret_val;
}
	
class TeleportAndLoader {
    public:
    int cheapTransportation(vector <int> boxes, int teleport_cost, int loader_cost) {
        box = boxes; tc = teleport_cost; lc = loader_cost;
        
        memo.clear();
        sort(box.begin(), box.end());
        return (int)doit(0);
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10000; int Arg2 = 1; int Arg3 = 15; verify_case(0, Arg3, cheapTransportation(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1000, 40, 50, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 200; int Arg2 = 10; int Arg3 = 600; verify_case(1, Arg3, cheapTransportation(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 10, 254, 987, 1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1000; int Arg3 = 5; verify_case(2, Arg3, cheapTransportation(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TeleportAndLoader ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
