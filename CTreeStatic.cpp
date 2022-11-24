#include "CTreeStatic.h"

CTreeStatic::CTreeStatic()
{

}
CTreeStatic::~CTreeStatic()
{

}
CNodeStatic* CTreeStatic::pcGetRoot()
{ 
	return (&c_root);
}

void CTreeStatic::vPrintTree()
{
	c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode)
{
	if (pcNewChildNode->getParentNode() == NULL)
	{
		return false;
	}

	CNodeStatic* oldParentOfChild = pcNewChildNode->getParentNode();
	std::vector<CNodeStatic>* oldParentChildren = oldParentOfChild->getChildrenVector();

	CNodeStatic* node;

	for (int i = 0; i < oldParentChildren->size(); i++)
	{
		node = &((*oldParentChildren).at(i));

		if (node == pcNewChildNode)
			(*oldParentChildren).erase(((*oldParentChildren).begin() + i));
	}

	pcParentNode->vAddNewChild(pcNewChildNode);

	return true;
}