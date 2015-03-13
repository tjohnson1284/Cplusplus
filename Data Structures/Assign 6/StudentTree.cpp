#include "StudentTree.h"
#include <string>

using namespace std;

TreeNode::TreeNode(const Student& s, TreeNode* left, TreeNode* right)
: m_student(s), m_left(left), m_right(right)
{}

Student::Student(string name, int age, string major, int tests[], int id)
:m_name(name), m_age(age), m_major(major), m_id(id)
{
	m_test[0] = tests[0];
	m_test[1] = tests[1];
	m_test[2] = tests[2];
}
Student::Student()
{
	m_name = "";
	m_age = -1;
	m_major = ""; 
	m_test[0] = -1;
	m_test[1] = -1;
	m_test[2] = -1;
	m_id = -1;
}
bool Student::readFromFile(ifstream &fin)
{
	
	getline(fin, m_name);
	if(m_name == "***")
	{
		return false;
	}
	getline(fin, m_major);
	fin >> m_age;
	fin >> m_test[0]; fin >> m_test[1]; fin >> m_test[2];
	fin >> m_id;
	fin.ignore(100, '\n');
	return true;
}
bool Student::readFromKeyboard()
{
	getline(cin, m_name);
	if(m_name == "***")
	{
		return false;
	}
	getline(cin, m_major);
	cin >> m_age;
	cin >> m_test[0]; cin >> m_test[1]; cin >> m_test[2];
	cin >> m_id;
	return true;
}
void Student::writeToFile(ofstream &fout) const
{
	fout << m_name;
	fout << m_major;
	fout << m_age;
	fout << m_test[0]; fout << m_test[1]; fout << m_test[2];
	fout << m_id;
}
void Student::writeToScreen() const
{
	cout << m_name;
	cout << m_major;
	cout << m_age;
	cout << m_test[0]; cout << m_test[1]; cout << m_test[2];
	cout << m_id;
}
int Student::getkey() const
{
	return m_id;
}
void Student::setkey(int id)
{
	m_id = id;
}
int Student::getage() const
{
	return m_age;
}
int Student::getave() const
{
	int temp;
	temp = (m_test[0] + m_test[1] + m_test[2]) / 3;
	return temp;
}
string Student::getmajor() const
{
	return m_major;
}
ostream& operator<< (ostream& os, const Student& s)
{
	

	if( os == cout )
	{
		os << "Name: " << s.m_name << endl;
		os << "Major: "<< s.m_major << endl;
		os << "Age: " << s.m_age << endl;
		os << "Test Scores: " << s.m_test[0] << " " << s.m_test[1] << " " << s.m_test[2] << endl;
		os << "Id: " << s.m_id << endl;
	}
	else
	{
		os << s.m_name <<endl;
		os << s.m_major <<endl;
		os << s.m_age << endl;
		os << s.m_test[0] << " " << s.m_test[1] << " " << s.m_test[2] << endl;
		os << s.m_id;
	}
	return os;
}
ostream& operator<< (ostream& os, const vector<Student>& s) 
{
	int temp = s.size();
	for( int i= 0; i < temp; i++)
		cout << s[i];
	return os;
}

Tree::Tree()
: m_root(0)
{}

ostream& operator<< (ostream& os, const TreeNode& n) // cout << n;
{
	os << n.m_student << endl;
	return os;
}
bool Tree::readfromfile(const string& filename)
{
	if(Size() > 0)
	{
		Clear();
		m_root = 0;
	}
	ifstream fin; 
	Student s;

	fin.open(filename.c_str());

	if (fin.fail())
	{  
		cout << "No file found. " << endl ;
		cin.get();
		return false;
	}

	while(s.readFromFile(fin))
	{
		Insert(s);
	}
	return true;
}
bool Tree::IsEmpty() const
{
	return m_root == 0;
}

int Tree::Size() const	// public
{
	return Size(m_root);
}

int Tree::Size(TreeNode* pTree) const	// private
{
	if( pTree == 0 )
		return 0;
	return 1 + Size(pTree->m_left) + Size(pTree->m_right);
}

bool Tree::Insert(const Student& s)	// public
{
	return Insert(s,m_root);
}

bool Tree::Insert(const Student& s, TreeNode*& pTree)	// private
{
	if( pTree == 0 )
	{
		pTree = new TreeNode(s);
	}
	else if( s.getkey() < pTree->m_student.getkey() )	// go left
	{
		Insert(s, pTree->m_left );
	}
	else 	// go right
	{
		Insert(s, pTree->m_right );
	}
	return true;

}

ostream& operator<< (ostream& os, const Tree& tree)
{
	tree.Print( os , tree.m_root );
	return os;
}
void Tree::Print() const
{
	Print(cout, m_root);
}
void Tree::Print(ostream& os, TreeNode* pTree) const
{
	if( pTree == 0 )
		return;
	// print entire left tree
	Print(os,pTree->m_left);

	os << *pTree; // prints current node's data

	// print entire right tree
	Print(os,pTree->m_right);
}



bool Tree::Lookup(Student& s) const	// public 
{
	return Lookup(s,m_root);
}

