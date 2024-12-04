#PROJECT: FINANCE TRACKER

#Description:
#Create a finance tracker application that allows users to manage their expenses, 
#incomes, and visualize their financial data. This project will involve handling data, 
#working with external libraries, and implementing a simple user interface.

#Features:

# User Authentication:
   # Implement a user authentication system to allow users to create accounts and log
   # in securely.
# Expense and Income Tracking:
   # Allow users to add, edit, and delete their expenses and incomes.
   # Include categories for expenses and incomes (e.g., groceries, bills, salary).
   # Track the date, amount, and category of each transaction.
# Data Storage:
   # Use a database (e.g., SQLite, SQLAlchemy) to store user data securely.
   # Implement data models for users, expenses, and incomes.
# Data Visualization:
   # Create visualizations (e.g., pie charts, bar graphs) to represent the user's expenses and incomes.
   # Use a plotting library such as Matplotlib or Plotly.
# Budgeting:
   # Allow users to set monthly budgets for different categories.
   # Provide notifications or warnings when users exceed their budget.
# Export and Import Data:
   # Allow users to export their financial data to a CSV file.
   # Implement an import feature to allow users to upload previously exported data.
# Command-Line Interface (Optional):
   # Implement a command-line interface (CLI) for users who prefer working in the terminal.
# Testing:
   # Write unit tests for critical components of your application.
# User-Friendly Interface:
   # Design a user-friendly interface using a GUI library (e.g., Tkinter, PyQt, Kivy).
   # Include features like data tables, graphs, and navigation.


#CHALLENGES
 # Implementing secure user authentication.
 # Integrating a database and designing efficient data models.
 # Creating dynamic and responsive data visualizations.
 # Handling user inputs and managing state in a graphical user interface.

# Incomplete code is provided below to start from. You will need to run the following command below to
# install the proper libraries to run this code:

# pip install flask flask_sqlalchemy flask_login




from flask import Flask, render_template, request, redirect, url_for
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager, UserMixin, login_user, login_required, logout_user, current_user

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///finance.db'
app.config['SECRET_KEY'] = 'your_secret_key'
db = SQLAlchemy(app)
login_manager = LoginManager(app)
login_manager.login_view = 'login'


# Data Models
class User(UserMixin, db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(50), unique=True, nullable=False)
    password = db.Column(db.String(50), nullable=False)
    expenses = db.relationship('Expense', backref='user', lazy=True)
    incomes = db.relationship('Income', backref='user', lazy=True)


class Expense(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    amount = db.Column(db.Float, nullable=False)
    category = db.Column(db.String(50), nullable=False)
    date = db.Column(db.Date, nullable=False)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)


class Income(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    amount = db.Column(db.Float, nullable=False)
    category = db.Column(db.String(50), nullable=False)
    date = db.Column(db.Date, nullable=False)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)


@login_manager.user_loader
def load_user(user_id):
    return User.query.get(int(user_id))


# Routes
@app.route('/')
@login_required
def dashboard():
    # Implement code to retrieve and display user's financial data
    return render_template('dashboard.html')


@app.route('/login', methods=['GET', 'POST'])
def login():
    # Implement code for user login
    return render_template('login.html')


@app.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect(url_for('login'))


if __name__ == '__main__':
    db.create_all()
    app.run(debug=True)

