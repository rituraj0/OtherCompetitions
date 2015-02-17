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

#define maxn 5005

int  bit[2*maxn];
int in[maxn];
int small[maxn][maxn];//(x,i)smaller than x in range [1,i) index including
//int big[maxn][maxn];

void update( int id, int val)
{
    while( id < 2*maxn)
    {
        bit[id]+=val;
        id+=id&(-id);
    }
}

int read( int id)
{
    int ans =0;

    while( id > 0)
    {
        ans+=bit[id];
        id-=id&(-id);
    }

    return ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 fill(bit,0);
 fill( small,0);

 int n,a;

 cin>>n;

 for(int i=1;i<=n;i++)
 {
     cin>>a;
     a++;
     update(a,1);

     a=10;

     for(int j=1;j<=n;j++)
        small[j][i] = read( j);
 }

 for(int i=1;i<=n;i++,cout<<endl)
    for(int j=1;j<=n;j++)
     cout<<small[i][j]<<" ";

 return 0;

}
