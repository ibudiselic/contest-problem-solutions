#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int C[50];
int compHeight[50];
int compDepth[50];
int compWeight[50];
int weight[50];
vector<string> X;
vector<string> G;
int N;
void dfs(int x, int comp) {
	C[x] = comp;
	for (int i=0; i<N; ++i)
		if (C[i]==-1 && X[x][i]=='=')
			dfs(i, comp);
}
int calcHeight(const vector< vector<int> > &components, int comp) {
	if (compHeight[comp] != -1)
		return compHeight[comp];

	compHeight[comp] = 0;
	for (int member=0; member<(int)components[comp].size(); ++member) {
		for (int other=0; other<(int)components.size(); ++other)
			if (other != comp) {
				for (int otherMember=0; otherMember<(int)components[other].size(); ++otherMember) {
					if (X[components[comp][member]][components[other][otherMember]] == '+') {
						compHeight[comp] = max(compHeight[comp], calcHeight(components, other)+1);
						break;
					}
				}
			}
	}

	return compHeight[comp];
}
int calcDepth(const vector< vector<int> > &components, int comp) {
	if (compDepth[comp] != -1)
		return compDepth[comp];

	compDepth[comp] = 0;
	for (int member=0; member<(int)components[comp].size(); ++member) {
		for (int other=0; other<(int)components.size(); ++other)
			if (other != comp) {
				for (int otherMember=0; otherMember<(int)components[other].size(); ++otherMember) {
					if (X[components[comp][member]][components[other][otherMember]] == '-') {
						compDepth[comp] = max(compDepth[comp], calcDepth(components, other)+1);
						break;
					}
				}
			}
	}

	return compDepth[comp];
}

