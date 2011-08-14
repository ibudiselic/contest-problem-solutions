/*
ID: ivan.bu1
PROG: checker
LANG: C
*/
#include <stdio.h>

int sol;
int n;
int cols[14];
int sum[28];
int diff[28];
int cur[14];
int bp;
FILE *fin, *fout;
void go(int row) {
    int a, b, i;
    if (!row) {
        if (++sol <= 3) {
            for (i=n; i>0; --i) {
                fprintf(fout, "%d%c", cur[i]+1, (i>1 ? ' ' : '\n'));
            }
        }
        return;
    }
    
    a = row;
    b = row + n;
    for (i=0; i<n; ++i, ++a, --b) {
        if (cols[i] + sum[a] + diff[b] == 0) {
            cols[i] = sum[a] = diff[b] = 1;
            cur[row] = i;
            go(row-1);
            cols[i] = sum[a] = diff[b] = 0;
        }
    }
}
int main(void) {
    fout = fopen("checker.out", "w");
    fin = fopen("checker.in", "r");
    fscanf(fin, "%d", &n);
    fclose(fin);

    go(n);
    fprintf(fout, "%d\n", sol);
    fclose(fout);

	return 0;
}
