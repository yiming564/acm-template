#include <bits/extc++.h>
#include <span>
#include <vector>

constexpr int MaxN = 1e5 + 5, MaxSGT = MaxN * 2;

struct SegTree {
    int son[MaxSGT][2], top = 2;
    struct Info {
        // replace it with your own payload.
        friend inline Info operator+(const Info &x, const Info &y) {
            return Info{}; // replace it with your own logic.
        }
    } info[MaxSGT];
    inline int &lson(int u) { return son[u][0]; }
    inline int &rson(int u) { return son[u][1]; }
    inline void PushUp(int u) { info[u] = info[lson(u)] + info[rson(u)]; }
    inline void Build(int u, int l, int r, std::span<const Info> x) {
        if (r - l == 1) return void(info[u] = x[l]);
        Build(lson(u) = top++, l, l + r >> 1, x);
        Build(rson(u) = top++, l + r >> 1, r, x);
        PushUp(u);
    }
    inline Info Query(int u, int l, int r, int pl, int pr) {
        if (pl <= l && r <= pr) return info[u];
        int mid = l + r >> 1; Info ans{};
        if (pl < mid) ans = ans + Query(lson(u), l, mid, pl, pr);
        if (mid < pr) ans = ans + Query(rson(u), mid, r, pl, pr);
        return ans;
    }
    inline void Set(int u, int l, int r, int x, const Info &v) {
        if (r - l == 1) return void(info[u] = v);
        int mid = l + r >> 1;
        if (x < mid) Set(lson(u), l, mid, x, v);
        else Set(rson(u), mid, r, x, v);
        PushUp(u);
    }
} tree;

int n;
std::vector<SegTree::Info> x;

int main() {
    tree.Build(1, 1, n, x);
    return 0;
}
