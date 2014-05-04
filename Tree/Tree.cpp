#include "iostream"
#include "list"
#include"clocale"
#include "conio.h"
using namespace std;
/**
@brief �����- ���� ������
*/
class TreeNode
{   
	friend class Tree;
	/** @brief ������ ���������� �� ������� ����*/
	list<TreeNode*> children; 
	/** @brief �������� ����*/
    int value;
	/**
	@brief ����� ����
	@detailed ������������ ������ ������� ������
	*/
	int nomer;
    public:
	/**
	@brief �����������
	@detailed �������� ������ �� ��������� value
	*/
	TreeNode(int value);
	/**
	@brief �����������
	@detailed �������� ������ �� ��������� � ������� ������ ����
	*/
	TreeNode();
};
  TreeNode::TreeNode(int value)
  {
	   TreeNode::value=value;
  }
  TreeNode::TreeNode()
  {
	   value=0;
	   nomer=0;
  }
  
/**
@brief �����-  ������
*/
class Tree
{   
	/**	@brief ��������� �� ������ ������*/
	TreeNode* root;
	/**@brief ����� ����� � ������*/
	int TreeNode_num;
    public:
	/**	
	@brief �����������
	@detailed ������ "������" ������
	*/
    Tree();
	/**	@brief ����� ��������� ����� ����� ������*/
	int getTreeNode_num() const;
	/**	@brief �������� ����� ������ �� ��������� value  */
	void CreateRoot(int value);
	/**	
	@brief � ���� � ������� nomer c������� ��� �� ��������� value 
	@detailed ����� ���� �������������� ��� ������ ������ ������
	*/
    void CreateChild( TreeNode &T ,int nomer, int value);
	/**	
	@brief  ����� ������ � ������ ������� � ��������� �����
	*/
	void preorderNumeration(TreeNode& T, int& i);
	/**	
	@brief  ����� ������ � ������ ������� � ������ �������� �����
	*/
	void preorderPrint (TreeNode& T);
	/**	
	@brief ����� ������ � ������������ ������� � ������ �������� �����
	*/
	void inorderPrint(TreeNode &T);
	/**	
	@brief  ����� ������ � �������� ������� � ������ �������� �����
	*/
	void postorderPrint(TreeNode &T);
	/**	
	@brief ��������� ����� ������ 
	*/
	TreeNode& getroot() const;
};
Tree::Tree()
{
	root=0;
	TreeNode_num=0;
}
int Tree::getTreeNode_num() const
{
	return TreeNode_num;
}
TreeNode& Tree::getroot() const
{
	return(*root);
}
void Tree::CreateRoot(int value)
{
	TreeNode *R;
	R=new (TreeNode);
	R->value=value;
	R->children.clear();
	root=R;
	TreeNode_num++;
}
void Tree:: CreateChild(TreeNode &T, int nomer,int value)
{   
	if(T.nomer==nomer)
	{
	TreeNode* A;
	A=new(TreeNode);
	A->value=value;
	T.children.push_back(A);
	TreeNode_num++;
	return;
	}
      for(list<TreeNode*>::iterator Iterator=T.children.begin();Iterator!=T.children.end();++Iterator)
  {
	 CreateChild(**Iterator,  nomer, value);
  }
}

void Tree ::preorderNumeration(TreeNode &T, int &i)
{

  T.nomer=i;
  i++;
  for(list<TreeNode*>::iterator Iterator=T.children.begin();Iterator!=T.children.end();++Iterator)
  {
	  preorderNumeration(**Iterator,i);
  }
}

void Tree ::preorderPrint(TreeNode &T)
{
  cout<<T.value<<" ";
  for(list<TreeNode*>::iterator Iterator=T.children.begin();Iterator!=T.children.end();++Iterator)
  {
	  preorderPrint(**Iterator);
  }
}
void Tree ::inorderPrint(TreeNode &T)
{
   if(T.children.empty())
   {    
	   cout<<T.value<<" ";
   }
   else
   {   
	   inorderPrint(**T.children.begin());
	   cout<<T.value<<" ";
	   list<TreeNode*>::iterator Iterator=T.children.begin();
	   Iterator++;
	   for(;Iterator!=T.children.end();++Iterator)
	   {   
		   inorderPrint(**Iterator);   
	   }
   }
}

void Tree ::postorderPrint(TreeNode &T)
{   
	if(!T.children.empty())
	{
    for(list<TreeNode*>::iterator Iterator=T.children.begin()++;Iterator!=T.children.end();++Iterator)
	{
		   postorderPrint(**Iterator);   
	}
	}
	cout<<T.value<<" ";
}
/**	
@brief ������� main()
@detailed �������� ������ � n ������ � �������� ��������� 
�� ����� � ������, ������������ � �������� �������
*/
void main()
{   
	setlocale(LC_ALL,"russian");
	Tree T;

	int j,n,nomer,value;
	cout<<"������� ����� ����� � ������\n";
	cin>>n;
	cout<<"������� �������� �����\n";
	cin>>value;
	T.CreateRoot(value);
	for (int i=1;i<n;i++)
	{  
		j=1;
		T.preorderNumeration(T.getroot(), j);
		cout<<"������� ����� ����, � �������� ����� �������� ����\n";
		cin>>nomer;
		while (nomer<=0 || nomer>T.getTreeNode_num())
		{
			cout<<"���� � ������� "<<nomer<<" ���������� � ������ ";
		    cin>>nomer;
		}
		cout<<"������� �������� ������������ ����\n";
		cin>>value;
 		T.CreateChild( T.getroot() , nomer, value);
	}
	cout<<"������ �������� ����� ��� ������ � ������ ������� \n";
	T.preorderPrint(T.getroot());
	cout<<"\n������ �������� ����� ��� ������ � c����������� ������� \n";
    T.inorderPrint(T.getroot());
	cout<<"\n������ �������� ����� ��� ������ � �������� ������� \n";
    T.postorderPrint(T.getroot());
	getch();
}
