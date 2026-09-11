
## Problem statement
Online code editors are now a crucial part of modern software development. They allow collaboration, real-time 
coding, and the ability to access development tools from anywhere in the world. In this article, we'll explore how to 
design a system to create a useful and scalable online code editor.

## Functional Requirements
1. Authentication & Authorization where user access code editor features and admin add new features
2. There are two roles users , admin
3. Code Editing  where user create file, write code, show highlighting, syntax and edit
4. Support multiple programming language.
5. Execution support terminal to run the code or execute method
6. Version Control to track all changes
7. One method to install new Extension 
8. One method to show others features name view -> word rap, auto format, auto correct, use ai to help like that
8. Help section


## Non-Functional Requirements
1. Perfomance code editor work smoothly user get quick answer when run the code no laghing isshu.
2. Scalablity -> when user increase system will be scalable use scaling -> vertical / horizontal
3. Security Maintain user data , user code etc.
4. Relaibilty Maintain minimal down time give high availblity.
5. Every time system will be updated new extension , new programming language. 

## Capacity Estimations
Assume traffic user per month 100,000
Traffic per second = 100000 / (30days * 24hr * 60min * 60sec)
TPS = 100000/2592000
TPS = 0.038

assume 1 submission execution  take 5 sec
1 submission rate per second = 1/5
SRPS = 0.2

Execution per second = submission rate per second * submission execution time
EPS = 0.2 * 5
EPS = 1.0 exections/second





