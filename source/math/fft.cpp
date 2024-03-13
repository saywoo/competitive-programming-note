
typedef complex<double> cp;
const double PI = acos(-1);

void FFT(vector<cp> &v, bool inv) {
    int siz = v.size();

    for (int i = 1, j = 0; i < siz; i++) {
        int bit = siz >> 1;
        while(!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(v[i], v[j]);
    }

    for (int k = 1; k < siz; k <<= 1) {
        double a = (inv ? PI / k : -PI / k);
        cp w(cos(a), sin(a));

        for (int i = 0; i < siz; i += (k << 1)) {
            cp z(1, 0);

            for (int j = 0; j < k; j++) {
                cp even = v[i+j], odd = v[i+j+k];

                v[i+j] = even + z * odd;
                v[i+j+k] = even - z * odd;

                z *= w; 
            }
        }
    }

    if (inv) {
        for (int i = 0; i < siz; i++) v[i] /= siz;
    }
}

// multiply(a, b) : 다항식 a, b의 convolution을 반환
vector<int> multiply(vector<int> &a, vector<int> &b) {
    vector<cp> A(a.begin(), a.end());
    vector<cp> B(b.begin(), b.end());

    int siz = 2;
    while (siz < A.size() + B.size()) siz <<= 1;

    A.resize(siz); FFT(A, false);
    B.resize(siz); FFT(B, false);

    for (int i = 0; i < siz; i++) A[i] *= B[i];
    FFT(A, true);

    vector<int> res(siz);
    for (int i = 0; i < siz; i++) res[i] = round(A[i].real());

    return res;
}