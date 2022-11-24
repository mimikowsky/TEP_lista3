#include <iostream>
#include "CNodeStatic.h"
#include "CTreeStatic.h"
#include "CTreeDynamic.h"

void v_tree_test();
void v_treeStatic_test();
void v_treeDynamic_test();
void v_subTreeDynamicMethod_test();
void v_subTreeDynamicMethod_testFailure();
void v_nodeDynamic_test();
void v_subTreeStaticMethod_test();
void v_subTreeStaticMethod_testFailure();

int main()
{
    //v_tree_test();
    //v_treeStatic_test();
    //std::cout << " \n";
    //v_treeDynamic_test();
    //v_subTreeDynamicMethod_test();
    //v_subTreeDynamicMethod_testFailure();
    //v_nodeDynamic_test();
    //v_subTreeStaticMethod_test();
    v_subTreeStaticMethod_testFailure();

}


void v_addNodesToDynamicTree(CTreeDynamic* c_tree1, CTreeDynamic* c_tree2)
{
    CNodeDynamic* c_root1 = (*c_tree1).pcGetRoot();

    c_root1->vAddNewChild();
    c_root1->vAddNewChild();
    c_root1->vAddNewChild();

    c_root1->pcGetChild(0)->vSetValue(1);
    c_root1->pcGetChild(1)->vSetValue(2);
    c_root1->pcGetChild(2)->vSetValue(3);

    c_root1->pcGetChild(2)->vAddNewChild();
    c_root1->pcGetChild(2)->pcGetChild(0)->vSetValue(4);


    CNodeDynamic* c_root2 = (*c_tree2).pcGetRoot();

    c_root2->vSetValue(50);

    c_root2->vAddNewChild();
    c_root2->vAddNewChild();

    c_root2->pcGetChild(0)->vSetValue(54);
    c_root2->pcGetChild(1)->vSetValue(55);

    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->vAddNewChild();

    c_root2->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_root2->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

    c_root2->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);
}

void v_addNodesToStaticTree(CTreeStatic* c_tree1, CTreeStatic* c_tree2)
{
    CNodeStatic* c_root1 = (*c_tree1).pcGetRoot();

    c_root1->vAddNewChild();
    c_root1->vAddNewChild();
    c_root1->vAddNewChild();

    c_root1->pcGetChild(0)->vSetValue(1);
    c_root1->pcGetChild(1)->vSetValue(2);
    c_root1->pcGetChild(2)->vSetValue(3);

    c_root1->pcGetChild(2)->vAddNewChild();
    c_root1->pcGetChild(2)->pcGetChild(0)->vSetValue(4);


    CNodeStatic* c_root2 = (*c_tree2).pcGetRoot();

    c_root2->vSetValue(50);

    c_root2->vAddNewChild();
    c_root2->vAddNewChild();

    c_root2->pcGetChild(0)->vSetValue(54);
    c_root2->pcGetChild(1)->vSetValue(55);

    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->vAddNewChild();

    c_root2->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_root2->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

    c_root2->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);
}

void v_tree_test()
{
    CNodeStatic c_root;
    c_root.vAddNewChild();
    c_root.vAddNewChild();

    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);

    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();

    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);

    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();

    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_root.vPrint();
    c_root.vPrintAllBelow();

    std::cout << "vPrintUp test \n";
    c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
}

void v_treeStatic_test()
{
    CTreeStatic c_tree;

    CNodeStatic *c_root = c_tree.pcGetRoot();

    c_root->vAddNewChild();
    c_root->vAddNewChild();

    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);

    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();

    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();

    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_tree.vPrintTree();

}

void v_treeDynamic_test()
{
    CTreeDynamic *c_tree;
    c_tree = new CTreeDynamic();

    CNodeDynamic* c_root = c_tree->pcGetRoot();

    c_root->vAddNewChild();
    c_root->vAddNewChild();

    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);

    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();

    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();

    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_tree->vPrintTree();

    delete c_root;
}

