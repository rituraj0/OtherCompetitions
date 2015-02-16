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

ll next_id( ll in)
{
    if( in&1)
        return  2LL*in;
    else
        return 2LL*in+1LL;
}

int main()
{
 ios_base::sync_with_stdio(0);

 ll expo[60];
 expo[0]=1;

 for(int i=1;i< 60 ; i++)
     expo[i]=expo[i-1]*2LL;

 ll  tar , ht;

 cin>>ht>>  tar;


 tar+=expo[ht]-1;

 vector<ll> req;

 while( tar > 0)
 {
     req.pb( tar);
     tar=tar/2LL;
 }

 sort( req.bg , req.en );

 ll curr = 1;

 ll ans =0;

 for(int i=0;i<sz(req);i++)
 {
     if( req[i] != curr)
     {
         ll ch = ht - i + 1;
         ans+= expo[ch]-1;

         curr =  req[i];
     }

     curr = next_id(curr);
 }


 cout<<ans+ht<<endl;

 return 0;

}
