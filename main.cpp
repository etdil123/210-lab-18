#include <iostream>
#include <string>
using namespace std;


struct Node { 
    float movieRating;
    string reviewComments;
    Node * next;
};

void insertNodeHead(Node * &head, float, string);
void insertNodeTail(Node * &head, float, string);

int main() {
    
    char repeat;
    // initializes the linked list
    Node *head = nullptr;
    
    while (repeat != 'n' && repeat != 'N'){
        int userDecision;
        float mRating;
        string mComments;

        cout << "Select linked list method to be used: " << endl;
        cout << "   [1] New nodes are added at the head of the linked list" << endl;
        cout << "   [2] New nodes are added to the tail of the linked list" << endl;
        cout << "   Your Choice: ";
        cin >> userDecision;

        cout << "Enter review rating 0-5: ";
        cin >> mRating;
        cin.ignore();

        cout << "Enter review comments: ";
        getline(cin, mComments); 


        cout << "Enter another review? Y/N: ";
        cin >> repeat;
        
    }

    return 0;
}

void insertNodeHead(Node * &head, float rating, string review){

    





}