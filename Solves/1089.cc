// https://acm.timus.ru/problem.aspx?space=1&num=1089

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

std::unordered_set<std::string> vocabulary;

bool transformWord(std::string& word) {
    for (const auto& vocabWord : vocabulary) {
        if (word.length() == vocabWord.length()) {
            int differences = 0;
            for (size_t i = 0; i < word.length(); ++i) {
                if (word[i] != vocabWord[i]) {
                    ++differences;
                    if (differences > 1) break;
                }
            }
            if (differences == 1) {
                word = vocabWord;
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::string input;
    while (std::getline(std::cin, input) && input != "#") {
        vocabulary.insert(input);
    }

    std::string output;
    std::string word;
    int corrections = 0;
    char c;

    while (std::cin.get(c)) {
        if (c >= 'a' && c <= 'z') {
            word += c;
        } else {
            if (!word.empty()) {
                if (transformWord(word)) {
                    ++corrections;
                }
                output += word;
                word.clear();
            }
            output += c;
        }
    }

    if (!word.empty()) {
        if (transformWord(word)) {
            ++corrections;
        }
        output += word;
    }

    std::cout << output << corrections << std::endl;
    return 0;
}
