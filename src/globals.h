/******************************************************************************\
================================================================================

Define/declare global types, constants/variables, macros, function prototypes

================================================================================
\******************************************************************************/


/*
 * INCLUDE STANDARD LIBRARIES
 */

#include <cstdio>

/*
 * DEFINE GLOBAL TYPES
 */

// Define bitboard type
#define U64 unsigned long long

/*
 * DEFINE GLOBAL CONSTANTS AND VARIABLES
 */

// Squares enumeration
enum {
    A8, B8, C8, D8, E8, F8, G8, H8,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A1, B1, C1, D1, E1, F1, G1, H1
};
// Sides enumeration
enum {
    white, black
};

// Bitboard with A file cleared
const U64 not_a_file = 18374403900871474942ULL;
// Bitboard with H file cleared
const U64 not_h_file = 9187201950435737471ULL;
// Bitboard with H and G files cleared
const U64 not_hg_file = 4557430888798830399ULL;
// Bitboard with A and B files cleared
const U64 not_ab_file = 18229723555195321596ULL;

// Declare pawn attacks table
extern U64 pawn_attacks[2][64];
// Declare knight attacks table
extern U64 knight_attacks[64];

/*
 * DEFINE MACROS
 */

// Get bit state
#define get_bit(bitboard, square) (((bitboard) & (1ULL << (square))) ? 1 : 0)
// Set bit state
#define set_bit(bitboard, square) ((bitboard) |= (1ULL << (square)))
// Clear bit state
#define clear_bit(bitboard, square) ((bitboard) &= ~(1ULL << (square)))

/*
 * DECLARE FUNCTION PROTOTYPES
 */

// main.cpp
void print_bitboard(U64 bitboard);

// attacks.cpp
void init_leapers_attacks();

U64 gen_pawn_attacks(int side, int square);

U64 gen_knight_attacks(int square);














