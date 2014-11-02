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


int main()
{
 ios_base::sync_with_stdio(0);

 ll n,x;

 cin>>n>>x;

 vector<ll> in(n);

 for(int i=0;i<n;i++)
     cin>>in[i];

 sort( in.bg, in.en);

 ll ans=0;

 for(int i=0;i<n;i++)
 {
     x=max(1LL,x);
     ans+=in[i]*x;
     x--;
 }

 cout<<ans<<endl;


 return 0;

}
