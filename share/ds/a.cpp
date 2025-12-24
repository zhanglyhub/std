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
inline int decode(int x, long long lastans) {    
    return x ^ (lastans & 0x7fffffff);
}
// const int MX=4e5+5;
// struct P{int x,y;};struct T{vector<P>v1,v2,v3;}t[MX<<1];
// P operator-(P a,P b){return {a.x-b.x,a.y-b.y};}
// int xj(P a,P b){return a.x*b.y-b.x*a.y;}
// int dot(P a,P b){return a.x*b.x+a.y*b.y;}
// void build(vector<P>&pa){if(pa.empty())return;static int s[N];int p=0,x;s[++p]=0;
// for(x=1;x<pa.size()-1;x++){int c=xj(pa[x]-pa[s[p]],pa[x+1]-pa[x]);
// while(c<0&&p>=2)p--;s[++p]=x;vector<P>tmp;for(x=1;x<=p;x++)
// tmp.push_back(pa[s[x]]);pa=tmp;}}
// void upd(int p,int l,int r,int idx,int x,int y){if(l==r){
// t[p].v1.push_back({x,y});t[p].v2.push_back({x,y});t[p].v3.push_back({x,y});return;}int mid=l+r>>1;
// if(idx<=mid)upd(p<<1,l,mid,idx,x,y);if(idx>mid)upd(p<<1|1,mid+1,r,idx,x,y);if(idx==r){
// t[p].v1.resize(t[p<<1].v1.size()+t[p<<1|1].v1.size());
// merge(all(t[p<<1].v1),all(t[p<<1|1].v1),t[p].v1.begin(),[&](P a,P b){if(a.x!=b.x)return a.x<b.x;return a.y<b.y;});
// t[p].v2.clear();t[p].v3.clear();build(t[p].v1);}}
// int askhull(vector<P>&pa,int x,int y){int l=0,r=pa.size()-1,ans=0;  
// while(l<=r){int mid=l+r>>1;int v=dot(pa[mid],{x,y});if(v>ans)ans=v,l=mid+1;
// else r=mid-1;}return ans;}
// int ask(int p,int l,int r,int ql,int qr,int x,int y){
// if(ql<=l&&r<=qr){return askhull(t[p].v1,x,y);}int mid=l+r>>1;int ans=0;
// if(ql<=mid)ans=max(ans,ask(p<<1,l,mid,ql,qr,x,y));
// if(qr>mid)ans=max(ans,ask(p<<1|1,mid+1,r,ql,qr,x,r));return ans;}
//reset maintain to up and down
const int MX=500000;
#define int long long
struct P{ll x,y;};struct T{vector<P>v1,v2,v3;}t[MX<<1];
int xj(P a,P b){return a.x*b.y-b.x*a.y;}
int dot(P a,P b){return a.x*b.x+a.y*b.y;}
P operator-(P a,P b){return {a.x-b.x,a.y-b.y};}
void build(vector<P>&pa,vector<P>&s,int ck){s.clear();
for(auto p:pa){while((int)s.size()>=2){int v=xj(s.back()-s[s.size()-2],p-s.back());
if(ck){if(v>=0)s.pop_back();else break;}else{if(v<=0)s.pop_back();else break;}}
s.push_back(p);}}
void upd(int p,int l,int r,int idx,int x,int y){
if(l==r){t[p].v1.push_back({x,y});t[p].v2.push_back({x,y});t[p].v3.push_back({x,y});return;}
int mid=l+r>>1;if(idx<=mid)upd(p<<1,l,mid,idx,x,y);if(idx>mid)upd(p<<1|1,mid+1,r,idx,x,y);
if(idx==r){t[p].v1.resize(t[p<<1].v1.size()+t[p<<1|1].v1.size());
merge(all(t[p<<1].v1),all(t[p<<1|1].v1),t[p].v1.begin(),[&](P a,P b){
if(a.x!=b.x)return a.x<b.x;return a.y<b.y;});build(t[p].v1,t[p].v2,1);build(t[p].v1,t[p].v3,0);}}
int hull(vector<P>&pa,int x,int y){int l=0,r=pa.size()-1,ans=LLONG_MIN;while(l<r){
int mid=l+r>>1;if(dot({x,y},pa[mid])<dot({x,y},pa[mid+1]))l=mid+1;else r=mid;}
return dot({x,y},pa[l]);}
int ask(int p,int l,int r,int ql,int qr,int x,int y){
if(ql<=l&&r<=qr)if(y>=0)return hull(t[p].v2,x,y);else return hull(t[p].v3,x,y);
int ans=LLONG_MIN;int mid=l+r>>1;
if(ql<=mid)ans=max(ans,ask(p<<1,l,mid,ql,qr,x,y));
if(qr>mid)ans=max(ans,ask(p<<1|1,mid+1,r,ql,qr,x,y));return ans;}
signed main(){
int i,j,k,x,y,z,q,c,m,n;
ios::sync_with_stdio(0),cin.tie(0);
char o;cin>>n>>o;int cnt=0;int ans=0;for(x=1;x<=n;x++){
char op;cin>>op;if(op=='A'){int x1,y1;cin>>x1>>y1;x1=(o!='E'?decode(x1,ans):x1);
y1=(o!='E'?decode(y1,ans):y1);upd(1,1,n,++cnt,x1,y1);}else{int x1,y1,l,r;cin>>x1>>y1>>l>>r;
l=(o!='E'?decode(l,ans):l);r=(o!='E'?decode(r,ans):r);x1=(o!='E'?decode(x1,ans):x1);
y1=(o!='E'?decode(y1,ans):y1);ans=ask(1,1,n,l,r,x1,y1);printf("%lld\n",ans);}}return 0;}