// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
ll k;
vector<array<ll,2>> ans;
void slove(){
	cin>>k;
    ll cnt=0;
    // 这里注意一下细节 就是对于第i位来说 我们记第i位放置的和第i位之后放置的数记为s 只要s是i的倍数 那么不管你怎么放
    // 可以保证最终有效的i的情况肯定是合法的 也就是i在收到很多1后最终还是i的倍数
    // 证明：比如我们在i+1放置了一个i+1 对 那么这个时候对于0-i-1 他们收到了一个1 所以我们失去了一个i 
    // 所以以此类推 每次失去的都是一个i 那么不管怎么搞 最终到i的时候都是i的倍数
    // 所以题解中/答案中 我们要一直保证是k可以是(cnt+1)的倍数 如果不是 直接放置模数 那么根据定理 你在自己这个位置怎么放都是不影响 自己的
    //于是就可以了 就很神奇
    while(k){
        cnt++;
        if(k%(cnt+1)==0) continue;
        cout<<cnt<<" "<<k%(cnt+1)<<"\n";
        k=k-k%(cnt+1);
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