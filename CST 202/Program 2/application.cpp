/*
 BIKESH MAHARJAN
 CS 202
 PROGRAM 2
 APPLICATION.CPP- CONTAINS THE APPLICATION PROGRAM TO TEST THE FUNCTIONS
*/

//INCLUDING MAINCLASS.H
#include "mainclass.h"


//MAIN FUNCTION
int main()
{
    int options;                      //DECLARING THE INTEGER FUNCTION
    mains data;                        //DECLARING CLASS VARIABLE
    
    welcome();                        //DECLARING MEMBER FUNCTION TO WELCOME
    
    //DO WHILE LOOP 
    do
    {
           // INTEGER DATA 
           int choice;
           
           cout<<endl<<"ENTER WHAT TO WORK ON: ";
           cout<<endl<<"1. ADD"<<endl;
           cout<<"2. REMOVE"<<endl;
           cout<<"3. EDIT"<<endl;
           cout<<"4. DISPLAY ALL"<<endl;
           cout<<endl<<"PLEASE CHOOSE: ";
           cin>>choice;               // GETTING CHOICE OF THE USER
           cin.ignore();              //ISTREAM IGNORE
           
           data.input(choice);        //IMPLEMENTING FUNCTION INPUT
                
    }while(options > 0 && options < 5);     
    
    cout<<endl<<"THANK YOU FOR USING THE PROGRAM"<<endl;
    
    return 0;
}
