#include "big_tree.h"
#include "internal.h"
#include <stdlib.h>
#include <stdio.h>

Tree createTree(compare cmp){
        Tree tree = {cmp,NULL};
        return tree;
}
TreeNode* createTreeNode(void *data,TreeNode *parent){
        TreeNode *treeNode = malloc(sizeof(TreeNode));
        treeNode->data = data;
        treeNode->parent = parent;
        treeNode->child = create_link_list();
        return treeNode;
}
TreeNode* getTreeNode(DLL* list,void* dataToFind,compare cmp){
        Iterator it = getIterator(list);
        TreeNode *tn;
        while(it.hasNext(&it)){
                tn = (TreeNode*)it.next(&it);
                if(cmp(tn->data,dataToFind) == 0){
                        return tn;
                }
                if(tn->child->head)
                        return getTreeNode(tn->child,dataToFind,cmp);
        }
        return NULL;
}
int insert_node(Tree* tree, void* parent_data, void* child_data) {
        TreeNode* root = (TreeNode*)tree->root;
        TreeNode* nodeToInsert, *parentNode;
        if(tree->root == NULL){
                tree->root = createTreeNode(child_data,NULL);
                return 1;
        }
        if(tree->cmp(root->data,parent_data) == 0){
                parentNode = root;
                nodeToInsert = createTreeNode(child_data,parentNode);
                insert_new_node(root->child,0,nodeToInsert);
                return 1;
        }
        parentNode = getTreeNode(root->child,parent_data,tree->cmp);
        nodeToInsert = createTreeNode(child_data,parentNode);
        insert_new_node(parentNode->child,0,nodeToInsert);
        return 1;
}
void* treeNext(Iterator *it){
        TreeNode *node;
        Iterator treeIterator = getIterator(it->list);
        treeIterator.position = it->position;
        node = treeIterator.next(&treeIterator);
        it->position++;
        return node->data;
}
Iterator get_children(Tree* tree, void *parent) {
        TreeNode *temp,*root = (TreeNode*)tree->root;
        Iterator it;
        if(tree->cmp(root->data,parent) == 0)
                temp = root;
        else
                temp = getTreeNode(root->child, parent, tree->cmp);
        it = getIterator(temp->child);
        it.next = &treeNext;
        return it;
}
int deleteNodeFromTree(Tree *tree, void *data){
        TreeNode *root = (TreeNode*)tree->root;
        TreeNode *tn,*parent;
        Iterator it;
        tn = getTreeNode(root->child,data,tree->cmp);
        if(0 == tn->child->size){
                parent = tn->parent;
                it = getIterator(parent->child);
                while(it.hasNext(&it)){
                        if(tree->cmp(data,it.next(&it)))
                                break;
                }
                delete_node(parent->child,it.position - 1);
                return 1;
        }
        return 0;
}
int search(Tree* tree,void* element_for_search){
    TreeNode* root = (TreeNode*)(tree->root);
    if(getTreeNode(root->child,element_for_search,tree->cmp) != NULL)
        return 1;
    return 0;
}