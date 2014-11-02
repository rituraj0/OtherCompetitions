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


const ll mod = 1000000007LL;
const ll inv = 500000004LL;

ll mult( ll a , ll b )
{
    return ( ( a%mod )*(b%mod) )%mod;
}

ll sub ( ll a, ll b)
{
     return (mod*2LL+(a%mod)-(b%mod) )%mod;
}

ll add( ll a , ll b)
{
    return ( (a%mod)+(b%mod) )%mod;
}
int main()
{
 ios_base::sync_with_stdio(0);

 ll a, b;

 cin>>a>>b;

 ll ans=0;

 ll as=a*(a+1)/2LL;

 ll all=mult(as , b);
    all=add(a,all);

 for(ll c=1;c<b;c++)
   {
            ll tp=mult(c,all);

            ans=add(ans,tp);
   }

   cout<<ans<<endl;

 return 0;

}
