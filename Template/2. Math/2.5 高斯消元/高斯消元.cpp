#include <cstdio>
#include <cmath>
#include <algorithm>

#define maxn 110
typedef long double db;
db a[maxn][maxn], x[maxn];
int main()
{
	for (int i = 1; i <= n; ++i)
	{
		if (fabs(a[i][i]) < 1e-15)
		{
			for (int j = i + 1; j <= n; ++j)
				if (fabs(a[j][i]) > fabs(a[i][i]))
				{
					for (int k = i; k <= n + 1; ++k)
						std::swap(a[i][k], a[j][k]);
				}
		}
		for (int j = i + 1; j <= n; ++j)
		{
			db temp = a[j][i] / a[i][i];
			for (int k = i; k <= n + 1; ++k)
				a[j][k] -= temp * a[i][k];
		}
	}
	x[n] = a[n][n + 1] / a[n][n];
	for (int i = n - 1; i; --i)
	{
		for (int j = i + 1; j <= n; ++j)
			a[i][n + 1] -= x[j] * a[i][j];
		x[i] = a[i][n + 1] / a[i][i];
	}
	for (int i = 1; i <= 64; ++i)
		printf("%.20Lf%c", x[i], " \n"[i % 8 == 0]);
	return 0;
}
