/******************************************************************************\
================================================================================

TBC

================================================================================
\******************************************************************************/

/*
 * INCLUDES
 */

#include "globals.h"

/*
 * FUNCTION DEFINITIONS
 */

// Print bitboard for debugging
void print_bitboard(U64 bitboard) {
    printf("\n");
    // Loop through ranks
    for (int rank = 0; rank < 8; rank++) {
        // Loop through files
        for (int file = 0; file < 8; file++) {
            // Convert rank and file to square
            int square = rank * 8 + file;
            // Print rank number
            if (!file) {
                printf("%d    ", 8 - rank);
            }
            // Print bit state
            printf(" %d ", get_bit(bitboard, square));
        }
        // Print new line after each rank
        printf("\n");
    }
    // Print file letters
    printf("\n      A  B  C  D  E  F  G  H\n");

    // Print bitboard as decimal
    printf("\nBitboard: %llu\n", bitboard);
}