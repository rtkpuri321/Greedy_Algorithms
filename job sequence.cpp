#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n,i,j;
    cin>>n;
    ll p[n],d[n];
    for(i=0;i<n;i++)
    {
        cin>>p[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>d[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j]<p[j+1])
            swap(p[j],p[j+1]);
            swap(d[j],d[j+1]);
        }
    }
    for(i=0;i<n;i++)
    cout<<p[i]<<" ";
    cout<<endl;
    ll a[n];
    memset(a,0,sizeof(a));
    ll mx=*max_element(d,d+n);
    for(i=0;i<n;i++)
    {
        if(a[d[i]-1]==0)
        a[d[i]-1]=p[i];
        else 
        {
            d[i]=d[i]-1;
            while(d[i]!=0)
            {
                if(a[d[i]]==0)
                a[d[i]]=p[i];
                d[i]--;
            }
        }
    }
    cout<<accumulate(a,a+n,0);
    return 0;
}
