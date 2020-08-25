#include <iostream>
#include <string>
#include <cmath>


#include <sstream>





std::string base10toR(std::string number, int r)
{
   std::string answer = "";

   if(number.find(".")<number.size())
   {

       std::string IntegerPart = number.substr(0,number.find("."));

       std::string decimalPart = number.substr(number.find(".")+1,number.size()-1);
       decimalPart = "0."+decimalPart;
       std::string answerIntegerPart = base10toR(IntegerPart,r);
       std::string answerDecimalPart = " ";
       

       double deci = std::stod(decimalPart);

       int x;

       std::string str;

       for (int i = 0; i < 6; i++)
       {
           deci = deci * r;

           x = (int)deci;

           if (x == 0)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "0");

           if (x == 1)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "1");

           if (x == 2)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "2");

           if (x == 3)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "3");

           if (x == 4)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "4");

           if (x == 5)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "5");

           if (x == 6)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "6");

           if (x == 7)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "7");

           if (x == 8)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "8");

           if (x == 9)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "9");

           if (x == 10)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "A");

           if (x == 11)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "B");

           if (x == 12)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "C");

           if (x == 13)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "D");

           if (x == 14)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "E");

           if (x == 15)

               answerDecimalPart.insert(answerDecimalPart.length() - 1, "F");

           deci = deci - (double)x;
       }

       answerDecimalPart.insert(0, ".");

       answer = answerIntegerPart  + answerDecimalPart;

 




   }
   else 
   {    int n=0;
       std::stringstream ss(number);
       
       
       
       ss>>n;
       std::string str;

       while(n!=0)
       {    if(n%r <10)
            {
           str = std::to_string(n%r);
           answer = str + answer;
            }
            else 
            {    
                char ch = 'A' + (n%r) -10;
                std::string s(1,ch);
                answer.insert(0,s);
            }
          
            n = n/r;
       }


       



   }

   
   
   
    return answer;
}

std::string baseRto10(std::string number,int r)
{
    std::string answer = "";
    if(number.find(".")<number.size())
    {
        std::string IntegerPart = number.substr(0, number.find("."));

        std::string decimalPart = number.substr(number.find(".") + 1, number.size() - 1);
        
        std::string answerIntegerPart = baseRto10(IntegerPart, r);
        std::string answerDecimalPart = "";
        double deci = 0;
        int x;

        for(int i = 0 ;  i <decimalPart.size();i++)
        {
            if (decimalPart[i] >= '0' && decimalPart[i] <= '9')
            {
                x = std::stoi(std::string(1, decimalPart[i]));
            }
            if (decimalPart[i] >= 'A' && decimalPart[i] <= 'F')
            {
                if (decimalPart[i] == 'A')
                    x = 10;
                else
                {
                    x = 10 + decimalPart[i] - 'A';
                }


            }
            deci += x*pow(r,-1-i);
        }

        std::string str = std::to_string(deci);
        
        answerDecimalPart = str.substr(1,str.size());
        

        answer = answerIntegerPart+ answerDecimalPart;



        
    }
    else
    {
        int x = 0;
        int n = 0;

        for(int i = 0;i<number.size();i++)
        {   if(number[i]>='0' && number[i]<='9')
            {
                x = std::stoi(std::string(1, number[i]));
            }
            if(number[i]>='A' && number[i]<='F')
            {
                if(number[i]=='A')
                x = 10;
                else
                {
                    x = 10 + number[i]-'A';
                }
                
            }
          
            n += x*std::pow(r,number.size()-i-1);


        }

        answer = std::to_string(n);
    }
    




    return answer;
}




std::string basextoy(std::string number,int x,int y)
{
    std::string temp = baseRto10(number,x);
    std::string answer = base10toR(temp,y);
    return answer;

}

int main()
{   std::string n;
    int x,y;
    std::cout<<"This program can convert number of any base less than or equal to 16 to any other base less than or equal to 16"<<std::endl;
    std::cout<<"Enter a number : "<<std::flush;

    std::cin>>n;

    std::cout<<"\nEnter the base of number you entered: "<<std::flush;
    std::cin>>x;
    std::cout<<"\nEnter the base in which you want to convert your number: "<<std::flush;
    std::cin>>y;
    std::string temp = baseRto10(n,x);
    std::string answer = base10toR(temp,y);
    std::cout<<"\nYour number in base "<<y<<" is "<<answer<<std::endl;


    return 0;
}