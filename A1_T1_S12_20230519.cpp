// File:A1_T1_S12_20230519.cpp
// Purpose :In conclusion, this program is a versatile and interactive toolset designed for a variety of practical and educational purposes.
// It allows users to split strings, convert numbers to binary, play a simple logic game, and check for phishing keywords in email content. Through its user-friendly menu and color-coded interface,
// the program provides an engaging experience while offering functionalities that range from text processing to cybersecurity awareness

// Author:Youssef Yasser Elsayed
// Section:S12
// ID:20230519
// TA:
// Date: 10 Oct 2024

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"


void splitFunction();
void decimalToBinaryFunction();
void bearFunction();
void checkPhishingKeywordsFunction();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////// Split  function code///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
   This function splits a target string by a given delimiter.
   It keeps searching for the delimiter in the target string,
   cuts the string accordingly, and stores the parts in a vector.
*/


vector<string> split(string target, string delimiter) {
    vector<string> result;
    string item;

    
    while (true) {
        int index = target.find(delimiter);  // Find the delimiter in the string 
        if (index < 0) {  // If delimiter not found, break the loop
            break;  
        }

        item = target.substr(0, index);  // Extract substring before the delimiter
        result.push_back(item);            // Add the substring to the result vector
        target = target.substr(index + delimiter.length());  
    }

    result.push_back(target);  

    return result;
}
void splitFunction() {
    string target, delimiter;
    cout << CYAN << "Welcome to spliter " << RESET << endl ;
    cout << YELLOW << "Write the string to split: " << RESET;
    getline(cin, target);
    cout << YELLOW << "Write the delimiter string: " << RESET;
    getline(cin, delimiter);

    vector<string> result = split(target, delimiter);

    for (const auto& part : result) {
        cout << part << endl;
    }

    

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////// Decimal to binary function code//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class db {
public:
    static void decimal_to_binary(int n) {
        int binary[32];
        int i = 0;

        if (n == 0) {
            cout << "0";
            return;
        }

        while (n > 0) {
            binary[i] = n % 2;   // Store remainder (binary digit)
            n = n / 2;
            i++;
        }
        if(n < 0){
            cout << RED << "please enter a positive number! " << RESET ;
        } // Print the binary digits in reverse order to get the correct binary number
        for (int j = i - 1; j >= 0; j--) {
            cout << binary[j];
        }
        cout << endl;
    }
    // Recursive function to generate all binary numbers of length k
    static void numbers(string prefix, int k) {
        if (k == 0) {
            cout << prefix << endl;
            return;
        }
        if ( k < 0){
            cout << RED << "invalid ,please enter a positive integer number!" << RESET ;
        }
        numbers(prefix + "0", k - 1);
        numbers(prefix + "1", k - 1);
    }
};
/*
   Handles the user interaction for converting a decimal number to binary
   and generating binary numbers of a specified length.
*/
void decimalToBinaryFunction() {
    int n;
    cout << CYAN << "Welcome to decimal to binary conversion " << RESET << endl ;
    cout << YELLOW << "Enter a decimal number: " << RESET ;
    cin >> n;
    cin.ignore() ;

    db::decimal_to_binary(n);

    string binaryInput;
    int k;

    cout << MAGENTA << "Enter a binary number: " << RESET ;
    cin >> binaryInput;
    cin.ignore() ;

    cout << MAGENTA << "Enter the value of k: " << RESET ;
    cin >> k;

    cin.ignore() ;

    db::numbers(binaryInput, k);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////// Bears function code////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
   Applies a special condition on the last two digits of a number by taking the product of the digits
   and subtracting that from the original number.
*/

int applyLastTwoDigitsCondition(int x) {
    int lastTwoDigits = x % 100;
    int product = (lastTwoDigits / 10) * (lastTwoDigits % 10);
    return x - product;
}

/*
   Applies three different transformation rules to the given number x:
   1. Subtract 42 if x is divisible by 5.
   2. Divide by 2 if x is divisible by 2.
   3. Apply the last two digits condition if x is divisible by 3 or 4.
   Returns the largest result that is still greater than or equal to 42.
*/

int num(int x) {
    if (x == 42) {
        return x;
    }

    int option1 = (x % 5 == 0) ? (x - 42) : x;
    int option2 = (x % 2 == 0) ? (x / 2) : x;
    int option3 = (x % 3 == 0 || x % 4 == 0) ? applyLastTwoDigitsCondition(x) : x;

    int results[] = { option1, option2, option3 };

    for (int i = 0; i < 3; i++) {
        if (results[i] >= 42 && results[i] != x) {
            return results[i];
        }
    }

    return x;
}

/*
   Handles the bear counting game where a number of bears is reduced by applying rules
   until it reaches 42 or no further conditions can be applied.
*/

void bearFunction() {
    int x;
    cout << CYAN << "︶꒦꒷♡꒷꒦︶ welcome to the bear counting game ︶꒦꒷♡꒷꒦︶ " << RESET << endl ;
    cout << CYAN << "Enter the number of bears: " << RESET ;
    cin >> x;
    cin.ignore();
    cout << RED << "Bears left: "<< RESET  << x << endl;

    while (x > 42) {     // Loop until the number reaches 42 or no more transformations are possible
        if (x == 42) {
            cout << GREEN << "True" << RESET << endl;
            break;
        }

        int previous = x;
        x = num(x);

        if (x == previous) {
            cout << RED << "No further conditions can be applied, stuck at: " << RESET  << x << endl;
            break;
        }
        
        cout << RED << "Bears left: " << RESET << x << endl;

        if( x == 42){
            cout << GREEN << "True" << RESET << endl ;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////// Phishing keywords function code////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
   The phishing_keywords map stores common phishing phrases along with their respective point values.
   Higher points indicate phrases that are more indicative of phishing.
*/

map<string, int> phishing_keywords = {
    {"update your information", 3}, {"account locked", 3}, {"immediate action required", 3},
    {"verify your account", 3}, {"confirm your identity", 3}, {"password expired", 3},
    {"account suspension", 3}, {"unauthorized access", 3}, {"risk of account closure", 3},
    {"immediate verification needed", 3}, {"bank account update", 3}, {"receive a payment", 3},
    {"money transfer", 3}, {"claim your prize", 3}, {"free gift", 3}, {"important update", 3},
    {"account verification required", 3}, {"new login attempt", 3}, {"security breach", 3},
    {"your action is required", 3}, {"confirm your email", 2}, {"follow the link", 2},
    {"account verification", 2}, {"billing problem", 2}, {"payment confirmation", 2},
    {"click to unblock", 2}, {"important account notification", 2}, {"free trial", 2},
    {"account activity alert", 2}, {"reset password", 2}, {"download now", 2},
    {"exclusive offer", 2}, {"verify your details", 2}, {"unusual sign-in activity", 2},
    {"you have been selected", 2}, {"update required", 2}, {"account information needed", 2},
    {"limited access", 2}, {"password reset link", 2}, {"subscription update", 2},
    {"customer service", 1}, {"contact support", 1}, {"thank you for your order", 1},
    {"order status", 1}, {"sign in", 1}, {"get paid", 1}, {"newsletter subscription", 1},
    {"special promotion", 1}, {"account management", 1}, {"request for information", 1}
};

string to_lowercase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

/*
   Handles user interaction for checking an email for phishing keywords.
   Prompts the user to enter the email content, then calls the checkPhishingKeywords function.
*/

void check_phishing_keywords(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No file found" << endl;
        return; 
    }

    string text = "";
    string line;
    while (getline(file, line)) {
        text += to_lowercase(line) + " ";
    }

    map<string, int> keyword_count;
    int total_points = 0;

    for (const auto& keyword_pair : phishing_keywords) {
        string keyword = keyword_pair.first;
        int points = keyword_pair.second;
        int position = text.find(keyword);
        int count = 0;

        while (position != -1) {
            count++;
            position = text.find(keyword, position + keyword.length());
        }

        if (count > 0) {
            keyword_count[keyword] = count;
            total_points += count * points;
        }
    }

    cout << GREEN << "Number of occurrences:\n" << RESET ;
    for (const auto& entry : keyword_count) {
        cout << " " << entry.first << RED << " found " << RESET << entry.second << RED << " times. Points: " << RESET
             << entry.second * phishing_keywords[entry.first] << endl;
    }
    cout << CYAN << "Total phishing points: " << total_points << RESET << endl;
}

void checkPhishingKeywordsFunction() {
    string filename;
    cout << CYAN << "𖨆♡𖨆 Welcome to phishing keywords scanner 𖨆♡𖨆 " << RESET << endl ;
    cout << YELLOW << "Enter the filename to check for phishing keywords: " << RESET;
    cin >> filename;
    cin.ignore();

    check_phishing_keywords(filename);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////// Main code /////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*
   The main function serves as the entry point to the program.
   It presents a menu for the user to select one of the available functionalities.
*/

int main() {
    string input;

    while (true) {
        cout << RED << "'*•.¸♡Menu♡¸.•*'" << RESET << endl;
        cout << GREEN << "1. Split a string" << RESET << endl;
        cout << GREEN << "2. Convert decimal to binary"<< RESET << endl;
        cout << GREEN << "3. Bear counting game"<< RESET << endl;
        cout << GREEN << "4. Check for phishing keywords in a file"<< RESET << endl;
        cout << GREEN << "5. Exit" << RESET << endl;
        cout << MAGENTA << "Enter your choice: "<< RESET;
        getline(cin, input); 
    

        if (input == "1") {
            splitFunction();
        } else if (input == "2") {
            decimalToBinaryFunction();
        } else if (input == "3") {
            bearFunction();
        } else if (input == "4") {
            checkPhishingKeywordsFunction();
        } else if (input == "5") {
            cout << RED << "Exiting program...." << RESET << endl;
            return 0;
        } else {
            cout << RED << "Invalid choice. Please try again."<< RESET << endl;
        }

        cout << endl; 
    }

    return 0;
}
