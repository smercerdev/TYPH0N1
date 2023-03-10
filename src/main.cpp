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
    U64 blockers = 0ULL;
    set_bit(blockers, B4);
    set_bit(blockers, D5);
    set_bit(blockers, G4);
    set_bit(blockers, D2);

    print_bitboard(gen_rook_attacks(D4, blockers));

    return 0;
}

