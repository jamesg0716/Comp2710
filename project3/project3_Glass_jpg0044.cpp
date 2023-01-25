/*
* Name: James Glass
* AU Email: jpg0044@auburn.edu
* FileName: project3_Glass_jpg0044.cpp
* Compiler: g++ project3_Glass_jpg0044.cpp -o project3.out
* Run: ./project3.out
* Sources:
* 1. Used https://www.geeksforgeeks.org/converting-strings-numbers-cc/ 
*    to implement the stringstream in the read_file method to convert string to int.
* 2. Used Project3_hint.pdf for the basic layout of the program.
* 3. Used Handout3_updated.pdf for <iostream> and <fstream> implementation.
* 4. Used Lec4.pdf for the different file open modes.
*/
 
#include <fstream> 
#include <iostream> 
#include <vector>
#include <string> 
#include <sstream>
using namespace std; 

//*******************************************
//***********METHOD_PROTOTYPES***************
//*******************************************

/* declare your user-defined functions */ 
/* do not forget to describe each function */
bool check_file(string);  
vector<int> read_file(string); 
void write_file(string, vector<int>); 
vector<int> merge(vector<int>, vector<int>); 
 
/* 
* Display the values of a given vector. 
* 
* Param: file Name of file to display. (string) 
* Param: v Vector containing values to display. (vector<int>) 
*/ 
void to_string(string, vector<int>); 
 
 
 
/* 
* Merge the numbers in two specified files and write all the numbers 
* to a specified third file sorted in ascending order. 
* 
* Return: 1 Program completed successfully. (int) 
*/ 

//*******************************************
//*************MAIN_FUNCTION*****************
//*******************************************

int main() { 
 /* declare your variables */ 
string file_1_input;
string file_2_input;
string main_file_output;
vector<int> numbers_file_1;
vector<int> numbers_file_2;
vector<int> numbers_file_3;

cout << "*** Welcome to James's sorting program ***" << endl;
 
 /* Get name of file one. */ 
 do { 
       cout << "Enter the first input file name: ";
       cin >> file_1_input;
  /* user friendly interfaces */ 
 } while (cin.fail() || !check_file(file_1_input)); 
 
 /* Get and display numbers from file one. */ 
 numbers_file_1 = read_file(file_1_input); 
 cout << "The list of " << numbers_file_1.size()
 << " numbers in file " << file_1_input << " is:" << endl;
 to_string(file_1_input, numbers_file_1);

 
 /* Get name of file two. */ 
 do { 
      cout << "Enter the second input file name: ";
      cin >> file_2_input;
  /* user friendly interfaces */ 
 } while (cin.fail() || !check_file(file_2_input)); 
 
 /* Get and display numbers from file two. */ 
 numbers_file_2 = read_file(file_2_input); 
 cout << "The list of " << numbers_file_2.size() 
 << " numbers in file " << file_2_input << " is:" << endl;
 to_string(file_2_input, numbers_file_2);
  
 
 /* Combine vectors and display the sorted result. */ 
 numbers_file_3 = merge(numbers_file_1, numbers_file_2); 
  
 cout << "The sorted list of " << numbers_file_3.size()
 << " numbers is: ";

 for (int i = 0; i < numbers_file_3.size(); i++) {
      cout << numbers_file_3[i] << " ";
 }
 cout << endl;
 /* Get name of output file. */ 
 do { 
     cout << "Enter the output file name: ";
     cin >> main_file_output;
  /* user friendly interfaces */ 
 } while (cin.fail()); 
 
 /* Write combined vector to output file. */ 
 write_file(main_file_output, numbers_file_3);
 cout << "*** Please check the new file - " << main_file_output
 << " ***" << endl;
 cout << "*** Goodbye. ***";
 
} 
 
//*******************************************
//****************MY_METHODS*****************
//*******************************************

// Checks for a proper existing file. 
bool check_file(string file) { 
 /* Input file input_stream. (ifstream) */ 
 ifstream input_stream; 
 
 /* Check whether file exists. */ 
 input_stream.open(file.c_str()); 
 if (input_stream.fail()) { 
      cout << "Error: could not open file" << endl;
      return false;
 } 
 input_stream.close(); 
 return true; 
} 

// Converts input file to a proper vector format. 
vector<int> read_file(string file) { 
 /* Input file input_stream. (ifstream) */ 
 ifstream input_stream; 
 
 /* Vector containing numbers from file. (vector<int>) */ 
 vector<int> v; 
 
 /* Integer read from file. (int) */ 
 int i;

 string num; // The string of each number in the file 
 
 /* Add each number in the file to a vector. */ 
 input_stream.open(file.c_str()); 
 if (input_stream.fail()) {
      cout << "Error: could not read file" << endl;
 }
 else {
      while (input_stream >> num) { 
            istringstream(num) >> i;
            v.push_back(i);
      }
 } 
 input_stream.close();
 return v; 
} 
 

void write_file(string file, vector<int> v) { 
     /* Output file input_stream. (ofstream) */
     ofstream output_stream;
     output_stream.open(file.c_str());
     if (output_stream.fail()) {
          cout << "Error: could not write file." << endl;
     } 
     else {
          for (int i = 0; i < v.size(); i++) {
               output_stream << v[i] << endl;
          }
     }
     output_stream.close();
} 
 
vector<int> merge(vector<int> v1, vector<int> v2) { 
  
     vector<int> v3;
     /* Vector interator numbers. (unsigned short) */ 
     unsigned short i;
     unsigned short j; 
 
 /* Compare both vectors. */ 
 while (v1.size() > 0 && v2.size() > 0) { 
  if (v1.at(0) < v2.at(0)) { 
      v3.push_back(v1.at(0));
      v1.erase(v1.begin());
  } else { 
       v3.push_back(v2.at(0));
       v2.erase(v2.begin());
  } 
 } 
 
 /* Add any remaining numbers from vector one. */ 
 if (v1.size() > 0) { 
   j = v1.size();
   for (i = 0; i < j; i++) {
        v3.push_back(v1.at(0));
        v1.erase(v1.begin());
   }
 } 
 
 /* Add any remaining numbers from vector two. */ 
 if (v2.size() > 0) { 
   j = v2.size();
   for(int i = 0; i < j; i++) {
        v3.push_back(v2.at(0));
        v2.erase(v2.begin());
   }
 }   
 return v3; 
} 
 
void to_string(string file, vector<int> v) { 
/* Display the numbers contained in a vector. */
ofstream stream;
stream.open(file.c_str());
if (stream.fail()) {
     cout << "Error: Could not open the desired file." << endl;
} 
else {
     for (int i = 0; i < v.size(); i++) {
          cout << v[i] << endl;
     }
}
  cout << endl;
}