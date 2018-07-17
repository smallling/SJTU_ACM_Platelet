//
//  Title : 最小表示法
//  Date : 28.03.2016
//  Test : BZOJ-2882
//  Complexity : O(n)
//  
/*
	对于循环同构等问题——
	解决办法：最小表示法
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
#define maxn 300010
#define cmod(_x, mod) ((_x) > mod ? (_x) - mod : (_x))
int a[maxn];
int main()
{
	R int n = FastIn();
	for (R int i = 0; i < n; ++i) a[i] = FastIn();
	//******************************************************
	R int i = 0, j = 1, k = 0;
	while (i < n && j < n && k < n)
	{
		R int tmp = a[(i + k) % n] - a[(j + k) % n];
		if (!tmp) k++;
		else
		{
			if (tmp > 0) i += k + 1;
			else j += k + 1;
			if (i == j) ++j;
			k = 0;
		}
	}
	j = dmin(i, j);
	//******************************************************
	for (R int i = j; i < n; ++i) printf("%d ",a[i] );
	for (R int i = 0; i < j - 1; ++i) printf("%d ",a[i] );
	if (j > 0) printf("%d\n",a[j - 1] );
	return 0;
}
/*
hack:
input:
5
2 1 1 1 1
output:
1 1 1 1 2
*/
