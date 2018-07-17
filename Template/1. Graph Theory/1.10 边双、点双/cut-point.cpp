//
//  Title : Cut-point
//  Date : 27.05.2016
//  Test : BZOJ-1123
//  Complexity : O(n)
//  
/*
	对于无向图求割点等问题——
	解决办法：tarjan
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#ifdef WIN32
	#define LL "%I64d"
#else
	#define LL "%lld"
#endif

#ifdef CT
	#define debug(...) printf(__VA_ARGS__)
	#define setfile() 
#else
	#define debug(...)
	#define filename ""
	#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);
#endif

#define R register
#define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 15, stdin), S == T) ? EOF : *S++)
#define dmax(_a, _b) ((_a) > (_b) ? (_a) : (_b))
#define dmin(_a, _b) ((_a) < (_b) ? (_a) : (_b))
#define cmax(_a, _b) (_a < (_b) ? _a = (_b) : 0)
#define cmin(_a, _b) (_a > (_b) ? _a = (_b) : 0)
char B[1 << 15], *S = B, *T = B;
inline int FastIn()
{
	R char ch; R int cnt = 0; R bool minus = 0;
	while (ch = getc(), (ch < '0' || ch > '9') && ch != '-') ;
	ch == '-' ? minus = 1 : cnt = ch - '0';
	while (ch = getc(), ch >= '0' && ch <= '9') cnt = cnt * 10 + ch - '0';
	return minus ? -cnt : cnt;
}
#define maxn 100010
#define maxm 1000010
struct Edge
{
	Edge *next;
	int to;
}*last[maxn], e[maxm], *ecnt = e;
inline void link(R int a, R int b)
{
	*++ecnt = (Edge) {last[a], b}; last[a] = ecnt;
}
int dfn[maxn], low[maxn], timer, n, m, size[maxn];
long long ans[maxn];
void dfs(R int x, R int fa)
{
	dfn[x] = low[x] = ++timer;
	size[x] = 1;
	R int tmp = 0;
	for (R Edge *iter = last[x]; iter; iter = iter -> next)
	{
		R int pre = iter -> to;
		if (pre != fa)
		{
			if (!dfn[pre])
			{
				dfs(pre, x);
				size[x] += size[pre];
				cmin(low[x], low[pre]);
				if (dfn[x] <= low[pre])
				{
					ans[x] += 1ll * tmp * size[pre];
					tmp += size[pre];
				}
			}
			else cmin(low[x], dfn[pre]);
		}
	}
	ans[x] += 1ll * tmp * (n - 1 - tmp);
}
int main()
{
//	setfile();
	n = FastIn(), m = FastIn();
	for (R int i = 1; i <= m; ++i)
	{
		R int a = FastIn(), b = FastIn();
		link(a, b); link(b, a);
	}
	dfs(1, 0);
	for (R int i= 1; i <= n; ++i) printf("%lld\n", (ans[i] + n - 1) << 1 );
	return 0;
}
