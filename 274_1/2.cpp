#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
#define bg begin()
#define en end()
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */




int main()
{
 ios_base::sync_with_stdio(0);

 map<ll,bool> mapa;

  ll in[200009];

 ll n,len,x,y;


 cin>>n>>len>>x>>y;

 for(int i=0;i<n;i++)
 {
     cin>>in[i];
     mapa[ in[i] ]=true;
 }

 bool x_mila=false,y_mila=false;

 for(int i=0;i<n;i++)
 {
     if( mapa[ in[i]-x ]==true)
        x_mila=true;

     if( mapa[ in[i]-y ]==true)
        y_mila=true;
 }

 if( x_mila && y_mila)
 {
     cout<<"0"<<endl;
     return 0;
 }

 if( x_mila || y_mila )
 {
    cout<<"1"<<endl;

    if(!x_mila)
        cout<<x<<endl;
    else
        cout<<y<<endl;

        return 0;
 }

      for(int i=0;i<n;i++)
         if( mapa[ in[i]-x-y]==true)
            {
                cout<<"1"<<endl;

                cout<<in[i]-x<<endl;

                return 0;
            }

 cout<<"2"<<endl;

 cout<<x<<" "<<y<<endl;




 return 0;

}
