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

bool done[7000];//if true , started to light a candle at this time

int n,rn, req;

vector<int> in;

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n>>rn>>req;

 in.resize(n);

 for(int i=0;i<n;i++)
    {

      cin>>in[i];

      in[i]+=400;//offset
    }

 sort( in.begin() , in.end() );

 fill( done,0);

 int ans=0;

 for(int i=0;i<n;i++)//for current ghost
 {
     int got = 0 ;

     for(int j=0;j<in[i];j++)
         if( done[j] )
           if( j + rn >= in[i] )
              got++;

     int rem = req - got;

     int aval =0;

     for(int j = in[i]-rn ; j< in[i] ;j ++ )
        if( !done[j])
            aval++;

        if( aval < rem )
        {
            cout<<"-1"<<endl;
            return 0;
        }

        int id = in[i]-1;

        while( rem > 0 )
        {
            if( ! done[id] )
            {
                done[id] = true;
                rem--;
                ans++;
            }
            id--;
        }

 }

 cout<<ans<<endl;

 return 0;

}
