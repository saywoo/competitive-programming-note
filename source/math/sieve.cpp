
// primeCheck[n] == 0 : n이 소수
// primeCheck[n] != 0 : n의 최소 소인수
int primeCheck[5005000];

void Sieve() {
    for (int i = 2; i <= sqrt(5000000); i++) {
        if (primeCheck[i]) continue;
        for (int j = i * i; j <= 5000000; j += i) {
            if (!primeCheck[j]) primeCheck[j] = i;
        }
    }
}