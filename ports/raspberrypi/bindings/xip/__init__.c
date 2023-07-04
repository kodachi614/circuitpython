#include <stdlib.h>

#include "py/obj.h"
#include "py/runtime.h"
#include "py/builtin.h"

// Definitions for the RP2040 XIP control registers
#include "src/rp2040/hardware_structs/include/hardware/structs/xip_ctrl.h"

// Methods we'll build into the xip_cache module...

// Reset the XIP cache counters.
STATIC mp_obj_t xip_cache_counter_reset(mp_obj_t self_in) {
    // Any write to a counter registers will reset the counter, so we
    // write to the access counter and the hit counter. Done.
    xip_ctrl_hw->ctr_acc = 1;
    xip_ctrl_hw->ctr_hit = 1;

    return mp_const_none;
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(xip_cache_counter_reset_obj, xip_cache_counter_reset);

// Read the XIP cache counters.
STATIC mp_obj_t xip_cache_counters(mp_obj_t self_in) {
    // We return a tuple of (accesses, hits).
    mp_obj_t tuple[2];

    tuple[0] = mp_obj_new_int(xip_ctrl_hw->ctr_acc);
    tuple[1] = mp_obj_new_int(xip_ctrl_hw->ctr_hit);

    return mp_obj_new_tuple(2, tuple);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(xip_cache_counters_obj, xip_cache_counters);

// Enable or disable the cache. Not scary at all, right?
// NOTE: disabling the cache will probably severely impact performance.
STATIC mp_obj_t xip_cache_enable(mp_obj_t self_in, mp_obj_t onoff_in) {
    const uint32_t current = xip_ctrl_hw->ctrl;
    uint32_t new = current & ~XIP_CTRL_EN_BITS;

    if (mp_obj_is_true(onoff_in)) {
        new |= XIP_CTRL_EN_BITS;
    }

    xip_ctrl_hw->ctrl = new;

    return mp_const_none;
}

STATIC MP_DEFINE_CONST_FUN_OBJ_2(xip_cache_enable_obj, xip_cache_enable);

// Flush the contents of the XIP cache.
STATIC mp_obj_t xip_cache_flush(mp_obj_t self_in) {
    // Write to the flush register to reset the counter...
    xip_ctrl_hw->flush = 1;

    // ...then spin until the flush is complete. (We could also read
    // the flush register, but that would stall the entire machine, and
    // if we do things this we, interrupts still get to happen.)
    while (!(xip_ctrl_hw->stat & XIP_STAT_FLUSH_READY_BITS)) {
        tight_loop_contents();
    }

    return mp_const_none;
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(xip_cache_flush_obj, xip_cache_flush);

STATIC const mp_rom_map_elem_t xip_cache_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_counter_reset), MP_ROM_PTR(&xip_cache_counter_reset_obj) },
    { MP_ROM_QSTR(MP_QSTR_counters), MP_ROM_PTR(&xip_cache_counters_obj) },
    { MP_ROM_QSTR(MP_QSTR_enable), MP_ROM_PTR(&xip_cache_enable_obj) },
    { MP_ROM_QSTR(MP_QSTR_flush), MP_ROM_PTR(&xip_cache_flush_obj) },
};

STATIC MP_DEFINE_CONST_DICT(xip_cache_locals_dict, xip_cache_locals_dict_table);

const mp_obj_type_t xip_cache_type = {
    { &mp_type_type },
    .name = MP_QSTR_xip_cache,
    .locals_dict = (mp_obj_dict_t *)&xip_cache_locals_dict,
};

typedef struct _xip_cache_obj_t {
    mp_obj_base_t base;
} xip_cache_obj_t;

STATIC const xip_cache_obj_t xip_cache_obj = {{&xip_cache_type}};

STATIC const mp_rom_map_elem_t xip_cache_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_xip_cache) },
    { MP_ROM_QSTR(MP_QSTR_xip_cache), MP_ROM_PTR(&xip_cache_obj) },
};

STATIC MP_DEFINE_CONST_DICT(xip_cache_globals, xip_cache_globals_table);

const mp_obj_module_t xip_cache_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&xip_cache_globals,
};

MP_REGISTER_MODULE(MP_QSTR_xip_cache, xip_cache_module, CIRCUITPY_RP2XIP);
