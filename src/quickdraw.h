
#ifndef QUICKDRAW_H_
#define QUICKDRAW_H_

typedef struct {
    int16_t v;
    int16_t h;
} Point;

typedef struct {
    int16_t top;
    int16_t left;
    int16_t bottom;
    int16_t right;
} Rect;

typedef struct {
    int16_t rgnSize;
    Rect rgnBBox;
    char *data;
} Region;

typedef struct {
    int16_t polySize;
    Rect polyBBox;
    Point *polyPoints;
} Polygon;

typedef struct Pattern {
    uint16_t p[8];
} Pattern;

typedef struct {
    Point pnLoc;
    Point pnSize;
    int16_t pnMode;
    Pattern pnPat;
} PenState;

enum {
    srcCopy    =  0,
    srcOr      =  1,
    srcXor     =  2,
    srcBic     =  3,

    notSrcCopy =  4,
    notSrcOr   =  5,
    notSrcXor  =  6,
    notSrcBic  =  7,

    patCopy    =  8,
    patOr      =  9,
    patXor     = 10,
    patBic     = 11,

    notPatCopy = 12,
    notPatOr   = 13,
    notPatXor  = 14,
    notPatBic  = 15
} PatternModes;

enum {
    blend       = 32,
    addPin      = 33,
    addOver     = 34,
    subPin      = 35,
    transparent = 36,
    addMax      = 37,
    subOver     = 38,
    adMin       = 39
} TransferModes;

const char ditherCopy = 64;
const char hilite = 50;

const int32_t whiteColor   =  30;
const int32_t blackColor   =  33;
const int32_t yellowColor  =  69;
const int32_t magentaColor = 137;
const int32_t redColor     = 205;
const int32_t cyanColor    = 273;
const int32_t greenColor   = 341;
const int32_t blueColor    = 409;

