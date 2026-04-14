/* *************************************************
*  Name: Brandon Crenshaw
*  Assignment: #3 - Tree Traversal for Parenthesized Math Expressions
*  Purpose: To reinforce and demonstrate a sufficient understanding of
*           of the tree ADT.
************************************************* */

#include "expTree.h"                                            // iostream is already included here

void preOrd(const std::string& expr){
    // Much of this is copied from tree stuff but is stored strings instead of trees/nodes
    std::stack<std::string> preStack;
    std::stack<char> operatorStack;
    std::string subexp;

    for (char entry : expr) {
        if (isspace(entry) || entry == '(') continue;
        if (isalnum(entry)) preStack.push(std::string(1, entry));               // string function converts char -> string
        else if (entry == '+' || entry == '-' || entry == '*' || entry == '/') operatorStack.push(entry);

        else if (entry == ')') {
            if (operatorStack.empty() || preStack.size() < 2) continue;

            std::string oprtr = std::string(1,operatorStack.top());          // pulling from stacks and building subexpressions
            operatorStack.pop();
            std::string right = preStack.top();
            preStack.pop();
            std::string left = preStack.top();
            preStack.pop();
            subexp = oprtr + " " + left + " " + right + " ";
            preStack.push(subexp);                                          // Very [censored] important
        }
    }
    std::cout << subexp << std::endl;
}

void postOrd(const std::string& expr){
    /* A repeat of the preorder function*/
    std::stack<std::string> postStack;
    std::stack<char> operatorStack;
    std::string subexp;

    for (char entry : expr) {
        if (isspace(entry) || entry == '(') continue;
        if (isalnum(entry)) postStack.push(std::string(1, entry));
        else if (entry == '+' || entry == '-' || entry == '*' || entry == '/') operatorStack.push(entry);

        else if (entry == ')') {
            if (operatorStack.empty() || postStack.size() < 2) continue;

            std::string oprtr = std::string(1,operatorStack.top());
            operatorStack.pop();
            std::string right = postStack.top();
            postStack.pop();
            std::string left = postStack.top();
            postStack.pop();
            subexp = left + " " + right + " " + oprtr;           // the order needed to be "post"
            postStack.push(subexp);

        }
    }
    std::cout << subexp << std::endl;
}



int main(void) {
    std::string expr = "((A+B)/(C-D))";                         // from instructions
    std::cout << "Input string: " << expr << std::endl;

    ExpTree<char> tree;
    tree.storeExpression(expr);

    std::cout << "Pre-order: ";
    tree.preorderPrint(tree.treeRoot);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    tree.postorderPrint(tree.treeRoot);
    std::cout << "\n" << std::endl;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    /* Expression take from HW#3 */
    std::string expr2 = "(((5+2)*(2-1))/(((2+9)+((7-2)-1))*8))";    // parenthese added after '/' because it wasn't fully parenthesize.
    std::cout << "Input string: " << expr2 << std::endl;

    ExpTree<char> tree2;
    tree2.storeExpression(expr2);

    std::cout << "Pre-order: ";
    tree2.preorderPrint(tree2.treeRoot);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    tree2.postorderPrint(tree2.treeRoot);
    std::cout << "\n" << std::endl;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    /* Somehting I just made up */
    std::string expr3 = "(((((((1+2)+3)+4)+5)+6)+7)+8)";
    std::cout << "Input string: " << expr3 << std::endl;

    ExpTree<char> tree3;
    tree3.storeExpression(expr3);

    std::cout << "Pre-order: ";
    tree3.preorderPrint(tree3.treeRoot);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    tree3.postorderPrint(tree3.treeRoot);
    std::cout << "\n" << std::endl;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    /* Stack Stuff */
    std::cout << "Stack-based print outs:"<< std::endl;
    preOrd(expr3);
    postOrd(expr3);

    return 0;
}
