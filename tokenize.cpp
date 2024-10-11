#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm> // for std::find

std::string removeSpaces(const std::string& input) {
    std::stringstream ss(input);
    std::string word;
    std::string result;

    std::string line;

    while (ss >> word) {
        
        if (word.length() >= 2) {

            if (word.substr(0, 2) == "//") {
                // Skip the entire line
                std::getline(ss, line); // Read and discard the rest of the line
                continue;
            }

        }
        
        result += word + " ";

    }

    std::cout << "Comment: " << line << std::endl;

    return result;
}

std::string addSpaces(const std::string& input) {

    std::vector<std::string> keywords = { "else", "using", "if", "int", "return", "void" };
    std::vector<std::string> operators = { "+", "-", "=", "==", "!=", ">>", "<<" };
    std::vector<std::string> literals = { "5", "10", "20", "0", "\"Hello!\"", "\"Number is greater than 5\"", "\"Number is less than or equal to 5\"" };

    std::vector<std::string> identifiers = { "cout", "greet", "main", "endl", "std", "number" };
    std::vector<std::string> separators = { ";", ",", "(", ")", "{", "}", "::" };

    std::stringstream ss(input);
    std::string word;
    std::string result;

    while (ss >> word) {
        // Logic for adding spaces based on keywords and separators
        for (const auto& keyword : keywords) {
            if (word.find(keyword) == 0) {
                result += keyword + " ";
                word = word.substr(keyword.length());
            }
        }


        for (const auto& identifier : identifiers) {
            if (word.find(identifier) == 0) {
                result += identifier + " ";
                word = word.substr(identifier.length());
            }
        }

        for (const auto& literal : literals) {
            if (word.find(literal) == 0) {
                result += literal + " ";
                word = word.substr(literal.length());
            }
        }

        for (const auto& op : operators) {
            if (word.find(op) == 0) {
                result += op + " ";
                word = word.substr(op.length());
            }
        }

        for (const auto& separator : separators) {
            if (word.find(separator) == 0) {
                result += separator + " ";
                word = word.substr(separator.length());
            }
        }

        // Add remaining word 
        if (!word.empty()) {

            for (const auto& keyword : keywords) {
                if (word.find(keyword) == 0) {
                    result += keyword + " ";
                    word = word.substr(keyword.length());
                }
            }

            for (const auto& op : operators) {
                if (word.find(op) == 0) {
                    result += op + " ";
                    word = word.substr(op.length());
                }
            }

            result += word + " ";
        }
    }

    return result;
}

void countTokens(const std::string& input) {
    int keywordCount = 0;
    int operatorCount = 0;
    int literalCount = 0;
    int identifierCount = 0;
    int separatorCount = 0;

    std::vector<std::string> CountedKeywords;
    std::vector<std::string> CountedOperators;
    std::vector<std::string> CountedLiterals;
    std::vector<std::string> CountedIdentifiers;
    std::vector<std::string> CountedSeparators;

    std::vector<std::string> keywords = { "else", "using", "if", "int", "return", "void" };
    std::vector<std::string> operators = { "+", "-", "=", "==", "!=", ">>", "<<" };
    std::vector<std::string> literals = { "5", "10", "20", "0", "\"Hello!\"", "\"Number is greater than 5\"", "\"Number is less than or equal to 5\"" };

    std::vector<std::string> identifiers = { "cout", "greet", "main", "endl", "std", "number" };
    std::vector<std::string> separators = { ";", ",", "(", ")", "{", "}", "::" };

    std::stringstream ss(input);
    std::string word;

    while (ss >> word) {
        // Count keywords
        if (std::find(keywords.begin(), keywords.end(), word) != keywords.end()) {
            keywordCount++;
            CountedKeywords.push_back(word);
        }
        // Count identifiers
        else if (std::find(identifiers.begin(), identifiers.end(), word) != identifiers.end()) {
            identifierCount++;
            CountedIdentifiers.push_back(word);
        }
        // Count literals
        else if (std::find(literals.begin(), literals.end(), word) != literals.end()) {
            literalCount++;
            CountedLiterals.push_back(word);
        }
        // Count separators
        else if (std::find(separators.begin(), separators.end(), word) != separators.end()) {
            separatorCount++;
            CountedSeparators.push_back(word);
        }
        // Count operators
        else if (std::find(operators.begin(), operators.end(), word) != operators.end()) {
            operatorCount++;
            CountedOperators.push_back(word);
        }
    }

    std::cout << "Keyword count: " << keywordCount << std::endl;
    std::cout << "Identifier count: " << identifierCount << std::endl;
    std::cout << "Literal count: " << literalCount << std::endl;
    std::cout << "Separator count: " << separatorCount << std::endl;
    std::cout << "Operator count: " << operatorCount << std::endl;
    std::cout << std::endl;

    int total = keywordCount + identifierCount + literalCount + separatorCount + operatorCount;
    std::cout << "Total token count: " << total << std::endl;
    std::cout << std::endl;

    // Display tokens in tabular form
    std::cout << std::setw(20) << "Category" << std::setw(20) << "Tokens" << std::endl;

    for (const auto& token : CountedKeywords) {
        std::cout << std::setw(20) << "Keyword" << std::setw(20) << token << std::endl;
    }

    for (const auto& token : CountedIdentifiers) {
        std::cout << std::setw(20) << "Identifier" << std::setw(20) << token << std::endl;
    }

    for (const auto& token : CountedLiterals) {
        std::cout << std::setw(20) << "Literal" << std::setw(20) << token << std::endl;
    }

    for (const auto& token : CountedSeparators) {
        std::cout << std::setw(20) << "Separator" << std::setw(20) << token << std::endl;
    }

    for (const auto& token : CountedOperators) {
        std::cout << std::setw(20) << "Operator" << std::setw(20) << token << std::endl;
    }
}

int main() {
    std::string str = R"(
        // C++ Program with a Function
        void greet() {
            std::cout << "Hello!" << std::endl;
        }
        int main() {
            greet();
            return 0;
        }
    )";

    std::string result = removeSpaces(str);
    std::cout << "Original string: \"" << str << "\"" << std::endl;
    std::cout << "String without spaces: \"" << result << "\"" << std::endl;

    std::string result2 = addSpaces(result);
    std::cout << "Each token separated: \"" << result2 << "\"" << std::endl;

    countTokens(result2);
    std::cout << std::endl;
    std::cout << std::endl;



    std::string str02 = R"(
 
//C++ program with loop and condition

int main() {
int number = 10;
if (number > 5) {
cout << "Number is greater than 5" << endl;
} else {
cout << "Number is less than or equal to 5" << endl;
}
return 0;
}

    )";

    std::string result02 = removeSpaces(str02);
    std::cout << "Original string: \"" << str02 << "\"" << std::endl;
    std::cout << "String without spaces: \"" << result02 << "\"" << std::endl;

    std::string result202 = addSpaces(result02);
    std::cout << "Each token separated: \"" << result202 << "\"" << std::endl;

    countTokens(result202);
    std::cout << std::endl;

    return 0;
}
