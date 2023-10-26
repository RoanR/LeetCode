#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set <int> winners;
        unordered_set <int> oneLost;
        unordered_set <int> losers;

        for (int i = 0; i < matches.size(); i++){
            //Sorting Losers
            if (winners.find(matches[i][1]) == winners.end()){
                if (losers.find(matches[i][1]) == losers.end()){
                    if (oneLost.find(matches[i][1]) == oneLost.end()){
                        oneLost.insert(matches[i][1]);
                    } else {
                        oneLost.erase(oneLost.find(matches[i][1]));
                        losers.insert(matches[i][1]);
                    } 
                }
            } else {
                winners.erase(winners.find(matches[i][1]));
                oneLost.insert(matches[i][1]);
            }

            //sorting winners
            if (losers.find(matches[i][0]) == losers.end()){
                if (oneLost.find(matches[i][0]) == oneLost.end()){
                    winners.insert(matches[i][0]);
                }       
            }
        }

        vector<int> winnersFinal;
        vector<int> oneLostFinal;
        for (const auto& player: winners) {
            winnersFinal.push_back(player);
        }
        for (const auto& player: oneLost) {
            oneLostFinal.push_back(player);
        }
        sort(oneLostFinal.begin(), oneLostFinal.end());
        sort(winnersFinal.begin(), winnersFinal.end());

        return{winnersFinal, oneLostFinal};
    }
};