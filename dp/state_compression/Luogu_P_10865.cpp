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
const int maxn=2200000;
const ll INF=1e17;
using namespace std;
int xx[5]={0,1,0,-1,0};
int yy[5]={0,0,1,0,-1};
int n,m,k,x,y,a;
int dp[maxn]; // 把状态清空到0的最佳方案
vector<array<int,3> > p;
vector<int >e[60];
int num[20];
void slove(){
    vector< array < int , 2 > > pos ;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        cin>>x>>y>>a;
        p.push_back({x,y,a});
    }
    sort(p.begin(),p.end(),[](const array<int,3> &b,const array<int,3> &c){
        if(b[0]!=c[0]) return b[0]<c[0];
        else return b[1]<c[1];
    }
    );
    vector<unsigned int> pow4(k+1, 1u);
    for(int i=1;i<=k;i++) pow4[i] = (pow4[i-1] << 2);
    int cnt=0,len=0;
    for(auto u:p){
        num[len]=u[2];
        pos.push_back({u[0],u[1]});
        len=pos.size();
        cnt=cnt+u[2]*(1<<(2*(len-1))); //attenion  这里是四进制         
    }
    vector<int > boom[60];
    auto has = [&](int x,int y){
        return x*5+y;
    };
    auto inb = [&](int x,int y){ return 1<=x && x<=n && 1<=y && y<=m; };
    for(int j=0;j<k;j++){ // 枚举这次要删掉那个格子
        for(int idx=0;idx<=4;idx++){
                int tx=pos[j][0]+xx[idx];
                int ty=pos[j][1]+yy[idx];
                if( !inb(tx,ty)) continue;
                for(int i=0;i<k;i++){
                    if((abs(tx-pos[i][0])+abs(ty-pos[i][1]))<=1){
                        e[has(j,idx)].push_back(i);
                    }
                }          
        }
    }
    for(int i=1;i<2100000;i++) dp[i]=100;
    dp[0]=0;
    for(int i=0;i<cnt;i++){
        for(int j=0;j<k;j++){ // 枚举这次要删掉那个格子
            for(int idx=0;idx<4;idx++){
                int tmp=i;
                for(auto u:e[has(j,idx)]){
                    if(((tmp/pow4[u])%4<num[u]) ) tmp=tmp+pow4[u];
                }
                //cout<<tmp<<" "<<i<<endl;
                dp[tmp]=min(dp[tmp],dp[i]+1);
            }
        }
    }
    cout<<dp[cnt];
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