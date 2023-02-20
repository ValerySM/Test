#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Animal.h"
#include "User.h"
#include "Player.h"
#include "Game.h"
#include "League.h"
static const char *const USER_FILE_NAME = "users.csv";
using namespace std;

void playLeague();

void registerUser();

void readUsers(vector<User> &users);

void getUserData(vector<User> &users, string &username, string &password, Animal** animal);

void saveUsers2File(vector<User> &users);

User *playerLogin();

void getUserNewNameAndPassword(vector<User> &users, string &username, string &password);

void play_with_ai();

void play_with_user();

int main() {
    int choice = 0;
    User* loggedUser= nullptr;
    while (choice != 7) {
        // Display the menu options
        cout << "Welcome to the home screen!" << endl;
        cout << "1. New player registration." << endl;
        cout << "2. Player login." << endl;
        cout << "3. Play vs User." << endl;
        cout << "4. Play vs Terminator T - 800." << endl;
        cout << "5. Entering a league or create new." << endl;
        cout << "6. Print the leader board" << endl;
        cout << "7. Output" << endl;

        // Prompt the user for their choice
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle the user's choice
        switch (choice) {
            case 1:
                registerUser();
                //addNewPlayer();
                break;
            case 2:
                loggedUser = playerLogin();
                if (loggedUser)
                    cout<<"Logged in as "<<loggedUser->getAsString()<<endl;
                else
                    cout<<"No match"<<endl;
                break;
            case  3:
                //play with user
                //play_with_user();


                break;
            case  4:
                play_with_ai();
                break;
            case 5:

                playLeague();
                break;
            case 6:
                //printLeaderboard();
                break;
            case 7:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    if(!loggedUser)
        delete loggedUser;
    return 0;
}

User *playerLogin() {
    string userName, password;
    User* loggedUser = nullptr;
    cout << "Enter a username: ";
    cin >> userName;
    cout << "Enter a password: ";
    cin >> password;
    vector<User> users;
    readUsers(users);
    for(const User& user: users)
        if(user.getUsername()==userName && user.getPassword() == password)
            loggedUser = new User(user);

    return loggedUser;
}

int main1()
{
    play_with_user();
    play_with_ai();
    //registerUser();
    return 0;
}

void play_with_user() {
    User user1 = User("First,12345,1,123,2,32,0,Fish,Barracuda");
    User user2 = User("Lex2,12345,1,123,2,32,3,Fish,Shark");
    Player* player1 =new UserPlayer(&user1);
    Player* player2 =new UserPlayer(&user2);
    Game game = Game(player1, player2, 8);
    game.Run();
}


void play_with_ai() {
    User user1 = User("Lex,12345,1,123,2,32,0,Fish,Barracuda");
    User user2 = User("Lex2,12345,1,123,2,32,3,Fish,Shark");
    Player* player1 =new UserPlayer(&user1);
    Player* player2 =new UserPlayer(&user2);
    Game game = Game(player1, player2, 8);
    //Player* playerAi =new Game::AiPlayer(Game::AiPlayer::Difficulty::EASY, &game);
    Player* playerAi2 =new Game::AiPlayer(Game::AiPlayer::Difficulty::EASY, &game);
    Game game2 =  Game(player1, playerAi2, 8);
    game2.Run();
    //todo get result from game. If user win increase gold\silver\bronze and save to file
}

void playLeague()
{
    //todo init game from file
    vector<User> users;
    vector<User*> p_users;
    vector<UserPlayer*> userPlayers;
    readUsers(users);
    int size = 0;//todo get_from_user
    cout<<"Enter a size of board you wanna play "<<endl;
    cin>>size;
    League league(size);
    for (const User& user: users)
        p_users.push_back(new User(user));
    for(User* p_user: p_users)
        userPlayers.push_back(new UserPlayer(p_user));
    for (UserPlayer* userPlayer: userPlayers)
        league.addPlayer(userPlayer);
    league.playMatches();
    //league.printTree();
    //todo start leage games
}

void registerUser() {
    vector<User> users;
    readUsers(users);
    string username, password;
    Animal *animal = nullptr;
    getUserData(users, username, password, &animal);
    User newUser = User(username, password, animal);
    users.push_back(newUser);

    saveUsers2File(users);
}

void saveUsers2File(vector<User> &users) {
    ofstream file(USER_FILE_NAME);
    for(User user: users)
        file<<user.getAsString()<<endl;
    file.close();
}

void getUserData(vector<User> &users, string &username, string &password, Animal** animal) {
    bool badanimal = true;
    getUserNewNameAndPassword(users, username, password);

    cout << "Choose player type (Mammal, Fish,Insect): ";
    string type;
    cin >> type;

    while (badanimal) {
        badanimal = false;
        if (type == "Mammal")
        {
            cout << "Choose mammal type (Dolphin, Dog, Cat): ";
            string mammalType;
            cin >> mammalType;

            if (mammalType == "Dolphin") {
                *animal = Animal::createAnimal("Mammal", "Dolphin");
            } else if (mammalType == "Dog") {
                *animal = Animal::createAnimal("Mammal", "Dog");
            } else if (mammalType == "Cat") {
                *animal = Animal::createAnimal("Mammal", "Cat");
            } else {
                cout << "Invalid mammal type." << endl;
                badanimal = true;
            }
        } else if (type == "Fish")
        {
            cout << "Choose fish type (Shark, Barracuda): ";
            string fishType;
            cin >> fishType;

            if (fishType == "Shark") {
                *animal = Animal::createAnimal("Fish", "Shark");
            } else if (fishType == "Barracuda") {
                *animal = Animal::createAnimal("Fish", "Barracuda");
            } else {
                cout << "Invalid fish type." << endl;
                badanimal = true;
            }
            }
        else if (type == "Insect")
        {
            cout << "Choose insect type (Ant, Grasshopper, Wasp): ";
            string insectType;
            cin >> insectType;

            if (insectType == "Ant") {
                *animal = Animal::createAnimal("Insect", "Ant");
            } else if (insectType == "Grasshopper") {
                *animal = Animal::createAnimal("Insect", "Grasshopper");
            } else if (insectType == "Wasp") {
                *animal = Animal::createAnimal("Insect", "Wasp");
            } else {
                cout << "Invalid insect type." << endl;
                badanimal = true;
            }

        }
        else
        {
            cout << "Invalid player type." << endl;
            badanimal = true;
        }
    }
}

void getUserNewNameAndPassword(vector<User> &users, string &username, string &password) {
    bool badname = true;

    while(badname) {
        cout << "Enter a username: ";
        cin >> username;
        for (const User& user: users) {
            if (user.getUsername() == username) {
                badname = true;
                break;
            }
            badname = false;
        }
    }
    cout << "Enter a password: ";
    cin >> password;
}

void readUsers(vector<User> &users) {
    ifstream file(USER_FILE_NAME);
    if (!file.is_open()) {
        return;
    }


    string line;
    while (getline(file, line)) {
        User user = User(line);
        users.push_back(user);
    }

    file.close();

    // print out user data
    // for (const auto& user : users) {
    //    cout << "login: " << user.getUsername() << ", password: " << user.getPassword() << endl;
    //}
}
