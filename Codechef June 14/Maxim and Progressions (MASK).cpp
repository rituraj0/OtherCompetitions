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

int in[110],n;

void solve()
{

     cin>>n;

     for(int i=0;i<n;i++)
         cin>>in[i];

     int ans=0;

     for(int mask=0;mask<(1<<n);mask++)
     {
          vector<int> tp;

              for(int i=0;i<n;i++)
                 if( mask&(1<<i))
                  tp.pb( in[i]);

              if( tp.sz<=2)
              {  ans++;
                 continue;
              }

           int d=tp[1]-tp[0];
            bool cool=true;

            for(int i=2;i<n;i++)
                 if( in[i]-in[i-1]!=d)
                   cool=false;

            if( cool)
                 ans++;
     }

     cout<<pow(2,n)-ans<<endl;



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
