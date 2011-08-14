#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>

using namespace std;

class ServiceNames {
	public:
	vector <string> makeList(vector <string> services) {
		map<string, set<string> > m;

		for (int i=0; i<(int)services.size(); ++i) {
			istringstream is(services[i]);
			string s, w;
			is >> s;
			while (is >> w)
				m[w].insert(s);
		}

		vector<string> sol;
		for (map<string, set<string> >::const_iterator it=m.begin(); it!=m.end(); ++it) {
			string s = it->first + " ==> ";
			for (set<string>::const_iterator it2=(it->second).begin(); it2!=(it->second).end(); ++it2) {
				if (it2 != (it->second).begin())
					s += ", ";
				s += *it2;
			}
			sol.push_back(s);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"BLAST Genome Annotation Sensitivity","PING","X Annotation"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Annotation ==> BLAST, X", "Genome ==> BLAST", "Sensitivity ==> BLAST" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, makeList(Arg0)); }
	void test_case_1() { string Arr0[] = {"PING"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, makeList(Arg0)); }
	void test_case_2() { string Arr0[] = {"BLAST Genome annotation Sensitivity","PING","X Annotation","Apple X ample"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Annotation ==> X", "Genome ==> BLAST", "Sensitivity ==> BLAST", "X ==> Apple", "ample ==> Apple", "annotation ==> BLAST" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, makeList(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ServiceNames ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
