#include<iostream>
using namespace std;

int hcd(int number1, int number2);

int main()
            {
          int number1, number2;
          cout<<"Please enter two numbers"<<endl;
          cin>>number1>>number2;

          cout<<"H.C.D of the two numbers is "<<hcd(number1, number2)<<endl;
return 0;

            }
          int hcd(int number1, int number2)
            {
          if (number2 !=0)
             return hcd(number2, number1%number2);
          else
             return number1;
            }
