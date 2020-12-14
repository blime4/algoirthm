#include<bits/stdc++.h>
using namespace std;

char s1[50010],s2[50010];
int a[50010],b[50010],c[50010];

int main(){
    int la,lb,lc;
    scanf("%s",s1);
    scanf("%s",s2);

    la = strlen(s1);
    lb = strlen(s2);

    for(int i=0;i<la;i++) a[la-i] = s1[i] - '0';
    for(int i=0;i<lb;i++) b[lb-i] = s2[i] - '0';

    lc = la + lb;
    for(int i=1 ; i<=la; i++){
        for(int j=1; j<=lb; j++){
            c[i+j-1] += a[i]*b[j];
        }
    }
    for(int i=0;i<la+lb;i++){
        if(c[i]>9){
            c[i+1] += c[i]/10;
            c[i] %= 10;
        }
    }

    while(c[lc]==0 && lc>1) lc--;
    for(int i=lc; i>=1;i--) printf("%d", c[i]);

    system("pause");
    return 0;
}