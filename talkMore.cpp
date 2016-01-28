#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

class Plan{
		int cost;
		float monLoc;
    	float monSTD;  
    	int days; 
    public:
    	Plan(){
    		cost=0;
    		monLoc=1;
    		monSTD=1;
    		days=30;
    	}
    	Plan(int c, float l, float s, int d){
    		cost=c;
    		monLoc=l;
    		monSTD=s;
    		days=d;
    	}
    	int getCost(){ return cost; }
    	float getMonLoc(){ return monLoc; }
    	float getMonSTD(){ return monSTD; }
    	int getDays(){ return days; }
};

float solve(vector<Plan> plan, int std, int local, int day)
{
	float ret=(float)(std+local);
	if(day==0)
		return 0;
	for(int i=0;i<plan.size();i++)
	{	
		if(plan[i].getDays()<=day)
			ret = min(ret, plan[i].getCost()+std*plan[i].getMonSTD()*plan[i].getDays()/30+local*plan[i].getMonLoc()*plan[i].getDays()/30+solve(plan,(std-std*plan[i].getDays()/30),(local-local*plan[i].getDays()/30),day-plan[i].getDays()));
		else{
			ret+=local+std;
			break;
			}
	}
	return ret;
}

int main(){
	int count=1;
	char ans;
	vector<Plan> plan;
	plan.push_back(Plan());
	int locMin, stdMin,c,d;
	float l,s; 
	cout<<"\nEnter local minutes:\n";
	cin>>locMin;
	cout<<"\nEnter STD minutes:\n";
	cin>>stdMin;
	cout<<"\nYou want to enter any plan? (y/n)\n";
	cin>>ans;
	while(ans=='y'){
		count++;
		cout<<"\nEnter cost of new plan: \n";
		cin>>c;
		cout<<"\nEnter local rate for new plan in rupees: (1 if N/A)\n";
		cin>>l;
		cout<<"\nEnter STD rate in rupees: (1 if N/A)\n";
		cin>>s;
		cout<<"\nEnter number of days:\n";
		cin>>d;
		plan.push_back(Plan(c,l,s,d));
		cout<<"\nWant to enter more? (y/n)\n";
		cin>>ans;
	}
	float result = solve(plan, locMin, stdMin, 30);
	cout<<"\n\nResult is: "<<result<<"\n";
	return 0;
}


# talkMore
