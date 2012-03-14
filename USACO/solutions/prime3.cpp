/*
ID: ivan.bu1
PROG: prime3
LANG: C++
*/
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstring>
#include <sstream>
#include <cassert>

using namespace std;

#define MAXPRIME 100000
int P[(MAXPRIME>>6) + 1];
inline bool is_prime_fast(int x) { return !((P[x>>6]>>((x>>1)&0x1F))&1); }
inline bool is_prime(int x) { return x==2 ? true : !(x&1)||x<2 ? false : is_prime_fast(x); }
void mark_nonprime(int x) { P[x>>6] |= (1<<((x>>1)&0x1F)); }
void init_primes() {
    for (int x=3; x<=MAXPRIME/x; x+=2) {
        if (is_prime_fast(x)) {
            const int z = x<<1;
            for (int y=x*x; y<=MAXPRIME; y+=z) {
                mark_nonprime(y);
            }
        }
    }
}

vector<int> primes;
vector<string> prime_str;
vector<int> first_inds;
vector< vector< vector<short> > > cands; // [i][j] list of primes with i+1 digit prefix = j
int A[5];

bool first = true;
void printstr(const string &fifth, ofstream &fout) {
    if (!first) {
        fout << '\n';
    }
    first = false;
    for (int i=0; i<4; ++i) {
        fout << prime_str[A[i]] << '\n';
    }
    fout << fifth << '\n';
}

int main() {
    int digsum, dig00;
	ifstream fin("prime3.in");
    fin >> digsum >> dig00;
    fin.close();

    init_primes();
    for (int i=10001; i<100000; i+=2) {
        if (is_prime_fast(i)) {
            ostringstream os;
            os << i;
            const string s = os.str();
            assert(s.size() == 5);
            int dsum = 0;
            for (int j=0; j<(int)s.size(); ++j) {
                dsum += s[j] - '0';
            }
            if (dsum == digsum) {
                primes.push_back(i);
                prime_str.push_back(s);
                if (s[0]-'0'==dig00 && s.find('0')==string::npos) {
                    first_inds.push_back((int)primes.size()-1);
                }
            }
        }
    }
    
    int pot10 = 10;
    for (int i=1; i<=5; ++i) {
        cands.push_back(vector< vector<short> >(pot10, vector<short>()));
        pot10 *= 10;

        for (int j=0; j<(int)primes.size(); ++j) {
            int prefix = 0;
            for (int k=0; k<i; ++k) {
                prefix = prefix*10 + prime_str[j][k]-'0';
            }
            cands.back()[prefix].push_back(j);
        }
    }
    
    string e(5, '0');
    vector<int> p(5);
    const vector< vector<short> > &C1 = cands[1];
    ofstream fout("prime3.out");
    for (int x=0; x<(int)first_inds.size(); ++x) { // row1
        A[0] = first_inds[x];
        for (int y=0; y<(int)primes.size(); ++y) { // row2
            A[1] = y;
            int diag_prefix = 10*(prime_str[A[0]][0]-'0') + prime_str[y][1]-'0';
            if (!C1[diag_prefix].size()) {
                continue;
            }
            bool ok = true;
            for (int j=0; j<5; ++j) {
                int prefix = 0;
                for (int i=0; i<2; ++i) {
                    prefix = prefix*10 + prime_str[A[i]][j]-'0';
                }
                if (!C1[prefix].size()) {
                    ok = false;
                    break;
                }
                p[j] = prefix;
            }
            if (!ok) {
                continue;
            }
            const int diag2_back = 10*(prime_str[y][3]-'0') + prime_str[A[0]][4]-'0';
            for (int i=0; i<(int)C1[p[0]].size(); ++i) { // col1
                const string &a = prime_str[C1[p[0]][i]];
                if (a.find('0') != string::npos) {
                    continue;
                }
                for (int j=0; j<(int)C1[p[1]].size(); ++j) { // col2
                    const string &b = prime_str[C1[p[1]][j]];
                    ok = true;
                    for (int r=2; r<5; ++r) {
                        int prefix = 10*(a[r]-'0') + b[r]-'0';
                        if (!C1[prefix].size()) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        continue;
                    }
                    
                    const int diag2_front = 10000*(a[4]-'0') + 1000*(b[3]-'0');
                    const int prefix3 = 10*(a[2]-'0') + b[2]-'0';
                    const int prefix4 = 10*(a[3]-'0') + b[3]-'0';
                    const vector< short > &C3 = C1[prefix3];
                    const vector< short > &C4 = C1[prefix4];
                    for (int k=0; k<(int)C3.size(); ++k) { // row3
                        const string &c = prime_str[C3[k]];
                        A[2] = C3[k];
                        if (!cands[2][diag_prefix*10 + c[2]-'0'].size()
                            ||
                            !cands[4][diag2_front + 100*(c[2]-'0') + diag2_back].size()) {
                            goto NEXT_ROW3;
                        }
                        for (int col=0; col<5; ++col) {
                            int prefix = p[col]*10 + c[col]-'0';
                            if (!cands[2][prefix].size()) {
                                goto NEXT_ROW3;
                            }
                        }
                        for (int l=0; l<(int)C4.size(); ++l) { // row4
                            const string &d = prime_str[C4[l]];
                            if (!cands[3][diag_prefix*100 + 10*(c[2]-'0') + d[3]-'0'].size()) {
                                continue; // goto NEXT_ROW4
                            }
                            A[3] = C4[l];
                            int need = 0;
                            int nsum = 0;
                            for (int j=0; j<5; ++j) {
                                int sum = 0;
                                for (int i=0; i<4; ++i) {
                                    sum += prime_str[A[i]][j]-'0';
                                }
                                if (sum>digsum || digsum-sum>=10 || (j==0 && sum==digsum)) {
                                    need = -1;
                                    break;
                                }
                                need = need*10 + (digsum-sum);
                                nsum += digsum-sum;
                                e[j] = (digsum-sum) + '0';
                            }
                            if (need==-1 || nsum!=digsum || !is_prime(need)) {
                                continue; // goto NEXT_ROW4
                            }
                            if (!cands[4][diag_prefix*1000 + 100*(c[2]-'0') + 10*(d[3]-'0') + e[4]-'0'].size()) {
                                continue; // goto NEXT_ROW4
                            }
                            for (int j=0; j<5; ++j) {
                                if (!cands[4][p[j]*1000 + 100*(c[j]-'0') + 10*(d[j]-'0') + e[j]-'0'].size()) {
                                    goto NEXT_ROW4;
                                }
                            }
                            { // block so gotos are possible
                                int diag2 = e[0]-'0';
                                for (int i=1; i<5; ++i) {
                                    diag2 = diag2*10 + prime_str[A[4-i]][i]-'0';
                                }
                                if (!cands[4][diag2].size()) {
                                    goto NEXT_ROW4;
                                }
                            }
                            printstr(e, fout);
                            NEXT_ROW4:;
                        }
                        NEXT_ROW3:;
                    }
                }
            }
        }
    }

    if (first) {
        fout << "NONE\n";
    }
    fout.close();

    return 0;
}
