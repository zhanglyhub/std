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
const int MX=1e5+5;int mk[MX];
struct P{int x,y;}a[MX],b[MX];P b1[MX],b2[MX];
P operator-(P a,P b){return {a.x-b.x,a.y-b.y};}
P operator+(P a,P b){return {a.x+b.x,a.y+b.y};}
bool operator==(P a,P b){return a.x==b.x&&a.y==b.y;}
bool operator<(P a,P b){if(a.x!=b.x)return a.x<b.x;return a.y<b.y;}
int dot(P a,P b){return {a.x*b.x+a.y*b.y};}
int xj(P a,P b){return a.x*b.y-a.y*b.x;}
int build(P*a,int n,P*b){int x,p=0;static int vis[MX],s[MX];MST(vis);
for(x=1;x<=n;x++){while(p>=2){if(xj(a[s[p]]-a[s[p-1]],a[x]-a[s[p]])>=0)vis[s[p--]]=0;
else break;}vis[s[++p]=x]=1;}int rp=p;for(x=n;x;x--){
while(rp>p){if(xj(a[s[rp]]-a[s[rp-1]],a[x]-a[s[rp]])>=0)vis[s[rp--]]=0;
else break;}vis[s[++rp]=x]=1;}int pos=0;while(rp)b[++pos]=a[s[rp--]];
pos=unique(b+1,b+pos+1)-b-1;return pos;}
signed main(){
int i,j,k,T,x,y,z,q,m,n;
ios::sync_with_stdio(0),cin.tie(0);
cin>>n>>m>>q;for(x=1;x<=n;x++)cin>>a[x].x>>a[x].y;
for(x=1;x<=m;x++)cin>>b[x].x>>b[x].y,b[x].x=-b[x].x,b[x].y=-b[x].y;
sort(a+1,a+n+1);sort(b+1,b+m+1);int f1=build(a,n,b1),f2=build(b,m,b2);
static P ans[N];int p=0,t1,t2;
for(t1=t2=1;t1<f1&&t2<f2;){ans[++p]=b1[t1]+b2[t2];
++(xj(b1[t1+1]-b1[t1],b2[t2+1]-b2[t2])>0?t1:t2);}
if(t1==f1)while(t2<=f2)ans[++p]=b1[t1]+b2[t2++];
else while(t1<=f1)ans[++p]=b1[t1++]+b2[t2];
for(x=1;x<=q;x++){int dx,dy;cin>>dx>>dy;int l,r,mid,pos=0;
if(xj(ans[p]-ans[1],P{dx,dy}-ans[1])>0||(xj(ans[p]-ans[1],P{dx,dy}-ans[1])==0
&&dot(P{dx,dy}-ans[1],ans[p]-ans[1])>0)){printf("0\n");continue;}
if(xj(ans[2]-ans[1],P{dx,dy}-ans[1])>0||(xj(ans[2]-ans[1],P{dx,dy}-ans[1])==0
&&dot(P{dx,dy}-ans[1],ans[2]-ans[1])>0)){printf("0\n");continue;}
l=2;r=p-1;while(l<=r){int mid=l+r>>1;if(xj(ans[mid+1]-ans[mid],ans[mid]-P{dx,dy})>=0)
pos=mid,l=mid+1;else r=mid-1;}
if(xj(ans[pos+1]-ans[pos],P{dx,dy}-ans[pos])>0)printf("1\n");else printf("0\n");}
return 0;}