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

#define maxn 100009

vector<int> rev[maxn],edge[maxn];

int n,ed;

deque<int> Q;

bool done[maxn];
int dist[maxn];

int main()
{

 scanf("%d%d",&n,&ed);

 int a,b;

 for(int i=1;i<=ed;i++)
 {
     cin>>a>>b;
     edge[a].pb(b);
     rev[b].pb(a);
 }

 fill(dist,-1);
 fill(done,0);

 dist[1]=0;

 Q.push_front(1);

 int ans=-1;


 while( !Q.empty() )
 {
     int curr=Q.front();Q.pop_front();
     int d=dist[curr];

     if( curr==n)
         {
             ans=d;
             break;
         }

      if( done[curr]) continue;

      done[curr]=true;

       for(int i=0;i<edge[curr].sz;i++)
       {
            int nc=edge[curr][i];
            Q.push_front(nc);

            if( dist[nc]==-1)
            {
                dist[nc]=d;
            }
           else
           {
               dist[nc]=min( dist[nc],d);
           }
       }

      for(int i=0;i<rev[curr].sz;i++)
       {
            int nc=rev[curr][i];
            Q.push_back(nc);

            if( dist[nc]==-1)
            {
                dist[nc]=d+1;
            }
           else
           {
               dist[nc]=min( dist[nc],d+1);
           }
       }

 }

 cout<<ans<<endl;



 return 0;

}
