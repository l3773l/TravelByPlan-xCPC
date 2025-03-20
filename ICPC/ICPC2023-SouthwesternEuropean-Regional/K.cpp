//
// Created by LL06p on 2024/4/4.
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6+5;
const int INF = 1e9+7;
typedef long long ll;
typedef pair<int,int> pii;
struct Splay{
    int rt,tot,fa[maxn],ch[maxn][2],val[maxn],cnt[maxn],sz[maxn];
    void maintain(int x){
        sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x];
    }
    bool get(int x){
        return x==ch[fa[x]][1];
    }
    void clear(int x){
        ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;
    }
    void rotate(int x){
        int y = fa[x],z=fa[y],chk=get(x);
        ch[y][chk]=ch[x][chk^1];
        if(ch[x][chk^1]) fa[ch[x][chk^1]] = y;
        ch[x][chk^1]=y;
        fa[y]=x;fa[x]=z;
        if(z) ch[z][y==ch[z][1]]=x;
        maintain(y);
        maintain(x);
    }
    void splay(int x){
        for(int f = fa[x];f=fa[x]; rotate(x))
            if(fa[f]) rotate(get(x)==get(f)?f:x);
        rt = x;
    }
    void ins(int k){
        if(!rt){
            val[++tot] = k;
            cnt[tot]++;
            rt = tot;
            maintain(rt);
            return ;
        }
        int cur = rt,f=0;
        while (true){
            if(val[cur]==k){
                cnt[cur]++;
                maintain(cur);
                maintain(f);
                splay(cur);
                break;
            }
            f = cur;
            cur = ch[cur][val[cur]<k];
            if(!cur){
                val[++tot]=k;
                cnt[tot]++;
                fa[tot] = f;
                ch[f][val[f]<k] = tot;
                maintain(tot);
                maintain(f);
                splay(tot);
                break;
            }
        }
    }

    int kth(int k){
        int cur = rt;
        while(true){
            if(ch[cur][0]&&k<=sz[ch[cur][0]]) cur = ch[cur][0];
            else{
                k-=cnt[cur]+sz[ch[cur][0]];
                if(k<=0){
                    splay(cur);
                    return val[cur];
                }
                cur = ch[cur][1];
            }
        }
    }
    int pre(){
        int cur = ch[rt][0];
        if(!cur) return cur;
        while(ch[cur][1]) cur = ch[cur][1];
        splay(cur);
        return cur;
    }
    int rk(int k){
        int res=0,cur=rt;
        while(true){
            if(k<val[cur]) cur = ch[cur][0];
            else{
                res+=sz[ch[cur][0]];
                if(k==val[cur]){
                    splay(cur);
                    return res+1;
                }
                res+=cnt[cur];
                cur = ch[cur][1];
            }
        }
    }
    void del(int k){
        rk(k);
        if(cnt[rt]>1){
            cnt[rt]--;
            maintain(rt);
            return ;
        }
        if(!ch[rt][0]&&!ch[rt][1]){
            clear(rt);
            rt = 0;
            return ;
        }
        if(!ch[rt][0]){
            int cur = rt;
            rt = ch[rt][1];
            fa[rt]=0;
            clear(cur);
            return ;
        }
        if(!ch[rt][1]){
            int cur = rt;
            rt = ch[rt][0];
            fa[rt]=0;
            clear(cur);
            return ;
        }
        int cur = rt,x = pre();
        fa[ch[cur][1]]=x;
        ch[x][1]=ch[cur][1];
        clear(cur);
        maintain(rt);
    }
}tree;
int a[maxn],b[maxn];
int c[maxn],d[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        tree.ins(i);
    }
//    for(int i=1;i<=n;i++){
//        printf("i is %d kth is %d",i,tree.kth(1));
//        tree.del(tree.kth(1));
//    }
    for(int i=1;i<=n/2;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n/2;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n/2;i++){
        c[i] = tree.kth(a[i]);
        tree.del(c[i]);
        d[i] = tree.kth(b[i]);
        tree.del(d[i]);
    }
    for(int i=1;i<=n/2;i++) printf("%d ",c[i]);
    printf("\n");
    for(int i=1;i<=n/2;i++) printf("%d ",d[i]);
    return 0;
}