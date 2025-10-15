#ifndef BLOCKS_H
#define BLOCKS_H

#define MAX_BLOCKS 256

typedef struct {
    int id;
    const char* name;
    const char* texture;
} Block;

void Blocks_Init(void);
Block* Blocks_Get(int id);

#endif
