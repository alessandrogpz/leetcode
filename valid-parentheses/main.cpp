/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/

#include "functions.h"

int main()
{

    std::string myString = "Hello World";
    std::string pString1 = "([)]";
    std::string pString2 = "{[]}";
    std::string pString3 = "[([]])";

    //iterateString(pString);
    std::cout << "False: " << isValid(pString1) << std::endl;
    std::cout << "True: " << isValid(pString2) << std::endl;
    std::cout << "False: " << isValid(pString3) << std::endl;

    return 0;
}