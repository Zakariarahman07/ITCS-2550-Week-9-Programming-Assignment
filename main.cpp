/*
Author: Zakaria Rahman

Date: March 22, 2026
Description: This program collects user inputs and validates if they enter the correct input.
             Also, it demonstrates file handling by writing to a file. Additionally, it shows the usage 
             of selection statements like if else statements and switch case statements. Furthermore, 
             it also demonstrates the use of repetition structures such as the for loop, do...while loop,
             and while loop, and use of user defined functions. It also demonstrates the use of Arrays and Enumerations.
             This program also shows the useage of data structures like struct. 
             Finally, it incorporates object-oriented programming concepts including classes, inheritance, and composition.
             Additionally, it shows the use of virtual functions and polymorphism. It also shows the use of pointers and dynamic memory allocation.
             This program also shows use of class templates and operator overloading. The program also shows exception handling. 
             This program also shows the use of recursion in programming. 
             New: Use of vectors, implementation of sequential search, bubble sort, and binary search.
Course: ITCS 2550 (C++ Programming 2)
*/


// header files
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <exception>
#include <cassert>
#include <vector>


using namespace std;



// Enumeration Declaration
enum difficultyLevel { EASY = 'E', MEDIUM = 'M', HARD = 'H'};

// Enumeration for Happiness Level
enum happinessLevelLife { SAD, NEUTRAL, HAPPY};

// Base Class (Abstract Class)
class Person {
    // Private Members
    private:
        string lastName;
        string firstName;
        int age;
    // Protected Members
    protected:
        happinessLevelLife happinessLevel;
    // Public Members
    public:
        // Default Constructor
        Person(){
            lastName = " ";
            firstName = " ";
            age = 0;
            happinessLevel = NEUTRAL;
        }
        // Parameterized Constructor
        Person(string lName, string fName, int a, happinessLevelLife hLevel);

        // Virtual Destructor
        virtual ~Person(){}

        // Setter Functions
        void setPersonalInformation(string lName, string fName, int a, happinessLevelLife hLevel);

        // Getter Functions
        string getLastName() const{
            return lastName;
        }
        string getFirstName() const {
            return firstName;
        }
        int getAge() const {
            return age;
        }
        happinessLevelLife getHappinessLevel() const {
            return happinessLevel;
        }
        
        // Virtual Print Function
        virtual void print() const;

        // Pure Virtual Function
        virtual string getSubject() const = 0;

        // Virtual Function for using << operator overloading
        virtual void  toStream(ostream& COUT) const {
            COUT << "My name is " << firstName << " " << lastName << " and I am " << age << " years old.";
        }

};
// Composition Class Date
class Date {
    // Private Members
    private:
        int day;
        int month;
        int year;
    // Public Members
    public:
        // Default Constrcutor
        Date() {
            day = 1;
            month = 1;
            year = 2000;
        }
        // Parameterized Constructor
        Date(int d, int m, int y) {
            if (d >=1 && d <= 31){
                day = d;
            } else {
                day = 1;
            }
            if (m >=1 && m <= 12) {
                month = m;
            } else {
                month = 1;
            }
            year = y;
        }
        // Setter Function
        void setDate(int d, int m, int y) {
            if (d >=1 && d <= 31){
                day = d;
            } else {
                day = 1;
            }
            if (m >=1 && m <= 12) {
                month = m;
            } else {
                month = 1;
            }
            year = y;
        }
        // Getter Functions
        int getDay() const {
            return day;
        }
        int getMonth() const {
            return month;
        }
        int getYear() const {
            return year;
        }

        // Format Date Function
        void formateDate() const {
            cout << right << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(2) << day << "/" << year << endl;
        }

};

// Derived Class Student
class Student:public Person {
    // Private Members
    private:
        string studentID;
        char studentGrade;
        int studentTestScore;
        string majorName;
        // Creating a vector for storing a student's multiple test scores for a semester
        vector<int> vectStudentTestScores;
    // Public Members
    public:
        // Default Constructor
        Student():Person() {
            studentID = " ";
            studentGrade = ' ';
            studentTestScore = 0;
            majorName = " ";
        }
        // Parameterized Constructor
        Student(string lName, string fName, int a, happinessLevelLife hLevel, string sID, char sGrade, int sTestScore, string sMajorName):Person(lName, fName, a, hLevel) {
            studentID = sID;
            studentGrade = sGrade;
            studentTestScore = sTestScore;
            majorName = sMajorName;
        }
        // Setter Function
        void setStudentInformation(string lName, string fName, int a, happinessLevelLife hLevel, string sID, char sGrade, int sTestScore, string sMajorName) {
            Person::setPersonalInformation(lName, fName, a, hLevel);
            studentID = sID;
            studentGrade = sGrade;
            studentTestScore = sTestScore;
            majorName = sMajorName;
        }
        // Getter Functions
        string getStudentID() const {
            return studentID;
        }
        char getStudentGrade() const {
            return studentGrade;
        }
        int getStudentTestScore() const {
            return studentTestScore;
        }
        int getScoreAt(int index) const {
            return vectStudentTestScores.at(index);
        }
        int getNumberOfScores() const {
            return static_cast<int>(vectStudentTestScores.size());
        }
        // Overriding the pure virtual function from the base class
        string getSubject() const {
            return majorName;
        }

