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

bool solve()
{
   string in;

   cin>>in;

   int n=sz(in);

   int req=(n-1)/2;

   //save left and try to match

   bool lf=true;
   int i=0,j=n-1;
   bool del=false;

    while( i < req)
    {
        if( in[i]==in[j])
        {
            i++;
            j--;
        }
        else
        {
            if( del)
            {
                lf=false;
                break;
            }
           else//delete  in[j]
           {
                j--;
                del=true;
           }
        }
    }


   // print(lf);

    //save right part

    bool rt=true;
    i=0,j=n-1;
    del=false;
    int dn=0;

    while( dn < req)
    {
        if( in[i]==in[j])
        {
            i++;
            j--;
            dn++;
        }
        else
        {
            if( del)
            {
                rt=false;
                break;
            }
           else//delete  in[i]
           {
                i++;
                del=true;
           }
        }
    }

   // print(rt);

    if( lf || rt)
         return true;

    return false;

}

int main()
{
 ios_base::sync_with_stdio(0);
   int test;

   cin>>test;

   while(test--)
   {
       if( solve() )
        cout<<"YES"<<endl;
       else
        cout<<"NO"<<endl;
   }

   return 0;
}
