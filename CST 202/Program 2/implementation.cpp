/*
   Bikesh Maharjan
   CS 202
   PROGRAM 2
   IMPLEMENTATION.CPP- IMPLEMENTS ALL THE FUNCTIONS AND FUNCTION MEMBER OF CLASSES
*/

//INCLUDING MAINCLASS FILE
#include "mainclass.h"
using namespace std;

int welcome()
{
     cout<<endl<<endl<<"*************WELCOME TO FILE STORING EXPERIMENT***********"<<endl;
     cout<<"*******************BY BIKESH MAHARJAN*********************"<<endl<<endl<<endl;		
     return 0;	
}

//INITIALIZING DATA IN DEFAULT CONSTRUCTOR
mains::mains()
{
     device = NULL;
}

//DEFAULT DESTRUCTOR
mains::~mains()
{
     delete []device;             
     delete device;
}

// FUNCTION TO GET CHOICE AND IMPLEMENT WHICHEVER CHOICE TO WORK ON
int mains::input(int choice)
{
    if(choice == 1)
    {
            add();                          //CALLING FUNCTION TO ADD      
    }        
     
    if(choice == 2)
    {
            remove();                       //CALLING FUNCTION TO REMOVE
    }
    
    if(choice == 3)
    {
            edit();                         //CALLING FUNCTION TO EDIT
    }        
    
    if(choice == 4)
    {
             displayall();                  //CALLING FUNCTION TO DISPLAY ALL
    }
         
    return 0;
}


//MEMBER FUNCTION TO ADD
int mains::add()
{
    //CREATING VARIABLES
    int choice1;
    char devicename[100];
    
    //DO_WHILE LOOP
    do
    {
           int choice1 = 0; 
           cout<<endl<<"ENTER WHICH DEVICE TO WORK ON: ";
           cout<<endl<<"1. LAPTOP"<<endl;
           cout<<"2. TABLET"<<endl;
           cout<<"3. USB"<<endl;
           cout<<endl<<"PLEASE CHOOSE: ";
      
           cin>>choice1;                      //GETTING CHOICE FROM THE USER
           cin.ignore();                      //ISTREAM IGNORE
           
           
    }while (choice1>0 && choice1<4);
    
     //IF_STATEMENT    
    if(choice1 == 1)
          device1.add();
    if(choice1 == 2)
          device2.add();
    if(choice1 == 3)
          device3.add();
    
    return 0;
}

//MEMBER FUNCTION TO REMOVE
int mains::remove()
{
    //CREATING VARIABLES
    int choice1;
    char devicename[100];
    
    //DO_WHILE LOOP
    do
    {
          int choice1 = 0; 
     
          cout<<endl<<"ENTER WHICH DEVICE TO WORK ON: ";
          cout<<endl<<"1. LAPTOP"<<endl;
          cout<<"2. USB"<<endl;
          cout<<"3. TABLET"<<endl;
          cout<<endl<<"PLEASE CHOOSE: ";
     
          cin>>choice1;                    //GETTING CHOICE FROM THE USER
          cin.ignore();                    //ISTREAM IGNORE      
    }while (choice1>0 && choice1<4);
     
    //IF STATEMENTS TO SELECT WHICH DEVICE TO WORK ON
    if(choice1 == 1)
          device1.remove();
    if(choice1 == 2)
          device2.remove();
    if(choice1 == 3)
          device3.remove();
           
    return 0; 
}

//MEMBER FUNCTION OF CLASS MAIN TO EDIT
int mains::edit()
{
    //CREATING VARIABLES
    int choice1;
    char devicename[100];
    
    //DO_WHILE LOOP
    do
    {       
          int choice1 = 0; 
     
          cout<<endl<<"ENTER WHICH DEVICE TO WORK ON: ";
          cout<<endl<<"1. LAPTOP"<<endl;
          cout<<"2. USB"<<endl;
          cout<<"3. TABLET"<<endl;
          cout<<endl<<"PLEASE CHOOSE: ";
     
          cin>>choice1;                       //GETTING CHOICE FROM THE USER
          cin.ignore();                       //ISTREAM IGNORE
          
          
    }while (choice1>0 && choice1<4);
     
    //IF STATEMENTS
    if(choice1 == 1)
          device1.edit();
    if(choice1 == 2)
          device2.edit();
    if(choice1 == 3)
          device3.edit();
    return 0;
}
      
