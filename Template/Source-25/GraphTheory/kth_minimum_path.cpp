const int MAXNODE=MN+MAXM*2;
int n,m,cnt,S,T,Kth,N,TT,used[MN];
int rt[MN],seq[MN],adj[MN],from[MN],dep[MN];
LL dist[MN],w[MAXM],ans[MAXK];
struct GivenEdge{
  int u,v,w;GivenEdge(){};
  GivenEdge(int _u,int _v,int _w): u(_u),v(_v),
                                   w(_w){};
}edge[MAXM];
struct Edge {
  int v,nxt,w;Edge(){};
  Edge(int _v,int _nxt,int _w):v(_v),nxt(_nxt),
                                w(_w){};
}e[MAXM];
inline void addedge(int u,int v,int w){
  e[++cnt]=Edge(v,adj[u],w);adj[u]=cnt;}
void dij(int S){
  for(int i = 1;i<=N;i++){
    dist[i]=INF;dep[i]=0x3f3f3f3f;
    used[i]=0;from[i]=0;}
  static priority_queue <pair<LL,int>,vector<
    pair<LL,int>>,greater<pair<LL,int>>>hp;
  while(!hp.empty())hp.pop();
  hp.push(make_pair(dist[S]=0,S));dep[S]=1;
  while(!hp.empty()){
    pair<LL,int> now=hp.top();hp.pop();
    int u=now.second;
    if(used[u])continue;else used[u]=true;
    for(int p=adj[u];p;p=e[p].nxt){
      int v=e[p].v;if(dist[u]+e[p].w<dist[v]){
        dist[v]=dist[u]+e[p].w;dep[v]=dep[u]+1;
        from[v]=p;hp.push(make_pair(dist[v],v));
    }}}
  for(int i=1;i<=m;i++)w[i]=0;
  for(int i=1;i<=N;i++)if(from[i])w[from[i]]=-1;
  for(int i=1;i<=m;i++)
    if(~w[i]&&dist[edge[i].u]<INF&&
       dist[edge[i].v]<INF)w[i]=-dist[edge[i].u]+
             (dist[edge[i].v]+edge[i].w);
    else w[i]=-1;
}
inline bool cmp_dep(int p,int q){
  return dep[p]<dep[q];}
struct Heap{
  LL key;
  int id,lc,rc,dist;
  Heap(){};
  Heap(LL k,int i,int l,int r,int d)
      : key(k),id(i),lc(l),rc(r),dist(d){};
  inline void clear(){key=0;id=lc=rc=dist=0;}
}hp[MAXNODE];
inline int merge_simple(int u,int v){
  if(!u)return v;if(!v)return u;
  if(hp[u].key>hp[v].key)swap(u,v);
  hp[u].rc=merge_simple(hp[u].rc,v);
  if(hp[hp[u].lc].dist<hp[hp[u].rc].dist)
    swap(hp[u].lc,hp[u].rc);
  hp[u].dist=hp[hp[u].rc].dist+1;
  return u;}
inline int merge_full(int u,int v){
  if(!u)return v;if(!v)return u;
  if(hp[u].key>hp[v].key)swap(u,v);
  int nnode=++cnt;hp[nnode]=hp[u];
  hp[nnode].rc=merge_full(hp[nnode].rc,v);
  if(hp[hp[nnode].lc].dist<hp[hp[nnode].rc].dist)
    swap(hp[nnode].lc,hp[nnode].rc);
  hp[nnode].dist=hp[hp[nnode].rc].dist+1;
  return nnode;}
using ele=pair<LL,int>;
priority_queue <ele,vector<ele>,greater<ele>> Q;
int main(){
  while(scanf("%d%d",&n,&m)!=EOF){
    scanf("%d%d%d%d",&S,&T,&Kth,&TT);
    for(int i=1;i<=m;i++){int u,v,w;
      scanf("%d%d%d",&u,&v,&w);edge[i]={u,v,w};}
    N=n;memset(adj,0,sizeof(*adj)*(N+1));cnt=0;
    for(int i=1;i<=m;i++)
      addedge(edge[i].v,edge[i].u,edge[i].w);
    dij(T);if(dist[S]>TT){/*NO PATH*/;continue;}
    for(int i=1;i<=N;i++)seq[i]=i;
    sort(seq+1,seq+N+1,cmp_dep);
    cnt=0;memset(adj,0,sizeof(*adj)*(N+1));
    memset(rt,0,sizeof(*rt)*(N+1));
    for(int i=1;i<=m;i++)
      addedge(edge[i].u,edge[i].v,edge[i].w);
    rt[T]=cnt=0;hp[0].dist=-1;
    for(int i=1;i<=N;i++){
      int u=seq[i],v=edge[from[u]].v;rt[u]=0;
      for(int p=adj[u];p;p=e[p].nxt){if(~w[p]){
          hp[++cnt]=Heap(w[p],p,0,0,0);
          rt[u]=merge_simple(rt[u],cnt);}}
      if(i==1)continue;
      rt[u]=merge_full(rt[u],rt[v]);}
    while(!Q.empty())Q.pop();
    Q.push(make_pair(dist[S],0));edge[0].v=S;
    for(int kth=1,t;kth<=Kth;kth++){//ans[1..Kth]
      if(Q.empty()){ans[kth] = -1;continue;}
      pair<LL,int> now=Q.top();Q.pop();
      ans[kth]=now.first;int p=now.second;
      if(t=hp[p].lc)Q.push(make_pair(
    	hp[t].key+now.first-hp[p].key,t));
      if(t=hp[p].rc)Q.push(make_pair(
	  	  hp[t].key+now.first-hp[p].key,t));
      if(t=rt[edge[hp[p].id].v])Q.push(make_pair(
          hp[t].key+now.first,t));}}}
