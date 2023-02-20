#include "Game.h"


Game::Game(Player *player1, Player *player2, size_t size) {
    this->player1 = player1;
    this->player2 = player2;
    this->size=size;
    board.resize(size, vector<char>(size, ' '));
    board[3][3] = 'X';
    board[4][4] = 'X';
    board[3][4] = 'O';
    board[4][3] = 'O';
    currentPlayer = 'X';
}

void Game::Run() {
    while (!isGameOver())
    {
        cout << string(5, '\n');
        cout << "Reversi" << endl;
        cout << string (2+size*3+(size+1), '-')<< endl;

        draw_board();

        cout << "Player " << getCurrentPlayerObject()->getGameName()
             << ", enter your move (row col): -("<<currentPlayer<<")";
        Move move = getCurrentPlayerObject()->getNextMove(board, currentPlayer);

        while (!makeMove(move.row -1, move.col -1))
        {
            cout << "Invalid move. Try again." << endl;
            move = getCurrentPlayerObject()->getNextMove(board, currentPlayer);
        }
        flipPlayer();
    }
    cout << "Game over!\n";
}

void Game::flipPlayer() { currentPlayer = currentPlayer == 'X' ? 'O' : 'X'; }

void Game::draw_board() {
    for (int r = 0; r < size; ++r)
    {
        cout << r + 1 << " ";
        cout << "| ";

        for (int c = 0; c < size; ++c)
        {
            cout << board[r][c] << " | ";
        }

        cout << endl << string (2+size*3+(size+1), '-') << endl;
    }

    cout << "   ";
    for (int c = 0; c < size; ++c)
    {
        cout << c + 1 << "   ";
    }
    cout << endl << endl;
}

Player *Game::getCurrentPlayerObject() {
    return (currentPlayer=='X')?player1:player2;
}

bool Game::makeMove(int row, int col)
{
    if (!isValidMove(row, col))
    {
        return false;
    }
    board[row][col] = currentPlayer;
    flipPieces(row, col);
    return true;
}

bool Game::isValidMove(int row, int col)
{
    if (row < 0 || row >= size || col < 0 || col >= size)
    {
        return false;
    }
    if (board[row][col] != ' ')
    {
        return false;
    }
    char otherPlayer;
    if(currentPlayer == 'X')
    {
        otherPlayer = 'O';
    }
    else
    {
        otherPlayer = 'X';
    }
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (auto d : directions)
    {
        int r = row + d.first;
        int c = col + d.second;
        if (r >= 0 && r < size && c >= 0 && c < size && board[r][c] == otherPlayer)
        {
            r += d.first;
            c += d.second;
            while (r >= 0 && r < size && c >= 0 && c < size && board[r][c] == otherPlayer)
            {
                r += d.first;
                c += d.second;
            }
            if (r >= 0 && r < size && c >= 0 && c < size && board[r][c] == currentPlayer)
            {
                return true;
            }
        }
    }
    return false;
}
bool Game::isGameOver()
{

    int count_x=0, count_0=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(board[i][j]=='X')
                count_x++;
            if(board[i][j]=='O')
                count_0++;
        }
    }
    if(!count_x||!count_0)
        return true;
    // Check if either player has any valid moves left
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (isValidMove(i, j))
            {
                return false;
            }
        }
    }

    // Check if the board is full
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }

    // If neither player has a valid move and the board is full, the game is over
    return true;
}

void Game::flipPieces(int row, int col)
{
    char otherPlayer;
    if (currentPlayer == 'X')
    {
        otherPlayer = 'O';
    }
    else
    {
        otherPlayer = 'X';
    }
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (auto d : directions)
    {
        int r = row + d.first;
        int c = col + d.second;
        if (r >= 0 && r < size && c >= 0 && c < size && board[r][c] == otherPlayer)
        {
            vector<pair<int, int>> toFlip;
            toFlip.push_back({r, c});
            r += d.first;
            c += d.second;
            while (r >= 0 && r < size && c >= 0 && c < size && board[r][c] == otherPlayer)
            {
                toFlip.push_back({r, c});
                r += d.first;
                c += d.second;
            }
            if (r >= 0 && r < size && c >= 0 && c < size && board[r][c] == currentPlayer)
            {
                for (auto p : toFlip)
                {
                    board[p.first][p.second] = currentPlayer;
                }
            }
        }
    }
}
string Game::countScore() {
    int x_count = 0, o_count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 'X') {
                x_count++;
            } else if (board[i][j] == 'O') {
                o_count++;
            }
        }
    }
    return "X: " + to_string(x_count) + " O: " + to_string(o_count);
}
Player * Game::getWinner()
{
    int x_count = 0, o_count = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == 'X')
            {
                x_count++;
            }
            else if (board[i][j] == 'O')
            {
                o_count++;
            }
        }
    }

    if (x_count > o_count)
    {
        return player1;
    }
    else if (o_count > x_count)
    {
        return player2;
    }
    else
    {
        return nullptr;
    }
}

Game::Game(const Game &other)
        : player1(other.player1), player2(other.player2),
          currentPlayer(other.currentPlayer), size(other.size), board(other.board)
{
}

Game &Game::operator=(const Game &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete player1;
    delete player2;

    player1 = other.player1;
    player2 = other.player2;
    currentPlayer = other.currentPlayer;
    size = other.size;
    board = other.board;

    return *this;
}

