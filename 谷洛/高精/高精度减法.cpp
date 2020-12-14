#include<bits/stdc++.h>
using namespace std;

char s1[10090],s2[10090],s3[10090];
int a[10090],b[10090],c[10090];
int flag = 0;

bool compare(char s1[],char s2[]){
    int u = strlen(s1), v = strlen(s2);
    if(u != v) return u>v;
    for(int i=0; i<u;i++){
        if(s1[i] != s2[i]) return s1[i]>s2[i];
    }
    return true;
}

int main(){
    int la,lb,lc;
    scanf("%s",s1);
    scanf("%s",s2);
    if(!compare(s1,s2)){ // 如果s1<s2，交换两个数
        flag = 1;
        strcpy(s3,s1);
        strcpy(s1,s2);
        strcpy(s2,s3);
    }

    la = strlen(s1);
    lb = strlen(s2);
    for(int i=0;i<la;i++) a[la-i] = s1[i]-'0';
    for(int i=0;i<lb;i++) b[lb-i] = s2[i]-'0';
    lc = max(la,lb);
    for(int i=1;i<=lc;i++){
        if(a[i]<b[i]){
            a[i+1]--;
            a[i] += 10;
        }
        c[i] = a[i]-b[i];
    }
    while(c[lc]==0 && lc>1) lc--;
    if(flag == 1) printf("-");
    for(int i=lc;i>0;i--) printf("%d",c[i]);
    return 0;
}