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

#define  maxn 10009

int boss[maxn];
int best[maxn];

int root(  int x)
{
     if( boss[x]==x) return x;
     return boss[x]=root( boss[x]);
}

int join( int x , int y)
{
    int xp=root(x) , yp=root(y);

    if(xp==yp) return 0;

    if( best[xp] > best[yp] )
         boss[yp]=xp;
    else if( best[xp] < best[yp])
         boss[xp]=yp;

    return true;
}

void solve()
{
    int n,Q;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        boss[i]=i;
        scanf("%d",&best[i]);
    }

    scanf("%d",&Q);

    int op,a,b;

    for(int q=1;q<=Q;q++)
    {
        scanf("%d",&op);

        if(op==0)
        {
            scanf("%d",&a); scanf("%d",&b);

            if(!join(a,b))
                printf("Invalid query!\n");
        }
        else
        {
            scanf("%d",&a);

            printf("%d\n",root(a));
        }
    }

}

int main()
{
   int test;

   scanf("%d",&test);

   while(test--)
   {
       solve();
   }

 return 0;

}
