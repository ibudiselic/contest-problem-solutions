#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <utility>

using namespace std;
typedef pair<int, int> PII;
template<class T> vector<T> tokenize(string s, const string &delim=" ") {
  vector<T> ret;
  string::size_type i=0;
  string::size_type len = delim.length();
  if (delim != " ")
    while ((i=s.find(delim)) != string::npos)
      s.replace(i, len, " ");

  istringstream is(s);
  T val;
  while (is >> val)
    ret.push_back(val);
  return ret;
}

class RangeGame {
	public:
	int get_best(const set<int> &s, const vector<vector<PII> > &a) {
		int bestp = -1;
		int best = -1;
		for (set<int>::const_iterator it=s.begin(); it!=s.end(); ++it) {
			int p = 0;
			for (int i=0; i<(int)a.size(); ++i)
				for (int j=0; j<(int)a[i].size(); ++j)
					if (a[i][j].first<=*it && *it<=a[i][j].second) {
						++p;
						break;
					}
			if (p > bestp) {
				best = *it;
				bestp = p;
			}
		}
		return best;
	}
	void update(set<int> &s, vector<vector<PII> > &a, const string &h) {
		vector<string> t = tokenize<string>(h);
		for (int i=0; i<(int)t.size(); ++i) {
			vector<int> tt = tokenize<int>(t[i], "-");

			for (int j=0; j<(int)a.size(); ++j)
				for (int k=0; k<(int)a[j].size(); ++k) {
					if (a[j][k].first<=tt[0] && tt[0]<=a[j][k].second) {
						a.erase(a.begin()+j);
						--j;
						break;
					}
					if (tt.size()==2 && a[j][k].first<=tt[1] && tt[1]<=a[j][k].second) {
						a.erase(a.begin()+j);
						--j;
						break;
					}
					if (tt.size()==2)
						if (tt[0]<=a[j][k].first && a[j][k].first<=tt[1] || tt[0]<=a[j][k].second && a[j][k].second<=tt[1]) {
							a.erase(a.begin()+j);
							--j;
							break;
						}
				}
		}
		s.clear();
		for (int i=0; i<(int)a.size(); ++i)
			for (int j=0; j<(int)a[i].size(); ++j) {
				s.insert(a[i][j].first);
				s.insert(a[i][j].second);
			}
	}
	vector <int> bestDoors(vector <string> possible, vector <string> hints) {
		vector<int> sol;
		set<int> nums;

		vector<vector<PII> > p(possible.size());
		for (int i=0; i<(int)possible.size(); ++i) {
			vector<string> t = tokenize<string>(possible[i]);
			for (int j=0; j<(int)t.size(); ++j) {
				vector<int> tt = tokenize<int>(t[j], "-");
				nums.insert(tt[0]);
				if (tt.size()==2) {
					p[i].push_back(make_pair(tt[0], tt[1]));
					nums.insert(tt[1]);
				} else {
					p[i].push_back(make_pair(tt[0], tt[0]));
				}
			}
		}

		for (int i=0; i<(int)hints.size(); ++i) {
			int best = get_best(nums, p);
			sol.push_back(best);

			update(nums, p, hints[i]);
		}
		int best = get_best(nums, p);
		sol.push_back(best);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1-100","100-200","200-300"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"50-75","250-1000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 100,  200,  100 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, bestDoors(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"100-900 1111","200-800 2222","300-700 3333","4444"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2000-4000","500"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 300,  100,  4444 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, bestDoors(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"346591240","858005279","1321831520","1453846384","1972718383","530431653-1848872872"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1400000000-2000000000","400000000-600000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 858005279,  346591240,  346591240 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, bestDoors(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RangeGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