        // Functionality for the vector
        // Adding an element to the vector object
        void addTestScores(int testScore) {
            vectStudentTestScores.push_back(testScore);
        }

        // For multiple test score addition in the vector
        void addMultipleScores(){
            int elementScore;
            int numberOfTestScores;
            cout << "Enter the number of scores you want to add: ";
            cin >> numberOfTestScores;

            //From GeeksForGeeks Website (https://www.geeksforgeeks.org/cpp/std-vector-reserve-in-cpp-stl/)
            vectStudentTestScores.reserve(numberOfTestScores);
            for (int i = 0; i < numberOfTestScores; i++) {
                cout << "Enter Score " << i + 1 << endl;
                cin >> elementScore;
                vectStudentTestScores.push_back(elementScore);
            }
        }
        // Overriding the virtual function for using << operator overloading
        void toStream(ostream& COUT) const {
            Person::toStream(COUT);
            COUT << " I am a student and my major is " << majorName << "." << endl;
        }
        
        // Feedback Function
        string getFeedback() const;
        // Print Function
        void print() const;

        // Bubble Sort, Liner Search, Binary Search Functions Prototype;
        void bubbleSortScores();
        int linearSearchScores(int keyScore) const;
        int binarySearchScores(int keyScore);
};

// Derived Class Teacher
class Teacher:public Person {
    // Private Members
    private:
        string teachingSubject;
        Date hireDate;
    // Public Members
    public:
        // Default Constructor
        Teacher():Person() {
            teachingSubject = " ";
            hireDate = Date();
        }
        // Parameterized Constructor
        Teacher(string lName, string fName, int a, happinessLevelLife hLevel, string teachingSubject, int d, int m, int y):Person(lName, fName, a, hLevel), hireDate(d, m, y) {
            // Using this pointer to differentiate between the parameter and class member variables with same name
            // When object is created, a 'this' pointer is automatically invoked.
            this->teachingSubject = teachingSubject;
        }

        // Setter Function
        void setTeacherInformation(string lName, string fName, int a, happinessLevelLife hLevel, string tSubject, int d, int m, int y) {
            Person::setPersonalInformation(lName, fName, a, hLevel);
            hireDate.setDate(d,m,y);
            teachingSubject = tSubject;
        }
        // Getter Function
        Date getHireDate() const {
            return hireDate;
        }
        // Overriding the pure virtual function from the base class
        string getSubject() const {
            return teachingSubject;
        }

        // Print Function
        void print() const {
            Person::print();
            cout << "Teaching Subject: " << teachingSubject << endl;
            cout << "Hire Date: ";
            hireDate.formateDate();
            cout << endl;
        }

        //  Overriding the virual function for using << operator overloading
        void toStream(ostream& COUT) const {
            Person::toStream(COUT);
            COUT << " I am a teacher and I teach " << teachingSubject << "." << endl;
        }

        // Overloading == operator for derived Teacher class
        bool operator==(const Teacher& other) const {
            return (teachingSubject == other.teachingSubject); // Two teacher from same department are considered equal
        }

        // Using recursion to calculate experience of a teacher in years
        int calculateYearsOfExperience(int currentYear) const {
            try {
                if (currentYear < hireDate.getYear()){
                    throw invalid_argument("Current year cannot be less than the hire year.");
                }
                int hireYear = hireDate.getYear();
                // Base Case
                if (currentYear == hireYear){
                    return 0;
                }
                // General Case
                // Calling the function (directly recursion)
                else {
                    return 1 + calculateYearsOfExperience(currentYear - 1);
                }
            }
            catch (const invalid_argument& ex) {
                cout << "Exception Caught: " << ex.what() << endl;
                return 0;
            }
        }   
};

// Non Member Function for Overloading << operator for the classes
ostream& operator<<(ostream& COUT, const Person& person) {
    person.toStream(COUT);
    return COUT;
}

// Class Template for Dynamic Array Logic
template <class Type>
class DynamicArray {
    private:
        Type** array;
        int currentSize;
        int maxSize;

