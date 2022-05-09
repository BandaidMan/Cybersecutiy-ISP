#include <iostream>
#include <fstream>
#include <string>
#include <hashlibpp.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc,char* argv[]) {
    auto start = high_resolution_clock::now();
    cout << "---- Begin Processing Password Dictionary ----" << endl;
    hashwrapper *md5_wrapper = new md5wrapper();
    string dictionary_file = "";
    string hash_value_from_passwd_file = "";
    string show_or_hide_progress = "";
    if (argc == 4) {
        dictionary_file = argv[1];
        hash_value_from_passwd_file = argv[2];
        show_or_hide_progress = argv[3];
    } else {
        dictionary_file = "password_dictionary.txt";
        hash_value_from_passwd_file = "3a8b7b53ab2be90f457869961f475aab";
        show_or_hide_progress = "show";
    }
    cout << "Dictionary File To Use: " << dictionary_file << endl << "MD5 Hash Value To Search For: " << hash_value_from_passwd_file << endl << endl;
    ifstream file(dictionary_file);
    string password_from_dictionary; 
    while (getline(file, password_from_dictionary)) {
        string computed_password_hash = md5_wrapper->getHashFromString(password_from_dictionary);
        if (show_or_hide_progress == "show") {
            cout << "Processing Password: " << password_from_dictionary << " --> Computed MD5 Hash: " << computed_password_hash << endl;
        }
        if (computed_password_hash == hash_value_from_passwd_file) {
            cout << endl << "*** Found Password ***: " << password_from_dictionary << endl << endl;
            break;
        }
    }
    cout << "---- End Processing Password Dictionary ----" << endl;
    delete md5_wrapper;
    auto stop = high_resolution_clock::now();
    double time_taken = std::chrono::duration<double>(stop - start).count();
    cout << "Total Execution Time: " << time_taken << " Seconds" << endl;
    return 0;
}