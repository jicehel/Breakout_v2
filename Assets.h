#pragma once

#ifndef ASSETS
#define ASSETS
    
    // Ball images
    
    uint16_t ball2Data[] = {2,2,1, 1, 0, 0, 0xffff,0xfb40,0xfb40,0x7980};
    Image ball2 = Image(ball2Data);

    uint16_t ball3Data[] = {3,3,1, 1, 0, 0, 0xffff,0xffff,0xfb40,0xffff,0xfec0,0x7980,0xfb40,0x7980,0x7980};
    Image ball3 = Image(ball3Data);

    uint16_t ball4Data[] = {4,4,1, 1, 0xf80d, 0, 0xf80d,0xffff,0xfb40,0xf80d,0xffff,0xfec0,0xfec0,0x7980,0xfb40,0xfec0,0xfb40,0x7980,0xf80d,0x7980,0x7980,0xf80d};
    Image ball4 = Image(ball4Data);

    uint16_t ball5Data[] = {5,5,1, 1, 0xf80d, 0, 0xf80d,0xfec0,0xffff,0x7800,0xf80d,0xfec0,0xffff,0xffff,0xfec0,0x7800,0xfec0,0xffff,0xfec0,0xfb40,0x7800,0x7800,0xfec0,0xfb40,0x7980,0x7800,0xf80d,0x7800,0x7800,0x7800,0xf80d};
    Image ball5 = Image(ball5Data);

    uint16_t ball4MetalData[] = {4,4,1, 1, 0xf80d, 0, 0xf80d,0xc618,0xad75,0xf80d,0xc618,0xef7d,0xdefb,0x3186,0xad75,0xdefb,0x630c,0x3186,0xf80d,0x3186,0x3186,0xf80d};
    Image ball4Metal = Image(ball4MetalData);

#endif