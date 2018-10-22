/*
	我们先来看看斜截式的式子$y=kx+b$，如果我们把$ki$看成斜率的话那么我们dp时需要最小化的就是截距，我们把斜截式转化成这个形式： $b_i=−k_i∗x_j+y_j$
	然后我们就可以把之前的那些可以转移到这个的状态的点看做是二维平面上的点$(−x_j,y_j)$，这样我们把问题转化为在平面上找到一个点使得斜率为$k_i$的直线的斜率最小。显然这样的点是在凸包上的，并且这样的点在凸包上和前面一个点的斜率小于等于$k_i$并且和后面一个点的斜率大于等于$k_i$。这样我们就可以在凸包上二分之类的方法来加速转移。当点的横坐标$x_i$和斜率$k_i$都是单调的时我们还可以用单调队列来维护凸包。
*/
int a[maxn], n, l;
ll sum[maxn], f[maxn];
inline ll sqr(ll x) {return x * x;}
#define y(_i) (f[_i] + sqr(sum[_i] + l))
#define x(_i) (2 * sum[_i])
inline double slope(int i, int j)
{
    return (y(i) - y(j)) / (1.0 * (x(i) - x(j)));
}
int q[maxn];
int main()
{
    n = F(), l = F() + 1;
    for (int i = 1; i <= n; ++i) a[i] = F(), sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; ++i) sum[i] += i;
    f[0] = 0;
/*  
	memset(f, 63, sizeof (f));
	for (int i = 1; i <= n; ++i)
    {
        int pos;
        for (int j = 0; j < i; ++j)
        {
            long long tmp = f[j] + sqr(sum[i] - sum[j] - l);
            f[i] > tmp ? f[i] = tmp, pos = j : 0;
        }
    }
*/
    int h = 1, t = 1;
    q[h] = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (h < t && slope(q[h], q[h + 1]) <= sum[i]) ++h;
        f[i] = f[q[h]] + sqr(sum[i] - sum[q[h]] - l);
        while (h < t && slope(q[t - 1], i) < slope(q[t - 1], q[t])) --t;
        q[++t] = i;
    }
    printf("%lld\n", f[n] );
    return 0;
}
