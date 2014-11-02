#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz size()
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

ll n;
ll in[500005];
ll dp[500005];
ll cont[500005];


int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n;

 for(int i=1;i<=n;i++)
     cin>>in[i];

 dp[n+1]=0;

 for(int i=n;i>=1;i--)
     dp[i]=in[i]+dp[i+1];

     print(dp[1]);

 if(dp[1]%3!=0)
 {
     cout<<"0\n";
     return 0;
 }

 ll req=dp[1]/3LL;

 fill(cont,0);//use as cont

 for(int i=n;i>=1;i--)
 {
     cont[i]=cont[i+1];

     if( dp[i]==req)
       cont[i]++;

       print(cont[i]);
 }

 ll ans=0;

 ll cs=0;

 print(cs);

 for(int i=1;i<=n;i++)
 {
     cs+=in[i];

     if(cs!=req)
         continue;

     ans+=cont[i+2];
 }

 cout<<ans<<endl;


 return 0;

}
