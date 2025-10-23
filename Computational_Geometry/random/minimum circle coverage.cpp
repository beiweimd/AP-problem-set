#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef  long double db;
const double eps = 1e-8;
struct point {
	db x, y;
} ;
db sq(db x) {return x * x;}
db dis(point a, point b) {return (db)sqrt(sq(a.x - b.x) + sq(a.y - b.y));}
class MinCircleCover {
    public:
        MinCircleCover(const std::vector<point>& points) : points_(points) {
            compute();
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
int main() {
	int n;cin>>n;
	vector<point>p;
	for(int i=1;i<=n;i++){
		long double  tx,ty;
		cin>>tx>>ty;
		p.push_back(point{tx,ty});
	}
	MinCircleCover mc(p);
	cout<<fixed<<setprecision(10);
	cout<<mc.getRadius()<<"\n";
	cout<<mc.getCenter().x<<" "<<mc.getCenter().y;
	return 0;
}
// #include <bits/stdc++.h>
// typedef long long ll;
// typedef long double db;
// const ll mod=1e9+7;
// const db pi=acos(-1);
// const db eps=1e-12;
// using namespace std;
// int t,n;
// db rx,ry,r;
// struct point{
// 	db  x,y;
// };
// db dis(point a,point b){
// 	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
// }
// void make_crcycle2(point a){
// 	rx=0.5*(rx+a.x);
// 	ry=0.5*(ry+a.y);
// 	r=dis(point{rx,ry},a);
// 	return ;
// }
// void make_crcycle3(point a,point b,point c){
//     if( (a.x-b.x)*(a.y-c.y)-(a.x-c.x)*(a.y-b.y)<=eps){ //判断共线的情况
//         r=rx=ry=0;
// 		return ;
//     }
//     db c1=0.5*( dis(point{0.0,0.0},b)-dis(point{0.0,0.0},a) );
//     db c2=0.5*( dis(point{0.0,0.0},c)-dis(point{0.0,0.0},a) );
//     db a1=b.x-a.x;
//     db a2=c.x-a.x;
//     db b1=b.y-a.y;
//     db b2=c.y-a.y;
//     rx=(b2*c1-b1*c2)/(b2*a1-b1*a2);
//     ry=(a2*c1-a1*c2)/(a2*b1-a1*b2);
//     r=dis(point{rx,ry},a);
//     return ;
// }	
// void slove(){
// 	cin>>n;
// 	vector<point >p;
// 	for(int i=1;i<=n;i++){
// 		db tx,ty;cin>>tx>>ty;
// 		p.push_back(point{tx,ty});
// 	}
//     //random_shuffle(p.begin(),p.end());//记得打乱
// 	for(int i=0;i<n;i++){ // 枚举前i个点的最小覆盖圆
// 		if( dis(point{rx,ry},p[i])>r+eps){ // 说明我们的这个点 不在圆内
// 		r=0;rx=p[i].x,ry=p[i].y;// 不在 那么新加入的这个点必然是在圆上一点
// 		for(int j=0;j<i;j++){ // 先去枚举前面的所有点 先按照这个两点确定直径构造一个圆
// 			if( dis(point{rx,ry},p[j])>r+eps){
// 				make_crcycle2(p[j]);
// 			}
// 			for(int k=0;k<j;k++){ // check一下两个点构造的直径圆能否覆盖前面的所有点 
// 				if( dis(point{rx,ry},p[k])>r+eps){
// 				make_crcycle3(p[k],p[i],p[j]);
// 			}
// 			}
// 		}
// 		}
// 	}
// 	cout<<fixed<<setprecision(9);
// 	cout<<sqrt(r)<<"\n";
// 	cout<<rx<<" "<<ry;
// 	return ;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     t=1;
//     while(t--){
// 		slove();
//     }
//     return 0;
// }
// // #include <bits/stdc++.h>
// // typedef long long ll;
// // typedef long double db;
// // const ll mod=1e9+7;
// // const db pi=acos(-1);
// // const db eps=1e-12;
// // using namespace std;
// // int t,n;
// // db ans=1e8,rx,ry;
// // struct point{
// //     db x,y;
// // };
// // struct cicycle{
// //     point info;
// //     db r;
// // };
// // point operator+(const point &a, const point &b) {
// //     return {a.x + b.x, a.y + b.y};
// // }
// // vector<point>p;
// // db dis(point a,point b){
// //     return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
// // }
// // db sq(db s){return s*s;}
// // cicycle c;
// // void sim_anneal(){
// //     c.info.x=c.info.y=c.r=0.0;
// //     for(auto u:p){
// //         c.info+u;
// //         c.r=max(c.r,dis(c.info,u));
// //     }
// //     c.info.x/=n;
// //     c.info.y/=n; // 计算初始的位置 是所有点的平均数
// //     db delta=20000;
// //     while(delta>eps){
// //         int id=0;
// //         db max_r=0.0;
// //         for(int i=0;i<n;i++){
// //             if(dis(c.info,p[i])>max_r){
// //                 id=i;
// //                 max_r=dis(c.info,p[i]);
// //             }
// //         }
// //         c.r=min(c.r,max_r);
// //         c.info.x+=(p[id].x-c.info.x)/max_r*delta;
// //         c.info.y+=(p[id].y-c.info.y)/max_r*delta;
// //         delta*=0.97;
// //     }
// // }
// // void slove(){
// // 	cin>>n;
// //     for(int i=1;i<=n;i++){
// //         db tx,ty;cin>>tx>>ty;
// //         p.push_back(point{tx,ty});
// //     }
// //     sim_anneal();
// //     cout<<fixed<<setprecision(10);
// //     cout<<sqrt(c.r)<<"\n";
// //     cout<<c.info.x<<" "<<c.info.y;
// //     return;
// // }
// // int main(){
// //     ios::sync_with_stdio(0);
// //     cin.tie(0);
// //     cout.tie(0);
// //     t=1;
// //     while(t--){
// // 		slove();
// //     }
// //     return 0;
// // }//这个是模拟退火乱搞法
// // // // ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// // // 最小圆覆盖的n^4做法 十分暴力
// // // #include <bits/stdc++.h>
// // // typedef long long ll;
// // // typedef long double db;
// // // const ll mod=1e9+7;
// // // const db pi=acos(-1);
// // // const db eps=1e-11;
// // // using namespace std;
// // // int t,n;
// // // db ans=1e8,rx,ry;
// // // struct point{
// // //     db x,y;
// // // };
// // // vector<point>p;
// // // db dis(point a,point b){
// // //     return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
// // // }
// // // db sq(db s){return s*s;}
// // // void check(point a,point b,point c){
// // //     if( (a.x-b.x)*(a.y-c.y)-(a.x-c.x)*(a.y-b.y)<=eps){ //判断共线的情况
// // //         return ;
// // //     }
// // //     db c1=0.5*( dis(point{0.0,0.0},b)-dis(point{0.0,0.0},a) );
// // //     db c2=0.5*( dis(point{0.0,0.0},c)-dis(point{0.0,0.0},a) );
// // //     db a1=b.x-a.x;
// // //     db a2=c.x-a.x;
// // //     db b1=b.y-a.y;
// // //     db b2=c.y-a.y;
// // //     db tx=(b2*c1-b1*c2)/(b2*a1-b1*a2);
// // //     db ty=(a2*c1-a1*c2)/(a2*b1-a1*b2);
// // //     db t_d=dis(point{tx,ty},a);
// // //     for(int i=0;i<n;i++){
// // //         if(dis(p[i],{tx,ty})>t_d) return ;
// // //     }
// // //     if(t_d<ans ){
// // //         ans=t_d;
// // //         rx=tx;ry=ty;
// // //     }
// // //     return ;
// // // }
// // // void slove(){
// // // 	cin>>n;
// // //     for(int i=1;i<=n;i++){
// // //         db tx,ty;cin>>tx>>ty;
// // //         p.push_back(point{tx,ty});
// // //     }
// // //     for(int i=0;i<n;i++){
// // //         for(int j=0;j<n;j++){
// // //             for(int k=0;k<n;k++)check(p[i],p[j],p[k]);
// // //         }
// // //     }
// // //     cout<<fixed<<setprecision(10);
// // //     cout<<(db)sqrt(ans)<<"\n";
// // //     cout<<rx<<" "<<ry;
// // //     return;
// // // }
// // // int main(){
// // //     ios::sync_with_stdio(0);
// // //     cin.tie(0);
// // //     cout.tie(0);
// // //     t=1;
// // //     while(t--){
// // // 		slove();
// // //     }
// // //     return 0;
// // // }