#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n;string s;
bool vis[maxn];
struct Node {
    int pos;string str;
};
vector<Node> ans;
void solve(){
    for(int i=0;i<n;){
        if(vis[i]){
            i++;
            continue;
        }
        int j = i;
        while(j+1<n&& vis[j+1]==false && (j-i+1)<3 ) j++;
        int len = (j-i+1);
        string s1 = s.substr(i,len);
        //the max string currently we can get
        char ch = s[i];
        string single,tri,doub;
        single+=ch;
        for(int j=0;j<3;j++) tri += ch;
        for(int j=0;j<2;j++) doub += ch;
        if(ch=='V'||ch=='L'||ch=='D'){
            ans.push_back({i,single});
            i++;
            continue;
        }
        // cout<<"i is "<<i<<" s1 is "<<s1<<endl;
        if(s1.length()==3){
            //the length is 3 , can be MMM or MM
            if(s1==tri) {
                ans.push_back({i,tri});
                i+=3;
                continue;
            }
            string s2 = s1.substr(0,2);
            if(s2==doub){
                ans.push_back({i,doub});
                i+=2;
                continue;
            }
            else {
             ans.push_back({i,single});
             i++;
             continue;   
            } 
        }
        if(s1.length()==2){
            if(s1==doub){
                ans.push_back({i,doub});
                i+=2;
                continue;
            }
            else {
             ans.push_back({i,single});
             i++;
             continue;   
            } 
        }
        else{
            ans.push_back({i,single});
            i++;
            continue;
        } 
    }
}
void pre(){
    for(int i=0;i<n;){
        if(i+3>n) break;
        string s1 = s.substr(i,3);
        if(s1=="MCM" || s1=="CXC" || s1=="XIX"){
            vis[i]=vis[i+1]=vis[i+2]=true;
            i= i+3;
            ans.push_back({i,s1});
            continue;
        }
        i++;
    }
}
int main(){
    cin>>n;
    cin>>s;
    pre();
    // for(int i=0;i<n;i++){
    //     cout<<"i is"<<i<<" vis  is "<<
    // }
    solve();
    cout<<ans.size()<<"\n";
    sort(ans.begin(), ans.end(), [](Node &a, Node &b){return a.pos < b.pos;});
    for (auto i : ans) {
        cout << i.str << endl;
    }
}
