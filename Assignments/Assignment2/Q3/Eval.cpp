/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Steven Wong
 * Date: October 2022
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
Token &evalauteOperation(Stack<Token> &numstack, Stack<Token> &opstack);
// Token &evalauteOperation(Token &operand1, Token &operand2, Token &operation);


int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token

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
                // perform the operation
                // push the result to the number stack   
                numstack.push(evalauteOperation(numstack, opstack));
            }
        }        
        // else if T is +, - or EOF:
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof)
        {
            // if the operator stack is nonempty and the top is one of +, -, *, /:
            if (!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                // pop the top two numbers and the top operator
                // perform the operation
                // push the result to the number stack
                numstack.push(evalauteOperation(numstack, opstack));
            }
            // push T to the operator stack; get the next token
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
        // else if T is * or /:
        else if (t.tt == asttok || t.tt == slashtok)
        {
            // if the operator stack is nonempty and the top is one of *, /:
            if (!opstack.isEmpty() && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                // pop the top two numbers and the top operator
                // perform the operation
                // push the result to the number stack
                numstack.push(evalauteOperation(numstack, opstack));
            }
            else
            {
                // push T to the operator stack; get the next token
                opstack.push(t);
                t = S.getnext();
            }
        }
    }

    cout << numstack.peek().val << endl;
    return 0;
}



// Assume client code is right for now
Token &evalauteOperation(Stack<Token> &numstack, Stack<Token> &opstack)
{
    Token operand1 = numstack.pop(); 
    Token operand2 = numstack.pop();
    Token operation = opstack.pop();

    Token *newToken = new Token();
    TokenType symbol = operation.tt;
    
    switch (symbol)
    {
        // Addition
        case pltok:
            newToken->tt = integer;
            newToken->val = operand2.val + operand1.val;
            break;
        // Minus
        case mitok:
            newToken->tt = integer;
            newToken->val = operand2.val - operand1.val;
            break;
        // Multiplication
        case asttok:
            newToken->tt = integer;
            newToken->val = operand2.val * operand1.val;
            break;
        // Integer Division w/ Truncation
        case slashtok:
            newToken->tt = integer;
            newToken->val = operand2.val / operand1.val;
            break;
        // Default case for any errors or special situations
        default:
            newToken->tt = errtok;
            newToken->val = 0;
            break;
    }
    Token &result = *newToken;
    return result;
}