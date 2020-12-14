#include<bits/stdc++.h>
#define tin int 
#define itn int
#define tni int
#define nit int
#define nti int
#define pritnf printf
#define scnaf scanf
using namespace std;

// 最大公约数，辗转相除法

inline int gcd(int x, int y) { return y ? gcd(y,x%y) : x; }

// 最小公倍数

inline int lcm(int GCD,int n,int m) {return n*m/GCD; }