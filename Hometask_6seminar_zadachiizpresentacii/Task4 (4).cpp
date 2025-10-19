// Hometask char from presentacia - PETR SOLDATOV IU1-12B - Task 4

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[100], str2[100];
    cin.getline(str1, 100);
    cin.getline(str2, 100);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        cout << "Нет" << endl;
        return 0;
    }

    char copy1[100], copy2[100];
    strcpy(copy1, str1);
    strcpy(copy2, str2);
    //пузырьок
    for (int i = 0; i < len1 - 1; i++) {
        for (int j = 0; j < len1 - i - 1; j++) {
            if (copy1[j] > copy1[j + 1]) {
                char temp = copy1[j];
                copy1[j] = copy1[j + 1];
                copy1[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < len2 - 1; i++) {
        for (int j = 0; j < len2 - i - 1; j++) {
            if (copy2[j] > copy2[j + 1]) {
                char temp = copy2[j];
                copy2[j] = copy2[j + 1];
                copy2[j + 1] = temp;
            }
        }
    }
    
    bool maybeanagramma = true;
    for (int i = 0; i < len1; i++) {
        if (copy1[i] != copy2[i]) {
            maybeanagramma = false;
            break;
        }
    }
    
    cout << (maybeanagramma ? "Да" : "Нет") << endl;
    return 0;
}