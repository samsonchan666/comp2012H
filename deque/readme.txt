/**********************************************************************
 *  Randomized Queues and Deques
 **********************************************************************/

Name: Chan Nok Hin
ID: 20349103
Login: nhchanaa
Hours to complete assignment (optional): 30 hours


/**********************************************************************
 *  Explain briefly how you implemented the randomized queue and deque.
 *  Which data structure did you choose (array, linked list, etc.)
 *  and why?
 **********************************************************************/
PUT YOUR ANSWER HERE
Deque is implemented through single-linked list for is flexibility to grow organically. It
also enables insert and remove operation can be done more easily.
Randomized queue is implenmented through array for its smoothness to choose a random item 
from the list. Therefore, array could be a better solution.

/**********************************************************************
 *  Briefly describe why any sequence of N randomized queue operations,
 *  starting from an empty randomized queue, takes O(N) time.
 **********************************************************************/
PUT YOUR ANSWER HERE
Enqueue operation just pushes an element onto the input array, which does
not depend on the lengths of either input or output and therefore runs in 
constant time O(1).

For dequeue operation, it involves deleting the element. The position of 
the randomized chosen element is replaced by the last element. 
Then the length of the array is reduced. So, the amortized time is O(1).

For isEmpty, size and sample, it returns a number or items of the array which
involves single operation, so O(1) time is needed.

To conclude, for N randomized queue operations, O(1*N) = O(N) time is needed.

/**********************************************************************
 *  Briefly describe why each Deque operation takes O(1) time.
 **********************************************************************/
PUT YOUR ANSWER HERE
As deque is implemented through linked list, addFirst and addLast simply involve
adding a new node, which takes O(1) time.

For removeFirst and removeLast, a node is removed and front or rear pointer point 
to a new node, so it uses O(1) time.

isEmpty and size basically just return a number and takes O(1) time.

/**********************************************************************
 *  How much memory (in bytes) does your data type use to store N items.
 *  Use tilde notation to simplify your answer. Use the memory requirements
 *  for a "typical machine" given in Lecture. In your analysis, don't include
 *  the memory for the items themselves (as this memory is allocated by
 *  the client and depends on the item type.
 *  For a typical machine, refer to page 11 of 
 *  https://www.cs.princeton.edu/courses/archive/spr10/cos226/lectures/02-14Analysis-2x2.pdf
 **********************************************************************/

RandomizedQueue:
object overhead ~ 8 bytes
int counter ~ 4 bytes
int arr_size ~ 4 bytes
node** node_array ~  4 bytes

Total = 20 bytes

Dequeue:
object overhead ~ 8 bytes
Node* front ~ 4 bytes
Node* rear ~ 4 bytes
int counter ~ 4 bytes

Total = 20 bytes




/**********************************************************************
 *  Known bugs / limitations.
 **********************************************************************/
In the subset, if the subset number is larger than the number of input
elements, floating exception occurrs.

/**********************************************************************
 *  List whatever help (if any) that you received and from whom,
 *  including help from staff members or lab TAs.
 **********************************************************************/
Discussion with friend on the designing and the limitation of the
data structure. 


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
At the beginning, I tried to separate the template header and the 
implementation, and I found a lot of undefined reference occurred. After doing 
a half-day research, just putting them together is the best solution.

/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/
What I learned is not only limit to the way to implement generic programming
or different data structure, but also many other subtle things
such as some template nest class syntax, writing makefile and reasons for
using differet data structure.
