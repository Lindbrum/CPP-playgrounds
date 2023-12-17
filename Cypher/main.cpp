#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <random>

using  namespace std;

int main() {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'\"_=+-*\\/?!$%&()^ ";
    //Build the cypher by shuffling the alphabet
    cout << "Accepted alphabet: " << alphabet << endl;
    cout << "Generating a random cypher..." << endl;
    string key {alphabet};
    //Time-based seed for the random generator
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(key.begin(), key.end(), default_random_engine(seed));
    cout << "Generated cypher: " << key << endl;
    cout << "Ready to test cypher!" << endl;
    //Show the menù
    char selected {};

    do {
        cout << "\n------------" << endl;
        cout << "C - Test cypher" << endl;
        cout << "R - Regenerate the cypher" << endl;
        cout << "E - extend the alphabet with new characters (this will also regenerate the cypher)" << endl;
        cout << "Q - Quit" << endl;
        cout << "What do you want to do? ";
        cin >> selected;
        cout << endl;
        switch (selected) {
            case 'c':
                case 'C': {
                string message;
                cout << "Provide a message to encrypt: ";
                cin.ignore(); //Ignore newline from menù extraction
                getline(cin, message);
                if (message.empty()) {
                    cout << "Nothing to encrypt..." << endl;
                }else {
                    cout << "Encrypting the message..." << endl;
                    bool aborting {false};
                    for (size_t i = 0; i < message.length(); ++i) {
                        size_t index {};
                        index = alphabet.find(message.at(i));
                        if (index == string::npos) {
                            cout << "Character '" << message.at(i) << "' is not part of the alphabet, aborting...";
                            aborting = true;
                            break;
                        }else {
                         message.at(i) = key.at(index);
                        }
                    }
                    if(!aborting) {
                        cout << "Encryption complete! The cyphertext is: " << message << endl;
                        cout << "Testing decryption...";
                        for (size_t i = 0; i < message.length(); ++i) {
                            size_t index {};
                            index = key.find(message.at(i));
                            message.at(i) = alphabet.at(index);
                        }
                        cout << "Decryption complete! The plaintext is: " << message << endl;
                    }
                }
                break;
            }
            case 'e':
                case 'E': {
                string new_chars;
                cout << "The current alphabet is: " << alphabet << endl;
                cout << "What character(s) do you wish to add? ";
                cin.ignore(); //Ignore newline from menù extraction
                getline(cin,new_chars);
                if (new_chars.empty()) {
                    cout << "No character was provided." << endl;
                    break;
                }
                string filtered_chars {};
                for (size_t i {0}; i < new_chars.length(); ++i) {
                    //Add this character if it's not a duplicate
                    if (alphabet.find(new_chars.at(i)) == string::npos
                    && filtered_chars.find(new_chars.at(i)) == string::npos) {
                        filtered_chars.push_back(new_chars.at(i));
                    }
                }
                alphabet += filtered_chars;
                cout << "The alphabet has been extended with the characters \"" << filtered_chars << "\"" << endl;
                /*FALL-THROUGH*/
                }
            case 'r':
                case 'R': {
                cout << "Accepted alphabet: " << alphabet << endl;
                cout << "Generating a random cypher..." << endl;
                key  = alphabet;
                //Time-based seed for the random generator
                seed = chrono::system_clock::now().time_since_epoch().count();
                shuffle(key.begin(), key.end(), default_random_engine(seed));
                cout << "Generated cypher: " << key << endl;
                cout << "Ready to test cypher!" << endl;
                break;
            }
            case 'q':
                case 'Q': {
                break;
            }
            default: {
                cout << "Unknown command, try again." << endl;
            }
        }
    } while (selected != 'q' && selected != 'Q');
    return 0;
}
