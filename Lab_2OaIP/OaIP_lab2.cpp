#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void toLowerString(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

int main() {
    char inputString[1000];
    cout << "Введите строку из 10 слов на латинице: ";
    cin.getline(inputString, 1000);

    // Слова на 'a'
    int countEndingWithA = 0;
    char* words[100];
    int wordCount = 0;

    char* token = strtok(inputString, " ");
    while (token != nullptr) {
        words[wordCount++] = token;
        token = strtok(nullptr, " ");
    }

    for (int i = 0; i < wordCount; i++) {
        int len = strlen(words[i]);
        if (len > 0 && tolower(words[i][len - 1]) == 'a') {
            countEndingWithA++;
        }
    }
    cout << "1. Слов, оканчивающихся на 'a': " << countEndingWithA << endl;

    //Длина самого короткого слова
    int minLength = strlen(words[0]);
    for (int i = 1; i < wordCount; i++) {
        int len = strlen(words[i]);
        if (len < minLength) {
            minLength = len;
        }
    }
    cout << "2. Длина самого короткого слова: " << minLength << endl;

    //Количество 'b' во втором слове
    int countB = 0;
    if (wordCount >= 2) {
        char* secondWord = words[1];
        for (int i = 0; secondWord[i] != '\0'; i++) {
            if (tolower(secondWord[i]) == 'b') {
                countB++;
            }
        }
    }
    cout << "3. Количество букв 'b' во втором слове: " << countB << endl;

    //Замена заглавных букв на строчные
    char modifiedString[1000];
    strcpy(modifiedString, inputString);
    toLowerString(modifiedString);
    cout << "4. Строка в нижнем регистре: " << modifiedString << endl;

    //Слова с одинаковыми первым и последним символом
    int countFirstLast = 0;
    for (int i = 0; i < wordCount; i++) {
        int len = strlen(words[i]);
        if (len > 0 && tolower(words[i][0]) == tolower(words[i][len - 1])) {
            countFirstLast++;
        }
    }
    cout << "Вопрос 5. Слов с одинаковыми первым и последним символом: " << countFirstLast << endl;

    return 0;
}