#include<bits/stdc++.h>
using namespace std;
int Excgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1;y=0;
		return a;
	}
	int d=Excgcd(b,a%b,x,y);
	int t=x;x=y;y=t-(a/b)*y;
	return d;
}
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	int a=1000,b=2500;
	int x1,y1;
	int g = Excgcd(a,b,x1,y1);
	if(y%g!=0){
		printf("-1\n");
	}
	else{
		printf("%d %d %d\n",x1,y1,g);
	}
	
}
