#include<bits/stdc++.h>
#define fs(x) fixed<<setprecision(x)
// #pragma GCC diagnostic error "-std=c++11"
// #pragma GCC target("avx")
// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-fhoist-adjacent-loads")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
#define N (1<<21)+100
#define mkp make_pair
#define cln cerr<<" "<<'\n'
#define MST(x) memset(x,0,sizeof(x))
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
using ll=long long;
#define ctz __builtin_ctzll
using namespace std;
#define pll pair<ll,ll>
template<typename tp1,typename tp2>
void chkmx(tp1&a,tp2&b){if(a<b)a=b;}
template<typename tp1,typename tp2>
void chkmn(tp1&a,tp2&b){if(a>b)a=b;}
template<typename tp1>
void chkabs(tp1&x){if(x<0)x=-x;}
namespace fast_io{char buf[N+10],*p1,*p2,c;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,N,stdin),p1==p2))?EOF:*p1++
template<typename tp>
void read(tp&x){int f=0;for(c=gc;c<48;c=gc)f^=c=='-';
for(x=0;c>47;x=(x<<1)+(x<<3)+(48^c),c=gc);if(f)x=-x;}
inline void rd(int &x){char c;while((c=getchar())<'0');x=c^'0';
while((c=getchar())>='0')x=x*10+(c^'0');}
}using fast_io::rd;
mt19937_64 rg(random_device{}());
using vt=vector<int>;
using vl=vector<ll>;
using ld=long double;
using LL=__int128_t;
using ui64=uint64_t; 
using ui32=uint32_t;
#define int long long
const int inf=1e9;
int a[N],b[N],c[N],tot=1,h[N],to[N],nxt[N],val[N],dp[N],p[N];
void add(int x,int y,int w){to[++tot]=y;nxt[tot]=h[x];h[x]=tot;val[tot]=w;
to[++tot]=x;nxt[tot]=h[y];h[y]=tot;val[tot]=0;}
namespace flow{int dis[N],cur[N];int bfs(int s,int t){
int x;for(x=1;x<=t;x++)dis[x]=0;dis[s]=1;queue<int>q;q.push(s);
while(!q.empty()){x=q.front();q.pop();for(int v=h[x];v;v=nxt[v]){int y=to[v];
if(val[v]>0&&!dis[y]){dis[y]=dis[x]+1;q.push(y);if(y==t)return 1;}}}return dis[t]!=0;}
int dfs(int s,int t,int ls){if(s==t||!ls)return ls;int x=0;
for(int v=h[s];v;v=nxt[v]){cur[s]=v;int y=to[v];if(dis[y]==dis[s]+1&&val[v]>0){
int fx=dfs(y,t,min(val[v],ls-x));if(fx){val[v^1]+=fx;val[v]-=fx;x+=fx;}
if(x==ls)break;}}return x;}
int upd(int s,int t){int ans=0;while(bfs(s,t)){ans+=dfs(s,t,inf);}return ans;}}
signed main(){
int i,j,k,T,x,y,z,q,m,n;
ios::sync_with_stdio(0),cin.tie(0);
for(cin>>T;T--;){cin>>n;for(x=1;x<=n;x++)cin>>a[x];
for(x=1;x<=n;x++)cin>>b[x];for(x=1;x<=n;x++)cin>>c[x];
for(x=1;x<=n;x++)dp[x]=1;for(x=2;x<=n;x++){for(j=1;j<x;j++)
if(a[j]<a[x])dp[x]=max(dp[j],0ll)+1;}int mx=-1;for(x=1;x<=n;x++)mx=max(dp[x],mx);
for(x=1;x<=n;x++)add(x,x+n,b[x]);int s=n<<2,t=s+1;for(x=1;x<=n;x++)if(dp[x]==1)add(s,x,inf);
for(x=1;x<=n;x++)if(dp[x]==mx)add(x+n,t,inf);for(x=1;x<=n;x++)for(j=1;j<x;j++)
if(dp[j]==dp[x]-1&&a[j]<a[x])add(j+n,x,inf);int ans=flow::upd(s,t);printf("%lld ",ans);
for(x=1;x<=n;x++)p[x]=x;sort(p+1,p+n+1,[&](int x,int y){return c[x]<c[y];});
vl res;for(x=1;x<=n;x++){int u=p[x];if(flow::bfs(u,u+n))continue;
while(flow::bfs(t,u+n))flow::dfs(t,u+n,inf);while(flow::bfs(u,s))flow::dfs(u,s,inf);
res.emplace_back(u);}sort(all(res));printf("%lld\n",(ll)res.size());for(x=0;x<(ll)res.size();x++)printf("%lld ",res[x]);printf("\n");
for(x=0;x<=(n<<2)+2;x++)a[x]=dp[x]=b[x]=c[x]=p[x]=h[x]=to[x]=val[x]=nxt[x]=0;}return 0;}