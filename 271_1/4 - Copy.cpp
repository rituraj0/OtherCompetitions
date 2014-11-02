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

pii init;

bool comp ( pii a, pii b)
{
    if (a.X - init.X >= 0 && b.X - init.X < 0)
        return true;
    if (a.X - init.X < 0 && b.X - init.X >= 0)
        return false;
    if (a.X - init.X == 0 && b.X - init.X == 0) {
        if (a.Y - init.Y >= 0 || b.Y - init.Y >= 0)
            return a.Y > b.Y;
        return b.Y > a.Y;
    }

    ll det = (a.X - init.X) * (b.Y - init.Y) - (b.X - init.X) * (a.Y - init.Y);
    if (det < 0)
        return true;
    if (det > 0)
        return false;

    ll d1 = (a.X - init.X) * (a.X - init.X) + (a.Y - init.Y) * (a.Y - init.Y);
    ll d2 = (b.X - init.X) * (b.X - init.X) + (b.Y - init.Y) * (b.Y - init.Y);
    return d1 > d2;
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

bool cool(  vector<pii> in)// check if a squre is there
 {
      init=mp(1<<20,1<<20);

      int id=-1;

      assert( sz(in)==4);

      cout<<"Input is";

      for(int i=0;i<4;i++)
        cout<<in[i].X<<"  "<<in[i].Y<<endl;

        for(int i=0;i<sz(in);i++)
        {
             if( in[i].Y < init.Y)
               { init=in[i];
                  id=i;
               }
            else if( (in[i].Y==init.Y) && (in[i].X < init.X) )
                 { init=in[i];
                   id=i;
                 }
        }

     vector<pii> curr;

     for(int i=0;i<sz(in);i++)
          if(i!=id)
            {
                curr.pb( in[i] );
            }

     sort( curr.begin(),curr.end(),comp);


   cout<<"center is "<<init.X<<"  "<<init.Y<<endl;
        for(int i=0;i<sz(curr);i++)
        cout<<curr[i].X<<"  "<<curr[i].Y<<endl;

     //check for 90*

//     ll dx1 =   (in[0].X-init.X),   dy1=( in[0].Y - init.Y );
//
//     ll dx2 =   ( in[2].X - init.X) , dy2=( in[2].Y - init.Y );
//
//
//     if( dy1*dy2 + dx1*dx2 !=0 )
//         return false;


         cout<<"Angle PAssed\n";

     cout<<init.X<<"  "<<init.Y<<endl;

     curr.pb( init );

     for(int i=0;i<sz(curr);i++)
        cout<<curr[i].X<<"  "<<curr[i].Y<<endl;

     //all same len

     vector<ll> D;

     for(int i=0;i<=2;i++)
        D.pb( leng(curr[i],curr[i+1] ) );

        D.pb( leng(init,curr[0]));

        sort(D.begin(),D.end());


        for(int i=0;i<sz(D);i++)
             cout<<D[i]<<" -  ";


             //.all sam elng

             ll hy=leng( init , curr[1] );

             print(hy);

             if( hy!=2LL*D[0]) // for 90*
                  return false;


           return (D[0]==D[3]);
 }


int solve()
{

 vector<pii> curr(4),home(4),rel(4);

 for(int i=0;i<4;i++)
      { cin>>curr[i].X>>curr[i].Y>>home[i].X>>home[i].Y;
         rel[i]=sub( curr[i] , home[i] );
      }

  int ans=-1;


  int a=0,b=0,c=0,d=0;

  cout<<rel[1].X<<"  "<<rel[1].Y<<endl;

   rel[1]=rot(rel[1]);

     cout<<rel[1].X<<"  "<<rel[1].Y<<endl;

//  for(int a=0; a<5; a++ , rel[0]=rot(rel[0]) )
//     for(int b=0; b<4; b++,  rel[1]=rot(rel[1]) )
//        for(int c=0; c<4; c++ , rel[2]=rot(rel[2]) )
//          for(int d=0; d<4; d++ , rel[3]=rot(rel[3]) )



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




       return ans;

}

int main()
{
 ios_base::sync_with_stdio(0);

 vector<pii> tp;
 tp.pb( mp(0,1));tp.pb( mp(1,1));
 tp.pb( mp(1,0));

 tp.pb( mp(0,1));


 cout<<cool(tp)<<endl;

 pii h=mp(1,1);

 for(int i=0;i<6;i++)
 {
     cout<<h.X<<"  "<<h.Y<<endl;

     h=rot(h);
 }

 int n;

 cin>>n;


 for(int i=0;i<n;i++)
    cout<<solve()<<endl;

 return 0;

}
