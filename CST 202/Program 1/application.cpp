/*
 BIKESH MAHARJAN
 CS 202
 PROGRAM 1
 APPLICATION.CPP- CONTAINS THE APPLICATION PROGRAM TO TEST THE FUNCTIONS
*/

//INCLUDING MAINCLASS.H
#include "mainclass.h"


//MAIN FUNCTION
int main()
{
    int options;                               //DECLARING THE INTEGER FUNCTION
    
    //CREATING A CLASS VARIABLE
    application process;                        //DECLARING CLASS VARIABLE
    
    welcome();
    
    //DO WHILE LOOP 
    do
    {
         cout<<endl<<"MENU: "<<endl;
         cout<<"1. ADD"<<endl;
         cout<<"2. SEARCH"<<endl;
         cout<<"3. REMOVE"<<endl;
         cout<<"4. DISPLAY ALL"<<endl;
         cout<<"5. EXIT"<<endl;
         
         cout<<endl<<"ENTER THE OPTION: ";
         cin>>options;                       //GETTING THE USER CHOICE
         cin.ignore();                       //IOSTREAM IGNORE
         
         if(options==1)
              process.add();                 //CALING THE FUNCTION TO ADD
         if(options==2)
              process.search();              //CALLING THE FUNCTION TO SEARCH
         if(options==3)
              process.remove();              //CALLING THE FUNCTION TO REMOVE
         if(options==4)
              process.display();             //CALLING THE FUNCTION TO DISPLAY
              
    }while(options > 0 && options < 5);     
    
    cout<<endl<<"THANK YOU FOR USING THE PROGRAM"<<endl;
    
    return 0;
}
