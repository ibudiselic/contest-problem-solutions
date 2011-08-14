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

vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}

const int INF = 987654321;
const int MUL = 200;

int L[200][200], H[200][200];
vector<string> places;
map<string, int> places_ind;
int get_ind(const string &s) {
    if (places_ind.count(s)) {
        return places_ind[s];
    } else {
        places_ind[s] = places.size();
        places.push_back(s);
        return (int)places.size() - 1;
    }
}
string to_str(int x) {
    ostringstream os;
    os << x;
    return os.str();
}
class LongStraightRoad {
	public:
	int distanceToDestination(vector <string> signs, string destination) {
		places.clear();
        places_ind.clear();
        int n = signs.size();
        for (int i=0; i<n; ++i) {
            get_ind("sign " + to_str(i));
        }
        
        for (int i=0; i<200; ++i) {
            for (int j=0; j<200; ++j) {
                L[i][j] = -INF;
                H[i][j] = INF;
            }
        }
        for (int i=0; i<n; ++i) {
            vector<string> t = cutUp(signs[i], ";");
            for (int j=0; j<(int)t.size(); ++j) {
                istringstream is(t[j]);
                string place;
                int dist;
                is >> place >> dist;
                dist *= MUL;
                int ind = get_ind(place);
                L[i][ind] = H[i][ind] = dist;
                L[ind][i] = H[ind][i] = -dist;
            }
        }
        
        L[0][0] = H[0][0] = 0;
        for (int i=1; i<n; ++i) {
            L[i-1][i] = 1;
            H[i][i-1] = -1;
            L[i][i] = H[i][i] = 0;
        }
        
        int m = places.size();
        for (int k=0; k<m; ++k) {
            for (int i=0; i<m; ++i) {
                for (int j=0; j<m; ++j) {
                    H[i][j] = min(H[i][j], H[i][k] + H[k][j]);
                    L[i][j] = max(L[i][j], L[i][k] + L[k][j]);
                }
            }
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<m; ++j) {
                if (H[i][j] < L[i][j]) {
                    return -1;
                }
            }
        }
        int dest = get_ind(destination);
        if (H[n-1][dest]!=L[n-1][dest] || H[n-1][dest]<0) {
            return -1;
        }
        
        return H[n-1][dest]/MUL;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"COLCHESTER 5;GLASTONBURY 25;MARLBOROUGH 13"
,"MARLBOROUGH 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "GLASTONBURY"; int Arg2 = 14; verify_case(0, Arg2, distanceToDestination(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"COLCHESTER 5;GLASTONBURY 25;MARLBOROUGH 13"
,"GLASTONBURY 13;MARLBOROUGH 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "GLASTONBURY"; int Arg2 = -1; verify_case(1, Arg2, distanceToDestination(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"A 25;B 15"
,"A 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "B"; int Arg2 = -1; verify_case(2, Arg2, distanceToDestination(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"YVO 60;J 62"
,"K 45"
,"K 40;MV 17"
,"K 37;YVO 44;HY 48;CC 69;D 77;YXF 80"
,"YVO 30;B 37;RB 59"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MV"; int Arg2 = 0; verify_case(3, Arg2, distanceToDestination(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"A 200;B 150"
,"C 45;D 100;E 150"
,"C 25;E 130"
,"F 80;G 65"
,"G 35;H 160"
,"A 160"
,"H 130"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "F"; int Arg2 = -1; verify_case(4, Arg2, distanceToDestination(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LongStraightRoad ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
