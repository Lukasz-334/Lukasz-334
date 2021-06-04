#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool Prime_number(const int& x,const std::vector<int>&vec)
{
     if(vec[x]==0)return true;
     else return false;
 
}

int main() 
{
    
std::vector<int>primary_number(100000);
primary_number[0]=1;
primary_number[1]=1;

 for(int i=2;i<=sqrt(100000);i++)
   {
    if(primary_number[i]==0)
     {
       for(int j=i*i;j<100000;j=j+i)
       {
        primary_number[j]++;
       }
     }
   }

int sum_of_numbers=0; 
std::vector<int>v(5);
int x=0;
for(int i=0;i<5;i++)
{
  std::cin>>x;
  v[i]=x;
}
sort(v.begin(),v.end());

 do {
    int val=10000;
    int num=0;
    int sum=0;
        for(int i=0;i<5;i++)
        {
            num=v[i]*val;
            sum=sum+num;
            val/=10;
        }
       if(Prime_number(sum,primary_number))
       {
       sum_of_numbers++;
       }
    } while(std::next_permutation(v.begin(), v.end()));
 
 std::cout<<sum_of_numbers<<std::endl;
 sum_of_numbers=0;
}
