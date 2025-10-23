// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e4+100;
using namespace std;
int t,n,l,r,mid;
db ans;
struct point{
    db x,y;
};
map<pair<int,int >,int> mp ;
point p2[maxn];
db sq(db x) {return x * x;}
db dis(point a, point b) {return sqrt(sq(a.x - b.x) + sq(a.y - b.y));}
point p[maxn];
class MinCircleCover {
    public:
        MinCircleCover(const std::vector<point>& points) : points_(points) {
            if(points.empty()){
                center_={0.0,0.0};
                radius_=0.0;
            }
            else compute();
        }
    
        point getCenter() const { return center_; }
        db getRadius() const { return radius_; }
    
    private:
        std::vector<point> points_;
        point center_;
        db radius_;
    
        void compute() {
            auto p = points_; // 创建副本避免修改原始数据
            std::shuffle(p.begin(), p.end(), 
                std::default_random_engine(std::random_device()()));
            
            center_ = p[0];
            radius_ = 0.0;
    
            for (size_t i = 1; i < p.size(); ++i) {
                if (dis(p[i], center_) > radius_ + eps) {
                    center_ = p[i];
                    radius_ = 0.0;
    
                    for (size_t j = 0; j < i; ++j) {
                        if (dis(p[j], center_) > radius_ + eps) {
                            center_.x = (p[i].x + p[j].x) / 2.0;
                            center_.y = (p[i].y + p[j].y) / 2.0;
                            radius_ = dis(p[j], center_);
    
                            for (size_t k = 0; k < j; ++k) {
                                if (dis(p[k], center_) > radius_ + eps) {
                                    point newO;
                                    db newR;
                                    computeCircle(p[i], p[j], p[k], newO, newR);
                                    center_ = newO;
                                    radius_ = newR;
                                }
                            }
                        }
                    }
                }
            }
        }
    
        void computeCircle(const point& p1, const point& p2, const point& p3, 
                          point& newO, db& newR) const {
            db a = p2.y - p1.y;
            db b = p3.y - p1.y;
            db c = p2.x - p1.x;
            db d = p3.x - p1.x;
            db e = sq(p2.x) + sq(p2.y) - sq(p1.x) - sq(p1.y);
            db f = sq(p3.x) + sq(p3.y) - sq(p1.x) - sq(p1.y);
    
            db denominator = 2 * (a*d - b*c);
            
            // 共线情况处理
            if (fabs(denominator) < eps) {
                // 计算三点的最小覆盖圆（三点共线时取最远两点的中点）
                db max_dist = 0.0;
                point pair[2];
                for (const auto& p : {p1, p2, p3}) {
                    for (const auto& q : {p1, p2, p3}) {
                        db dist = dis(p, q);
                        if (dist > max_dist) {
                            max_dist = dist;
                            pair[0] = p;
                            pair[1] = q;
                        }
                    }
                }
                newO.x = (pair[0].x + pair[1].x) / 2.0;
                newO.y = (pair[0].y + pair[1].y) / 2.0;
                newR = max_dist / 2.0;
            } else {
                newO.x = (a*f - b*e) / denominator;
                newO.y = (d*e - c*f) / denominator;
                newR = dis(newO, p1);
            }
        }
};
void check(int x){
    //if(x==1 or x==n) return ;
    vector<point >lef,rig;
    for(int i=1;i<=x;i++){
        lef.push_back(p[i]);
    }
    for(int i=x+1;i<=n;i++){
        rig.push_back(p[i]);
    }
    MinCircleCover lef_(lef),rig_(rig);
    auto lefr=lef_.getRadius();
    auto rigr=rig_.getRadius();
    if(lefr>=rigr) r=x-1;
    else l=x+1;
    if(ans<=lefr && ans<=rigr) l=n+100;
    //cout<<x<<lefr<<" "<<rigr<<endl;
    ans=min(ans,max(lefr,rigr));
}
void rotate(db angle){
    for(int i=1;i<=n;i++){
        auto a=p2[i];
        db tx=a.x*cos(angle)+a.y*sin(angle);
        db ty=a.y*cos(angle)-a.x*sin(angle);
        p[i].x=tx;
        p[i].y=ty;
    }
    return ;
}
void slove(){
    ans=10000000.01;
	cin>>n;
    mp.clear();
    if(n==0) exit(0);
    int top=0;
    for(int i=1;i<=n;i++){
        db tx,ty;cin>>tx>>ty;
        if(mp[{tx,ty}]==0){
            p[++top]={tx,ty};
            p2[top]=p[top];
        }
        mp[{tx,ty}]=1;
    }
    n=top;
    for(int i=0;i<=180;i++){ // test2在121的时候有问题 120没问题
        db angle=i/180.0*pi;
        rotate(angle);
        sort(p+1,p+1+n,[](const  point &a,const point  &b){
            if(a.x!=b.x) return a.x<b.x;
            else return a.y>b.y;
        }
        );
        l=1,r=n; // 代表答案所在的区间
        while(l<=r){
            //cout<<l<<" "<<r<<"\n";
            mid=(l+r+1)/2;
            check(mid);
        }
        //check(0);
    }
    // db angle=16/180.0*pi;
    // cout<<angle;
    // rotate(angle);
    // for(int i=1;i<=n;i++)
    // {
    //     auto u=p[i];
    //     cout<<u.x<<" "<<u.y<<endl;
    // }
    cout<<fixed<<setprecision(2);
    cout<<ans<<"\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        slove();
    }
    return 0;
}