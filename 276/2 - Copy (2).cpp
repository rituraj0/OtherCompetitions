#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */


vector<int> all;

//./ can  do in  )(1) Todo , declare an araray and then
int solve( int lo ,int hi ,int val)//val se  maxi of all bada
{
    int ans=0;

    while( lo <= hi )
    {
        int mid=(lo+hi)/2;

        if( all[mid] < val)
        {
            ans=max(ans,all[mid]);
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }


    return ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 set<int> st;

 int n,x;

 cin>>n;

 for(int i=1;i<=n;i++)
 {
     cin>>x;
     st.insert(x);
 }



 all.pb(0);

 int mx=0;

 for( set<int>::iterator it=st.begin() ; it !=st.end() ; it++)
 {
     all.pb(*it);
     mx=max(mx,*it);
 }

 int ans=0;

// print(mx);

 for(int i=1;i<sz(all);i++)// )(n)
 {
     int tp=all[i];

    // cout<<tp<<"   " ;

     for(int j=tp;j<=2*mx;j+=tp)//O( lg (n) ) , amortized cost
     {
         //find lower at j
         int x= solve(i+1,n , j); // O(lg(n))
         // tp se bada and j se chhota
         //what if j-1 & j both , search for exavly smaaller

         ans=max( ans , x%tp);

         //cout<<j<<"-"<<x<<"   ";
     }

    // cout<<endl;
 }

 cout<<ans<<endl;

 return 0;

}
