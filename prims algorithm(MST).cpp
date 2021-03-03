#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


int main()
{
    ll v,i,j;
    
    cin>>v;
    ll a[v][v];
    
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            
            cin>>a[i][j];
        }
    }
    bool g[v][v];
    memset(g,false,sizeof(g));
    ll flag=0;
    bool m[v];
    i=0;
    ll d[v];
    for(j=0;j<v;j++)
    d[j]=10000;
    ll p[v],pos;
    ll n=0;
    d[i]=0;
    while(n!=1)
    {
        unordered_map<bool,ll>b;
        ll mn=10000;
        m[i]=true;
        for(j=0;j<v;j++)
        {
            if(a[i][j]<d[j] && a[i][j]>0)
            {
                d[j]=a[i][j];
                p[j]=i;
            }
        }
        for(j=0;j<v;j++)
        {
            if(d[j]<mn && d[j]!=0 && m[j]!=true)
            {
                mn=d[j];
                pos=j;
            }
        }
        i=pos;
        for(j=0;j<v;j++)
        b[m[j]]++;
        n=b.size();
    }
    cout<<"Edge Weight\n";
    ll sum=0;
    for(j=1;j<v;j++)
    {
        sum+=a[p[j]][j];
        cout<<p[j]<<'-'<<j<<"   "<<a[p[j]][j]<<endl;
    }
    cout<<"Minimum Cost: "<<sum;
    return 0;
}
