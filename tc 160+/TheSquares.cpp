#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int to_int(const string &s) {
	int ret;
	sscanf(s.c_str(), "%d", &ret);
	return ret;
}
vector<string> parse_str(const vector<string> &v) {
	string s;
	for (int i=0; i<(int)v.size(); ++i) {
		s += v[i];
	}
	vector<string> ret;
	istringstream is(s);
	string t;
	while (is >> t) {
		ret.push_back(t);
	}

	return ret;
}
vector<int> parse(const vector<string> &v) {
	vector<string> t = parse_str(v);
	vector<int> ret;
	for (int i=0; i<(int)t.size(); ++i) {
		ret.push_back(to_int(t[i]));
	}

	return ret;
}

struct S {
	int x1, y1, x2, y2, side;
	string name;
	S(int x1_, int y1_, int x2_, int y2_, int side_, const string &name_): x1(x1_), y1(y1_), x2(x2_), y2(y2_), side(side_), name(name_) {}
};
bool operator<(const S &a, const S &b) {
	if (a.side != b.side) {
		return a.side > b.side;
	}
	return a.name < b.name;
}
bool inside(const S &a, const S &b) {
	return b.x1<=a.x1 && a.x2<=b.x2 && b.y1<=a.y1 && a.y2<=b.y2;
}

bool I[1250][1250];
class TheSquares {
	public:
	vector <string> findSequence(vector <string> x, vector <string> y, vector <string> lengths, vector <string> names, int k) {
		vector<int> X = parse(x);
		vector<int> Y = parse(y);
		vector<int> L = parse(lengths);
		vector<string> N = parse_str(names);

		vector<S> v;
		int n = X.size();
		for (int i=0; i<n; ++i) {
			v.push_back(S(X[i], Y[i], X[i]+L[i], Y[i]+L[i], L[i], N[i]));
		}

		sort(v.begin(), v.end());
		
		memset(I, 0, sizeof I);
		vector<int> level(n, 1);
		for (int i=n-1; i>=0; --i) {
			for (int j=i+1; j<n; ++j) {
				if (inside(v[j], v[i])) {
					I[j][i] = 1;
					level[i] = max(level[i], level[j]+1);
				}
			}
		}

		set<int> cand;
		int ind = -1;
		for (int i=0; i<n; ++i) {
			if (level[i] >= k) {
				if (ind == -1) {
					ind = i;
					cand.insert(i);
				} else if (v[i].name < v[ind].name) {
					cand.clear();
					ind = i;
					cand.insert(i);
				} else if (v[i].name == v[ind].name) {
					if (!I[i][*cand.rbegin()]) {
						cand.insert(i);
					}
				}
			}
		}

		if (ind == -1) {
			return vector<string> ();
		}

		vector<string> sol;
		sol.push_back(v[ind].name);

		for (int t=k-1; t>0; --t) {
			set<int> ncand;
			ind = -1;
			for (set<int>::const_iterator it=cand.begin(); it!=cand.end(); ++it) {
				for (int j=*it+1; j<n; ++j) {
					if (level[j]>=t && I[j][*it]) {
						if (ind == -1) {
							ind = j;
							ncand.insert(j);
						} else if (v[j].name < v[ind].name) {
							ncand.clear();
							ind = j;
							ncand.insert(j);
						} else if (v[j].name == v[ind].name) {
							if (!I[j][*ncand.rbegin()]) {
								ncand.insert(j);
							}
						}
					}
				}
			}
			assert(ind != -1);
			sol.push_back(v[ind].name);
			cand = ncand;
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1 1 1 4 7 8 1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1 1 4 7 8 1000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 3 4 5 1 1000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"X Y Z ALPHA BETA GAMMA DELTA"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; string Arr5[] = {"BETA", "GAMMA" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, findSequence(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"1 1 1 4 7 8 1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1 1 4 7 8 1000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 3 4 5 1 1000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"X Y Z ALPHA BETA GAMMA DELTA"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; string Arr5[] = {"Z", "Y", "X" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, findSequence(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"4 4 4 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"7 7 7 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"47 47 47 47"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"GLUK GLUKA GLUKOVI GLUKOM"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; string Arr5[] = {"GLUK", "GLUKA", "GLUKOM", "GLUKOVI" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, findSequence(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"1 15 27 39"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 13 22 36"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"8 3 5 974"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"ACB DEF GHI JKL"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; string Arr5[] = { }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(3, Arg5, findSequence(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"123 453 754"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"119 487 874"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1000 500 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"SQUARE SQUARE SQUARE"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; string Arr5[] = {"SQUARE", "SQUARE", "SQUARE" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(4, Arg5, findSequence(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { string Arr0[] = {"3 5 10 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 8 10 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"974 990 1 1000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"X Y X Y"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; string Arr5[] = {"Y", "X", "X" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(5, Arg5, findSequence(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { string Arr0[] = {"1 1 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1 1 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 1 1 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"A A A A"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1000; string Arr5[] = { }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(6, Arg5, findSequence(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheSquares ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
