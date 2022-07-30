# Fast Food Order Management in C

C program that will implement a food ordering system used in a fast food restaurant. This restaurant only serves burgers and salads and when people want to order food, they give their name and food choices to the cashier and then wait until those in front of them have been served. The program use **a linked list** to implement the queue-like data structure.

The linked list is to maintain the following information for each group that is waiting:

x name (we assume a maximum name length of 30 characters) x food items (number of burgers and salads ordered)

x in-restaurant status: whether the group has called ahead or is waiting in the restaurant

The system allows you to call and put your order in before you arrive at the restaurant, but it does not take orders for a specific time and date (i.e. 4 burgers and 2 salads for 7pm on Saturday). Note: these call-ahead groups will still need to check in when they arrive, so the cashier knows they are waiting in the restaurant.

Groups are added to the order list when they call-ahead or when they arrive at the restaurant. Groups are always added to the end of the order list. The system will require that each name used be unique. So, when a group is added to the order list, the system must make sure that no other group is already using that name.

The restaurant staff working in the kitchen have a steady speed in preparing food and they work on one order at a time. On average, preparing a salad takes 2 minutes while burger takes 5 minutes. The system needs to track how many food items have been ordered and provide customers with an estimated wait time.

You can assume that every time an order is being called, it will go to the first group in line. However, in order to pick up the food, the group needs to be present at the restaurant. If they are not, then the system will call the next eligible group for pick up (an eligible group is a group that the number of burgers and salads they ordered is less than or equal to prepared order).

The commands used by this system are listed below and are to come from standard input. This program does prompt the user for input and display error messages for unknown commands or improperly formatted commands. Note that the name of the group when given will be given as the last item on the input line. Each command given must display some information about the command being performed. Code to implement this interface is provided in the program **.**

| Command                                    | Description                                                                                                                                                                                                                                                                    |
|--------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **q**                                      | Quit the program.                                                                                                                                                                                                                                                              |
| **?**                                      | List the commands used by this program and a brief description of how to use each one.                                                                                                                                                                                         |
| **a \<\#burgers\> \<\#salads\> \<name\>**  | Add the order to the order list using the given order and name specifying the group is waiting in the restaurant. The orders information is added to the end of the list. If the name already exists in the order list, give an error message and do not add the information.  |
| **c \<\#burgers\> \<\#salads\> \<name\>**  | Add the order to the order list using the given order and name specifying the order as a call ahead order. The orders information is added to the end of the list. If the name already exists in the order list, give an error message and do not add the information.         |
| **w \<name\>**                             | Mark the call ahead order using the given name as waiting in the restaurant. If the name does not exist is the order list or is not a call ahead group, give an error message.                                                                                                 |
| **r \<\#burgers\> \<\#salads\>**           | Retrieve and remove the first order on the order list that is waiting in the restaurant and contains less than or equal to number of prepared burgers and salads. Note that first is the order that has been in the order list the longest.                                    |
| **l \<name\>**                             | List total number of orders that are in the order list in front of the order specified by the given name. If the name does not exist, give an error message.                                                                                                                   |
| **t \<name\>**                             | Give an estimated waiting time based on the order list knowing preparing burgers will take 5 minutes and preparing salads takes 2.  If the name does not exist, give an error message.                                                                                         |
| **d**                                      | Display the total number of orders in the order list. Also display the names, order details and in-restaurant status of all orders in the order list in order from first to last.                                                                                              |

Note that **\<\#burgers\>** and **\<\#salads\>** are to be integer values and **\<name\>** is a list of characters. The \< and \> symbols are NOT part of the input but being used to describe the input.

# Linked List Operations/Functions

You must write C functions for the following 8 operations. These functions must be called when the specified commands are given as input.

**addToList ( )** This operation is to add a new node to the end of the linked list. This is to be used when the **a** and **c** commands are given as input.

**doesNameExist ( )** This operation is to return a Boolean value indicating whether a name already exists in the linked list. This is to be used when the **a, c, w, t** and **l** commands are given as input.

**updateStatus ( )** This operation is to change the in-restaurant status when a call-ahead order arrives at the restaurant. This operation will return a FALSE value if that order is already marked as being in the restaurant. This is to be used when the **w** command is given as input.

**retrieveAndRemove ( )** This operation is to find the first in-restaurant order that matches the order prepared for pick up at the counter. This operation is to return the name of group. This group is to be removed from the linked list. This is to be used when the **r** command is given as input.

**countOrdersAhead ( )** This operation is to return the number of orders waiting ahead of an order with a specific name. This is to be used when the **l** command is given as input.

**displayWaitingTime( )**  This operation is to return the estimated waiting time for the specific name. The function will check the number of burgers and salads ordered ahead of the specified name and using known preparing time (5 minutes for burger and 2 minutes for salad) calculates the estimated wait time. This is to be used when **t** command is given as input.

**displayOrdersAhead ( )** This operation traverses down the list until a specific order name is encountered. As each node is tra ersed, print out that node s orders. This command is to be used when the **l** command is given.

**displayListInformation ( )** This operation to traverse down the entire list from beginning to end. As each node is tra ersed, print out that node s name, order details and in-restaurant status. This command is to be used when the **d** command is given as input.

Note that there may be a many-to-many relationship between the commands in the user interface and the required functions. For example, the l command ( list ) relies on the following functions: doesNameExist(), countOrdersAhead() and displayOrdersAhead().
