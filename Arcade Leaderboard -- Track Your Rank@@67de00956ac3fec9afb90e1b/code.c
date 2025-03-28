#include <stdio.h>

void findRank(int leaderboard[], int leaderboardSize, int scores[], int scoresSize) {
    // Step 1: Create an array to hold unique scores
    int uniqueScores[leaderboardSize];
    int uniqueCount = 0;

    // Step 2: Populate uniqueScores with unique leaderboard scores
    for (int i = 0; i < leaderboardSize; i++) {
        if (i == 0 || leaderboard[i] != leaderboard[i - 1]) {
            uniqueScores[uniqueCount++] = leaderboard[i];
        }
    }

    // Step 3: For each score, determine the rank
    int rankIndex = uniqueCount - 1; // Start from the lowest rank
    for (int i = 0; i < scoresSize; i++) {
        // Move up the leaderboard until we find the right rank
        while (rankIndex >= 0 && scores[i] >= uniqueScores[rankIndex]) {
            rankIndex--;
        }
        // The rank is the index + 2 (because rankIndex is 0-based and we need to skip the ranks)
        printf("Your rank after game %d (score %d): %d\n", i + 1, scores[i], rankIndex + 2);
    }
}

int main() {
    // Example leaderboard scores (descending order)
    int leaderboard[] = {100, 90, 90, 80, 75, 60};
    int leaderboardSize = sizeof(leaderboard) / sizeof(leaderboard[0]);

    // Example scores you achieved (ascending order)
    int scores[] = {70, 80, 90, 95};
    int scoresSize = sizeof(scores) / sizeof(scores[0]);

    // Find and print ranks
    findRank(leaderboard, leaderboardSize, scores, scoresSize);

    return 0;
}