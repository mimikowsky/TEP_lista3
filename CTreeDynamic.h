#pragma once
#include "CNodeDynamic.h"

class CTreeDynamic
{
private:
	CNodeDynamic* pc_root;
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic* pcGetRoot();
	void vPrintTree();
	bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode);
};