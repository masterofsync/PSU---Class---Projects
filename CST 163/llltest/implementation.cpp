#include "main.h"
using namespace std;

info::info()
{
	name = NULL;
	age = NULL;
	birthdate = NULL;
	country = NULL;
}

info::~info()
{
	delete []name;
	delete name;
	
	age = NULL;
	
	delete []birthdate;
	delete birthdate;
	
	delete []country;
	delete country;
}

int info::name(char newname[])
{
	if(name)
		delete []name;	
	
	name = new char[strlen(newname)];
	strcpy(name, newname);
	return 1;
}

int info::age(int newage)
{
	if(age)
		age = 0;
	age = newage;
	return 1;
}

int info::birthdate(char newbirthdate[])
{
	if(birthdate)
		delete [] birthdate;
	birthdate = new char[strlen(birthdate)+1];
	strcpy(birthdate,newbirthdate);
	return 1;
}

int country(char newcountry[]);
{
	if(country)
		delete []country;
	country = new char[strlen(country)+1];
	strcpy(country,newcountry);
	return 1;
}

int info::copy(info &data)
{
	if(!name || !age || !birthdate || !country)
		return 0;
	
	if(data.name)
		delete data.name;
	data.name = new char [strlen(name)+1];
	strcpy(data.name,name);

	if(data.age)
		data.age = 0;
	data.age = age;

	if(data.birthdate)
		delete data.birthdate;
	data.birthdate = new char[strlen(birthdate)];
	strcpy(data.birthdate,birthdate);
	
	if(data.country)
		delete data.country;
	data.country = new char[strlen(country)];
	strcpy(data.country,country);

	return 1;
}

int info::display()
{
	if(!name)
		return 0;
	cout<<"NAME: "<<name<<endl;
	cout<<"Age: "<<age<<endl;
	cout<<"Date of Birth: "<<birthdate<<endl; 
	cout<<"Country: "<<country<<endl;
	return 1;
}

int info::check(char dname[])
{
	if(strcmp(dname,name))
	{
		return 1;
	}
	else
		return 0;
	
}

profile::profile
{
	head = NULL;
}

profile::~profile
{
	delete [] head;	
	delete head;
}

int profile::add(info &data)
{
	if(!head)
	{
		head = new node;
		head->next = NULL;
		data.copy(head->prof);
	}
	if(head)
	{	
		node *temp;
		temp = head;
		
		while(temp->next!=NULL)
		{
			temp = temp->next;
		} 

		temp->next = new node;
		temp = temp->next;
		temp->next = NULL;
		data.copy(temp->prof);
	}
	return 0;
}

int profile::delete(char dname[])
{
	node *temp;
	node *prev;
	
	prev = NULL;
	temp = node;
	
	if(!head)
		return 0;
	if(head)
	{
		while(temp->next!=NULL && temp->prof.check(dname)))
		{	
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		delete []temp;
		delete temp;
	}
}

int profile::edit(char dname[],info &datas)
{
	node *temp;
	temp = head;
	node *prev;
	prev = NULL;
	node *after;
	after = NULL;
	if(!head)
		return 0;
	if(head)
	{
		while(temp->next!=NULL&&temp->prof.check(dname))
		{
			prev = temp;
			temp = temp->next;
		}
		after = temp->next;
		temp->prof.~info();
		temp = NULL;
		temp = add(datas);
		prev->next = temp;
		temp->next = after;
	}
	return 0;
}

int profile::remove()
{
	node *temp;
	while(head!=NULL)
	{
		temp = head;
		head = head->next;
		delete []temp;
		delete temp;
	}
	return 1;
}

int display(info &data)
{
	node *temp;
	temp = head;
	int count = 1;
	
	if(!head)
		return 0;
	
	if(head)
	{
		while(temp->next!=NULL)
		{
			temp = temp->next;
			cout<<"PROFILES:"<<endl<<endl;
			cout<<count<<". "<<temp->prof.display();
			count++;
		}
		return 1;
	}
	return 0;
}
