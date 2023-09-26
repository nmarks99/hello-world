#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

// splits a char array into a std::vector<double>
std::vector<double> split_char_arr(const char *msg, char delimiter=',') {
    // copies char* to std::string, replaces delimiter with spaces,
    // creates an istringstream from the string and splits by whitespace,
    // and finally, converts each substring to a double and stores it in a
    // std::vector<double> and returns it
    std::string s_msg(msg);
    std::replace(s_msg.begin(), s_msg.end(), delimiter, ' ');
    std::istringstream ss(s_msg);
    std::vector<double> v_out{std::istream_iterator<double>(ss), {}};
    return v_out;
}
