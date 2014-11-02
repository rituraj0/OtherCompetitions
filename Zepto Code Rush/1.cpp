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

int n,col[2005],ht[2005],add[2005];
bool used[2005];

int solve( int turn , int cp)
{
    int ans=-1;
    int id=-1;

    for(int i=1;i<=n;i++)
        if(!used[i])
         if( col[i]==turn)
           if( ht[i]<=cp)
           {
               if( ans < add[i])
               {
                   ans=add[i];
                   id=i;
               }
           }

         if(id!=-1)
            used[id]=true;

//           cout<<turn<<"  "<<cp<<"  "<<id<<endl;

      return id;

}


int init( int st , int pw)
{
    fill(used,0);
    int ans=0;

   while(1)
   {
        int id=solve(st,pw);
        if(id==-1) break;
        pw+=add[id];
         ans++;

        id=solve(1-st,pw);
        if(id==-1) break;
        pw+=add[id];
        ans++;
   }

   return ans;
}


int main()
{
 ios_base::sync_with_stdio(0);
 int x;

 cin>>n>>x;

 for(int i=1;i<=n;i++)
 {
     cin>>col[i]>>ht[i]>>add[i];
 }

// init(0,x);

 int ans=max( init(0,x) , init(1,x) );

 cout<<ans<<endl;


 return 0;

}
