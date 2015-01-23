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


int main()
{
 ios_base::sync_with_stdio(0);

  int n;
  int in[505];

  cin>>n;

  int mx=0;

  for(int i=1;i<=n;i++)
     {
         cin>>in[i];

         mx=max( mx , in[i]);
     }

  int gc=__gcd(in[1],in[2]);

  for(int i=3;i<=n;i++)
     gc= __gcd(gc , in[i] );

   int cont = (mx/gc)-n;

   if( cont &1 )
    cout<<"Alice"<<endl;
   else
    cout<<"Bob"<<endl;

 return 0;

}
