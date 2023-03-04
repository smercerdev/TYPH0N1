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
    BITBOARD bitboard = 0ULL;
    set_bit(bitboard, E4);
    set_bit(bitboard, F5);
    set_bit(bitboard, A2);
    clear_bit(bitboard, E4);
    clear_bit(bitboard, E4);
    print_bitboard(bitboard);
    return 0;
}

