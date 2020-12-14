#include<bits/stdc++.h>
#define tin int 
#define itn int
#define tni int
#define nit int
#define nti int
#define pritnf printf
#define scnaf scanf
#define ll long long
#define INF 0x7fffffff
#define F(i,n,m) for(int i=n;i<=m;i++)//灵性define，减少码量（for打得我烦） 
using namespace std;


itn n,a[1000010];
void qs(int l, int r){
    int mid = a[(l+r)/2];
    int i=l,j=r;
    do{
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(l<j) qs(l,j);
    if(i<r) qs(i,r);
}

int main(){
    cin>>n;
    F(i,1,n){
        cin>>a[i];
    }
    qs(1,n);
    F(i,1,n){
        cout<<a[i]<<" ";
    }
    return 0;
}