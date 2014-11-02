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

int in[100009];
int fs[100009], bs[100009];
int n;

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n;

 for(int i=1;i<=n;i++)
     cin>>in[i];

 //fs
  fs[0]=fs[1]=0;

  for(int i=2;i<=n;i++)
     { fs[i]=fs[i-1]+max(0,in[i]-in[i-1]);
        // cout<<fs[i]<<"  ";
     }

     //cout<<endl;

  //bs
  bs[n+1]=bs[n]=0;

  for(int i=n-1;i>=1;i--)
    {
     bs[i]=bs[i+1]+max( 0 , in[i+1] - in[i]);

     //cout<<bs[i]<<" ";
    }

    //cout<<endl;

  int ans=fs[n];
  int id=-1;

  for(int i=1;i<=n-1;i++)//try i & i+1
  {
      swap(in[i],in[i+1]);

      int tp=fs[i-1] + bs[i+2];

      if( i-1>=1)
       tp+=max(0, in[i]-in[i-1]);

       tp+=max(0 , in[i+1]-in[i] );

       if(i+2<=n)
         tp+=max( 0 , in[i+2]-in[i+1]);

       if(tp<ans)
       {
           ans=tp;
           id=i;
       }

     swap(in[i],in[i+1]);

  }

  cout<<id<<endl;

 return 0;

}
