#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

vector<long long> V;
long long getMil(const string &s) {
	long long x;
	int k;
	sscanf(s.c_str(), "%lld.%d", &x, &k);

	return x*1000 + k;
}
map<long long, int> M1, M2;
void go(int pos, int lim, long long len, int cnt, map<long long, int> &M) {
	if (pos == lim) {
		int &need = M[len];
		if (need==0 || need>cnt)
			need = cnt;
		return;
	}

	go(pos+1, lim, len, cnt, M);
	go(pos+1, lim, len+V[pos], cnt+1, M);
}
class LongPipes {
	public:
	int fewestWelds(vector <string> segments, string desiredLength) {
		for (int i=0; i<(int)segments.size(); ++i)
			V.push_back(getMil(segments[i]));

		long long x = getMil(desiredLength);
		M1.clear();
		M2.clear();

		go(0, V.size()/2, 0, 0, M1);
		go(V.size()/2, V.size(), 0, 0, M2);

		int best = 1234567890;
		for (map<long long, int>::const_iterator it=M1.begin(); it!=M1.end(); ++it)
			if (M2.count(x - it->first))
				best = min(best, it->second + M2[x - it->first]);

		return best < 1234567890 ? best-1 : -1;
	}





// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1.000","2.000","4.000","8.000","16.000","32.000","64.000","128.000",
 "256.000","512.000","1024.000","2048.000","4096.000","8192.000",
 "16384.000","32768.000","65536.000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "65535.000"; int Arg2 = 15; verify_case(0, Arg2, fewestWelds(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0.001","0.002","0.004","0.008","0.016","0.032","0.064","0.128","0.256",
 "0.512","1.024","2.048","4.096","8.192","16.384","32.768","65.536",
 "131.072","262.144","524.288","1048.576","2097.152","4194.304","8388.608",
 "16777.216","33554.432","67108.864","134217.728","268435.456","536870.912",
 "1073741.824","2147483.648","4294967.296","8589934.592","17179869.184",
 "34359738.368","68719476.736","137438953.472"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "233333333.555"; int Arg2 = 17; verify_case(1, Arg2, fewestWelds(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "38000000000.000"; int Arg2 = 37; verify_case(2, Arg2, fewestWelds(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"0.002","0.002","0.004","0.008","0.016","0.032","0.064","0.128","0.256",
 "0.512","1.024","2.048","4.096","8.192","16.384","32.768","65.536",
 "131.072","262.144","524.288","1048.576","2097.152","4194.304","8388.608",
 "16777.216","33554.432","67108.864","134217.728","268435.456","536870.912",
 "1073741.824","2147483.648","4294967.296","8589934.592","17179869.184",
 "34359738.368","68719476.736","137438953.472"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1000000000.001"; int Arg2 = -1; verify_case(3, Arg2, fewestWelds(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LongPipes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
