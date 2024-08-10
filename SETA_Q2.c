#include <iostream>
#include <map>
#include <cctype>
#include <string>

// Function to check if a character is a letter
bool isLetter(char ch) {
    return std::isalpha(static_cast<unsigned char>(ch));
}

// Function to convert a character to lowercase
char toLower(char ch) {
    return std::tolower(static_cast<unsigned char>(ch));
}

int main() {
    // Read the paragraph from the user
    std::string paragraph;
    std::cout << "Enter a paragraph: ";
    std::getline(std::cin, paragraph);

    // Map to store character frequencies
    std::map<char, int> freqMap;

    // Iterate through each character in the paragraph
    for (char ch : paragraph) {
        if (isLetter(ch)) {
            char lowerCh = toLower(ch);
            freqMap[lowerCh]++;
        }
    }

    // Print the frequencies
    std::cout << "Character frequencies:\n";
    for (const auto& entry : freqMap) {
        std::cout << entry.first << ": " << entry.second << "\n";
    }

    return 0;
}


