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
        SNode() : left(NULL), right(NULL) {}
        TreeNode<T> * parent;
		TreeNode<T> * left;					// Node is for an Arithmetic Epression (Binary) tree
		TreeNode<T> * right;
        T data;
};
#endif // TREENODE_H


#ifndef TREE_ADT_H
#define TREE_ADT_H

template <typename T>
class Tree : public TreeNode<T> {
    private:
        TreeNode<T> * root;
		int size;

    public:
        // CONSTRUCTORS and DESTRUCTOR
        Tree() : head(NULL) { }
        Tree(Tree<T>& lObj) : root(NULL)  { copyList(&lObj); }  // copy constructor
        ~Tree() { deleteList(); }

        // METHODS
        bool empty(){ return size == NULL; }                                  // simple getter method

        bool addElmAtFront(T *inData){                                              // create node make it new head
            bool isAdded = true;
            SNode<T> * newHead = new SNode<T>;
            newHead->data = *inData;
            newHead->next = head;
            head = newHead;
            return isAdded;
        }

        bool insertElmAtEnd(T * inData){                                            // create node, traverse to tail, add there
            SNode<T> * currNode = head;

            // Make a new node
            SNode<T> * newNode = new SNode<T>;
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


        bool removefromFront(T * inData){                                           // make 2nd node the head, delete previous head
            bool wasRead = false;
            if (head == NULL){ }
            else {
                wasRead = true;
                SNode<T> * currNode = head;
                *inData = currNode->data;
                head = currNode->next;
                delete currNode;
                currNode = NULL;
            }
            return wasRead;
        }

        bool removefromFront(){                                                     // overridde for delete all that doesn't write node data
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
        }
};

#endif // TREE_ADT_H

