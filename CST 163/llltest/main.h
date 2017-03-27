#include<iostream>
using namespace std;

class info
{
	public:
		info();
		~info();
		int name(char []);
		int age(int);
		int birthdate(char []);
		int country(char []);
		int copy(info &);
		int display();
		int check(char []);
	private:
		char *name;
		int age;
		char * birthdate;	
		char *country;
};

struct node
{
	info prof;
	node *next;
};

class profile
{
	public:
		profile();
		~profile();
		int add(info &);
		int delete(char []);
		int edit(char []);
		int remove();
		int display(info &);
	private:
		node *head;
};

