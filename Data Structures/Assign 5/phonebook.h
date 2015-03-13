// phonebook.h
//----------------------------

#include <iostream>
#include <afxwin.h>

using namespace std;

#define new DEBUG_NEW

struct phonebookitem  {
	string m_name, m_phone;	// key
	int m_age;

	
	phonebookitem* m_next;
	phonebookitem(const string& name, int age, const string &m_phone, phonebookitem* next = NULL);
	
};

ostream& operator<< (ostream&, const phonebookitem&);

class ULnkList  {
	friend ostream& operator<< (ostream&, const ULnkList&);
    //friend phonebookitem GetPeopleWithGivenAge(int age);
public:
	ULnkList();
	// copy ctor
	ULnkList(const ULnkList& existingList ); // 4
	//Precondition: valid list
	//Postcondition: list copied.
	~ULnkList();	// 2
	//Precondition: valid list.
	//Postcondition: List deleted

	bool IsEmpty() const;
	//Precondition: Valid list
	//Postcondition: Either 
	// 1. Returns true if the list is empty.
	// 2. Returns false if the list is not empty.
	int Size() const;
	//Precondition: Valid list
	//Postcondition: Returns the size of said list.
	bool Insert(const string& name, int age, const string &phone);
	//Precondition: Valid list to store in, Valid data given
	//Postcondition: if the name doesn't exist, Information stored in the phonebook, true returned. 
	// Else, if name exists, no action taken, false returned.
	bool Delete(const string& name);	// 3
	//Precondition: Valid list, valid name given
	//Postcondition: Name is found, node deleted, true returned.
	// Name is not found, no action, false returned.
	bool Lookup(const string& name, int& age, string &m_phone) const;		// 1
	//Precondition: Valid List, valid data given.
	//Postcondition: Name is found, true returned.
	// Name is not found, false is returned.
	bool unique(const string &name) const;
	//Precondition: valid list, valid data given
	//Postcondition: name is found, false returned.
	//name is not found, true returned.
	int getmaxage() const;
	//Precondition: valid list
	//Postcondition: returns the age the of the oldest person in the list.
	// returns 0 if the list is empty.
	ULnkList GetPeopleWithGivenAge(int age);
	//precondition: valid list, valid age given
	//postcondition: returns a phonebook with all people of a given age.
	ULnkList GetAllPeopleWithMaxAge();
	//precondition: valid list
	//postcondition: returns a phonebook with all oldest people.
	ULnkList& operator =(const ULnkList& list2);			// 5
	//Precondition: Valid lists
	//Postcondition: List 2 stored in List 1
	

private:

	phonebookitem* m_head;   
	int m_num;    
	

	// helper functions:
	void Clear();	// both 6
	//Precondition: Valid list.
	//Postcondition: List deleted
	void Clear2();
	//Precondition: Valid list
	//Postcondition: List deleted, dummy node saved
	void Copy(const ULnkList& list2);
	//Precondition: Both lists are valid.
	//Postcondition: List copied from given phone book to the current phone book.
};






