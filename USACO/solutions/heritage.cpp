/*
ID: ivan.bu1
PROG: heritage
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

using namespace std;

string preorder, inorder;
int n;

string solve(int pl, int pr, int il, int ir) {
    if (pl >= pr) {
        return "";
    }
    char root = preorder[pl];
    int pos = inorder.find(root);
    string L = solve(pl+1, pl+1+pos-il, il, pos);
    return L + solve(pl+1+pos-il, pr, pos+1, ir) + root;
}
int main() {
	ifstream fin("heritage.in");
    fin >> inorder >> preorder;
    fin.close();
    n = preorder.size();

    ofstream fout("heritage.out");
    fout << solve(0, n, 0, n) << '\n';
    fout.close();

	return 0;
}
