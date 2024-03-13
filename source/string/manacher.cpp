
// 각 문자를 중심으로 하는 최장 팰린드롬의 길이를 반환
// Manacher("ASDDSA") = {0, 1, 0, 1, 0, 1, 6, 1, 0, 1, 0, 1, 0}
vector<int> Manacher(string &s) {
    int n = s.length() * 2 + 1;
    vector<int> ret(n);
    string tmp = "#";

    for (auto i: s) {
        tmp += i; tmp += '#';
    }

    for (int i = 0, p = -1, r = -1; i < n; i++) {
        if (i <= r) ret[i] = min(r - i, ret[2*p-i]);
        else ret[i] = 0;
        
        while (i - ret[i] - 1 >= 0 && i + ret[i] + 1 < n && tmp[i-ret[i]-1] == tmp[i+ret[i]+1]) ret[i]++;
        if (i + ret[i] > r) { 
            r = i + ret[i]; p = i;
        }
    }

    return ret;
}