void Game::UserRun() {
    cout << "         Welcome to Reversi!" << endl;
    while (!isGameOver())
    {

        cout << string(5, '\n');
        cout << "Reversi" << endl;
        cout << string (2+size*3+(size+1), '-')<< endl;

        draw_board();

        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        int row, col;
        cin >> row >> col;
        while (!makeMove(row -1, col -1))
        {
            cout << "Invalid move. Try again." << endl;
            cin >> row >> col;
        }
        if (currentPlayer == 'X')
        {
            currentPlayer = 'O';
        }
        else
        {
            currentPlayer = 'X';
        }
    }
    cout << "Game over!\n";
}




string Game::AiPlayer::getGameName() {
    return "Terminator: T-800";
}

int Game::AiPlayer::evaluateBoard(char player) {
    int score = 0;
    for (int r = 0; r < game->size; ++r) {
        for (int c = 0; c < game->size; ++c) {
            if (game->board[r][c] == player) {
                score += 1;
            } else if (game->board[r][c] != ' ') {
                score -= 1;
            }
        }
    }
    return score;
}

Game::AiPlayer::AiPlayer(Game::AiPlayer::Difficulty difficulty, Game *game) {
    this->difficulty = difficulty;
    this->game = new Game(*game);
}

Game::AiPlayer::~AiPlayer(){
    delete game;
}

int Game::AiPlayer::minmax(int depth, bool maximizingPlayer, char player, int alpha, int beta, Game game) {
    if (depth == 0 || game.isGameOver()) {
        return evaluateBoard(player);
    }
    if (maximizingPlayer) {
        int bestValue = INT_MIN;
        for (int r = 0; r < game.size; ++r) {
            for (int c = 0; c < game.size; ++c) {
                if (game.isValidMove(r, c)) {
                    Game child = game;
                    child.makeMove(r, c);
                    child.flipPlayer();
                    //cout<<r<<c<<endl;
                    int value = minmax(depth - 1, false, player, alpha, beta, child);
                    bestValue = max(bestValue, value);
                    alpha = max(alpha, bestValue);
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return bestValue;
    } else {
        int bestValue = INT_MAX;
        for (int r = 0; r < game.size; ++r) {
            for (int c = 0; c < game.size; ++c) {
                if (game.isValidMove(r, c)) {
                    Game child = game;
                    child.makeMove(r, c);
                    child.flipPlayer();
                    //cout<<r<<c<<endl;
                    int value = minmax(depth - 1, true, player, alpha, beta, child);
                    bestValue = min(bestValue, value);
                    beta = min(beta, bestValue);
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return bestValue;
    }
}

pair<int, int> Game::AiPlayer::getBestMove(char player) {
    int depth = 0;
    switch(difficulty){

        case Difficulty::EASY:
            depth = 2;
            break;
        case Difficulty::MEDIUM:
            depth = 4;
            break;
        case Difficulty::HARD:
            depth = 6;
            break;
    }
    int bestValue = INT_MIN;
    pair<int, int> bestMove = make_pair(-1, -1);
    for (int r = 0; r < game->size; ++r) {
        for (int c = 0; c < game->size; ++c) {
            if (game->isValidMove(r, c)) {
                Game child = *game;
                child.makeMove(r, c);
                child.flipPlayer();
                int value = minmax(depth - 1, false, player, INT_MIN, INT_MAX, child);
                if (value > bestValue) {
                    bestValue = value;
                    bestMove = make_pair(r, c);
                }
            }
        }
    }
    return bestMove;
}

Move Game::AiPlayer::getNextMove(vector<vector<char>> board, char curPlayer) {
    game->board = board;
    game->currentPlayer = curPlayer;
    pair<int,int> best_move = getBestMove(curPlayer);
    cout<<"T-800: choose ("<<best_move.first+1<<','<<best_move.second+1<<')';
    return Move{best_move.first+1, best_move.second+1};
}


Game::AiPlayer::AiPlayer(const AiPlayer& other) : Player(other) {
    this->difficulty = other.difficulty;
    this->game = other.game;
}

Game::AiPlayer &Game::AiPlayer::operator=(const Game::AiPlayer &other) {
    if (this != &other) {
        Player::operator=(other);
        this->difficulty = other.difficulty;
        this->game = other.game;
    }
    return *this;
}
//void Game::AiPlayer::incrementBronze(User& user) {
    //bronze++;
//}
//void Game::AiPlayer::incrementSilver(User& user) {
    //silver++;
//}
//void Game::AiPlayer::incrementGold(User& user) {
    //gold++;
//}

//void Game::AiPlayer::awardPoints(User& user) {
   //if(getWinner()==player1) {
      // if (difficulty == Difficulty::EASY) {
        //   user.incrementBronze();
        //   cout << "You have been awarded 1 point (bronze)!" << endl;
       //} else if (difficulty == Difficulty::MEDIUM) {
       //    user.incrementSilver();
        //   cout << "You have been awarded 1 point (silver)!" << endl;
      // } else if (difficulty == Difficulty::HARD) {
      //     user.incrementGold();
      //     cout << "You have been awarded 1 point (gold)!" << endl;
      // }
   //}
//}


