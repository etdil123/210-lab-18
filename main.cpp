#include <iostream>
#include <string>
using namespace std;


struct Node { 
    float movieRating;
    string reviewComments;
    Node * next;
};

int main() {
    
    char repeat;
    
    while (char != 'n' || char != 'N'){
        int userDecision;

        cout << "Select linked list method to be used: " << endl;
        cout << "   [1] New nodes are added at the head of the linked list" << endl;
        cout << "   [2] New nodes are added to the tail of the linked list" << endl;
        cout << "   Your Choice: ";
        cin >> userDecision;


        cout << "Enter another review? Y/N: "
        
    }

    return 0;
}