#include<bits/stdc++.h>
#define tin int 
#define int int
#define tni int
#define nit int
#define nti int
#define printf printf
#define scnaf scanf
#define ll long long
#define INF 0x7fffffff
using namespace std;




inline int read()
{
    int x=0,k=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*k;
}
#define maxn 10005
#define maxm 500005
#define inf 2147483647
int n,m,s,tot,dis[maxn],head[maxn];
bool vis[maxn];
struct Edge
{
      int next,to,w;
}h[maxm];
void add(int u,int v,int w)
{
    h[++tot].next=head[u];
    h[tot].to=v;
    h[tot].w=w;
    head[u]=tot;
}
//�����dijkstra�㷨������һ��
queue<int> q;
//�����Ż�
inline void spfa()
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=inf;
        //����ֵ
    }
    int u,v;
    q.push(s);
    dis[s]=0;
    //������ֵ��Ϊ0
    vis[s]=1;//��仰�ɼӿɲ��ӣ���Ϊѭ����ʱ��vis[s]�ֻᱻ��Ϊ0
    while(!q.empty())
    //��������û��Ԫ�ص�ʱ���Ǿ��Ѿ����������еĵ�Դ���·��
	{
        u=q.front();
        //�����ֽڵ��¼���������׽ڵ�
        q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=h[i].next)
        //Ѱ����u�����ı�
		{
            v=h[i].to;
            if(dis[v]>dis[u]+h[i].w)
			{
                dis[v]=dis[u]+h[i].w;
                //�ɳڲ�������floyd�Ƚ�����
                if(!vis[v])
				{
                //�Ѿ��ڶ�����ĵ�Ͳ����ٽ�����
                      vis[v]=1;
                      q.push(v);
                }
            }
        }
    }
}
int main(){
    n=read(),m=read(),s=read();
    for(int i=1,u,v,w;i<=m;i++)
	{
        u=read(),v=read(),w=read();
        add(u,v,w);
    }
    spfa();
    for(int i=1; i<=n; i++)
    {
        printf("%d ",dis[i]);
    }
    return 0;
}
































// ���������,�������ݿ��ܻ᲻ͨ��

// spfa o(km)
// ���Ѿ�����

// ���д���Ǳ����µĵ�

/*  step 1 : �ȼ������
    step 2 : ö�ٵ�ǰ������г���
    step 3 : �жϵ�ǰö�ٵĵ�����г�������Ӧ�Ľڵ�᲻�ᱻ����


*/

//2147483647
// int head[510000],ne[510000],edge[510000],ver[510000],tot=0;
// int d[10100],v[10100];
// int n,m,s;

// void add(int x,int y,int z){ // �ڽӱ�
//     ver[++tot] = y;
//     edge[tot] = z;
//     ne[tot] = head[x];
//     head[x] = tot;
// }
// void spfa(int s){
//     for(int i=1;i<=n;i++){
//         d[i] = 2147483647;
//     }
//     d[s] = 0;
//     queue<int>q;
//     q.push(s);
//     v[s]=1;
//     while(q.size()){
//         int x = q.front();
//         q.pop();
//         v[x]= 0;
//         for(int i = head[x]; i;i=ne[i]){
//             int y = ver[i];
//             int z = edge[i];
//             if(d[y]>d[x]+z){
//                 d[y] = d[x] +z;
//                 if(!v[y]){
//                     q.push(y);
//                     v[y]=1;
//                 }
//             }
//         }
//     }
// }
// int main(){
//     cin>>n>>m>>s;
//     for(int i = 1;i<=n;i++){
//         int x,y,z;
//         cin>>x,y,z;
//         add(x,y,z); // �����ڽӱ�
//     }
//     spfa(s); // �õ���s��ͷ�ģ������е����̾���
//     for(int i=1;i<=n;i++){
//         if(s==i){
//             cout<<"0"<<" ";
//         }
//         else{
//             cout<<d[i]<<" ";
//         }
//     }
//     system("pause");
//     return 0;
// }


// int dis[500010],n,m,s,tot;
// int st[500010];
// bool vis[10010];
// queue<int>q;

// struct node {
//     int to;
//     int val;
//     int last;
// }edge[50050];
// void add(int from,int to,int val){
//     ++tot;                          // �����ߵı��
//     edge[tot].to = to;              // ��ǰ�����ߵ��յ�
//     edge[tot].val = val;            // ��ǰ�����ߵĳ���
//     edge[tot].last = st[from];      
//     /*
//     edge[tot].last �����ߵ���һ����
//     st[from] ��ǰ����ı�Ϊֹ�������������ߣ� ����һ���ߵ����
//     */
//     st[from]=tot;
// }
// void spfa(){
//     while(q.size()){
//         int x = q.front();
//         q.pop();
//         vis[x] = false;
//         for()
//     }
// }
// int main(){
//     cin>>n>>m>>s;
//     for(int i=1;i<=n;i++){
//         int a,b,c;
//         cin>>a>>b>>c;
//         add(a,b,c);
//     }
//     for(int i=1;i<=n;i++){
//         dis[i]=2147483647;
//     }
//     dis[s]=0;
//     q.push(s);
//     vis[s]=true;
//     spfa();
//     for(int i=1;i<=n;i++){
//         cout<<dis[i]<<" ";
//     }
//     return 0;
// }