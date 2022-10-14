/*
* Description: Evaluation of infix expressions using two Stacks.
*
* Author:
* Date:
*/

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using namespace std;



int main()
{
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token

    t = S.getnext();

    while (t.tt != eof || !opstack.isEmpty())
    {
        if (t.tt == integer)
        {
            numstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == lptok)
        {
            opstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == rptok)
        {
            if (opstack.peek().tt == lptok)
            {
                opstack.pop();
                t = S.getnext();
            }
            else
            {
                int a = numstack.peek().val;
                numstack.pop();
                int b = numstack.peek().val;
                numstack.pop();
                int answer = 0;
                if (opstack.peek().tt == pltok)
                    answer = b + a;
                if (opstack.peek().tt == mitok)
                    answer = b - a;
                if (opstack.peek().tt == asttok)
                    answer = b * a;
                if (opstack.peek().tt == slashtok)
                    answer = b / a;
                opstack.pop();
                Token temp;
                temp.tt = integer;
                temp.val = answer;
                temp.text = "";
                numstack.push(temp);
            }
        }
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof)
        {
            if (!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                int a = numstack.peek().val;
                numstack.pop();
                int b = numstack.peek().val;
                numstack.pop();
                int answer = 0;
                if (opstack.peek().tt == pltok)
                    answer = b + a;
                if (opstack.peek().tt == mitok)
                    answer = b - a;
                if (opstack.peek().tt == asttok)
                    answer = b * a;
                if (opstack.peek().tt == slashtok)
                    answer = b / a;
                opstack.pop();
                Token temp;
                temp.tt = integer;
                temp.val = answer;
                numstack.push(temp);
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
        else if (t.tt == asttok || t.tt == slashtok)
        {
            if (!opstack.isEmpty() && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                int a = numstack.peek().val;
                numstack.pop();
                int b = numstack.peek().val;
                numstack.pop();
                int answer = 0;
                if (opstack.peek().tt == asttok)
                    answer = b * a;
                if (opstack.peek().tt == slashtok)
                    answer = b / a;
                opstack.pop();
                Token temp;
                temp.tt = integer;
                temp.val = answer;
                numstack.push(temp);
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
    }


    cout << numstack.peek().val << endl;

    return 0;
}
