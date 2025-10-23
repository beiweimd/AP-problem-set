// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int t,n;
db x[maxn],y[maxn],w[maxn];
db ansx,ansy,dis;
db Rand(){
    return (db)rand()/RAND_MAX;
}
db sq(db a){return a*a;}
double calc(db xx,db yy){
    db res=0;
    for(int i=1;i<=n;i++){
        res+=sqrt(sq(xx-x[i])+sq(yy-y[i]))*w[i];
    }
    if(res<dis) {
        dis=res;
        ansx=xx;
        ansy=yy;
    }
    return res;
}
void sumulateAnneal(){
    double T=10000;//温度 模拟退火的一个参数 初始越大时间越长
    db nowx=ansx;
    db nowy=ansy;
    while(T>0.001){
        db nx=nowx+T*(Rand()*2-1);
        db ny=nowy+T*(Rand()*2-1);
        db deta=calc(nx,ny)-calc(nowx,nowy);
        // 计算是否更优秀
        if(exp(-deta/t)>Rand()) nowx=nx,nowy=ny;
        T*=0.97;//每次迭代多少 自己调参
    }
    for(int i=1;i<=1000;i++){
        db nx=ansx+T*(Rand()*2-1);
        db ny=ansy+T*(Rand()*2-1);
        calc(nx,ny); //继续在找到的范围内微调
    }
}
void slove(){
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>w[i];
        ansx+=x[i];ansy+=y[i];
    }
    ansx/=n;ansy/=n;
    dis=calc(ansx,ansy); // 初始的答案
    sumulateAnneal();
    cout<<fixed<<setprecision(3)<<ansx<<" "<<ansy<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    t=1;
    while(t--){
		slove();
    }
    return 0;
}