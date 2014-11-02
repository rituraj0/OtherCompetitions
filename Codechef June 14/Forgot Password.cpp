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


char mapa[200],x,y;
int n;
string in;

void solve()
{

    fill(mapa,0);

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        mapa[x]=y;
    }

    cin>>in;

    bool fr=false;

     for(int i=0;i<in.sz;i++)
          {

            if( mapa[ in[i] ]!=0)
            in[i]=mapa[ in[i] ];

            if( in[i]=='.')
                 fr=true;
          }

     int l=0,r=( (int)in.sz )-1;

      if( fr)
      {
         while(in[r]=='0')
         r--;

         if( in[r]=='.')
         r--;
      }

     while( in[l]=='0')
         l++;

/*
//      if( in[l]=='.')
//         l++;

         if(l==r)
         {
                 cout<<in[l]<<endl;
         }
        else
            */

        if( l-1==r)
        {
            cout<<"0\n";
        }
        else
        {
              for(int i=l;i<=r;i++)
               cout<<in[i];

               cout<<endl;
        }

}

int main()
{

 int test;

 cin>>test;

 while(test--)
 {
     solve();
 }

 return 0;

}
