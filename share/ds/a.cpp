#include<bits/stdc++.h>
// #pragma GCC optimize("inline")
// #pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)
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
#define cln cerr<<"Line:   "<<__LINE__<<"    "
#define pct __builtin_popcountll
#define ctz __builtin_ctzll
#define mkp make_pair
#define MST(x) memset(x,0,sizeof(x))
#define all(x) x.begin(),x.end()
using namespace std;
constexpr int N=(1<<21)+100,_g=3,M1=1e9+7,M2=1e9+9,M=998244353;
using ll=long long;
namespace fast_io{
    char buf[N+5],*p1,*p2,c;
    #define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,N,stdin),p1==p2)?EOF:*p1++)
    inline int read(){
        int an=0,f=1;while(!isdigit(c=gc))if(c=='-')f=-f;
        do an=an*10+(48^c);while(isdigit(c=gc));return an*f;
    }int ot;char ob[N+20],stk[20],t;
    inline void fls(){
        fwrite(ob,1,ot,stdout),ot=0;
    }inline void write(ll x){
        if(x<0)ob[ot++]='-',x=-x;
        while(x>9)stk[++t]=48^(x%10),x/=10;
        for(ob[ot++]=48^x;t;ob[ot++]=stk[t--]);
        ob[ot++]='\n';if(ot>N)fls();
    }
}
using fast_io::read;
using fast_io::write;
// using namespace fast_io;
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
using ul=unsigned long long;
template<typename tp1,typename tp2>
    void chkmx(tp1 &x,const tp2 &y){if(x<y)x=y;}
template<typename tp1,typename tp2>
    void chkmn(tp1 &x,const tp2 &y){if(x>y)x=y;}
