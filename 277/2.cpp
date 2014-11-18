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

 int in[150][150];
 int ans[150][150];
  bool row[150],col[150];
  int temp[150][150];

int main()
{
 ios_base::sync_with_stdio(0);



 fill(row,0);
 fill(col,0);

 int n,m;

 cin>>n>>m;

 for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
        cin>>in[i][j];

 //marking all zeros to
 for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
        if( in[i][j]==0)
        {
            row[i]=col[j]=true;
        }

   //check for invalid condn

   for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if( in[i][j]==1)
        {
           if( row[i] && col[j])
           {
               cout<<"NO\n";
               return 0;
           }
        }


    bool tr[150],tc[150]; fill(tr,0); fill(tc,0);

   for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
       if( (row[i]==false) && (col[j] ==false) )
       {
            ans[i][j]=1;
            tr[i]=tc[j]=true;
       }
       else
       {
           ans[i][j]=0;
       }

       //Now check if anwer is correct
       // by building a

       fill(temp,0);

       for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
         if( tr[i] || tc[j] )
           temp[i][j]=1;

       //now check if both in & temp match

       for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
          if( temp[i][j] != in[i][j])
            {
               cout<<"NO\n";
               return 0;
            }


    cout<<"YES\n";

   for(int i=1;i<=n;i++,cout<<endl)
     for(int j=1;j<=m;j++)
        cout<<ans[i][j]<<" ";



 return 0;

}
