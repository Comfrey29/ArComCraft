#include "blocks.h"
#include <stdio.h>

static Block blocks[MAX_BLOCKS];
static int block_count = 0;

void Blocks_Init(void) {
    blocks[0].id = 0; blocks[0].name = "Air"; blocks[0].texture = "air.png";
    blocks[1].id = 1; blocks[1].name = "Stone"; blocks[1].texture = "stone.png";
    blocks[2].id = 2; blocks[2].name = "Dirt"; blocks[2].texture = "dirt.png";
    blocks[3].id = 3; blocks[3].name = "Grass"; blocks[3].texture = "grass.png";
    block_count = 4;
    printf("%d blocs inicialitzats.\n", block_count);
}

Block* Blocks_Get(int id) {
    if (id >= 0 && id < block_count)
        return &blocks[id];
    return NULL;
}