void add(int &x,int y){(x+=y)>=M?x-=M:0;}
void del(int &x,int y){(x-=y)<0?x+=M:0;}
void add(int &x,ul y,int z){x=(y*z+x)%M;}
void del(int &x,ul y,int z){(x-=y*z%M)<0&&(x+=M);}
int qp(ll a,ll x=M-2){
    int res=1;for(;x;x>>=1,a=a*a%M)
        (x&1)&&(res=a*res%M);return res;
}
int qp(ll a,ll x,int M){
    int res=1;for(;x;x>>=1,a=a*a%M)
        (x&1)&&(res=a*res%M);return res;
}
struct NTP{};
template<typename tp1,typename tp2,int N>
struct Htb{
    static constexpr int M=1e7+19;
    int hd[M+3],to[N],ct;
    tp1 ed[N];tp2 w[N];
    static int hc(ul v){
        v^=v<<13,v^=v>>7;
        return (v^(v<<17))%M;
    }
    void ins(tp1 x,tp2 y){
        int &p=hd[hc(x)];
        ed[++ct]=x,to[ct]=p;
        w[p=ct]=y;
    }
    int count(tp1 x){
        for(int i=hd[hc(x)];i;i=to[i])
            if(ed[i]==x)return 1;
        return 0;
    }
    pair<tp2,bool>find(tp1 x){
        for(int i=hd[hc(x)];i;i=to[i])
            if(ed[i]==x)return mkp(w[i],true);
        return mkp(tp2(),false);
    }
    int operator[](tp1 x){
        int &p=hd[hc(x)];
        for(int i=p;i;i=to[i])
            if(ed[i]==x)return i;
        ed[++ct]=x,to[ct]=p;
        return p=ct;
    }
    void clear(){while(ct)hd[hc(ed[ct--])]=0;}
};
namespace MATH{
    vector<int>jc,nv,_nv;
    int dv2(int x){return x&1?x+M>>1:x>>1;}
    int C(int n,int m){
        assert(m<=n);
        return 1ll*jc[n]*nv[m]%M*nv[n-m]%M;
    }
    int P(int n,int m){
        return 1ll*jc[n]*nv[n-m]%M;
    }
    int D(int n,int m){
        if(n<0||m<0)return 0;
        if(!n)return 1;
        if(!m)return 0;
        return C(n+m-1,m-1);
    }
    void init(int n){
        int x;
        jc.resize(n+2);
        jc[0]=jc[1]=1;
        nv=_nv=jc;
        for(x=2;x<=n;++x){
            jc[x]=1ll*x*jc[x-1]%M;
            _nv[x]=ll(M-M/x)*_nv[M%x]%M;
            nv[x]=1ll*nv[x-1]*_nv[x]%M;
        }
    }
}
struct DET{
    int a[3005][3005],n;
    int run(){
        if(!n)return 1;
        int x,y,z,k,res=1;
        for(x=1;x<=n;++x){
            for(y=x;y<=n&&!a[y][x];++y);
            if(y>n)return 0;
            if(y>x){
                for(k=1;k<=n;++k)swap(a[x][k],a[y][k]);
                res&&(res=M-res); 
            }
            k=qp(a[x][x]);
            res=1ll*res*a[x][x]%M;
            for(z=1;z<=n;++z)
                a[x][z]=1ll*a[x][z]*k%M;
            for(y=1;y<=n;++y)
                if(x!=y){
                    k=a[y][x];
                    for(z=1;z<=n;++z)
                        del(a[y][z],a[x][z],k);
                }
        }
        for(x=1;x<=n;++x)
            res=1ll*res*a[x][x]%M;
        return res;
    }
}det;
ll Gcd(ll x,ll y){
    if(!x||!y)return x|y;
    int k=min(ctz(x),ctz(y));
    ll d;y>>=ctz(y);
    while(x){
        x>>=ctz(x),d=x-y;
        if(x<y)y=x;
        if(d<0)x=-d;
        else x=d;
    }return y<<k;
}
using ll=long long;
using ul=unsigned long long;
constexpr int bceil(int n){return 1<<(std::__lg(n-1)+1);}
template<int mod>struct NTT{
    constexpr int dil(int x){return x>>31?x+mod:x;}
    constexpr int mul(ul x,int y){return x*y%mod;}
    constexpr int qpow(int a,int b,int r=1){for(;b;a=mul(a,a),b>>=1){r=b&1?mul(r,a):r;}return r;}
    int w[N>>1],wI[N>>1];
    void init(int n){
        int l=bceil(n)>>1;w[0]=wI[0]=1;
        for(int i=1;i<l;i<<=1){w[i]=qpow(_g,((mod-1)>>2)/i),wI[i]=qpow(_g,mod-1-((mod-1)>>2)/i);}
        for(int i=1;i<l;++i){w[i]=mul(w[i&(i-1)],w[i&-i]),wI[i]=mul(wI[i&(i-1)],wI[i&-i]);}
    }
    void dif(int *f,int lim){
        for(int l=lim>>1,r=lim;l;l>>=1,r>>=1)
            for(int*j=f,*o=w;j!=f+lim;j+=r,++o)
                for(int*k=j,x,y;k!=j+l;++k)
                    (x=*k)>=mod&&(x-=mod),y=mul(k[l],*o),*k=x+y,k[l]=x-y+mod;
    }
    void dit(int *f,int lim){
        for(int l=1,r=2;l<lim;l<<=1,r<<=1)
            for(int*j=f,*o=wI;j!=f+lim;j+=r,++o)
                for(int*k=j,x,y;k!=j+l;++k)
                    x=*k,y=mod-k[l],(*k=x-y)<0&&(*k+=mod),k[l]=mul(x+y,*o);
        for(int i=0,p=mod-(mod-1)/lim;i<lim;++i)f[i]=1ll*f[i]*p%mod;
    }
    void mul(int *f,int *g,int n){
        dif(f,n),dif(g,n);
        for(int i=0;i<n;++i)f[i]=1ll*f[i]*g[i]%M;
        dit(f,n);
    }
    void mul_(int *f,int *g,int n){
        static int g_[N];
        for(int i=0;i<n;++i)g_[i]=g[i];
        dif(f,n),dif(g_,n);
        for(int i=0;i<n;++i)f[i]=1ll*f[i]*g_[i]%M;
        dit(f,n);
    }
    void mul(int *f,int n){
        dif(f,n);int i;
        for(i=0;i<n;++i)f[i]=1ll*f[i]*f[i]%M;
        dit(f,n);
    }
};
NTT<M>ntt;
// using namespace MATH;
mt19937_64 rg(random_device{}());
using LL=__int128_t;
using vt=vector<int>;
using vl=vector<ll>;
using ld=double;        
//using namespace fast_io;
// int a[N],val[N],l[N],r[N];
// struct P{int x,y};
// P operator+(P a,P b){return {a.x+b.x,a.y+b.y};}
// int xj(P a,P b){return a.x*b.y-b.x*a.y;}
// struct T{P l[N],r[N],m[N],mx[N];int sl,sr,sm,op,mxl,mxr;}*t[N];
// void add(int p){int t,t1,t2;int sl=t[p<<1]->sm,sr=t[p<<1|1]->sm;
// for(t=t1=t2=1;t1<=sl||t2<=sr;t++,t1++,t2++){t[p]->m[t]=t[p<<1]->m[t1]+t[p<<1|1]->m[t2];}
// t[p]->sm=t[p<<1]->sm+t[p<<1|1]->sm;}//add lsum+rsum
// void mg1(int p){int pl=t[p<<1]->sm,pr=t[p<<|1]->sl;int t1,t2,t3;
// for(t1=t2=t3=1;t1<=pl||t2<=pr;t1++,t2++,t3++){t[p<<1|1]->l[t1]=t[p<<1|1]->l[t1]+t[p<<1]->m[t2];}
// t[p<<1|1]->sl+=t[p<<1]->sm;//add lsum and rperfix for prefix
// //merge lprefix hull and rprefix hull
// int s1=t[p<<1]->sl,s2=t[p<<1|1]->sl;t[p]->sl=s1+s2;
// for(t1=t2=1,t3=0;t1<s1&&t2<s2;){t[p]->m[++t3]=t[p<<1]->l[t1]+t[p<<1|1]->l[t2];
// ++(xj(t[p<<1]->l[t1+1]-t[p<<1]->l[t1],t[p<<1|1]->l[t2+1]-t[p<<1|1]->l[t2])>0?t1:t2);
// if(t1==s1)while(t2<=s2)t[p]->l[++t3]=t[p<<1]->l[t1]+t[p<<1|1]->l[t2++];
// else while(t1<=s1)t[p]->l[++t3]=t[p<<1|1]->l[t1++]+t[p<<1|1]->r[t2];}
// }
// //add rsum and lsuffix 
// //merge rsuffix hull and lsuffix hull
// void mg2(int p){int pl=t[p<<1|1]->sm,pr=t[p<<1]->sr;int t1,t2,t3;
// for(t1=t2=t3=1;t1<=sl&&t2<=sr;t1++,t2++,t3++){t[p<<1]->l[t1]=t[p<<1]->l[t1]+t[p<<1|1]->m[t2];}
// t[p<<1]->sr+=t[p<<1|1]->sm;
// //merge
// int s1=t[p<<1]->sr,s2=t[p<<1|1]->sr;t[p]->sr=s1+s2;
// for(t1=t2=1,t3=0;t1<s1&&t2<s2;){t[p]->m[++t3]=t[p<<1]->r[t1]+t[p<<1|1]->r[t2];
// ++(xj(t[p<<1]->r[t1+1]-t[p<<1]->r[t1],t[p<<1|1]->r[t2+1]-t[p<<1|1]->r[t2])>0?t1:t2);
// if(t1==s1)while(t2<=s2)t[p<<1]->r[++t3]=t[p<<1]->r[t1]+t[p<<1|1]->r[t2++];
// else while(t1<=s2)t[p<<1]->r[++t3]=t[p<<1]->r[t1++]+t[p<<1|1]->r[t2];}
// }
// //merge for subsum
// void mg3(int p){int p1=t[p<<1]->sr,p2=t[p<<1|1]->sl;t[p]->mxl=p1+p2;
// t[p]->mxr=p1+p2;int t1,t2,t3;static P tmp[N];
// for(t1=t2=1,t3=0;t1<p1&&t2<p2;){tmp[++t3]=t[p<<1]->r[t1]+t[p<<1|1]->l[t2];
// ++(xj(t[p<<1]->r[t1+1]-t[p<<1]->r[t1],t[p<<1|1]->l[t2+1]-t[p<<1|1]->l[t2])>0?t1:t2);
// if(t1==p1)while(t2<=p2)tmp[++t3]=t[p<<1]->r[t1]+t[p<<1|1]->l[t2++];
// else while(t1<=p2)tmp[++t3]=t[p<<1]->r[t1++]+t[p<<1|1]->l[t2];}//hull=lsuff and rperfix
// //submax=max(lsmax,rsmax,hull)
// //merge for lsmax,rsmax
// p1=t[p<<1]->mxr,p2=t[p<<1|1]->mxl;t1=t2=1;t3=0;int len=
// for(t1=t2=1,t3=0;t1<p1&&t2<p2;){t[p]->mx[++t3]=t[p<<1]->mx[t1]+t[p<<1|1]+mx[t2];
// ++(xj(t[p<<1]->mx[t1+1]-t[p<<1]+mx[t],t[p<<1|1]->mx[t2+1]-t[p<<1|1]->mx[t2])>0?t1:t2);}
// if(t1==p1)while(t2<=p2)t[p]->mx[++t3]=t[p<<1]->mx[t1]+t[p<<1|1]->mx[t2++];
// else while(t1<=p1)t[p]->mx[++t3]=t[p<<1]->mx[t1++]+t[p<<1|1]->mx[t2];
// //merge for hull,result of ls and rs
// }
// void upd(int p,int l,int r,int ql,int qr,int x){
// if(ql<=l&&r<=qr){t[p]->op=x;return;}int mid=l+r>>1;
// if(ql<=l)upd(p<<1,l,mid,ql,qr,x);if(qr>mid)upd(p<<1|1,mid+1,r,ql,qr,x);}
// void solve(int l,int r,int p,int idx){if(l==r)return;int mid=l+r>>1;solve(p<<1,l,mid);
// solve(p<<1|1,mid+1,r);if(idx==r){add(p);mg1(p);mg2(p);}}
const int MX=600050;
int a[300050],ptr,bk,bks;
struct P{ll x,y;}pool[MX*3];
bool cmp(const P&a,const P&b){if(a.x!=b.x)return a.x<b.x;return a.y<b.y;}
P operator+(P a,P b){return {a.x+b.x,a.y+b.y};}
P operator-(P a,P b){return {a.x-b.x,a.y-b.y};}
bool operator==(P a,P b){return a.x==b.x&&a.y==b.y;}
int xj(P a,P b){return a.x*b.y-a.y*b.x;}
int dot(P a,P b){return a.x*b.x+a.y*b.y;}
struct hull{int a;int len,mk;hull():a(0),len(0),mk(N){}void init(int x){a=x;len=0;}
P&operator[](int x){return pool[a+x];}};struct T{hull ls,rs,mx;P sum;}t[MX];
void bh(P a,hull&b){assert(b.len+1<MX);
while(b.len>=2&&xj(b[b.len]-b[b.len-1],a-b[b.len])>=0)
b[b.len--]={0,0};b[++b.len]=a;}
void hb(hull&a,P s,hull&b,hull&c){c.a=ptr;c.len=0;int x,y,k;
for(x=1,y=1,k=0;x<=a.len&&y<=b.len;){if(cmp(a[x],b[y]+s))
bh(a[x++],c);else bh(b[y++]+s,c);}while(x<=a.len)
bh(a[x++],c);while(y<=b.len)bh(b[y++]+s,c);ptr+=a.len+b.len;}
void cal(hull&a,hull&b,hull&c){c.a=ptr;c.len=0;int t,t1,t2;
for(t1=1,t2=1;t1<a.len&&t2<b.len;){c[++c.len]=a[t1]+b[t2];
++(xj(a[t1+1]-a[t1],b[t2+1]-b[t2])>0?t2:t1);}if(t1==a.len)
while(t2<=b.len)c[++c.len]=a[t1]+b[t2++];else while(t1<=a.len)
c[++c.len]=a[t1++]+b[t2];ptr+=c.len;}
void up(int p){
    t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
    hb(t[p<<1].ls,t[p<<1].sum,t[p<<1|1].ls,t[p].ls);
    hb(t[p<<1|1].rs,t[p<<1|1].sum,t[p<<1].rs,t[p].rs);
    hull tmp1;cal(t[p<<1].rs,t[p<<1|1].ls,tmp1);
    hull tmp2;hb(t[p<<1].mx,P{0,0},t[p<<1|1].mx,tmp2);
    hb(tmp2,P{0,0},tmp1,t[p].mx);
}
P bd(int l,int r,hull&ls,hull&rs,hull&mx){
    if(l==r){
        ls.a=ptr++;ls.len++;ls[1]=P{a[l],1};
        rs.a=ptr++;rs.len++;rs[1]=P{a[l],1};
        mx.a=ptr++;mx.len++;mx[1]=P{a[l],1};
        return P{a[l],1};
    }   
    int mid=l+r>>1;hull ls1,ls2,rs1,rs2,mx1,mx2;P lsm,rsm;
    lsm=bd(l,mid,ls1,rs1,mx1);rsm=bd(mid+1,r,ls2,rs2,mx2);//merge 
    hb(ls1,lsm,ls2,ls);hb(rs2,rsm,rs1,rs);
    hull tp;cal(rs1,ls2,tp);
    hull tmp;hb(mx1,P{0,0},mx2,tmp);
    hb(tp,P{0,0},tmp,mx);
    return lsm+rsm;
}
void cpy(hull&a,int&p){
int x;for(x=1;x<=a.len;x++)pool[p+x]=a[x];
a.a=p;p+=a.len+1;}
void build(int p,int l,int r){
    if(r-l+1<=bk){
        int p1=ptr;
        t[p].sum=bd(l,r,t[p].ls,t[p].rs,t[p].mx);
        int p2=p1;
        //|------||---ls---||---rs---||---mx---|
        //  p1        ls.len      rs.len   mx.len

        cpy(t[p].ls,p2);
        cpy(t[p].rs,p2);
        cpy(t[p].mx,p2);
        ptr=p2;
        return;
    }
        int mid=l+r>>1;
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        up(p);
    }
