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

pair<int,int> nodes[maxn];
ll sum[maxn];
int baap[maxn];


int n,ed,road, reg;


set< pair<ll,int> > st;// (sm , node )


void update( int a, int b)//delete a from se, and insert curr[sum] from b
{
    st.erase( mp(sum[a],a ) );

    if(a!=b)// can be the case when we join nodes in same components
    st.erase( mp(sum[b],b ) );

    st.insert( mp(sum[b],b ) );

    if(a!=b)
        nodes[a]=mp(a,b);
}

int root( int u)
{
    if( baap[u]==u)
         return u;

    return baap[u]= root( baap[u] );

}

void join( int x, int y)
{
    int xp = root(x) , yp=root(y);

    if( xp == yp )
    {
        sum[xp]+=1000;//if in same comp , add 1000
        update(xp,xp);
    }
    else
    {
        ll a = sum[xp];
        ll b = sum[yp];
        ll c = min( (ll)(1e9) , a+b+1  );

        if( rand()&1)
        {
            baap[xp]=yp;
            sum[yp]+=sum[xp]+c;
            update(xp,yp);//delete xp from set ,
        }
        else
        {
            baap[yp]=xp;
            sum[xp]+=sum[yp]+c;
            update(yp,xp);//delete yp from set

        }
    }
}

void pre_join( int x, int y , ll len)
{
    int xp = root(x) , yp=root(y);

    if( xp == yp )
    {
        sum[xp]+=len;
    }
    else
    {
        if( rand()&1)
        {
            baap[xp]=yp;
            sum[yp]+=len;
        }
        else
        {
            baap[yp]=xp;
            sum[xp]+=len;
        }
    }
}

vector< pair<int,int> > ans;

int main()
{
 ios_base::sync_with_stdio(0);

 fill( sum , 0);

 cin>>n>>ed>>road>>reg;

 for(int i=1;i<=n;i++)
 {
     baap[i]=i;
     nodes[i]=mp(i,-1);
     st.insert( mp(0LL,i) );
 }

 int a,b;
 ll len;

 for(int i = 1; i<=ed; i++)
 {
     cin>>a>>b>>len;

     pre_join(a,b,len);
 }

 int comp =0;

 for(int i=1;i<=n;i++)
     if( root(i)==i)
      comp++;

 if( comp < reg)//can not form reg regions
 {
     cout<<"NO\n";
     return 0;
 }

 int ex =  comp - req;

 int done = 0;

 for(int i=0;i<ex;i++)//join this time
 {
    if( sz(st) < 2 )
        break; //can take two differnt array
    int a =  (*st.begin()).Y;//get node from 2 compnents
               st.erase( st.begin() );

    int b =  (*st.begin()).Y;//get node from
               st.erase( st.begin() );

      ans.pb( mp(a,b));

      done++;
 }

 //find any comp where number of nodes is  grater than or equal to 2
 int id = -1;

 for(int i=1;i<=n;i++)
     if( root(i) == i)
    {
        if( nodes[i].Y!=-1)
             id=i;
    }

 if( id !=-1 )
 {

   while( done < road)
   {
       ans.pb( nodes[id] );
   }
 }

if( sz(ans)!=road )
{
    cout<<"NO\n";
    return 0;
}

cout<<"YES\n";

for(int i=0;i<road;i++)
    cout<<ans[i].X<<" "<<ans[i].Y<<endl;


 return 0;

}
