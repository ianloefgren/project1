# project1

CSCI 2270 Final Project

Author: Ian Loefgren

# Summary
This project is a basic database that is constructed using a hash table. The user has the option of creating an account, and storing a message in their account that is accesible only when they log in, as well as changing their password and printing user info. User info includes username, hashed password (proof of concept) and stored message. User passwords are salted and hashed using a salt generator and a hash function both written by me. While these functions are not cryptographically secure, they demonstrate the concept of password encryption with salted passwords.

# Concept
A hash function for passwords is very similar to the hash function we used for our hash table homework assignment, differing in that a password hashing function outputs a string of chracters equal in length to the inputted string, instead of an index. The hash function will always generate the same output for the same input. This would make is easy to break in if the attacker knew the hashing function. This is the purpose of the salt generator. A salt is a random, unique string of characters that is appended to the plain-text password, before all of it is hashed. This means an attacker would have to know both the hashing function and the salt, instead of just hashing common passwords and trying them.

For more information, visit: https://crackstation.net/hashing-security.htm

#  How To Run
1) Clone the project repository to a directory on your computer, or download the files manually.

2) Check if your system has a copy of make by changing directory into the project folder, and running the command "make" (no quotes) in a terminal to use the included makefile.
  - If this does not work, each file will have to be manually compiled and linked. (see end of section)
  - Alternatively compile and run using your favorite IDE, such as codeblocks.

3) Run the created excecutable.

Manually compiling and linking files:
Type the following commands in the terminal (make sure you are in the folder containing the code!)

    g++ -c PassTable.cpp
    g++ -c Account.cpp
    g++ -c HashTable.cpp
    g++ -c projectDriver.cpp
    g++ -o projectDriver PassTable.o Account.o HashTable.o projectDriver.o
    ./projectDriver

!!!!  If you are having trouble compliling or running the code please email me!!!!

  ian.loefgren@colorado.edu

# Dependencies
This project requires the standard c library random, as well as c library time.h, which both are standard and included with c and c++ compilers.

# System Requirements
This program should run on all operating systems.

# Contributors
Ates Goral, for code to generate a string of random characters.

#Open Issues/Bugs
See the issues tab for open bugs and feature requests.
