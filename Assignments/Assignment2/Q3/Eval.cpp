/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author:
 * Date:
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using namespace std;

// Remove after completing
// while T is not EOF or the operator stack is non empty

//     if T is a number:
//         push T to the number stack; get the next token
		
//     else if T is a left parenthesis:
//         push T to the operator stack; get the next token
		
//     else if T is a right parenthesis:
//         if the top of the operator stack is a left parenthesis:
//             pop it from the operator stack; get the next token:
//         else:
//             pop the top two numbers and the top operator
//             perform the operation
//             push the result to the number stack
	
//     else if T is +, - or EOF:
//         if the operator stack is nonempty and the top is one 
//                                             of +, -, *, /:
//             pop the top two numbers and the top operator
//             perform the operation
//             push the result to the number stack
//         else:
//             push T to the operator stack; get the next token

//     else if T is * or /:
//         if the operator stack is nonempty and the top is one of *, /:
//             pop the top two numbers and the top operator
//             perform the operation
//             push the result to the number stack
//         else:
//             push T to the operator stack; get the next token



// For testing purposes, function prototypes
int evalauteOperation(Token &operand1, Token &operand2, Token &operation);


int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token



    // //  Token  //
// class Token {
//     public:
//         TokenType tt;
//         string text;
//         int val;
// };


    // WIP 
    t = S.getnext();

    // while T is not EOF or the operator stack is non empty
    while (t.tt != eof || !opstack.isEmpty())
    {
        // if T is a number:
        // push T to the number stack; get the next token
        if (t.tt == integer)
        {
            numstack.push(t);
            t = S.getnext();
        }
        // else if T is a left parenthesis:
        // push T to the operator stack; get the next token
        else if (t.tt == lptok)
        {
            opstack.push(t);
            t = S.getnext();
        }
        // else if T is a right parenthesis:
        else if (t.tt == rptok)
        {
            // if the top of the operator stack is a left parenthesis:
            if (opstack.peek().tt == lptok)
            {
                // pop it from the operator stack; get the next token:
                // Check this
                opstack.pop();
                t = S.getnext();
            }
            else
            {
                // pop the top two numbers and the top operator
                Token operand1 = numstack.pop(); 
                Token operand2 = numstack.pop();
                Token operation = opstack.pop();

                // perform the operation
                Token result = 

                // push the result to the number stack
                
            }
        }        



        

    }
    

    t = S.getnext();

    // Pretty printer coding demo.  Please remove before coding
    while (t.tt != eof) {
        if (t.tt == integer || t.tt == lptok || t.tt == rptok) {
            cout << t;
        } else if (t.tt == pltok || t.tt == mitok || 
                   t.tt == asttok || t.tt == slashtok) {
            cout << ' ' << t << ' ';
        }

        t = S.getnext();
    }

    cout << endl;
    // End pretty printer coding demo.

    return 0;
}

// Assumes that all tokens have valid values
int evalauteOperation(Token &operand1, Token &operand2, Token &operation)
{

    // typedef enum { pltok, mitok, asttok, slashtok, lptok, rptok, integer, errtok, eof }

    TokenType symbol = operation.tt;
    
    switch (symbol)
    {
        case 0:
            return operand1.val + operand2.val;

        case 1:
            return operand1.val - operand2.val;

        case 2:
            return operand1.val * operand2.val;

        case 3:
            return operand1.val / operand2.val;
        
        default:
            return 0;
    }
}
