#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generatePowerset(const vector<char>& set, vector<char>& subset, int index) {
    if (index == set.size()) {
        cout << "(";
        for (char c : subset) {
            cout << c;
        }
        cout << ")" << endl;
        return;
    }

    generatePowerset(set, subset, index + 1);

    subset.push_back(set[index]);
    generatePowerset(set, subset, index + 1);
    subset.pop_back();
}

int main() {
    vector<char> set = {'a', 'b', 'c'};
    vector<char> subset;
    
    cout << "Powerset: " << endl;
    generatePowerset(set, subset, 0);
    
    return 0;
}

