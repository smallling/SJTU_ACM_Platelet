int n;
typedef double db;
const db pi = acos(-1.0);
struct Cir {
	db x, y, r;
}c[maxn];
struct Seg {
	db l, r;
	inline bool operator < (const Seg &that) const
	{
		return l < that.l || (l == that.l && r < that.r);
	}
} s[maxn];
inline db sqr(db x) {return x * x;}
inline db len(db x)
{
	int scnt = 0;
	for (int i = 1; i <= n; ++i)
		if (fabs(c[i].x - x) <= c[i].r)
		{
			db t = sqrt(sqr(c[i].r) - sqr(c[i].x - x));
			s[++scnt] = (Seg) {c[i].y - t, c[i].y + t};
		}
	std::sort(s + 1, s + scnt + 1);
	db ret = 0; db l = 1e18, r = -1e18;
	for (int i = 1; i <= scnt; ++i)
	{
		if (s[i].l > r)
		{
			if (l < r) ret += r - l;
			l = s[i].l; r = s[i].r;
		}
		else
			cmax(r, s[i].r);
	}
	if (l < r) ret += r - l;
	return ret;
}
inline db f(db l, db r, db fl, db fm, db fr)
{
	return (r - l) * (fl + fr + fm * 4.0) / 6.0;
}
db ans(db l, db r, db fl, db fm, db fr)
{
	db mid = (l + r) * 0.5;
	db mid1 = (l + mid) * 0.5, mid2 = (mid + r) * 0.5;
	db fmid1 = len(mid1), fmid2 = len(mid2);
	db ff = f(l, r, fl, fm, fr), flmid = f(l, mid, fl, fmid1, fm), fmidr = f(mid, r, fm, fmid2, fr);
	if (r - l < 1e-9 || fabs(ff - flmid - fmidr) < 1e-9) return ff;
	else return ans(l, mid, fl, fmid1, fm) + ans(mid, r, fm, fmid2, fr);
}
int main()
{
	srand(time(NULL) + clock());
	scanf("%d", &n);
	db l = 1e18, r = -1e18, theta = rand(), co = cos(theta), si = sin(theta);
	for (int i = 1; i <= n; ++i)
	{
		db x, y;
		scanf("%lf%lf%lf", &x, &y, &c[i].r);
		c[i].x = co * x - si * y;
		c[i].y = si * x + co * y;
		cmin(l, c[i].x - c[i].r);
		cmax(r, c[i].x + c[i].r);
	}
	double mid = (l + r) * 0.5;
	printf("%.3lf\n", ans(l, r, len(l), len(mid), len(r)));
	return 0;
}