bool Tree::Lookup(Student& s, TreeNode* pTree) const	// private
{
	
	if( pTree == 0 )		// base case one
	{
		return false;
	}
	else if( s.getkey() == pTree->m_student.getkey() )	// base case
	{
		//p.m_age = pTree->m_person.m_age;
		s = pTree->m_student;	// Better
		return true;
	}
	else if( s.getkey() < pTree->m_student.getkey())	// go left
	{
		return Lookup(s , pTree->m_left );
	}
	else 	// go right
	{
		return Lookup(s , pTree->m_right );
	}
}


Tree& Tree::operator=(const Tree &list2)
{
	if( this == &list2 )
		return *this;
	Clear();
	Copy(list2);
	return *this;
}
Tree::Tree( const Tree& t2)
{
	Copy(t2);
}

void Tree::Clear()
{
	Clear(m_root);
}

void Tree::Clear(TreeNode* pTree)
{
	if( pTree == 0 )
		return;
	Clear(pTree->m_left);
	Clear(pTree->m_right);
	delete pTree;
}

void Tree::Copy(const Tree& list2)
{
	
	Copy(m_root, list2.m_root);
}

void Tree::Copy(TreeNode *&pThis, TreeNode *pTree2)
{
	if(pTree2 == 0) 
		return;
	pThis = new TreeNode(pTree2->m_student, pTree2->m_left, pTree2->m_right);
	Copy(pThis->m_left, pTree2->m_left);
	Copy(pThis->m_right, pTree2->m_right);

}
bool Tree::Delete(int id) // public
{
	return Delete(id,m_root);
}
bool Tree::Delete(int id, TreeNode*& pTree)
{
	TreeNode* temp;
	int count = 0;

	count ++;
	if(count%2 == 0)
	{
		temp = pTree;
	}
	// base case
	if( pTree == 0 )
		return false;
	else if( id == pTree->m_student.getkey())
	{
		DeleteNode(pTree); // hard part
		return true;
	}
	// recursive cases:
	else if( id > pTree->m_student.getkey() )
		return Delete(id , pTree->m_right);
	else //if( name < pTree->m_name )
		return Delete(id , pTree->m_left);
}
void Tree::DeleteNode(TreeNode*& pTree)
{
	TreeNode* temp = pTree;
	if( pTree->m_left == 0 )
	{
		pTree = pTree->m_right;
		delete temp;
	}
	else if( pTree->m_right == 0 )
	{
		pTree = pTree->m_left;
		delete temp;
	}
	else if( pTree->m_left != 0 && pTree->m_right != 0 )
	{
		Student s;
		int id;
		GetPredecessor(s, pTree->m_left);
		pTree->m_student = s;
		id = s.getkey();
		Delete(id,pTree->m_left); // ???
	}
}
void Tree::GetPredecessor(Student &s, TreeNode* pTree)
{
	while(pTree->m_right != 0 )
		pTree = pTree->m_right;

	s = pTree->m_student;	
}

Tree::~Tree()
{
	Clear();
}
void Tree::GetMaxAve(int& ave)
{
	GetMaxAve(ave, m_root);
}
void Tree::GetMaxAve(int& ave,TreeNode* pTree)
{
	if( pTree == 0 )
		return;
	
	if (ave < pTree->m_student.getave())
	{
		ave = pTree->m_student.getave();
	}
	GetMaxAve(ave,pTree->m_left);
	GetMaxAve(ave,pTree->m_right);
	
}
void Tree::GivenMaxAve(const int& ave, vector<Student>& s)
{
	GivenMaxAve(ave, m_root, s);
	return;
	
}
void Tree::GivenMaxAve(const int& ave, TreeNode*& pTree, vector<Student>& s) 
{

	if( pTree == 0 )
		return;
	
	if (ave == pTree->m_student.getave())
	{
		s.push_back( pTree->m_student );
	}
	GivenMaxAve(ave,pTree->m_left, s);
	GivenMaxAve(ave,pTree->m_right, s);
	
	
}
void Tree::GivenMajor(const string& major, vector<Student>& s)
{
	GivenMajor(major, m_root, s);
	return;
}
void Tree::GivenMajor(const string& major, TreeNode*& pTree, vector<Student>& s)
{
	if( pTree == 0 )
		return;
	
	if (major == pTree->m_student.getmajor())
	{
		s.push_back( pTree->m_student );
	}
	GivenMajor(major,pTree->m_left, s);
	GivenMajor(major,pTree->m_right, s);
}
void Tree::AllPeopMaxAve(int& ave, vector<Student>& s)
{
	
	AllPeopMaxAve(ave, s, m_root);
	return;
}
void Tree::AllPeopMaxAve(int& ave, vector<Student>& s, TreeNode*& pTree)
{
	if( pTree == 0 )
		return;
	if ( ave < pTree->m_student.getave())
	{
		s.clear();
		s.push_back( pTree->m_student );
		ave = pTree->m_student.getave();
	}
	else if (ave == pTree->m_student.getave())
	{
		s.push_back( pTree->m_student );
	}
	AllPeopMaxAve(ave, s ,pTree->m_left);
	AllPeopMaxAve(ave, s ,pTree->m_right);
}