    public:
        // Default Constructor
        DynamicArray(int size = 10) {
            maxSize = size;
            currentSize = 0;
            array = new Type*[maxSize];
        }
        // Destructor
        ~DynamicArray() {
            for (int i = 0; i < currentSize; i++) {
                delete array[i];
            }
            delete[] array;
        }
        // Overload the += operator to add an element to the dynamic array
        void operator+=(Type* element) {
            if (currentSize == maxSize) {
                int newCapacity = maxSize + 1;
                Type** newArray = new Type*[newCapacity];

                for (int i = 0; i < currentSize; i++) {
                    newArray[i] = array[i];
                }
                delete[] array;
                array = newArray;
                maxSize = newCapacity;
            }
            array[currentSize] = element;
            currentSize++;
        }

        // Overload the -= operator to remove an element from the dynamic array
        void operator-=(int index) {

            if (index < 0 || index >= currentSize) {
                throw out_of_range("Invalid index for removal");
            }
            delete array[index];
            // Continuous Memory Allocation
            for (int i = index; i < currentSize -1; i++) {
                array[i] = array[i + 1];
            }
            // The last pointer component is set to nullptr after shifting
            array[currentSize - 1] = nullptr; // Safer Approach
            currentSize--;
        }

        // Overload the [] operator to access an element at a specific index
        // Exception Handling for invalid or out of bounds index
        const Type* operator[] (int index) const{
            // If the index is out of bounds, we throw an exception
            if (index < 0 || index >= currentSize) {
                throw out_of_range("Index out of bounds");
            }
            return array[index];
        }

        // Getters
        int getCurrentSize() const {
            return currentSize;
        }
};

// Manager Class (Owns a dynamic array of Person's pointers)
class School {
    // Private Members
    private:
        // Calling an instance of the class template
        DynamicArray<Person> people;
    // Public Members
    public:
        // Default Constructor
        School():people(10) {
            // Initializing the dynamic array with size of 10
        }
        // Adding a Person (Student or Teacher) to the School
        void addPerson(Person* p) {
            people += p; // Using the overload += operator to add a person pointer
        }

        // Removing a Person from school
        void removePerson(int index) {
            try {
                people -= index; // Using the overload -= operator to remove a person pointer
            }
            catch (const out_of_range& ex) {
                cout << "Error: " << ex.what() << endl;
            }
        }

        // Accessing a Person at a specific index
        const Person* getPerson(int index) const {
            try {
                return people[index]; // Using the overload [] operator
            }
            catch (const out_of_range& ex) {
                cout << "Error: " << ex.what() << endl;
                return nullptr;
            }
        }

        // Print All People in the School Polymorphically
        void printAllPeople() const {
            for (int i = 0; i < people.getCurrentSize(); i++) {
                try {
                    people[i]->print();
                }
                catch (const out_of_range& ex) {
                    cout << "Error printing the person at index " << i << ": " << ex.what() << endl;
                }
            }
        }

};

// Exception Class for Invalid Difficulty Level in the Quiz
// Inherits from the Exception Class
class InvalidDifficultyLevelException: public exception {
    private:
        string message;
    public:
        InvalidDifficultyLevelException(string message){
            this->message = message;
        }
        const char* what() const noexcept {
            return message.c_str();
        }
};


// Function Templates for finding the maximum of three values
// Type can be any data type (int, double, float, char etc.)
template <class T>
T findMax(T a, T b, T c)
{
    if (a >=b && a >= c) {
        return a;
    }
     else if (b >= a && b >= c) {
        return b;
    } 
    else {
        return c;
    }
}
// Struct Definition (Global Scope)
struct LearnerProfile {
    string name;
    string favoriteMathSubject;
    int problemsSolvedPerWeek;
    int confidenceLevel;
    double hoursSpentStudyingPerWeek;
};


// Declaring a constant for number of questions asked on the quiz
const int NO_OF_QUESTIONS = 5;
// Some Color Codes as Constants
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string RESET = "\033[0m";

// Constants for array size
const int NUMBER_OF_TEST_SCORES = 5;

// Function prototypes

void changeConsoleTextColor(string color);

void displayWelcomeBanner();

void collectUserInfo(LearnerProfile& learner);

double calculateEstimatedProblemsPerHour(LearnerProfile& learner);

void userInputReportFile(ofstream& userOutputFile, LearnerProfile& learner, double& estimatedProblemsPerHour, double testScores[], double& averageTestScores);

double averageTestScores(double testScorees[], int size);

void mathQuiz(int& noOfCorrectAnswers, char quizDifficultyLevel);

void quizFeedback(int& confidenceLevel, int& noOfCorrectAnswers);

void displayStudentFavoriteSubjects(string favoriteSubjects[], const int NUMBER_OF_FAVORITE_SUBJECTS);