//MEMBER FUNCTION TO DISPLAY ALL DATAS
int mains::displayall()
{
    //CARRYING OUT FUNCTIONS TO DISPLAY ALL DATA   
    device1.display();
    device2.display();
    device3.display();
    return 0;
}    

//DEFAULT CONSTRUCTOR FOR LAPTOP
laptop::laptop()
{   
    head = NULL;               //INITIALIZING THE HEAD POINTER
}

//DEFAULT DESTRUCTOR TO DELETE ALL DATA IN LAPTOP
laptop::~laptop()
{
    delete []head;
    delete head;
}

//MEMBER FUNCTION OF CLASS LAPTOP TO ADD
int laptop::adddata(char *data)
{
    //CREATING NODE POINTERS
    node *temp;
    node *temp1; 
    temp = head;
    
    //IF STATEMENT TO CHECK IF HEAD IS NULL AND TO ADD DATA
    if(head == NULL)
    {
        head = new node;                       //CREATING NEW NODE AS HEAD  
        head->data = new char[strlen(data)+1]; //ALLOCATING SPACE FOR DATA
        strcpy(head->data, data);              //COPYING DATA
        head->prev = NULL;                     //SETTING PREVIOUS TO NULL
        head->next = NULL;                     //SETTING NEXT POINTER TO NULL
    }
    else if(temp->next == NULL)                //CHECKING IF SECOND NODE IS NULL
    {
        temp->next=new node;                   //CREATING NEXT NEW NODE
        temp = temp->next;                     //GOING TO NEXT NODE
        temp->data=new char[strlen(data)+1];   //ALLOCATING SPACE FOR DATA
        strcpy(temp->data, data);              //COPYING DATA
        temp->prev = head;                     //CREATING DOUBLY LINKED LIST
        temp->next= NULL;                      //SETTING NEXT POINTER TO NULL
    }
    else
    {
        while(temp->next != NULL)              //GOING TO THE LAST NODE
        {
              temp1 = temp;
              temp->next = new node;           //NEW NODE IN NEXT POINTER
              temp = temp->next;               //GOING TO NEXT NODE
              temp->data=new char[strlen(data)+1];
              strcpy(temp->data, data);        //COPYING DATA
              temp->next = NULL;               //SETTING NEXT POINTER TO NULL
              temp->prev = temp1;              //SETTING DOUBLY LINKED LIST
        }
    }
    
    return 0;
}

//MEMBER FUNCTION TO REMOVE DATA
int laptop::removedata(char *data)
{
    //CREATING NODE POINTERS
    node *temp;
    node *temp1 = head;
    temp = head->next;
    
    //CHECKING IF HEAD POINTER IS NULL
    if(head == NULL)
        cout<<"NO DATA";
    else if(head->next == NULL)            //CHECKING IF NEXT POINTER IS NULL
    {
        if(strcmp(head->data,data) == 0);  //COMPARING IF BOTH DATA ARE SAME
        {
             delete []head;                //DELETING  IF ITS SAME
             delete head;                  //DELETING HEAD
             head = NULL;                  //SETTING HEAD TO NULL
        }
    }
    else
    {
         while(temp->next != NULL)             //TRAVERSING TO LAST NODE
         {
                       
             if(strcmp(temp->data,data) == 0)//COMPARING IF BOTH DATA ARE SAME
             {
                   temp1->next = temp->next; //SETTING NEXT POINTER AS SAME
                   temp = NULL;              //SETTING TEMP AS NULL          
                   return 0;
             }
             temp1 = temp;                             
             temp = temp->next;              //TRAVERSING TO NEXT POINTER          
         }
         cout<<"SPECIFIED FILE NOT FOUND";
    }
    return 0;
}

//MEMBER FUNCTION TO DISPLAY
int laptop::displaydata()
{
    //CREATING DATA VARIABLES
    int num = 1;
    node *temp = head;                    //CREATING A NODE POINTER
    if(head == NULL)                      //CARRYING OUT IF HEAD IS NULL 
    {
            cout<<"NO FILES IN LAPTOP";
    }
    else
    {
            cout<<endl<<"FILES IN LAPTOP: "<<endl;
            while(temp->next != NULL)     //REAPEATING TILL LAST NODE        
            {  
                  cout<<num<<". "<<temp->data<<endl;
                  num += 1;
            }
    }
    return 0;
}

