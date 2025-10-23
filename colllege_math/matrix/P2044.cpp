// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long double db;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=200;
using namespace std;
using i128 = __int128;
using u128 = unsigned __int128;
typedef i128 ll;
std::ostream& operator<<(std::ostream& os, i128 x){
    if(x==0){ os<<'0'; return os; }
    if(x<0){ os<<'-'; x=-x; }
    char s[50]; int n=0;
    while(x){ int d = (int)(x%10); s[n++] = char('0'+d); x/=10; }
    while(n--) os<<s[n];
    return os;
}
std::istream& operator>>(std::istream& is, i128& x){
    std::string s; is>>s; bool neg=false; size_t i=0; x=0;
    if(!s.empty() && (s[0]=='-'||s[0]=='+')){ neg=(s[0]=='-'); i=1; }
    for(; i<s.size(); ++i) x = x*10 + (s[i]-'0');
    if(neg) x = -x;
    return is;
}
ll mod;
int n;
struct  mat{
    ll a[maxn][maxn]; 
};
mat operator*(const mat&A,const mat&B){
    mat z={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                z.a[i][j]+=A.a[i][k]*B.a[k][j];
                z.a[i][j]%=mod;
                z.a[i][j]+=mod;
                z.a[i][j]%=mod;
            }
        }
    }
    return z;
}
mat quickmod(mat x,ll y){
    mat s={};
    for(int i=1;i<=n;i++) s.a[i][i]=1;
    while(y){
        if(y&1) s=s*x;
        x=x*x;
        y>>=1;
    }
    return s;
}
void slove(){
	ll p,a0,g,c,k;
    cin>>mod>>p>>c>>a0>>k>>g;
    n=2;
    if(k==0) {
        cout<<(a0%g);return ;
    }
    if(k==1){
        cout<<((a0*p+c+mod)%mod)%g;return ;
    }
    mat m={};
    m.a[1][1]=p%mod;m.a[2][2]=1ll; m.a[1][2]=1ll;
    mat ans=quickmod(m,k);
    ll num= ((ans.a[1][1]*a0)+((ans.a[1][2]*c)))%mod;
    cout<<num%g;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}