void v_subTreeDynamicMethod_test()
{

    CTreeDynamic c_tree1;
    CTreeDynamic c_tree2;
    v_addNodesToDynamicTree(&c_tree1, &c_tree2);

    std::cout << "Tree 1: \n";
    c_tree1.vPrintTree();
    std::cout << "Tree 2: \n";
    c_tree2.vPrintTree();

    CNodeDynamic* c_root1 = c_tree1.pcGetRoot();
    CNodeDynamic* c_root2 = c_tree2.pcGetRoot();

    std::cout << "---\n";
    c_tree1.bMoveSubtree(c_root1->pcGetChild(2), c_root2->pcGetChild(0));
    std::cout << "Now Tree1 looks like that: \n";
    c_tree1.vPrintTree();
    std::cout << "Tree2 looks like that: \n";
    c_tree2.vPrintTree();

}

void v_subTreeDynamicMethod_testFailure()
{
    CTreeDynamic c_tree1;
    CTreeDynamic c_tree2;
    v_addNodesToDynamicTree(&c_tree1, &c_tree2);

    std::cout << "Tree 1: \n";
    c_tree1.vPrintTree();
    std::cout << "Tree 2: \n";
    c_tree2.vPrintTree();

    CNodeDynamic* c_root1 = c_tree1.pcGetRoot();
    CNodeDynamic* c_root2 = c_tree2.pcGetRoot();

    std::cout << "-SubTreeMethod Test Failure (as a Child we give a root, not a subtree)-\n";
    c_tree1.bMoveSubtree(c_root1->pcGetChild(2), c_root2);
    std::cout << "Now Tree1 looks like that: (should not change) \n";
    c_tree1.vPrintTree();
    std::cout << "Tree2 looks like that: (should not change) \n";
    c_tree2.vPrintTree();
}

void v_subTreeStaticMethod_test()
{
    CTreeStatic c_tree1;
    CTreeStatic c_tree2;
    v_addNodesToStaticTree(&c_tree1, &c_tree2);

    std::cout << "Tree 1: \n";
    c_tree1.vPrintTree();
    std::cout << "Tree 2: \n";
    c_tree2.vPrintTree();

    CNodeStatic* c_root1 = c_tree1.pcGetRoot();
    CNodeStatic* c_root2 = c_tree2.pcGetRoot();

    std::cout << "---\n";
    c_tree1.bMoveSubtree(c_root1->pcGetChild(2), c_root2->pcGetChild(0));
    std::cout << "Now Tree1 looks like that: \n";
    c_tree1.vPrintTree();
    std::cout << "Tree2 looks like that: \n";
    c_tree2.vPrintTree();
}

void v_subTreeStaticMethod_testFailure()
{
    CTreeStatic c_tree1;
    CTreeStatic c_tree2;
    v_addNodesToStaticTree(&c_tree1, &c_tree2);

    std::cout << "Tree 1: \n";
    c_tree1.vPrintTree();
    std::cout << "Tree 2: \n";
    c_tree2.vPrintTree();

    CNodeStatic* c_root1 = c_tree1.pcGetRoot();
    CNodeStatic* c_root2 = c_tree2.pcGetRoot();
  

    std::cout << "-SubTreeMethod Test Failure (as a Child we give a root, not a subtree)-\n";
    c_tree1.bMoveSubtree(c_root1->pcGetChild(2), c_root2);
    std::cout << "Now Tree1 looks like that: (should not change) \n";
    c_tree1.vPrintTree();
    std::cout << "Tree2 looks like that: (should not change) \n";
    c_tree2.vPrintTree();
}

void v_nodeDynamic_test()
{
    CNodeDynamic* c_root;
    c_root = new CNodeDynamic();

    c_root->vAddNewChild();
    c_root->vAddNewChild();

    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);

    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();

    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();

    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_root->vPrint();
    c_root->vPrintAllBelow();
    delete c_root;
}