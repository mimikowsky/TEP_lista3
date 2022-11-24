#pragma once
#include "CNodeStatic.h"

class CTreeStatic
{
private:
	CNodeStatic c_root;

public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic* pcGetRoot();
	void vPrintTree();
	bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);
};