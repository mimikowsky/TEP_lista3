#pragma once
#include <vector>


class CNodeDynamic
{
private:
	std::vector<CNodeDynamic*> v_children;
	CNodeDynamic* pc_parent_node;
	int i_val;

public:
	CNodeDynamic();
	~CNodeDynamic();
	void vSetValue(int iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	CNodeDynamic* pcGetChild(int iChildOffset);
	void vPrint();
	void vPrintAllBelow();
	CNodeDynamic* getParentNode();
	std::vector<CNodeDynamic*> getChildrenVector();
	void vAddNewChild(CNodeDynamic* newChild);
	void vSetParentNode(CNodeDynamic* pcParent);
	void setChildrenVector(std::vector<CNodeDynamic*> v_newChildren);
};