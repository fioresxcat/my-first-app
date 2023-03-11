
#include <bits/stdc++.h>
using namespace std ;

const int MAXN=(int)1e6+5 ;

int cnt[MAXN],pre[MAXN] ;
int f[MAXN] ;
struct Data
{
    int date,father,mother,isalive,regioncode ;

}Person[MAXN];

int convertDate(string date)
{
    return (date[0]-'0')*(1e7)+(date[1]-'0')*(1e6)+(date[2]-'0')*(1e5)+(date[3]-'0')*(1e4)
             +(date[5]-'0')*(1e3)+(date[6]-'0')*(1e2)+(date[8]-'0')*10+date[9]-'0' ;
}
int convertID(string str)
{
    int res=0 ;
    for(int i=0;i<(int)str.size();++i)
        res=res*10+str[i]-'0' ;
    return res ;
}


bool dd[MAXN] ;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.inp","r",stdin) ;
    freopen("input.out","w",stdout) ;

    int numPeople=0 ;
    vector<int> valDate ;
    while(true)
    {
        string str ; cin>>str ;
        if(str=="*") break ;
        ++numPeople ;
        string date,father,mother,isalive,regioncode ;
        cin>>date >>father >>mother >>isalive>> regioncode ;

        int dateNumber=convertDate(date) ;
        valDate.push_back(dateNumber) ;

        int motherNumber=convertID(mother) ;
        int fatherNumber=convertID(father) ;
        int regionNumber=convertID(regioncode) ;
        bool aliveNumber=(isalive=="Y"?1:0) ;

        Person[numPeople]={dateNumber,fatherNumber,motherNumber,
                              aliveNumber,regionNumber} ;
    }

    sort(valDate.begin(),valDate.end()) ;
    valDate.resize(unique(valDate.begin(),valDate.end())-valDate.begin()) ;
    for(int i=1;i<=numPeople;++i)
    {
        int t=lower_bound(valDate.begin(),valDate.end(),Person[i].date)-valDate.begin()+1 ;
        cnt[t]++ ;
       // cout<<Person[i].date<<"\n" ;
    }

    for(int i=1;i<=numPeople;++i)
    {
        pre[i]=pre[i-1]+cnt[i] ;
    }

    for(int i=1;i<=numPeople;++i)
    {
        if(Person[i].isalive)
        {
            int mother=Person[i].mother ;
            int father=Person[i].father ;
            //cout<<mother<<" "<<father<<"\n" ;
            if(Person[father].isalive)
                f[i]=max(f[i],f[father]+1) ;
            if(Person[mother].isalive)
                f[i]=max(f[i],f[mother]+1) ;
        }
    }



    while(true)
    {
        string str ; cin>>str ;
        if(str=="***") break ;
        if(str=="NUMBER_PEOPLE_BORN_AT")
        {
            string date ;
            cin>>date;
            int t=convertDate(date) ;
            auto it=lower_bound(valDate.begin(),valDate.end(),t) ;
            if(it==valDate.end() || *it!=t) cout<<0<<"\n" ;
            else cout<<cnt[it-valDate.begin()+1]<<"\n" ;
        }
        if(str=="NUMBER_PEOPLE")
        {
            cout<<numPeople<<"\n" ;
        }

        if(str=="NUMBER_PEOPLE_BORN_BETWEEN")
        {
            string date ;
            cin>>date ;
            int t=convertDate(date) ;
            cin>>date ;
            int k=convertDate(date) ;
            int r=upper_bound(valDate.begin(),valDate.end(),k)-valDate.begin() ;
            int l=lower_bound(valDate.begin(),valDate.end(),t)-valDate.begin() ;
            cout<<pre[r]-pre[l]<<"\n" ;
        }

        if(str=="MOST_ALIVE_ANCESTOR")
        {
            string code ; cin>>code ;
            int t=convertID(code) ;
            cout<<f[t]<<"\n" ;
        }

        if(str=="MAX_UNRELATED_PEOPLE")
        {
            int ans=0 ;

            #define MASK(x) (1LL<<(x))
            #define BIT(x,i) (((x)>>(i))&1)
            for(int mask=1;mask<=MASK(numPeople)-1;++mask)
            {
                bool ok=true ;
                for(int s=1;s<=numPeople;++s)
                if(BIT(mask,s-1))
                {
                   queue<int> q ;
                   q.push(s) ;
                   memset(dd,false,sizeof dd) ;
                   dd[s]=true ;

                   while(!q.empty())
                   {
                       int u=q.front() ;
                       if(u!=s && BIT(mask,u-1)) ok=false ;
                       q.pop() ;
                       if(dd[Person[u].father]==0 && Person[u].father!=0)
                       {
                           dd[Person[u].father]=1 ;
                           q.push(Person[u].father) ;
                       }
                       if(dd[Person[u].mother]==0 && Person[u].mother!=0)
                       {
                           dd[Person[u].mother]=1 ;
                           q.push(Person[u].mother) ;
                       }

                   }
                }
                if(ok==true)
                {
                    ans=max(ans,__builtin_popcount(mask)) ;
                }

            }
            cout<<ans <<"\n" ;
        }



    }


    return 0 ;
}
