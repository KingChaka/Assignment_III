/* *************************************************
*  Name: Brandon Crenshaw
*  Assignment: #3 - Tree Traversal for Parenthesized Math Expressions
*  Purpose: To reinforce and demonstrate a sufficient understanding of
*           of the tree ADT.
*
************************************************* */

#ifndef TREENODE_H
#define TREENODE_H

template <typename T>
class TreeNode {                           // basic node class

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
        Tree() : treeRoot(nullptr), node_cnt(0), max_depth(0) { }
        // Tree(Tree<T>& lObj) : root(NULL)  { copyList(&lObj); }  // copy constructor
        // ~Tree() { deleteList(); }

        // METHODS =============================================================

        //ACESSORS
        int size() const { return node_cnt; }
        bool empty() { return node_cnt == 0; }
        int height() { return max_depth; }
        TreeNode<T> root() {return treeRoot;}


        // MUTATORS

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

