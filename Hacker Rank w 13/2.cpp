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

const  ll mod = (1e9+7);
int main()
{
 ios_base::sync_with_stdio(0);

 int test;

 cin>>test;

 while(  test--)
 {
      map<ll, int> mapa;

      string in;

      cin>>in;

      int n=sz(in);

      for(int i=0;i<n;i++)
         for(int j=i;j<n;j++)
          {
             vector<int> here;

             for(int k=i;k<=j;k++)
             {
                here.pb( in[k]-'a'+1);
             }

             sort( here.begin() , here.end() );

             ll curr=0;
             ll pw=1;

             for(int k=0;k<sz(here);k++)
              {
                curr= curr + ( pw * here[k] );
                curr = curr %mod;
                pw =(pw*26LL)%mod;
              }

            mapa[curr]++;
        }

        int ans=0;

        for( map<ll,int>::iterator it = mapa.begin(); it!=mapa.end() ;it++ )
        {
            int cc=it->second;

            ans+=cc*(cc-1)/2;
        }

        cout<<ans<<endl;
 }

 return 0;

}
