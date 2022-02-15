#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;


class Student {
    private:
        vector<int> scores;

    public:
        void input() {
            int i = 0;
            int temp_score;
            while(i < 5) {
                cin >> temp_score;
                scores.push_back(temp_score);
                i++;
            }
        }

        int calculateTotalScore() {
            int total_score = 0;
            for (int i=0; i < scores.size(); i++) {
                total_score += scores[i];
            }
            return total_score;
        }
};

int main() {

    Student st;
    st.input();
    int total = st.calculateTotalScore();
    cout << total << "\n";

    return 0;
}