//MEMBER FUNCTION OF LAPTOP TO EDIT DATA
int laptop::editdata(char *data, char *newdata)
{
    //CREATING TEMPORARY VARIABLES
    node *temp;
    node *temp1 = head;
    
    temp = head->next;                        //SETTING TEMP TO NEXT OF HEAD
     
    if(head == NULL)                          // WHEN HEAD IS NULL
        cout<<"NO DATA";
    else if(head->next == NULL)
    {
        if(strcmp(head->data,data) == 0);     //COMPARING IF DATAS ARE SAME
        {
             strcpy(head->data, newdata);     //COPYING DATA             
        }
    }
    else
    {
        while(temp->next != NULL)               //TRAVERSING TILL LAST POINTER
        {
                       
             if(strcmp(temp->data,data) == 0)  //COMPARING DATA
             {
                   strcpy(temp->data,newdata);
                   return 0;
             }
             temp1 = temp;
             temp = temp->next;
        }
        cout<<"SPECIFIED FILE NOT FOUND";
    }
    return 0;
}

//DEFAULT CONSTRUCTOR OF SUBCLASS OF LAPTOP
sublaptop::sublaptop()
{
     data = NULL;
}

//DEFAULT DESTRUCTOR OF SUBCLASS OF LAPTOP
sublaptop::~sublaptop()
{
     delete []data;
     delete data;
}

//MEMBER FUNCTION TO ADD
int sublaptop::add()
{
    //CREATING VARIABLE
    char data1[100];
    
    cout<<"PLEASE ENTER FILE NAME TO SAVE: ";
    cin.get(data1,100,'\n');                  //GETTING DATA FROM USER
    cin.ignore(101,'\n');                     //ISTREAM IGNORE
    
    data = new char[strlen(data1)+1];         //ALLOCATING DATA TYPE AND SPACE
    strcpy(data,data1);                       //COPYING DATA
    
    adddata(data);                            //CALLING FUNCTION TO ADD DATA
    return 0;
}

//MEMBER FUNCTION TO REMOVE
int sublaptop::remove()
{
    char data1[100];
    
    cout<<"PLEASE ENTER FILE NAME TO SAVE: ";
    cin.get(data1,100,'\n');                  //GETTING DATA FROM USER
    cin.ignore(101,'\n');                     //ISTREAM IGNORE
    
    data = new char[strlen(data1)+1];         //ALLOCATING DATA SPACE
    strcpy(data,data1);                       //COPYING DATAS
    
    removedata(data);                         //CALLING FUNTION TO REMOVE DATA
    return 0;
}

//MEMBER FUNCTION TO DISPLAY ALL THE FILES IN LAPTOP
int sublaptop::display()
{
    displaydata();                            //CALLING FUNCTION TO DISPALY DATA
    return 0;
}

//MEMBER FUNCTION TO EDIT DATA IN LAPTOP
int sublaptop::edit()
{
    //CREATING DATA VARIABLES
    char data1[100];
    char data2[100];
    char newdata[100];
    
    cout<<"PLEASE ENTER FILE NAME TO EDIT: ";
    cin.get(data1,100,'\n');                 //GETTING DATA FROM THE USER
    cin.ignore(101,'\n');                    //ISTREAM IGNORE
    
    cout<<"ENTER FILE NEW FILE NAME:";
    cin.get(data2,100,'\n');                 //GETTING SECOND DATA FROM THE USER
    cin.ignore(101,'\n');                    //ISTREAM IGNORE
    
    data = new char[strlen(data1)+1];        //ALLOCATING SPACE FOR DATA
    strcpy(data,data1);                      //COPYING DATA
                       
    editdata(data, newdata);                 //CALLING FUNTION TO EDIT DATA
    return 0;
}


//FUNCTION TO MAKE A KEY OF A WORD
int keychanger(char keyword[])
{
    //FOR LOOP
    for(int count=0;count<strlen(keyword);++count)
            keyword[count] = tolower(keyword[count]);
    int key = keyword[0]+keyword[2];
    
    if(keyword != NULL)
    return key;
    else
    return -1;
}

//DEFAULT CONSTRUCTOR 
subtablet::subtablet()
{
     data = NULL;
}

//DEFAULT DESTRUCTOR
subtablet::~subtablet()
{
     delete []data;
     delete data;
}

//MEMBER FUNCTION TO ADD
int subtablet::add()
{
    //CREATING VARIABLES
    char data1[100];
    int key;
    
    cout<<"PLEASE ENTER FILE NAME TO SAVE: ";
    cin.get(data1,100,'\n');                  //GETTING DATA FROM THE USER
    cin.ignore(101,'\n');                     //ISTREAM IGNORE
    
    data = new char[strlen(data1)+1];         //ALLOCATING DATA SPACE
    strcpy(data,data1);                       //COPYING DATA
    
    key = keychanger(data);                   //CALLING FUNCTION TO GET THE KEY
    
    adddata(key, data);                       //CALLING FUNCTION TO ADD DATA
    return 0;
}

