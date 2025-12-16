#include<bits/stdc++.h>
#define fs(x) fixed<<setprecision(x)
#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
namespace fastio{
char buf[N+10],*p1,*p2,c;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,N,stdin),p1==p2))?EOF:*p1++
template<typename tp>
void read(tp&x){int f=0;for(c=gc;c<48;c=gc)f^=c=='-';
for(x=0;c>47;x=(x<<1)+(x<<3)+(48^c),c=gc);if(f)x=-x;}    
}using fastio::read;
mt19937_64 rg(random_device{}());
using vt=vector<int>;
using vl=vector<ll>;
using ld=long double;
using LL=__int128_t;
using ui64=uint64_t;
int h[N],to[N],nxt[N],tot,s[N].a[N],dept[N],fa[N],dfn[N],seq[N],timer,f[N][N],mk[N+63>>6],res[N],op[N];struct Q{int l,r,u,id;}b[N];vt t[N];
void add(int x,int y){to[++tot]=y;nxt[tot]=h[x];h[x]=tot;}
void dfs(int x,int pa,int d){dfn[x]=++timer;fa[x]=pa;dept[x]=d;seq[timer]=x;
for(int v=h[x];v;v=nxt[v]){int y=to[x];if(y==pa)continue;dfs(y,x,d+1);}}
bool mn(int x,int y){return dept[x]<dept[y];}
void lca(int n){dfs(1,-1,0);int x,t=log(n)/log(2)+1,i,k;
for(x=1;x<=n;x++)f[x][0]=seq[x];for(x=1;x<t;x++){
for(k=1;k<=n-(1<<x)+1;k++)f[i][j]=mn(f[x][k-1],f[k+(1<<x)][k-1]);}}
int ask(int a,int b){if(a==b)return a;if(dfn[a]>dfn[b])swap(a,b);a=dfn[a]+1;b=dfn[b];
int k=log(r-l+1)/log(2);return fa[mn(f[a][k],f[b-(1<<k)+1][k])];}
void upd(int l,int r,int ql,int qr,int p,int u,int id){if(ql<=l&&r<=qr){t[p].push_back(u);return;}
int mid=l+r>>1;if(ql<=mid)upd(l,mid,ql,qr,p<<1,u,id);if(qr>mid)upd(mid+1,r,ql,qr,p<<1|1,u,id);}
vt query(int l,int r,int ql,int qr,int p){if(ql<=l&&r<=qr)return t[p];int mid=l+r>>1;
vt lans,rans,ans;if(ql<=mid)lans=query(l,mid,ql,qr,p<<1);if(qr>mid)rans=query(mid+1,r,ql,qr,p<<1|1);
int x=0,y=0;for(;x<(int)lans.size();){for(;y<(int)rans.size();)if(dfn[lans[x]]<=dfn[rans[y]])ans.push_back(lans[x++]);
ans.push_back(rans[y++]);}while(x<=(int)lans.size()-1)ans.push_back(lans[x]);
while(y<=(int)rans.size())rans.push_back(rans[x]);return ans;}
//vatrial tree
//我们可以更加深刻一些，建虚树本质上是查u这条chain以前或者说dfn小于u的节点的编号的最大值
//这里dfn列表已经有序，直接扫一遍即可，stop,this solution is O(n) when is worst,
// but build tree is cost O(m+q) is not best than before,so it can be solve easier?
//val 中有blk,wht --> 单调栈，维护一个max,mk，!mk -> ans=s.top();(m+q)logn
void build(vt&val){int p=0;static int s[N];int x;for(x=0;x<(int)val.size();x++){
if(!(val[x>>6]&1ull<<(val[x]&63))){res[op[val[x]]]=val[s[x]];continue;}
for(;p&&val[s[p]]<val[x];p--);s[++p]=x;val[x>>6]^=1ull<<(val[x]&63);}} 
void solve(int l,int r){if(l==r)return;int mid=l+r>>1;solve(l,mid);solve(mid+1,r);
vt val;auto q=query(1,n,l,r,1);int y;for(x=l;x<=r;x++)mk[a[x]>>6]|=1ull<<(a[x]&63);for(x=l;x<=r;){for(;y<q.size();)
if(dfn[a[x]]<dfn[q[y]])val.push_back(a[x++])val.push_back(q[y++]);}while(x<=r)val.push_back(a[x++]);
while(y<=(int)q.size()-1)val.push_back(q[y++]);build(val);}
int main(){
int i,j,k,x,y,z,T,q,c,m,n;
ios::sync_with_stdio(0),cin.tie(0);
cin>>n>>m>>q;for(x=1;x<n;x++){int u,v;cin>>u>>v;add(u,v);add(v,u);}
for(x=1;x<=m;x++)cin>>a[x];for(x=1;x<=q;x++){cin>>b[x].l>>b[x].r>>b[x].u;b[x].id=x;op[b[x].u]=x;
upd(1,n,b[x].l,b[x].r,1,b[x].u,b[x].id);}
lca(n);sort(b+1,b+q+1,[&](Q a,Q b){return dfn[a.u]<dfn[b.u]});
solve(1,n);for(x=1;x<=q;x++)printf("%d\n",res[x]);return 0;}
