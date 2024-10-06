// Ethan Dilk | Lab 18 | COMSC 210
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
void deleteList(Node * &head);

int main() {
    // initializes the linked list
    Node *head = nullptr;
    
    char repeat = 'y';
    int userDecision;
    float mRating;
    string mComments;
   
    cout << "Select linked list method to be used: " << endl;
    cout << "   [1] New nodes are added at the head of the linked list" << endl;
    cout << "   [2] New nodes are added to the tail of the linked list" << endl;
    cout << "   Your Choice: ";
    cin >> userDecision;

    // while user has not select n or N - input movie ratings & reviews
    while (repeat != 'n' && repeat != 'N'){
        cout << "Enter review rating 0-5: ";
        cin >> mRating;
        cin.ignore();

        cout << "Enter review comments: ";
        getline(cin, mComments); 
        
        // new Node to store user input
        Node *newMovie = new Node;
        newMovie->movieRating = mRating;
        newMovie->reviewComments = mComments;
        newMovie->next = nullptr;
        // If 1 store in head & if 2 store at tail 
        if (userDecision == 1)
            insertNodeHead(head, newMovie);
        else
            insertNodeTail(head, newMovie);

        cout << "Enter another review? Y/N: ";
        cin >> repeat;
    }

    outputReviews(head);
    deleteList(head);

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
            prev = curr;
            curr = curr->next;
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
    cout << "Outputting all reviews: " << endl;
    while (curr) {
        // display curr Node data
        cout << "   > Review #" << count << ": " << curr->movieRating << " Comments: " << curr->reviewComments << endl;
        sum += curr->movieRating;
        count++;
        // move curr to next Node
        curr = curr->next;
    }
    // calculate average and display
    cout << "   > Average Rating: " << (sum / (count - 1)) << endl;
}

void deleteList(Node * &head) {
    Node * curr = head;

    // while curr is not null
    while(curr) {
        // move head to next and delete curr Node
        head = curr->next;
        delete curr;
        curr = head;
    }
    // make head point to nullptr
    head = nullptr;
}