//MEMBER FUNCTION TO REMOVE DATA
int subtablet::remove()
{
    //CREATING DATA VARIABLES
    char data1[100];
    int key;
    
    cout<<"PLEASE ENTER FILE NAME TO SAVE: ";
    cin.get(data1,100,'\n');                  //GETTING DATA FROM THE USER
    cin.ignore(101,'\n');                     //ISTREAM IGNORE
                                              
    data = new char[strlen(data1)+1];         //ALLOCATING DATA SPACE
    strcpy(data,data1);                       //COPYING DATA
    
    key = keychanger(data);                   //CALLING FUNCTION TO GET KEY
    
    removedata(key);                          //CALLING FUNCTION TO REMOVE
    
    return 0;
}

//MEMBER FUNCTION TO DISPLAY
int subtablet::display()
{
    displaydata();                            //CALLING FUNCTION TO DISPLAY DATA          
    return 0;
}

//MEMBER FUNCTION TO EDIT
int subtablet::edit()
{
    //CREATING DATA VARIABLES
    char data1[100];
    char data2[100];
    char newdata[100];
    
    cout<<"PLEASE ENTER FILE NAME TO EDIT: ";
    cin.get(data1,100,'\n');                  //GETTING DATA FROM THE USER
    cin.ignore(101,'\n');                     //ISTREAM IGNORE
    
    cout<<"ENTER FILE NEW FILE NAME:";
    cin.get(data2,100,'\n');                  //GETTING SECOND DATA FROM USER
    cin.ignore(101,'\n');                     //ISTREAM IGNORE
    
    data = new char[strlen(data1)+1];         //ALLOCATING DATA SPACE
    strcpy(data,data1);                       //COPYING DATA
    
    editdata(data, newdata);                  //CALLING FUNCTION TO EDIT DATA
    return 0;
}

//DEFAULT CONSTRUCTOR
tablet::tablet()
{
    size = 12;                           //SETTING THE ARRAY SIZE TO 12            
    head2 = new node;                    //MAKING NEW NODE
    head2->datas = new char*[size];      //CREATING ARRAY IN LLL
    for (int i = 0; i < size; i++)       //FOR LOOP
    {
        head2->datas[i] = NULL;          //SETTING ALL DATA TO NULL
    }
}

//DEFAULT DESTRUCTOR TO REMOVE EVERYTHING
tablet::~tablet()
{
    for (int i = 0; i < size; i++)
    {
         if (head2 != NULL) 
         {
               node *entry1 = NULL;
               node *entry2 = head2;         
               while (entry2 != NULL) 
               {
                     entry1 = entry2;
                     entry2 = entry2->next;
                     for (int i = 0; i < size; i++)
                     {
                            if(head2->datas[i] != NULL)
                            delete[] head2->datas[i];         
                     }
                              
                     delete head2;   
                     delete entry1;   
               }
         }               
    }
}

//MEMBER FUNCTION TO ADD DATA
int tablet::adddata(int key, char *item)
{
    int position = (key % size);          //FOR THE POSITION OF DATA
    node *temp = NULL;                    //CREATING NODE POINTER          
            
    if(head2 == NULL)
    {
           head2 = new node;              //CREATING NEW NODE
           head2->datas[position] = new char[strlen(item)+1]; //ALLOCATING SPACE 
           strcpy(head2->datas[position], item);  
           head2->next = NULL;            //SETTING NEXT POINTER TO NULL
    }
    else
    {
           temp = head2;
           while(temp->next != NULL)      //TRAVERSING TO LAST NODE
           {
                    //IF STATEMENT TO CHECK IF ITS NULL        
                  if(temp->datas[position] == NULL)
                  {
                         temp->datas[position] =new char[strlen(item)+1];               
                         strcpy(temp->datas[position], item);
                         return 1;
                  }  
                  temp = temp->next;
           }
           temp->next = new node;         //CREATING NEW NODE 
           temp = temp->next;
           temp->datas[position] =new char[strlen(item)+1];
           strcpy(temp->datas[position], item);            
    }
    return 1;
}
     
    

