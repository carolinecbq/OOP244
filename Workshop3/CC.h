#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
    class CC {
        void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
        void prnNumber(unsigned long long no) const;
        bool validate(const char* cardHolderName, unsigned long long cardNumber,short cvv, short expYear, short expMonth) const;
        char* cardHolderName;
        short cvv;
        short expYear;
        short expMonth;
        unsigned long long cardNumber;
        void aloCopy(const char* name);
        void deallocate();
    public:
        void set();
        bool isEmpty() const;
        void set(const char* cc_name, unsigned long long cc_number, short cvv, short expYear, short expMonth);
        void display() const;
        CC();
        CC(const char* cc_name, unsigned long long cc_number, short cvv, short expYear, short expMonth);
        ~CC();


    };

}
#endif // !SENECA_CC_H_

