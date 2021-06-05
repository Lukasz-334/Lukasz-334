#include<iostream>
#include<string>


int main()
{
std::string end_word;
char letter;
int num=0;
std::string instruction;
int number_of_instructions=0; 
std::cin>>number_of_instructions;

while(number_of_instructions--)
  {
  std::cin>>instruction;
  
  if(instruction=="DODAJ")
    {
    std::cin>>letter;
    end_word+=letter;
    }
  else if(instruction=="USUN")  
    {
    std::cin>>num;
    int it=0;
    it=end_word.size()-num;
        if(it<=0)
        {
          end_word.erase();  
        }
        else
        {
         end_word.erase(it);   
        }
    }
  else if(instruction=="ZAMIEN")  
    {
    std::cin>>letter;
    if(!end_word.empty())
        {
          char& back = end_word.back();
          back=letter;  
        }
    }
  }

std::cout<<end_word<<std::endl;

return 0;

}