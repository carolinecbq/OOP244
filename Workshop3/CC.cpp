#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {

    void CC::prnNumber(unsigned long long no) const {
        cout << no / 1000000000000ull << " ";
        no %= 1000000000000ull;
        cout.fill('0');
        cout.width(4);
        cout.setf(ios::right);
        cout << no / 100000000ull << " ";
        no %= 100000000ull;
        cout.width(4);
        cout << no / 10000ull << " ";
        no %= 10000ull;
        cout.width(4);
        cout << no;
        cout.unsetf(ios::right);
        cout.fill(' ');
    }
    void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
        char lname[31]{};
        strcpy(lname, name, 30);
        cout << "| ";
        cout.width(30);
        cout.fill(' ');
        cout.setf(ios::left);
        cout << lname << " | ";
        prnNumber(number);
        cout << " | " << cvv << " | ";
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout.width(2);
        cout << expMon << "/" << expYear << " |" << endl;
        cout.unsetf(ios::right);
    }

    void CC::aloCopy(const char* name) {
        delete[] cardHolderName;

        if (name) {
            cardHolderName = new char[strlen(name) + 1];
            strcpy(cardHolderName, name);
        } else {
            cardHolderName = nullptr;
        }

    }

    void CC::deallocate() {
        delete[] cardHolderName;
        cardHolderName = nullptr;
    }

    bool CC::validate(const char* cardHolderName, unsigned long long cardNumber, short cvv, short expMonth, short expYear) const {
        int conditions = 0;

        if ((cardHolderName != nullptr) && (strlen(cardHolderName) > 2)) {
            conditions += 1;
        }

        if (cardNumber >= 4000000000000000ull && cardNumber <= 4099999999999999ull) {
            conditions += 1;
        }

        if (cvv >= 100 && cvv <= 999) {
            conditions += 1;
        }

        if (expMonth >= 1 && expMonth <= 12) {
            conditions += 1;
        }

        if (expYear >= 24 && expYear <= 32) {
            conditions += 1;
        }

        if (conditions == 5) {
            return true;
        } else {
            return false;
        }
    }

    void CC::set() {
        delete[] cardHolderName;
        cardHolderName = nullptr;
        cardNumber = 0;
        cvv = 0;
        expYear = 0;
        expMonth = 0;
    }

    bool CC::isEmpty() const {
        if (cardHolderName == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void CC::set(const char* cc_name, unsigned long long cc_number, short cvv, short expMonth, short expYear) {
        set();
        if (validate(cc_name, cc_number, cvv, expMonth, expYear) == true) {
            aloCopy(cc_name);
            cardNumber = cc_number;
            this->cvv = cvv;
            this->expYear = expYear;
            this->expMonth = expMonth;
        }

    }

    void CC::display() const {
        if (cardHolderName == nullptr) {
            cout << "Invalid Credit Card Record\n" << endl;
        } else {
            display(cardHolderName, cardNumber, expYear, expMonth, cvv);
        }


    }

    CC::CC() {
        cardHolderName = nullptr;
        cardNumber = 0;
        cvv = 0;
        expYear = 0;
        expMonth = 0;
    }

    CC::CC(const char* cc_name, unsigned long long cc_number, short cvv, short expYear, short expMonth) {
        cardHolderName = nullptr;

        if (validate(cc_name, cc_number, cvv, expMonth, expYear) == true) {
            aloCopy(cc_name);
            cardNumber = cc_number;
            this->cvv = cvv;
            this->expYear = expYear;
            this->expMonth = expMonth;
        }
    }

    CC::~CC() {
        delete[] cardHolderName;
        cardHolderName = nullptr;
    }

}