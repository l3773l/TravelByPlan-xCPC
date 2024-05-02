#include<bits/stdc++.h>
using namespace std;
const double INF = 1e9+7;
const int maxn = 1000+5;
double dist[maxn];
double G[maxn][maxn];
bool st[maxn];
double dijkstra(int n){
	for(int i=0;i<=n;i++) dist[i]=INF;
	dist[0]=0;
	for(int i=0;i<n;i++){
		int t = -1;
		for(int j=0;j<=n;j++){
			if(!st[j]&&(t==-1||dist[t]>dist[j])) t = j;
		}
		if(t==-1) break;
		//use t to update
		for(int j=0;j<=n;j++)
			dist[j] = min(dist[j],dist[t]+G[t][j]);
		st[t] = true;
	}
	return dist[n];
}
int x[maxn],y[maxn];
double distance(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
int main(){
	int n,v1,v2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	scanf("%d %d %d %d",&x[0],&y[0],&x[n+1],&y[n+1]);
//	for(int i=0;i<=n+1;i++){
//		printf("%d %d\n",x[i],y[i]);
//	}
	scanf("%d %d",&v1,&v2);
	//construct the graphe
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n+1;j++){
			if(i==j) {
				G[i][j]=0;continue;
			}
			double d = distance(i,j);
			if(v2*3 >=d){
				G[i][j] = 1.0*d / v2; 	
			}
			else {
				G[i][j] = 3.0 + (d-3*v2) / v1;
			}	
		}
	}
	for(int i=1;i<=n+1;i++){
		double d1 = distance(0,i);
		G[0][i] = 1.0*d1  / v1;
		if(i==n+1) continue;
		double d2 = distance(n+1,i);
		G[n+1][i] = 1.0*d2 / v1;
	}
	G[0][n+1] = G[n+1][0] = 1.0*distance(0,n+1) / v1;
	
//	printf("Grid is \n");
//	for(int i=0;i<=n+1;i++){
//		for(int j=0;j<=n+1;j++) printf("%lf ",G[i][j]);
//		printf("\n");
//	}
	double ans = dijkstra(n+1);
//	for(int i=0;i<=n+1;i++) 
//		printf("dist %d is %lf\n",i,dist[i]);
	printf("%lf",ans);	
	return 0;
}
