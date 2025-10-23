// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e5;
const ll INF=1e17;
using namespace std;
int n;
unsigned int a[maxn];
bool b[40][maxn];  
int last[maxn]; // 代表某一位 i 最前面的一个0在哪里
array<db,3>ans;
void cal1(){
    db base=1.0;
    db cnt=0.0;
    base=base/pow(n,2);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=29;j++){
            if(b[j][i]) {
                cnt=cnt+(base*(1<<j));
            }
        }
    }
    //cout<<cnt<<"\n";
    for(auto &u:ans) u+=cnt;
    return ;
}
void caland(){
    db base=2.0;
    ll cnt=0.0;
    base=base/pow(n,2);
    for(int j=0;j<=29;j++){
        int pre=0;
        for(int i=1;i<=n;i++){
            if(!b[j][i] ) pre=i;
            last[i]=pre;
        }
        for(int i=n;i>=1;i--){ //这里是我们枚举这个右端点
            if(!b[j][i]) continue;
            // 最右边为1 只要选0在last[i]之后就行了
            int l=last[i],r=i; // 只要你在这个区间里就行 
            cnt=cnt+((1ll<<j)*(r-l-1) );
        }
    }
    ans[1]=ans[1]+(base*cnt); // 每个区间被选的概率都是2/n*n cnt是总和
    return ;
}
void calor(){ // 如果是or的话 我们只要观察1的位置就可以了
    // 具体的 还是枚举右端点 如果一个数是1 那么前面任意选 如果一个数是0 那么只能选0最近的一个1和之前
    db base=2.0;
    ll cnt=0.0;
    base=base/pow(n,2);
    for(int j=0;j<=29;j++){
        int pre=0;
        for(int i=1;i<=n;i++){
            if(b[j][i] ) pre=i;
            last[i]=pre;
        }
        for(int i=n;i>=1;i--){ //这里是我们枚举这个右端点
            if(b[j][i]) {
                cnt=cnt+(1ll<<j)*(i-1);
            }
            else{
                if(last[i]==0) continue;
                else cnt=cnt+(1ll<<j)*(last[i]);
            }
        }
    }
    ans[2]=ans[2]+(base*cnt); // 每个区间被选的概率都是2/n*n cnt是总和
    return ;
}
void calxor(){
    db base=2.0;
    ll cnt=0.0;
    base=base/pow(n,2);
    for(int j=0;j<=29;j++){
        int c1=0,c2=0;
        if(b[j][1]) c2++;
        else c1++;
        for(int i=2;i<=n;i++){
            if(b[j][i]) cnt=cnt+(1ll<<j)*c1;
            else cnt=cnt+(1ll<<j)*c2;
            c1++;
            if(b[j][i]) swap(c1,c2);
        }
    }
    ans[0]=ans[0]+(base*cnt); // 每个区间被选的概率都是2/n*n cnt是总和
    return ;
}
void slove(){
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=29;j++){
            b[j][i]=(a[i]&(1<<j));
        }
    }
    cal1(); // 这里是计算长度为1的区间 那么显然每个点做贡献的概率都是1/n*2
    caland(); // 这里是直接计算剩下区间长度为2的 并且是区间and的和
    calor();// 同理
    calxor();//同理
    cout<<fixed<<setprecision(3)<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
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