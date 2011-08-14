#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string to_str(long long x) {
    ostringstream os;
    os << x;
    return os.str();
}
long long to_ll(const string &s) {
    istringstream is(s);
    long long x;
    is >> x;
    return x;
}

class Transformation {
	public:
	vector <string> transform(vector <string> A) {
		vector<long long> v;
        for (int i=0; i<(int)A.size(); ++i) {
            v.push_back(to_ll(A[i]));
        }

        for (int i=(int)A.size()-1; i>=0; --i) {
            for (int j=0; j<(int)A.size(); ++j) {
                if (i != j) {
                    long long t = __gcd(v[i], v[j]);
                    long long x = v[j] / t;

                    while (1) {
                        long long y = __gcd(v[i], x);
                        if (y == 1) {
                            break;
                        }
                        v[i] /= y;
                    }
                }
            }

            for (int j=i+1; j<(int)A.size(); ++j) {
                v[i] /= __gcd(v[i], v[j]);
            }
        }

        for (int i=0; i<(int)A.size(); ++i) {
            A[i] = to_str(v[i]);
        }

        return A;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1","2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1", "2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, transform(Arg0)); }
	void test_case_1() { string Arr0[] = {"2","3","6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1", "1", "6" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, transform(Arg0)); }
	void test_case_2() { string Arr0[] = {"210","2","3","5","7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1", "2", "3", "5", "7" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, transform(Arg0)); }
	void test_case_3() { string Arr0[] = {"6","2","3","4","9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1", "1", "1", "4", "9" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, transform(Arg0)); }
	void test_case_4() { string Arr0[] = {"6","2","3","4","9","8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1", "1", "1", "1", "9", "8" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, transform(Arg0)); }
	void test_case_5() { string Arr0[] = {"3637","260","26122993443584","47715564111559878","2","871126696052836","3492829317","83024857214176826"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3637", "5", "26122993443584", "7952594018593313", "1", "217781674013209", "3492829317", "41512428607088413" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, transform(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Transformation ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