int A, B;
void update(int w, int &t) {
	int newVal = (w<0 ? 0 : (w==0 ? 1: 2));
	if (t == -2)
		t = newVal;
	else if (t != newVal)
		t = -1;
}
bool testWeight(int x) {
	const int nComp = G.size();
	for (int i=0; i<nComp; ++i)
		if (compWeight[i] != -1) {
			if (compWeight[C[x]]>compWeight[i] && (G[C[x]][i]=='=' || G[C[x]][i]=='-')
				||
				compWeight[C[x]]<compWeight[i] && (G[C[x]][i]=='=' || G[C[x]][i]=='+')
				||
				compWeight[C[x]]==compWeight[i] && (G[C[x]][i]=='-' || G[C[x]][i]=='+')) {
					return false;
			}
		}
	return true;
}
void goB(int w, int &t) {
	if (weight[B] != -1) {
		assert(compWeight[C[B]] == weight[B]);
		update(w-weight[B], t);
	} else {
		if (compWeight[C[B]] == -1) {
			int lo = (compHeight[C[B]]+1)*10;
			int hi = (3-compDepth[C[B]])*10;
			for (weight[B]=lo; weight[B]<=hi; weight[B]+=10)
				if ((compWeight[C[B]]=weight[B]) && testWeight(B)) {
					update(w-weight[B], t);
					if (t == -1)
						break;
				}
			weight[B] = -1;
			compWeight[C[B]] = -1;
		} else {
			weight[B] = compWeight[C[B]];
			if (testWeight(B))
				update(w-weight[B], t);
			weight[B] = -1;
		}
	}
}
void goA(int w, int &t) {
	if (weight[A] != -1) {
		assert(compWeight[C[A]] == weight[A]);
		goB(w-weight[A], t);
	} else {
		if (compWeight[C[A]] == -1) {
			int lo = (compHeight[C[A]]+1)*10;
			int hi = (3-compDepth[C[A]])*10;
			for (weight[A]=lo; weight[A]<=hi; weight[A]+=10)
				if ((compWeight[C[A]]=weight[A]) && testWeight(A)) {
					goB(w-weight[A], t);
					if (t == -1)
						break;
				}
			weight[A] = -1;
			compWeight[C[A]] = -1;
		} else {
			weight[A] = compWeight[C[A]];
			if (testWeight(A))
				goB(w-weight[A], t);
			weight[A] = -1;
		}
	}
}
void goY(int y, int w, int &t) {
	if (weight[y] != -1) {
		assert(compWeight[C[y]] == weight[y]);
		goA(w+weight[y], t);
	} else {
		if (compWeight[C[y]] == -1) {
			int lo = (compHeight[C[y]]+1)*10;
			int hi = (3-compDepth[C[y]])*10;
			for (weight[y]=lo; weight[y]<=hi; weight[y]+=10)
				if ((compWeight[C[y]]=weight[y]) && testWeight(y)) {
					goA(w+weight[y], t);
					if (t == -1)
						break;
				}
			weight[y] = -1;
			compWeight[C[y]] = -1;
		} else {
			weight[y] = compWeight[C[y]];
			if (testWeight(y))
				goA(w+weight[y], t);
			weight[y] = -1;
		}
	}
}
void goX(int x, int y, int &t) {
	if (weight[x] != -1) {
		assert(compWeight[C[x]] == weight[x]);
		goY(y, weight[x], t);
	} else {
		if (compWeight[C[x]] == -1) {
			int lo = (compHeight[C[x]]+1)*10;
			int hi = (3-compDepth[C[x]])*10;
			for (weight[x]=lo; weight[x]<=hi; weight[x]+=10)
				if ((compWeight[C[x]]=weight[x]) && testWeight(x)) {
					goY(y, weight[x], t);
					if (t == -1)
						break;
				}
			weight[x] = -1;
			compWeight[C[x]] = -1;
		} else {
			weight[x] = compWeight[C[x]];
			if (testWeight(x))
				goY(y, weight[x], t);
			weight[x] = -1;
		}
	}
}
int answer(int x, int y) {
	int t = -2;
	goX(x, y, t);
	assert(t != -2);
	return t;
}
class WeighingScale {
	public:
	vector <int> count(vector <string> measures, int A, int B) {
		X = measures;
		N = X.size();
		::A = A;
		::B = B;

		memset(C, 0xff, sizeof C);
		int compCnt = 0;
		for (int i=0; i<N; ++i)
			if (C[i] == -1)
				dfs(i, compCnt++);

		vector< vector<int> > components(compCnt, vector<int>());
		for (int i=0; i<N; ++i)
			components[C[i]].push_back(i);

		G.assign(compCnt, string(compCnt, '?'));
		for (int i=0; i<compCnt; ++i) {
			G[i][i] = '=';
			for (int j=i+1; j<compCnt; ++j) {
				for (int a=0; a<(int)components[i].size(); ++a)
					for (int b=0; b<(int)components[j].size(); ++b)
						if (X[components[i][a]][components[j][b]] != '?') {
							if (X[components[i][a]][components[j][b]] == '=') {
								G[i][j] = G[j][i] = '=';
							} else if (X[components[i][a]][components[j][b]] == '+') {
								G[i][j] = '+';
								G[j][i] = '-';
							} else {
								G[i][j] = '-';
								G[j][i] = '+';
							}
							goto RELATION_FOUND;
						}
				RELATION_FOUND: ;
			}
		}

		memset(compHeight, 0xff, sizeof compHeight);
		memset(compDepth, 0xff, sizeof compDepth);
		for (int i=0; i<compCnt; ++i) {
			calcHeight(components, i);
			calcDepth(components, i);
		}

		memset(weight, 0xff, sizeof weight);
		memset(compWeight, 0xff, sizeof compWeight);
		for (int i=0; i<N; ++i)
			if (compHeight[C[i]] == 2)
				compWeight[C[i]] = weight[i] = 30;
			else if (compHeight[C[i]] == 1 && compDepth[C[i]] == 1)
				compWeight[C[i]] = weight[i] = 20;
			else if (compHeight[C[i]] == 0 && compDepth[C[i]] == 2)
				compWeight[C[i]] = weight[i] = 10;

		vector<int> sol(3, 0);
		for (int i=0; i<N; ++i)
			if (i!=A && i!=B)
				for (int j=i+1; j<N; ++j)
					if (j!=A && j!=B) {
						int t = answer(i, j);
						if (t != -1)
							++sol[t];
					}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"?+????","-?+???","?-????","????+?", "???-?+","????-?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; int Arr3[] = {1, 4, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"?+?????","-?+????","?-?????","????+??", "???-?+?","????-??", "???????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; int Arr3[] = {10, 0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"?+?????","-?+????","?-?????","????+??", "???-?+?","????-??", "???????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; int Arr3[] = {1, 4, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"??+?", "???+", "-???", "?-??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arr3[] = {1, 0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"??+??", "???+?", "-???=", "?-???", "??=??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arr3[] = {3, 0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"?+???++?????++","-??=?=???????=","??????????=???","?=??+?==??????",
"???-???-???-??","-=????????????","-??=???=?-+???","???=+?=???????",
"??????????????","??????+???????","??=???-????-??","????+?????+???",
"-?????????????","-=????????????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 2; int Arr3[] = {1, 10, 36 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WeighingScale ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
