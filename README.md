-------------------------------------------------------------------------------
# Implementation Explanation Document

## Student Information
- Full Name: Sandiel Carmona Jr.
- Course Name: CSCL 373 - Advanced Data Structures
- Course Description: This course explores advanced data structures in C++ with 
a focus on linked lists, stacks, queues, and algorithmic design, emphasizing 
object-oriented programming and code modularity.
- Assignment Title: Doubly Linked List Implementation (Without User Input)
- Date: 10/05/2025

## 1. Introduction
This assignment required the creation of a doubly linked list (DLinkedList) in
C++ without using sentinel nodes. The program uses two classes: DNode for 
representing each node and DLinkedList for managing the list’s functionality.
The goal was to implement a working linked list that supports insertion and 
deletion from both ends, forward and reverse traversal, and automatic node tracking.
The list operations were tested automatically in the main function without user input.


## 2. Tools and Technologies Used
[List the tools, technologies, or platforms you used to implement the assignment. 
This could include programming languages, development environments, operating 
systems, AI tools, or libraries.]

- Tool 1: C++ (object-oriented programming language)
- Tool 2: CodeLabZone (Integrated Development Environment for compiling and testing assignments)
- Tool 3: ChatGPT (Used for debugging and verifying operator logic, 
compilation errors, and implementation design compliance)

## 3. Implementation Details
### Key Components
- Classes: 
     DNode:
Represents a node in the list containing:

An integer element (elem)

Two pointers (prev, next)

A static counter activeNodes to track the number of live nodes

A constructor that increments the counter when a node is created


    DLinkedList:
Manages the list’s functionality. Contains:

Pointers head and trailer to track the start and end of the list

An integer n to store the number of elements

Methods for insertion, deletion, traversal, and size tracking
A destructor that decrements the counter when a node is deleted
- Functions (if used): 
addFront() / addBack(): Insert nodes at the front or back of the list.

removeFront() / removeBack(): Remove nodes from the front or back of the list.

print(bool front): Prints elements from head (if true) or trailer (if false).

size(): Returns the total number of nodes.

activeNodeCount(): Returns the static count of active nodes across the program.

### Design Choices
The implementation avoids dummy nodes and uses nullptr at both ends to mark the boundaries of the list.

A static integer (activeNodes) is used to globally track how many nodes currently exist.

Error handling for empty list removal ensures safe pointer operations and prevents segmentation faults.

The destructor uses a loop to remove all nodes and release memory safely.

The print() function provides bidirectional traversal flexibility, showcasing the use of prev and next links.

## 4. Challenges, Solutions, and Error Report
### Technical Challenges
- Challenge 1: Avoiding multiple definition errors for the static variable activeNodes.
  - Solution: Declared the static variable in DNode.h and 
  defined it only once in DLinkedList.cpp to prevent linker conflicts.

- Challenge 2: Managing nullptr boundaries without sentinel nodes.
  - Solution: Implemented checks in both addFront() 
  and addBack() to handle empty list initialization properly.
  
-Challenge 3: Ensuring list cleanup without memory leaks.
  - Solution: The DLinkedList destructor uses removeFront() in a 
  loop to delete all nodes safely.

### Error Report
- Common Errors Encountered:
  - Error 1: multiple definition of 'DNode::activeNodes'
    - Cause: The static variable was declared in both main.cpp and DLinkedList.cpp.
    - Solution: Removed its definition from DLinkedList.cpp. and kept it only inmain.cpp 
  
  - Error 2: Runtime crash when removing from an empty list.
    - Cause: Missing check before deleting a node in removeFront() and removeBack().
    - Solution: Added if (empty()) return; at the start of both methods.
    
  - Error 3: Backward traversal displayed garbage values when only one element existed.
    - Cause: Improper pointer update after deletion.
    - Solution: Added conditions to reset head and trailer to nullptr when the list becomes empty.

## 5. Testing Strategy
### Verification Methods
Since this program runs without user input, testing was fully automated inside 
the main.cpp file using predefined operations and sequential steps. 
Each operation was designed to verify a specific behavior of the DLinkedList 
and ensure pointer integrity, correct node counts, and proper traversal in both directions.

1. Predefined Testing Scenarios

Scenario 1: Add three nodes to the front using addFront() (values: 10, 20, 30).

Expected behavior: The list order should be 30 20 10.

Scenario 2: Add two nodes to the back using addBack() (values: 40, 50).

Expected behavior: The list should now read 30 20 10 40 50.

Scenario 3: Print the list from front to back and verify elements appear in correct order.

Scenario 4: Print the list from back to front to verify reverse traversal logic using the prev pointer.

Expected behavior: The reverse order should be 50 40 10 20 30.

Scenario 5: Remove one element from the front and one from the back using removeFront() and removeBack().

Expected behavior: The list should now display 20 10 40.

Scenario 6: Add a new element to the front (60) and back (70).

Expected behavior: The final list should read 60 20 10 40 70.

2. Output Verification

Each step printed a labeled result to the console showing the direction and the node values.
The output was manually verified against the expected sequences. Example verified output:

List (front to back): 30 20 10 40 50
List (back to front): 50 40 10 20 30
List (front to back): 20 10 40
List (front to back): 60 20 10 40 70
Total active nodes: 5

3.Correctness Validation

Checked that addFront() and addBack() correctly adjusted both head and trailer pointers.

Confirmed removeFront() and removeBack() properly deallocated memory without leaving dangling pointers.

Verified that the static node counter accurately reflected live nodes after each operation.

Confirmed that all print statements displayed expected sequences before and after modifications.

Ensured no segmentation faults occurred when deleting nodes from an empty list.

4. No User Input Requirement

All operations were executed automatically in a controlled sequence, 
demonstrating that the list functions perform correctly without 
needing manual input or user prompts.

## 6. Conclusion
This assignment strengthened my understanding of pointer manipulation, dynamic memory, and 
object-oriented design in C++.Implementing a doubly linked list without sentinel nodes 
required careful boundary handling and static memory tracking. The concept of a static counter 
for live nodes was especially useful in monitoring memory allocation. This project 
reinforced core OOP principles such as encapsulation and class interaction, 
skills that are crucial for advanced data structure design.

## 7. References

https://www.jjay-csci272.org/course-materials/lesson-9



-------------------------------------------------------------------------------
