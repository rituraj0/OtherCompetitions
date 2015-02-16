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


using namespace std;

map<int,int> ID;

vector< pair<int,int> > in;

int n;

int right ( int id )
{
    int lo = id , hi = n;

    while( lo < hi )//Won work 12 17 , serch for 15 ,i
    {
        int mid = (lo+hi+1)/2;

        if( in[mid].X <= in[id].X + in[id].Y -1)
            lo=mid;
        else
            hi=mid-1;
    }

    return lo;
}

int find_count( int id ,int rg)
{
    int lo = id, hi = n;

    while( lo < hi )
    {
        int mid = (lo+hi+1)/2;

        if( in[mid].X <= rg)
            lo = mid;
        else
            hi = mid - 1;
    }

    return (lo-id+1);
}

#define maxn 100009
int tree[4*maxn];

void update( int node , int  l ,int r, int id ,int val)//update at [id[ = val
{
    if( (l>id) || (r<id))
         return;

    if( l==r )
    {
        if( l==id)
            tree[node]=val;

        return;
    }

    int mid = (l+r)/2;

    update(2*node , l ,mid , id, val);
    update(2*node +1 , mid+1, r, id, val);

    tree[node]= max( tree[2*node] , tree[2*node+1] );
}


int query( int  node , int l ,int r, int a, int b)//find max between [a,b];
{
     if( (l>b)|| (r<a))
         return -(1<<30); // can be negative x cordinates , so returning 0 wont work

     if( (a<=l) && (r<=b) )
         return tree[node];

     int mid = (l+r)/2;

     int ls = query( 2*node , l , mid , a, b );
     int rs = query(2 *node +1 , mid+1, r, a, b);

     return max(ls,rs);
}

int ans[maxn];

int main()
{
    ios_base::sync_with_stdio(0);

    cin>>n;

    int a,b;

    for(int i=0;i<n;i++)
    {
        cin>>a>>b;

        ID[a]=i;

        in.pb( mp(a,b) );
    }

    sort( in.begin() , in.end() );

    in.pb(  mp(1<<30,0) );

    //cout<<in[n].X<<endl;

    fill( tree, -63);

   // cout<<tree[0]<<endl;

    for(int i=n-1;i>=0;i--)
    {
        int rt = right(i);

        int  tp = query(1,0,n-1,i,rt);//find max between [i,rt];

        tp = max( tp , in[i].X + in[i].Y -1 ); //find "range" ,

        int cont = find_count( i, tp );

        ans[ ID[ in[i].X ] ] = cont ;

        update( 1 , 0, n-1, i , tp  );

        int xx=10;;

        //cout<<xx<<endl;
    }


    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";

    return 0;
}
