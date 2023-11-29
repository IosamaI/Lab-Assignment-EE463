

#include <stdio.h>

int main() {
    // Declare four character variables to represent each letter in the combination
    char i, j, k, l;

    // First loop: iterate 'i' through all lowercase letters from 'a' to 'z'
    for(i = 'a'; i <= 'z'; i++) {
        // Second loop: iterate 'j' through all lowercase letters
        for(j = 'a'; j <= 'z'; j++) {
            // If 'j' is the same as 'i', skip to the next iteration
            // to avoid repeating the same letter
            if(j == i) continue;

            // Third loop: iterate 'k' through all lowercase letters
            for(k = 'a'; k <= 'z'; k++) {
                // If 'k' is the same as 'i' or 'j', skip to the next iteration
                if(k == i || k == j) continue;

                // Fourth loop: iterate 'l' through all lowercase letters
                for(l = 'a'; l <= 'z'; l++) {
                    // If 'l' is the same as 'i', 'j', or 'k', skip to the next iteration
                    if(l == i || l == j || l == k) continue;

                    // Print the combination of letters
                    printf("%c%c%c%c\n", i, j, k, l);
                }
            }
        }
    }
    return 0;
}
