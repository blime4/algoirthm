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
//上面和dijkstra算法基本上一样
queue<int> q;
//队列优化
inline void spfa()
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=inf;
        //赋初值
    }
    int u,v;
    q.push(s);
    dis[s]=0;
    //将起点的值负为0
    vis[s]=1;//这句话可加可不加，因为循环的时候vis[s]又会被赋为0
    while(!q.empty())
    //当队列里没有元素的时候，那就已经更新了所有的单源最短路径
	{
        u=q.front();
        //将队手节点记录并弹出队首节点
        q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=h[i].next)
        //寻找与u相连的边
		{
            v=h[i].to;
            if(dis[v]>dis[u]+h[i].w)
			{
                dis[v]=dis[u]+h[i].w;
                //松弛操作，和floyd比较相似
                if(!vis[v])
				{
                //已经在队列里的点就不用再进入了
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
































// 随机数据用,特殊数据可能会不通过

// spfa o(km)
// 它已经死了

// 队列存的是被更新的点

/*  step 1 : 先加入起点
    step 2 : 枚举当前点的所有出边
    step 3 : 判断当前枚举的点的所有出边所对应的节点会不会被更新


*/

//2147483647
// int head[510000],ne[510000],edge[510000],ver[510000],tot=0;
// int d[10100],v[10100];
// int n,m,s;

// void add(int x,int y,int z){ // 邻接表
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
//         add(x,y,z); // 加入邻接表
//     }
//     spfa(s); // 得到以s开头的，到所有点的最短距离
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
//     ++tot;                          // 这条边的编号
//     edge[tot].to = to;              // 当前这条边的终点
//     edge[tot].val = val;            // 当前这条边的长度
//     edge[tot].last = st[from];      
//     /*
//     edge[tot].last 这条边的上一条边
//     st[from] 当前读入的边为止（不包括这条边） 的上一条边的序号
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