// Helper Function for Unit Testing for ENUM Decision Logic
int getMaxRandomNumberForDifficulty(char difficultyLevel)
{
    switch(difficultyLevel) {
        case EASY:
            return 10;
        case MEDIUM:
            return 100;
        case HARD:
            return 1000;
        default:
            return 10; // For invalid input/guard case
    }
}
// For Unit Testing
#ifdef RUN_TESTS
    #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
    #include "doctest.h"

    // New Updated Unit Tests
    TEST_CASE("Equality operator - equal teachers") {
        Teacher t1("Brown","Alice",35,HAPPY,"Physics",1,9,2010);
        Teacher t2("White","Bob",40,NEUTRAL,"Physics",2,5,2015);

        CHECK(t1 == t2);  // same teachingSubject → equal
    }

    TEST_CASE("Equality operator - not equal teachers") {
        Teacher t1("Brown","Alice",35,HAPPY,"Physics",1,9,2010);
        Teacher t2("White","Bob",40,NEUTRAL,"Math",2,5,2015);

        CHECK_FALSE(t1 == t2);
    } 
    TEST_CASE("<< operator works for Teacher") {
        Teacher t("Brown","Alice",35,HAPPY,"Physics",1,9,2010);

        std::ostringstream out;
        out << t;
        CHECK(out.str().find("Physics") != std::string::npos);
    }

    TEST_CASE("DynamicArray [] valid index") {
        DynamicArray<Person> arr;

        Student* s = new Student("Smith","John",20,HAPPY,"S100",'A',95,"Math");
        arr += s;

        CHECK(arr[0] == s);
    }
    TEST_CASE("DynamicArray += increases size") {
        DynamicArray<Person> arr;

        arr += new Student("Smith","John",20,HAPPY,"S100",'A',95,"Math");

        CHECK(arr.getCurrentSize() == 1);
    }

    TEST_CASE("DynamicArray -= removes and shifts") {
        DynamicArray<Person> arr;

        Student* s1 = new Student("Smith","John",20,HAPPY,"S100",'A',95,"Math");
        Student* s2 = new Student("Doe","Jane",22,NEUTRAL,"S200",'B',85,"Biology");

        arr += s1;
        arr += s2;

        arr -= 0;  // remove first

        CHECK(arr.getCurrentSize() == 1);
        CHECK(arr[0] == s2);
    }

    TEST_CASE("Function template findMax with int") {
        CHECK(findMax(3,7,5) == 7);
    }

    TEST_CASE("Function template findMax with double") {
        CHECK(findMax(2.5,9.1,4.2) == doctest::Approx(9.1));
    }

    TEST_CASE("Class template DynamicArray resizing") {
        DynamicArray<int> arr(1);

        arr += new int(10);
        arr += new int(20);  // forces resize

        CHECK(arr.getCurrentSize() == 2);
        CHECK(*arr[0] == 10);
        CHECK(*arr[1] == 20);
    }
    
    TEST_CASE("DynamicArray operator[] - throws on empty array") {
    DynamicArray<Person> arr;
    CHECK_THROWS_AS(arr[0], out_of_range);
    }

    TEST_CASE("DynamicArray operator[] - throws on out of bounds index") {
        DynamicArray<Person> arr;
        arr += new Student("Smith", "John", 20, HAPPY, "S100", 'A', 95, "Math");
        CHECK_THROWS_AS(arr[5], out_of_range);
    }

    TEST_CASE("DynamicArray operator[] - throws on negative index") {
        DynamicArray<Person> arr;
        arr += new Student("Smith", "John", 20, HAPPY, "S100", 'A', 95, "Math");
        CHECK_THROWS_AS(arr[-1], out_of_range);
    }

    TEST_CASE("DynamicArray operator[] - no throw on valid index") {
        DynamicArray<Person> arr;
        arr += new Student("Smith", "John", 20, HAPPY, "S100", 'A', 95, "Math");
        CHECK_NOTHROW(arr[0]);
    }

    // ===== DynamicArray operator-= Tests =====

    TEST_CASE("DynamicArray operator-= throws on empty array") {
        DynamicArray<Person> arr;
        CHECK_THROWS_AS((arr -= 0), out_of_range);
    }

    TEST_CASE("DynamicArray operator-= throws on invalid index") {
        DynamicArray<Person> arr;
        arr += new Student("Smith", "John", 20, HAPPY, "S100", 'A', 95, "Math");
        CHECK_THROWS_AS((arr -= 5), out_of_range);
    }

    TEST_CASE("DynamicArray operator-= throws on negative index") {
        DynamicArray<Person> arr;
        arr += new Student("Smith", "John", 20, HAPPY, "S100", 'A', 95, "Math");
        CHECK_THROWS_AS((arr -= -1), out_of_range);
    }

    TEST_CASE("DynamicArray operator-= no throw on valid index") {
        DynamicArray<Person> arr;
        arr += new Student("Smith", "John", 20, HAPPY, "S100", 'A', 95, "Math");
        CHECK_NOTHROW((arr -= 0));
    }
    // Test cases for the recursive function calculateYearsOfExperience
    TEST_CASE("Checking for valid input"){
        Teacher t1("Brown", "Alice", 35, HAPPY, "Physics", 1, 9, 2010);
        CHECK(t1.calculateYearsOfExperience(2026) == 16);
    }
    TEST_CASE("Checking for invalid input"){
        Teacher t1("John", "Bob", 25, HAPPY, "Biology", 1, 9, 2030);
        CHECK(t1.calculateYearsOfExperience(2026) == 0);
    }
    TEST_CASE("Bubble Sort on an Empty Vector") {
        Student s1;
        s1.bubbleSortScores();
        CHECK(s1.getNumberOfScores() == 0);
    }

    TEST_CASE("Bubble sort on a single element vector") {
        Student s1;
        s1.addTestScores(75);
        s1.bubbleSortScores();
        CHECK(s1.getScoreAt(0) == 75);
    }
    TEST_CASE("Bubble sort on a multiple elements vector") {
        Student s1;
        s1.addTestScores(75);
        s1.addTestScores(30);
        s1.addTestScores(55);
        s1.addTestScores(90);
        s1.bubbleSortScores();
        vector<int> expected = {30, 55, 75, 90};
        for (int i = 0; i < s1.getNumberOfScores(); i++) {
            CHECK(s1.getScoreAt(i) == expected[i]);
        }
    }
    TEST_CASE("Linear search for element in vector") {
        Student s1;
        s1.addTestScores(65);
        s1.addTestScores(75);
        s1.addTestScores(85);
        s1.addTestScores(90);
    
        CHECK(s1.linearSearchScores(85) == 2);
        CHECK(s1.linearSearchScores(100) == -1);
        CHECK(s1.linearSearchScores(65) == 0);
    }
    TEST_CASE("Binary search for element in unsorted vector") {
        Student s1;
        s1.addTestScores(85);
        s1.addTestScores(65);
        s1.addTestScores(90);
        s1.addTestScores(75);
        
        // binarySearch automatically sorts first
        CHECK(s1.binarySearchScores(85) == 2);
        CHECK(s1.binarySearchScores(65) == 0);
        CHECK(s1.binarySearchScores(100) == -1); 
    }

