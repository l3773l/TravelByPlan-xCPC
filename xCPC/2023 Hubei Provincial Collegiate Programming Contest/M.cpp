#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long x, y;
	cin >> x >> y;
	if(y%500!=0){
		cout<<"-1"<<"\n";
		return 0;
	}
	y/=500;
	if(y%2==0){
		long long c = y/5;
		int res =  (y%10);
		if(res==6||res==8){
			if(c==0){
				cout<<-1<<"\n";
				return 0;
			}
			c-=1;//
		}
		long long b = res/2;
		long long a = (x-b-c);
		if(a<0) cout<<"-1\n";
		else cout<<a<<" "<<b<<" "<<c<<"\n";
	}
	else{
		long long c = y/5;
		int res = y%10;
		long long b;
		if(res==1||res==3){
			if(c==0){
				cout<<-1<<"\n";
				return 0;
			}
			c -=1;
			b = (res==1)? 3L : 4L;
		}
		else if(res==5){
			b = 0L;
		}
		else {
			//res = 7 /9 
			b = (res==7) ? 1L : 2L;
		}
		long long a = (x-b-c);
	    if(a<0) cout<<"-1\n";
		else cout<<a<<" "<<b<<" "<<c<<"\n";
	}
}
