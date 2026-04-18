/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: --bpp 1 --size 18 --no-compress --font IBMPlexSansThaiLooped-SemiBold.ttf --range 2-127,3584-3711 --format lvgl -o IBMTH_18.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include <lvgl.h> 
#endif

#ifndef IBMTH_18_EN
#define IBMTH_18_EN 1
#endif

#if IBMTH_18_EN

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+000D "\r" */
    0x0,

    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0x8f, 0xc0,

    /* U+0022 "\"" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x30,

    /* U+0023 "#" */
    0x8, 0x83, 0x10, 0x66, 0x3f, 0xf7, 0xfe, 0x23,
    0x4, 0x41, 0x88, 0xff, 0xdf, 0xf8, 0xcc, 0x11,
    0x82, 0x20,

    /* U+0024 "$" */
    0x18, 0xc, 0x1f, 0xdf, 0xfd, 0x96, 0xc3, 0xe0,
    0xfc, 0x3f, 0xd, 0xc6, 0x73, 0x3f, 0xf3, 0xf0,
    0x60, 0x30,

    /* U+0025 "%" */
    0x78, 0x11, 0x98, 0x63, 0x31, 0x86, 0x62, 0xc,
    0xcc, 0x1f, 0xb7, 0x9e, 0x5f, 0x1, 0xb3, 0x6,
    0x66, 0x8, 0xcc, 0x31, 0x98, 0xc3, 0x31, 0x3,
    0xc0,

    /* U+0026 "&" */
    0x1e, 0xf, 0xe1, 0x8c, 0x31, 0x87, 0x70, 0x7c,
    0xf, 0x3b, 0x77, 0xc6, 0xd8, 0x73, 0x8e, 0x3f,
    0xe3, 0xee,

    /* U+0027 "'" */
    0xff, 0xf0,

    /* U+0028 "(" */
    0x19, 0x98, 0xc4, 0x63, 0x18, 0xc6, 0x31, 0x84,
    0x31, 0x86, 0x18,

    /* U+0029 ")" */
    0xc3, 0xc, 0x61, 0xc, 0x63, 0x18, 0xc6, 0x31,
    0x18, 0xcc, 0xc0,

    /* U+002A "*" */
    0x18, 0x18, 0x99, 0xff, 0x7e, 0x3c, 0x7e, 0x66,
    0x0,

    /* U+002B "+" */
    0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18,
    0x18,

    /* U+002C "," */
    0x77, 0x32, 0x60,

    /* U+002D "-" */
    0xff, 0xc0,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0x6, 0xc, 0x30, 0x60, 0xc1, 0x6, 0xc, 0x18,
    0x60, 0xc1, 0x86, 0xc, 0x18, 0x60, 0xc0,

    /* U+0030 "0" */
    0x3e, 0x3f, 0x98, 0xd8, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xd8, 0xcf, 0xe3, 0xe0,

    /* U+0031 "1" */
    0x1e, 0xf, 0x87, 0x61, 0x98, 0x46, 0x1, 0x80,
    0x60, 0x18, 0x6, 0x1, 0x80, 0x61, 0xff, 0x7f,
    0xc0,

    /* U+0032 "2" */
    0x3c, 0x3f, 0x39, 0xc8, 0x60, 0x30, 0x18, 0x18,
    0x18, 0x18, 0x38, 0x38, 0x1f, 0xff, 0xf8,

    /* U+0033 "3" */
    0x1e, 0x3f, 0xd8, 0x60, 0x30, 0x18, 0xf8, 0x7c,
    0x7, 0x1, 0x80, 0xd8, 0xef, 0xe3, 0xe0,

    /* U+0034 "4" */
    0x7, 0x1, 0xc0, 0xf0, 0x6c, 0x1b, 0xc, 0xc3,
    0x31, 0x8c, 0x63, 0x3f, 0xff, 0xfc, 0xc, 0x3,
    0x0,

    /* U+0035 "5" */
    0x7f, 0x3f, 0x98, 0xc, 0x6, 0xe3, 0xf9, 0x8e,
    0x3, 0x1, 0x80, 0xf8, 0xef, 0xe3, 0xe0,

    /* U+0036 "6" */
    0xe, 0xe, 0xc, 0xc, 0x7, 0xe7, 0xfb, 0x8f,
    0x83, 0xc1, 0xe0, 0xf8, 0xef, 0xe3, 0xe0,

    /* U+0037 "7" */
    0xff, 0xff, 0xf0, 0xd8, 0x60, 0x70, 0x30, 0x38,
    0x18, 0xc, 0xe, 0x6, 0x3, 0x3, 0x80,

    /* U+0038 "8" */
    0x3e, 0x3f, 0xb8, 0xf8, 0x3e, 0x3b, 0xf9, 0xfd,
    0xc7, 0xc1, 0xe0, 0xf8, 0xef, 0xe3, 0xe0,

    /* U+0039 "9" */
    0x3e, 0x3f, 0xb8, 0xf8, 0x3c, 0x1f, 0x1d, 0xfe,
    0x7f, 0x3, 0x3, 0x83, 0x83, 0x83, 0x80,

    /* U+003A ":" */
    0xff, 0x80, 0x7, 0xfc,

    /* U+003B ";" */
    0x77, 0x70, 0x0, 0x7, 0x73, 0x26,

    /* U+003C "<" */
    0x2, 0xc, 0x79, 0xcf, 0x18, 0x3c, 0x1c, 0x1e,
    0xc, 0x8,

    /* U+003D "=" */
    0xff, 0xff, 0x0, 0x0, 0xff, 0xff,

    /* U+003E ">" */
    0x81, 0x83, 0xc1, 0xc1, 0xe0, 0xc7, 0x9c, 0xf1,
    0x82, 0x0,

    /* U+003F "?" */
    0x79, 0xfb, 0x1a, 0x30, 0x61, 0xcf, 0x18, 0x30,
    0x0, 0xe1, 0xc3, 0x80,

    /* U+0040 "@" */
    0xf, 0xc0, 0x7f, 0xc3, 0x87, 0x9b, 0xb6, 0xef,
    0xdf, 0x63, 0x3d, 0x8c, 0xf6, 0x33, 0xd8, 0xcf,
    0x63, 0x3e, 0xff, 0x9b, 0x9c, 0x78, 0x0, 0xff,
    0x80, 0xfe, 0x0,

    /* U+0041 "A" */
    0xf, 0x0, 0xf0, 0xf, 0x1, 0xf8, 0x19, 0x81,
    0x98, 0x39, 0xc3, 0x8c, 0x3f, 0xc7, 0xfe, 0x70,
    0xe6, 0x6, 0x60, 0x70,

    /* U+0042 "B" */
    0xff, 0x7f, 0xf0, 0x78, 0x3c, 0x1f, 0xfb, 0xfd,
    0x83, 0xc1, 0xe0, 0xf0, 0x7f, 0xef, 0xe0,

    /* U+0043 "C" */
    0x1e, 0xf, 0xe6, 0x1b, 0x4, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x30, 0x66, 0x39, 0xfe, 0x1e,
    0x0,

    /* U+0044 "D" */
    0xfe, 0x3f, 0xcc, 0x1b, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x3c, 0x1b, 0xfc, 0xfe,
    0x0,

    /* U+0045 "E" */
    0xff, 0xff, 0xf0, 0x18, 0xc, 0x7, 0xfb, 0xfd,
    0x80, 0xc0, 0x60, 0x30, 0x1f, 0xff, 0xf8,

    /* U+0046 "F" */
    0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xff, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0047 "G" */
    0x1f, 0xf, 0xe6, 0x1f, 0x2, 0xc0, 0x30, 0xc,
    0x7f, 0x1f, 0xc0, 0xf0, 0x36, 0x1c, 0xff, 0x1e,
    0xc0,

    /* U+0048 "H" */
    0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xff, 0xff,
    0xff, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xc0,

    /* U+0049 "I" */
    0xff, 0xf3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0x3f, 0xfc,

    /* U+004A "J" */
    0x3f, 0x3f, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3,
    0x3, 0x63, 0x63, 0x7e, 0x3c,

    /* U+004B "K" */
    0xc1, 0xb0, 0xec, 0x73, 0x38, 0xdc, 0x36, 0xf,
    0xc3, 0xb8, 0xe6, 0x31, 0xcc, 0x3b, 0xe, 0xc1,
    0xc0,

    /* U+004C "L" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0, 0xff, 0xff,

    /* U+004D "M" */
    0xe0, 0x7e, 0x7, 0xf0, 0xff, 0xf, 0xf9, 0xbd,
    0xdb, 0xcf, 0x3c, 0xf3, 0xc6, 0x3c, 0x63, 0xc0,
    0x3c, 0x3, 0xc0, 0x30,

    /* U+004E "N" */
    0xe0, 0xf8, 0x3f, 0xf, 0xe3, 0xf8, 0xf7, 0x3c,
    0xcf, 0x3b, 0xc7, 0xf1, 0xfc, 0x3f, 0x7, 0xc1,
    0xc0,

    /* U+004F "O" */
    0x1f, 0x7, 0xf1, 0x87, 0x60, 0x7c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0x1d, 0xc3, 0x1f,
    0xc1, 0xf0,

    /* U+0050 "P" */
    0xfe, 0x7f, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0xfd,
    0xfc, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x0,

    /* U+0051 "Q" */
    0x1f, 0x7, 0xf1, 0xc7, 0x30, 0x6c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xd, 0x83, 0x3d,
    0xe3, 0xf8, 0x1e, 0x1, 0x80, 0x3c, 0x3, 0x80,

    /* U+0052 "R" */
    0xfe, 0x7f, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0xfd,
    0xfe, 0xc6, 0x63, 0xb0, 0xd8, 0x7c, 0x18,

    /* U+0053 "S" */
    0x3e, 0x3f, 0xf0, 0xd8, 0xc, 0x7, 0xe1, 0xfc,
    0x1f, 0x1, 0x80, 0xf0, 0xff, 0xe3, 0xe0,

    /* U+0054 "T" */
    0xff, 0xff, 0xf0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x0,

    /* U+0055 "U" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf8, 0xef, 0xe3, 0xe0,

    /* U+0056 "V" */
    0xe0, 0x6c, 0x1d, 0x83, 0x38, 0x63, 0x1c, 0x63,
    0xe, 0x60, 0xcc, 0x1b, 0x83, 0x60, 0x3c, 0x7,
    0x80, 0xe0,

    /* U+0057 "W" */
    0x61, 0xc3, 0x30, 0xe1, 0x98, 0x70, 0xce, 0x6c,
    0x67, 0x36, 0x71, 0x9b, 0x30, 0xcd, 0x98, 0x64,
    0x6c, 0x3e, 0x36, 0xf, 0x1e, 0x7, 0x8f, 0x3,
    0x83, 0x81, 0xc1, 0xc0,

    /* U+0058 "X" */
    0x70, 0xee, 0x18, 0xe7, 0xc, 0xc1, 0xf8, 0x1e,
    0x3, 0x80, 0x78, 0x1b, 0x87, 0x30, 0xc7, 0x38,
    0x76, 0xe,

    /* U+0059 "Y" */
    0xe1, 0xd8, 0x77, 0x18, 0xcc, 0x3b, 0x7, 0x81,
    0xe0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x0,

    /* U+005A "Z" */
    0xff, 0xff, 0xc0, 0xe0, 0xe0, 0xe0, 0x60, 0x70,
    0x70, 0x30, 0x38, 0x38, 0x1f, 0xff, 0xf8,

    /* U+005B "[" */
    0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcf,
    0xf0,

    /* U+005C "\\" */
    0xc1, 0x83, 0x3, 0x6, 0xc, 0xc, 0x18, 0x30,
    0x30, 0x60, 0xc0, 0xc1, 0x83, 0x2, 0x6,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3f,
    0xf0,

    /* U+005E "^" */
    0x1c, 0xe, 0xf, 0x86, 0xc6, 0x77, 0x1b, 0xe,
    0x82,

    /* U+005F "_" */
    0xff, 0xff, 0xc0,

    /* U+0060 "`" */
    0x4e, 0x62,

    /* U+0061 "a" */
    0x3c, 0x3f, 0x10, 0xc0, 0x63, 0xf7, 0xfb, 0xd,
    0x86, 0xff, 0xbc, 0xc0,

    /* U+0062 "b" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xdc, 0xfe, 0xc7, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc7, 0xfe, 0xdc,

    /* U+0063 "c" */
    0x3c, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7,
    0x7e, 0x3c,

    /* U+0064 "d" */
    0x3, 0x3, 0x3, 0x3, 0x3b, 0x7f, 0xe7, 0xc3,
    0xc3, 0xc3, 0xc3, 0xe3, 0x7f, 0x3b,

    /* U+0065 "e" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xff, 0xff, 0xc0, 0xe2,
    0x7e, 0x3c,

    /* U+0066 "f" */
    0x1c, 0xf3, 0xc, 0xff, 0xf3, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0xc0,

    /* U+0067 "g" */
    0x3, 0x81, 0xcf, 0x8f, 0xec, 0x36, 0x1b, 0xc,
    0xfc, 0x3c, 0x60, 0x3f, 0xc7, 0xfc, 0x1e, 0xf,
    0xfe, 0xfc,

    /* U+0068 "h" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xde, 0xff, 0xe3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,

    /* U+0069 "i" */
    0xfc, 0xff, 0xff, 0xf0,

    /* U+006A "j" */
    0x33, 0x30, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0xfe,

    /* U+006B "k" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc7, 0xce, 0xdc, 0xd8,
    0xf8, 0xfc, 0xcc, 0xce, 0xc7, 0xc7,

    /* U+006C "l" */
    0xdb, 0x6d, 0xb6, 0xdb, 0x6e, 0xc0,

    /* U+006D "m" */
    0xde, 0x7b, 0xff, 0xfe, 0x79, 0xf0, 0xc3, 0xc3,
    0xf, 0xc, 0x3c, 0x30, 0xf0, 0xc3, 0xc3, 0xf,
    0xc, 0x30,

    /* U+006E "n" */
    0xde, 0xff, 0xe3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3,

    /* U+006F "o" */
    0x3e, 0x3f, 0xb8, 0xd8, 0x3c, 0x1e, 0xf, 0x7,
    0xc6, 0x7f, 0x1f, 0x0,

    /* U+0070 "p" */
    0xdc, 0xfe, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7,
    0xfe, 0xdc, 0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0071 "q" */
    0x3b, 0x7f, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xe3,
    0x7f, 0x3b, 0x3, 0x3, 0x3, 0x3,

    /* U+0072 "r" */
    0xdf, 0xfe, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0x0,

    /* U+0073 "s" */
    0x7d, 0xff, 0x16, 0xf, 0x87, 0xc1, 0xe3, 0xfe,
    0xf0,

    /* U+0074 "t" */
    0x30, 0xc3, 0x3f, 0xfc, 0xc3, 0xc, 0x30, 0xc3,
    0xf, 0x1c,

    /* U+0075 "u" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7,
    0xff, 0x7b,

    /* U+0076 "v" */
    0xe1, 0xb0, 0xd8, 0xce, 0x63, 0x31, 0xb8, 0xd8,
    0x3c, 0x1e, 0xe, 0x0,

    /* U+0077 "w" */
    0x63, 0x8d, 0x8e, 0x36, 0x38, 0xd9, 0xa6, 0x36,
    0xd8, 0xdb, 0x63, 0x4d, 0x8f, 0x14, 0x1c, 0x70,
    0x71, 0xc0,

    /* U+0078 "x" */
    0x61, 0xb9, 0x8e, 0xc3, 0xc1, 0xe0, 0xf0, 0x78,
    0x6e, 0x73, 0xb0, 0xc0,

    /* U+0079 "y" */
    0xc1, 0xf1, 0x98, 0xcc, 0x66, 0x63, 0xb0, 0xd8,
    0x78, 0x3c, 0xe, 0x7, 0x3, 0x7, 0x83, 0x80,

    /* U+007A "z" */
    0xff, 0xff, 0x7, 0xe, 0x1c, 0x38, 0x70, 0xe0,
    0xff, 0xff,

    /* U+007B "{" */
    0x3c, 0xf3, 0xc, 0x30, 0xc3, 0xc, 0xe3, 0x83,
    0xc, 0x30, 0xc3, 0xf, 0x3c,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xf3, 0xc3, 0xc, 0x30, 0xc3, 0xe, 0x1c, 0x73,
    0xc, 0x30, 0xc3, 0x3c, 0xf0,

    /* U+007E "~" */
    0xf8, 0x7f, 0x83, 0xc0,

    /* U+0E01 "ก" */
    0x1f, 0x1c, 0x66, 0xf, 0xc3, 0x30, 0xcc, 0x33,
    0xc, 0xc3, 0x30, 0xcc, 0x30,

    /* U+0E02 "ข" */
    0x78, 0xff, 0x39, 0xcd, 0xf3, 0x1c, 0xce, 0x33,
    0xc, 0xc3, 0x31, 0x87, 0xc0,

    /* U+0E03 "ฃ" */
    0x66, 0xf5, 0xbd, 0xed, 0xf3, 0x18, 0xcc, 0x33,
    0xc, 0xc3, 0x19, 0x83, 0xc0,

    /* U+0E04 "ค" */
    0x3f, 0x18, 0x6c, 0xf, 0x3, 0xdc, 0xfe, 0xbf,
    0xaf, 0x33, 0xc0, 0xf0, 0x30,

    /* U+0E05 "ฅ" */
    0x73, 0xbf, 0xfc, 0xcf, 0x3, 0xdc, 0xfe, 0xbf,
    0xaf, 0x33, 0xc0, 0xf0, 0x30,

    /* U+0E06 "ฆ" */
    0x6c, 0xf7, 0x3d, 0xcd, 0xa3, 0x18, 0xcc, 0x37,
    0xf, 0x33, 0xcf, 0xdc, 0x70,

    /* U+0E07 "ง" */
    0x6, 0xd, 0xd, 0x67, 0x63, 0x73, 0x33, 0x3b,
    0x1b, 0x1f,

    /* U+0E08 "จ" */
    0x7e, 0x71, 0x90, 0x66, 0x36, 0x9b, 0x4c, 0xe6,
    0x33, 0x19, 0x87, 0x80,

    /* U+0E09 "ฉ" */
    0x3f, 0xe, 0x31, 0x3, 0x0, 0x67, 0xd, 0xb1,
    0xb6, 0x3b, 0xd9, 0x3f, 0x27, 0x98,

    /* U+0E0A "ช" */
    0x78, 0xff, 0x39, 0xf9, 0xf3, 0x1c, 0xce, 0x33,
    0xc, 0xc3, 0x31, 0x87, 0xc0,

    /* U+0E0B "ซ" */
    0x66, 0xf5, 0xbd, 0xf9, 0xf3, 0x18, 0xcc, 0x33,
    0xc, 0xc3, 0x19, 0x83, 0xc0,

    /* U+0E0C "ฌ" */
    0x3e, 0xd, 0x8c, 0x3c, 0x18, 0xf8, 0x63, 0x61,
    0x8d, 0x86, 0x37, 0xb8, 0xdb, 0x9b, 0x6e, 0x7c,
    0xe6, 0x70,

    /* U+0E0D "ญ" */
    0x1f, 0x6, 0xe3, 0xd, 0x83, 0x1f, 0x86, 0x33,
    0xc, 0x66, 0x18, 0xcf, 0x31, 0x93, 0x63, 0x26,
    0xc6, 0x38, 0x78, 0x0, 0x0, 0x3, 0x0, 0x9,
    0x60, 0x12, 0xc0, 0x1f, 0x0,

    /* U+0E0E "ฎ" */
    0x1f, 0xc, 0x66, 0xd, 0xc3, 0x30, 0xcc, 0x37,
    0xf, 0x43, 0xd0, 0xd8, 0x30, 0xc, 0xfb, 0x2e,
    0xcb, 0xf3, 0x9c,

    /* U+0E0F "ฏ" */
    0x1f, 0x1c, 0x66, 0xd, 0xc3, 0x30, 0xcc, 0x37,
    0xf, 0x43, 0xd0, 0xd8, 0x30, 0xd, 0xd3, 0x6c,
    0xdb, 0xf7, 0x5c,

    /* U+0E10 "ฐ" */
    0x1, 0x80, 0xdf, 0xfc, 0x74, 0x19, 0x8d, 0xa6,
    0xd3, 0x39, 0x8c, 0xc6, 0x61, 0xe0, 0x7, 0xdf,
    0x4f, 0xbd, 0xeb, 0x80,

    /* U+0E11 "ฑ" */
    0x66, 0xfa, 0xff, 0x7d, 0xbb, 0x30, 0xc6, 0x30,
    0xc6, 0x18, 0xc3, 0x18, 0x63, 0xc,

    /* U+0E12 "ฒ" */
    0x73, 0x87, 0xff, 0x8f, 0x3, 0x1e, 0x66, 0x3d,
    0x2c, 0x7a, 0x58, 0xf7, 0xf1, 0xe7, 0x9b, 0xdb,
    0x3f, 0xe3, 0x9c,

    /* U+0E13 "ณ" */
    0x1f, 0x6, 0x38, 0xc3, 0x18, 0x31, 0x9e, 0x18,
    0xc3, 0xc, 0x61, 0x86, 0x30, 0xf3, 0x1c, 0x4d,
    0xb3, 0x26, 0xf9, 0x8e, 0x73, 0x80,

    /* U+0E14 "ด" */
    0x3f, 0x18, 0x6c, 0xf, 0x3, 0xcc, 0xf4, 0xbd,
    0x6f, 0x33, 0xd8, 0xfc, 0x30,

    /* U+0E15 "ต" */
    0x73, 0xbf, 0xfc, 0xcf, 0x3, 0xcc, 0xf4, 0xbd,
    0x2f, 0x33, 0xd8, 0xfc, 0x30,

    /* U+0E16 "ถ" */
    0x1f, 0x1c, 0x66, 0xf, 0xc3, 0x30, 0xcc, 0x33,
    0xcc, 0x9b, 0x26, 0xc7, 0x30,

    /* U+0E17 "ท" */
    0x63, 0xde, 0x8f, 0xe1, 0xb8, 0x33, 0x6, 0x60,
    0xcc, 0x19, 0x83, 0x30, 0x66, 0xc,

    /* U+0E18 "ธ" */
    0x3f, 0x30, 0xf0, 0x1f, 0xe7, 0xf8, 0xf, 0x7,
    0x83, 0xc1, 0xbf, 0x0,

    /* U+0E19 "น" */
    0x60, 0xcd, 0xc, 0xd0, 0xc7, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0xe3, 0x33, 0x3f, 0x33, 0x8e,

    /* U+0E1A "บ" */
    0x60, 0xf4, 0x3d, 0xd, 0xc3, 0x30, 0xcc, 0x33,
    0xc, 0xc3, 0x30, 0xdf, 0xe0,

    /* U+0E1B "ป" */
    0x0, 0xc0, 0x30, 0xd, 0x83, 0xd0, 0xf4, 0x37,
    0xc, 0xc3, 0x30, 0xcc, 0x33, 0xc, 0xc3, 0x7f,
    0x80,

    /* U+0E1C "ผ" */
    0x70, 0xe6, 0x39, 0x8f, 0xc3, 0xc0, 0xf3, 0x3c,
    0xcf, 0x33, 0xcc, 0xde, 0xe0,

    /* U+0E1D "ฝ" */
    0x0, 0xc0, 0x30, 0xd, 0xc3, 0x98, 0xe6, 0x3f,
    0xf, 0x3, 0xcc, 0xf3, 0x3c, 0xcf, 0x33, 0x7b,
    0x80,

    /* U+0E1E "พ" */
    0x63, 0x3d, 0x33, 0xd3, 0x37, 0x7b, 0x34, 0xb3,
    0x4b, 0x34, 0xf3, 0xcf, 0x38, 0x73, 0x87,

    /* U+0E1F "ฟ" */
    0x0, 0x30, 0x3, 0x0, 0x36, 0x33, 0xd3, 0x3d,
    0x33, 0x77, 0xb3, 0x4b, 0x34, 0xb3, 0x4f, 0x3c,
    0xf3, 0x87, 0x38, 0x70,

    /* U+0E20 "ภ" */
    0x1f, 0xc, 0x66, 0xd, 0xc3, 0x30, 0xcc, 0x37,
    0xf, 0x43, 0xd0, 0xd8, 0x30,

    /* U+0E21 "ม" */
    0x60, 0xf4, 0x3d, 0xd, 0xc3, 0x30, 0xcc, 0x37,
    0xf, 0x33, 0xcf, 0xdc, 0x70,

    /* U+0E22 "ย" */
    0x73, 0xd3, 0xf3, 0xc3, 0x73, 0x43, 0xc3, 0xc3,
    0xc2, 0x7c,

    /* U+0E23 "ร" */
    0x3f, 0x31, 0xb0, 0x58, 0xf, 0xe0, 0x18, 0x3c,
    0x36, 0x1b, 0x7, 0x0,

    /* U+0E24 "ฤ" */
    0x1f, 0x1c, 0x66, 0xf, 0xc3, 0x30, 0xcc, 0x33,
    0xcc, 0x9b, 0x26, 0xc7, 0x30, 0xc, 0x3, 0x0,
    0xc0,

    /* U+0E25 "ล" */
    0x7e, 0x71, 0xa0, 0x60, 0x37, 0xfe, 0xf, 0xc7,
    0x93, 0xc9, 0xb8, 0xc0,

    /* U+0E26 "ฦ" */
    0x1f, 0xc, 0x66, 0xd, 0xc3, 0x30, 0xcc, 0x37,
    0xf, 0x43, 0xd0, 0xd8, 0x30, 0xc, 0x3, 0x0,
    0xc0,

    /* U+0E27 "ว" */
    0x7d, 0x8c, 0x18, 0x30, 0x60, 0xc3, 0x8d, 0x1a,
    0x18,

    /* U+0E28 "ศ" */
    0x0, 0xcf, 0xf6, 0x1f, 0x3, 0xc0, 0xf7, 0x3f,
    0xaf, 0xeb, 0xcc, 0xf0, 0x3c, 0xc,

    /* U+0E29 "ษ" */
    0x60, 0x6d, 0x6, 0xd0, 0x67, 0x76, 0x35, 0x63,
    0x7f, 0x30, 0x63, 0x6, 0x30, 0xe7, 0xfc,

    /* U+0E2A "ส" */
    0x1, 0xbf, 0xf8, 0xf0, 0x30, 0x1b, 0xff, 0x7,
    0xe3, 0xc9, 0xe4, 0xdc, 0x60,

    /* U+0E2B "ห" */
    0x60, 0xef, 0x1b, 0xf1, 0xb7, 0x1e, 0x3f, 0xc3,
    0xcc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc,

    /* U+0E2C "ฬ" */
    0x0, 0x30, 0x3, 0x1, 0xe6, 0x3, 0xd0, 0x3d,
    0x3, 0x73, 0x33, 0x33, 0x37, 0xb3, 0x4b, 0x3c,
    0xf3, 0x87, 0x38, 0x70,

    /* U+0E2D "อ" */
    0x7e, 0x71, 0x90, 0x67, 0x36, 0xdb, 0x6d, 0xe6,
    0xc3, 0x71, 0x9f, 0x80,

    /* U+0E2E "ฮ" */
    0x1, 0xbf, 0xf8, 0xe8, 0x33, 0x9b, 0x6d, 0xb6,
    0xf3, 0x61, 0xb8, 0xcf, 0xc0,

    /* U+0E2F "ฯ" */
    0x73, 0xdb, 0xdb, 0xf7, 0x7b, 0x3, 0x3, 0x3,
    0x3, 0x3,

    /* U+0E30 "ะ" */
    0x63, 0xd3, 0xd3, 0xd6, 0x7c, 0x0, 0x63, 0xd3,
    0xd7, 0x7c,

    /* U+0E31 "ั" */
    0x63, 0xd3, 0xd7, 0x7c,

    /* U+0E32 "า" */
    0x7d, 0x8c, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x6,
    0xc,

    /* U+0E33 "ำ" */
    0x70, 0x6, 0xc0, 0x36, 0x0, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x7, 0xc0, 0x63, 0x0, 0x18, 0x0,
    0xc0, 0x6, 0x0, 0x30, 0x1, 0x80, 0xc, 0x0,
    0x60, 0x3,

    /* U+0E34 "ิ" */
    0x3e, 0x31, 0xb0, 0x7f, 0xf0,

    /* U+0E35 "ี" */
    0x1, 0x9e, 0xd8, 0xf8, 0x3f, 0xf8,

    /* U+0E36 "ึ" */
    0x3e, 0xe6, 0x1b, 0x41, 0xef, 0xf8,

    /* U+0E37 "ื" */
    0xd, 0xb9, 0xf0, 0x7f, 0xf0,

    /* U+0E38 "ุ" */
    0xfb, 0xf3, 0x30,

    /* U+0E39 "ู" */
    0xe7, 0x6f, 0xd9, 0xb3, 0xc0,

    /* U+0E3A "ฺ" */
    0xe0,

    /* U+0E3F "฿" */
    0x18, 0xc, 0x6, 0x1f, 0xed, 0x9e, 0xcf, 0x67,
    0xb3, 0xfe, 0x6c, 0xf6, 0x7b, 0x3d, 0x9f, 0xf8,
    0x60, 0x30,

    /* U+0E40 "เ" */
    0xc6, 0x31, 0x8c, 0x63, 0xd3, 0x9b, 0x80,

    /* U+0E41 "แ" */
    0xc3, 0x30, 0xcc, 0x33, 0xc, 0xc3, 0x30, 0xcf,
    0x3a, 0x73, 0x9c, 0xdc, 0xe0,

    /* U+0E42 "โ" */
    0x3e, 0x66, 0xc0, 0xf0, 0x38, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x1c, 0x26, 0x26, 0x1c,

    /* U+0E43 "ใ" */
    0x7d, 0x8d, 0x18, 0x30, 0xc3, 0x6, 0xc, 0x18,
    0x30, 0x60, 0xc1, 0xc4, 0xc9, 0x8e,

    /* U+0E44 "ไ" */
    0xcc, 0x3e, 0x1f, 0x5, 0x80, 0xc0, 0x60, 0x30,
    0x18, 0xc, 0x6, 0x3, 0x1, 0x80, 0xf0, 0x4c,
    0x26, 0xe,

    /* U+0E45 "ๅ" */
    0x7d, 0x8c, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x6,
    0xc, 0x18, 0x30, 0x60,

    /* U+0E46 "ๆ" */
    0x77, 0x64, 0xf8, 0x7a, 0x3d, 0x1b, 0xc, 0x6,
    0x3, 0x1, 0x80, 0xc0, 0x60, 0x30, 0x18,

    /* U+0E47 "็" */
    0x3, 0x7f, 0xc3, 0xcb, 0x77,

    /* U+0E48 "่" */
    0xff,

    /* U+0E49 "้" */
    0x60, 0xf3, 0xf6, 0x66, 0xfc,

    /* U+0E4A "๊" */
    0x6e, 0xf5, 0xba, 0x6f, 0x9e,

    /* U+0E4B "๋" */
    0x21, 0x3e, 0x42, 0x0,

    /* U+0E4C "์" */
    0x3, 0x7f, 0xd8, 0xd8, 0x70,

    /* U+0E4D "ํ" */
    0x76, 0xf6, 0xe0,

    /* U+0E4E "๎" */
    0x74, 0x43, 0xce,

    /* U+0E4F "๏" */
    0x1f, 0xc, 0x19, 0x1, 0x67, 0x3d, 0xb7, 0xb6,
    0xf3, 0x9a, 0x2, 0x60, 0xc3, 0xe0,

    /* U+0E50 "๐" */
    0x3e, 0x31, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x6,
    0xc6, 0x3e, 0x0,

    /* U+0E51 "๑" */
    0x3e, 0x18, 0x6c, 0xf, 0x63, 0xe4, 0xf9, 0x37,
    0x8c, 0x6, 0x3, 0x7, 0x0,

    /* U+0E52 "๒" */
    0xc0, 0xc, 0x0, 0xce, 0xed, 0xb3, 0xd9, 0x3d,
    0xe3, 0xda, 0x3c, 0xe3, 0xc0, 0x36, 0x6, 0x3f,
    0xc0,

    /* U+0E53 "๓" */
    0x7b, 0xdc, 0xcf, 0x19, 0xe3, 0x3c, 0x67, 0xe0,
    0xf6, 0x1e, 0xc3, 0x70, 0x60,

    /* U+0E54 "๔" */
    0x1, 0x80, 0xe0, 0x78, 0xfc, 0x70, 0x30, 0xcc,
    0x4b, 0x16, 0xc7, 0x18, 0xc3, 0xfc,

    /* U+0E55 "๕" */
    0x39, 0x99, 0x66, 0x78, 0xf8, 0x70, 0x30, 0xcc,
    0x4b, 0x16, 0xc7, 0x18, 0xc3, 0xfc,

    /* U+0E56 "๖" */
    0xe0, 0x38, 0x6, 0xf1, 0xc6, 0x70, 0xc0, 0x33,
    0x8d, 0xa3, 0x78, 0xdc, 0x61, 0xe0,

    /* U+0E57 "๗" */
    0x0, 0x18, 0x0, 0xdd, 0xc7, 0xdb, 0x3c, 0xd9,
    0xe0, 0xcf, 0x6, 0x7e, 0x33, 0xd9, 0x9e, 0xcc,
    0xdc, 0x7c,

    /* U+0E58 "๘" */
    0x0, 0xc0, 0x38, 0x3f, 0x3f, 0x87, 0x1d, 0x85,
    0xf0, 0xbe, 0xf, 0xcc, 0x79, 0xcd, 0xff, 0x0,

    /* U+0E59 "๙" */
    0x0, 0x30, 0x3, 0x79, 0xbe, 0xe7, 0xc6, 0x7c,
    0x60, 0xc7, 0xf, 0x30, 0xdb, 0xd, 0xb8, 0x71,
    0x80,

    /* U+0E5A "๚" */
    0x71, 0xbd, 0x9b, 0xd9, 0xbf, 0x3b, 0x7d, 0xb0,
    0x1b, 0x1, 0xb0, 0x1b, 0x1, 0xb0, 0x1b,

    /* U+0E5B "๛" */
    0x1e, 0x0, 0x0, 0x31, 0xdc, 0x0, 0x11, 0xee,
    0x66, 0x18, 0xb7, 0xbb, 0xc, 0x73, 0xff, 0xc6,
    0x1, 0x7f, 0xbf, 0x1, 0x9d, 0xc0, 0x80, 0x8c,
    0xc0, 0x61, 0xc6, 0x0, 0xf, 0x80, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 68, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 68, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 89, .box_w = 2, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 6, .adv_w = 136, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 11, .adv_w = 189, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 29, .adv_w = 173, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 47, .adv_w = 276, .box_w = 15, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 205, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 75, .box_w = 2, .box_h = 6, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 92, .adv_w = 97, .box_w = 5, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 103, .adv_w = 97, .box_w = 5, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 114, .adv_w = 160, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 123, .adv_w = 173, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 132, .adv_w = 86, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 135, .adv_w = 116, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 137, .adv_w = 86, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 126, .box_w = 7, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 154, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 173, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 186, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 201, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 216, .adv_w = 173, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 233, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 248, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 263, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 308, .adv_w = 92, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 92, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 318, .adv_w = 173, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 173, .box_w = 8, .box_h = 6, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 334, .adv_w = 173, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 344, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 259, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 383, .adv_w = 194, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 403, .adv_w = 191, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 185, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 435, .adv_w = 198, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 452, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 166, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 480, .adv_w = 205, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 207, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 122, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 157, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 537, .adv_w = 195, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 554, .adv_w = 150, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 567, .adv_w = 235, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 587, .adv_w = 207, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 205, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 622, .adv_w = 185, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 637, .adv_w = 205, .box_w = 11, .box_h = 17, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 661, .adv_w = 191, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 676, .adv_w = 176, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 691, .adv_w = 167, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 708, .adv_w = 199, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 184, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 741, .adv_w = 273, .box_w = 17, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 769, .adv_w = 189, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 787, .adv_w = 182, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 804, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 819, .adv_w = 95, .box_w = 4, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 828, .adv_w = 126, .box_w = 7, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 843, .adv_w = 95, .box_w = 4, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 852, .adv_w = 173, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 861, .adv_w = 161, .box_w = 9, .box_h = 2, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 864, .adv_w = 173, .box_w = 4, .box_h = 4, .ofs_x = 3, .ofs_y = 11},
    {.bitmap_index = 866, .adv_w = 161, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 878, .adv_w = 173, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 892, .adv_w = 148, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 902, .adv_w = 173, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 916, .adv_w = 161, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 926, .adv_w = 101, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 937, .adv_w = 157, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 955, .adv_w = 169, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 969, .adv_w = 79, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 973, .adv_w = 79, .box_w = 4, .box_h = 18, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 982, .adv_w = 162, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 996, .adv_w = 85, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1002, .adv_w = 256, .box_w = 14, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1020, .adv_w = 169, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1030, .adv_w = 162, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1042, .adv_w = 173, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1056, .adv_w = 173, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1070, .adv_w = 113, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1078, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1087, .adv_w = 108, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1097, .adv_w = 169, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1107, .adv_w = 151, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1119, .adv_w = 236, .box_w = 14, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1137, .adv_w = 157, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1149, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1165, .adv_w = 145, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1175, .adv_w = 105, .box_w = 6, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1188, .adv_w = 108, .box_w = 2, .box_h = 17, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1193, .adv_w = 105, .box_w = 6, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1206, .adv_w = 173, .box_w = 9, .box_h = 3, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 1210, .adv_w = 198, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1223, .adv_w = 190, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1236, .adv_w = 196, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1249, .adv_w = 209, .box_w = 10, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1262, .adv_w = 215, .box_w = 10, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1275, .adv_w = 196, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1288, .adv_w = 165, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1298, .adv_w = 183, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1310, .adv_w = 203, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1324, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1337, .adv_w = 199, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1350, .adv_w = 280, .box_w = 14, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1368, .adv_w = 282, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 1397, .adv_w = 204, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1416, .adv_w = 204, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1435, .adv_w = 183, .box_w = 9, .box_h = 17, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1455, .adv_w = 200, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1469, .adv_w = 298, .box_w = 15, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1488, .adv_w = 288, .box_w = 17, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1510, .adv_w = 209, .box_w = 10, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1523, .adv_w = 215, .box_w = 10, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1536, .adv_w = 202, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1549, .adv_w = 207, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1563, .adv_w = 176, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1575, .adv_w = 204, .box_w = 12, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1590, .adv_w = 202, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1603, .adv_w = 202, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1620, .adv_w = 215, .box_w = 10, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1633, .adv_w = 215, .box_w = 10, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1650, .adv_w = 224, .box_w = 12, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1665, .adv_w = 224, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1685, .adv_w = 204, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1698, .adv_w = 197, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1711, .adv_w = 183, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1721, .adv_w = 163, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1733, .adv_w = 202, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1750, .adv_w = 183, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1762, .adv_w = 204, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1779, .adv_w = 151, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1788, .adv_w = 209, .box_w = 10, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1802, .adv_w = 214, .box_w = 12, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1817, .adv_w = 183, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1830, .adv_w = 211, .box_w = 12, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1845, .adv_w = 224, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1865, .adv_w = 186, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1877, .adv_w = 186, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1890, .adv_w = 174, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1900, .adv_w = 159, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1910, .adv_w = 0, .box_w = 8, .box_h = 4, .ofs_x = -9, .ofs_y = 12},
    {.bitmap_index = 1914, .adv_w = 149, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1923, .adv_w = 149, .box_w = 13, .box_h = 16, .ofs_x = -5, .ofs_y = 0},
    {.bitmap_index = 1949, .adv_w = 0, .box_w = 9, .box_h = 4, .ofs_x = -9, .ofs_y = 12},
    {.bitmap_index = 1954, .adv_w = 0, .box_w = 9, .box_h = 5, .ofs_x = -10, .ofs_y = 12},
    {.bitmap_index = 1960, .adv_w = 0, .box_w = 12, .box_h = 4, .ofs_x = -12, .ofs_y = 12},
    {.bitmap_index = 1966, .adv_w = 0, .box_w = 9, .box_h = 4, .ofs_x = -10, .ofs_y = 12},
    {.bitmap_index = 1971, .adv_w = 0, .box_w = 4, .box_h = 5, .ofs_x = -4, .ofs_y = -7},
    {.bitmap_index = 1974, .adv_w = 0, .box_w = 7, .box_h = 5, .ofs_x = -8, .ofs_y = -6},
    {.bitmap_index = 1979, .adv_w = 0, .box_w = 3, .box_h = 1, .ofs_x = -3, .ofs_y = -4},
    {.bitmap_index = 1980, .adv_w = 190, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1998, .adv_w = 104, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2005, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2018, .adv_w = 115, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2034, .adv_w = 114, .box_w = 7, .box_h = 16, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 2048, .adv_w = 115, .box_w = 9, .box_h = 16, .ofs_x = -2, .ofs_y = 0},
    {.bitmap_index = 2066, .adv_w = 149, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2078, .adv_w = 183, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 2093, .adv_w = 0, .box_w = 8, .box_h = 5, .ofs_x = -8, .ofs_y = 12},
    {.bitmap_index = 2098, .adv_w = 0, .box_w = 2, .box_h = 4, .ofs_x = -2, .ofs_y = 12},
    {.bitmap_index = 2099, .adv_w = 0, .box_w = 8, .box_h = 5, .ofs_x = -8, .ofs_y = 12},
    {.bitmap_index = 2104, .adv_w = 0, .box_w = 10, .box_h = 4, .ofs_x = -10, .ofs_y = 11},
    {.bitmap_index = 2109, .adv_w = 0, .box_w = 5, .box_h = 5, .ofs_x = -5, .ofs_y = 12},
    {.bitmap_index = 2113, .adv_w = 0, .box_w = 8, .box_h = 5, .ofs_x = -8, .ofs_y = 11},
    {.bitmap_index = 2118, .adv_w = 0, .box_w = 5, .box_h = 4, .ofs_x = -5, .ofs_y = 12},
    {.bitmap_index = 2121, .adv_w = 0, .box_w = 4, .box_h = 6, .ofs_x = -5, .ofs_y = 12},
    {.bitmap_index = 2124, .adv_w = 203, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2138, .adv_w = 184, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2149, .adv_w = 185, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 2162, .adv_w = 233, .box_w = 12, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2179, .adv_w = 225, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2192, .adv_w = 178, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2206, .adv_w = 178, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2220, .adv_w = 187, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2234, .adv_w = 262, .box_w = 13, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2252, .adv_w = 205, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2268, .adv_w = 212, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2285, .adv_w = 237, .box_w = 12, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2300, .adv_w = 430, .box_w = 25, .box_h = 10, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 13, .range_length = 1, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 2,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 3585, .range_length = 58, .glyph_id_start = 97,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 3647, .range_length = 29, .glyph_id_start = 155,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 1, 2, 3, 0, 4,
    5, 2, 6, 7, 2, 0, 8, 9,
    8, 10, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 11, 11, 0, 0,
    0, 12, 13, 14, 15, 16, 17, 18,
    19, 20, 0, 21, 22, 23, 24, 0,
    0, 25, 26, 25, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 7,
    0, 38, 0, 39, 40, 41, 0, 42,
    43, 44, 45, 46, 47, 48, 49, 45,
    45, 50, 40, 51, 52, 53, 54, 55,
    56, 57, 58, 59, 60, 36, 0, 7,
    0, 61, 62, 62, 61, 0, 63, 63,
    61, 64, 65, 65, 63, 62, 61, 61,
    66, 63, 63, 64, 61, 0, 61, 61,
    67, 64, 62, 68, 0, 68, 63, 68,
    61, 63, 62, 69, 61, 61, 61, 61,
    66, 70, 66, 71, 68, 61, 66, 63,
    72, 0, 61, 61, 0, 0, 0, 0,
    0, 0, 0, 0, 73, 73, 74, 75,
    76, 61, 63, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    77, 77, 0, 78, 79, 80, 63, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 1, 2, 0, 0, 0,
    3, 2, 0, 4, 2, 0, 5, 6,
    5, 7, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 8, 8, 0, 0,
    0, 9, 10, 11, 0, 12, 0, 0,
    0, 12, 0, 13, 14, 0, 0, 0,
    0, 12, 0, 12, 0, 15, 16, 17,
    18, 19, 20, 21, 22, 0, 23, 24,
    0, 25, 0, 26, 27, 28, 29, 28,
    30, 31, 27, 32, 33, 27, 34, 35,
    35, 28, 36, 29, 35, 37, 38, 39,
    40, 41, 42, 43, 44, 0, 0, 24,
    0, 45, 46, 47, 0, 0, 48, 49,
    50, 51, 46, 47, 45, 45, 52, 52,
    50, 53, 0, 45, 0, 0, 45, 54,
    55, 54, 0, 0, 0, 0, 54, 54,
    52, 48, 0, 56, 45, 0, 52, 57,
    0, 0, 0, 54, 54, 58, 58, 0,
    0, 0, 57, 59, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 60, 61,
    62, 63, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 64, 0,
    0, 0, 65, 0, 0, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 14, 9, 23, 0, 0,
    0, 0, 0, 0, 0, -26, 0, 0,
    0, 0, 0, -14, -3, 0, -11, 0,
    4, 0, 3, 4, 0, 2, 0, 0,
    0, 0, 0, 0, -6, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    7, 6, 1, 6, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 17, 10, 22,
    0, 0, 0, 0, -17, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, -1, -12, 0, -9, -5, 0,
    -16, -2, 0, 0, 0, 2, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, -3, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 6, 0, 6, 6,
    3, 6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 3, 0, 18, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 20, 0, 0, 0, 0,
    -26, 0, 0, 0, 0, 0, 0, -23,
    0, 5, -11, 0, 0, 0, -21, -9,
    -17, -11, 3, -19, 9, 0, 0, 0,
    1, 0, -4, -5, -4, 0, 0, 0,
    0, 0, 0, 0, -6, -2, -14, -11,
    0, -13, 3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, 4, -9, -7, -6, -13,
    0, -7, -3, -10, -14, -10, 0, 0,
    0, 0, 0, 3, 3, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, -2,
    -1, -10, -2, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -49,
    0, 0, 0, -13, -6, 0, 0, -5,
    7, 0, 4, 3, 0, 4, 0, 0,
    0, 0, -9, 0, -8, -8, 0, -7,
    0, 0, 0, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -12, 0, -8, 0, -4, -14, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -34,
    0, 0, 0, 0, 0, -8, 0, 0,
    0, 0, 0, 0, 3, 4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -5, 0,
    -5, -8, -3, -10, 0, -9, -6, -11,
    -12, -4, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, -5, -3, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -14, -3,
    0, 5, -5, 0, 0, -11, -5, 3,
    -7, 0, -2, 0, -19, -6, -14, -6,
    1, -19, 0, 0, 0, 4, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, 0, -8, -5, 0, -4,
    3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, 0, -6, 0, 0, 0,
    -4, 0, 0, -3, 0, -7, 0, -7,
    -2, -6, -11, 0, 0, 0, -18, 0,
    0, 0, 0, -1, -1, 0, 0, 0,
    0, 0, 0, -1, 0, -3, -2, -3,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, -3, 0, 0, -4, -4, 0, 0,
    -3, -2, -4, 0, 0, 0, 0, 0,
    0, 0, -4, -3, 0, 0, 0, -11,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, -11, 4, -10, 0,
    0, 0, -9, 0, 0, -7, 0, -7,
    0, -7, -5, -7, -12, -6, 0, 0,
    -7, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, -5, 0,
    0, 0, -1, 0, 0, -2, 0, 0,
    0, 0, 0, 0, -3, -3, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, -11, 4, -27, 0,
    -21, 0, 1, -8, -21, -7, 0, -20,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -39, -12, 0, -9, -9, -2,
    -12, 0, -3, 0, -8, -8, -10, -3,
    -7, -6, -4, -11, -6, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    3, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, -11, 0, -7, -3, -3, -12,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, -9, 0, 0, 0, -5, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, -1,
    -1, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, -1, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -7, 0, -8, 0, 0, 0, -5,
    0, 0, -3, 0, 0, 0, 0, 0,
    -4, 0, 0, 0, 0, -22, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    -8, 3, 3, -14, 0, 0, 0, -12,
    0, -10, 0, -5, -3, -7, 0, -6,
    -3, 0, -5, 0, 0, 0, 0, -3,
    0, -7, -7, -6, -3, 0, 0, -2,
    -3, -3, 0, -8, -5, -5, -5, -2,
    -5, 3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -24, -2, 0, 6, -10, 4, 0, -16,
    -4, 5, -11, 0, 0, 0, -21, -9,
    -20, -11, 0, -24, 0, 0, 0, 7,
    1, 0, -3, -3, 0, 0, 0, 0,
    0, 0, 0, 0, -5, -2, -14, -9,
    3, -10, 3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, -1, 0, -11, 4, -10, 0,
    0, 0, -7, 0, 0, -7, -1, -7,
    0, -7, -5, -7, -13, -5, 0, 0,
    -27, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, -9, 0, -29, 0, -22,
    0, 0, -3, -19, 0, 0, -18, -2,
    0, 0, -1, -2, -8, -5, -7, 0,
    0, -41, -4, 0, -6, -6, 0, -9,
    0, 0, 0, -3, -4, -4, 0, 0,
    0, 1, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -7, 0, 0, -4,
    -5, 0, 0, -6, 0, -3, 0, -9,
    0, -7, -4, -8, -3, 0, -11, 0,
    0, 0, 0, -3, 0, -4, -4, 0,
    -7, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, 0,
    4, -8, 0, 0, -2, 0, 0, 0,
    0, -4, -6, 0, -4, -3, 0, -9,
    0, 0, 0, -16, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 4, -8, 6,
    -21, -13, -26, -12, 0, -10, -19, -7,
    -1, -15, -3, 5, 0, 1, 2, 0,
    1, 0, 0, 0, -23, -20, 0, -19,
    -19, -4, -23, 0, 0, 0, -13, -13,
    -20, 0, -13, -8, -10, -11, -10, -14,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, -9, 0, -10, 0, 0, 0, -6,
    0, 0, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -18, 0, 0,
    0, 0, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 3,
    -10, 6, -17, -7, -18, -8, 4, -9,
    -14, -7, 0, -13, -7, 1, 0, 1,
    1, 0, 0, -1, 0, 0, -22, -11,
    0, -10, -10, 0, -12, 0, -1, 0,
    -5, -5, -7, 0, -7, -3, -3, -3,
    -2, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    4, -8, 3, -11, -3, -11, 0, 3,
    -6, -6, -5, 0, -12, 0, 2, 0,
    1, 1, 0, 0, -1, 0, 0, -14,
    -7, 0, -6, -6, 0, -6, 0, -1,
    0, -3, -1, -3, 0, -1, 0, -3,
    -3, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, 0, 3, -10, 0, -4,
    -1, -9, 1, -7, 0, -5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    6, -2, 0, -5, -5, 0, 0, 0,
    0, 0, 0, 0, -3, -5, -5, -4,
    -6, 0, -3, 3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 2, -15, 6, -19, -14, -23,
    -14, 1, -12, -19, -13, 0, -18, -11,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, -23, -18, -3, -16, -16, -6, -17,
    -4, -8, 0, -13, -14, -16, -6, -11,
    -9, -10, -10, -9, -12, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, -3, 3, 9, -12,
    0, 0, 0, -5, 0, -5, 0, -1,
    0, 0, 0, -2, -1, 0, -2, 0,
    0, 0, 4, 0, 0, -1, -1, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    -1, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, -9, -11, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 4,
    -27, 1, -14, -16, -23, -18, -22, -14,
    6, -23, 7, 0, 0, 0, -9, 0,
    -17, -15, -7, 7, 0, 16, -12, 0,
    3, -11, -15, -10, -20, -14, 6, -4,
    2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    0, 0, 3, -1, 6, 0, 0, 0,
    2, 0, 0, 0, 0, -20, 0, -9,
    -2, 0, -13, 2, 0, 0, 3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, -3, -1, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -6, 0, 0, -5, 3, 0, 0, 0,
    0, 0, 0, -1, 0, 0, -19, 0,
    -10, -6, -5, -16, -1, 0, 0, -15,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, 0, -2, 0, -2, -3,
    -4, -3, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 2, 0, 0, 1, 0, -13,
    0, -8, -3, 0, -13, 2, 0, 0,
    -9, 0, 0, -1, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, 0, 0, -5, 3, 0,
    0, 0, 0, 0, 0, -1, 0, -3,
    -19, 0, -10, -5, -5, -16, -1, 0,
    0, -16, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, -1, -4, -2, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 6, 9, -4, 7, -9, 0,
    -6, 0, 9, 0, -2, 4, 0, -6,
    0, 8, 0, 8, 7, 3, 7, 1,
    0, 4, -18, 0, 0, -1, -1, 1,
    -1, 3, 0, 0, 0, 0, 0, 0,
    0, 3, 0, 0, 3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, -1, 7, 2,
    0, 6, 0, 0, 0, 6, 0, 0,
    -2, 0, -3, 0, -2, 0, 3, -3,
    3, 0, 3, 16, -1, 0, -2, -2,
    0, 2, 0, 7, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -16, 0, -10, -7, 0,
    -16, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, -2, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -12, 0, -7,
    -3, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, 0, -11, 0, 0, 0,
    -4, 4, -3, 0, -1, -2, -9, 0,
    -5, -2, 0, -14, 4, 0, 0, 5,
    0, 0, -7, -5, 0, -1, 0, 0,
    0, 0, 0, -3, -3, -3, -4, -1,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, -3, 0, 0,
    0, 0, 6, 0, 0, 2, 0, -4,
    0, -2, 0, 4, -5, 4, 0, 0,
    6, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, -1, 0, -2,
    -1, 0, -2, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, 0, 0, -5, 3, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    -19, 0, -10, -6, -5, -16, -1, 0,
    0, -16, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    -2, -3, -4, -3, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -12, 0, -7, -3, 0, -11, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 9, -6, 0, -23,
    -2, -6, 0, 0, 0, -10, 3, 0,
    -7, 2, -3, 0, 0, 1, -6, -6,
    -3, 0, 0, -23, -3, 0, -1, -1,
    2, -5, 0, 0, 0, 0, 0, 0,
    1, 0, 2, 1, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    -2, -1, 0, 0, 0, 0, 0, 0,
    0, -1, 0, -19, 0, -9, 0, -7,
    -14, 0, 0, 0, -12, 0, 0, 0,
    0, -1, -1, 0, 0, 0, 0, 0,
    -2, -2, 0, -3, -3, -5, -3, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, 0, -4, 0, 0, 0, 0, 2,
    0, 0, 0, 0, -7, 0, 0, 0,
    0, -6, 0, 0, 2, 5, 0, 0,
    -1, -1, -1, -1, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -13, 0, -7,
    -2, 0, -14, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    7, -5, 0, -14, -2, -3, 0, 0,
    0, -8, 0, -1, -6, 0, -8, 0,
    -3, 0, 0, -9, 0, 0, 0, -20,
    -3, 0, -2, -2, 1, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 6, -6, 0, -11, -1, 0, 0,
    0, -2, -5, 0, 0, -6, 0, -10,
    0, -3, -3, 0, -10, 0, 0, 0,
    -14, -4, 0, -3, -3, 0, -5, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, -8, 0, 0, -10, 0,
    0, 0, -5, 0, 0, 0, -3, 0,
    -11, 0, -3, -3, 0, -10, 0, 0,
    0, 6, 0, 0, -4, -4, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 6, -8, 0, -14, -2,
    -1, 0, 0, -3, -4, 0, -1, -8,
    0, -10, 0, -3, 0, 0, -9, 0,
    0, 0, -23, -4, 0, -2, -2, 2,
    -7, 0, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, -3, 0, 3,
    -6, 0, 0, 0, -3, 3, 0, 0,
    0, 0, -10, 0, -3, -1, 3, -8,
    0, 0, 0, 2, 0, 0, -3, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, -3, -2, -5, 0, 0,
    0, 0, 0, -3, -3, -3, 0, 0,
    -5, -3, -53, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, -3, -4, -1,
    0, 0, 0, 0, -3, 0, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, -3, -6, 0, -5,
    -6, 0, 0, -3, -4, 0, -7, -6,
    -1, 0, 0, -3, -3, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -9, -3, 0, -5,
    -6, -4, -3, -3, -1, 0, -3, -10,
    -6, -3, -10, 0, -3, 0, 0, 0,
    0, 0, 6, 0, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 13, 5, 16, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 6,
    0, 3, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 11, 9,
    13, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, -2, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 2,
    -4, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -6, -2,
    -3, 0, 0, 0, -5, -5, 0, 0,
    0, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, 0, 0, 0,
    0, 0, 6, 1, 12, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, -3, -9, 0,
    -6, -9, -1, 0, -6, -10, 0, -11,
    -9, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 17, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 6,
    17, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, -3, -9,
    0, -6, -9, -1, 0, -6, -7, 0,
    -11, -9, 0, 0, 14, 21, 36, 0,
    0, 0, 0, 0, 0, 17, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    9, 17, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    -6, 0, -6, -5, -1, 0, -3, -4,
    0, -8, -6, 0, 0, 15, 20, 30,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    -3, -13, 0, -6, -9, -1, 0, -6,
    -7, 0, -11, -9, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 10,
    4, 14, 0, 0, 6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    5, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 17, 7, 27, 0, 7, 14
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 80,
    .right_class_cnt     = 65,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t IBMTH_18 = {
#else
lv_font_t IBMTH_18 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 25,          /*The maximum line height required by the font*/
    .base_line = 7,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if IBMTH_18*/

