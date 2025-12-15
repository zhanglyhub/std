#include<bits/stdc++.h>
// #pragma GCC optimize("inline")
// #pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)
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
void ckmx(tp1&a,tp2&b){if(a<b)a=b;}
template<typename tp1,typename tp2>
void ckmn(tp1&a,tp2&b){if(a>b)a=b;}
template<typename tp1>
void ckabs(tp1&x){if(x<0)x=-x;}
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
const int W=500005,B=W+63>>6;
struct Bit{ui64 a[B];Bit(){reset();}
inline void reset(){MST(a);}
inline bool get(int x){return (a[x>>6]>>(x&63))&1ull;}
inline void set(int x){a[x>>6]|=1ull<<(x&63);}
inline void uset(int x){a[x>>6]&=~(1ull<<(x&63));}
Bit operator+(const Bit&b){Bit r;unsigned __int128 ck=0;
for(int i=0;i<B;i++){unsigned __int128 sum=(unsigned __int128)a[i]+b.a[i]+ck;r.a[i]=(ui64)sum;
ck=sum>>64;}return r;}
bool operator[](int x){return get(x);}};
int main(){
int i,j,k,x,y,z,T,q,c,m,n;
ios::sync_with_stdio(0),cin.tie(0);
for(cin>>T;T--;){string s;cin>>n>>s;int c1=0,c0=0,cnt1=0,cnt2=0;
Bit ans1,ans2,res;
for(i=0;i<n;i++){if(48^s[i])c1++;else c0++;if(c1>=n-i-1)break;}
for(x=0;x<=i;x++){if(48^s[x])ans1.set(cnt1),cnt1++;}
for(x=n-i-2,y=i+1;x>=0;x--,y++)if(48^s[y])ans2.set(x);res=ans1+ans2;
for(k=n+1;k>=0;k--)if(res[k])break;if(k<0){printf("0\n");continue;}
for(x=k;x>=0;x--)printf("%d",res[x]);printf("\n");}
return 0;}