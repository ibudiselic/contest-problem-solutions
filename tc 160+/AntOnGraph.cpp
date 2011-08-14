#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef long long matrix_type_;
const long long INF = 100LL * 500 * 1000000000 + 1;
class SqMatrix {
    public:
    SqMatrix(int n_): n(n_) {
        //cerr << "constructor " << this << '\n';
        orig = new matrix_type_[n*n];
    }
    SqMatrix(const SqMatrix &other): n(other.size()) {
        //cerr << "copy constructor " << this << ' ' << &other << '\n';
        orig = new matrix_type_[n*n];
        other.copy_contents_to(orig);
    }
    void operator=(const SqMatrix &other) {
        //cerr << "copy operator " << this << ' ' << &other << '\n';
        assert(other.size() == n);
        if (this != &other) {
            other.copy_contents_to(orig);
        }
    }
    ~SqMatrix() {
        //cerr << "destructor " << this << '\n';
        delete[] orig;
    }
    
    static SqMatrix identity(int n) {
        SqMatrix A(n);
        A.init(-INF);
        for (int i=0; i<n; ++i) {
            A(i, i) = 0;
        }
        return A;
    }
    
    void init(matrix_type_ val) {
        for (int i=0; i<n*n; ++i) {
            *(orig + i) = val;
        }
    }
    // user responsible for 'p' pointing to enough memory
    void copy_contents_to(matrix_type_ *p) const { memcpy(p, orig, n*n*sizeof(matrix_type_)); }
    
    int size() const { return n; }
    matrix_type_& operator()(int i, int j) { return *(orig + i*n + j); }
    matrix_type_ operator()(int i, int j) const { return *(orig + i*n + j); }

    private:
        const int n;
        matrix_type_ *orig;
};
SqMatrix operator*(const SqMatrix &A, const SqMatrix &B) {
    assert(A.size() == B.size());
    const int n = A.size();
    SqMatrix C(n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            C(i, j) = -INF;
            for (int k=0; k<n; ++k) {
                if (A(i, k)>-INF && B(k, j)>-INF) {
                    C(i, j) = max(C(i, j), A(i, k) + B(k, j));
                }
            }
        }
    }
    return C;
}

SqMatrix to_the(SqMatrix A, long long n) {
    const int sz = A.size();
    SqMatrix res(SqMatrix::identity(sz));
    
    while (n > 0) {
        if (n & 1) {
            res = res * A;
        }
        A = A * A;
        n >>= 1;
    }
    
    return res;
}

string to_str(long long x) {
    ostringstream os;
    os << x;
    return os.str();
}
class AntOnGraph {
	public:
	string maximumBonus(vector <string> p0, vector <string> p1, vector <string> p2, int stepsPerSecond, int timeLimit) {
        const int n = p0.size();
		SqMatrix A(n);
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                int x = (p0[i][j]-'0')*100 + (p1[i][j]-'0')*10 + (p2[i][j]-'0') - 500;
                A(i, j) = (x==-500 ? -INF : x);
            }
        }
        
        A = to_the(A, stepsPerSecond);
        if (A(1, 1) < 0) {
            A(1, 1) = 0;
        }
        A = to_the(A, timeLimit);
        
        return (A(0, 1)>-INF ? to_str(A(0, 1)) : string("IMPOSSIBLE"));
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"05","50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00","00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"01","10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 2; string Arg5 = "3"; verify_case(0, Arg5, maximumBonus(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"05","50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00","00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"01","10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 3; string Arg5 = "IMPOSSIBLE"; verify_case(1, Arg5, maximumBonus(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"0550","0000","0005","5000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0000","0000","0000","0000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0110","0000","0001","1000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; int Arg4 = 9; string Arg5 = "49"; verify_case(2, Arg5, maximumBonus(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"0540","0000","0004","4000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0090","0000","0009","9000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0190","0000","0009","9000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; int Arg4 = 9; string Arg5 = "-5"; verify_case(3, Arg5, maximumBonus(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"079269665406","506042219642","720809987956",
 "315099331918","952306192584","406390344278",
 "999241035142","370785209189","728363760165",
 "019367419000","279718007804","610188263490"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"038604914953","804585763146","350629473403",
 "028096403898","575205051686","427800322647",
 "655168017864","582553303278","980402170192",
 "620737714031","686142310509","092421645460"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"063231394554","109852259379","740182746422",
 "853015982521","476805512496","898530717993",
 "430534005863","440162807186","132879980431",
 "685312177072","780267345400","959947501200"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 37; int Arg4 = 1221; string Arg5 = "20992235"; verify_case(4, Arg5, maximumBonus(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AntOnGraph ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
