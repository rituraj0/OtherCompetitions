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

vector<int> graf[2005];

int main()
{
 ios_base::sync_with_stdio(0);

 int n,x;

 cin>>n;

 for(int i=1;i<=n;i++)
 {
     cin>>x;
     graf[x].pb(i);
 }

 bool mila=false;
 ll cn=1;

 int mx=0;
 int id=0;

 vector<int> tw;

 for(int i=1;i<=2000;i++)
 {
     if( sz(graf[i]) ==0 )
         continue;
     cn=cn*sz(graf[i]);

     if( sz(graf[i])==2 )
     {
         tw.pb( i);
     }

     sort( graf[i].bg , graf[i].en );

     if( mx < sz(graf[i]) )
       { mx=sz(graf[i]);
          id=i;
       }

     if(cn>=3)
     {
         mila=true;
     }
 }

 if(!mila)
 {
     cout<<"NO"<<endl;
     return 0;
 }

     cout<<"YES"<<endl;

 if( mx >=3 )
 {
        for(int k=1;k<=3;k++,cout<<endl)
        {
             for(int i=1;i<=2000;i++)
                 for(int j=0;j<sz( graf[i] );j++ )
                   cout<<graf[i][j]<<" ";

             next_permutation( graf[id].begin() , graf[id].end() );
        }

        return 0;
 }

//cout<<" two wla section"<<endl;


 for(int k=1;k<=3;k++,cout<<endl)
 {
            for(int i=1;i<=2000;i++)
                 for(int j=0;j<sz( graf[i] );j++ )
                   cout<<graf[i][j]<<" ";

            if(k==1)
              next_permutation( graf[ tw[0] ].begin() , graf[ tw[0] ].end() );
            else
                next_permutation( graf[ tw[1] ].begin() , graf[ tw[1] ].end() );
 }



 return 0;

}
