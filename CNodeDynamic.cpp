#include "CNodeDynamic.h"
#include <iostream>

CNodeDynamic::CNodeDynamic() 
{ 
	i_val = 0; 
	pc_parent_node = NULL;
}
CNodeDynamic::~CNodeDynamic()
{
	for (int i = 0; i < v_children.size(); i++)
	{
		delete v_children.at(i);
	}
}
void CNodeDynamic::vSetValue(int iNewVal)
{ 
	i_val = iNewVal;
}
int CNodeDynamic::iGetChildrenNumber()
{ 
	return(v_children.size()); 
}
void CNodeDynamic::vAddNewChild()
{
	CNodeDynamic* c_newChild;
	c_newChild = new CNodeDynamic;
	c_newChild->pc_parent_node = this;
	v_children.push_back(c_newChild);
}
CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (iChildOffset < v_children.size() && iChildOffset >= 0)
	{
		return v_children.at(iChildOffset);
	}
	else return NULL;
}
void CNodeDynamic::vPrint()
{ 
	std::cout << "Value " << i_val << "\n";
}
void CNodeDynamic::vPrintAllBelow()
{
	vPrint();
	for (int i = 0; i < v_children.size(); i++)
	{
		v_children.at(i)->vPrintAllBelow();
	}
}
CNodeDynamic* CNodeDynamic::getParentNode()
{
	return pc_parent_node;
}

std::vector<CNodeDynamic*> CNodeDynamic::getChildrenVector()
{
	return v_children;
}

void CNodeDynamic::vAddNewChild(CNodeDynamic* newChild)
{
	newChild->vSetParentNode(this);
	v_children.push_back(newChild);
}
void CNodeDynamic::vSetParentNode(CNodeDynamic* pcParent)
{
	pc_parent_node = pcParent;
}
void CNodeDynamic::setChildrenVector(std::vector<CNodeDynamic*> v_newChildren)
{
	v_children = v_newChildren;
}