#endif

#ifndef RUN_TESTS
int main(){

    // Creating a Person pointer and poiting it to a student object to demonstrate polymorphism
    //Person* person1 = new Student("Smith", "John", 20, HAPPY, "S100", 'A', 95, "Math");
    // Both does the same work
    // Testing Purpose
    //cout << *person1 << endl; // Using the overloaded << operator by dereferencing the pointer
    //person1->toStream(cout); // Pointer calling the virtual function
    
    // Calling the function which displays a welcome banner to the user
    displayWelcomeBanner();

    // Declaring some variables
    LearnerProfile userData;
    double userEstimatedProblemsPerHour = 0.0;

    // Can't create an object of the Person class as it is an abstract class due to a pure virtual function.
    //Person p;
    // ----------------

    
    // Calling the 'Collect User Info' function to get the user's input
    collectUserInfo(userData);

    // Calling the function to calculate the user's estimated time solving each problem
    userEstimatedProblemsPerHour = calculateEstimatedProblemsPerHour(userData);

    // Using an array to store user's last five test scores
    double userTestScores[NUMBER_OF_TEST_SCORES];

    cout << userData.name << ", please enter your last five " << userData.favoriteMathSubject << "'s test scores: " << endl << endl;
    for (int i = 0; i < NUMBER_OF_TEST_SCORES; i++) {
        // Input Validation for each score using a do...while loop
        double score;
        bool isValid = false;
        do {
            cout << "Test Score " << i + 1 << ": ";
            if (cin >> score && score >= 0.0 && score <= 100.0) {
                userTestScores[i] = score;
                isValid = true;
            } else {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Test Score. Please Enter a score between 0 to 100.\n";
            }
        } while(!isValid);
    }
    cout << endl;
    // Calculating and displaying the average test score
    double totalScores = 0.0;
    double userAverageTestScore = 0.0;
    for (int i = 0; i < NUMBER_OF_TEST_SCORES; i++) {
        totalScores += userTestScores[i];
    }
    userAverageTestScore = totalScores / NUMBER_OF_TEST_SCORES;
    cout << fixed << showpoint << setprecision(2);
    cout << userData.name << ", your average test score in " << userData.favoriteMathSubject << " is: " << userAverageTestScore << endl << endl;


    // File Handling
    ofstream outputFile;

    // Calling the Function for saving the user info to a separate text file
    userInputReportFile(outputFile, userData, userEstimatedProblemsPerHour, userTestScores, userAverageTestScore);

    // Calling the function to insert and display user's favorite subjects using an array
    const int NUMBER_OF_FAVORITE_SUBJECTS = 3;
    string userFavoriteSubjects[NUMBER_OF_FAVORITE_SUBJECTS];
    displayStudentFavoriteSubjects(userFavoriteSubjects, NUMBER_OF_FAVORITE_SUBJECTS);

    // Math Quiz
    cout << "Please Complete the Following Five Quesitions Math Quiz: \n" << endl;


    // Seeding the random number generator once
    srand(time(0));

    // Variable Declaration
    int numberOfCorrectAnswers = 0;

    // Using /a for loop for calling the mathQuiz functions
    // Using the InvalidDifficultyLevelException for handling invalid difficulty level
    char quizDifficultyLevel;
    do {
        cout << "Enter difficulty level for the quiz (E for Easy, M for Medium or H for Hard): ";
        cin >> quizDifficultyLevel;
        cout << endl;

        try {
            if (quizDifficultyLevel != EASY && quizDifficultyLevel != MEDIUM && quizDifficultyLevel != HARD) {
                throw InvalidDifficultyLevelException("Invalid Difficulty Level!");
            }
            for (int i = 1; i <= NO_OF_QUESTIONS; i++) {
                mathQuiz(numberOfCorrectAnswers, quizDifficultyLevel);
            }
            break; // Exit the loop
        }
        catch(const InvalidDifficultyLevelException& ex) {
            cout << "Exception Caught: " << ex.what() << endl;
            cout << "Please Enter a Valid Difficulty Level." << endl;
        }
    } while (true);
    cout << endl;

    // Calling the quizFeedback function
    quizFeedback(userData.confidenceLevel, numberOfCorrectAnswers);
    cout << endl;

    // Class Objects and Inheritance
    Student student1("Rahman", "Zakaria", 20, HAPPY, "123456", 'A', 94, "Physics");

    Teacher teacher1("Koss", "John", 45, NEUTRAL, "Computer_Science", 20, 5, 2003);

    // Printing the Student and Teacher's Information using the print function
    cout << "----- Inheritance and Composition Demonstration -----\n" << endl;
    student1.print();
    cout << endl;
    teacher1.print();
    cout << endl;
    
    return 0;
}
#endif


