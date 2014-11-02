#include<algorithm>
#include<iomanip> 
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;


#define pb push_back

vector <int> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);
  
  
  vector<int> tp;
  
  for(int i=0;i<ans.size();i++)
   tp.pb( atoi( ans[i].c_str() ) );

  return tp;
}

	
struct node
{
       int st,fn,gn;
       
       bool operator <( const node &a) const
        {
		 return ( fn < a.fn);
        }
        
};

//similar to spoj RENT :)

class ContestSchedule 
{
public:

double  expectedWinnings(vector <string> cont) 
{
	 
				 int n,dp[55];

  				 node data[55];
 
                   
                 n=cont.size();                
                 
                  
                  int i,j,maks;
                  
                  for(i=0;i<n;i++)
                   {
				       vector<int> tp=parse( cont[i]," " );
				       data[i].st=tp[0];
                       data[i].fn=tp[1];
                       data[i].gn=tp[2];
                   }        
                   
                   sort(data,data+n);
                   
                     for(i=0;i<n;i++)
                      {  
					      maks=0;
                      
                         for(j=0;j<i;j++)
                           {
                              if( data[j].fn <= data[i].st )
                                maks=max( maks , dp[j] );           
                              else
                                break;
                           }       
                           
                           dp[i]=maks+data[i].gn;
                      }      
                      
                      int mx=0;
                      for(i=0;i<n;i++)
                       mx=max(mx, dp[i] );
                       
                      double ans=mx;
                             ans=ans/100.00;
                      
					  return ans;
 	
}

};



double test0() {
	string t0[] = {"1 10 100","10 20 100","20 30 100","30 40 100"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ContestSchedule * obj = new ContestSchedule();
	clock_t start = clock();
	double my_answer = obj->expectedWinnings(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 4.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"10 20 20","30 40 60","15 35 90"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ContestSchedule * obj = new ContestSchedule();
	clock_t start = clock();
	double my_answer = obj->expectedWinnings(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.9;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"1 100 85","99 102 100","101 200 60"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ContestSchedule * obj = new ContestSchedule();
	clock_t start = clock();
	double my_answer = obj->expectedWinnings(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 1.45;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"1 1000000000 1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ContestSchedule * obj = new ContestSchedule();
	clock_t start = clock();
	double my_answer = obj->expectedWinnings(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.01;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {
"1361955 8940967 10","628145516 644285978 17","883515280 910484865 36",
"762888635 769291174 52","98152102 136328674 1","9580638 20450682 50",
"646139319 664648341 20","484027666 505290970 57","841082555 879295329 99",
"940563715 966953344 4","579113528 595261527 25","925801172 962952912 9",
"285845005 307916055 45","403573723 410697485 10","9467290 25698952 90",
"631265400 650639733 3","520690249 559261759 96","491747709 531061081 86",
"643215695 672420161 94","614608448 617341712 44","456517316 491770747 24",
"806956091 828414045 88","528156706 559510719 15","158398859 190439269 4",
"743974602 761975244 49","882264704 887725893 1","877444309 884479317 59",
"785986538 806192822 19","732553407 747696021 81","132099860 148305810 97",
"555144412 572785730 99","506507263 535927950 82","489726669 505160939 90",
"793692316 804153358 99","901329638 919179990 10","29523791 44318662 58",
"570497239 595701008 73","706091347 730328348 23","118054686 135301010 39",
"307178252 337804001 93","896162463 900667971 39","271356542 273095245 80",
"865692962 891795950 91","593986003 596160000 58","807688147 831190344 59",
"468916697 496462595 92"
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ContestSchedule * obj = new ContestSchedule();
	clock_t start = clock();
	double my_answer = obj->expectedWinnings(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 14.12;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
