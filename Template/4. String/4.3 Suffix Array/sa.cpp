#include <cstdio>
#include <cstring>

#define R register
#define maxn 200010
char s[maxn];
int sa[maxn], rank[maxn], wa[maxn], wb[maxn], cnt[maxn], height[maxn];
inline void build(R int n, R int m)
{
	R int *x = wa, *y = wb, *t;
	for (R int i = 1; i <= n; ++i) cnt[x[i] = s[i] - 'a' + 1]++;
	for (R int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (R int i = n; i; --i) sa[cnt[x[i]]--] = i;

	for (R int j = 1; j < n || (j == 1 && m < n); j <<= 1, t = x, x = y, y = t)
	{
		memset(cnt + 1, 0, m << 2);
		R int p = 0;
		for (R int i = n - j + 1; i <= n; ++i) y[++p] = i;
		for (R int i = 1; i <= n; ++i)
		{
			++cnt[x[i]];
			sa[i] > j ? y[++p] = sa[i] - j : 0;
		}
		for (R int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
		for (R int i = n; i; --i) sa[cnt[x[y[i]]]--] = y[i];
                m = 0;
		for (R int i = 1; i <= n; ++i)
			y[sa[i]] = (i == 1 || x[sa[i]] != x[sa[i - 1]] || x[sa[i - 1] + j] != x[sa[i] + j]) ? ++m : m;
	}
	for (R int i = 1; i <= n; ++i) rank[sa[i]] = i;
	for (R int i = 1, j, k = 0; i <= n; height[rank[i++]] = k)
		for (k ? --k : 0, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; ++k);
}
int main()
{
	scanf("%s", s + 1);
	R int n = strlen(s + 1);
	build(n, 26);
	for (R int i = 1; i <= n; ++i) printf("%d ", sa[i]); puts("");
	for (R int i = 2; i <= n; ++i) printf("%d ", height[i]); puts("");
	return 0;
}
