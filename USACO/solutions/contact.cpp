/*
ID: ivan.bu1
PROG: contact
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
#include <numeric>

using namespace std;

struct Item {
    int f, len, mask;
    Item(int f_=0, int len_=0, int mask_=0): f(f_), len(len_), mask(mask_) {}
    string repr() const {
        string ret;
        for (int i=0; i<len; ++i) {
            ret += (mask&(1<<i)) ? "1" : "0";
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
bool operator<(const Item &a, const Item &b) {
    if (a.f != b.f) {
        return a.f > b.f;
    } else if (a.len != b.len) {
        return a.len < b.len;
    } else {
        return a.mask < b.mask;
    }
}

int cnt[13][1<<12];
int main() {
	ifstream fin("contact.in");
    int a, b, N;
    fin >> a >> b >> N;
    vector<string> tmp;
    copy(istream_iterator<string>(fin), istream_iterator<string>(), back_inserter(tmp));
    fin.close();
    string S = accumulate(tmp.begin(), tmp.end(), string());
    int a_mask = (1<<a)-1;
    
    if (a <= (int)S.size()) {
        int mask = 0;
        for (int i=0; i<a-1; ++i) {
            mask = (mask<<1) + (S[i]=='1');
        }
        int start = 0;
        while (start+a <= (int)S.size()) {
            mask = ((mask<<1)&a_mask) + (S[start+a-1]=='1');
            ++cnt[a][mask];
            int tmp_mask = mask;
            for (int i=0; i<b-a && start+a+i<(int)S.size(); ++i) {
                tmp_mask = (tmp_mask<<1) + (S[start+a+i]=='1');
                ++cnt[a+i+1][tmp_mask];
            }
            ++start;
        }
    }

    vector<Item> v;
    for (int i=a; i<=b; ++i) {
        for (int mask=0; mask<(1<<i); ++mask) {
            if (cnt[i][mask]) {
                v.push_back(Item(cnt[i][mask], i, mask));
            }
        }
    }
    sort(v.begin(), v.end());
    
    ofstream fout("contact.out");
    for (int i=0; i<(int)v.size(); ++i) {
        if (N-- == 0) {
            break;
        }
        int f = v[i].f;
        fout << f << '\n';
        int j = i;
        int counter = 0;
        while (j<(int)v.size() && v[j].f==f) {
            if (counter == 6) {
                counter = 0;
                fout << '\n';
            }
            if (++counter > 1) {
                fout << ' ';
            }
            fout << v[j].repr();
            ++j;
        }
        fout << '\n';
        i = j-1;
    }
    fout.close();

	return 0;
}

