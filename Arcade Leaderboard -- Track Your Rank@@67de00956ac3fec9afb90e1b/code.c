#include <stdio.h>

#define MAX 100000  // Define a maximum size for arrays

// Function to remove duplicates from sorted leaderboard
int removeDuplicates(int arr[], int n) {
    int j = 0; 
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[j++] = arr[i];
        }
    }
    return j;  // New size of unique array
}

// Binary search to find the correct rank position
int findRank(int uniqueScores[], int size, int score) {
    int low = 0, high = size - 1, mid;
    
    while (low <= high) {
        mid = low + (high - low) / 2;
        
        if (uniqueScores[mid] == score) {
            return mid + 1; // Exact match found, return 1-based rank
        } else if (uniqueScores[mid] < score) {
            high = mid - 1; // Move left
        } else {
            low = mid + 1; // Move right
        }
    }
    
    return low + 1; // New rank position (1-based index)
}

void climbingLeaderboard(int leaderboard[], int n, int scores[], int m) {
    // Step 1: Remove duplicate scores from leaderboard
    int uniqueScores[MAX];
    for (int i = 0; i < n; i++) uniqueScores[i] = leaderboard[i];  // Copy array
    int uniqueSize = removeDuplicates(uniqueScores, n);
    
    // Step 2: Compute ranks for each game score
    for (int i = 0; i < m; i++) {
        int rank = findRank(uniqueScores, uniqueSize, scores[i]);
        printf("%d\n", rank);
    }
}

// Main function to test the leaderboard ranking
int main() {
    int leaderboard[] = {100, 90, 90, 80, 75, 60};
    int scores[] = {50, 65, 77, 90, 102};
    
    int n = sizeof(leaderboard) / sizeof(leaderboard[0]);
    int m = sizeof(scores) / sizeof(scores[0]);

    climbingLeaderboard(leaderboard, n, scores, m);
    
    return 0;
}
