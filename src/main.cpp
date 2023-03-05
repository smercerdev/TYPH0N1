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
 * MAIN FUNCTION
 */

int main() {
    init_leapers_attacks();

    for (int square = 0; square < 64; square++) {
        print_bitboard(knight_attacks[square]);
        print_bitboard(pawn_attacks[white][square]);
    }
    return 0;
}