struct H{int L,R,val,id;short op;}U[MX];
bool cp(H&a,H&b){if(a.val!=b.val)return a.val<b.val;return a.id<b.id;}
struct G{ll ls,rs,mx,sum;G():ls(0),rs(0),mx(0),sum(0){}
G(ll ls,ll rs,ll mx,ll sum):ls(ls),rs(rs),mx(mx),sum(sum){}};
G mg(G&a,G&b){G res;res.sum=a.sum+b.sum;res.ls=max(a.ls,a.sum+b.ls);
res.rs=max(b.rs,b.sum+a.rs);res.mx=max({(a.rs+b.ls),a.mx,b.mx});return res;}
ll ask(hull&a,P val){
    int x=min(a.len,a.mk);int res=0;for(;x;x--)if(res<dot(a[x],val))
    a.mk=x,res=dot(a[x],val);
    return res;
}
G bf(int l,int r,int val){int x;ll mx=0,mx1=0,sum=0,ls=0;for(x=l;x<=r;x++){sum+=a[x]+val;
mx1=max(ll(a[x]+val),ll(mx1+a[x]+val));mx=max(mx,mx1);ls=max(ls,sum);}ll rs=0,rsm=0;for(x=r;x>=l;x--){rsm+=a[x]+val;
rs=max(rs,rsm);}return {ls,rs,mx,sum};}
G solve(int p,int l,int r,int ql,int qr,int val){
    if(ql<=l&&r<=qr){
        if(r-l+1<bk) return bf(l,r,val);
        G res;
        res.sum=dot(t[p].sum,P{1,val});
        res.ls=ask(t[p].ls,P{1,val});
        res.rs=ask(t[p].rs,P{1,val});
        res.mx=ask(t[p].mx,P{1,val});
        return res;
    }
    int mid=l+r>>1;G L,R;
    if(ql<=mid)L=solve(p<<1,l,mid,ql,qr,val);
    if(qr>mid)R=solve(p<<1|1,mid+1,r,ql,qr,val);
    return mg(L,R);
}
signed main(){
int i,j,k,x,y,z,c,n,m;
// ios::sync_with_stdio(0),cin.tie(0);
n=read();m=read();for(x=1;x<=n;x++)a[x]=read();
bk=__lg(n);if(bk==0)bks=bk=1;else bks=n/max(bk,1ll)+1;
build(1,1,n);vl res(m+2,-1);
for(x=1;x<=m;x++){U[x].op=read();if(U[x].op==1){U[x].val=read();}
else U[x].L=read(),U[x].R=read();U[x].val+=U[x-1].val,U[x].id=x;}
sort(U+1,U+m+1,cp);
for(x=1;x<=m;x++){if(U[x].op==2){G da=solve(1,1,n,U[x].L,U[x].R,U[x].val);
res[U[x].id]=max({da.ls,da.rs,da.mx,da.sum});}}
for(x=1;x<=m;x++)if(res[x]!=-1)write(res[x]);fast_io::fls();
return 0;}
//不想卡了吐了

//hack:
// 9 5
// 4 9 3 5 9 5 10 -4 -2 
// 1 -8
// 2 3 9
// 1 2
// 2 5 6
// 1 -10
