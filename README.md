# Quiz Management System

## Project Description

This project is a simple quiz management system written in C.  
It allows the user to manage students, manage questions, run a quiz, calculate scores, save results, and keep a simple log of the main operations.

## Main Objectives

The main objectives of this project are:

- to practice structures and arrays
- to organize the code using functions and separate files
- to save and load data using files
- to manage students and questions
- to execute a simple quiz
- to save the final result of a student

## Implemented Features

The project includes:

- student management
- question management
- loading and saving students
- loading and saving questions
- menu-based interaction
- test execution
- answer collection
- score calculation
- result storage
- log management

## Project Structure

The project is organized into separate source and header files.

src/
- main.c: contains the main menu
- student.c: contains student functions
- question.c: contains question functions
- test.c: contains test execution functions
- result.c: contains result saving functions
- log.c: contains log functions

include/
- student.h
- question.h
- test.h
- result.h
- log.h

data/
- students.csv

## Input and Output Files

- students.csv stores student data
- questions.csv stores quiz questions
- results.txt stores the test results
- log.txt stores the main operations of the program

## Implementation Choices

The project uses structures to represent students and questions.  
Arrays are used to store multiple students and questions.  
Functions are used to divide the program into smaller parts.  
CSV and text files are used to save and load data.  
The code is divided into modules to make the project more organized and easier to understand.