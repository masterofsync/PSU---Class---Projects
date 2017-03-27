/*
Bikesh Maharjan
CS163
Program 5
APPLICATION.CPP- THIS FILE IS USED AS A TESTING AREA FOR THE CODES 
*/

//INCLUDING MAINCLAS.H
#include "mainclas.h"
using namespace std;

//MAIN FUNCTION FOR PROGRAM TESTING
int main()
{
    
    
    cout<<endl<<endl<<"******WELCOME TO GRAPHS*****"<<endl;
    cout<<"*****BY BIKESH MAHARJAN*****"<<endl<<endl;
    
    //DECLARING A VARIABLE OF THE CLASS TABLE
    table items;
    
    //DECLARING VARIABLES
    int choice;
    
    //DO WHILE PROGRAM TO EXIT IF THE CHOICES LISTED ARE NOT CHOSEN
    do
    {
         cout<<endl<<"OPTIONS:"<<endl;
         cout<<"1. ADD VERTICES"<<endl;
         cout<<"2. ADD EDGES"<<endl;
         cout<<"3. SEARCH"<<endl;
         cout<<"4. DISPLAY ALL"<<endl;
         cout<<"5. EXIT"<<endl;
         cout<<endl<<"ENTER CHOICE: ";

         cin>>choice;                             //GETTING THE VALUE FOR CHOICE
         cin.ignore();                            //ISTREAM IGNORE 

         //IF STATEMENTS FOR CALLING THE RIGHT FUNCTIONS 
         if(choice==1)
         {
             adding(items);
         }
    
         if(choice==2)
         {
             addingedges();       
         }
    
         if(choice==3)
         { 
             find();        
         }     
         if(choice==4)
             items.display();
    
    }while(choice>0 && choice<5);
    
    return 0;
}
