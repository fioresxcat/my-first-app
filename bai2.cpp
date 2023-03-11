
#include <bits/stdc++.h>

using namespace std;
const int MAXN=35 ;
int n,m ;
int f[MAXN][MAXN] ;
struct Data
{
    int u,v,w ;
    friend bool operator <(const Data &A,const Data &B)
    {
        return A.w<B.w ;
    }
};
int root[MAXN] ;
int Root(int u) {return root[u]?root[u]=Root(root[u]):u ;}
bool Union(int u,int v)
{
    int p=Root(u) ;
    int q=Root(v) ;
    if(p==q) return false ;
    root[p]=q ;
    return true ;
}
int a[MAXN] ;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(f,0x3f,sizeof f) ;
    cin>>n >>m ;
    for(int u=1;u<=n;++u)
        f[u][u]=0 ;

    while(m--)
    {
        int u,v,w; cin>>u >>v >>w ;
        f[u][v]=min(f[u][v],w) ;
        f[v][u]=min(f[v][u],w) ;
    }
    for(int k=1;k<=n;++k)
    {
        for(int u=1;u<=n;++u)
        {
            for(int v=1;v<=n;++v)
                f[u][v]=min(f[u][v],f[u][k]+f[k][v]) ;
        }
    }

    vector<Data> edges ;

    int k ; cin>>k ;
    for(int i=1;i<=k;++i)
        cin>>a[i] ;

    for(int i=1;i<=k;++i)
    {
        for(int j=i+1;j<=k;++j)
        {
            edges.push_back({i,j,f[i][j]}) ;
        }
    }
    sort(edges.begin(),edges.end()) ;
    int ans=0 ;
    for(auto x: edges)
    {
        ans+=Union(x.u,x.v)*x.w ;
    }
    cout<<ans ;


    return 0 ;
}
