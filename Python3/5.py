# This is a simple Python script to explain functions with a practical example.

# Function Example: Greet the user

# Define a function called 'greet'
def greet(name):
    """
    This function takes a 'name' parameter and prints a greeting message.
    """
    print("Hello, " + name + "! Welcome to the Python functions lab.")

# Main function
def main():
    """
    The main function where the program starts.
    """
    # Get the user's name as input
    user_name = input("Enter your name: ")
    
    # Call the greet function with the user's name
    greet(user_name)

    # Additional function calls can be added here

# Call the main function to start the program
if __name__ == "__main__":
    main()

# Comments to explain the example:
# - Defined a function 'greet' that takes a 'name' parameter and prints a greeting message.
# - Defined a main function where the program starts.
# - Inside the main function, prompted the user to enter their name using the input function.
# - Called the 'greet' function with the user's name.
# - The 'if __name__ == "__main__":' block ensures that the 'main' function is executed when the script is run.

# Exercise 1 (Incomplete): Create a function to calculate the square of a number
# The learner needs to complete the code to define a function to calculate the square of a number.

# Define a function called 'calculate_square'
# It should take a 'number' parameter and return the square of the number.
def calculate_square(number):
    # Incomplete: The learner needs to modify the code to return the square of the number.

# Exercise 2 (Buggy): Create a function to find the maximum of two numbers
# The learner needs to fix the bug in the code to correctly find the maximum of two numbers.

# Define a function called 'find_maximum'
# It should take two parameters 'num1' and 'num2' and return the maximum of the two numbers.
def find_maximum(num1, num2):
    # Buggy: The learner needs to fix the code to correctly find the maximum of num1 and num2.


