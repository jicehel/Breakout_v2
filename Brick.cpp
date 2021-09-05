#include <Gamebuino-Meta.h>
#include "Global.h"


// -------------------------------------------
// //             Briques                   //
// -------------------------------------------

const uint16_t b01Data[] = {8,4,1, 1, 0, 0, 0x4a69,0xbdf7,0xbdf7,0xbdf7,0xbdf7,0xbdf7,0xd69a,0xef7d,0x39c7,0x8410,0x9cd3,0x9cd3,0x9cd3,0x9cd3,0x9cd3,0xad55,0x39e7,0x6b6d,0x73ae,0x73ae,0x73ae,0x73ae,0x73ae,0x738e,0x2124,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x31a6};
const uint16_t b02Data[] = {8,4,1, 1, 0, 0, 0x528e,0x7bd5,0x8416,0x8c57,0x9cb8,0xa519,0xb59a,0xef5e,0x865,0x210c,0x296d,0x39ef,0x4a71,0x6b53,0x7bf5,0xb59a,0x844,0x10aa,0x210c,0x296d,0x420f,0x4a71,0x6b53,0x9cd8,0x1,0x844,0x865,0x1086,0x18c7,0x2107,0x2948,0x6330};
const uint16_t b03Data[] = {8,4,1, 1, 0, 0, 0x1b32,0x3cba,0x4d3b,0x5dbc,0x763d,0x869e,0x9f1f,0xbf7f,0x109,0x2b4,0x356,0x13f8,0x2c99,0x4d7b,0x6e3d,0x96ff,0xc8,0x211,0x2b4,0x316,0x13f8,0x2c9a,0x4d7b,0x763d,0x43,0xc8,0x109,0x16a,0x1cb,0xa0c,0x1a6d,0x33f4};
const uint16_t b04Data[] = {8,4,1, 1, 0, 0, 0x3ef,0x595,0x595,0x638,0x69a,0x6db,0x75c,0x47be,0x186,0x3ce,0x491,0x4b2,0x595,0x638,0x679,0x71b,0x186,0x30b,0x3ee,0x40f,0x4d2,0x595,0x679,0x69a,0x82,0x186,0x186,0x207,0x248,0x269,0x2cb,0x451};
const uint16_t b05Data[] = {8,4,1, 1, 0, 0, 0x4bc7,0x7d0a,0x856b,0x8dcc,0x8e0d,0x964e,0xa6af,0xd756,0x160,0x1301,0x1b82,0x2c24,0x3485,0x4527,0x5589,0xa68f,0x100,0xa80,0x1301,0x1b82,0x2c24,0x34a5,0x4527,0x964d,0x60,0x100,0x160,0x981,0x11e1,0x1222,0x1a62,0x5c68};
const uint16_t b06Data[] = {8,4,1, 1, 0, 0, 0x92c0,0xd4e1,0xddc2,0xe622,0xe6a3,0xef03,0xf78a,0xfff8,0x5920,0xbae1,0xc3a1,0xd441,0xdce2,0xe5e2,0xeea3,0xef63,0x58e0,0xb221,0xbae1,0xc361,0xd441,0xdce2,0xe5e2,0xeec2,0x2840,0x58e0,0x5920,0x6180,0x61e0,0x6a41,0x6a81,0x9bc1};
const uint16_t b07Data[] = {8,4,1, 1, 0, 0, 0x9bc8,0xcd2a,0xd52a,0xdd4a,0xe58a,0xe5aa,0xee0a,0xff38,0x4920,0xa280,0xb2c0,0xbb00,0xcb40,0xdba0,0xe400,0xedea,0x38e0,0x8200,0xa2a0,0xb2c0,0xbb00,0xcb20,0xdba0,0xe5aa,0x1040,0x30c0,0x4100,0x5160,0x5960,0x6180,0x69a0,0xa408};
const uint16_t b08Data[] = {8,4,1, 1, 0, 0, 0x81e8,0xb2ec,0xcb8e,0xcbcf,0xdc31,0xe4b3,0xed14,0xfe38,0x3842,0x78e5,0x8946,0xa1e8,0xaa4a,0xbacc,0xcbaf,0xed14,0x3021,0x6883,0x78e5,0x8946,0xa1e8,0xaa4a,0xbacc,0xdc51,0x1000,0x3021,0x3842,0x4082,0x48a3,0x5104,0x5925,0x928a};
const uint16_t b09Data[] = {8,4,1, 1, 0, 0, 0x7b28,0xbcad,0xc50e,0xc50e,0xd590,0xe5d2,0xee33,0xff9d,0x3121,0x7263,0x8b46,0x9ba8,0xa429,0xc4ed,0xddd1,0xee33,0x28a0,0x6202,0x7263,0x8b26,0x9ba8,0xa429,0xc4ed,0xddd1,0x1040,0x28a0,0x3121,0x3942,0x49a3,0x49e4,0x5225,0x93ca};
const uint16_t b10Data[] = {8,4,1, 1, 0, 0, 0x92d5,0xbb9a,0xb379,0xa337,0xab37,0x9b16,0x92d4,0xc479,0x8273,0xab59,0x9af6,0x8ab4,0x7210,0x61ae,0x516c,0x92d4,0x92d4,0xc3db,0xab59,0x92f5,0x8ab4,0x7210,0x61ae,0x9b15,0x7210,0x8ab4,0x8273,0x7a51,0x6a10,0x69ef,0x59ad,0x8272};
const uint16_t b11Data[] = {8,4,1, 1, 0, 0, 0xa1a6,0xfcd1,0xfc91,0xfc11,0xfc30,0xfc11,0xfdd7,0xffff,0x5000,0xea28,0xe9c8,0xd188,0xb106,0x98e4,0x80c4,0xfdd7,0x6000,0xeb29,0xea28,0xe1a8,0xd188,0xb126,0x98e4,0xfc11,0x3000,0x5800,0x5000,0x4800,0x3800,0x3000,0x1800,0x81a6};
const uint16_t b12Data[] = {8,4,1, 1, 0, 0, 0x3761,0x576a,0x5f6a,0x7769,0x6769,0x7769,0xa772,0xef7d,0x1c80,0x2760,0x3f60,0x3f60,0x3760,0x3761,0x7769,0xa772,0xaa0,0x1d20,0x2760,0x3f60,0x3f60,0x3760,0x3761,0x7769,0x960,0x960,0xaa0,0x1320,0x1400,0x1c80,0x1d20,0x3761};
Image imageBrique[12] = {Image(b01Data),Image(b02Data),Image(b03Data), Image(b04Data),Image(b05Data), Image(b06Data),Image(b07Data), Image(b08Data), Image(b09Data),Image(b10Data), Image(b11Data), Image(b12Data)};

