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
 * LEAPERS ATTACKS
 */

// Pawn attack tables
U64 pawn_attacks[2][64];
// Knight attacks table
U64 knight_attacks[64];
// King attacks table
U64 king_attacks[64];

// Initialize attacks for leapers
void init_leapers_attacks() {
    for (int square = 0; square < 64; square++) {
        // Initialize pawn attacks
        pawn_attacks[white][square] = gen_pawn_attacks(white, square);
        pawn_attacks[black][square] = gen_pawn_attacks(black, square);
        // Initialize knight attacks
        knight_attacks[square] = gen_knight_attacks(square);
        // Initialize king attacks
        king_attacks[square] = gen_king_attacks(square);
    }
}

// Generate pawn attacks
U64 gen_pawn_attacks(int side, int square) {
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
    // Return attacks map
    return attacks;
}

// Generate knight attacks
U64 gen_knight_attacks(int square) {
    // Resulting attacks for the knight
    U64 attacks = 0ULL;

    // Set knight position
    U64 bitboard = 0ULL;
    set_bit(bitboard, square);

    // SE attacks
    if ((bitboard >> 17) & not_h_file) attacks |= (bitboard >> 17);
    if ((bitboard >> 10) & not_hg_file) attacks |= (bitboard >> 10);
    // NE attacks
    if ((bitboard << 6) & not_hg_file) attacks |= (bitboard << 6);
    if ((bitboard << 15) & not_h_file) attacks |= (bitboard << 15);
    // SW attacks
    if ((bitboard >> 15) & not_a_file) attacks |= (bitboard >> 15);
    if ((bitboard >> 6) & not_ab_file) attacks |= (bitboard >> 6);
    // NW attacks
    if ((bitboard << 10) & not_ab_file) attacks |= (bitboard << 10);
    if ((bitboard << 17) & not_a_file) attacks |= (bitboard << 17);

    // Return attacks map
    return attacks;
}

// Generate king attacks
U64 gen_king_attacks(int square) {
    // Resulting attacks for the king
    U64 attacks = 0ULL;

    // Set king position
    U64 bitboard = 0ULL;
    set_bit(bitboard, square);

    // SE attack
    if ((bitboard >> 9) & not_h_file) attacks |= (bitboard >> 9);
    // E attack
    if ((bitboard >> 1) & not_h_file) attacks |= (bitboard >> 1);
    // NE attack
    if ((bitboard << 7) & not_h_file) attacks |= (bitboard << 7);
    // N attack
    if ((bitboard << 8)) attacks |= (bitboard << 8);
    // SW attack
    if ((bitboard >> 7) & not_a_file) attacks |= (bitboard >> 7);
    // W attack
    if ((bitboard << 1) & not_a_file) attacks |= (bitboard << 1);
    // NW attack
    if ((bitboard << 9) & not_a_file) attacks |= (bitboard << 9);
    // S attack
    if ((bitboard >> 8)) attacks |= (bitboard >> 8);

    // Return attacks map
    return attacks;
}
