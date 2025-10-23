// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int n,m,target,flag,block;
int a[maxn],ans[maxn];
vector<array<int ,3> >p;
int mp[20000000];
int cnt;
void add(int x){
    mp[a[x]]++;
    int num=(a[x]^target);
    cnt=cnt+mp[num];
}
void del(int x){
    int num=(a[x]^target);
    cnt=cnt-mp[num];
    mp[a[x]]--;
}
void slove(){
    cin>>n>>m>>target;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int l,r;cin>>l>>r;
        p.push_back({l,r,i});
    }
    block=sqrt(n);
    sort(p.begin(),p.end(),[](const array<int ,3>&a,const array<int ,3>&b){
            if(a[0]/block==b[0]/block ) return a[1]<b[1];
            else return a[0]/block<b[0]/block;
    }
    );
    int posl=1,posr=0;
    mp[a[1]]++;
    for(auto [l,r,id]:p){
        while(posl<l){ posl++;del(posl-1);}
        while(posl>l){posl--;add(posl);}
        while(posr>r){posr--;del(posr+1);}
        while(posr<r){posr++;add(posr);}
        if(cnt) ans[id]=1;
        //cout<<l<<" "<<r<<" "<<cnt<<endl;
    }
    for(int i=1;i<=n;i++){
        if(ans[i]) cout<<"yes";
        else cout<<"no";
        cout<<"\n";
    }
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