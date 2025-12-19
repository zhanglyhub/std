include<bits/stdc++.h>
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
namespace fast_io{
    char buf[N+10],*p1,*p2,c;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,N,stdin),p1==p2))?EOF:*p1++
template<typename _Tp>
    void read(_Tp &x){
        int f=0;for(c=gc;c<48;c=gc)f^=c=='-';
        for(x=0;c>47;x=(x<<1)+(x<<3)+(48^c),c=gc);
        if(f)x=-x;
    }
template<typename _Tp,typename..._tps>
    void read(_Tp &x,_tps&...y){read(x),read(y...);}
    char ob[N+100],stk[505];int tp,ot;
    void fls(){fwrite(ob,1,ot,stdout),ot=0;}
    int cntt;
template<typename _Tp>
    static inline void write(_Tp x,char c){
        if(!cntt)atexit(fls),cntt=1;
        while(x>9)stk[++tp]=48^(x%10),x/=10;
        for(ob[ot++]=48^x;tp;ob[ot++]=stk[tp--]);
        ob[ot++]=c;if(ot>N)fls();
    }
template<typename tq>
    void rd(tq &x){ 
	int f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	x*=f;
    }
}using fast_io::read;
using fast_io::write;
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
int h[N],to[N<<1],nxt[N<<1],tot,a[N],dfn[N],seq[N],timer,mk[N],ck[N],mx[N],dept[N],fa[N],f[N][__lg(N)+2];vector<pii>t[N<<2];
int ans[N];vt g[N];struct T{int l,r,u;}b[N];
int mn(int x,int y){return dept[x]<dept[y]?x:y;}
void add(int x,int y){to[++tot]=y;nxt[tot]=h[x];h[x]=tot;}
void dfs(int x,int pa,int d){dfn[x]=++timer;seq[timer]=x;dept[x]=d;fa[x]=pa;
for(int v=h[x];v;v=nxt[v]){int y=to[v];if(y==pa)continue;dfs(y,x,d+1);}}
void lca(int n){dfs(1,-1,0);int x;for(x=1;x<=n;x++)f[x][0]=seq[x];
int t=__lg(n)+1;int y;for(y=1;y<t;y++){for(x=1;x<=n-(1<<y)+1;x++)
f[x][y]=mn(f[x][y-1],f[x+(1<<y-1)][y-1]);}}
int ask(int a,int b){if(a==b)return a;if(dfn[a]>dfn[b])swap(a,b);a=dfn[a]+1;b=dfn[b];
int k=__lg(b-a+1);return fa[mn(f[a][k],f[b-(1<<k)+1][k])];}
void upd(int p,int l,int r,int ql,int qr,int u,int id){if(ql<=l&&r<=qr){
t[p].emplace_back(mkp(u,id));return;}int mid=l+r>>1;if(ql<=mid)upd(p<<1,l,mid,ql,qr,u,id);
if(qr>mid)upd(p<<1|1,mid+1,r,ql,qr,u,id);}void ad(int x,int y){g[x].emplace_back(y);}
void clr(int x){for(auto y:g[x])clr(y);g[x].clear();mx[x]=mk[x]=0;}
void build(vt&val){static int s[N];int p=0;s[++p]=1;for(auto x:val){
if(x==1)continue;int lk=ask(s[p],x);if(lk!=s[p]){while(p-1&&dept[s[p-1]]>dept[lk])ad(s[p-1],s[p]),p--;
if(dept[s[p-1]]<dept[lk])ad(lk,s[p]),s[p]=lk;else ad(lk,s[p--]);}s[++p]=x;}while(p-1)ad(s[p-1],s[p]),p--;}
void dfs1(int x,int pa){for(auto y:g[x]){if(y==pa)continue;dfs1(y,x);mk[x]+=mk[y];}}
void dfs2(int x,int pa){for(auto y:g[x]){if(y==pa)continue;
mx[y]=mx[x];if(mk[y]<mk[x])mx[y]=max(mx[y],x);dfs2(y,x);}}
void solve(int p,int l,int r,const vt&vec,const int&n){if(!vec.empty()&&!t[p].empty()){
int x,y;for(auto x:vec)mk[a[x]]=1;vt la,lb,lc;for(auto x:vec)la.emplace_back(a[x]);
for(auto x:t[p])lb.emplace_back(x.first);vt list;list.resize(la.size()+lb.size());
sort(all(lb),[&](int x,int y){return dfn[x]<dfn[y];});
merge(all(la),all(lb),list.begin(),[](int x,int y){return dfn[x]<dfn[y];});
sort(all(list),[&](int x,int y){return dfn[x]<dfn[y];});
list.erase(unique(all(list)),list.end());build(list);dfs1(1,0);dfs2(1,0);
for(auto y:t[p]){ans[y.second]=max(ans[y.second],mx[y.first]);}
for(auto x:t[p])if(mk[x.first])ans[x.second]=max(ans[x.second],x.first);clr(1);}
if(l==r)return;int mid=l+r>>1;vt lidx,ridx;for(auto x:vec){if(x<=mid)lidx.emplace_back(x);
else ridx.emplace_back(x);}solve(p<<1,l,mid,lidx,n);solve(p<<1|1,mid+1,r,ridx,n);} 
int main(){
int i,j,k,x,y,z,q,c,m,n;
// ios::sync_with_stdio(0),cin.tie(0);
scanf("%d%d%d",&n,&m,&q);vt idx(m);for(x=1;x<n;x++){int u,v,w;cin>>u>>v;add(u,v);add(v,u);}
for(x=1;x<=m;x++)scanf("%d",&a[x]);lca(n);for(x=0;x<m;x++){idx[x]=x+1;}
sort(all(idx),[&](int x,int y){return dfn[a[x]]<dfn[a[y]];});
for(x=1;x<=q;x++){scanf("%d%d%d",&b[x].l,&b[x].r,&b[x].u);}
for(x=1;x<=q;x++)upd(1,1,m,b[x].l,b[x].r,b[x].u,x);solve(1,1,m,idx,n);
for(x=1;x<=q;x++)printf("%d\n",ans[x]);return 0;}
// 1 5 2 3 4 7 6 8 10
// 2 4 6 8 10
// 6 8 10
// 5 9 10
// 8 10
// 6 10
// 2 3 4 10
// 3 4
// 4 8
// 1 2 3 5
// 1 2 3 5 8
// 1 5 4 7 6 10
// 1 5 7 8
// 1 5 7
// 5 3
// 4 7
// 1 4 7 9
// 4 7 6
// 4 6 8
// 9 4
// 6
// 7 6