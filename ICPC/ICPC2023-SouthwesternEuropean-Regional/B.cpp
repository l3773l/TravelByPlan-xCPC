/*
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2100+5;
const int INF = 1e9+7;
typedef long long ll;
typedef pair<int,int> pii;
#define all(a) (a).begin(), (a).end()
struct Edge{
	int from,to,cap,flow;//起点,终点,容量,流量
};
struct Dicnic{
	int n,m,s,t;//点,边,源点,汇点
	vector<Edge> edges;//边集
	vector<int> G[maxn];
	bool vis[maxn];//bfs 使用的
	int d[maxn];//起点到i的距离,就是bfs得到的层次图,下次dfs沿着d走
	int cur[maxn];//当前弧优化使用
	void addEdge(int from,int to,int cap){
		edges.push_back({from,to,cap,0});
		edges.push_back({to,from,0,0});//反向边
		m = edges.size();
		G[from].push_back(m-2);G[to].push_back(m-1);
		//正边的编号都是偶数,反向边的编号都是奇数
	}
	bool bfs(){
		memset(vis,0,sizeof(vis));
		queue<int> Q;Q.push(s);
		d[s]=0;vis[s]=true;
		while(!Q.empty()){
			int x = Q.front();Q.pop();
			for(auto v : G[x]){
				Edge &e = edges[v];//获得边的编号
				if(!vis[e.to]&&e.cap>e.flow){
					//只有未被访问过,而且位于残量网络中的弧才考虑
					vis[e.to]=1;
					d[e.to]=d[x]+1;Q.push(e.to);
				}
			}
		}
		return vis[t];
	}
        int dfs(int x,int a){
		//寻找增广路,a代表目前经过的路中,每个边剩余的流量
		if(x==t||a==0) return a;//到达终点/残量为0
		int flow = 0,f;
		for(int &i = cur[x];i<G[x].size();i++){
			Edge &e = edges[G[x][i]];
			if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
				//首先要按层次图走,然后当前增加流量要是增广路中流量最小的的
				e.flow+=f;
				edges[G[x][i]^1].flow-=f;//正边加流量,反边减流量
				flow+=f;a-=f;
				if(a==0) break;
			}
		}
		return flow;
	}
	int Maxflow(int s,int t){
		this->s=s;this->t=t;
		int flow=0;
		while(bfs()){
			memset(cur,0,sizeof(cur));flow+=dfs(s,INF);
		}
		return flow;
	}
};
signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//该图是个二分图上找最小覆盖
	//而最小覆盖等于最大匹配,所谓匹配就是指没有公共顶点的边
	//为了求出一个二分图的最大匹配,可以按以下方法建模
	//源点连接左部所有点，设置容量为1
	//汇点连接右部,容量也为1，求最大流即可。
	Dicnic g;
	int N,M;
	cin>>N>>M;
	int t =0 ,s = M+2*N+2 ;//图的总大小为 100+2000+5=2105
	for(int i=1;i<=M;i++){
		g.addEdge(s,i,1);
	}
	for(int i=1;i<=N;i++){
		g.addEdge(M+N+i,t,1);//国家到汇点
	}
	for(int i=1;i<=N;i++){
		int num;cin>>num;
		for(int j=1;j<=num;j++){
			int color;
			cin>>color;
			g.addEdge(color,M+N+i,1);
		}
	}
	int flow = g.Maxflow(s,t);
	cout<<flow;
	return 0;
}
/*
4 6
3
1 4 5
3
1 4 5
3
1 4 5
3
1 4 5
*/