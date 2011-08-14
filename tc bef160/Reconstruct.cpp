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

struct Point {
	int _x, _y, _z;
	Point(int x=0, int y=0, int z=0): _x(x), _y(y), _z(z) {}
	int x() const { return _x; }
	int y() const { return _y; }
	int z() const { return _z; }
	string p_str() const
	{
		return to_str<int>(_x)+' '+to_str<int>(_y)+' '+to_str<int>(_z);
	}
};
int n;
vector<int> d[20];
int sqr(int x)
{
	return x*x;
}
int dist(const Point &a, const Point &b)
{
	return sqr(a.x()-b.x()) + sqr(a.y()-b.y()) + sqr(a.z()-b.z());
}

bool rekurzija(Point *p, int t)
{
	int start = (t==1 ? 0 : -31);
	if (t==n)
		return true;
	
	for (int x=start; x<32; ++x)
		for (int y=start; y<32; ++y)
			for (int z=start; z<32; ++z)
				if (sqr(x)+sqr(y)+sqr(z) == d[t-1][t]) {
					bool doit = true;
					p[t] = Point(p[t-1].x()+x, p[t-1].y()+y, p[t-1].z()+z);
					for (int v=0; v<t-1; ++v)
						if (dist(p[v], p[t])!=d[v][t]) {
							doit = false;
							break;
						}
						if (doit) {
							if (rekurzija(p, t+1))
								return true;
						}
				}
	return false;
}				
class Reconstruct {
    public:
    vector <string> findPoints(vector <string> dists)
    {
        Point p[20];
        n = (int)dists.size();
        
        for (int i=0; i<n; ++i)
        	d[i] = tokenize<int>(dists[i]);
        
        if (n==1 || rekurzija(p, 1)) {
        	vector<string> sol;
        	for (int i=0; i<n; ++i)
        		sol.push_back(p[i].p_str());
        	return sol;
        }
        return vector<string>();
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0 1","1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0 0 0",  "0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findPoints(Arg0)); }
	void test_case_1() { string Arr0[] = {"0 2 2","2 0 2","2 2 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0 0 0",  "0 1 1",  "-1 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findPoints(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 33 25","33 0 84","25 84 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0 0 0",  "1 4 4",  "3 -4 0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findPoints(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 15","15 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findPoints(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Reconstruct ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
