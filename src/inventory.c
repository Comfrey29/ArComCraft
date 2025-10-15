#include "inventory.h"
#include "blocks.h"
#include <stdio.h>

static int inventory[MAX_BLOCKS] = {0};

void Inventory_Init(void) {
    for (int i = 0; i < MAX_BLOCKS; i++) inventory[i] = 0;
}

void Inventory_AddBlock(int blockId, int amount) {
    if (blockId >= 0 && blockId < MAX_BLOCKS)
        inventory[blockId] += amount;
}

void Inventory_Show(void) {
    printf("Inventari:\n");
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (inventory[i] > 0) {
            Block* b = Blocks_Get(i);
            if (b) printf("%s x%d\n", b->name, inventory[i]);
        }
    }
}

