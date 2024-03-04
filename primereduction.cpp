#include <cstdio>
#include <vector>
#include <cmath>

std::vector<int> primes;

bool isPrime(int n) {
    if(n <= 1)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    for(int i = 3; i <= std::sqrt(n); i+=2) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int smallestPrime(int n) {
    for(int i : primes) {
        if(n % i == 0)
            return i;
    }
    return n;
}

void calc(int n, int t) {
    t++;
    if(isPrime(n)) {
        printf("%d %d\n", n, t);
        return;
    }

    int sum = 0;
    while (n != 1) {
        int sp = smallestPrime(n);
        n = n / sp;
        sum += sp;
    }
    calc(sum, t);
}

int main() {
    // input data and keep track of max
    std::vector<int> input;
    int max = -1;
    while(1) {
        int t;
        scanf("%d", &t);
        if(t == 4)
            break;
        max = std::max(max, t);
        input.push_back(t);
    }

    // find all primes
    for(int i = 0; i <= std::sqrt(max); i++) {
        if(isPrime(i))
            primes.push_back(i);
    }

    for(int i : input) {
        if(i == 76) {
            double x;
        }
        calc(i, 0);
    }
}
