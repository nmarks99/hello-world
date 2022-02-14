#include <iostream>
#include <string>
#include <vector>

void split_string(std::string instring, std::vector<std::string> &split_vec, char delimiter);

using namespace std;
int main() {

    string myString = "one,two,three,four";

    char delim = ',';
    vector<string> split_vec;
    split_string(myString, split_vec, delim);
    
    for (int i=0; i < split_vec.size(); i++){
        cout <<  split_vec[i] << "\n";
    }

    return 0;
}

void split_string(std::string instring, std::vector<std::string> &split_vec, char delimiter){
    unsigned const int LEN = instring.length();
    unsigned int i = 0;
    std::vector<char> temp_vec;

    for (i; i <= LEN; i++){    
        if (instring[i] != delimiter){
            temp_vec.push_back(instring[i]);
        }
        else{
            // convert char vec to string and append it to split_vecay
            split_vec.push_back(std::string(temp_vec.begin(), temp_vec.end()));
            temp_vec.clear(); // clear temp vec 
        }
        
        if (i == LEN) {
            split_vec.push_back(std::string(temp_vec.begin(), temp_vec.end()));
            temp_vec.clear(); // clear temp vec 
        }
    }
}   
