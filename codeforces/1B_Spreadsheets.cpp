#include <cstdio>

char S[64], buff[32];

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i=0; i<n; ++i) {
        int r, c;
        scanf("%s", &S);
        if (sscanf(S, "R%dC%d", &r, &c) == 2) {
            int x = c--;
            int j = 0;
            while (x > 0) {
                x = (x-1)/26;
                ++j;
            }
            buff[j--] = '\0';
            while (j >= 0) {
                buff[j--] = 'A' + c%26;
                c = c/26 - 1;
            }
            printf("%s%d\n", buff, r);
        } else {
            sscanf(S, "%[^0123456789]%d", buff, &r);
            int c = 0;
            char *p = buff;
            while (*p) {
                c = 26*c + (*p++-'A'+1);
            }
            printf("R%dC%d\n", r, c);
        }
    }

    return 0;
}
