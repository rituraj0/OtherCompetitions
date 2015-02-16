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


struct node
{
    bool here;

    int aage[3];

    node()
    {
        here=false;
        fill(aage,-1);
    }

};

int node_count=0;


node tree[1<<22];//maixmum number of char

string in;

void insertt ( int curr , int pos)
{
    if( pos==sz(in) )
    {
        tree[curr].here=true;
        return;
    }

    int id = in[pos]-'a';

    if( tree[curr].aage[id] ==-1)
    {
        tree[curr].aage[id] = ++node_count;
    }

    //cout<<curr<<" "<<tree[curr].aage[id]<< " "<<in[pos]<<endl;

    insertt(tree[curr].aage[id] ,pos+1);
}

bool mila=false;//set to false in beginning

void searchh( int curr , int pos , bool taken)
{
    if( curr==-1)
         return;

    if( pos==sz(in) )
    {
        if( taken)
              if( tree[curr].here)
                   {
                       mila=true;
                         return;
                   }

        return;
    }

    int id = in[pos]-'a';

    //go in rigth direct

    searchh( tree[curr].aage[id],pos+1,taken);

    if( !taken)
    {
        for(int i=0;i<3;i++)
              if( id!=i)
                 searchh(tree[curr].aage[i],pos+1, true );

    }

}

int main()
{
 ios_base::sync_with_stdio(0);
//
// in= "abcab";
//
// insertt(0,0);
//
// cout<<node_count<<endl;
//
// mila= false;
//
// searchh(0,0,0);
//
// cout<<mila<<endl;
//
//// cout<<
//
// in = "aacab";
//
//  mila= false;
//
// searchh(0,0,0);
//
// cout<<mila<<endl;
//
// //
//
//  in = "aaab";
//
//  mila= false;
//
//  searchh(0,0,0);
//
// cout<<mila<<endl;
//
// //
//
//   in = "aabcbcbab";
//
//  mila= false;
//
//  searchh(0,0,0);
//
//  cout<<mila<<endl;

int n,Q;

 cin>>n>>Q;

 for(int i=0;i<n;i++)
 {
     cin>>in;
     insertt(0,0);
 }

 for(int i=0;i<Q;i++)
 {
     cin>>in;

     mila=false;

     searchh(0,0,0);

     if( mila)
        cout<<"YES\n";
     else
        cout<<"NO\n";
 }






 return 0;

}
