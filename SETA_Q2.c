#include <iostream>
#include <map>
#include <cctype>
#include <string>


bool isLetter(char ch) {
    return std::isalpha(static_cast<unsigned char>(ch));
}


char toLower(char ch) {
    return std::tolower(static_cast<unsigned char>(ch));
}

int main() {
 
    string paragraph;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);


   map<char, int> freqMap;


    for (char ch : paragraph) {
        if (isLetter(ch)) {
            char lowerCh = toLower(ch);
            freqMap[lowerCh]++;
        }
    }


    cout << "Character frequencies:\n";
    for (const auto& entry : freqMap) {
        std::cout << entry.first << ": " << entry.second << "\n";
    }

    return 0;
}


