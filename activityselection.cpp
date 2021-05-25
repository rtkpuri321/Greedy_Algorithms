// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    
    struct act{
        int start,finish;
    };
    
    static bool actcomp(act s1,act s2)
    {
        return s1.finish<s2.finish;
    }
    
    int maxMeetings(int s[], int e[], int n)
    {
        int i,j;
        
        act a[n];
        
        
        for(i=0;i<n;i++)
        {
            a[i].start=s[i];
            a[i].finish=e[i];
        }
        
        sort(a,a+n,actcomp);
        
        int count=1;
        
        j=0;
        for(i=1;i<n;i++)
        {
            if(a[i].start>a[j].finish)
            {
                count++;
                j=i;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
