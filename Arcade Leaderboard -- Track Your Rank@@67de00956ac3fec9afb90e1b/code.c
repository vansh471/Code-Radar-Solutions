#include <stdio.h>

// Function to remove duplicate scores and return new size
int removeDuplicates(int arr[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[j++] = arr[i];
        }
    }
    return j;  // Return new size of the unique leaderboard
}

// Binary search to find the rank of the given score
int findRank(int uniqueScores[], int size, int score) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (uniqueScores[mid] == score) {
            return mid + 1; // Exact match found, return rank (1-based index)
        } else if (uniqueScores[mid] < score) {
            high = mid - 1; // Move left (higher rank)
        } else {
            low = mid + 1; // Move right (lower rank)
        }
    }

    return low + 1; // New rank position (1-based index)
}

// Function to determine ranks for player's scores
void climbingLeaderboard(int leaderboard[], int n, int scores[], int m) {
    // Step 1: Remove duplicate scores
    int uniqueScores[n];  
    for (int i = 0; i < n; i++) uniqueScores[i] = leaderboard[i];  
    int uniqueSize = removeDuplicates(uniqueScores, n);

    // Step 2: Find rank for each game score
    for (int i = 0; i < m; i++) {
        int rank = findRank(uniqueScores, uniqueSize, scores[i]);
        printf("%d\n", rank);
    }
}

// Main function
int main() {
    int leaderboard[] = {100, 90, 90, 80, 75, 60};  // Leaderboard scores (descending)
    int scores[] = {50, 65, 77, 90, 102};           // Player's scores (ascending)
    
    int n = sizeof(leaderboard) / sizeof(leaderboard[0]);
    int m = sizeof(scores) / sizeof(scores[0]);

    climbingLeaderboard(leaderboard, n, scores, m);
    
    return 0;
}
