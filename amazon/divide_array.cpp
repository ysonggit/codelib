/* http://www.careercup.com/question?id=5021311902416896

(Bar Raiser Round) 
Divide the array(+ve and -ve numbers) into two parts such that the average of both the parts is equal. 

Input: 
[1 7 15 29 11 9] 

Output: 
[15 9 1 7 11 29] 

Explanation: 
The average of first two elements is (15+9)/2 = 12, average of remaining elements is (1+7 +11 +29)/4 = 12

Sum_{A[0]...A[k]} = Sum_{A[0] ... A[k-1]} + A[k]
 */

#include <iostream>

using namespace std;

