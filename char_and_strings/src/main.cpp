// Section 10
// Challenge -
// Substitution Cipher

/*
A simple and very old method of sending secret messages is the substitution cipher.
You might have used this cipher with your friends when you were a kid.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program thats ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted message.
Then decryped the encrypted message back to the original message.

You may use the 2 strings below for  your subsitition.
For example, to encrypt you can replace the character at position n in alphabet
with the character at position n in key.

To decrypt you can replace the character at position n in key
with the character at position n in alphabet.

Have fun! And make the cipher stronger if you wish!
Currently the cipher only substitutes letters - you could easily add digits, puncuation, whitespace and so
forth. Also, currently the cipher always substitues a lowercase letter with an uppercase letter and vice-versa.
This could also be improved.

Remember, the less code you write the less code you have to test!
Reuse existing functionality in libraries and in the std::string class!
*/

#include <iostream>
#include <string>

int main() {

    std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    std::string original_msg {};


    std::cout << "Enter a message to be encrypted: ";
    std::getline(std::cin, original_msg);

    int msg_size = original_msg.size();

    if (msg_size <= 0) {
        std::cout << "Invalid input" << std::endl;
        exit(-1);
    }

    std::string encrypted_msg (msg_size, '*');
    std::string decrypted_msg (msg_size, '*');

    for (int i = 0; i < msg_size; i++) {
        size_t pos = alphabet.find(original_msg[i]);
        if (pos == std::string::npos)
            encrypted_msg[i] = original_msg[i];
        else
            encrypted_msg[i] = key[pos];
    }

    for (int i = 0; i < msg_size; i++) {
        size_t pos = key.find(encrypted_msg[i]);
        if (pos == std::string::npos)
            decrypted_msg[i] = encrypted_msg[i];
        else
            decrypted_msg[i] = alphabet[pos];
    }
    std::cout << "Original message: " << original_msg << std::endl;
    std::cout << "Encrypted message: " << encrypted_msg << std::endl;
    std::cout << "Decrypted message: " << decrypted_msg << std::endl;


    std::cout << std::endl;
    return 0;
}

