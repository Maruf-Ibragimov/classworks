#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;
    vector<string>* transaction_history;

public:
    BankAccount(int number = 0, string name = "", double initial_balance = 0.0)
        : accountNumber(number), accountHolderName(name), balance(initial_balance) {
        transaction_history = new vector<string>();
    }

    void deposit(double amount) {
        balance += amount;
        transaction_history -> push_back("Deposit: +" + to_string(amount));
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transaction_history -> push_back("Withdraw: -" + to_string(amount));
        } else {
            cout << "Error while transaction" << endl;
        }
    }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transactions: ";
        for (const auto& transaction : *transaction_history) {
            cout << transaction << " ";
        }
        cout << endl;
    }

    BankAccount(const BankAccount& other): accountNumber(other.accountNumber),
                                           accountHolderName(other.accountHolderName),
                                           balance(other.balance) {
        transaction_history = new vector<string>(*other.transaction_history);
    }

    BankAccount& operator=(const BankAccount& other) {
        if (this != &other) {
            accountNumber = other.accountNumber;
            accountHolderName = other.accountHolderName;
            balance = other.balance;
            delete transaction_history;
            transaction_history = new vector<string>(*other.transaction_history);
        }
        return *this;
    }

    ~BankAccount() {
        delete transaction_history;
    }
    
};

int main() {
    BankAccount account_1(123456, "Maruf Ibragimov", 10000.0);
    account_1.deposit(500);
    account_1.withdraw(200);

    BankAccount account2_shallow = account_1;

    BankAccount account2_deep;
    account2_deep = account_1;

    cout << "Account 1:" << endl;
    account_1.display();

    cout << "\nShallow Copy: " << endl;
    account2_shallow.display();

    cout << "\nDeep Copy: " << endl;
    account2_deep.display();

    return 0;
}
