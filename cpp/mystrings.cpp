#include "mystrings.h"

void print_string_length(std::string instring){
    int len = instring.size();
    char out[30+len];
    sprintf(out,"length of string = %d\n",len);
    std::cout << out;
}  


void split_string(std::string instring, std::vector<std::string> &split_arr, char delimiter){
    // NOT DONE YET
    unsigned const int LEN = instring.length();
    unsigned int i = 0;

    for (i; i < LEN; i++){
        std::vector<char> temp_vec;
        while (instring[i] != delimiter){
            temp_vec.push_back(instring[i]);
        }
        // convert char vec to string and append it to split_array
        temp_vec.clear(); // clear temp vec 
    }
}   


