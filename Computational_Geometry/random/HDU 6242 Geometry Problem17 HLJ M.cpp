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
struct point {
    db x,y;
};
point operator-(const point &a, const point &b) {
    return {a.x - b.x, a.y - b.y};
}
db sq(point a){
    return a.x*a.x+a.y*a.y;
}
int Rand(int L, int R) {//区间内随机数生成函数
    return (ll)rand() * rand() % (R - L + 1) + L;
}
point a[maxn];
db dis(point a,point b){
    return  sq(a-b);
}
db rx,ry,r;
void make_crcycle3(point a,point b,point c){
    // cout<<a.x<<" "<<a.y<<"\n";
    // cout<<b.x<<" "<<b.y<<"\n";
    // cout<<c.x<<" "<<c.y<<"\n";
    if( (a.x-b.x)*(a.y-c.y)-(a.x-c.x)*(a.y-b.y)<=eps){ //判断共线的情况
        r=rx=ry=0;
		return ;
    }
   db c1=0.5*( dis(point{0.0,0.0},b)-dis(point{0.0,0.0},a) );
    db c2=0.5*( dis(point{0.0,0.0},c)-dis(point{0.0,0.0},a) );
    db a1=b.x-a.x;
    db a2=c.x-a.x;
    db b1=b.y-a.y;
    db b2=c.y-a.y;
    rx=(b2*c1-b1*c2)/(b2*a1-b1*a2);
    ry=(a2*c1-a1*c2)/(a2*b1-a1*b2);
    r=dis(point{rx,ry},a); 
    // cout<<a.x<<" "<<a.y<<"\n";
    // cout<<b.x<<" "<<b.y<<"\n";
    // cout<<c.x<<" "<<c.y<<"\n";
    // cout<<rx<<" "<<ry<<" "<<r<<endl;
    return ;
}
bool check(array<int,3>p){
    if(p[0]==p[1] or p[0]==p[2] or p[2]==p[1]) return false;
    make_crcycle3(a[p[0]],a[p[1]],a[p[2]]);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(dis(point{rx,ry},a[i])-r<=eps) cnt++;
    }
    if(fabs(rx)>1e9||fabs(ry)>1e9||fabs(r)>1e9) return false;
    return cnt>=(n/2+1);
}
void slove(){
    srand((unsigned)time(0));
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    if(n==1){
        cout<<a[1].x<<" "<<a[1].y<<" "<<0<<"\n";return ;
    }
    if(n<=4){
        cout<<(a[1].x+a[2].x)/2<<" "<<(a[1].y+a[2].y)/2<<" ";
        cout<<sqrt((dis(a[1],a[2])))/2;
        cout<<"\n";return ;
    }
    array<int ,3>p;
    while(1){
        p[0]=Rand(1,n); p[1]=Rand(1,n);p[2]=Rand(1,n);
        if(check(p)){
            cout<<rx+eps<<" "<<ry+eps<<" "<<sqrt(r)+eps<<"\n";
            break;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    cout<<fixed<<setprecision(5);
    while(t--){
		slove();
    }
    return 0;
}