/*
ID: ivan.bu1
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>

using namespace std;

string digs = "IVXLCDM";
int dig_vals[] = { 1, 5, 10, 50, 100, 500, 1000 };

#define SPECIALS_COUNT 6
int specials_vals[SPECIALS_COUNT] = { 4, 9, 40, 90, 400, 900 };
const char *specials[] = { "IV", "IX", "XL", "XC", "CD", "CM" };
int cnt[256];
int main() {
	ifstream fin("preface.in");
    int n;
    fin >> n;
    fin.close();

    int t = n;
    for (int num=1; num<=t; ++num) {
        n = num;
        while (n > 0) {
            int largest_special = SPECIALS_COUNT - 1;
            while (largest_special>=0 && n<specials_vals[largest_special]) {
                --largest_special;
            }
            int largest_dig = digs.size()-1;
            while (largest_dig>=0 && n<dig_vals[largest_dig]) {
                --largest_dig;
            }
            if (largest_special!=-1 && specials_vals[largest_special]>dig_vals[largest_dig]) {
                n -= specials_vals[largest_special];
                for (int i=0; i<2; ++i) {
                    ++cnt[specials[largest_special][i]];
                }
            } else {
                int how_many = n/dig_vals[largest_dig];
                n -= how_many * dig_vals[largest_dig];
                cnt[digs[largest_dig]] += how_many;
            }
        }
    }

    vector<int> vals;
    int largest_used = -1;
    for (int i=0; i<(int)digs.size(); ++i) {
        vals.push_back(cnt[digs[i]]);
        if (vals.back() > 0) {
            largest_used = i;
        }
    }
    ofstream fout("preface.out");
    for (int i=0; i<=largest_used; ++i) {
        fout << digs[i] << ' ' << vals[i] << '\n';   
    }
    fout.close();

	return 0;
}
