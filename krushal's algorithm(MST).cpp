#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


int main()
{
    ll v,i,j;
    
    cin>>v;//example 6
    ll a[v][v],k=0,b[v*v],v1[v*v],v2[v*v];
    
    unordered_map<ll,unordered_map<ll,ll>>m;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            
            cin>>a[i][j];
            
        }
    }
    /*INPUT FORMAT
    0 2 0 6 0 3
    2 0 3 8 5 0
    0 3 0 0 7 0
    6 8 0 0 9 0
    0 5 7 9 0 0
    3 0 0 0 0 0
    */
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            
            cin>>a[i][j];
            if(a[i][j]>0)
            {
                b[k]=a[i][j];
                v1[k]=i;
                v2[k]=j;
                k++;
                a[j][i]=0;
            }
        }
    }
    for(i=0;i<v;i++)
    {
        for(j=0;j<v-1-i;j++)    
        {
            if(b[j]>b[j+1])
            {
                swap(b[j],b[j+1]);      // Preferably do sorting using merge sort or heap sort for O(nlogn) complexity.
                swap(v1[j],v1[j+1]);    // instead of bubble sort which has O(n^2).
                swap(v2[j],v2[j+1]);
            }
        }
    }
    
    bool g[v];
    memset(g,false,sizeof(g));
    for(i=0;i<v;i++)
    {
        if(g[v2[i]]==true)
        {
            b[i]=0;
        }
        else
        {
            g[v2[i]]=true;
        }
    }
    cout<<"Edge Weight\n";
    ll sum=0;
    for(j=0;j<v;j++)
    {
        if(b[j]>0)
        {
            cout<<v1[j]<<'-'<<v2[j]<<"   "<<b[j]<<endl;
            sum+=b[j];
        }
    }
    cout<<"Minimum Cost: "<<sum;
    return 0;
}
