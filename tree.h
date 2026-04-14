/* *************************************************
*  Name: Brandon Crenshaw
*  Assignment: #3 - Tree Traversal for Parenthesized Math Expressions
*  Purpose: To reinforce and demonstrate a sufficient understanding of
*           of the tree ADT.
************************************************* */

#define INITIAL_HT -1

#ifndef TREENODE_H
#define TREENODE_H

template <typename T>
class TreeNode {
    public:
        bool isRoot;
        bool isExternal;

        TreeNode<T> * parent;
        TreeNode<T> * left;
        TreeNode<T> * right;
        T data;

        //Constructor
        TreeNode<T>() : parent(nullptr),left(nullptr),right(nullptr) {}
};
#endif // TREENODE_H ---------------------------------------



#ifndef TREE_ADT_H
#define TREE_ADT_H

template <typename T>
class Tree : public TreeNode<T> {
    private:
        int node_cnt;
        int max_depth;

        void deleteTree(){
            while(node_cnt > 0) remove(treeRoot, treeRoot->data);
        }

    public:
        // CONSTRUCTORS and DESTRUCTOR ----------------------------------------
        TreeNode<T> * treeRoot;
        Tree() : node_cnt(0), max_depth(INITIAL_HT),treeRoot(nullptr) { }
        ~Tree() { deleteTree(); }

        // ACESSORS -----------------------------------------------------------
        T root() const {
            if(treeRoot != nullptr) return treeRoot->data;
            return T();
        }

        int height() const { return max_depth; }

        int size() const { return node_cnt; }

        bool empty() const { return node_cnt == 0; }

        TreeNode<T> * search(TreeNode<T> * start, T element) const {
            TreeNode<T> * currNode = start;
            while (currNode != nullptr){
                if ( element == currNode->data ) {
                    return currNode;
                } else if( element < currNode->data ) {
                    currNode = currNode->left;
                } else {
                    currNode = currNode->right;
                }                                                       // end of left-right conditionals
            }                                                           //end of while loop
            return nullptr;
        }

        // MUTATORS -----------------------------------------------------------


        bool addLeft(TreeNode<T> * curNode, T element) {                   // element will have to be updated to use keys
            bool isAdded = false;
            if(curNode->left == nullptr) {
                TreeNode<T> * inNode = new TreeNode<T>;                     //create new node and update its info
                inNode->data = element;
                inNode->parent = curNode;
                curNode->left = inNode;
                isAdded = true;
                node_cnt++;
            }
            return isAdded;
        }


        bool addRight(TreeNode<T> * curNode, T element) {                   // element will have to be updated to use keys
            bool isAdded = false;
            if(curNode->left == nullptr) {
                TreeNode<T> * inNode = new TreeNode<T>;                     //create new node and update its info
                inNode->data = element;
                inNode->parent = curNode;
                curNode->right = inNode;
                isAdded = true;
                node_cnt++;
            }
            return isAdded;
        }


        bool remove(TreeNode<T> * start, T element) {
            /* removes nodes from the tree */
            TreeNode<T> * currNode = search(start, element);
            TreeNode<T> * promotedNode = nullptr;

            if (currNode == nullptr) {
                return false;
                }
            // FOR NODES with NO CHILDREN
            if(currNode->left == nullptr && currNode->right == nullptr) {
                if ( currNode->parent == nullptr) {                         // node is root node
                    treeRoot = nullptr;
                    delete currNode;
                    currNode = nullptr;
                } else if (currNode->parent->left == currNode) {            // node is external left child
                    currNode->parent->left = nullptr;
                    delete currNode;
                    currNode = nullptr;
                } else {                                                    // node is external right child
                    currNode->parent->right = nullptr;
                    delete currNode;
                    currNode = nullptr;
                }                                                           // closes "root-left-right" conditional
            }                                                               // closes "no children" block
            // For NODES with ONE CHILD
            else if (currNode->right == nullptr) {                          // node has left child only
                if( currNode->parent == nullptr ) {
                    treeRoot = currNode->left;
                    delete currNode;
                    currNode = nullptr;
                } else if ( currNode->parent->left == currNode ) {
                    currNode->parent->left = currNode->left;
                    delete currNode;
                    currNode = nullptr;
                } else {
                    currNode->parent->right = currNode->left;
                    delete currNode;
                    currNode = nullptr;
                }
            }
            else if (currNode->left == nullptr) {                           // node has right child only
                if( currNode->parent == nullptr ) {
                    treeRoot = currNode->right;
                } else if ( currNode->parent->left == currNode ) {
                    currNode->parent->left = currNode->right;
                } else {
                    currNode->parent->right = currNode->right;
                }
            }
            // For NODES with TWO CHILDREN
            else {
                promotedNode = currNode->right;                             // select the immediate right child
                while (promotedNode->left != nullptr) {                     // then selects thr left-most leaf
                    promotedNode = promotedNode->left;
                }
                T promotedData = promotedNode->data;                        // copies data (not key); So copy both when updated.
                remove(treeRoot,promotedNode->data);                        // removes the node with 0 or 1 child
                node_cnt++;
                currNode->data = promotedData;
            }
            node_cnt--;
            return true;
        }

};

#endif // TREE_ADT_H

