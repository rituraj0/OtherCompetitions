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


int main()
{
 ios_base::sync_with_stdio(0);

 int n,k;
 int x[205];

 cin>>n>>k;

 for(int i=1;i<=n;i++)
     cin>>x[i];

  int ans=-(1<<28);

  for(int a=1;a<=n;a++)
     for(int b=a;b<=n;b++)
  {
        vector<int> in,out;

          for(int i=a;i<=b;i++)
             in.pb(x[i]);

          for(int i=1;i<a;i++)
             out.pb(x[i]);
          for(int i=b+1;i<=n;i++)
             out.pb( x[i] );

           sort(in.begin(),in.end());
           sort(out.begin(),out.end());


            for(int cn=(int)out.sz-1;(cn>=0)&&(cn>=(int)out.sz-k);cn--)
            {
                 int id=-1;

                   for(int i=0;i<in.sz;i++)
                      if( in[i]<out[cn])
                   {
                       id=i;
                       break;
                   }

                   if(id==-1)
                     break;

                   in[id]=out[cn];
            }

            int tp=0;

            for(int i=0;i<in.sz;i++)
                 tp+=in[i];

              ans=max(ans,tp);

  }

  cout<<ans<<endl;

 return 0;

}
