
// 선언: Trie* root = new Trie;
// 추가: root->Insert(문자열.c_str());
// 찾기: root->Find(문자열.c_str());
// 삭제: root->Delete(문자열.c_str());

struct Trie {
    int child_num;
    bool finish;
    Trie* next[26];

    Trie() {
        child_num = 0;
        finish = false;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (next[i]) delete next[i];
        }
    }
    void Insert(const char* s) {
        child_num++;

        if (!*s) {
            this->finish = true;
            return;
        }

        int now = *s - 'A';
        if (!next[now]) next[now] = new Trie;
        next[now]->Insert(s + 1);
    }
    bool Find(const char* s) {
        if (!*s) return this->finish;

        int now = *s - 'A';
        if (!next[now]) return false;
        return next[now]->Find(s + 1);
    }
    bool Delete(const char* s) {
        this->child_num--;
        
        if (!*s) this->finish = false;
        else {
            int now = *s - 'A';
            if (!next[now]->Delete(s + 1)) {
                delete next[now];
                next[now] = nullptr;
            }
        }
        return this->child_num;
    }
};