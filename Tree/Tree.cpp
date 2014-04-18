#include "iostream"
#include "list"
using namespace std;
class TreeElement
{   
	friend class Tree;
    protected:
	list<TreeElement*> children; 
	TreeElement* parent;
    int value;
	int nomer;
	
    public:
	TreeElement(int Data);
	TreeElement();
};
  TreeElement::TreeElement(int value)
  {
	  this->value=value;
  }
  

class Tree
{
	TreeElement* root;
    public:
    Tree();
	int GetTreeElementValue(int i);
	void CreateRoot(int value);
    void CreateChild(TreeElement &A, int nomer);
};
Tree::Tree()
{
	root=0;
}
void Tree::CreateRoot(int value)
{
	TreeElement R(value);
	R.parent=0;
}