# AP2022

Advanced Programming 1 by Niv Swisa & Guy Reuveni -

WHAT THE PROGRAM DOES :

The program receives two vectors and calculates the distance between them using 5 different distance algorithms. The algorithms used are "Minkowski", "Euclidean", "Manhattan", "Canberra" and "Chebyshev".

HOW TO RUN THE PROGRAM :
In order to run the program you need to clone it to your PC and :

1. Use the cd command to access the cloned directory

2. Use the command "cd AP2022" in order to access the c++ file containing all the headers and classes

3. Now you need to compile the files using "g++ -std=c++11 *.cpp"

4. To run the project enter "./a.out".

5. Now you can enter the vectors and run the program.

NOTES :

1. If the vectors aren't of the same length the program will shut down.

2. If the input consists of anything other than double values the program will shut down, such as:
  - if the input is empty
  - if there is more than one decimal period in a single number.
  - if a decimal number starts with a decimal period instead of a number or a minus sign.
  - if the are doubleblank spaces in a row or other whitespaces like tab etc.
  - if the input starts with a blank space
  - if the input consists of anything else other than a decimal period or a digit such as letter, signs and so on.

3. if one of the values is greater than a double value the program will shut down. 

4. The Minkowski algorithm is the base to the Manhattan and Euclidean algorithms. In Manhattan the p value is the constant 1 and in the Euclidean the p value is the constant 2.

5. The p Value chosen for the Minkowski algorithm is the constant 2.

6. In the Canberra algorithm we covered the case where the division by zero could occur and made sure to avoid the calculation.