// Function that change the console's text color
// Credit to AI and YouTube Videos
void changeConsoleTextColor(string color) {
    cout << color;
}

// Function that displays the welcome banner to the user
void displayWelcomeBanner(){
    // calling the function to change the color of the console's text
    changeConsoleTextColor(YELLOW);

    // Welcome Message
    cout << left << setfill('-') << setw(100) << "" << endl << endl;
    cout << "Welcome to the Math Aptitude Analyzer! Sharpen your Math skills and discover your true potential!" << endl << endl;
    cout << "Get ready to challenge yourself and see how strong your math skills really are!" << endl << endl;
    cout << "Please enter the following information as prompted. Thank you!" << endl << endl;
    cout << left << setfill('-') << setw(100) << "" << endl << endl;

    // Changing the color back to default
    changeConsoleTextColor(RESET);
}

// Function that collects and validates the data from the user
void collectUserInfo(LearnerProfile& learner) 
{
    // Prompts the user for inputs

    cout << "Enter your full name: ";
    getline(cin, learner.name);
    cout << endl;

    cout << "Enter your favorite Math Subject: ";
    getline(cin, learner.favoriteMathSubject);
    cout << endl;

    // Input Validation using while loop

    cout << "Enter the number of Math Problems Solved Per Week: ";

    while (!(cin >> learner.problemsSolvedPerWeek)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Input. Please enter a whole number: " << endl;
    }
    cout << endl;

    cout << "On a scale of 1 to 10, how confident are you in Math (1 being least and 10 being the most): ";

    while(!(cin >> learner.confidenceLevel) || learner.confidenceLevel < 1 || learner.confidenceLevel > 10){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Input. Please enter a number between 1 - 10: ";
    }
    cout << endl;

    cout << "Enter number of hours studying Math per week: ";

    while (!(cin >> learner.hoursSpentStudyingPerWeek) || learner.hoursSpentStudyingPerWeek < 1 || learner.hoursSpentStudyingPerWeek > 168){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Input. Please enter a number between 1 to 168: ";
    }
    cout << endl;

}

