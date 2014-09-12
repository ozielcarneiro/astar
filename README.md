This code was developed for an assignment for the Artificial Intelligence course at USC using C++. The assignment requested to program the A* Search algorithm for a problem where there was a square board, with two characters A and B, and obstacles (meaning no character could use this place on the board), the movement of A is controlled and B moves based on the action of A. The goal is to make A and B reach the same spot on the board. The A* algorithm uses three different heuristics to evaluate the Euclidean Distance, Manhattan Distance and Chessboard Distance and print the results of each heuristic to comparison.

1 - Program Description

The program is divided in 4 classes, IO.cpp, Node.cpp, Search.cpp, main.cpp.

The class IO.cpp is responsible for writing and reading text files, with two methods fileToString(string fileName) which reads the file specified by the path in the string fileName, and stringToFile(string fileName, string text) which writes the string text into a file specified by the string fileName.

The class Node.cpp describes each node in the search tree. The class is designed based on the problem, so the variables and methods represent the details of the problem. The variables will hold the following information: previous node on tree, position of agents, cost to reach node, level of the node, map size, number of obstacles, position of obstacles, costs of moves and a flag that determines which heuristic the search is using. The methods moveUp(),moveRight(),moveDown() and moveLeft() are responsible to generate the following children nodes, there is a method to check if the node is a goal node, and a method to get the path to the node recursively. The total value of the node in the A* algorithm is obtained through a method that calls a method to obtain the path cost until this node and other method to obtain the heuristic value of the node, and sums the values. The heuristic value is obtained by calling getHeuristicCost() which returns a value according to the heuristicFlag value, if heuristicFlag is 1 it returns the Euclidean Distance, if it is 2 it returns the Manhattan Distance and if it is 3 it returns the Chessboard Distance. Also there is set and get methods to access the other variables. There is a constructor in the node class that is responsible to map the information in a string to the correspondent variables.

The class Search.cpp implements the  A* search algorithms, as a method. Other methods like checkVisited(Node* node), to check if a node has been visited before, and sortQueue() to sort the queue holding the next nodes to be visited by the total A* value of each of them. The class hold three variables, two dynamic growing vectors to hold the queue and the visited nodes, and a visited nodes counter.

The last class, main.cpp, is the class responsible for running the program. It reads the input file "input.txt" from the same directory of the program and split the information in it corresponding to each run in strings. Then for each run it creates two Nodes, one using the constructor with the input string for the run, which will be the starting node, and other empty which will hold the goal node. Then it creates a Search object. When calling the search function two nodes are required as parameters, the starting node and the empty goal node. The search method returns a boolean variable indicating success. The results of the batch are written in two tables in a file called "output.txt" on the same directory of the program, one containing the number of expanded nodes for each input and each heuristic, and the other table containing the optimal path (starting at the original position) for each input. If there is no possible solution for an input a '-' is added in place of nodes expanded values for this input, and '-1' for the optimal path.

2 - Compile Instructions

To compile the program type the following command on the Terminal: g++ main.cpp IO.cpp Node.cpp Search.cpp

For the program to run correctly the input.txt file needs to be in the same directory as the output file generated after compilation.

To run the program after compiling type the following command on the Terminal: ./a.out

3 - Input and Output Files

The input file is a text file containing a batch of settings for the problem, each instance can be divided as the board size, then the cost of each of the movements of A, then the position of A and B, and the position of the obstacles. The output file is a text file with a table showing the number of nodes expanded during the search using each of the heuristics and for each input instance, then the optimal path of A for each input instance or -1 if no solution is found.