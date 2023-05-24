# myString - Custom String Class

`myString` is a custom string class that provides basic string manipulation functionalities. It allows you to create, modify, and perform operations on strings.

## Features

- Creation of strings from C-style character arrays
- Copying strings from one object to another
- Concatenation of strings
- Comparison of strings for equality and inequality
- Conversion of strings to uppercase and lowercase
- Removal of whitespace characters from strings

## Usage

To use the `myString` class, follow these steps:

1. Include the necessary header files:
   ```cpp
   #include <iostream>
   #include "myString.h"
   ```

2. Create a `myString` object:
   ```cpp
   myString str("Hello, world!"); // Create a myString object initialized with a C-style string
   ```

3. Perform various operations on the string:
   ```cpp
   str.print(); // Print the string
   std::cout << "Length: " << str.length() << std::endl; // Get the length of the string
   str.upper(); // Convert the string to uppercase
   str.lower(); // Convert the string to lowercase
   str.strip(); // Remove whitespace characters from the string
   ```

4. Use operators and member functions:
   ```cpp
   myString other("OpenAI");
   myString concatenated = str + other; // Concatenate two strings using the + operator
   if (str == other) { // Check for string equality
       // Perform some actions if the strings are equal
   }
   ```

5. Clean up the allocated memory:
   ```cpp
   // Destructor automatically deallocates the memory for the string
   ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributions

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

## Acknowledgments

The `myString` class is inspired by the concept of C-style strings and the need for a custom string class with additional functionalities.
