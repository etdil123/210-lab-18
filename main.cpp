#include <iostream>
#include <string>
using namespace std;


struct Node { 
    float movieRating;
    string reviewComments;
    Node * next;
};

void insertNodeHead(Node * &head, Node * &newMovie);
void insertNodeTail(Node * &head, Node * &newMovie);
void outputReviews(Node * &head);

int main() {
    
    char repeat;
    // initializes the linked list
    Node *head = nullptr;
    
    int userDecision;
    float mRating;
    string mComments;
   
    cout << "Select linked list method to be used: " << endl;
    cout << "   [1] New nodes are added at the head of the linked list" << endl;
    cout << "   [2] New nodes are added to the tail of the linked list" << endl;
    cout << "   Your Choice: ";
    cin >> userDecision;

    while (repeat != 'n' && repeat != 'N'){
        
        cout << "Enter review rating 0-5: ";
        cin >> mRating;
        cin.ignore();

        cout << "Enter review comments: ";
        getline(cin, mComments); 

        Node *newMovie = new Node;
        newMovie->movieRating = mRating;
        newMovie->reviewComments = mComments;

        if (userDecision == 1)
            insertNodeHead(head, newMovie);
        else
            insertNodeTail(head, newMovie);

        cout << "Enter another review? Y/N: ";
        cin >> repeat;
        
    }




    return 0;
}

void insertNodeHead(Node * &head, Node * &newMovie){

    // if first node - then make it the head
    if (!head) {
        head = newMovie;
        // since only 1 item in linked list - need to make it point to nullptr
        newMovie = nullptr;
    }
    else {
        newMovie->next = head;
        head = newMovie;
    }
}

void insertNodeTail(Node * &head, Node * &newMovie){
    Node * curr = head;
    Node * prev = head;

    if (!head) {
        head = newMovie;
        // since only 1 item in linked list - need to make it point to nullptr
        newMovie = nullptr;
    }
    else {
        // traverse the linked list
        while (curr) {
            curr = curr->next;
            prev = prev ->next;
        }
        // at end - now insert between prev and curr
        newMovie->next = curr;
        prev->next = newMovie;
    }
}

void outputReviews(Node * &head) {

    float sum = 0;
    int count = 1;

    if (!head){
        cout << "No movie reviews!" << endl;
        return;
    }

    Node * curr = head;



}