#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <set>
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

typedef pair<double, double> Pdd;
/*** real code starts here ***/
class PointLifeGame {
	public:
	string format(double x)
	{
		int t = (int)(x*10000);
		char buff[10];
		
		sprintf(buff, "%04d.", t/10000);
		t %= 10000;
		
		int i=0;
		while (t!=0) {
			buff[8-i++] = t%10 + '0';
			t /= 10;
		}
		while (i<4)
			buff[8-i++] = '0';
		buff[9] = '\0';
		return buff;
	}
	string simulate(vector <int> xs, vector <int> ys, int rnds) {
		set<Pdd, greater<Pdd> > s1, s2;
		
		for (int i=0; i<(int)xs.size(); ++i)
			s1.insert(make_pair(ys[i], xs[i]));
		
		while (rnds--) {
			s2.clear();
			int cnt = 0;
			for (set<Pdd, greater<Pdd> >::const_iterator i=s1.begin(); i!=s1.end() && cnt++<rnds+2; ++i)
				for (typeof(i) j=s1.begin(); j!=i && j!=s1.end(); ++j)
					s2.insert(make_pair((i->first + j->first)/2, (i->second + j->second)/2));
			s2.swap(s1);
		}
		return format((s1.begin())->second)+' '+format((s1.begin())->first);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; string Arg3 = "0005.0000 0010.0000"; verify_case(0, Arg3, simulate(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; string Arg3 = "0005.0097 0007.5000"; verify_case(1, Arg3, simulate(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,10,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; string Arg3 = "0015.0000 0005.0000"; verify_case(2, Arg3, simulate(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10, 
 1,2,3,4,5,6,7,8,9,10, 
 1,2,3,4,5,6,7,8,9,10, 
 1,2,3,4,5,6,7,8,9,10, 
 1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1,1,1,1,1,1, 
 2,2,2,2,2,2,2,2,2,2,
 3,3,3,3,3,3,3,3,3,3,
 4,4,4,4,4,4,4,4,4,4,
 5,5,5,5,5,5,5,5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; string Arg3 = "0009.0009 0005.0000"; verify_case(3, Arg3, simulate(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {3,3,8,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; string Arg3 = "0002.4658 0002.1875"; verify_case(4, Arg3, simulate(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PointLifeGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
