#include "CNodeStatic.h"
#include <iostream>

CNodeStatic::CNodeStatic() 
{
	i_val = 0; 
	pc_parent_node = NULL;
}

CNodeStatic::~CNodeStatic()
{

}


void CNodeStatic::vSetValue(int iNewVal)
{ 
	i_val = iNewVal; 
}

int CNodeStatic::iGetChildrenNumber() 
{ 
	return(v_children.size());
}

void CNodeStatic::vAddNewChild()
{
	CNodeStatic newChild;
	newChild.pc_parent_node = this;
	v_children.push_back(newChild);
}

void CNodeStatic::vAddNewChild(CNodeStatic* newChild)
{
	newChild->vSetParentNode(this);
	v_children.push_back(*newChild);
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset)
{
	if (iChildOffset < v_children.size() && iChildOffset >= 0)
	{
		return &(v_children.at(iChildOffset));
	}
	else return NULL;
}

void CNodeStatic::vPrint()
{
	std::cout << "Value: " << i_val << "\n";
}

void CNodeStatic::vPrintAllBelow()
{
	vPrint();
	for (int i = 0; i < v_children.size(); i++)
	{
		v_children.at(i).vPrintAllBelow();
	}
}

void CNodeStatic::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)
	{
		pc_parent_node->vPrintUp();
	}
}
CNodeStatic* CNodeStatic::getParentNode()
{
	return pc_parent_node;
}

std::vector<CNodeStatic>* CNodeStatic::getChildrenVector()
{
	return &v_children;
}

void CNodeStatic::vSetParentNode(CNodeStatic* pcParent)
{
	pc_parent_node = pcParent;
}