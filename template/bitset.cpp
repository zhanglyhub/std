struct Bit{ui64 a[B];Bit(){reset();}
inline void reset(){MST(a);}
inline bool get(int x){return (a[x>>6]>>(x&63))&1ull;}
inline void set(int x){a[x>>6]|=1ull<<(x&63);}
inline void uset(int x){a[x>>6]&=~(1ull<<(x&63));}
Bit operator+(const Bit&b){Bit r;unsigned __int128 ck=0;
for(int i=0;i<B;i++){unsigned __int128 sum=(unsigned __int128)a[i]+b.a[i]+ck;r.a[i]=(ui64)sum;
ck=sum>>64;}return r;}};