int h[N],to[N],nxt[N],tot,a[N],dfn[N],seq[N],timer,mk[N],ck[N],mx[N],dept[N],fa[N],f[N][__lg(N)+2];vector<pii>t[N];
int ql[N],qr[N],u[N],ans[N];vt g[N];
int mn(int x,int y){return dept[x]<dept[y]?x:y;}
void add(int x,int y){to[++tot]=y;nxt[tot]=h[x];h[x]=tot;}
void dfs(int x,int pa,int d){dfn[x]=++timer;seq[timer]=x;dept[x]=d;fa[x]=pa;
for(int v=h[x];v;v=nxt[v]){int y=to[v];if(y==pa)continue;dfs(y,x,d+1);}}
void lca(int n){dfs(1,-1,0);int x;for(x=1;x<=n;x++)f[x][0]=seq[x];
int t=__lg(n)+1;int y;for(y=1;y<t;y++){for(x=1;x<=n-(1<<y)+1;x++)
f[x][y]=mn(f[x][y-1],f[x+(1<<y-1)][y-1]);}}
int ask(int a,int b){if(a==b)return a;if(dfn[a]>dfn[b])swap(a,b);a=dfn[a]+1;b=dfn[b];
int k=__lg(b-a+1);return fa[mn(f[a][k],f[b-(1<<k)+1][k])];}
signed main(){ios::sync_with_stdio(0),cin.tie(0);int n,m,s,x,y,k,z;
cin>>n>>m>>s;for(x=1;x<n;x++){cin>>k>>z;add(k,z);add(z,k);}lca(n,s);
for(x=1;x<=m;x++){cin>>k>>z;printf("%d\n",ask(k,z));}return 0;}
