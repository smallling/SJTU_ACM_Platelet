//
//  Title: Shortest Path Faster Algorithm (SPFA)
//  Date:  29.11.2015
//  Complexity:
//      Time:  O(KE) KΪ���ж�����ӵ�ƽ��������EΪ����
//      Space: O(N+E)
//  Test��FZOJ-1127
/*
    ��֪һ��ͼG������������̾���
	�ǳ�ʵ�ã����� 
*/ 
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 23333
#define maxm 40000
#define R register
#define INF 23333
int d[maxn],n,m,s,t,last[maxn];
bool vis[maxm+10];
std::queue<int> q;

struct Edge{
	int w,to,next;
}e[maxm+10];//�߱�w�����Ȩ��to�������ӵ���һ�˵㣬next������һ�˵����һ���� 

inline int FastIn()
{
	R char ch=getchar();R int cnt=0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') cnt=cnt*10+ch-'0',ch=getchar();
	return cnt;
}

int main()
{
	n=FastIn();m=FastIn();s=FastIn();t=FastIn();
	R int i,x,y,c,head=0,tail=1;
	for (i=1;i<=m;i++)
	{
		 x=FastIn();y=FastIn();c=FastIn();
		 e[i]=(Edge){c,y,last[x]};
		 last[x]=i;
	}//�������� 
	memset(d,INF,sizeof(d));
	d[s]=0;q.push(s);
	while (!q.empty())
	{
		x=q.front();q.pop() ;
		vis[x]=0;
		for (i=last[x];i;i=e[i].next)
		{
			if (d[e[i].to]>d[x]+e[i].w)
			{
				d[e[i].to]=d[x]+e[i].w;//����и��ŵĽ⣬�Ǿ͸�������˵��ֵ 
				if (!vis[e[i].to)
				{
					q.push(e[i].to);//�������㲻�ڶ��оͽ�����˵���� 
					vis[e[i].to]=1;
				}
			}
		}
	}
	return !printf("%d",d[t]);
}
