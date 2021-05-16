#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

class edge{
    public:
    ll src;
    ll dest;
    ll wg;
};

ll fpar(ll k,ll par[])
{
    if(par[k]==k)
    return k;

    return fpar(par[k],par);
}

bool compare(edge e1,edge e2)
{
    return e1.wg < e2.wg;
}

void krush(edge *inp,ll e,ll v)
{
    sort(inp,inp+e,compare);
    
    ll *par=new ll[v];
    
    edge * out=new edge[v-1];
    
    for(ll i=0;i<v;i++)
    par[i]=i;
    
    ll count=0;
    ll i=0;
    
    while(count!= (v-1))
    {
        edge cedge=inp[i];
        
        ll sp=fpar(cedge.src,par);
        ll dp=fpar(cedge.dest,par);
        
        if(sp!=dp)
        {
            out[count]=cedge;
            count++;
            par[sp]=dp;
        }
        i++;
    }
    cout<<"Source"<<" "<<"Destination"<<" "<<"Weight"<<endl;
    for(i=0;i<v-1;i++)
    {
        if(out[i].src<out[i].dest)
        cout<<out[i].src<<" "<<out[i].dest<<" "<<out[i].wg;
        else
        cout<<out[i].dest<<" "<<out[i].src<<" "<<out[i].wg;
        
        cout<<endl;
    }
    
}

int main()
{
    ll e,v,i;
    cin>>e>>v;
    
    edge *inp=new edge[v];
    
    for(i=0;i<e;i++)
    {
        ll s,d,w;
        cin>>s>>d>>w;
        inp[i].src=s;
        inp[i].dest=d;
        inp[i].wg=w;
    }
    
    krush(inp,e,v);
    
    return 0;
}
