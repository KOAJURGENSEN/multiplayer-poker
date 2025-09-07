//play no limit texas holdem poker 
//Per game: 
//  up to 22 players
//Per hand:
//  From right to left:
//  button (deals)
//  small blind
//  big blind
//  early position
//  middle position
//  late position
//  2 hole cards
//  5 card river (3 card flop + 2 turn cards)
//Per hand:
//  Betting starts with left of big blind 
//  Fold    
//  call - matching bet
//  raise (minimum of double big blind)
//  Check - Passing action to next (after flop)
//Hand rankings (worst to best):
//  High card
//  Pair
//  Two pair
//  Three of a kind
//  Straight (ace is high or low)
//  Flush (5 cards same suit)
//  Full House (Three of a kind + pair)
//  Four of a kind
//  Straight Flush
//  Royal Flush (Straight flush 10-K)

//Classes:
//  Deck?
//  Card
//  Player
//  Game
#include <iostream>


#include <string>
#include <stack>

#include <random>
#include <chrono>

class Card{
    public:
        int value;
        char suit;
        Card(int value, char suit){
            this->value = value;
            this->suit = suit;
        }
        Card(){}

};

class Player{
    public:
        int balance;
        std::string name;
        Player* next; //????
        Player(int balance, std::string& name){
            this->balance = balance;
            next = nullptr;
        }

};

//https://cppscripts.com/circular-linked-list-cpp
class CircularLinkedList{
    public:
        Player* head;

        CircularLinkedList(){
            head = nullptr;
        }

        void append(int balance, std::string& name){
            Player* newPlayer = new Player(balance, name);

            if(!head){
                head = newPlayer;
                newPlayer->next = head;
            } else {
                Player* temp = head;
                while(temp->next != head){
                    temp = temp->next;
                }
                temp->next = newPlayer;
                newPlayer->next = head;
            }
        }

        void display(){
            if(head){
                Player* temp = head;
                do{
                    std::cout << temp->name << "'s Balance:  " << temp->balance << '\n';
                    temp = temp->next;
                }
                while (temp != head);
                }
        }
};


class Deck{

    public:
    Card deck[52] = 
    {
        {1, 'c'}, {1, 's'}, {1, 'd'}, {1, 'h'},
        {2, 'c'}, {2, 's'}, {2, 'd'}, {2, 'h'},
        {3, 'c'}, {3, 's'}, {3, 'd'}, {3, 'h'},
        {4, 'c'}, {4, 's'}, {4, 'd'}, {4, 'h'},
        {5, 'c'}, {5, 's'}, {5, 'd'}, {5, 'h'},
        {6, 'c'}, {6, 's'}, {6, 'd'}, {6, 'h'},
        {7, 'c'}, {7, 's'}, {7, 'd'}, {7, 'h'},
        {8, 'c'}, {8, 's'}, {8, 'd'}, {8, 'h'},
        {9, 'c'}, {9, 's'}, {9, 'd'}, {9, 'h'},
        {10, 'c'}, {10, 's'}, {10, 'd'}, {10, 'h'},
        {11, 'c'}, {11, 's'}, {11, 'd'}, {11, 'h'},
        {12, 'c'}, {12, 's'}, {12, 'd'}, {12, 'h'},
        {13, 'c'}, {13, 's'}, {13, 'd'}, {13, 'h'}, 
    };
    

    void shuffle(){
        std::mt19937 mt{static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())};
        std::uniform_int_distribution dist{0, 51};

        for(int i = 0; i < 52; i++){
            int rand = dist(mt);
            Card temp;
            temp = deck[i];
            deck[i] = deck[rand];
            deck[rand] = temp;
        }
    }

    void print(){
        for(int i = 0; i < 52; i++){
            std::cout << deck[i].value << ' ' << deck[i].suit << '\n';
        }
    }   
};



class Game{
    public:
        Deck deck;
        CircularLinkedList rotation;

        Game(int numPlayers){

            for(int i = 1; i <= numPlayers; i++){
                std::cout << "Enter Player " << i << ": balance name" << '\n';
                std::cout << "Player " << i << ": ";
                int balance;
                std::string name; 
                std::cin >> balance; //Error heare capturing both bal and name 
                std::cin >> name;   //Fix: do name before balance

                rotation.append(balance, name);
            }
        }
};

using namespace std;
int main(){
    cout << "No limit Holdem" << '\n';
    cout << "Enter [a] to start or [q] to quit:" <<'\n';
    char userInput;
    cin >> userInput;      

    while(userInput != 'q'){
        cout << "Enter number of players: ";
        int numPlayers{};
        cin >> numPlayers;

        Game game{numPlayers};
        game.rotation.display();

    }

    


    //Start
    //How many players >>
        //for range(players)
            //player
    //enter balance one by one
}
