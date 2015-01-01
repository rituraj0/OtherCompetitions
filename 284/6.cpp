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

const int  maxn = 200010;

int tree[maxn*2][62],in[maxn];

//tree[x][i].. time taken to cross this section at (a,b) if we start at  time (st s%60 == i)

void merge( int root)
{
    int lc=2*root;
    int rc=lc+1;

    for(int i=0;i<60;i++)
    {
        int start_right = ( i + tree[lc][i] )%60;
        int total = tree[lc][i] + tree[rc][start_right];

        tree[root][i]=total;
    }
}

void build( int root , int l , int r)
{
    if( l == r)
    {
        for(int i=0; i<60; i++)
             if( i% in[l]==0)
              tree[root][i]=2;
             else
              tree[root][i]=1;

        return ;
    }

    int mid=(l+r)/2;
    build( 2*root , l,  mid) ;
    build( 2*root + 1 , mid+1 , r );

    merge(root);
}


void update( int root , int l , int r ,  int index , int val)
{
    if( l == r)
    {
        in[l]=val;

        for(int i=0; i<60; i++)
             if( i% in[l]==0)
              tree[root][i]=2;
             else
              tree[root][i]=1;

        return ;
    }

    int mid=(l+r)/2;

    if( index <= mid  )
      update( 2*root , l , mid , index , val) ;
    else
      update( 2*root + 1 , mid+1 , r , index  , val );

     merge(root);
}


int query( int root , int x, int y , int l  , int r  , int tm)
{
     if( (x==l) && (y==r) )
     {
        return tree[root][tm];
     }

     int mid=(l+r)/2;

     if( y <= mid)
         return query(2*root , x , y , l , mid , tm );
     else if( x > mid )
         return query(2*root + 1 , x , y ,  mid +1, r , tm );
     else
     {
        int lt = query(2*root , x , mid , l , mid , tm);

        return  lt + query( 2*root + 1 , mid+1 , y , mid +1 , r , (lt + tm )%60 );
     }
}

int main()
{
    ios_base::sync_with_stdio(0);


    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
        cin>>in[i];

    int Q;

    cin>>Q;

    int a,b;
    char op;

    build(1,1,N);

    //int root , int x, int y , int l  , int r  , int tm)

    for(int i=1;i<=Q;i++)
    {
        cin>>op>>a>>b;

        if(op == 'C')
         update( 1 , 1 , N, a ,b  );
        else
         cout<<query(1 ,a ,b-1, 1,N ,0)<<endl;;
    }

    return 0;
}
