#include <stdio.h>

// Function to remove duplicates and return the size of unique elements
int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

// Binary search function to find the rank of the player's score
int findRank(int arr[], int size, int score) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == score) {
            return mid + 1;  // Same score as someone in the leaderboard
        } else if (arr[mid] < score) {
            high = mid - 1;  // Move left
        } else {
            low = mid + 1;   // Move right
        }
    }
    return low + 1;  // Rank is 1-based
}

void climbingLeaderboard(int leaderboard[], int n, int scores[], int m) {
    // Remove duplicates from leaderboard
    int uniqueSize = removeDuplicates(leaderboard, n);

    // Find rank for each game score
    for (int i = 0; i < m; i++) {
        printf("%d\n", findRank(leaderboard, uniqueSize, scores[i]));
    }
}

// Driver code
int main() {
    int leaderboard[] = {100, 90, 90, 80, 75, 60};
    int scores[] = {50, 65, 77, 90, 102};

    int n = sizeof(leaderboard) / sizeof(leaderboard[0]);
    int m = sizeof(scores) / sizeof(scores[0]);

    climbingLeaderboard(leaderboard, n, scores, m);

    return 0;
}
