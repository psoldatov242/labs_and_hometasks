#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
protected:
    string accountNumber;  
    string ownerName;      
    double balance;        

public:
    BankAccount(string accNum, string owner, double initialBalance) {
        accountNumber = accNum;
        ownerName = owner;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Успешно пополнено: " << amount << " руб." << endl;
        }
        else {
            cout << "Ошибка: сумма пополнения должна быть положительной!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Успешно снято: " << amount << " руб." << endl;
        }
        else if (amount > balance) {
            cout << "Ошибка: недостаточно средств на счёте!" << endl;
        }
        else {
            cout << "Ошибка: сумма снятия должна быть положительной!" << endl;
        }
    }

    virtual void displayInfo() {
        cout << fixed << setprecision(2);
        cout << "\n=== Информация о банковском счёте ===" << endl;
        cout << "Номер счёта: " << accountNumber << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << balance << " руб." << endl;
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double newBalance) {
        balance = newBalance;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate; 

public:
    SavingsAccount(string accNum, string owner, double initialBalance, double rate)
        : BankAccount(accNum, owner, initialBalance) {
        interestRate = rate;
    }

    void applyInterest() {
        double interest = balance * (interestRate / 100.0);
        balance += interest;
        cout << "Начислены проценты: " << interest << " руб. (ставка: "
            << interestRate << "%)" << endl;
    }

    void displayInfo() override {
        BankAccount::displayInfo();
        cout << "Процентная ставка: " << interestRate << "%" << endl;
        cout << "======================================" << endl;
    }
};

int main() {
    cout << "=== Банковская система ===" << endl;

    BankAccount regularAccount("123456789", "Иван Иванов", 5000.0);
    cout << "\n1. Работа с обычным банковским счётом:";
    regularAccount.displayInfo();

    regularAccount.deposit(1500.50);
    regularAccount.withdraw(2000.75);
    regularAccount.withdraw(5000.00); 
    regularAccount.displayInfo();

    SavingsAccount savingsAccount("987654321", "Петр Петров", 10000.0, 5.0);
    cout << "\n\n2. Работа со сберегательным счётом:";
    savingsAccount.displayInfo();

    savingsAccount.deposit(3000.0);
    savingsAccount.withdraw(1000.0);
    savingsAccount.applyInterest(); 
    savingsAccount.displayInfo();

    cout << "\n\n3. Дополнительные операции со сберегательным счётом:";
    savingsAccount.applyInterest();
    savingsAccount.displayInfo();

    return 0;
}