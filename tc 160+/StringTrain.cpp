#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

class StringTrain {
	public:
	string buildTrain(vector <string> cars) {
		string sol = cars[0];

		for (int i=1; i<(int)cars.size(); ++i) {
			int limit = min((int)cars[i].size(), (int)sol.size());
			for (int len=limit-1; len>0; --len)
				if (cars[i].substr(0, len) == sol.substr(sol.size()-len, len)) {
					sol += cars[i].substr(len, string::npos);
					break;
				}
		}
		string result = to_str<string::size_type>(sol.size()) + ' ';

		vector<bool> use(26, true);
		string t;
		for (int i=(int)sol.size()-1; i>=0; --i)
			if (use[sol[i]-'A']) {
				t = sol[i] + t;
				use[sol[i]-'A'] = false;
			}

		return result+t;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABCDE","CDFFF","CDE","CDEGG","GABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "10 DEGABC"; verify_case(0, Arg1, buildTrain(Arg0)); }
	void test_case_1() { string Arr0[] = {"AAAAA","AAAAA","AAAAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "7 A"; verify_case(1, Arg1, buildTrain(Arg0)); }
	void test_case_2() { string Arr0[] = {"CABABDABAB","CABAB","ABABDABAB","DABAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "15 CDAB"; verify_case(2, Arg1, buildTrain(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABABAB","ABABAB","ABABABAB","BZZZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "15 ABZ"; verify_case(3, Arg1, buildTrain(Arg0)); }
	void test_case_4() { string Arr0[] = {"A","A","A","AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1 A"; verify_case(4, Arg1, buildTrain(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StringTrain ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
