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

 string ans="Alien";

 int in[10];


 for(int i=1;i<=6;i++)
     cin>>in[i];

  //try bear
  for(int  i=1;i<=6;i++)//ehad
    for(int j=1;j<=6;j++)//body
    {
       if(i==j)
         continue;

       vector<int> rem;

        for(int k=1;k<=6;k++)
              if(k!=i)
                 if(k!=j)
                   rem.pb( in[k]);

        sort( rem.begin() , rem.end() );

        if( rem[0]==rem[3])
        {
            if(in[i]==in[j])
                 ans="Elephant";
            else
                 ans="Bear";
        }
    }

    cout<<ans<<endl;


 return 0;

}
