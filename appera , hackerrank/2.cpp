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

int cont[100009];

bool done[100009];

int main()
{
 ios_base::sync_with_stdio(0);

 fill(cont,0);

 int n;
 cin>>n;

 cont[1]=1;
 cont[2]=2;

 for(int i=3;i<=n;i++)
 {
     int tp=2;//1 * i

      for(int j=2;j*j<=i;j++)
         if( i%j==0)
          {
              int a=j; int b=i/j;

              if( a==b)
                 tp++;
              else
                 tp+=2;
         }

       cont[i] =tp;
 }

 fill(done,0);

 ll ans=0;


 for(int i=1;i<=n;i++)
 {
//        if(i<20)
//            cout<<cont[i]<<" ";

     if( !done[ cont[i] ] )
    {
     ans+=i;
      done[ cont[i] ]=true;;

    }

 }

    cout<<ans<<endl;


 return 0;

}
