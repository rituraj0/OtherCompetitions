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

#define maxn 100009

int pos[32][maxn];

bool bit[32][maxn];

int sum[32][maxn];

int lf[maxn],rt[maxn],val[maxn];

int main()
{
 ios_base::sync_with_stdio(0);


 int n,m;

 cin>>n>>m;


 for(int i=1;i<=m;i++)
     cin>>lf[i]>>rt[i]>>val[i];

   //setting pos
   fill(pos,63);

 for(int b=0;b<=30;b++)
    for(int i=1;i<=m;i++)
         if(  val[i] & (1<<b) )
         {
                pos[b][ rt[i] ]=min( pos[b][ rt[i] ] , lf[i]);
          }

    //set bits
    fill( bit,0);

    for(int b=0;b<=30;b++)
    {
         int mn=n+10;

        for(int  i=n;i>=1;i--)
        {
            mn=min( mn , pos[b][i]);

            if( mn <= i)
                bit[b][i]=true;

        }
    }

  //Now sum

  for(int b=0;b<=30;b++)
  {
      sum[b][0]=0;

      for(int i=1;i<=n;i++)
         {
             sum[b][i]=sum[b][i-1]+( bit[b][i]==true);
         }
  }

  //print sum

  // noe for invalid pos

  for(int b=0;b<=30;b++)
    for(int i=1;i<=m;i++)
         if(  (val[i] & (1<<b) ) ==0 )
         {
            int  ls=sum[b][ lf[i] -1];
            int rs=sum[b][ rt[i] ];

            if(ls+(rt[i]+1-lf[i])==rs)//no zero between on this bit
            {
                cout<<"NO"<<endl;

                return 0;
            }
        }

   //now print ing ans

   cout<<"YES\n";

   for(int i=1;i<=n;i++)
   {
       int sm=0;

       for(int b=0;b<=30;b++)
         if( bit[b][i])
           sm+=(1<<b);

       cout<<sm<<" ";
   }

   cout<<endl;



//



 return 0;

}
