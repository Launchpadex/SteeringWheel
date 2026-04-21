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

typedef struct {
    int32_t prev_pos;
    uint32_t prev_pos_time;
    int32_t prev_speed;
    uint32_t prev_speed_time;
    int32_t curr_speed;
    uint32_t curr_speed_time;
    int32_t filtered_speed;
    int32_t filtered_accel;
} AxisState_t;

int32_t FFB_CalculateSpeed(uint8_t axis_id, int32_t current_pos, uint32_t current_time_ms);
int32_t FFB_CalculateAccel(uint8_t axis_id, int32_t current_speed, uint32_t current_time_ms);

extern PIDBlockLoad_t gNewEffectBlockLoad;

void    FFB_Init(void);
void    FFB_CreateNewEffect(CreateNewEffect_t *in, PIDBlockLoad_t *out);
void    FFB_GetPIDPool(PIDPool_t *out);
void    FFB_ProcessOutputReport(uint8_t *buf, uint16_t len);
int32_t FFB_GetForce(int32_t position, int32_t speed, int32_t accel, uint32_t current_time_ms);
void    FFB_SetMotorCurrent(int32_t current_mA);

int32_t FFB_GetLastForce(void);
int32_t FFB_GetLastSpeed(void);
int32_t FFB_GetLastAccel(void);
