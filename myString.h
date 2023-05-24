#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class myString {
private:
    char* arr;

    void strCopy(char*& arr, const char* str);
    char* strCat(const char* arr, const char* str);
    int strLen(const char* str);


public:
    myString();
    myString(const char* str);
    myString(const myString& other);
    ~myString();

    int length();

    myString& operator=(const myString& other);
    myString operator+(const myString& other);
    friend std::ostream& operator<<(std::ostream& os, const myString& str);
    bool operator==(const myString& other);
    bool operator!=(const myString& other);

    void print();



    void upper();
    void lower();
    void strip();

};



#endif
