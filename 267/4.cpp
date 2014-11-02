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


string in[maxn];

int n;
int id;
int edcont;
string ed[maxn][2];

pair<int,int> val[maxn];
vector<int> graf[maxn];

map<string,int> mapa;

pair<int,int> cont( string in)
{
    pair<int,int> ans(0,0);

    for(int i=0;i<sz(in);i++)
        if( in[i]=='r')
         ans.X++;

         ans.Y=sz(in);

         return ans;
}

int dad[maxn];//-1 for no dad

bool inc[maxn];
char color[maxn];

void  print_cycle(int v)
{
    int w=v;

    pair<int,int> ans=mp( (1<<28) ,(1<<28) );

    do
     {
       w=dad[w];

       ans=min( ans , val[w] );
       // cout<<w<<"..";
      }while(w!=v);


      //cout<<endl;


              w=v;

             do
             {
               w=dad[w];

               val[w]=ans;
              // cout<<w<<"  ";
              }while(w!=v);

}


void dfs(int u)
{
     color[u]='g';

     for(int i=0;i<graf[u].size();i++)
       {
          int v=graf[u][i];

          if( color[v]=='g' && v!=dad[u] )
            {
             dad[v]=u;

             print_cycle(v);
             }

           if( color[v]=='w')
             { dad[v]=u;
                dfs(v);
             }
        }
  color[u]='b';
}

void find_cycle()
{
     for(int i=1;i<=n;i++)
      {color[i]='w';
       dad[i]=-1;
      }

      for(int i=1;i<=n;i++)
        if( color[i]=='w')
           dfs(i);
}

//***************second DFS *************

bool done[maxn];

pair<int,int> solve( int u)
{
    if(  done[u] )
          return val[u];

    done[u]=true;

     for(int i=0;i<sz(graf[u]);i++)
     {
         val[u]=min( val[u] , solve( graf[u][i] ) );
     }

      return val[u];
}

int main()
{
 ios_base::sync_with_stdio(0);

int N;
 cin>>N;

 for(int i=1;i<=N;i++)
     { cin>>in[i];
       transform(in[i].begin(), in[i].end(), in[i].begin(), ::tolower);

      // cout<<in[i]<<endl;
     }


 cin>>edcont;

 int id=1;

 for(int i=1;i<=edcont;i++)
 {
      cin>>ed[i][0]>>ed[i][1];

      transform(ed[i][0].begin(), ed[i][0].end(), ed[i][0].begin(), ::tolower);
      transform(ed[i][1].begin(), ed[i][1].end(), ed[i][1].begin(), ::tolower);

      //cout<<ed[i][0]<<"   "<<ed[i][1]<<endl;

      if( mapa.count(ed[i][0])==0 )
        {
            val[id]=cont( ed[i][0] );
            mapa[ ed[i][0] ]=id++;
        }

       if( mapa.count(ed[i][1])==0 )
        {
            val[id]=cont( ed[i][1]);
            mapa[ ed[i][1] ]=id++;
        }

        //cout<<mapa[ ed[i][0] ]<<"  "<<mapa[ ed[i][1] ]<<endl;

        graf[ mapa[ ed[i][0] ] ].pb( mapa[ ed[i][1] ] );
 }

  n=id-1;


  find_cycle();


  //Now onemore dfs

  for(int cn=0;cn<2;cn++)
  {
        fill(done,0);

          for(int j=1;j<=n;j++)
             solve( j);
  }

  pair<int,int> ans=mp(0,0);


  for(int i=1;i<=N;i++ )
  {
       if( mapa.count( in[i]) ==0 )
       {
         pair<int,int>curr=cont(in[i]);

         ans.X+=curr.X;
         ans.Y+=curr.Y;
       }
       else
       {
           int k=mapa[ in[i] ];

           ans.X+=val[k].X;
           ans.Y+=val[k].Y;
       }
  }


  cout<<ans.X<<" "<<ans.Y<<endl;


 return 0;

}
