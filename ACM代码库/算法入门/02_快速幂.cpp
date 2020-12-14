#include<bits/stdc++.h>
#define tin int 
#define itn int
#define tni int
#define nit int
#define nti int
#define pritnf printf
#define scnaf scanf
#define ll long long
using namespace std;

// quick_pow

// 快速幂 : https://www.luogu.com.cn/blog/cicos/quickpow#

/* 我的理解：

    a^11 = a^(1011)
    ans = 1
    base = a
    if 1011&1 ans *= base base*=base
    if 101&1 ans *= base base*=base
    if 10&1
    if 1&1 ans *= base base*=base
*/

// int quick_power(int a,int b){
//     int ans = 1 ,base =a;
//     while(b>0){
//         if(b&1){
//             ans *= base;
//         }
//         base *= base;
//         b>>= 1;
//     }
//     return ans;
// }

// // 快速幂 + 取余
// int m = 10000000007;
// int quick_power(int a,int b){
//     int ans = 1 ,base =a;
//     while(b>0){
//         if(b&1){
//             ans *= base;
//             ans %= m;
//         }
//         base *= base;
//         base %= m;
//         b>>= 1;
//     }
//     return ans;
// }



ll b,p,k,ans=1;
int main(){
    cin>>b>>p>>k;
    printf("%lld^%lld mod %lld=",b,p,k);
    while(p>0){
        if(p&1){
            ans *= b;
            ans %= k;
        }
        b *= b;
        b %= k;
        p>>=1;
    }
    printf("%lld",ans%k);
    return 0;
}