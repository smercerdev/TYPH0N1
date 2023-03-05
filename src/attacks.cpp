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
 * LEAPER ATTACKS
 */

// Pawn attacks table
U64 pawn_attacks[2][64];

// Initialize leaper attacks
void init_leapers_attacks() {
    for (int square = 0; square < 64; square++) {
        // Initialize pawn attacks
        pawn_attacks[white][square] = mask_pawn_attacks(white, square);
        pawn_attacks[black][square] = mask_pawn_attacks(black, square);
    }
}

// Mask pawn attacks
U64 mask_pawn_attacks(int side, int square) {
    // Resulting attacks for the pawn
    U64 attacks = 0ULL;

    // Set pawn position
    U64 bitboard = 0ULL;
    set_bit(bitboard, square);

    // White pawn attacks
    if (!side) {
        // Attack left
        if ((bitboard >> 7) & not_a_file) attacks |= (bitboard >> 7);
        // Attack right
        if ((bitboard >> 9) & not_h_file) attacks |= (bitboard >> 9);

        // Black pawn attacks
    } else {
        // Attack left
        if ((bitboard << 7) & not_h_file) attacks |= (bitboard << 7);
        // Attack right
        if ((bitboard << 9) & not_a_file) attacks |= (bitboard << 9);
    }
    return attacks;
}
