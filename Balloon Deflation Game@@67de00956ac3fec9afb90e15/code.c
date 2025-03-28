#include <stdio.h>

void deflateBalloons(int balloons[], int size) {
    while (1) {
        int minAir = -1;
        int count = 0;

        // Find the minimum air amount among non-flat balloons
        for (int i = 0; i < size; i++) {
            if (balloons[i] > 0) {
                if (minAir == -1 || balloons[i] < minAir) {
                    minAir = balloons[i];
                }
                count++; // Count how many balloons have air
            }
        }

        // If no balloons have air left, break the loop
        if (count == 0) {
            break;
        }

        // Print the number of balloons with air
        printf("Balloons with air at the beginning of this round: %d\n", count);

        // Release the minimum air amount from all balloons
        for (int i = 0; i < size; i++) {
            if (balloons[i] > 0) {
                balloons[i] -= minAir;
                if (balloons[i] < 0) {
                    balloons[i] = 0; // Ensure no negative air
                }
            }
        }
    }
}

int main() {
    // Example balloon air amounts
    int balloons[] = {10, 5, 15, 20, 0, 8};
    int size = sizeof(balloons) / sizeof(balloons[0]);

    // Start the deflation game
    deflateBalloons(balloons, size);

    return 0;
}