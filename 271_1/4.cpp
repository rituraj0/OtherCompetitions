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
#define fi freopen("input.tXt","r",stdin)
#define fo freopen("output.tXt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

#define pii pair<ll,ll>

pii rot( pii in)
{
    int X=in.X;
    int Y=in.Y;

    if( X>=0 && Y >=0)
         return mp(-X,Y);

    if( X <=0 && Y >=0 )
         return mp(X,-Y);

    if( X<=0 && Y<=0 )
         return mp(-X,Y);

     return mp(X,-Y);
}


ll leng( pii a , pii b)
{
    return (a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y);
}

pii add( pii a, pii b)
{
    return mp( a.X+b.X , a.Y+b.Y );
}

pii sub ( pii a, pii b)
{
    return mp( a.X-b.X , a.Y - b.Y );
}

bool cool(  vector<pii> curr)// check if a squre is there
 {
      init=mp(1<<20,1<<20);

      int id=-1;

      assert( sz(in)==4);

     vector<ll> D;

     for(int i=0;i<=2;i++)
        D.pb( leng(curr[i],curr[i+1] ) );

        sort(D.begin(),D.end());


        if(D[0]==0)
             return false;


             ll hy=leng( init , curr[1] );

            // print(hy);

             if( hy!=2LL*D[0]) // for 90*
                  return false;


           return (D[0]==D[3]);
 }

void trace( vector<pii> in)
{
    for(int i=0;i<sz(in);i++)
        cout<<in[i].X<<"  "<<in[i].Y<<endl;

    cout<<"\n\n\n";
}

int solve()
{

 vector<pii> curr(4),home(4),rel(4),save;

 for(int i=0;i<4;i++)
      { cin>>curr[i].X>>curr[i].Y>>home[i].X>>home[i].Y;
         rel[i]=sub( curr[i] , home[i] );
      }

      save=rel;

  int ans=-1;


  int a=0,b=0,c=0,d=0;


  for( a=0 ; a<5; a++ , rel[0]=rot(rel[0]) )
  {

     for( b=0; b<5; b++,  rel[1]=rot(rel[1]) )
     {
           if( b==0)
              rel[1]=save[1];

         for( c=0  ; c<5; c++ , rel[2]=rot(rel[2]) )
         {
               if(c==0)
                  rel[2]=save[2];

              for(d=0 ; d<4; d++ , rel[3]=rot(rel[3]) )
              {
                    if(d==0)
                         rel[3]=save[3];

                    vector<pii> tp;

                    for(int i=0;i<4;i++)
                         tp.pb( add(rel[i],home[i] ) );

                    if( cool(tp) )
                    {
                        if(ans==-1)
                             ans=a+b+c+d;
                        else
                            ans=min( ans , a+b+c+d);
                    }
            }
         }
     }
  }

 return ans;

}

int main()
{
 ios_base::sync_with_stdio(0);


 int n;

 cin>>n;


 for(int i=0;i<n;i++)
    cout<<solve()<<endl;

 return 0;

}