Pattern MacPaintPatterns[] = {
    {}, // index 0 is invalid
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, //  1
    {0xDD, 0xFF, 0x77, 0xFF, 0xDD, 0xFF, 0x77, 0xFF}, //  2
    {0xDD, 0x77, 0xDD, 0x77, 0xDD, 0x77, 0xDD, 0x77}, //  3
    {0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA}, //  4
    {0x55, 0xFF, 0x55, 0xFF, 0x55, 0xFF, 0x55, 0xFF}, //  5
    {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA}, //  6
    {0xEE, 0xDD, 0xBB, 0x77, 0xEE, 0xDD, 0xBB, 0x77}, //  7
    {0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88}, //  8
    {0xB1, 0x30, 0x03, 0x1B, 0xD8, 0xC0, 0x0C, 0x8D}, //  9
    {0x80, 0x10, 0x02, 0x20, 0x01, 0x08, 0x40, 0x04}, // 10
    {0xFF, 0x88, 0x88, 0x88, 0xFF, 0x88, 0x88, 0x88}, // 11
    {0xFF, 0x80, 0x80, 0x80, 0xFF, 0x08, 0x08, 0x08}, // 12
    {0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // 13
    {0x80, 0x40, 0x20, 0x00, 0x02, 0x04, 0x08, 0x00}, // 14
    {0x82, 0x44, 0x39, 0x44, 0x82, 0x01, 0x01, 0x01}, // 15
    {0xF8, 0x74, 0x22, 0x47, 0x8F, 0x14, 0x22, 0x71}, // 16
    {0x55, 0xA0, 0x40, 0x40, 0x55, 0x0A, 0x04, 0x04}, // 17
    {0x20, 0x50, 0x88, 0x88, 0x88, 0x88, 0x05, 0x02}, // 18
    {0xBF, 0x00, 0xBF, 0xBF, 0xB0, 0xB0, 0xB0, 0xB0}, // 19
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // 20
    {0x80, 0x00, 0x08, 0x00, 0x80, 0x00, 0x08, 0x00}, // 21
    {0x88, 0x00, 0x22, 0x00, 0x88, 0x00, 0x22, 0x00}, // 22
    {0x88, 0x22, 0x88, 0x22, 0x88, 0x22, 0x88, 0x22}, // 23
    {0xAA, 0x00, 0xAA, 0x00, 0xAA, 0x00, 0xAA, 0x00}, // 24
    {0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00}, // 25
    {0x11, 0x22, 0x44, 0x88, 0x11, 0x22, 0x44, 0x88}, // 26
    {0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00}, // 27
    {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80}, // 28
    {0xAA, 0x00, 0x80, 0x00, 0x88, 0x00, 0x80, 0x00}, // 29
    {0xFF, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80}, // 30
    {0x08, 0x1C, 0x22, 0xC1, 0x80, 0x01, 0x02, 0x04}, // 31
    {0x88, 0x14, 0x22, 0x41, 0x88, 0x00, 0xAA, 0x00}, // 32
    {0x40, 0xA0, 0x00, 0x00, 0x04, 0x0A, 0x00, 0x00}, // 33
    {0x03, 0x84, 0x48, 0x30, 0x0C, 0x02, 0x01, 0x01}, // 34
    {0x80, 0x80, 0x41, 0x3E, 0x08, 0x08, 0x14, 0xE3}, // 35
    {0x10, 0x20, 0x54, 0xAA, 0xFF, 0x02, 0x04, 0x08}, // 36
    {0x77, 0x89, 0x8F, 0x8F, 0x77, 0x98, 0xF8, 0xF8}, // 37
    {0x00, 0x08, 0x14, 0x2A, 0x55, 0x2A, 0x14, 0x08}  // 38
};



Pattern black;
Pattern dkGrey;
Pattern gray;
Pattern ltGray;
Pattern white;


const char OP_NOP             = 0x00;
const char OP_ClipRgn         = 0x01;
const char OP_BkPat           = 0x02;
const char OP_TxFont          = 0x03;
const char OP_TxFace          = 0x04;
const char OP_TxMode          = 0x05;
const char OP_SpExtra         = 0x06;
const char OP_PnSize          = 0x07;
const char OP_PnMode          = 0x08;
const char OP_PnPat           = 0x09;
const char OP_FillPat         = 0x0A;
const char OP_OvSize          = 0x0B;
const char OP_Origin          = 0x0C;
const char OP_TxSize          = 0x0D;
const char OP_FgColor         = 0x0E;
const char OP_BkColor         = 0x0F;
const char OP_TxRatio         = 0x10;
const char OP_picVersion      = 0x11;
const char OP_Line            = 0x20;
const char OP_LineFrom        = 0x21;
const char OP_ShortLine       = 0x22;
const char OP_ShortLineFrom   = 0x23;
const char OP_LongText        = 0x28;
const char OP_DHText          = 0x29;
const char OP_DVText          = 0x2A;
const char OP_DHDVText        = 0x2B;
const char OP_frameRect       = 0x30;
const char OP_paintRect       = 0x31;
const char OP_eraseRect       = 0x32;
const char OP_invertRect      = 0x33;
const char OP_fillRect        = 0x34;
const char OP_frameSameRect   = 0x38;
const char OP_paintSameRect   = 0x39;
const char OP_eraseSameRect   = 0x3A;
const char OP_invertSameRect  = 0x3B;
const char OP_fillSameRect    = 0x3C;
const char OP_frameRRect      = 0x40;
const char OP_paintRRect      = 0x41;
const char OP_eraseRRect      = 0x42;
const char OP_invertRRect     = 0x43;
const char OP_fillRRect       = 0x44;
const char OP_frameSameRRect  = 0x48;
const char OP_paintSameRRect  = 0x49;
const char OP_eraseSameRRect  = 0x4A;
const char OP_invertSameRRect = 0x4B;
const char OP_fillSameRRect   = 0x4C;
const char OP_frameOval       = 0x50;
const char OP_paintOval       = 0x51;
const char OP_eraseOval       = 0x52;
const char OP_invertOval      = 0x53;
const char OP_fillOval        = 0x54;
const char OP_frameSameOval   = 0x58;
const char OP_paintSameOval   = 0x59;
const char OP_eraseSameOval   = 0x5A;
const char OP_invertSameOval  = 0x5B;
const char OP_fillSameOval    = 0x5C;
const char OP_frameArc        = 0x60;
const char OP_paintArc        = 0x61;
const char OP_eraseArc        = 0x62;
const char OP_invertArc       = 0x63;
const char OP_fillArc         = 0x64;
const char OP_frameSameArc    = 0x68;
const char OP_paintSameArc    = 0x69;
const char OP_eraseSameArc    = 0x6A;
const char OP_invertSameArc   = 0x6B;
const char OP_fillSameArc     = 0x6C;
const char OP_framePoly       = 0x70;
const char OP_paintPoly       = 0x71;
const char OP_erasePoly       = 0x72;
const char OP_invertPoly      = 0x73;
const char OP_fillPoly        = 0x74;
const char OP_frameSamePoly   = 0x78;
const char OP_paintSamePoly   = 0x79;
const char OP_eraseSamePoly   = 0x7A;
const char OP_invertSamePoly  = 0x7B;
const char OP_fillSamePoly    = 0x7C;
const char OP_frameRgn        = 0x80;
const char OP_paintRgn        = 0x81;
const char OP_eraseRgn        = 0x82;
const char OP_invertRgn       = 0x83;
const char OP_fillRgn         = 0x84;
const char OP_frameSameRgn    = 0x88;
const char OP_paintSameRgn    = 0x89;
const char OP_eraseSameRgn    = 0x8A;
const char OP_invertSameRgn   = 0x8B;
const char OP_fillSameRgn     = 0x8C;
const char OP_BitsRect        = 0x90;
const char OP_BitsRgn         = 0x91;
const char OP_PackBitsRect    = 0x98;
const char OP_PackBitsRgn     = 0x99;
const char OP_ShortComment    = 0xA0;
const char OP_LongComment     = 0xA1;
const char OP_EndOfPicture    = 0xFF;






#endif // QUICKDRAW_H_