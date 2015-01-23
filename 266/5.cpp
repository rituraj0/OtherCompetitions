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

vector<int> graf[maxn];

int  done[maxn];

int in[maxn],out[maxn];//for dfs time

int curr_time=0;

void dfs( int u)
{
    if( done[u])
         return;

    done[u]=true;

    in[u]=curr_time++;

    for(int i=0;i<graf[u].size();i++)
    {
        int v=graf[u][i];

        dfs(v);
    }

    out[u]=curr_time++;
}


vector<int> input[maxn];


int baap[maxn];

int root( int x)
{
    if( baap[x]==x )
        return x;

    return baap[x] = root( baap[x] );
}

void join( int x , int y)
{
    int xp=root(x), yp= root(y);

    if( xp == yp )
        return;

    if( rand() &1 )
        baap[xp]=yp;
    else
        baap[yp]=xp;
}


bool head[maxn];
int start[maxn];

bool ans[maxn];

vector< pair<int,int> > query[maxn];

int main()
{
    int n,ed;

    fill(head,true);

   // print( head[10] );

    cin>>n>>ed;

    int a,b,c;

    int doc_id=1;

    for(int k=1;k<=ed;k++)
    {
        cin>>a;

        if( a == 1)
        {
            cin>>b>>c; // b ka boss is c

            graf[c].pb(b);

            head[b]=false;
            input[k].pb(a);input[k].pb(b);input[k].pb(c);
        }
       else if( a == 2 )
       {
             cin>>b;

             start[doc_id++]=b;

             input[k].pb(a); input[k].pb(b);
       }
      else
      {
             cin>>b>>c;

             input[k].pb(a);input[k].pb(b);input[k].pb(c);

             query[c].pb( mp(b,k) );//doc.pb (emp,time)
      }

    }


    fill(done,0);

    for(int i=1;i<=n;i++)
         if( head[i])
           dfs(i);
//
//    for(int i=1;i<=n;i++)
//        cout<<in[i]<<"_"<<out[i]<<endl;


    for(int i=1;i<=n;i++)
        baap[i]=i;

    doc_id = 1;

    for(int k=1;k<=ed;k++)
    {
        if( input[k][0]==1)
        {
            join( input[k][1], input[k][2] );
        }
        else if( input[k][0] == 2 )
        {
          //do nothing

          int down = input[k][1];

          for(int i=0;i<query[doc_id].size();i++)
          {
              int tm= query[doc_id][i].Y;
              int up = query[doc_id][i].X;

              if( (root(up) == root(down) ) && (in [up] <= in[down] ) && ( out[down] <= out[up]) )
               {
                 ans[tm]=true;
               }
          }

          doc_id++;
        }
    }

    for( int k=1; k<=ed; k++ )
         if( input[k][0] == 3 )
            {
                if( ans[k])
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }

    return 0;

}
