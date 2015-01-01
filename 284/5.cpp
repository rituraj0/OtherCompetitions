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
#define pii pair<int,int>

int id=1;


vector<int> graf[3100];


vector< pair<int,int> > prime( ll in)
{
     ll save=in;;

    vector< pair<int,int> > ans;

    for(ll i=2;i*i<=in;i++)
    {
        while(in%i==0)
        {
            ans.pb( mp(i,id) );
            id++;
            in=in/i;
        }
    }

    if( in > 1)
         {ans.pb( mp(in,id) );
           id++;
         }

    ll tp=1;

    for(int i=0;i<sz(ans);i++)
         tp=tp*ans[i].X;



   /* cout<<tp<<"  **** *  "<<save<<endl;

    for(int i=0;i<sz(ans);i++)
       cout<<ans[i].X<<"  "<<ans[i].Y<<endl;
    assert(tp==save);
     */
    return ans;
}


int in[110];

vector< pair<int,int> >st[110];

int edge[110][2];

int right_partner[3000],left_partner[3000];

bool done[3000];

bool kuhn( int v)
{
  if( done[v])  return false;

  done[v]=true;

  for(int i=0;i<sz(graf[v]);i++)
  {
      int to= graf[v][i];

      if( left_partner[to]==-1 )
      {
          left_partner[to]=v;
          right_partner[v]=to;
          return true;
      }
  }


  for(int i=0;i<sz(graf[v]);i++)
  {
      int to= graf[v][i];

      if( kuhn(left_partner[to] ) )
      {
          left_partner[to]=v;
          right_partner[v]=to;
          return true;
      }
  }

  return false;

}

int main()
{

 id=1;

 int N,m;

 cin>>N>>m;


 vector<int> left;

 for(int i=1;i<=N;i++)
    {
        cin>>in[i];

        st[i]=prime( (ll)in[i]);

        if( i&1)
        {
            for(int j=0; j<sz( st[i] ); j++)
                 left.pb( st[i][j].Y );
        }
    }

  int a,b,x,y;

  for(int i=1;i<=m;i++)
     {
          cin>>x>>y;

          if(x&1)
             {a=x;
              b=y;
             }
          else
          {
              a=y;
              b=x;
          }


          vector< pii> A = st[a] , B = st[b];

          for(int i=0;i<sz(A);i++)
             for(int j=0;j<sz(B);j++)
                if( A[i].X == B[j].X)
                    {
                        graf[ A[i].Y ].pb( B[j].Y );
                        graf[ B[j].Y ].pb( A[i].Y );
                    }
     }

     fill( right_partner,-1);
     fill( left_partner ,-1);


      bool mila=true;


     do
      {

            mila=false;

            fill(done ,0);

            for(int i=0;i<sz(left);i++)
            {
                int curr =left[i];

                if( (!done[curr]) && ( right_partner[curr]==-1) )
                     mila = mila || kuhn( curr);
            }
      }
      while( mila);

      int ans=0;

     /* cout<<" left content is "<<endl;

      for(int i=0;i<sz(left);i++)
        cout<<left[i]<<endl;



      cout<<"Prinint mtaxche done ";

      */

      for(int i=0;i<sz(left);i++)
         if( right_partner[ left[i] ]!=-1)
            {
                 ans++;

                 //cout<<left[i]<<"  "<<right_partner[ left[i] ]<<endl;
            }



      cout<<ans<<endl;

  return 0;


}
