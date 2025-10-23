#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
#include<queue>
#include<stack>
#include<iomanip>
#include<algorithm>
typedef unsigned long long  ll;
typedef long double db;
const long double pi = std::acos(-1);
const long double eps = 1e-30;
const ll mod=1e9+7;
const int maxn=4e5+100;
db r,ans,area; // 代表整个园的面积
db pos[7][3];
int t;
struct point{
    db x,y;
    point() : x(0), y(0) {};
    //显式定义接受两个参数的构造函数
     point(db _x, db _y) : x(_x), y(_y) {};
};
point operator-(const point &a, const point &b) {
    return {a.x - b.x, a.y - b.y};
}
point operator+(const point &a, const point &b) {
    return {a.x + b.x, a.y + b.y};
}
point operator*(const point &a, db b) {
    return {a.x * b, a.y * b};
}
point p[5];
db cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
point trans(db x){
    return point{ eps+r*(db)std::cos(x / 180 * pi),eps+r*(db)std::sin(x / 180 * pi) };
}
point intersection_point( point a,point b ,point c,point d){ // 计算线段AB和线段CD的交点
    point v=b-a,w=d-c,pq=a-c;
    db t=cross(pq,w)/cross(w,v);
    return a+v*t;
}
db calc(db a,db b,db c,db d){
    db s=0.0;
    p[0]=trans(a);
    p[1]=trans(b);
    p[2]=trans(c);
    p[3]=trans(d);
     db angle=(a-b);
     if(angle<0) angle=360+angle;
    //std::cout<<angle/180*pi<<"\n"; // 角度是对的
    s=s+area*angle/360;
    if(angle<180) s=s-fabs(cross(p[0],p[1]))*0.5+eps; // 这里要注意 角度大于180的时候 扇形加上三角形面积才是要减去的大扇形
    else s=s+fabs(cross(p[0],p[1]))*0.5+eps; //其实就是优弧和劣弧的区别 详见cycle那个图
    point z=intersection_point(p[0],p[2],p[1],p[3]);
    s=s+0.5*fabs(cross(z-p[0],z-p[1]) );
    return s;
}
void slove(){
    std::cin>>r;
    area=pi*r*r;
    ans=area;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=5;j++){
            std::cin>>pos[j][i];
        }
    }
    db sum=0.0;
    sum+=calc(pos[1][1],pos[5][2],pos[4][2],pos[2][1]);
    sum+=calc(pos[5][1],pos[4][2],pos[3][2],pos[1][1]);
    sum+=calc(pos[4][1],pos[3][2],pos[2][2],pos[5][1]);
    sum+=calc(pos[3][1],pos[2][2],pos[1][2],pos[4][1]);
    sum+=calc(pos[2][1],pos[1][2],pos[5][2],pos[3][1]);
    std::cout<<ans-sum<<"\n";
    return ;
}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin>>t;
    std::cout<<std::fixed<<std::setprecision(9);
    while(t--){
        slove();
    }
    return 0;
}