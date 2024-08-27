#ifndef _ILLEGALFUNDSEXCEPTION_H_
#define _ILLEGALFUNDSEXCEPTION_H_
#include<exception>

class IllegalFundsException : public std::exception {
    public:
        IllegalFundsException() noexcept = default;
        ~IllegalFundsException() = default;
        virtual const char* what() const noexcept {
            return "Illegal Funds Exception";
        }
};

#endif