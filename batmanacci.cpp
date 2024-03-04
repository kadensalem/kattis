#include<cstdio>
#include <algorithm>
int main() {
    // Scan inputs
    unsigned long long n, k;
    scanf("%llu %llu", &n, &k);

    // To store the fibonacci sequence
    unsigned long long f[100001];

    // Calculate all fibonacci numbers up to n
    f[1] = 1, f[2] = 1;
    for(int i = 3; i < n+1; i++) {
        f[i] = f[i-2] + f[i-1];
        if(f[i] > k)
            f[i] = k;
    }

    // Go down the sequence
    while(n > 2) {
        if(k <= f[n-2]) {
            // kth letter is from n-2 
            n-=2;
        }
        else {
            // kth letter is from n-1
            k-=f[n-2];
            n-=1;
        }
    }

    // n is either 1 or 2 at this point --> print
    if(n == 1)
        printf("%c", 'N');
    else
        printf("%c", 'A');
}
