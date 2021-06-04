#include<iostream>
#include<string>

int main()
{

std::string num;
std::cin>>num;
std::string::iterator p=num.begin();
std::string::iterator k=num.end();

while(p!=k)
{
if(*p=='0')
  {
  break;
  }
  p++;
}

while(p!=k)
{
k--;
if(*k=='1')
  {
  break;
  } 
}


if((*p=='0')&&(*k=='1'))
{
  std::string new_num(p+1,k); 
  if(new_num.empty())
  {
   std::cout<<"PUSTY"<<std::endl;
  }
  else
  {
   std::cout<<new_num<<std::endl;  
  }
}
else
{
std::cout<<"PUSTY"<<std::endl;
}

    return 0;
}