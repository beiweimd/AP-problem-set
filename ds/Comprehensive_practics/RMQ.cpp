#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000010;

ll a[N], n, q,f[40][N];
unsigned int A, B, C;
ll ans;
inline unsigned int rng61() {
    A ^= A << 16;
    A ^= A >> 5;
    A ^= A << 1;
    unsigned int t = A;
    A = B;
    B = C;
    C ^= t ^ A;
    return C;
}
void init(){
    for(int j=1;j<=31;j++){
        for(int i=1;i<=n;i++){
            if(i+(1ll<<j)-1<=n){
               f[j][i]=max(f[j-1][i],f[j-1][i+(1<<(j-1))]);
            }
        }
    }
}
ll query(int l ,int r){
    int k=log2(r-l+1);
    return max(f[k][l],f[k][r-(1<<k)+1]);
}
int main() {
    scanf("%d%d%u%u%u", &n, &q, &A, &B, &C);

    for (int i = 1; i <= n; i++) {
        a[i] = rng61();
        f[0][i]=a[i];
    }
    init();
    for (int i = 1; i <= q; i++) {
        unsigned int l = rng61() % n + 1, r = rng61() % n + 1;
        if (l > r) swap(l, r);
        ans=ans^query(l,r);
    }
   cout<<ans;
}
