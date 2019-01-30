/**********************************************************************
 *  Pattern Recognition readme.txt template
 **********************************************************************/

Name:  Chan Nok Hin       
Login:  20349103          
Hours to complete assignment (optional): 30



/**********************************************************************
 *  Step 1.  Explain briefly how you implemented brute force.
 *           What method(s) did you add to the Point data type?
 **********************************************************************/
Brute force is implemented through 4 nested for loop to create all possible
subsets of 4 elements. Then check that whether the elements inside each subset
are collinear.
check_collinear(): check whether 4 points are collinear(same slope)

/**********************************************************************
 *  Step 2.  Explain briefly how you implemented the sorting solution.
 *           Did you sort by angle, slope, or something else?
 *           What method(s) did you add to the Point data type?
 *           What steps did you do to print a minimal representation?
 **********************************************************************/
 Sorting solution is implemented through two nested for loop. Outer loop
 select the origin. Inner loop check whether collinear through measure the
 angle to the origin
setAngle(): measure the angle from the selected origin using arctan
getFlag(): flag to determine whether the point had been a element of
          a collinear subset

/**********************************************************************
 *  Empirical    Fill in the table below with actual running times in
 *  Analysis     seconds when reasonable (say 180 seconds or less).
 *               You can round to the nearest tenth of a second.
 **********************************************************************/

      N       brute       sorting
---------------------------------
     10       0.00        0.00
     20       0.00        0.00
     40       0.00        0.00
     80       0.01        0.00
    100       0.02        0.00
    150       0.04        0.01
    200       0.08        0.01
    400       0.33        0.04
   1000       3.64        0.20
   2000       28.78       0.54
   4000       >180        2.15
  10000       >180        14.09


/**********************************************************************
 *  Estimate how long it would take to solve an instance of size
 *  N = 1,000,000 for each of the two algorithms using your computer.
 **********************************************************************/
Brute: 1.28*10^13 s 
Sorting: 173700 s



/**********************************************************************
 *  Theoretical   Give the worst-case running time of your programs
 *  Analysis      as a function of N. Justify your answer briefly.
 **********************************************************************/
Brute: O(N^4)
As there is 4 nested for loop, so the worst case is  O(N^4)

Sorting: O(N^3)
As quick sort is used and everypoint will be set as an origin. The 
worst-case is O(N^3)

/**********************************************************************
 *  Known bugs / limitations. For example, if your program prints
 *  out different representations of the same line segment when there
 *  are 5 or more points on a line segment, indicate that here.
 **********************************************************************/
As the brute force check every subsets which cotain 4 elements 
are collinear, it will print out more lines when there are 5 or more points on a line segment


/**********************************************************************
 *  List whatever help (if any) that you received. Be specific with
 *  the names of lab TAs, classmates, or course staff members.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Although writing the algorithm is not hard, integration of qt , algorithm,
point class and deque structure is the most difficult. A lot of things need 
to be improved and corrected forth and back

/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/

