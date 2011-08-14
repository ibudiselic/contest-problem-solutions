#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
 * MODULAR ARITHMETIC
 * NO ERROR CHECKING!
 * optimized for speed, not robustness
 */
typedef long long matrix_type_;
const matrix_type_ MOD = 1000000007;
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
        A.init(0);
        for (int i=0; i<n; ++i) {
            A(i, i) = 1;
        }
        return A;
    }
    
    void init(matrix_type_ val) {
        val %= MOD;
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

SqMatrix operator+(const SqMatrix &A, const SqMatrix &B) {
    assert(A.size() == B.size());
    const int n = A.size();
    SqMatrix C(n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            C(i, j) = A(i, j) + B(i, j);
            if (C(i, j) >= MOD) {
                C(i, j) -= MOD;
            }
        }
    }
    return C;
}

SqMatrix operator*(const SqMatrix &A, const SqMatrix &B) {
    assert(A.size() == B.size());
    const int n = A.size();
    SqMatrix C(n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            C(i, j) = 0;
            for (int k=0; k<n; ++k) {
                C(i, j) += A(i, k) * B(k, j);
                if (C(i, j) >= MOD) {
                    C(i, j) %= MOD;
                }
            }
        }
    }
    return C;
}
// multiply by row-vector (result is a row-vector)
vector<matrix_type_> operator*(const vector<matrix_type_> &v, const SqMatrix &A) {
    const int n = v.size();
    assert(A.size() == n);
    vector<matrix_type_> res(n);
    for (int j=0; j<n; ++j) {
        for (int k=0; k<n; ++k) {
            res[j] += v[k] * A(k, j);
            if (res[j] >= MOD) {
                res[j] %= MOD;
            }
        }
    }
    return res;
}
// multiply by column-vector (result is a column-vector)
vector<matrix_type_> operator*(const SqMatrix &A, const vector<matrix_type_> &v) {
    const int n = v.size();
    assert(A.size() == n);
    vector<matrix_type_> res(n);
    for (int i=0; i<n; ++i) {
        for (int k=0; k<n; ++k) {
            res[i] += A(i, k) * v[k];
            if (res[i] >= MOD) {
                res[i] %= MOD;
            }
        }
    }
    return res;
}
// nth power O(lg n)
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

int bc(int x) {
    int ret = 0;
    while (x > 0) {
        x &= (x-1);
        ++ret;
    }
    return ret;
}
long long lcm(long long m, long long n) {
    return m/__gcd(m, n) * n;
}
SqMatrix I = SqMatrix::identity(6);
SqMatrix calc(long long len, const SqMatrix &A) {
    assert(len > 0);
    if (len == 1) {
        return A;
    } else if (len & 1) {
        return A * (calc(len-1, A) + I);
    } else {
        return calc(len/2, A) * (I + to_the(A, len/2));
    }
}
long long calc(long long len, const SqMatrix &A, vector<long long> v) {
    SqMatrix B = calc(len, A);
    return (B * v)[5];
}
class AvoidFour {
	public:
	int count(long long n) {
        if (n == 1) {
            return 9;
        } else if (n == 2) {
            return 99;
        }
        SqMatrix A(6);
		A(0, 0) = 1; A(0, 1) = 1; A(0, 2) = 1; A(0, 3) = 1; A(0, 4) = 1; A(0, 5) = 0;
        A(1, 0) = 8; A(1, 1) = 8; A(1, 2) = 8; A(1, 3) = 8; A(1, 4) = 8; A(1, 5) = 0;
        A(2, 0) = 1; A(2, 1) = 1; A(2, 2) = 0; A(2, 3) = 0; A(2, 4) = 0; A(2, 5) = 0;
        A(3, 0) = 0; A(3, 1) = 0; A(3, 2) = 1; A(3, 3) = 0; A(3, 4) = 0; A(3, 5) = 0;
        A(4, 0) = 0; A(4, 1) = 0; A(4, 2) = 0; A(4, 3) = 1; A(4, 4) = 0; A(4, 5) = 0;
        A(5, 0) = 9; A(5, 1) = 9; A(5, 2) = 9; A(5, 3) = 9; A(5, 4) = 8; A(5, 5) = 0;

        vector<long long> v;
        v.push_back(1);
        v.push_back(0);
        v.push_back(0);
        v.push_back(0);
        v.push_back(0);
        v.push_back(0);
        
        long long sol = (calc(n, A) * v)[5];
        
        vector<long long> lens;
        long long cur = 44;
        while (cur <= n) {
            lens.push_back(cur);
            cur = cur*10 + 4;
        }
        const int len_cnt = lens.size();
        for (int mask=1; mask<(1<<len_cnt); ++mask) {
            int sgn = (bc(mask)&1 ? -1 : 1);
            long long val = 1;
            for (int i=0; i<len_cnt; ++i) {
                if ((mask>>i) & 1) {
                    val = lcm(val, lens[i]);
                    if (val > n) {
                        val = n+1;
                        break;
                    }
                }
            }
            if (val <= n) {
                sol = (sol + sgn*calc(n/val, to_the(A, val), v) + MOD) % MOD;
            }
        }
        
        return sol;
	}





   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; int Arg1 = 9998; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { long long Arg0 = 5LL; int Arg1 = 99980; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { long long Arg0 = 87LL; int Arg1 = 576334228; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { long long Arg0 = 88LL; int Arg1 = 576334228; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { long long Arg0 = 4128LL; int Arg1 = 547731225; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AvoidFour ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
