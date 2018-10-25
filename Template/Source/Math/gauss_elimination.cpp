for (int i = 1, now = 1; i <= n && now <= m; ++now)
{
    int tmp = i;
    for (int j = i + 1; j <= n; ++j)
        if (fabs(a[j][now]) > fabs(a[tmp][now]))tmp = j;
    for (int k = now; k <= m; ++k)
        std::swap(a[i][k], a[tmp][k]);
    if (fabs(a[i][now]) < eps) continue;

    for (int j = i + 1; j <= n; ++j)
    {
        db tmp = a[j][now] / a[i][now];
        for (int k = now; k <= m; ++k)
            a[j][k] -= tmp * a[i][k];
    }
    ++i; ++rank;
}
