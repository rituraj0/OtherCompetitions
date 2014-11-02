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

vector<int> all;

bool prime[1<<20];

int in[1<<20],pos[1<<20];

void init()
{
     fill(prime,true);

     print(prime[5]);

      for(int i=2;i<=100009;i++)
          if( prime[i])
      {
               all.pb( i );

                for(int j=2*i;j<=100009;j+=i)
                     prime[j]=false;
      }

      sort(all.bg,all.end());
}

int main()
{
 ios_base::sync_with_stdio(0);

   init();

  int n;

  cin>>n;

  fill(pos,-1);

   for(int i=1;i<=n;i++)
     { in[i]=n-i+1;
       pos[ in[i] ]=i;
     }


     vector< pair<int,int> > ans;

    for(int curr=1;curr<=n;curr++)
    {
          while( pos[curr]!=curr)
          {
               int d=pos[curr]-curr+1;

               int old=pos[curr];

               vector<int>::iterator it=lower_bound(all.begin(),all.end(),d);

               if(*it!=d)
                 it--;

               int can=*it;

//               pos[curr]=

               int nw=pos[curr]+1-can;

               pos[ in[old] ]=nw;
               pos[ in[nw] ]=old;

               swap( in[old],in[nw] );

               ans.pb( mp(nw,old) );
          }
    }


    cout<<ans.size()<<endl;

    for(int i=0;i<(int)ans.sz;i++);
        // cout<<ans[i].X<<" "<<ans[i].Y<<endl;


         cout<<"\n\n\n\Sortedis\n\n\n";

         for(int i=1;i<=n;i++)
            if(i!=in[i])
             cout<<in[i]<<"  ";


 return 0;

}
