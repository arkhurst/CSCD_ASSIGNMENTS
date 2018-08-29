#include<iostream>
using namespace std;

int main()
{
   int number, i, j = 0;

   cout << "Enter number: ";
   cin >> num;

   //whether number is a prime or not
   for (i = 1; i <= number; i++)
   {
      if ((number % i) == 0)
      {
         j++;
      }
   }

   if (j == 2)
      cout << "\n" << number << " is a prime number.\n";
   else
      cout << num << " is not a prime number.\n";

   return 0;
}

