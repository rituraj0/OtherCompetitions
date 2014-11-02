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

#define maxn (1<<20)

int n;
int init[maxn],goal[maxn];
bool done[maxn];
int dep[maxn];
int odd[maxn],even[maxn];//inclusive
int part[maxn];

vector<int> graf[maxn];


int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n;

 int a,b;

 for(int i=1;i<=n-1;i++)
 {
     cin>>a>>b;
     graf[a].pb(b);
     graf[b].pb(a);
 }

 for(int i=1;i<=n;i++)
     cin>>init[i];

 for(int i=1;i<=n;i++)
     cin>>goal[i];


 fill(done,0); fill(dep,0);

 vector<int> ans;
 queue<int> Q;

 done[1]=true;
 dep[1]=1;

 if( goal[1]!=init[1])
 {
     ans.pb(1);
     odd[1]++;
 }

 for(int i=0;i<graf[1].sz;i++)
     {Q.push( graf[1][i] );
       part[ graf[1][i] ]=1;
     }


     while(Q.size()>0)
     {
         int tp=Q.front() ; Q.pop();

         if( done[tp] )
             continue;

         done[tp]=true;

         int pr=part[tp];

         dep[tp]=dep[pr]+1;

         odd[tp]=odd[pr]; even[tp]=even[pr];

         if( dep[tp]&1)
         {
              if( odd[pr]&1)
                 init[tp]=1-init[tp];
         }
        else
        {
              if( even[pr]&1 )
                 init[tp]=1-init[tp];
        }

        if( init[tp]!=goal[tp])
        {
            ans.pb(tp);

             if( dep[tp]&1)
                 odd[tp]++;
             else
                 even[tp]++;
        }

         for(int i=0;i<graf[tp].sz;i++)
         {
              int x=graf[tp][i];

               if(!done[x])
               {
                Q.push(x);
                part[x]=tp;
               }
         }

    }

    cout<<ans.sz<<endl;

    for(int i=0;i<ans.sz;i++)
         cout<<ans[i]<<endl;



 return 0;

}
