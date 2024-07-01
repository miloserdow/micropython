#include "py/runtime.h"
#include "py/obj.h"
#include "py/objstr.h"
#include "py/mphal.h"
#include "near_api.h"

static mp_obj_t mod_near_input(mp_obj_t register_id_obj) {
    uint64_t register_id = mp_obj_get_int(register_id_obj);
    near_input(register_id);
    return mp_const_none;
}

static mp_obj_t mod_near_read_register(mp_obj_t register_id_obj, mp_obj_t ptr_obj) {
    uint64_t register_id = mp_obj_get_int(register_id_obj);
    uint64_t ptr = mp_obj_get_int(ptr_obj);
    near_read_register(register_id, ptr);
    return mp_const_none;
}

static mp_obj_t mod_near_register_len(mp_obj_t register_id_obj) {
    uint64_t register_id = mp_obj_get_int(register_id_obj);
    uint64_t len = near_register_len(register_id);
    return mp_obj_new_int_from_ull(len);
}

static mp_obj_t mod_near_value_return(mp_obj_t value_len_obj, mp_obj_t value_ptr_obj) {
    uint64_t value_len = mp_obj_get_int(value_len_obj);
    uint64_t value_ptr = mp_obj_get_int(value_ptr_obj);
    near_value_return(value_len, value_ptr);
    return mp_const_none;
}

static mp_obj_t mod_near_log_utf8(mp_obj_t len_obj, mp_obj_t ptr_obj) {
    uint64_t len = mp_obj_get_int(len_obj);
    uint64_t ptr = mp_obj_get_int(ptr_obj);
    near_log_utf8(len, ptr);
    return mp_const_none;
}

static MP_DEFINE_CONST_FUN_OBJ_1(mod_near_input_obj, mod_near_input);
static MP_DEFINE_CONST_FUN_OBJ_2(mod_near_read_register_obj, mod_near_read_register);
static MP_DEFINE_CONST_FUN_OBJ_1(mod_near_register_len_obj, mod_near_register_len);
static MP_DEFINE_CONST_FUN_OBJ_2(mod_near_value_return_obj, mod_near_value_return);
static MP_DEFINE_CONST_FUN_OBJ_2(mod_near_log_utf8_obj, mod_near_log_utf8);

static const mp_rom_map_elem_t near_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_near) },
    { MP_ROM_QSTR(MP_QSTR_input), MP_ROM_PTR(&mod_near_input_obj) },
    { MP_ROM_QSTR(MP_QSTR_read_register), MP_ROM_PTR(&mod_near_read_register_obj) },
    { MP_ROM_QSTR(MP_QSTR_register_len), MP_ROM_PTR(&mod_near_register_len_obj) },
    { MP_ROM_QSTR(MP_QSTR_value_return), MP_ROM_PTR(&mod_near_value_return_obj) },
    { MP_ROM_QSTR(MP_QSTR_log_utf8), MP_ROM_PTR(&mod_near_log_utf8_obj) },
};
static MP_DEFINE_CONST_DICT(near_module_globals, near_module_globals_table);

const mp_obj_module_t mp_module_near = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&near_module_globals,
};

