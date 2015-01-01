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


#define maxn 1000

string can[maxn];
int n;

int baap[maxn];

int root( int x)
{
    if( baap[x]==x)
         return x;

    return baap[x] = root( baap[x] );
}

void join( int x , int y)
{
    int xp= root(x);
    int yp=root(y);

    if( xp==yp )
         return;

    if( rand() &1 )
         baap[xp]=yp;
    else
          baap[yp]=xp;
}


int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n;

 vector<int> in;

 for(int i=0;i<n;i++)
     {
         int x;
         cin>>x;
         in.pb(x);
     }


  for(int i=0;i<n;i++)
         baap[i]=i;

 for(int i=0;i<n;i++)
    {

      cin>>can[i];

       for(int j=0;j<n;j++)
         if( can[i][j]=='1')
           join( i ,j);
    }

    vector<int> save= in;

    sort( save.bg, save.end());

    bool fixed[maxn];

    fill(fixed, 0);

    vector<int> ans=in;

    for(int id=0;id<n;id++)
    {
        int curr = save[id];

        int cid=-1;

        for(int i=0;i<n;i++)
             if( ans[i] == curr)
                  cid=i;

        assert( cid != -1);

        vector<int> go;//can go here , can be empty

        for(int i=0;i<n;i++)
             if( can[cid][i] =='1' )
                go.pb( i);

        sort( go.begin() , go.end());

        int nx= -1;


        for(int i=0;i<sz(go);i++)
             if( !fixed[ go[i] ])
                if( go[i] <= cid)
             {
                nx=go[i];
                break;
            }

          cout<<curr<<"  "<<nx<<endl;

       assert( nx !=-1 ) ;

        if( nx == -1)
            continue;


        swap( ans[nx] , ans[cid] );

        fixed[nx] = true;

    cout<<"curr is "<<curr<<endl;
    for(int i=0;i<sz(ans);i++)
        cout<<ans[i]<<"  ";


        cout<<"\n\n";
    }


    for(int i=0;i<sz(ans);i++)
        cout<<ans[i]<<"  ";




 return 0;

}