//MEMBER FUNCTION TO REMOVE DATA
int tablet::removedata(int key)
{
    //GETTING THE POSITION OF THE DATA TO REMOVE
    int position = (key % size);
    node *temp = NULL;           //CREATING NODE POINTER AND SETTING TO NULL
    
    //IF STATEMENT
    if(head2 == NULL)
    {
         cout<<"NO DATA TO REMOVE";
    }
    else
    {
         temp = head2;
         while(head2 != NULL)          //WHILE HEAD IS NOT NULL
         {
                temp = head2->next; 
                for(int i = 0;i<12;i++) //LOOP 12 TIMES     
                {
                        if(head2->datas[i] != NULL) //IF DATA IS NOT NULL
                        {
                               delete []head2->datas[i];
                        }
                }
                delete []head2;
                delete head2;
                head2 = temp;
         }
    }
return 1;
}
                            

//MEMBER FUNCTION TO DISPLAY DATA
int tablet::displaydata()
{
    node *temp = head2;
    cout<<endl<<"ALL FILES IN TABLET: "<<endl;
    while(temp->next != NULL)       //TRAVERSING UNTIL IT REACHES IT LAST NODE
    {
           for (int i = 0;i<12;i++) 
           {
                 if(temp->datas[i] != NULL)               
                 cout<<temp->datas[i]; 
           }
           temp = temp->next;
    }
}


//MEMBER FUNCTION TO EDIT DATA
int tablet::editdata(char *data, char *newdata)
{
     
      int key = keychanger(data);      //KEY OF DATA TO BE EDITED
      int key2;   
      int position = (key % size);     //POSITION OF DATA TO BE EDITED
      int key3 = keychanger(newdata);  //KEY OF NEW DATA
      
      if (head2 == NULL)
      {
           cout<<"NO DATA FOUND TO EDIT";
      }
      else 
      {
           node *temp = head2; 
           
           //WHILE LOOP UNTIL NULL OR WHEN THE KEY MATCHES
           while(temp->next != NULL && key != key2) 
           {
                 key2 = keychanger(temp->datas[position]);
                 temp = temp->next;
           }
           if (temp == NULL)
           { 
                 cout<<"NO DATA FOUND";
           }
           else
           {
               removedata(key);         //CALLING FUNCTION TO REMOVE DATA                  
               adddata(key3,newdata);   //CALLING FUNCTION TO ADD DATA
           }
      }
    
}

//DEFAULT CONSTRUCTOR
subusb::subusb()
{
     data = NULL;
}

//DEFAULT DESTRUCTOR
subusb::~subusb()
{
     delete []data;
     delete data;
}

//MEMBER FUNCTION TO ADD
int subusb::add()
{
    char data1[100];
    int key;
    
    cout<<"PLEASE ENTER FILE NAME TO SAVE: ";
    cin.get(data1,100,'\n');               //GETTING DATA FROM THE USER
    cin.ignore(101,'\n');                  //ISTREAM IGNORE
    
    data = new char[strlen(data1)+1];      //ALLOCATING DATA SPACE
    strcpy(data,data1);                    //COPYING DATA
    
    key = keychanger(data1);               //GETTING KEY OF SPECIFIED DATA
    
    adddata(key, data);                    //CALLING FUNCTION TO ADD DATA
    
    return 0;
}

//MEMBER FUNCTION TO REMOVE
int subusb::remove()
{
    char data1[100];
    int key;
    
    cout<<"PLEASE ENTER FILE NAME TO SAVE: ";
    cin.get(data1,100,'\n');               //GETTING DATA FROM THE USER
    cin.ignore(101,'\n');                  //ISTREAM IGNORE
    
    key = keychanger(data1);               //GETTING THE KEY OF THE DATA
    
    data = new char[strlen(data1)+1];      //ALLOCATING SPACE FOR THE DATA
    strcpy(data,data1);                    //COPYING DATA
    
    
    removedata(key);                       //CALLING FUNTION TO REMOVE DATA
    
    return 0;
}

//MEMBER FUNCTION TO DISPLAY
int subusb::display()
{
    displaydata();                         //CALLING FUNCTION TO DISPLAY DATA
    
    return 0;
}

