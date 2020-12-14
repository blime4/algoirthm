#include<bits/stdc++.h>
using namespace std;

char s1[505],s2[505];
int a[505],b[505],c[505];

int main(){
    int la,lb,lc;
    scanf("%s",s1);
    scanf("%s",s2);

    la = strlen(s1);
    lb = strlen(s2);

    // 字符转数字，并转置
    for(int i=0;i<la;i++) a[la-i] = s1[i] - '0';
    for(int i=0;i<lb;i++) b[lb-i] = s2[i] - '0';

    lc = max(la,lb) + 1;
    for(int i=1;i<=lc;i++){
        c[i] += a[i] + b[i];
        c[i+1] = c[i]/10;
        c[i] = c[i] % 10;
    }

    if(c[lc]==0 && lc>0) lc--;
    for(int i=lc;i>0;i--){
        printf("%d",c[i]);
    }
    return 0;
}
