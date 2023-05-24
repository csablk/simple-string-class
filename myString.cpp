#include <iostream>
#include "myString.h"

myString::myString(const char* str) {
    strCopy(arr, str);  // Copy the passed string into the arr array / Копирует переданную строку в массив arr
}

myString::myString() {
    arr = nullptr;  // Initialize the arr pointer with nullptr / Инициализирует указатель arr значением nullptr
}

myString::myString(const myString& other) {
    strCopy(arr, other.arr);  // Copy the string from another myString object into the current one / Копирует строку из другого объекта myString в текущий объект
}

void myString::strCopy(char*& arr, const char* str) {
    int strSize = strLen(str);

    arr = new char[strSize + 1];

    for (int i = 0; i < strSize; ++i) {
        arr[i] = str[i];
    }

    arr[strSize] = '\0';
}

int myString::strLen(const char* str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

void myString::print() {
    std::cout << arr << std::endl;  // Print the content of the arr array / Выводит содержимое массива arr
}

char* myString::strCat(const char* arr, const char* str) {
    int arrSize = strLen(arr);
    int strSize = strLen(str);

    char* array = new char[arrSize + strSize + 1];

    for (int i = 0; i < arrSize; ++i) {
        array[i] = arr[i];
    }

    for (int i = 0; i < strSize; ++i) {
        array[arrSize + i] = str[i];
    }

    array[arrSize + strSize] = '\0';

    return array;
}

myString::~myString() {
    delete[] arr;  // Deallocate the memory of the arr array / Освобождает память, занятую массивом arr
}

int myString::length()  {
    return strLen(arr);  // Return the length of the string stored in arr / Возвращает длину строки, хранящейся в arr
}

myString& myString::operator=(const myString& other) {
    if (this != &other) {
        delete[] arr;  // Deallocate the memory of the current arr array / Освобождает память, занятую текущим массивом arr
        strCopy(arr, other.arr);  // Copy the string from another myString object into the current one / Копирует строку из другого объекта myString в текущий объект
    }
    return *this;
}

myString myString::operator+(const myString& other) {
    myString result;
    result.strCopy(result.arr, strCat(arr, other.arr));  // Concatenate the strings of two myString objects and store the result in a new myString object / Сцепляет строки двух объектов myString и сохраняет результат в новом объекте myString
    return result;
}

std::ostream& operator<<(std::ostream& os, const myString& str) {
    os << str.arr;  // Overloaded stream insertion operator to print the content of the arr array / Перегруженный оператор вставки потока для вывода содержимого массива arr
    return os;
}

bool myString::operator==(const myString& other) {
    if (strLen(arr) != strLen(other.arr)) return false;

    for (int i = 0; i < strLen(arr); i++) {
        if (arr[i] != other.arr[i]) return false;
    }

    return true;
}

bool myString::operator!=(const myString& other) {
    return !(*this == other);  // Overloaded inequality operator using the equality operator / Перегруженный оператор неравенства с использованием оператора равенства
}

void myString::upper() {
    int strSize = strLen(arr);

    for (int i = 0; i < strSize; ++i) {
        if (arr[i] >= 'a' && arr[i] <= 'z') {
            arr[i] = arr[i] - ('a' - 'A');  // Convert lowercase letters to uppercase letters / Преобразует строчные буквы в прописные буквы
        }
    }
}

void myString::lower() {
    int strSize = strLen(arr);

    for (int i = 0; i < strSize; ++i) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            arr[i] = arr[i] + ('a' - 'A');  // Convert uppercase letters to lowercase letters / Преобразует прописные буквы в строчные буквы
        }
    }
}

void myString::strip() {
    int strSize = strLen(arr);

    char* newArr = new char[strSize];
    int j = 0;

    for (int i = 0; i < strSize; ++i) {
        if (arr[i] != ' ') {
            newArr[j] = arr[i];  // Copy non-space characters to a new array / Копирует непробельные символы в новый массив
            ++j;
        }
    }

    newArr[j] = '\0';  // Null-terminate the new array / Добавляет нулевой символ в конец нового массива

    arr = newArr;  // Update the arr pointer to point to the new array / Обновляет указатель arr, чтобы он указывал на новый массив
}
