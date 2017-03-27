/*
      Bikesh Maharjan
      CS 202
      Program 3
      APPLICATION.CPP- APPLICATION AREA TO TEST DATA
*/

//INCLUDING MAINCLAS.H
#include "mainclass.h"
using namespace std;

//MAIN FUNCTION FOR PROGRAM TESTING
int main()
{
    
    cout<<endl<<endl<<"******WELCOME TO PSU-CLASSES*****"<<endl;
    cout<<"*****BY BIKESH MAHARJAN*****"<<endl<<endl;
    
    //DECLARING A VARIABLE OF THE CLASS TABLE
    table items;
    application item;
    
    //DECLARING VARIABLES
    int choice;
    
    //DO WHILE PROGRAM TO EXIT IF THE CHOICES LISTED ARE NOT CHOSEN
    do
    {
         cout<<endl<<"OPTIONS:"<<endl;
         cout<<"1. ADD CLASSES"<<endl;
         cout<<"2. ADD PRE-REQUISITE"<<endl;
         cout<<"3. SEARCH"<<endl;
         cout<<"4. DISPLAY ALL"<<endl;
         cout<<"5. EXIT"<<endl;
         cout<<endl<<"ENTER CHOICE: ";

         cin>>choice;                             //GETTING THE VALUE FOR CHOICE
         cin.ignore();                            //ISTREAM IGNORE 

         //IF STATEMENTS FOR CALLING THE RIGHT FUNCTIONS 
         if(choice==1)
         {
             item.adding(items);
         }
    
         if(choice==2)
         {
             item.addingedges(items);       
         }
    
         if(choice==3)
         { 
             item.find(items);        
         }     
         if(choice==4)
         {
             items.display();
         }
    }while(choice>0 && choice<5);
    
    cout<<endl<<"THANK YOU FOR USING THIS PROGRAM"<<endl;
    
    return 0;
}
