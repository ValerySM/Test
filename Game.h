//
// Created by valery-sm on 2/20/2023.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "Player.h"
#include "iostream"
#include "vector"
using namespace std;
class Game {
    Player* player1;
    Player* player2;
    char currentPlayer;
    size_t size;
    vector<vector<char>> board;
    bool makeMove(int row, int col);
    bool isValidMove(int row, int col);
    void flipPieces(int row, int col);
    bool isGameOver();
    string countScore();

public:

    Player * getWinner();
    Game(Player* player1,Player* player2,size_t size);
    void Run();
    void UserRun();
    Player* getCurrentPlayerObject();
    Game(const Game &other);
    Game &operator=(const Game &other);
    void draw_board();


    class AiPlayer: public Player{
    public:
        enum class Difficulty{
            EASY,
            MEDIUM,
            HARD
        };
    private:
        void awardPoints(User& user);
        Difficulty difficulty;
        int evaluateBoard(char player);
        int minmax(int depth, bool maximizingPlayer, char player, int alpha, int beta, Game game);
        pair<int, int> getBestMove(char player);
        Game* game;
    public:
        AiPlayer(Difficulty difficulty, Game* game);
        AiPlayer(const AiPlayer& other);
        void incrementBronze(User& user);
        void incrementSilver(User& user);
        void incrementGold(User& user);
// Assignment operator
        AiPlayer& operator=(const AiPlayer& other);
        Move getNextMove(vector<vector<char>>, char curPlayer);
        virtual string getGameName();
        ~AiPlayer();
    };
    friend AiPlayer;

    void flipPlayer();
};

#endif //PROJECT_GAME_H
