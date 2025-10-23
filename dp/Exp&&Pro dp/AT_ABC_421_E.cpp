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
const int maxn=1e4;
const ll INF=1e17;
using namespace std;
db p[maxn];
db dp[4][maxn];
db score[maxn];
db dfs(int k,int state){ // k是我们还能扔多少次 state是我们已经固定了几个
    if(dp[k][state]>0+eps) return dp[k][state];
    dp[k][state]=0;
    if(k==1){
        int cnt=0;
        //cout<<k<<" "<<state<<" "<<dp[k][state]<<endl;
        for(int i=0;i<(1<<6);i++){ // 枚举所有可能扔出来的形状
            if( (state&i)!=state) continue; // 固定的不能变
            cnt++;
            dp[k][state]+=score[state|i];
            cout<<(state|i)<<"\n";
        }     
        //cout<<k<<" "<<state<<" "<<dp[k][state]<<endl;
        dp[k][state]/=cnt;
        return dp[k][state];
    }
    int cnt=0;
    for(int i=0;i<(1<<6);i++){ // 枚举所有可能扔出来的形状
            if( (state&i)!=state) continue; // 固定的不能变
            cnt++;
            db t=0;
            for(int j=0;j<(1<<6);j++){
                if((j|i)!=i) continue; 
                t=max(t,dfs(k-1,state|j));
            }   
            dp[k][state]+=t;
    }     
    dp[k][state]/=cnt;
    return dp[k][state];
}
db init(int x){
    db s=0;
    map<db,db>mp;
    for(int i=0;i<6;i++){
        if(x&(1<<i)) continue;
        else mp[p[i]]+=p[i];
    }
    for(int i=1;i<=6;i++) s=max(s,mp[p[i]]);
    return s;
}
void slove(){
    for(int i=1;i<=6;i++){
        cin>>p[i];
    }
    
    cout<<fixed<<setprecision(10)<<dfs(3,0);
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