#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n,i,num;
    cin>>n;
    priority_queue <ll, vector<ll>, greater<ll>> pq;
    for(i=0;i<n;i++)
    {
        cin>>num;
        pq.push(num);
    }
    ll k=0,sum=0,s=0;
    while(pq.size()>1)
    {
        s=0;
        s+=pq.top();
        pq.pop();
        s+=pq.top();
        pq.pop();
        pq.push(s);
        sum+=s;
    }
    cout<<sum;
    return 0;
}
