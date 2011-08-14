/*
ID: ivan.bu1
PROG: runround
LANG: C++
*/
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>

using namespace std;

class Chooser {
    public:
    Chooser(int k_, const vector<int> &items_): k(k_), n(items_.size()), items(items_) {
        assert(k <= (int)items.size());
        is_used.assign(items.size(), 0);
        used_indices.assign(k, 0);
        for (int i=0; i<k; ++i) { // choose first k items first
            is_used[i] = true;
            used_indices[i] = i;
        }
    }
    int size() const { return k; }
    int operator[](int i) const { return items[used_indices[i]]; }
    bool is_item_index_used(int i) const { return is_used[i]; }
    bool next() {
        int passed_ones = 0;
        for (int i=0; i<n; ++i) {
            // in effect looking for the first unused item after the first used item
            if (is_used[i]) { 
                if (i == n-1) { // last k items used (last combination)
                    return false;
                }
                is_used[i] = false;
                if (is_used[i+1]) {
                    ++passed_ones;
                } else {
                    is_used[i+1] = true;
                    used_indices[passed_ones] = i+1;
                    break;
                }
            }
        }
        for (int i=0; i<passed_ones; ++i) {
            is_used[i] = true;
            used_indices[i] = i;
        }
        return true;
    }
    private:
    int k, n;
    vector<int> items;
    vector<int> is_used;
    vector<int> used_indices;
};
    
long long get_max_val(const Chooser &chooser) {
    long long ret = 0;
    for (int i=chooser.size()-1; i>=0; --i) {
        ret = ret*10 + chooser[i];
    }
    return ret;
}
long long get_val(const vector<int> &v) {
    long long ret = 0;
    for (int i=0; i<(int)v.size(); ++i) {
        ret = ret*10 + v[i];
    }
    return ret;
}
bool runaround(const vector<int> &v) {
    bool used[10] = {0};
    int pos = 0;
    int total = 0;
    while (total++ < (int)v.size()) {
        if (used[pos]) {
            return false;
        }
        used[pos] = true;
        int x = v[pos];
        pos = (pos+x)%v.size();
    }
    return (pos==0);
}

int n;
long long INF = 1234567890123LL;
long long calc(int k, const vector<int> &v) {
    long long ret_val = INF;
    Chooser chooser(k, v);
    do {
        long long val = get_max_val(chooser);
        if (val <= n) {
            continue;
        }
        vector<int> tmp;
        for (int i=0; i<chooser.size(); ++i) {
            tmp.push_back(chooser[i]);
        }
        do {
            val = get_val(tmp);
            if (val<=n || val>=ret_val) {
                continue;
            }
            if (runaround(tmp)) {
                ret_val = val;
            }
        } while (next_permutation(tmp.begin(), tmp.end()));
    } while (chooser.next());

    return ret_val==INF ? -1 : ret_val;
}

int main() {
	ifstream fin("runround.in");
    fin >> n;
    fin.close();
    ofstream fout("runround.out");
    ostringstream os;
    os << n;
    string s = os.str();
    vector<int> v;
    for (int i=1; i<10; ++i) {
        v.push_back(i);
    }
    long long ret = calc(s.size(), v);
    int sz = s.size();
    while ((ret = calc(sz, v)) == -1) {
        ++sz;
    }
    
    fout << ret << '\n';
    fout.close();
	return 0;
}

