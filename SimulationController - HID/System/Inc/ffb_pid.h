#pragma once
#include <stdint.h>
#include <string.h>

#define MAX_EFFECTS  11
#define FIRST_EID     1

typedef struct __attribute__((packed)) {
    uint8_t report_id;
    uint8_t effect_type;
} CreateNewEffect_t;

typedef struct __attribute__((packed)) {
    uint8_t  report_id;
    uint8_t  effect_block_index;
    uint8_t  load_status;
    uint16_t ram_pool_available;
} PIDBlockLoad_t;

typedef struct __attribute__((packed)) {
    uint8_t  report_id;
    uint16_t ram_pool_size;
    uint8_t  max_simultaneous_effects;
    uint8_t  memory_management;
} PIDPool_t;

extern PIDBlockLoad_t gNewEffectBlockLoad;

void    FFB_Init(void);
void    FFB_CreateNewEffect(CreateNewEffect_t *in, PIDBlockLoad_t *out);
void    FFB_GetPIDPool(PIDPool_t *out);
void    FFB_ProcessOutputReport(uint8_t *buf, uint16_t len);
int16_t FFB_GetForce(void);   /* call from your motor loop */
