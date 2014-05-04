#include "iostream"
#include "list"
#include"clocale"
#include "conio.h"
using namespace std;
/**
@brief Класс- узел дерева
*/
class TreeNode
{   
	friend class Tree;
	/** @brief Список указателей на сыновей узла*/
	list<TreeNode*> children; 
	/** @brief Значение узла*/
    int value;
	/**
	@brief Номер узла
	@detailed определяется прямым обходом дерева
	*/
	int nomer;
    public:
	/**
	@brief Конструктор
	@detailed Создаётся объект со значением value
	*/
	TreeNode(int value);
	/**
	@brief Конструктор
	@detailed Создаётся объект со значением и номером раными нулю
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
@brief Класс-  дерево
*/
class Tree
{   
	/**	@brief указатель на корень дерева*/
	TreeNode* root;
	/**@brief Число узлов в дереве*/
	int TreeNode_num;
    public:
	/**	
	@brief конструктор
	@detailed создаёт "пустое" дерево
	*/
    Tree();
	/**	@brief Метод получения числа узлов дерева*/
	int getTreeNode_num() const;
	/**	@brief создание корня дерева со значением value  */
	void CreateRoot(int value);
	/**	
	@brief У узла с номером nomer cоздаётся сын со значением value 
	@detailed поиск узла осущесвтляется при прямом обходе дерева
	*/
    void CreateChild( TreeNode &T ,int nomer, int value);
	/**	
	@brief  обход дерева в прямом порядке и нумерация узлов
	*/
	void preorderNumeration(TreeNode& T, int& i);
	/**	
	@brief  обход дерева в прямом порядке и печать значений узлов
	*/
	void preorderPrint (TreeNode& T);
	/**	
	@brief обход дерева в симметричном порядке и печать значений узлов
	*/
	void inorderPrint(TreeNode &T);
	/**	
	@brief  обход дерева в обратном порядке и печать значений узлов
	*/
	void postorderPrint(TreeNode &T);
	/**	
	@brief получение корня дерева 
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
@brief Функция main()
@detailed Создаётся дерево с n узлами и значения выводятся 
на экран в прямом, симметричном и обратном порядке
*/
void main()
{   
	setlocale(LC_ALL,"russian");
	Tree T;

	int j,n,nomer,value;
	cout<<"Введите число узлов в дереве\n";
	cin>>n;
	cout<<"Введите значение корня\n";
	cin>>value;
	T.CreateRoot(value);
	for (int i=1;i<n;i++)
	{  
		j=1;
		T.preorderNumeration(T.getroot(), j);
		cout<<"Введите номер узла, к которому нужно добавить сына\n";
		cin>>nomer;
		while (nomer<=0 || nomer>T.getTreeNode_num())
		{
			cout<<"узел с номером "<<nomer<<" отсутсвует в дереве ";
		    cin>>nomer;
		}
		cout<<"Введите значение добавляемого узла\n";
		cin>>value;
 		T.CreateChild( T.getroot() , nomer, value);
	}
	cout<<"Печать значений узлов при обходе в прямом порядке \n";
	T.preorderPrint(T.getroot());
	cout<<"\nПечать значений узлов при обходе в cимметричном порядке \n";
    T.inorderPrint(T.getroot());
	cout<<"\nПечать значений узлов при обходе в обратном порядке \n";
    T.postorderPrint(T.getroot());
	getch();
}
