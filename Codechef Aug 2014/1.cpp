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

int in[200],n,k;

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        cin>>in[i];
    }

    string ans="NO";

    for(int i=1;i<=n;i++)
         for(int j=i;j<=n;j++)
            {
                 int cn=0;

                    for(int x=i;x<=j;x++)
                          if( in[x]%2==0)
                             cn++;

                  if(cn==k)
                     ans="YES";
            }

    cout<<ans<<"\n";

}

int main()
{
 ios_base::sync_with_stdio(0);

 int test;

 cin>>test;

 while(test--)
 {
   solve();
 }

 return 0;

}
