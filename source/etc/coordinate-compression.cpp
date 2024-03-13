
typedef long long int ll;

// comp : 압축한 좌표값들을 저장
vector<ll> comp;

void CoordComp(vector<ll> &v)
{
    for (auto i: v) comp.emplace_back(i);

    // 좌표를 압축
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    // 원래 값을 재인덱싱
    for (int i = 0; i < v.size(); i++) {
        v[i] = lower_bound(comp.begin(), comp.end(), v[i]) - comp.begin();
    }
}