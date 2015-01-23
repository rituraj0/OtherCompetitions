#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((long long)(s.size()))
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define prlong long(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

#define maxn 200009
#define pii pair<long long,long long>


map<string , long long > ID;
long long id_cont = 0;

vector<string>  input;

void process( string &in)
{
  transform(in.begin(), in.end(), in.begin(), ::tolower);

  if( ID.count(in)==0)
  {
      input.pb(in);
      ID[in]=id_cont++;
  }
}

//cont of word in eassy
long long cont[maxn];


// size and numver of cont
pii contpp[maxn];

void count_rlen()
{
    for(long long i=0;i<sz(input);i++)
    {
       long long rc=0;

       for(long long j=0;j<sz(input[i]);j++)
         if( input[i][j]=='r')
           rc++;

       contpp[i]=mp(rc,sz(input[i]));
    }

}


//#start r=tarjan algo

vector<long long> graf[maxn];

long long index[maxn];
long long low[maxn];
bool instack[maxn];

long long inscc[maxn];
long long ts=1;

long long sccid=1;

stack<long long> st;

pii mini[maxn];

void tarjan( long long u)
{
    if( index[u] )
        return;

    index[u]=low[u]=ts;
    ts++;

    st.push(u);
    instack[u]=true;

    for(long long i=0;i<sz(graf[u]);i++)
    {
        long long  ch = graf[u][i];

         if( index[ch])//alreadt one
         {
             if( instack[ch] )
                 low[u]=min( low[u] , index[ch]);
         }
         else
         {
              tarjan(ch);

              low[u] = min( low[u] , low[ch] );
         }

         contpp[u] = min( contpp[u] , mini[ inscc[ch] ] );
    }

    if( low[u] == index[u] )
    {
        mini[sccid] = mp(1<<20,1<<20);

        while( !st.empty() )
        {
            long long ch = st.top();
                     st.pop();

             instack[ch]=false;
             inscc[ch]=sccid;

             mini[sccid]=min( mini[sccid] ,contpp[ch]);

             if( ch==u)
                break;
        }

        sccid++;
    }

}


int  main()
{
    long long n,m;
    string tp,to;

    cin>>n;

    fill(cont,0);

    for(long long i=0;i<n;i++)
    {
        cin>>tp;

        process(tp);

        cont[ ID[tp] ]++;
    }

    cin>>m;

    for(long long i=0;i<m;i++)
    {
        cin>>tp>>to;

        process(tp);
        process(to);

        graf[ ID[tp] ].pb( ID[to] );
    }

    //cout and len
    count_rlen();


    //start maxn
    fill(index,0);
    fill(low,-1);
    fill(instack,0);
    fill(inscc,0);


    //init mini
    for(long long i=0;i<=sccid+1;i++)
         mini[i]=mp(1<<20,1<<20);

    for(long long i=0;i<sz(input);i++)
    {

        if( !index[i] )
          tarjan(i);


      //  cout<<input[i]<<"  "<<ID[input[i]]<<" "<<contpp[i].X<<"  "<<contpp[i].Y<<"  " <<inscc[i]<<"  "<<cont[i]<<endl;
    }


////
   // for(long long i=1;i<sccid;i++)
        //cout<<mini[i].X<<"  "<<mini[i].Y<<endl;

     long long rc=0,lc=0;

     for(long long i=0;i<sz(input);i++)
     {
         rc+=cont[i]*mini[ inscc[i] ].X;
         lc+=cont[i]*mini[ inscc[i] ].Y;
     }

    cout<<rc<<" "<<lc<<endl;



    return 0;
}

