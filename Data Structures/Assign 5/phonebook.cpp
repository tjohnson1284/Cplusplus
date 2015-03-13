// UnSortedLnkList.cpp
//----------------------------
#include "phonebook.h"
#include <iostream>
#include <string>
using namespace std;

phonebookitem::phonebookitem(const string& name, int age, const string &phone, phonebookitem* next)
:m_name(name), m_age(age), m_phone(phone),m_next(next)
{}


ostream& operator<< (ostream& os, const phonebookitem& n)	// cout << n;
{
	os << "Name: " << n.m_name << "\tAge: " << n.m_age << "\tPhone: " << n.m_phone << endl;
	return os;
}

ULnkList::ULnkList()
: m_head(new phonebookitem("",-99,"",0)), m_num(0)
{}
//
ULnkList::ULnkList(const ULnkList& existingList )			// List l1(existingList);
//: m_head(new phonebookitem("",-99,NULL)), m_num(existingList.m_num)
{
	Copy(existingList);
}

bool ULnkList::IsEmpty() const
{
	return m_num == 0;
	// return m_head->m_next == NULL;
}

int ULnkList::Size() const
{
	return m_num;
}
//
bool ULnkList::Insert(const string& name, int age, const string &phone)
{
	phonebookitem *p = m_head->m_next;
	phonebookitem *tp = m_head;
	
	if( p == 0)
	{
		tp->m_next = new phonebookitem(name,age,phone,0);
		m_num++;
		return true;
	}
	while (p != 0)
	{
		if(p->m_name == name)
		{
			return false;
		}
		if(p->m_name > name)
		{
			break;
		}
		tp = tp->m_next;
		p = p->m_next;
	}
		tp->m_next = new phonebookitem(name,age,phone,tp->m_next);
		m_num++;
		return true;
	
    //return false;
}
int ULnkList::getmaxage() const
{
	phonebookitem *p = m_head->m_next;
	int temp = 0;

	if(Size() != 0)
	{
		while(p != 0)
		{
			if(p->m_age > temp)
			{
				temp = p->m_age;
			}
			p=p->m_next;
		}
		return temp;
	}
	return 0;
}
ostream& operator<< (ostream& os, const ULnkList& list) 
{
	phonebookitem *p = list.m_head->m_next; // 
	while( p != 0 )
	{
		cout << *p << endl;
		p = p->m_next;
	}



	return os;
}

bool ULnkList::Lookup(const string& name /* in */ , int& age, string &phone /* out */ ) const
{
	
	phonebookitem *p = m_head->m_next;
	while( p != 0)
	{
	
		if( name == p->m_name )
		{
			age = p->m_age;
			phone = p->m_phone;
			return true;
		}
		if(name < p->m_name)
		{
			break;
		}
		p = p->m_next;
	}
	return false;
}
//

bool ULnkList::Delete(const string& name)
{
	phonebookitem *p = m_head->m_next;
	phonebookitem *tp = m_head;			// dummy phonebookitem avoids special cases
	while( p != 0)
	{
		if( name == p->m_name ) 
		{
			// fix pointers
			tp->m_next = p->m_next;
			delete p;
			m_num--;
			return true;
		}
		if(name < p->m_name)
		{
			break;
		}
		// update pointers
		tp = p;
		p = p->m_next;
	}
	return false;
}
//
ULnkList::~ULnkList()
{
	Clear();
}

ULnkList& ULnkList::operator =(const ULnkList& list2)  
{
	if( this != &list2 )
	{
		
		Clear();

		
		Copy(list2);
	}

	return *this;

}

void ULnkList::Clear()
{
	phonebookitem *p = m_head;
	while( p != 0)
	{
		
		phonebookitem *save = p;
		p = p->m_next;
		delete save;
	}
}
void ULnkList::Clear2()
{
	phonebookitem *p = m_head->m_next;
	while( p != 0)
	{
		
		phonebookitem *save = p;
		p = p->m_next;
		delete save;
		m_num--;
	}
	m_head->m_next = 0;
}
	
void ULnkList::Copy(const ULnkList& list2)
{
	phonebookitem *p = list2.m_head->m_next;
	phonebookitem *pThis = m_head = new phonebookitem("",-99,"",0); 
	while( p != 0)
	{
		
		pThis->m_next = new phonebookitem(p->m_name,p->m_age,p->m_phone,0); 
		
		
		p = p->m_next;
		pThis = pThis->m_next;
	}
	m_num = list2.m_num;
}

ULnkList ULnkList::GetPeopleWithGivenAge(int age) 
{
	ULnkList newlist;
	phonebookitem *p = m_head->m_next;
	int count = 0;
	
	while(p!=0)
	{
		if(age == p->m_age)
		{
			newlist.Insert(p->m_name, p->m_age, p->m_phone);
		}
		p = p->m_next;
	}
	return newlist;
}
ULnkList ULnkList::GetAllPeopleWithMaxAge()
{
	ULnkList newlist;
	phonebookitem *p = m_head->m_next;
	
	int age = 0, count = 0;
	
	while(p != 0)
	{
		if(age < p->m_age)
		{
				newlist.Clear2();
				newlist.Insert(p->m_name, p->m_age, p->m_phone);
				age = p->m_age;
		}
		else if(age == p->m_age)
		{
			newlist.Insert(p->m_name, p->m_age, p->m_phone);
		}
		p = p->m_next;

	}
	
	return newlist;
}