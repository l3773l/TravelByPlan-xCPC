#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> vecs;
void build_vecs(int type,int blocks,vector<int> &ans){
	for(int i=0;i<blocks;i++){
				ans.push_back(-1);ans.push_back(2);
				ans.push_back(-1);ans.push_back(2);
				ans.push_back(1);ans.push_back(-2);
				ans.push_back(1);ans.push_back(-2);
	}
			for(int i=0;i<=type;i++){
				for(auto x : vecs[i]){
					ans.push_back(x);
				}
			}
}
int main(){
	int T;
	T = 1e5+ 7;
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> init0 = {-1,2};
	vector<int> init1 = {1,-2};
	vecs.push_back(init0);vecs.push_back(init0);
	vecs.push_back(init1);vecs.push_back(init1);
	for (int n = 2; n <= T; ++n) {
//		int n;
//		cin>>n;
		if(n==2){
			cout<<"1 -3 -3 1"<<"\n";
			continue;
		}
		int type = (n-2)%4;
		int blocks = (n-2)/4; // the total blocks
		vector<int> ans;
		if(type==0){
			ans.push_back(4);//a_1
			build_vecs(type,blocks,ans);
			ans.push_back(-2); //a_n 
		}
		if(type==1){
			ans.push_back(4);//a_1
			build_vecs(type,blocks,ans);
			ans.push_back(-3); //a_n 
		}
		if(type==2){
			ans.push_back(4);//a_1
			build_vecs(type,blocks,ans);
			ans.push_back(2); //a_n 
		}
		if(type==3){
			ans.push_back(4);//a_1
			build_vecs(type,blocks,ans);
			ans.push_back(-1); //a_n 
		}
//		if (type > 3 || type < 0) cout << "oops!" << endl;
//		cout<<"N is "<<n<<"\n"<<"The length of ans is "<<ans.size()<<"The blocks is "<<blocks<<" type is"<<type<<"\n";
//		cout<<"ans is \n";
//		for(auto x : ans){
//			cout<<x<<" ";
//		}
		int lsum =0,rsum=0;
		for(int i=0;i<ans.size();i+=2){
			lsum+= ans[i]*ans[i+1];
		}
		rsum = ans[0] * (ans[ans.size()-1]);
		for(int i=1;i<ans.size()-1;i+=2){
			rsum *= (ans[i]+ans[i+1]);
		}
		if (lsum != rsum) {
			cout << "err! " <<  n << endl;
			cout<<"lsum is"<<lsum<<"rsum is"<<rsum<<"\n";
		}
		if (n % 1000 == 0) cout << n << endl;
//		cout<<endl;	
	}
}
