"""
Practice Problem: Iterate through the first 10 numbers (0–9). In each iteration, print the current number, the previous number, and their sum.

Exercise Purpose: This exercise teaches “State Tracking.” In programming, you often need to remember a value from a previous loop iteration to calculate results in the current one. This is the basis for algorithms like Fibonacci sequences or running totals.

Given Input: Range: numbers = range(10)

"""

n=int(input())
print("Printing current and previous number sum in a range (",n,")")

for i in range(n):
    if i==0:
        print("Current Number 0 Previous Number 0 Sum: 0")

    else:
        print("current Number",i,"Previous Number",i-1,"Sum:",i+(i-1))