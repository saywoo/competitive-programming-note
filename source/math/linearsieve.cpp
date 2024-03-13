
// primeCheck[n] == 0 : n이 소수
// primeCheck[n] != 0 : n의 최소 소인수
int primeCheck[5005000];
vector<int> primeNum;

void LinearSieve() {
    for (int i = 2; i <= 5000000; i++) {
        if (!primeCheck[i]) primeNum.emplace_back(i);

        for (auto j: primeNum) {
            if (i * j > 5000000) break;
            primeCheck[i*j] = j;
            if (i % j == 0) break;
        }
    }
}