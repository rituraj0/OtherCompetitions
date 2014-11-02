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



 int n;
 string in[200];

 map<char,int> mapa;

 bool used[8][8];
 int cont[8][8];


int main()
{
 ios_base::sync_with_stdio(0);


 mapa['R']=0;
 mapa['G']=1;
 mapa['B']=2;
 mapa['Y']=3;
 mapa['W']=4;

  cin>>n;

  fill(used,0);

  for(int i=0;i<n;i++)
    { cin>>in[i];

     int a=mapa[ in[i][0] ],b=in[i][1]-'0';
     used[a][b]=true;
    }



  int ans=10;

  for(int a=0;a<(1<<5);a++)//num
     for(int b=0;b<(1<<5);b++)//col
     {
        fill(cont,0);

         for(int i=0;i<5;i++)
         {
              int x=5;

                if( a&(1<<i))
                     x=i;

                  for(int j=0;j<5;j++)
                  {

                      if(!used[i][j]) continue;

                      int y=5;

                       if( b&(1<<j))
                         y=j;

                       cont[x][y]++;
                  }
         }

        bool cool=true;

        for(int i=0;i<=5;i++)
         for(int j=0;j<=5;j++)
          if( cont[i][j] > 1)
            cool=false;


        if( cool)
            ans=min( ans , __builtin_popcount(a) + __builtin_popcount(b) );

    }


    cout<<ans<<endl;


 return 0;

}
