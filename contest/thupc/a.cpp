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
// int h[N],to[N],nxt[N],tot,s[N].a[N],dept[N],fa[N],mx[N],dfn[N],seq[N],timer,f[N][N],mk1[N+63>>6],mk2[N+63>>6],res[N],op[N];struct Q{int l,r,u,id;}b[N];vector<pii>t[N<<2];vt g[N];
// void add(int x,int y){to[++tot]=y;nxt[tot]=h[x];h[x]=tot;}
// void addtr(int x,int y){g[x].push_back(y);g[y].push_back(x);mk2[x>>6]|=1ull<<(x&63);mk2[y>>6]|=1ull<<(y&63);}
// void dfs(int x,int pa,int d){dfn[x]=++timer;fa[x]=pa;dept[x]=d;seq[timer]=x;
// for(int v=h[x];v;v=nxt[v]){int y=to[x];if(y==pa)continue;dfs(y,x,d+1);}}
// bool mn(int x,int y){return dept[x]<dept[y];}
// void lca(int n){dfs(1,-1,0);int x,t=log(n)/log(2)+1,i,k;
// for(x=1;x<=n;x++)f[x][0]=seq[x];for(x=1;x<t;x++){
// for(k=1;k<=n-(1<<x)+1;k++)f[i][j]=mn(f[x][k-1],f[k+(1<<x)][k-1]);}}
// int ask(int a,int b){if(a==b)return a;if(dfn[a]>dfn[b])swap(a,b);a=dfn[a]+1;b=dfn[b];
// int k=log(r-l+1)/log(2);return fa[mn(f[a][k],f[b-(1<<k)+1][k])];}
// void upd(int l,int r,int ql,int qr,int p,int u,int id){if(ql<=l&&r<=qr){t[p].push_back(mkp(u,id));return;}
// int mid=l+r>>1;if(ql<=mid)upd(l,mid,ql,qr,p<<1,u,id);if(qr>mid)upd(mid+1,r,ql,qr,p<<1|1,u,id);}
// // vt query(int l,int r,int ql,int qr,int p){if(ql<=l&&r<=qr)return t[p];int mid=l+r>>1;
// // vt lans,rans,ans;if(ql<=mid)lans=query(l,mid,ql,qr,p<<1);if(qr>mid)rans=query(mid+1,r,ql,qr,p<<1|1);
// // int x=0,y=0;for(;x<(int)lans.size();){for(;y<(int)rans.size();)if(dfn[lans[x]]<=dfn[rans[y]])ans.push_back(lans[x++]);
// // ans.push_back(rans[y++]);}while(x<=(int)lans.size()-1)ans.push_back(lans[x]);
// // while(y<=(int)rans.size())rans.push_back(rans[x]);return ans;}
// //vatrial tree
// //我们可以更加深刻一些，建虚树本质上是查u这条chain以前或者说dfn小于u的节点的编号的最大值
// //这里dfn列表已经有序，直接扫一遍即可,
// //val 中有blk,wht --> 单调栈，维护一个max,mk，!mk -> ans=s.top();(m+q)logn
// void build(vt&val){int p=0;static int s[N];s[++p]=1;for(auto x:val){if(x==1)continue;
// int lk=ask(s[p],x);if(lk==s[p])addtr(lk,s[p]),s[p--],s[++p]=x;else{while(p-1&&s[p-1]!=lk)addtr(s[p-1],s[p--]);
// addtr(s[p],x);s[p--];s[++p]=x;}}while(p-1)addtr(s[p-1],s[p--]);}
// void dfs1(int x,int pa){ck[x]=mk1[x>>6]&1ull<<(x&63);for(auto y:g[x]){if(y==pa)continue;dfs(y,x);ck[x]|=ck[y];}}
// void dfs2(int x,int pa,int bst){int bts1=bst;if(ck[x]){bst1=max(bst1,max(bst,x));}mx[x]=bst1;for(auto y:g[x]){
// if(y==pa)continue;dfs(y,x,bst1);}}
// void solve(int p,int l,int r){if(!t[p].empty()){int x;for(x=l;x<=r;x++)mk1[val[x]>>6]|=1ull<<(val[x]&63);
// int y;vt bd;for(x=l;x<=r;){for(y=0;y<=(int)t[p].size()-1;)if(val[x]<t[p][y])bd.push_back(val[x++]);
// bd.push_back(t[p][y++]);}bd.erase(all(bd),bd.end());build(bd);dfs1(1,0);dfs2(1,0,0);
// for(auto u:t[p])res[u]=max(res[u],mx[u]);for(x=l;x<=r;x++)mk1[val[x]>>6]~=1ull<<(val[x]&63);for(auto u:bd)g[u].clear();
// if(l==r)return;int mid=l+r>>1;solve(p<<1,l,mid);solve(p<<1|1,mid+1,r);}}
int h[N],to[N],nxt[N],tot,a[N],dfn[N],seq[N],timer,mk[N],ck[N],mx[N],dept[N],fa[N],f[N][__lg(N)+2];vector<pii>t[N];
int ql[N],qr[N],u[N],ans[N];vt g[N];
int mn(int x,int y){return dept[x]<dept[y]?x:y;}
void add(int x,int y){to[++tot]=y;nxt[tot]=h[x];h[x]=tot;}
void dfs(int x,int pa,int d){dfn[x]=++timer;seq[timer]=x;dept[x]=d;fa[x]=pa;
for(int v=h[x];v;v=nxt[v]){int y=to[v];if(y==pa)continue;dfs(y,x,d+1);}}
void lca(int n){dfs(1,-1,0);int x;for(x=1;x<=n;x++)f[x][0]=seq[x];
int t=log(n)/log(2)+1;int y;for(y=1;y<t;y++){for(x=1;x<=n-(1<<y)+1;x++)
f[x][y]=mn(f[x][y-1],f[x+(1<<y-1)][y-1]);}}
int ask(int a,int b){if(a==b)return a;if(dfn[a]>dfn[b])swap(a,b);a=dfn[a]+1;b=dfn[b];
int k=__lg(b-a+1);return fa[mn(f[a][k],f[b-(1<<k)+1][k])];}
void upd(int p,int l,int r,int ql,int qr,int u,int id){if(ql<=l&&r<=qr){t[p].emplace_back(mkp(u,id));return;}
int mid=l+r>>1;if(ql<=mid)upd(p<<1,l,mid,ql,qr,u,id);if(qr>mid)upd(p<<1|1,mid+1,r,ql,qr,u,id);}
void ad(int x,int y){g[x].emplace_back(y);}
void build(vt&val){static int s[N];int p;s[++p]=1;for(auto x:val){if(x==1)continue;int lk=ask(s[p],x);
if(lk!=s[p]){while(p-1&&dept[s[p-1]]>dept[x])ad(s[p-1],x),p--;
if(dept[s[p-1]]<dept[lk])ad(s[p-1],lk),s[p--],s[++p]=lk;else ad(lk,s[p]),p--;}s[++p]=x;}}
void dfs1(int x,int pa){ck[x]=(mk[x>>6]>>(x&63))&1ull;for(auto y:g[x])
{if(y==pa)continue;ck[x]|=ck[y];dfs1(y,pa);}}
void dfs2(int x,int pa,int bst){int bst1=bst;if(ck[x]){bst1=max(bst1,max(bst,x));}mx[x]=bst1;
for(auto y:g[x]){if(y==pa)continue;dfs2(y,x,bst1);}}
void solve(int p,int l,int r,const vt&vec){if(!vec.empty()&&!t[p].empty()){vt list;
static ui64 mk1[(N>>6)+5];int x=0,y=0;for(auto v:vec)mk[a[v]>>6]|=1ull<<(a[v]&63);
while(x<=(int)vec.size()-1&&y<=(int)t[p].size()-1){
if(dfn[a[vec[x]]]<dfn[t[p][y].first]){if(!((mk1[a[vec[x]]>>6]>>(a[vec[x]]&63))&1ull)){
mk1[a[vec[x]]>>6]|=1ull<<(a[vec[x]]&63);list.emplace_back(a[vec[x]]);}x++;}
else{if(!((mk1[t[p][y].first>>6]>>(t[p][y].first&63))&1ull)){
mk1[t[p][y].first>>6]|=1ull<<(t[p][y].first&63);list.emplace_back(t[p][y].first);}y++;}}
while(x<=(int)vec.size()-1){if(!((mk1[a[vec[x]]>>6]>>(a[vec[x]]&63))&1ull))list.emplace_back(a[vec[x]]);x++;}
while(y<=(int)t[p].size()-1){if(!((mk1[t[p][y].first>>6]>>(t[p][y].first&63))&1ull))list.emplace_back(t[p][y].first);y++;}
list.erase(unique(all(list)),list.end());build(list);//这里dfn顺序不对，如果排序的话复杂度会炸，考虑到vec有序，似乎可以归并？       
dfs1(1,0);dfs2(1,0,0);for(auto y:t[p]){ans[y.second]=max(ans[y.second],mx[y.first]);for(x=l;x<=r;x++)
mk[a[x]>>6]&=~(1ull<<(a[x]&63)),g[a[x]].clear();}}
if(l==r)return;int mid=l+r>>1;vt lidx,ridx;for(auto x:vec){if(x<=mid)lidx.emplace_back(x);
else ridx.emplace_back(x);}solve(p<<1,l,mid,lidx);solve(p<<1|1,mid+1,r,ridx);} 
int main(){
int i,j,k,x,y,z,T,q,c,m,n;
ios::sync_with_stdio(0),cin.tie(0);
cin>>n>>m>>q;vt idx(m);for(x=1;x<n;x++){int u,v,w;cin>>u>>v;add(u,v);add(v,u);}
for(x=1;x<=m;x++)cin>>a[x];lca(n);for(x=0;x<m;x++){idx[x]=x+1;}
sort(all(idx),[&](int x,int y){return dfn[a[x]]<dfn[a[y]];});
for(x=1;x<=q;x++){cin>>ql[x]>>qr[x]>>u[x];upd(1,1,n,ql[x],qr[x],u[x],x);} 
solve(1,1,m,idx);for(x=1;x<=q;x++)printf("%d\n",ans[x]);return 0;}