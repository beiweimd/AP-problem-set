#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-16;
using namespace std;
int t,n;
db angle,mul;
struct point{
    db x,y;
};
vector<point >p;
vector<point >new_p;
db sq(db x){
    return x*x;
}
db dis(point a,point b){
    return (db)sqrt( sq( (a.x-b.x ))+sq(a.y-b.y)  );
}
void  trans(const point a){
    point ans;
    ans.x=a.x*cos(angle)+a.y*sin(angle);
    ans.y=a.y*cos(angle)-a.x*sin(angle);
    ans.x/=mul;
    new_p.push_back(ans);
    return ;
}
class MinCircle {
    private:
        point center;
        db radiusSquared;
    
    public:
    void computeThreePointsCircle(const point& p1, const point& p2, const point& p3) {
        db dx1 = p2.x - p1.x;
        db dy1 = p2.y - p1.y;
        db dx2 = p3.x - p1.x;
        db dy2 = p3.y - p1.y;

        db a = dx1, b = dy1;
        db c = dx2, d = dy2;

        db e = (p2.x*p2.x + p2.y*p2.y) - (p1.x*p1.x + p1.y*p1.y);
        db f = (p3.x*p3.x + p3.y*p3.y) - (p1.x*p1.x + p1.y*p1.y);

        db denominator = 2.0 * (a*d - b*c);
        // if (fabs(denominator) < eps) {
        //     // 共线情况处理
        //     return;
        // }
        center.x = (b*f - d*e) / denominator;
        center.y = (c*e - a*f) / denominator;
        radiusSquared = (center.x - p1.x)*(center.x - p1.x) + (center.y - p1.y)*(center.y - p1.y);
    }
    
        db distanceSquared(const point& a, const point& b) const {
            return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
        }
        void computeMinCircle(vector<point>& points) {
            random_shuffle(points.begin(), points.end());
            center = points[0];
            radiusSquared = 0.0;
    
            for (size_t i = 1; i < points.size(); ++i) {
                if (distanceSquared(points[i], center) > radiusSquared + eps) {
                    center = points[i];
                    radiusSquared = 0.0;
    
                    for (size_t j = 0; j < i; ++j) {
                        if (distanceSquared(points[j], center) > radiusSquared + eps) {
                            center.x = (points[i].x + points[j].x) / 2.0;
                            center.y = (points[i].y + points[j].y) / 2.0;
                            radiusSquared = distanceSquared(points[j], center);
    
                            for (size_t k = 0; k < j; ++k) {
                                if (distanceSquared(points[k], center) > radiusSquared + eps) {
                                    computeThreePointsCircle(points[i], points[j], points[k]);
                                }
                            }
                        }
                    }
                }
            }
        }
    
        point getCenter() const { return center; }
        db getRadius() const { return sqrt(radiusSquared); }
};
void slove(){
    cin>>n;
    map<pair<db,db>,int>mp;
    for(int i=1;i<=n;i++){
        db tx,ty;cin>>tx>>ty;
        if(mp[make_pair(tx,ty)]==0)p.push_back({tx,ty});
        mp[make_pair(tx,ty)]=1;
    }
    cin>>angle>>mul;
    angle=angle/180*pi;
    for(auto u:p){
        trans(u);
    }
    MinCircle mc;
    mc.computeMinCircle(new_p);
    db radius=mc.getRadius();
    cout<<fixed<<setprecision(3)<<radius+eps;
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    t=1;
    while(t--){
		slove();
    }
    return 0;
}