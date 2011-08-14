/*
ID: ivan.bu1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

/*
    * #1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.
    * #2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.
    * #3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.
    * #4: Reflection: The pattern was reflected horizontally (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image).
    * #5: Combination: The pattern was reflected horizontally and then subjected to one of the rotations (#1-#3).
    * #6: No Change: The original pattern was not changed.
    * #7: Invalid Transformation: The new pattern was not obtained by any of the above methods.
*/
void rot90(int n, vector<string> &v) {
	vector<string> t = v;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			v[j][n-1-i] = t[i][j];
}
void reflect(int n, vector<string> &v) {
	for (int i=0; i<n; ++i)
		for (int j=0; j<n/2; ++j)
			swap(v[i][j], v[i][n-1-j]);
}
int main() {
	ifstream fin("transform.in");
    ofstream fout("transform.out");

	int N;
	fin >> N;

	vector<string> in(N, string());
	vector<string> out(N, string());
	getline(fin, in[0]);

	for (int i=0; i<N; ++i)
		getline(fin, in[i]);

	for (int i=0; i<N; ++i)
		getline(fin, out[i]);

	for (int i=1; i<=3; ++i) {
		rot90(N, in);
		if (in == out) {
			fout << i << '\n';
			return 0;
		}
	}
	rot90(N, in);

	reflect(N, in);
	if (in == out) {
		fout << 4 << '\n';
		return 0;
	}

	for (int i=0; i<3; ++i) {
		rot90(N, in);
		if (in == out) {
			fout << 5 << '\n';
			return 0;
		}
	}
	rot90(N, in);

	if (in == out)
		fout << 6 << '\n';
	else
		fout << 7 << '\n';

	return 0;
}