// Draw the defined brick
void Brick::drawBrick(int8_t brickType, int8_t xBrique, int8_t yBrique) {
  if (brickType > 10) brickType = level.defaultBonusBrick;
  if (brickType > 0)  gb.display.drawImage(xBrique, yBrique, imageBrique[brickType - 1]);
}

void Brick::collision_brick(int8_t r,int8_t c ) {
  //If a collison has occured
  if (currentLevel[r][c].typeBrick > 1) {
         level.brickCount++;
         game.score = game.score + NB_PTS_BRICK;
         // Manage bonus / malus add
         /* if (typeBrick[r][c] == 11 || typeBrick[r][c] == 12 || typeBrick[r][c] == 14 || typeBrick[r][c] == 20 || typeBrick[r][c] == 21 ) {
            (if game.sound) gb.sound.fx(SBonus); 
            Add_bonus(typeBrick[r][c],BRICK_WIDTH * c,((r+1)*BRICK_HEIGHT  + Ytop));
         } else if (typeBrick[r][c] == 13 || typeBrick[r][c] == 17 || typeBrick[r][c] == 18 || typeBrick[r][c] == 19 ) {
            gb.sound.fx(SLostlife); 
            Add_bonus(18,BRICK_WIDTH * c,((r+1)*BRICK_HEIGHT  + Ytop));
         } // end if */    
         currentLevel[r][c].isHit = true;
  }
}
