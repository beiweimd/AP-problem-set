#include <bits/stdc++.h>
using i64 = long long;
using ll = long long;
using namespace std;

#ifdef LOCAL
#   define debug(x) cout << #x << " = " << x << endl
#   define debugv(v) do { cout << #v << ": ["; string d;\
    for (const auto& e : v) cout << d << e, d = ", "; cout << "]" << endl; } while (0)
#else
#   define debug(...) 12
#   define debugv(...) 12
#endif
int n;
void solve() {
    cin>>n;
    vector<ll> a(n+1);
    map<ll,ll> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll max_cnt=1ll;
    ll ans=2*a[1];
    array<ll,2>num;
    num[0]=num[1]=a[1];
    mp[a[1]]++;
    // 0 max 1 min
    cout<<ans<<" ";
    for(int i=2;i<=n;i++){
        mp[a[i]]++;
        num[0]=max(num[0],a[i]);
        num[1]=min(num[1],a[i]);
        ans=num[0]+num[1];
        if(  mp[num[1]]==1 &&mp[num[0]]==i-1) {
            ans=max(num[0]+num[1],num[0]*2);
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}