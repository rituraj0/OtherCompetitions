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


int in[2005][2005];
int n;

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n;

 for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
 {
     cin>>in[i][j];
 }


 for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
 {
       if(i==j)
       {
            if( in[i][j]!=0)
            {
                cout<<"NO"<<endl;
                return 0;
            }
       }
       else
       {
            if( in[i][j]!=in[j][i])
            {
                cout<<"NO"<<endl;
                return 0;
            }
       }
 }

 cout<<"YES"<<endl;

 return 0;

}
