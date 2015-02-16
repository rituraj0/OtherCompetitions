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


#defin  maxn 500005

bool tree[4*maxn];
int lazy[4*maxn];

void build_node(int node )
{
    tree[node] = ( tree[2*node] || tree[2*node +1 ] );
}

void update_node( int node ,int val )//val can be 0 or 1
{
    if( val !=-1 )
    {
        tree[node]=lazy[node]=val;
    }
}


void propogate( int node )
{
    update_node(2*node, lazy[node);
    update_node(2*node +1 , lazy[node] );
    lazy[node]=-1;
}

void build( int node, int l, int r)
{
    //no need , initayy all zero ,
}

//for drain  val =0 , a ==b
//for fill , val 1  a= start[curr] b= fini[curr];

void update( int node, int l ,int r, int a, int b, int val)
{
    if( (l>b) || (r < a) )
         return;

    if( (l<=a) && (b<=r) )
    {
        update_node(node,val);
        return;
    }

    propogate(node);

    int mid = (l+r)/2;

    update(2*node, l ,mid , a, b, val );
    update(2*node +1 , mid + 1, r , a, b, val );

    build_node(node);
}


bool query ( int node, int  l ,int  r, int id)
{
    if( (r<id) || ( l > id ) )
         return 0;

    if( l==r )
    {
        assert(l==id);
        return tree[node];
    }

    propogate(node);

    int mid = (l+r)/2;

    bool a = query( 2*node, l , mid , id );
    bool b = query( 2* node , mid +1 , r, id );


   // build_node(node);
   // not reuired
   // TODO : check if any regression  d

    return (a|| b);
}



//************   DFS section **********

vector<int> graf[maxn];
int ID[maxn];
int cid=0;
int start[maxn],fini[maxn];
int N;

void dfs( int curr , int par)
{
     if( ID[curr]!=-1 )
         return;

     ID[curr]=cid++;

     for(int i=0;i<sz(graf[curr]);i++)
     {
         int nx = graf[curr][i];

         if( nx != par)
            dfs(nx , curr);
     }

     start[curr]=ID[curr];
     fini[curr]=cid-1;
}


void build_dfs()
{
    fill( ID,-1);
    fill( start,-1);
    fill( fini,-1);

    int a,b;

    for(int i=0;i<N-1;i++)
    {
        cin>>a>>b;
        a--;b--;
        graf[a].pb(b);
        graf[b].pb(a);
    }

    dfs(0,-1);

}
//************   DFS section **********

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>N:

  build_dfs();

  fill( tree , 0 );
  fill( lazy , -1 );

  int Q,a,b;

  cin>>Q

  for(int i=0;i<q;i++)
  {
      cin>>a>>b;

       b--;

       if( a== 1)//file thi sand its children
       {
            int lo = start[b], hi = fini[b];

            update(1 , 0 , n-1, lo , hi , 1);
       }
       else if( a == 1 )//empty it and its ancestors
       {
           int lo = b, hi = b;
           update( 1, 0 , n-1 , lo ,hi , 0);
       }
       else
       {
           cout<<query(1,0,n-1,b)<<endl;
       }
  }


 return 0;

}
