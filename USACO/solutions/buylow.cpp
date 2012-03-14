/*
ID: ivan.bu1
PROG: buylow
LANG: C++
*/
#include <cassert>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <set>
#include <sstream>

using namespace std;

int n;
unsigned A[5000];
int len[5000];
const int base = 1000000000;
vector<int> cnt[5000];

string to_str(const vector<int> &v) {
    ostringstream os;
    for (int i=(int)v.size()-1; i>=0; --i) {
        ostringstream os2;
        os2 << v[i];
        const string s = os2.str();
        if (i+1 < (int)v.size()) {
            os << string(9-s.size(), '0');
        }
        os << s;
    }
    return os.str();
}
void inc(vector<int> &a, const vector<int> &b) {
    int carry = 0;
    for (int i=0; i<(int)b.size() || carry; ++i) {
        if (i == (int)a.size()) {
            a.push_back(0);
        }
        a[i] += (i<(int)b.size() ? b[i] : 0) + carry;
        if (a[i] >= base) {
            a[i] -= base;
            carry = 1;
        } else {
            carry = 0;
        }
    }
}
int main() {
	ifstream fin("buylow.in");
    fin >> n;
    for (int i=0; i<n; ++i) {
        fin >> A[i];
    }
    fin.close();
    
    int maxlen = 0;
    for (int i=0; i<n; ++i) {
        len[i] = 1;
        for (int j=0; j<i; ++j) {
            if (A[j]>A[i] && len[j]+1>len[i]) {
                len[i] = len[j] + 1;
            }
        }
        maxlen = max(maxlen, len[i]);

        cnt[i].assign(1, 0);
        if (len[i] == 1) {
            cnt[i][0] = 1;
        } else {
            set<unsigned> used;
            for (int j=i-1; j>=0; --j) {
                if (A[j]>A[i] && len[i]==len[j]+1 && !used.count(A[j])) {
                    used.insert(A[j]);
                    inc(cnt[i], cnt[j]);
                }
            }
        }
    }

    vector<int> sol(1, 0);
    set<unsigned> used;
    for (int i=n-1; i>=0; --i) {
        if (len[i]==maxlen && !used.count(A[i])) {
            used.insert(A[i]);
            inc(sol, cnt[i]);
        }
    }

    ofstream fout("buylow.out");
    fout << maxlen << ' ' << to_str(sol) << '\n';
    fout.close();

	return 0;
}
