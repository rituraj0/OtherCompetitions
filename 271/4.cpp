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

int in[1<<20];

int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 cin>>n;

 for(int i=1;i<=n;i++)
     cin>>in[i];

 int Q;

 cin>>Q;

 for(int q=1;q<=Q;q++)
 {
        int x;
        cin>>x;
        int cn=0;

        for(int i=1;i<=n;i++)
        {
                int g=in[i];

                if( g < x)
                     continue;

             for(int j=i;j<=n;j++)
                {
                    g=__gcd(g,in[j]);

                    if(g==x)
                        cn++;
                    else if( g  < x)
                       break;
                }
        }
    cout<<cn<<endl;
 }

 return 0;

}
