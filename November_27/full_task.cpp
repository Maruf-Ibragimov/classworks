#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;
    double* transactionHistory;
    int transactionCount;
    static int totalAccounts;

public:
    BankAccount() : accountNumber(0), accountHolderName(""), balance(0.0), transactionHistory(nullptr), transactionCount(0) {
        totalAccounts++;
    }

    BankAccount(int accNumber, const string& accHolder, double initBalance)
        : accountNumber(accNumber), accountHolderName(accHolder), balance(initBalance), transactionHistory(nullptr), transactionCount(0) {
        totalAccounts++;
    }

    BankAccount(int accNumber, const string& accHolder)
        : accountNumber(accNumber), accountHolderName(accHolder), balance(0.0), transactionHistory(nullptr), transactionCount(0) {
        totalAccounts++;
    }

    BankAccount(const BankAccount& source)
        : accountNumber(source.accountNumber),
          accountHolderName(source.accountHolderName),
          balance(source.balance),
          transactionCount(source.transactionCount) {
        transactionHistory = source.transactionHistory;
    }

    BankAccount(BankAccount&& source) noexcept
        : accountNumber(source.accountNumber),
          accountHolderName(move(source.accountHolderName)),
          balance(source.balance),
          transactionHistory(source.transactionHistory),
          transactionCount(source.transactionCount) {
        source.accountNumber = 0;
        source.accountHolderName = "";
        source.balance = 0.0;
        source.transactionHistory = nullptr;
        source.transactionCount = 0;
    }

    ~BankAccount() {
        delete[] transactionHistory;
        totalAccounts--;
    }

    void addTransaction(double amount) {
        if (!transactionHistory) {
            transactionHistory = new double[100];
        }
        transactionHistory[transactionCount++] = amount;
    }

    bool compareAccounts(const BankAccount& other) const {
        return this->accountNumber == other.accountNumber;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    friend void transferFunds(BankAccount& from, BankAccount& to, double amount);
};

int BankAccount::totalAccounts = 0;

void transferFunds(BankAccount& from, BankAccount& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
    }
}

int main() {
    BankAccount defaultAccount;
    defaultAccount.addTransaction(500);
    cout << "Total accounts: " << BankAccount::getTotalAccounts() << endl;

    BankAccount parameterizedAccount(12345, "John Doe", 1000.0);
    parameterizedAccount.addTransaction(200);
    parameterizedAccount.addTransaction(-100);
    cout << "Total accounts: " << BankAccount::getTotalAccounts() << endl;

    BankAccount overloadedAccount(54321, "Jane Doe");
    overloadedAccount.addTransaction(300);
    cout << "Total accounts: " << BankAccount::getTotalAccounts() << endl;

    BankAccount copiedAccount = parameterizedAccount;
    cout << "Total accounts: " << BankAccount::getTotalAccounts() << endl;

    BankAccount movedAccount = move(overloadedAccount);
    cout << "Total accounts: " << BankAccount::getTotalAccounts() << endl;

    return 0;
}
