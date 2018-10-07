<<<<<<< HEAD
//
//  Title: Functional Segment Tree
//  Date:16.12.2015
//  Complexity:O((n+m)logn)
//  Test:YZOJ-1991
#include<cstdio>
#include<algorithm>
#define maxt 2000010
#define maxn 100010
#define R register
inline int FastIn(){
	R char ch=getchar();R int cnt=0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') cnt=cnt*10+ch-'0',ch=getchar();
	return cnt;
}

int ls[maxt],
    rs[maxt],
	count[maxt],
	root[maxn],
	tot;

int num[maxn],rank[maxn],n,m,r[maxn];

bool cmp(const int &i,const int &j){
	return num[i]<num[j];
}

inline void Insert(int last,int left,int right,int pre)
{
	count[++tot]=count[last]+1;	
	if (left==right) return;	
	R int mid=(left+right)>>1;
	if (pre>mid){
		rs[tot]=tot+1;
		Insert(rs[last],mid+1,right,pre);
	}
	else{
		ls[tot]=tot+1;
		rs[tot]=rs[last];
		Insert(ls[last],left,mid,pre); 
	}
}

inline int Query(int a,int b,int k)
{
	R int l=1,r=n,mid,f1=a,f2=b,cnt,kk=k;
	while (l<r){
		mid=(l+r)>>1;cnt=count[ls[f2]]-count[ls[f1]];
		if (cnt>=kk) f1=ls[f1],f2=ls[f2],r=mid;
		else f1=rs[f1],f2=rs[f2],l=mid+1,kk-=cnt;
	}
	return l;
}

int main()
{
	n=FastIn();m=FastIn();R int i,a,b,k;	
	for (i=1;i<=n;i++) num[i]=FastIn(),rank[i]=i;
	std::sort(rank+1,rank+n+1,cmp);
	std::sort(num+1,num+n+1);
	for (i=1;i<=n;i++) r[rank[i]]=i;
	for (i=1;i<=n;i++) {
		root[i]=tot+1;
		Insert(root[i-1],1,n,r[i]); 
	}
	for (i=1;i<=m;i++){
		a=FastIn();b=FastIn();k=FastIn();
		printf("%d\n",num[Query(root[a-1],root[b],k)]);
	}
	return 0;
}
=======
//
//  Title: Functional Segment Tree
//  Date:16.12.2015
//  Complexity:O((n+m)logn)
//  Test:YZOJ-1991
#include<cstdio>
#include<algorithm>
#define maxt 2000010
#define maxn 100010
#define R register
inline int FastIn(){
	R char ch=getchar();R int cnt=0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') cnt=cnt*10+ch-'0',ch=getchar();
	return cnt;
}

int ls[maxt],
    rs[maxt],
	count[maxt],
	root[maxn],
	tot;

int num[maxn],rank[maxn],n,m,r[maxn];

bool cmp(const int &i,const int &j){
	return num[i]<num[j];
}

inline void Insert(int last,int left,int right,int pre)
{
	count[++tot]=count[last]+1;	
	if (left==right) return;	
	R int mid=(left+right)>>1;
	if (pre>mid){
		rs[tot]=tot+1;
		Insert(rs[last],mid+1,right,pre);
	}
	else{
		ls[tot]=tot+1;
		rs[tot]=rs[last];
		Insert(ls[last],left,mid,pre); 
	}
}

inline int Query(int a,int b,int k)
{
	R int l=1,r=n,mid,f1=a,f2=b,cnt,kk=k;
	while (l<r){
		mid=(l+r)>>1;cnt=count[ls[f2]]-count[ls[f1]];
		if (cnt>=kk) f1=ls[f1],f2=ls[f2],r=mid;
		else f1=rs[f1],f2=rs[f2],l=mid+1,kk-=cnt;
	}
	return l;
}

int main()
{
	n=FastIn();m=FastIn();R int i,a,b,k;	
	for (i=1;i<=n;i++) num[i]=FastIn(),rank[i]=i;
	std::sort(rank+1,rank+n+1,cmp);
	std::sort(num+1,num+n+1);
	for (i=1;i<=n;i++) r[rank[i]]=i;
	for (i=1;i<=n;i++) {
		root[i]=tot+1;
		Insert(root[i-1],1,n,r[i]); 
	}
	for (i=1;i<=m;i++){
		a=FastIn();b=FastIn();k=FastIn();
		printf("%d\n",num[Query(root[a-1],root[b],k)]);
	}
	return 0;
}
>>>>>>> 49188fa6ef8b175c2f4a6388509d8dc5116ebccd
