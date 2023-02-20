#include "League.h"
#include <iostream>
#include <algorithm>

void League::addPlayer(UserPlayer* player) {
    players.push_back(player);
}

// play all matches in the league
void League::playMatches() {
    // randomly pair the players
    std::random_shuffle(players.begin(), players.end());
    std::vector<std::pair<UserPlayer*, UserPlayer*>> pairs;
    for (size_t i = 0; i < players.size(); i += 2) {
        pairs.push_back(std::make_pair(players[i], players[i + 1]));
    }

    // play each match
    for (const auto& pair : pairs) {
        UserPlayer* p1 = pair.first;
        UserPlayer* p2 = pair.second;

        // play the match and record the result
        int result = playMatch(p1, p2, size);
        Match match(p1, p2, size);
        match.result = result;
        matches.push_back(match);
    }
}

// print the league tree
void League::printTree() {
    // print the matches
    cout << "Matches:" << endl;
    for (int i = 0; i < matches.size(); i++) {
        Match match = matches[i];
        cout << match.p1->getGameName() << " vs. " << match.p2->getGameName() << endl;
    }
    cout << endl;

    // print the league standings
    cout << "League Standings:" << endl;
    for (int i = 0; i < players.size(); i++) {
        UserPlayer* player = players[i];
        player->increment_score();
        cout << player->getGameName() << ": " << player->getUser()->getScore() << " points" << endl;
    }
}