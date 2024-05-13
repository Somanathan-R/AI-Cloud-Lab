#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minimax(int curDepth, int nodeIndex, bool maxTurn, const vector<int>& scores, int targetDepth) {
    // Base case: targetDepth reached
    if (curDepth == targetDepth) {
        return scores[nodeIndex];
    }

    if (maxTurn) {
        return max(minimax(curDepth + 1, nodeIndex * 2, false, scores, targetDepth),
                   minimax(curDepth + 1, nodeIndex * 2 + 1, false, scores, targetDepth));
    } else {
        return min(minimax(curDepth + 1, nodeIndex * 2, true, scores, targetDepth),
                   minimax(curDepth + 1, nodeIndex * 2 + 1, true, scores, targetDepth));
    }
}

int main() {
    vector<int> scores = {3, 5, 2, 9, 12, 5, 23, 23};
    int treeDepth = log2(scores.size());

    cout << "The optimal value is: " << minimax(0, 0, true, scores, treeDepth) << endl;

    return 0;
}
