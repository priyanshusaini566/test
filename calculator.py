print("1.Addition +")
print("2.Subtraction -")
print("3.Multiplication ")
print("4.Division /")

operator=(input("Enter your choice : "))

num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))

match operator:
    case "1":
        print("the addition will be : ",num1+num2)

    case "2":
        print("the subtraction will be : ",num1-num2)

    case "3":
        print("the multiplication will be : ",num1*num2)

    case "4":
        if(num2!=0):
           print("the division will be : ",num1/num2)

        else:
            print("the denominator should not be 0")

    case _:
        print("Invalid operation")
