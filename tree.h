/* *************************************************
*  Name: Brandon Crenshaw
*  Assignment: #3 - Tree Traversal for Parenthesized Math Expressions
*  Purpose: To reinforce and demonstrate a sufficient understanding of
*           of the tree ADT.
*
************************************************* */
#define INITIAL_HT -1

#ifndef TREENODE_H
#define TREENODE_H

template <typename T>
class TreeNode {                           // basic node class for a binary tree

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
#endif // TREENODE_H


#ifndef TREE_ADT_H
#define TREE_ADT_H

template <typename T>
class Tree : public TreeNode<T> {
    private:
        TreeNode<T> * treeRoot;
        int node_cnt;
        int max_depth;

    public:
        // CONSTRUCTORS and DESTRUCTOR
        Tree() : treeRoot(nullptr), node_cnt(0), max_depth(INITIAL_HT) { }
        // Tree(Tree<T>& lObj) : root(NULL)  { copyList(&lObj); }  // copy constructor
        // ~Tree() { deleteList(); }

        // METHODS =========================================
        //ACESSORS
        TreeNode<T>* root() const {return treeRoot;}
        int height() const { return max_depth; }
        int size() const { return node_cnt; }
        bool empty() const { return node_cnt == 0; }

        // MUTATORS
        void insert(TreeNode<T> * inNode, T element) {      // element will have to be updated to use keys
            inNode->data = element;
            
            // FOR EMPTY TREE
            if(empty()){ root = inNode; }                   // ends the empty tree condition
            
            // FOR NON-EMPTY TREE
            else {                                          
                TreeNode<T> currNode = inNode;
                while(currNode != nullptr) {                // to  travel down to a leaf node.
                    if (inNode->data < currNode->data) {
                        if(currNode->left == nullptr) {
                            currNode->left = inNode;
                            currNode = nullptr; }
                        else { currNode = currNode->left; } // closes "move/add to left" operation.
                    } else {
                        if(currNode->right == nullptr) {
                            currNode->right = inNode;
                            currNode = nullptr; }
                        else { currNode = currNode->right; } // closes "move/add to right" operation.
                    }                       // closes left or right decision
                }                           // closes the while loop
            }                               // closes the root / non-root split
            node_cnt++;
        }                                   // closes the method

        /*
        // TRAVERSAL
        int depth (Tree arbor, TreeNode<T> inputNode){
            if (currentNode.isRoot()) {
                return 0;
            } else {
                return 1 + depth(arbor, inputNode.parent());
            }
        }


        bool insertElement(T * inData){
            TreeNode<T> * currNode = root;

            // Make a new node
            TreeNode<T> * newNode = new TreeNode<T>;
            newNode->data = *inData;

            //Add to the tail
            if(head == NULL) head = newNode;
            else {
                while(currNode->next != NULL){                  // to the end of the linked list.
                    currNode = currNode->next;
                }
            currNode->next = newNode;                           // appends to the end of the linked list.
            }
            return true;
        }



        bool removeElement(){                                                     // overridde for delete all that doesn't write node data
            bool wasRead = false;
            if (head == NULL){}
            else {
                wasRead = true;
                SNode<T> * currNode = head;
                if(head->next == NULL){ head = NULL;}
                else { head = head->next; }
                delete currNode;
                currNode = NULL;
            }
            return wasRead;
        }


        bool nextElm(T * inData){                                                   // reports what data is in the head node
            bool wasRead = false;
            if(head == NULL){ }
            else{ *inData = head->data; }
            return wasRead;}

        void deleteList(){                                                          // removes all nodes starting from the head end
            while( head != NULL ) { removefromFront();}
        }

        void copyList(LinerSinglyLinkedList * targetLL) {                           // copies each node one-by-one into another linked-list
            SNode<T> * currNode = targetLL->head;
            T dataCpy;
            do{
                dataCpy = currNode->data;
                insertElmAtEnd(&dataCpy);
                currNode = currNode->next;
            } while( currNode != NULL );
        */
};

#endif // TREE_ADT_H

