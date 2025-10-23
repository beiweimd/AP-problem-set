// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=2e5;
using namespace std;
int t,n,q,m,l,r,k;
int ans[maxn],a[maxn],cnt[maxn],fre[maxn];
vector<array<int,4>>query;
void slove(){
    cin>>n;m=(int)sqrt(n)+1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>q;for(int i=1;i<=q;i++){
        cin>>l>>r>>k;
        query.push_back({l,r,k,i});
    }
    sort(query.begin(),query.end()
    );
    int posl=1,posr=0;
    auto add=[&](int x){
        cnt[fre[a[x]]]--;
        fre[a[x]]++;
        cnt[fre[a[x]]]++;
    };
    auto del=[&](int x){
        cnt[fre[a[x]]]--;
        fre[a[x]]--;
        cnt[fre[a[x]]]++;        
    };
    for(auto[lef,rig,tk,id]:query){
        while(posl<lef) del(posl),posl++;
        while(posl>lef) posl--,add(posl); 
        while(posr>rig) del(posr),posr--;
        while(posr<rig) posr++,add(posr);
        ans[id]=cnt[tk];
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<"\n";
    }
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