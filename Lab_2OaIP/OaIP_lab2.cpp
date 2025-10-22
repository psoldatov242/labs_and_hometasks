#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Функция для разбиения строки на слова
vector<string> splitString(const string& str) {
    vector<string> words;
    string currentWord;
    
    for (char c : str) {
        if (c == ' ') {
            if (!currentWord.empty()) {
                words.push_back(currentWord);
                currentWord.clear();
            }
        } else {
            currentWord += c;
        }
    }
    
    // Добавляем последнее слово, если оно есть
    if (!currentWord.empty()) {
        words.push_back(currentWord);
    }
    
    return words;
}

// Функция для преобразования строки в верхний регистр
string toUpper(string str) {
    for (char& c : str) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
    }
    return str;
}

bool isD(char c) {
    return c == 'd' || c == 'D';
}

bool endsWithB(const string& word) {
    if (word.empty()) return false;
    char lastChar = word[word.length() - 1];
    return lastChar == 'b' || lastChar == 'B';
}

int main() {
    string input;
    cout << "Введите строку из 10 слов на латинице: ";
    getline(cin, input);
//тут на строки дроблю строку
    vector<string> words = splitString(input);

    int count_b = 0;
    for (const auto& w : words) {
        if (endsWithB(w)) {
            count_b++;
        }
    }

    size_t max_len = 0;
    for (const auto& w : words) {
        if (w.length() > max_len) {
            max_len = w.length();
        }
    }

    int count_d = 0;
    if (!words.empty()) {
        string last_word = words.back();
        for (char c : last_word) {
            if (isD(c)) {
                count_d++;
            }
        }
    }

    string upper_str = toUpper(input);

    int count_match = 0;
    for (const auto& w : words) {
        if (w.length() >= 4 && w[1] == w[w.length() - 2]) {
            count_match++;
        }
    }
    string longest_common;
    for (int i = 0; i < words.size(); ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            const string& word1 = words[i];
            const string& word2 = words[j];
            for (size_t start = 0; start < word1.length(); ++start) {
                for (size_t length = 1; length <= word1.length() - start; ++length) {
                    string substring = word1.substr(start, length);
                    if (word2.find(substring) != string::npos && substring.length() > longest_common.length()) {
                        longest_common = substring;
                    }
                }
            }
        }
    }

    cout << "\nРезультаты:\n";
    cout << "1. Слов на 'b': " << count_b << endl;
    cout << "2. Самое длинное слово: " << max_len << " символов" << endl;
    cout << "3. Букв 'd' в последнем слове: " << count_d << endl;
    cout << "4. Строка в верхнем регистре: " << upper_str << endl;
    cout << "5. Слов с совпадающими 2-м и предпоследним символом: " << count_match << endl;
    cout << "6. Самая длинная общая подстрока: \"" << longest_common << "\"" << endl;

}