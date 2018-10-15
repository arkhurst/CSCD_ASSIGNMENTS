#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()     {

     
         
   int id_number;
   int score;
   string gender;
   char grade;
   string name;
   int age;
   int ageTotal = 0;
   int numberOfStudents = 0;
   int femaleCount = 0;
   int maleCount = 0;
   int scoreCount = 0;
   double averageScore;
   double averageAge;
      

   for( int x = 0; x<5; x++){
     ofstream outfile;
     outfile.open (" file.txt ");

     cout<< "Input your student id number";
     cin>> id_number;
     outfile << id_number<< endl;

     cout<< "Your name?";
     cin>> name;
     outfile <<name<<endl;
     
     cout<< "What is your age";
     cin>> age;
     outfile<<age<<endl;
     numberOfStudents++;
     scoreCount = scoreCount + score;
     ageTotal = ageTotal + age;


     cout<< "Your gender (male/female)";
     cin>> gender;
     outfile<<gender<<endl;
         if( gender == "female"){
             femaleCount++;
         }
        else if( gender == "male"){
             maleCount++;
         }            
     cout<< "what is your score?";
     cin>> score;
     outfile<<score<<endl;


outfile.close();
      
              
     
 }

ifstream infile;
infile.open ("file.txt");

infile.close ();  
    cout<< "The total number of student input is: "<<numberOfStudents<<endl;
    averageAge = ageTotal/numberOfStudents;
    cout<< "The average number of age is: "<<averageAge<<endl;
    averageScore = scoreCount/numberOfStudents;
    cout<< "The average number of score is: "<<averageScore<<endl;
    cout<< "the male count is: "<<maleCount<<endl;
    cout<< "the female count is: "<<femaleCount<<endl;


return 0;
}
