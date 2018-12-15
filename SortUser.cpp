#include <stdio.h>
#include<iostream>
#include <stdlib.h>

typedef struct User
{
	int id;
	char nickname[51];
	int karma;
} User;


void addKarma(User* user, int amount)
{
	static int callCnt = 0;
	callCnt++;
	user->karma += amount;
	printf("%d\n", callCnt);
}
int cmpkarma(const void * pa,const void * pb)
{
	
	User* a = (User*)pa;
	User* b = (User*)pb;
	return a->karma - b->karma; 

}

int cmpname(const void * pa,const void * pb)
{
	User* a = (User*)pa;
	User* b = (User*)pb;
	return *a->nickname - *b->nickname;
}
int main()
{
	 
	User user1 = {1, "nicky", 10};
	User user2 = {2, "arain1", 15};
	User user3 = {3,"aran", 4};
	User mas[3]={user1,user2,user3};
	std::cout<<"Sort Karma\n";
	qsort(&mas[0],3,sizeof(User),cmpkarma);
	
	for (int i=0;i<3;i++)
	{	
		std::cout<<mas[i].karma<<"\t";
		std::cout<<mas[i].id<<"\t";
		std::cout<<mas[i].nickname<<"\t"<<"\n";
	}
	std::cout<<"\nSort Nickname\n";	
	qsort(&mas[0],3,sizeof(User),cmpname);
	
	for (int i=0;i<3;i++)
	{	
		std::cout<<mas[i].karma<<"\t";
		std::cout<<mas[i].id<<"\t";
		std::cout<<mas[i].nickname<<"\t"<<"\n";
	}
}