//MEMBER FUNCTION TO EDIT DATA
int subusb::edit()
{
    //CREATING CHAR VARIABLES
    char data1[100];
    char data2[100];
    char newdata[100];
    
    cout<<"PLEASE ENTER FILE NAME TO EDIT: ";
    cin.get(data1,100,'\n');               //GETTING DATA FROM THE USER
    cin.ignore(101,'\n');                  //ISTREAM IGNORE
    
    cout<<"ENTER FILE NEW FILE NAME:";
    cin.get(data2,100,'\n');               //GETTING DATA FROM THE USER
    cin.ignore(101,'\n');                  //ISTREAM IGNORE
    
    data = new char[strlen(data1)+1];      //ALLOCATING SPACE
    strcpy(data,data1);                    //COPYING DATA
    
    editdata(data, newdata);               //CALLING FUNCTION TO EDIT DATA
    return 0;
}


//DEFAULT CONSTRUCTOR
usb::usb()
{
       size = 12;
       head3 = new node*[size];
       for (int i = 0; i < size; i++)
       {
            head3[i] = NULL;       
       }
}

//DEFAULT DESTRUCTOR FOR USB
usb::~usb()
{
       for (int i = 0; i < size; i++)
       if (head3[i] != NULL) 
       {
             node *entry1 = NULL;
             node *entry2 = head3[i];
             while (entry2 != NULL) 
             {
                   entry1 = entry2;
                   entry2 = entry2->next;
                   delete[] head3;         
                   delete entry1;
             }
       }               
}
 


//MEMBER FUNCTION TO ADD DATA IN USB
int usb :: adddata(int key, char *data) 
{
     int position = (key % size);   //GETTING THE POSITION OF DATA
                       
     if (head3[position] == NULL)
     {    
          head3[position] = new node;
          head3[position]->next = NULL;
          strcpy(head3[position]->data,data);
     }   
     else 
     { 
          node *entry = head3[position];
          while(entry->next != NULL)//TRAVERSING TILL LAST NODE
          {
               entry = entry->next;
          }
          entry->next = new node;
          entry = entry->next;
          strcpy(entry->data, data);
     }
     return 0;
}


//MEMBER FUNCTION TO REMOVE DATA
int usb::removedata(int key) 
{
    int position = (key % size);         //GETTING THE POSITION OF THE DATA
    int key2;
    
    if (head3[position] != NULL)         //IF HEAD IS NOT NULL 
    {
          //CREATING TEMPORARY NODE POINTERS TO CARRY OUT OPERATIONS              
          node *prev = NULL;             
          node *entry = head3[position];
          key2 = keychanger(entry->data);
          
          //WHILE LOOP TO LOOP UNTIL THERE IS NO DATA AND TILL THE DATA IS FOUND
          while (entry->next != NULL && key != key2) 
          {
                prev = entry;
                entry = entry->next;
          }
          
          if (key != key2) 
          {
                if (prev == NULL) 
                {
                     node *nextData = entry->next;
                     delete entry;
                     head3[position] = nextData;
                }
           
                else 
                {
                     node *nextData = entry->next;
                     delete entry;
                     prev->next = nextData;
                }
          }
    }
}

//MEMBER FUNCTION TO EDIT DATA
int usb::editdata(char *data, char *newdata)
{
    int key = keychanger(data);       //GETTING THE KEY OF DATA THAT IS STORED
    int key2;                         
    int position = (key % size);      //GETTING THE POSITION OF THE DATA
    int key3 = keychanger(newdata);   //GETTTING THE KEY FOR NEW DATA
    
    //IF STATEMENT TO CHECK IF THE HEAD IS NULL
    if (head3[position] == NULL)
    {
         cout<<"NO DATA FOUND";
    }
    else 
    {
         node *entry = head3[position];       //CREATING NODE POINTER     
         
         //WHILE LOOP TO SEARCH UNTIL DATA IS FOUND OR NO DATA IS LEFT
         while (entry != NULL && key != key2) 
         {
               key2 = keychanger(entry->data);
               entry = entry->next;
         }
         if (entry == NULL)
         {      
               cout<<"NO DATA FOUND";
         }
         else
         {
               removedata(key);                //CALLING FUNCTION TO REMOVE DATA
               adddata(key3,newdata);          //CALLING FUNCTION TO ADD DATA
         }
    }
    
}


//MEMBER FUNCTION TO DISPLAY 
int usb::displaydata()
{    
    cout<<endl<<"ALL THE DATA IN USB: "<<endl;
    //FOR LOOP
    for(int i = 0;i < size;++i)
    {
            node *temp = head3[i];
            while (temp->next != NULL)         //LOOP TO TRAVERSE TILL LAST NODE
            {
                   cout<<temp->data<<endl;       
                   temp = temp->next;
            }
    }
}
