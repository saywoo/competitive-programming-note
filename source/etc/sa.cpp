
double t, d, k, lim, local_pow;
int local_ans = 1e9;

void reset_sa() {
    t = 1, d = 0.9999, k = 4, lim = 0.005; 
    local_pow = 0;
}

int scoring() {

}

void simulated_annealing() {
    reset_sa(); int e1, e2;
    e1 = scoring();

    while (t > lim) {
        // 현재 상태를 백업 후, 상태를 변형

        // 상태를 변형한 후, e2로 점수 측정
        e2 = scoring();

        if (e2 < local_ans) {
            local_pow = 0; local_ans = e2;

            e1 = e2;
        }
        else local_pow++;

        double p = exp((e1 - e2) / (t * k * log(local_pow)));
        if (p < Rand.randDouble(0, 1)) {
            // 복구   
        }
        else e1 = e2;
        t *= d;
    }
}