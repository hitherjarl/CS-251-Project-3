


Name Mohamed Imran Mohamed Siddiqe
UIN: 656951860:

-----------------------------------------------

Describe what augmentations to the bst data structures you made to complete the 
project -- i.e., what typedefs did you change and why?
The only changes that I made to the data structures is that I added int Nleft and Nright to keep track of the amounts of nodes in each side of the tree. If you add one element, it increments and if you delete a node, it decrements. I also added int size, max and min to make sure I didn't need to depend on the functions alone for those values.






-----------------------------------------------
Which functions did you need to modify as a result of the augmentations from the previous
question?  
I had to modify the Insert and Remove function aswell as the static version of those functions.








-----------------------------------------------
For each function from the previous question, how did you ensure that the (assymptotic) runtime 
remained the same?
I made sure that the runtime remained the same by not using any loops in the modified functions and to only use recursion.







-----------------------------------------------
For each of the assigned functions, tell us how far you got using the choices 0-5 and
answer the given questions.  


0:  didn't get started
1:  started, but far from working
2:  have implementation but only works for simple cases
3:  finished and I think it works most of the time but not sure the runtime req is met. 
4:  finished and I think it works most of the time and I'm sure my design leads to 
       the correct runtime (even if I still have a few bugs).
5:  finished and confident on correctness and runtime requirements


bst_to_array level of completion:  ____5_______  


-----------------------------------------------
bst_get_ith level of completion:  ______5_____  

    How did you ensure O(h) runtime?

    ANSWER: Depend on recursion and to not traverse through the entire tree.

-----------------------------------------------
bst_get_nearest level of completion:  _____5______  

    How did you ensure O(h) runtime?

    ANSWER: Depend on recursion and to not traverse through the entire tree.
  
-----------------------------------------------
bst_num_geq level of completion:  _____5______  

    How did you ensure O(h) runtime?

    ANSWER: Depend on recursion and to not traverse through the entire tree.

-----------------------------------------------
bst_num_leq level of completion:  _____5_______

    How did you ensure O(h) runtime?

    ANSWER: Depend on recursion and to not traverse through the entire tree.

-----------------------------------------------
bst_num_range level of completion:  _____5_______

    How did you ensure O(h) runtime?

    ANSWER: Depend on recursion and to not traverse through the entire tree.

-----------------------------------------------
Implementation of size-balanced criteria according to 
the given guidelines (including bst_sb_work):

    Level of completion: _____4______


Write a few sentences describing how you tested your solutions.  Are there
any tests that in retrospect you wish you'd done?
I mainly did the testing on a sheet of paper then I converted it to code. I did test the function and it works to a certain extent.






