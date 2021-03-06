#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
 
struct Person
{
long long name;
long long length;
};
bool operator< (const Person& a, const Person& b)
{
if(a.length<b.length)
{
return true;
}
else
{
return false;
}
}
int main()
{
int t;
long long n;
scanf("%d",&t);
for(int i =0;i<t;i++)
{
scanf("%lld",&n);
vector<Person> persons;
map<int,int> band;
for(long long j = 0;j<n;j++)
{
Person p;
scanf("%lld %lld",&p.name,&p.length);
persons.push_back(p);
}
sort(persons.begin(), persons.end());
long long count = 0;
long long total = 0;
long long subtotal = 0;
for(std::vector<Person>::iterator it = persons.begin(); it != persons.end(); ++it) {
Person p = *it;
// printf("%lld %lld\n",p.name,p.length);
if(band.find(p.name)==band.end())
{
band[p.name]=1;
count = count + 1;
total = total + count * p.length;
}
else
{
subtotal +=p.length;
}
//total = total + count * p.length;
}
total += subtotal*count;
printf("%lld\n",total);
}
return 0;

