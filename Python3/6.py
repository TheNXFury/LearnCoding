# This is a simple Python script to explain classes and data structures with a practical example.

# Example: Creating a simple 'Person' class and using a list to store people

# Define a class called 'Person'
class Person:
    def __init__(self, name, age):
        """
        Constructor method that initializes the attributes of the person.
        """
        self.name = name
        self.age = age

    def greet(self):
        """
        Method that prints a greeting message using the person's name.
        """
        print(f"Hello, my name is {self.name} and I am {self.age} years old.")

# Create an instance of the 'Person' class
person1 = Person("Alice", 25)

# Call the 'greet' method of the 'Person' class
person1.greet()

# Create a list to store 'Person' objects
people_list = []

# Add 'Person' objects to the list
people_list.append(Person("Bob", 30))
people_list.append(Person("Charlie", 22))
people_list.append(Person("David", 28))

# Iterate through the list and call the 'greet' method for each person
for person in people_list:
    person.greet()

# Comments to explain the example:
# - Defined a class 'Person' with a constructor (__init__) method to initialize the person's attributes.
# - Created an instance 'person1' of the 'Person' class with the name "Alice" and age 25.
# - Called the 'greet' method of the 'Person' class to print a greeting message using the person's name.
# - Created a list 'people_list' to store 'Person' objects.
# - Added 'Person' objects to the list.
# - Iterated through the list and called the 'greet' method for each person.

# Exercise 1 (Incomplete): Expand the 'Person' class
# Complete the code to add a new attribute and method to the 'Person' class.

# Modify the 'Person' class to include:
# - A new attribute 'gender'
# - A new method 'introduce' that prints a message including the person's gender

# Exercise 2: Use a list to store multiple 'Person' objects
# Use the defined list below to store and print multiple 'Person' objects in a list by creating a loop.

# Create a list to store 'Person' objects
people_list_2 = []


