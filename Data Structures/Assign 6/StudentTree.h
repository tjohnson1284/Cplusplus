#include <iostream>
#include <afxwin.h>
#include <fstream>
#include <vector>

using namespace std;

#define new DEBUG_NEW

class Student
{
	friend ostream& operator<< (ostream& os, const vector<Student>& s);
	friend ostream& operator<< (ostream& os, const Student& s);
private: 
	string m_name, m_major;
	int m_age, m_test[3], m_id;
	
public:
	Student(string name, int age, string major, int tests[], int id);
	//initializer
	Student();
	//default constructor
	bool readFromFile(ifstream &fin);
	//precondition: none
	//postcondition: Either
	//1) Student successfully read, true returned
	//2) No student, false returned.

	bool readFromKeyboard();
	//precondition: none
	//postcondition: Either
	//1) Student successfully read, true returned
	//2) No student, false returned.

	void writeToFile(ofstream &fout) const;
	//precondition: existing list
	//postcondition: list printed to file

	void writeToScreen() const;
	//precondition: existing list
	//postcondition: list printed to screen

	int getkey() const;
	void setkey(int id);
	int getage() const;
	int getave()const;
	string getmajor() const;
	
};



struct TreeNode
{
	Student m_student;
	
	TreeNode* m_left;
	TreeNode* m_right;
	TreeNode(const Student &s, TreeNode* left = 0, TreeNode* right = 0);

};

ostream& operator<<(ostream& os, const TreeNode& tree);

class Tree 
{
	friend ostream& operator<< (ostream &os, const Tree &tree);
	
public:
	Tree();
	Tree(const Tree &tree2);
	~Tree();
	
	bool readfromfile(const string& filename);
	bool IsEmpty() const; 
	//precondition: valid list
	//postcondition: Either
	//1) returns true if the list is empty
	//2) returns false if the list has any data
	int Size() const;
	//precondition: valid list
	//postcondition: size of list returned
	bool Insert(const Student& student);
	//precondition: valid list, valid student data given
	//postcondition:Either
	// 1) Inserts a student into the list in order of ID, returns true
	// 2) If student already is in the list, returns false
	bool Delete(int id);
	//precondition: valid list, valid id given
	//postcondition: Either
	// 1) Finds the student, student deleted, true returned
	// 2) Does not find the student, false returned
	bool Lookup(Student &student) const;
	//Precondition: Valid list, valid student data given
	//Postcondition: Either
	// 1) Finds the student, returns their data and returns true.
	// 2) Does not find the student, false returned
	void Print () const;
	//Precondition: valid list
	//Postcondition: prints the tree
	Tree& operator = (const Tree& tree2);
	//Precondition: valid list in tree2
	//Postcondition: Tree 2 copied into base tree
	void GetMaxAve(int& ave) ;
	void GivenMaxAve(const int& ave, vector<Student>& s);
	void GivenMajor(const string& major, vector<Student>& s);
	void AllPeopMaxAve(int& ave, vector<Student>& s);


private: 
	TreeNode* m_root;

	//helper
	bool Insert(const Student &student, TreeNode *&pTree);
	//precondition: valid list, valid student data given
	//postcondition:Either
	// 1) Inserts a student into the list in order of ID, returns true
	// 2) If student already is in the list, returns false
	
	int Size(TreeNode *pTree) const;
	//precondition: valid list
	//postcondition: size of list returned

	void Print(ostream &os, TreeNode* pTree) const;
	//Precondition: valid list
	//Postcondition: prints the tree

	bool Lookup(Student &student, TreeNode *pTree) const;
	//Precondition: Valid list, valid student data given
	//Postcondition: Either
	// 1) Finds the student, returns their data and returns true.
	// 2) Does not find the student, false returned

	bool Delete(int id, TreeNode *&pTree);
	//precondition: valid list, valid id given
	//postcondition: Either
	// 1) Finds the student, student deleted, true returned
	// 2) Does not find the student, false returned

	void DeleteNode(TreeNode *&pTree);

	void GetPredecessor(Student &stud, TreeNode* pTree);
	void Print(TreeNode *pTree) const;
	//Precondition: Valid list, valid student data given
	//Postcondition: Either
	// 1) Finds the student, returns their data and returns true.
	// 2) Does not find the student, false returned
	void Clear();
	void Clear(TreeNode *pTree);
	//Precondition: Valid list
	//Postcondition: list deleted
	void Copy(const Tree &list2);
	//Precondition: Valid list
	//Postcondition: copies list2 into tree 1
	void Copy(TreeNode *&pThis, TreeNode *pTree2);
	//Precondition: Valid list
	//Postcondition: copies list2 into tree 1
	void GetMaxAve(int& ave, TreeNode* pTree);
	void GivenMaxAve(const int& ave, TreeNode*& pTree, vector<Student>& s);
	void GivenMajor(const string& major, TreeNode*& pTree, vector<Student>& s);
	void AllPeopMaxAve(int& ave, vector<Student>& s, TreeNode*& pTree);
};