#pragma once
#include <vector>
class CNodeStatic
{
private:
	std::vector<CNodeStatic> v_children;
	CNodeStatic* pc_parent_node;
	int i_val;

public:
	CNodeStatic();
	~CNodeStatic();
	void vSetValue(int iNewValue);
	int iGetChildrenNumber();
	void vAddNewChild();
	void vAddNewChild(CNodeStatic* newChild);
	CNodeStatic* pcGetChild(int iChildOffset);
	void vPrint();
	void vPrintAllBelow();
	void vPrintUp();
	CNodeStatic* getParentNode();
	std::vector<CNodeStatic>* getChildrenVector();
	void vSetParentNode(CNodeStatic* pcParent);
};