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

int  cont[1<<21];

int main()
{
 ios_base::sync_with_stdio(0);

 int n,k;

 cin>>n>>k;

 int x;

 int mn=(1<<21),mx=0;

 fill(cont,0);

 for(int i=1;i<=n;i++)
 {
     cin>>x;

     cont[x]++;

     mx=max(mx,x);
     mn=min(mn,x);
 }

 if( mn <= k+1 )
 {
     cout<<mn<<endl;
     return 0;
 }

 for(int i=1;i<(1<<21);i++)
    cont[i]=cont[i-1]+cont[i];

 int ans=0;

 for(int div=k+1;div<=mn;div++)
 {
     int cn =0;
     int it = mx/div;

     for(int j=1;j<=it;j++)
     {
         int le=j*div;
         int rt=le+k;

         cn+=cont[rt]-cont[le-1];
     }

     if(cn==n)
        ans=div;
 }

 cout<<ans<<endl;

 return 0;

}
