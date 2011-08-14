#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

long long num(const string &s) {
	long long x = 0;
	for (int i=0; i<(int)s.size(); ++i) {
		x = 10*x + (s[i]-'0');
	}
	return x;
}
string str(long long x) {
	ostringstream os;
	os << x;
	return os.str();
}

class AbsSequence {
	public:
	vector <string> getElements(string first, string second, vector <string> indices) {
		long long a = num(first);
		long long b = num(second);
		if (a==0 && b==0) {
			return vector<string>(indices.size(), "0");
		}

		vector< pair<long long, int> > V;
		for (int i=0; i<(int)indices.size(); ++i) {
			V.push_back(make_pair(num(indices[i]), i));
		}
		sort(V.begin(), V.end());

		for (int i=(int)V.size()-1; i>0; --i) {
			V[i].first -= V[i-1].first;
		}

		int pos = 0;
		vector<string> sol(V.size(), "");

		while (1) {
			while (pos<(int)V.size() && V[pos].first==0) {
				sol[V[pos++].second] = str(a);
			}

			if (pos >= (int)V.size()) {
				break;
			}

			long long d = a-b>=0 ? a-b : b-a;
			a = b;
			b = d;
			--V[pos].first;
			if (b==0 && V[pos].first>0) {
				if (V[pos].first%3 == 1) {
					b = a;
					a = 0;
				} else if (V[pos].first%3 == 2) {
					b = a;
				}
				V[pos].first = 0;
			}
			cerr << pos << ' ' << V[pos].first << ' ' << a << ' ' << b << '\n';

			if (a>b && V[pos].first>3) {
				d = a-b>=0 ? a-b : b-a;
				long long kM = a/d;
				if (kM < 3) {
					continue;
				}
				long long seg_cnt = (kM-1)/2;
				long long seg_lim = (V[pos].first-1)/3;
				long long seg_fin = min(seg_cnt, seg_lim);

				V[pos].first -= seg_fin*3 + 1;
				b = d;
				a -= (seg_fin*2 + 1)*d;
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "21"; string Arg1 = "12"; string Arr2[] = {"0", "1", "2", "3", "4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"21", "12", "9", "3", "6" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getElements(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "0"; string Arg1 = "0"; string Arr2[] = {"1000000000000000000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"0" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getElements(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "823"; string Arg1 = "470"; string Arr2[] = {"3","1","31","0","8","29","57","75","8","77"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"117", "470", "2", "823", "115", "87", "49", "25", "115", "23" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, getElements(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "710370"; string Arg1 = "177300"; string Arr2[] = {"5","95","164721","418","3387","710","0","1197","19507","5848"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"178470", "108270", "90", "0", "90", "90", "710370", "90", "0", "0" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getElements(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AbsSequence ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
