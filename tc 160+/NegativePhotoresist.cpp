#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> X, Y;
bool G[50][50];
int N;
double calcDist(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
double calc(double ang) {
	double cosfi = cos(ang);

	vector<double> y(Y.begin(), Y.end());
	for (int i=0; i<N; ++i)
		y[i] *= cosfi;

	vector< vector<double> > dist(N, vector<double> (N, 1e32));
	for (int i=0; i<N; ++i) {
		dist[i][i] = 0;
		for (int j=i+1; j<N; ++j)
			if (G[i][j])
				dist[i][j] = dist[j][i] = calcDist(X[i], y[i], X[j], y[j]);
	}

	for (int k=0; k<N; ++k)
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

	double total = 0;
	for (int i=0; i<N; ++i)
		for (int j=i+1; j<N; ++j)
			if (dist[i][j] < 1e25)
				total += dist[i][j];

	return total;
}
class NegativePhotoresist {
	public:
	double minimumTilt(vector <string> pin, int limit) {
		memset(G, 0, sizeof G);
		N = pin.size();
		X.resize(N, 0);
		Y.resize(N, 0);
		for (int i=0; i<N; ++i) {
			istringstream is(pin[i]);
			string coords;
			is >> coords;
			sscanf(coords.c_str(), "%d,%d", &X[i], &Y[i]);
			int x;
			while (is >> x)
				G[i][x] = 1;
		}

		double lo = 0.01;
		double hi = 1.55;

		for (int i=0; i<500; ++i) {
			double mid = (hi+lo)/2;

			if (calc(mid) < limit)
				hi = mid;
			else
				lo = mid;
		}

		return (lo+hi)/2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3,0 2 3",
"13,0 2 3",
"0,2 0 1",
"8,50 0 1",
"3,100000 5",
"100000,3 4",
"8432,221"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100835; double Arg2 = 1.4454078077996135; verify_case(0, Arg2, minimumTilt(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"3,0 2 3",
"13,0 2 3",
"0,2 0 1",
"8,50 0 1",
"3,100000 5",
"100000,3 4",
"8432,221"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 141601; double Arg2 = 0.010604469396671205; verify_case(1, Arg2, minimumTilt(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"3,0 2 3",
"13,0 2 3",
"0,2 0 1",
"8,50 0 1",
"3,100000 5",
"100000,3 4",
"8432,221"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100065; double Arg2 = 1.5491503047781332; verify_case(2, Arg2, minimumTilt(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"76492,66181 1",
"74004,26736 0 14",
"22967,14922",
"5781,62226",
"82836,93961 23",
"87218,72769 19",
"93356,54263 21 23",
"31487,92953",
"4108,40237 25",
"90459,36018 18",
"86769,8014",
"6311,25772 13",
"9507,63470 20",
"30653,48087 11 15",
"84214,63941 1",
"87079,8036 13",
"10892,10164 25 23",
"31650,57394",
"12181,22580 9",
"8820,66849 5",
"63222,10057 12",
"85163,78521 6",
"73264,56781",
"45982,63119 4 6 16",
"96653,33496",
"4728,75705 8 16",
"93821,30582",
"9948,22812"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2198136; double Arg2 = 1.078664288678656; verify_case(3, Arg2, minimumTilt(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"26749,31005 7 12 37 22 3 31 18 14 22 43 18 47 27",
"89443,23479 37 20 18 45 4 28 45 48 45 48 42 43",
"26624,91482 8 10 9 47 38 7 26 38 7 15 24 33 13 19",
"74780,3281 5 35 24 0 32 6 7 40 16 44 27 29 27 42",
"64491,34646 12 42 9 10 25 1 14 22 32 28 16 24 49",
"57611,97350 3 6 16 38 37 26 7 46 47 9 34 17 36 33",
"54900,19650 5 41 17 21 3 41 45 9 45 24 7 29 49 33",
"37779,84466 30 37 0 43 36 2 5 45 31 2 3 13 17 6 27",
"68486,19205 2 14 42 44 17 34 25 41 38 43 10 49 11",
"86915,28119 21 31 2 40 31 12 49 41 4 22 5 34 6 46",
"81402,18667 40 2 17 17 18 8 4 12 38 12 15 26 42 12",
"76982,50425 29 29 13 8 36 49 16 27 26 28 27 34 46",
"43766,59005 15 27 0 9 4 22 10 10 49 44 37 10 34 24",
"71619,57051 36 47 48 39 11 45 32 42 30 7 29 2 34",
"95436,51350 8 18 23 22 17 23 22 16 0 48 19 4 24 19",
"18419,71778 29 12 31 23 24 30 36 26 10 18 45 36 2",
"58370,12207 48 33 5 14 19 47 11 28 44 3 18 32 4 46",
"93954,84580 33 21 10 8 47 35 32 6 10 14 43 22 5 7",
"37005,46508 14 29 22 1 10 0 23 37 15 0 31 16 31 41",
"25700,33156 20 25 35 40 38 16 14 22 14 23 27 25 2",
"87882,64415 19 35 35 33 1 24 26 24 34 41 34 31 29",
"80610,20042 9 27 35 28 46 17 37 28 36 37 6 41 34",
"55546,68119 39 18 34 14 12 0 14 9 0 17 39 4 19 27",
"12701,80882 30 32 15 14 37 42 14 47 18 33 47 19 46",
"14048,1355 15 20 20 3 28 42 14 12 2 49 45 25 6 4",
"27482,63293 49 38 45 19 8 39 4 38 47 38 46 19 24",
"48215,66574 35 41 32 30 20 41 5 2 15 35 10 11 49",
"53613,76037 21 12 40 11 42 46 0 3 49 11 19 3 22 7",
"90922,15011 21 30 40 40 40 21 44 24 1 16 4 11 49",
"67445,91022 15 11 35 47 18 11 38 20 13 38 3 32 6",
"93451,40067 41 23 7 28 26 47 42 15 44 49 31 13 31",
"25947,11589 9 15 9 40 39 0 30 7 18 20 30 35 43 18",
"98403,23751 47 37 44 26 23 17 3 13 48 4 16 42 29",
"32918,74706 17 16 39 47 41 20 23 36 5 35 2 6 43 43",
"9851,96894 8 22 44 36 20 21 5 20 12 9 43 13 46 11",
"86305,55072 37 21 26 29 20 3 20 17 19 46 26 33 31",
"66150,16273 45 13 39 7 21 34 15 11 45 39 15 33 5",
"95275,37494 1 35 32 43 7 0 21 23 5 39 44 21 18 12",
"16184,79884 40 25 39 5 8 2 19 10 47 2 25 29 25 29",
"77000,48925 33 22 36 38 25 37 13 31 40 46 40 36 22",
"19246,92639 10 38 9 28 19 28 28 48 31 27 39 39 3",
"37419,96699 30 26 33 6 9 8 45 26 21 6 20 46 18 43",
"65611,72059 8 30 23 4 44 24 10 13 27 3 32 1 48 48",
"78307,80168 37 7 8 17 0 31 34 41 48 33 33 48 1 48",
"35276,57349 8 32 45 34 30 37 28 42 12 46 16 49 3",
"10106,992 36 25 44 41 1 7 36 13 15 6 6 1 24 49 1",
"43647,68652 21 5 35 44 39 27 41 9 25 16 34 23 11",
"7588,43383 32 33 29 2 17 13 30 38 23 16 25 5 23 0",
"39549,20275 16 13 40 14 32 43 1 1 42 43 42 43",
"49470,43071 25 9 8 12 30 11 44 26 28 27 24 45 4 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 45315043; double Arg2 = 1.4635199471353126; verify_case(4, Arg2, minimumTilt(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NegativePhotoresist ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
