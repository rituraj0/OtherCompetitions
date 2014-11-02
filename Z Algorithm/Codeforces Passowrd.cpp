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

int z[1<<20];
string in;
int n;

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>in;

 n=in.sz;

 z[0]=n;

  int l=0,r=0;

 for(int i=1;i<n;i++)
 {
       if( r < i)
       {
            l=r=i;

            while( (r<n) && ( in[r-l]==in[r]) )
                 r++;

            z[i]=r-l;
            r--;
            continue;
       }

       int b=r-i+1;
       int k=i-l;

       if( z[k]< b)
         z[i]=z[k];
       else
       {
            l=i;

            while( (r<n) && ( in[r-l]==in[r]) )
                 r++;

            z[i]=r-l;
            r--;
       }
 }


 int ans=0;

 int mz=0;

 for(int i=1;i<n;i++)
 {
        if( (z[i]==n-i)&&(n-i<=mz) )
           {
               ans=n-i;
               break;
           }

           mz=max(mz,z[i]);
 }

 if(ans==0)
    cout<<"Just a legend\n";
 else
    cout<<in.substr(0,ans)<<endl;

 return 0;

}
