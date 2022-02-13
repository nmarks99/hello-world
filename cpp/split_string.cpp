#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator
#include <vector>



void print_string_length(std::string instring){
    int len = instring.size();
    char out[30+len];
    sprintf(out,"length of string = %d\n",len);
    std::cout << out;
}

void split_string(std::string instring, char delimiter, std::vector<char> &split_arr){
    unsigned const int LEN = instring.length();
    unsigned int i = 0;

    for (i; i < LEN; i++){
        char ch = instring[i];
        if (ch != delimiter){
            split_arr.push_back(ch);
        }
    }
}   

// void csv_split_line(char *str,char *x,char *y, char *z){
//     unsigned const int STRING_LENGTH = strlen(str);
//     unsigned int i = 0;
//     unsigned int j;
//     char coords_temp[STRING_LENGTH];

//     for (j = 0; j < STRING_LENGTH; j++){
//         if (str[j] != ','){
//             strncat(coords_temp,&str[j],1);
//         }
//         else{
//             if (i == 0){ 
//               strcpy(x,coords_temp);
//             }
//             else if (i == 1){
//               strcpy(y,coords_temp);
//             }
//             else if (i == 2){
//               strcpy(z,coords_temp);
//             }
//             memset(coords_temp,0,sizeof(coords_temp));
//             i++;
//         }
//     }
//     strcpy(z,coords_temp);
//     memset(coords_temp,0,sizeof(coords_temp));
// }

int main() {


    std::string myString = "one,two,three";
    char delim = ',';
    std::vector<char> split_arr;
    split_string(myString,delim,split_arr);
    std::cout << split_arr[0];
    std::cout << split_arr[1];
    std::cout << split_arr[2];
    std::cout << split_arr[3];

        
    // std::string x;

    // // read user input
    // std::cin >> x;

    // std::string text = "You said ";
    // std::cout << text.append(x).append("\n");

    return 0;
}