// Function for Calculation
double calculateEstimatedProblemsPerHour(LearnerProfile& learner){
    
    // despite user entering 0 hours or negative hours, for unit testing purpose, we handle it here to avoid division by zero or negative hours
    if (learner.hoursSpentStudyingPerWeek <=0){
        learner.hoursSpentStudyingPerWeek = 1; // setting it to 1 by default to avoid division by zero or negative hours
    }
    return static_cast<double> (learner.problemsSolvedPerWeek) / learner.hoursSpentStudyingPerWeek;
}

// Function for Writing User's Input to an Output txt file
void userInputReportFile(ofstream& userOutputFile, LearnerProfile& learner, double& estimatedProblemsPerHour, double testScores[], double& averageTestScores) {
    
    userOutputFile.open("report.txt");

    userOutputFile << fixed << showpoint << setprecision(2);

    userOutputFile << left << setfill(' ') << setw(50) << "Name:" << right << setw(20) << setfill(' ') << learner.name << endl;
    userOutputFile << left << setfill(' ') << setw(50) << "Favorite Math Subject:" << right << setw(20) << setfill(' ') << learner.favoriteMathSubject << endl;
    userOutputFile << left << setfill(' ') << setw(50) << "Confidence Level:" << right << setw(20) << setfill(' ') << learner.confidenceLevel << endl;
    userOutputFile << left << setfill(' ') << setw(50) << "# of Hours Studying Math:" << right << setw(20) << setfill(' ') << learner.hoursSpentStudyingPerWeek << endl;
    userOutputFile << left << setfill(' ') << setw(50) << "Estimated Problems Solved Per Hour:" << right << setw(20) << setfill(' ') << estimatedProblemsPerHour << endl;
    userOutputFile << left << setfill(' ') << setw(50) << "Test Scores-" << endl;
    for (int i = 0; i < NUMBER_OF_TEST_SCORES; i++) {
        userOutputFile << left << setfill(' ') << setw(50) << "Test Score " + to_string(i+1) + ": " << right << setw(20) << setfill(' ') << testScores[i] << endl;
    }
    userOutputFile << left << setfill(' ') << setw(50) << "Average Test Scores:" << right << setw(20) << setfill(' ') << averageTestScores << endl;


    userOutputFile.close();
}

// Function for asking the user some basic arithmetic problems
void mathQuiz(int& noOfCorrectAnswers, char quizDifficultyLevel) {
    int randomNum1, randomNum2;
    int result = 0;
    int userAnswer;
    char mathOperator;

    switch(quizDifficultyLevel) {
        case EASY:
            randomNum1 = (rand() % 10) + 1;
            randomNum2 = (rand() % 10) + 1;
            break;
        case MEDIUM:
            randomNum1 = (rand() % 100) + 1;
            randomNum2 = (rand() % 100) + 1;
            break;
        case HARD:
            randomNum1 = (rand() % 1000) + 1;
            randomNum2 = (rand() % 1000) + 1;
            break;
    }

    cout << "Enter a math operator (+, -, *, /, %): ";

    while (!(cin >> mathOperator) || (mathOperator != '+' && mathOperator != '-' && mathOperator != '*' && mathOperator != '/' && mathOperator != '%')){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Input. Please Enter a correct Math Operator: ";
    }
        cout << endl;

        switch(mathOperator) {
            case '+':
            result = randomNum1 + randomNum2;
            break;
        case '-':
            result = randomNum1 - randomNum2;
            break;
        case '*':
            result =randomNum1 * randomNum2;
            break;
        case '/':
            result = randomNum1 / randomNum2;
            break;
        case '%':
            result = randomNum1 % randomNum2;
            break;
        }

    cout << randomNum1 << " " << mathOperator << " " << randomNum2 << " = ";
    cin >> userAnswer;
    cout << endl;

    if (userAnswer == result){
        // using the console text color function
        changeConsoleTextColor(GREEN);

        cout << "Correct! Well Done!" << endl;

        changeConsoleTextColor(RESET);
        noOfCorrectAnswers++;
    } else{
        changeConsoleTextColor(RED);
        cout << "Wrong Answer! The correct answer was: " << result << endl;
        changeConsoleTextColor(RESET);
    }
    cout << endl;
}


