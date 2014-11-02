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


vector<int> graf[1005];

int  done[1005];

int cn;

int pos[5][1005];

int dfs(int in)
{
    if( done[in]!=-1) return done[in];

    done[in]=0;

    for(int i=0;i<graf[in].sz;i++)
    {
        int u=graf[in][i];
        done[in]=max(done[in],dfs(u) );
    }

    done[in]++;

    return done[in];
}

int main()
{
    int n,k;

    fi;fo;

   cout<<500000<<endl;

   for(int i=1;i<500000;i++)
     cout<<"1"<<" ";

   cout<<"1";

     cout<<endl;



    return 0;

}
