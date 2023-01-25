/* 
* Name: James Glass
* AU Email: jpg0044@auburn.edu
* Filename: project4_Glass_jpg0044.cpp
* Compiler: g++ project4_Glass_jpg0044.cpp -o project4.out
* Run: ./project4.out
* Sources: 
* 1. Used Visual Studio Code as text editor.
* 2. Used Project4_hint.pdf for the basic formatting and hints for the project.
* 3. Used https://www.geeksforgeeks.org/pointers-c-examples/ for help with pointers.
*/ 
//Libary imports. 
#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
#include <climits> 
using namespace std; 
 
 
//Structure for creating a linked list that holds a trivia question,answer and point amount. 
struct trivia_node { 
 string question; 
 string answer; 
 int point; 
 trivia_node *next; 
 
}; 

//creates a pointer to triva_node. 
typedef trivia_node* ptr_node; 
 
//Prototypes 
void init_question_list(ptr_node&);
void add_question(ptr_node&);
int ask_question(ptr_node, int);
void Unit_test();
void clear();

//Variables
int num_of_questions;
int point_total = 0;
 
//creates two versions. 
//#define UNIT_TESTING 
#define trivia_quiz 
 
int main() {  
 ptr_node node_list = new trivia_node; 
 string user_input = "Yes";

 //Creates a new trivia game / 
 //Sets up three original  questions/ 
 //Sets up loop for user to input his or her own questions. 
 //Quiz questions are stored in linked list. 
#ifdef trivia_quiz 
 init_question_list(node_list); 
 
 cout << "*** Welcome to James's trivia quiz game ***\n"; 
 while (user_input == "yes" || user_input == "Yes") {
     add_question(node_list);
     cout << "Continue? (Yes/No): ";
        cin >> user_input;
        clear();
 } 
 
 //This is start of Trivia quiz game. 
 ask_question(node_list, num_of_questions); 
 cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***"; 
 return 0; 
 
#endif 
//Method for testing 
#ifdef UNIT_TESTING 
 
 Unit_Test(); 
 return 0; 
 
#endif 
} 
 
 
//initializes the quiz to have these three questions inputted into the linked list. 
void init_question_list(ptr_node& q_list) { 
 //ptr_node cur_ptr; 
 //ptr_node cur_ptr; 
    ptr_node cur_ptr = new trivia_node;
    cur_ptr->question = "How long was the shortest war on record?";
    cur_ptr->answer = "38";
    cur_ptr->point = 100;
    cur_ptr->next = new trivia_node;
    q_list = cur_ptr;

    cur_ptr = q_list->next;
    cur_ptr->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    cur_ptr->answer = "Bank of Italy";
    cur_ptr->point = 50;
    cur_ptr->next = new trivia_node;
    
    cur_ptr = cur_ptr->next;
    cur_ptr->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
    cur_ptr->answer = "Wii Sports"; 
    cur_ptr->point = 20;
    cur_ptr->next = NULL;

    num_of_questions = 3; 
} 
//gives user the option to add a question to the linked list. 
//question is added to the front of the linked list. 
void add_question(ptr_node& q_list) { 
ptr_node new_ptr = new trivia_node;

    cout << "Enter a question: ";
    getline(cin, new_ptr->question);

    cout << "Enter an answer: ";
    getline(cin, new_ptr->answer);

    cout << "Enter points awarded: ";
    cin >> new_ptr->point;

    new_ptr->next = q_list;
    q_list = new_ptr;
    num_of_questions++; 
 
} 
//Checks for null value 
//Ask the user trivia questions and starts the game 
int ask_question(ptr_node q_list, int num_ask) { 
ptr_node cur_ptr = new trivia_node;
    string user_answer;
    cur_ptr = q_list;

    if (q_list == NULL) {
        return 0;
    }
    
    if (num_ask < 1) {
        cout << "Warning - The number of trivia to be asked must be "
             << "equal to or greater than 1.";
        return 1;
    } 
    else if (num_of_questions < num_ask) {
        cout << "Warning - There is only " << num_of_questions
             << " trivia in the question list.";
        return 1;
    }
    else {
        cout << "\n";
        for (int i = 0; i < num_ask; i++) {
            cout << "Question: " << cur_ptr->question << endl;
            cout << "Answer: "; 
            getline(cin, user_answer);
            if (user_answer.compare(cur_ptr->answer) == 0) {
                cout << "Your answer is correct. You receive "
                     << cur_ptr->point << " points.\n";
                point_total += cur_ptr->point;

                cout << "Your total points: " << point_total << endl;
            }
            else {
                cout << "Your answer is wrong. Correct answer is: "
                     << cur_ptr->answer << endl;
                
                cout << "Your total points: " << point_total << endl;
            }

            cur_ptr = cur_ptr->next;
            clear();
        }
    }
    return 0;
} 
 
 
 
//Test cases to check whether the methods work. 
void Unit_test() {
    ptr_node node_list = new trivia_node;
    init_question_list(node_list);

    cout << "*** This is a debugging version ***" << endl;
    cout << "Unit Test Case 1: Ask no question. "
         << "The program should give a warning message. "
         << endl;
    assert(ask_question(node_list, 0) == 1);
    cout << "\nCase 1 Passed\n\n";

    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. "
         << "The tester enters an incorrect answer."
         << endl;
    ask_question(node_list, 1);
    assert(point_total == 0);
    cout << "Case 2.1 Passed\n\n"; 

    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. "
         << "The tester enters the correct answer."
         << endl;
    ask_question(node_list, 1);
    assert(point_total == 100);
    cout << "Case 2.2 Passed\n\n";
    point_total = 0;

    cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list."
         << endl; 
    ask_question(node_list, 3);
    assert(num_of_questions == 3);
    cout << "Case 3 Passed\n\n";

    cout << "Unit Test Case 4: Ask 5 questions in the linked list."
         << endl;
    int num_ask = 5;
    assert(ask_question(node_list, num_ask) == 1);
    cout << "\nCase 4 Passed\n\n";

    cout << "*** End of debugging version ***" << endl;
}

void clear() {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}