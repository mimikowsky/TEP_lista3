#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic()
{
	pc_root = new CNodeDynamic();
}
CTreeDynamic::~CTreeDynamic()
{
	delete pc_root;
}
CNodeDynamic* CTreeDynamic::pcGetRoot()
{
	return(pc_root); 
}
void CTreeDynamic::vPrintTree() 
{
	pc_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode)
{
	if (pcNewChildNode->getParentNode() == NULL)
	{
		return false;
	}

	CNodeDynamic* oldParentOfChild = pcNewChildNode->getParentNode();
	std::vector<CNodeDynamic*> oldParentChildren = oldParentOfChild->getChildrenVector();
	
	CNodeDynamic* node;

	for (int i = 0; i < oldParentChildren.size(); i++)
	{
		node = oldParentChildren.at(i);

		if (node == pcNewChildNode)
			oldParentChildren.erase(oldParentChildren.begin()+i);
	}

	oldParentOfChild->setChildrenVector(oldParentChildren);

	pcParentNode->vAddNewChild(pcNewChildNode);

	return true;
}