// Function for getting a feedback based on confidence level and quiz results
void quizFeedback(int& confidenceLevel, int& noOfCorrectAnswers) {
    cout << "----- Quiz Feedback -----\n" << endl;


    // Using if/else blocks with compound boolean conditions
    if (noOfCorrectAnswers >= 4 && confidenceLevel >= 7) {
        cout << "Great! Your confidence matches your performance." << endl;
        cout << "You can try more advance problems!" << endl;
    }
    else if (noOfCorrectAnswers >= 3 && confidenceLevel >= 5) {
        cout << "Good work! Keep on practicing to improve." << endl;
        cout << "Solving more problems increases your confidence level." << endl;
    }
    else if (noOfCorrectAnswers >= 3 && confidenceLevel < 5) {
        cout << "Your performance is okay, but your confidence is low." << endl;
        cout << "Focus on building your confidence through consistent practice." << endl;
    }
    else if (noOfCorrectAnswers < 3 && confidenceLevel >=5) {
        cout << "You feel confident, but your performance shows the opposite." << endl;
        cout << "Practice fundamental concepts to match your confidence level." << endl;
    }
    else{
        cout << "Focus on basic concepts and fundamentals of Math." << endl;
        cout << "Practice regularly to improve your skills and confidence level." << endl;
    }

    cout << endl;
}

// Function to insert and display user's favorite subjects
void displayStudentFavoriteSubjects(string favoriteSubjects[], const int NUMBER_OF_FAVORITE_SUBJECTS) {

    cout << "Enter Your Favorite Subjects: " << endl;
    for (int i = 0; i < NUMBER_OF_FAVORITE_SUBJECTS; i++){
        cin >> favoriteSubjects[i];
    }
    cout << endl;

    cout << "Your Favorite Subjects are- " << endl;
    for (int i = 0; i < NUMBER_OF_FAVORITE_SUBJECTS; i++) {
        changeConsoleTextColor(YELLOW);
        cout << favoriteSubjects[i] << " ";
    }
    cout << endl << endl;
    changeConsoleTextColor(RESET);
}


// Base Class Parameterizes Constructor
Person::Person(string lName, string fName, int a, happinessLevelLife hLevel) {
    lastName = lName;
    firstName = fName;
    age = a;
    happinessLevel = hLevel;
}

// Setter Function
void Person::setPersonalInformation(string lName, string fName, int a, happinessLevelLife hLevel) {
    lastName = lName;
    firstName = fName;
    age = a;
    happinessLevel = hLevel;
}

// Print Function
void Person::print() const {
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Age: " << age << endl;
    cout << "Happiness Level with Life: ";
    switch (happinessLevel) {
        case SAD:
            cout << "Sad" << endl;
            break;
        case NEUTRAL:
            cout << "Neutral" << endl;
            break;
        case HAPPY:
            cout << "Happy" << endl;
            break; 
    }
}

// Derived Class Feedback Function
string Student::getFeedback() const {
    if (studentGrade == 'A' || studentTestScore >= 90){
        return "Excellent work! Keep up the high performance.";
    }
    else if (studentGrade == 'B' || studentTestScore >= 80){
        return "Good job! You are doing well, but there is room for improvement.";
    }
    else if (studentGrade == 'C' || studentTestScore >= 70) {
        return "Fair performance. Focus on improving weaker areas.";
    }
    else {
        return "Needs improvement. Consider extra practice and studying.";
    }
}

// Derived Class Print Function
void Student::print() const {
    Person:: print();
    cout << "Student ID: " << studentID << endl;
    cout << "Student Grade: " << studentGrade << endl;
    cout << "Student Test Score: " << studentTestScore << endl;
    cout << "Feedback: " << getFeedback() << endl;
}

// Bubble Sort Algorithm
void Student::bubbleSortScores() {
    int tempValue;
    // Converting the unsigned int to an int value
    int length = static_cast<int>(vectStudentTestScores.size());

    for (int iteration = 1; iteration < length; iteration++) {
        for (int index = 0; index < length - iteration; index++) {
            if (vectStudentTestScores[index] > vectStudentTestScores[index + 1]) {
                tempValue = vectStudentTestScores[index];
                vectStudentTestScores[index] = vectStudentTestScores[index + 1];
                vectStudentTestScores[index + 1] = tempValue;
            }
        }
    }
}

// Linear Search Algorithm
int Student::linearSearchScores(int keyScore) const {
    // Converting the unsigned int to an int value
    int length = static_cast<int>(vectStudentTestScores.size());
    for (int i = 0; i < length; i++) {
        if (vectStudentTestScores.at(i) == keyScore) {
            return i;
        }
    }
    return -1;
}

// Binary Search Algorithm
int Student::binarySearchScores(int keyScore){

    // Calling the Bubble Sort Function
    bubbleSortScores();
    // Converting the unsigned int to an int value
    int length = static_cast<int>(vectStudentTestScores.size());

    
    int low = 0;
    int high = length - 1;
    int middle;

    bool found = false;

    while (low <= high && !found) {
        middle = (low + high) / 2;

        if (vectStudentTestScores[middle] == keyScore) {
            found = true;
        }
        else if(vectStudentTestScores[middle] > keyScore) {
            high = middle - 1;
        }
        else {
            low = middle +1;
        }
    }

    if (found) {
        return middle;
    } else {
        return -1;
    }
}
