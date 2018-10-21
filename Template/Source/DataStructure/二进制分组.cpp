/*
	【UOJ #46】 【清华集训2014】玄学
	二进制分组的思想。
	用线段树维护时间的操作序列，每次操作一个一个往线段树里面插，等到一个线段被插满的时候用归并来维护区间的信息。查询的时候如果一个线段没有被插满就递归下去。定位到一个区间的时候在区间里面归并出来的信息二分。
*/
#include <cstdio>

#define maxn 100010
#define maxm 600010
#define R register
int x[maxn], tnum;
struct Seg {
    int l, r, a, b;
} p[maxn * 200];
int lef[maxm << 2], rig[maxm << 2], pcnt, ta, tb, ql, qr, n, m, k, ans;
void update(R int o, R int l, R int r)
{
    lef[o] = pcnt + 1;
    for (R int i = lef[o << 1], j = lef[o << 1 | 1], head = 1; i <= rig[o << 1] || j <= rig[o << 1 | 1]; )
        if (p[i].r <= p[j].r)
        {
            p[++pcnt] = (Seg) {head, p[i].r, 1ll * p[i].a * p[j].a % m, (1ll * p[j].a * p[i].b + p[j].b) % m};
            head = p[i].r + 1;
            p[i].r == p[j].r ? ++j : 0; ++i;
        }
        else
        {
            p[++pcnt] = (Seg) {head, p[j].r, 1ll * p[i].a * p[j].a % m, (1ll * p[j].a * p[i].b + p[j].b) % m};
            head = p[j].r + 1; ++j;
        }
    rig[o] = pcnt;
}
int find(R int o, R int t, R int &s)
{
    R int l = lef[o], r = rig[o];
    while (l < r)
    {
        R int mid = l + r >> 1;
        if (t <= p[mid].r) r = mid;
        else l = mid + 1;
    }
//    printf("%d %d t %d s %d %d %d\n", p[l].l, p[l].r, t, s, p[l].a, p[l].b);
    s = (1ll * s * p[l].a + p[l].b) % m;
}
void modify(R int o, R int l, R int r, R int t)
{
    if (l == r)
    {
        lef[o] = pcnt + 1;
        ql > 1 ? p[++pcnt] = (Seg) {1, ql - 1, 1, 0}, 1: 0;
        p[++pcnt] = (Seg) {ql, qr, ta, tb};
        qr < n ? p[++pcnt] = (Seg) {qr + 1, n, 1, 0}, 1: 0;
        rig[o] = pcnt;
        return ;
    }
    R int mid = l + r >> 1;
    if (t <= mid) modify(o << 1, l, mid, t);
    else modify(o << 1 | 1, mid + 1, r, t);

    if (t == r) update(o, l, r);
}
void query(R int o, R int l, R int r)
{
    if (ql <= l && r <= qr)
    {
        find(o, k, ans);
        return ;
    }
    R int mid = l + r >> 1;
    if (ql <= mid) query(o << 1, l, mid);
    if (mid < qr) query(o << 1 | 1, mid + 1, r);
}
int main()
{
    R int type; scanf("%d%d%d", &type, &n, &m);
    for (R int i = 1; i <= n; ++i) scanf("%d", &x[i]);
    R int Q; scanf("%d", &Q);
    for (R int QQ = 1; QQ <= Q; ++QQ)
    {
        R int opt, l, r; scanf("%d%d%d", &opt, &l, &r);
        type & 1 ? l ^= ans, r ^= ans : 0;
        if (opt == 1)
        {
            scanf("%d%d", &ta, &tb); ++tnum; ql = l; qr = r;
            modify(1, 1, Q, tnum);
        }
        else
        {
            scanf("%d", &k); type & 1 ? k ^= ans : 0; ql = l; qr = r;
            ans = x[k];
            query(1, 1, Q);
            printf("%d\n", ans);
        }
    }
    return 0;
}
