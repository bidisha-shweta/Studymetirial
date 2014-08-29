#include <iostream>
#include <limits>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;
struct chef{
	int age;
	int star;
};
struct comp1{
bool operator()(const chef& a, const chef& b)
       {
          return a.age<b.age?false:true;
       }
};
struct comp2{
       
bool operator()(const chef& a, const chef& b)
       {
          return a.age>b.age?false:true;
       }
};




int main()
{
    ;
    priority_queue<chef,vector<chef>,comp1> minHeap;
    priority_queue<chef,vector<chef>,comp2> maxHeap;
    
    int n,age,star;
    scanf("%d",&n);
    
    chef senior_min,junior_max;
    int arr[10009];
    junior_max.age = 0;
    junior_max.star = 0;
    senior_min.age = 1000000009;
    senior_min.star = 0;
    int junior_count=0;
    int senior_count=0;
    int juniortotal = 0;
    int seniortotal = 0;
    
    for(int i = 0;i < n; i++)
    {
    	chef c;
        scanf("%d %d",&c.age,&c.star);
        
        if(junior_count == senior_count)
        {
            junior_count++;
            if(senior_min.age < c.age)
            {
                //minHeap.push(star)
                /**transfer one from senior group to junior group**/
                //printf("DEBUG1 %d\n",senior_min.age);
                juniortotal+=senior_min.star;
                seniortotal-=senior_min.star;
                seniortotal+=c.star;
                maxHeap.push(senior_min);//maxPush(maxHeap,senior_min);
                minHeap.pop();
                minHeap.push(c);
                //minPush(minHeap,c);
                
                senior_min=minHeap.top();//minPop(minHeap);//search(arr,senior_min,star,-1);
                junior_max = maxHeap.top();//maxHeap.front();
            
            }
            
            else
            {
                
                /**add in the junior group**/
                juniortotal+=c.star;
                maxHeap.push(c);//maxPush(maxHeap,c);
                junior_max=maxHeap.top();
                
            }
        }
        else if(junior_count>senior_count)
        {
            senior_count++;
            /**shift the max of the minimum array to the maximum array**/
            if(c.age < junior_max.age)
            {
                
                juniortotal-=junior_max.star;
                juniortotal+=c.star;
                seniortotal+=junior_max.star;
                minHeap.push(junior_max);
                maxHeap.pop();
                maxHeap.push(c);
                junior_max=maxHeap.top();
                senior_min=minHeap.top();
                
                
                
            }
            else
            {
                
                /**add in the senior group**/
                seniortotal+=c.star;
                minHeap.push(c);
                senior_min=minHeap.top();
                
            }
        }
       
        printf("%d\n",abs(juniortotal-seniortotal));
        
    }
    
    return 0;
}

