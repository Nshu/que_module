//
// Created by abata on 2018/12/02.
//

#include "../que_module_qmk_adapter.h"

void que_data_initialize(bool is_use_event_que, data_t *que_data);

uint8_t *que_head_initialize(bool is_use_event_que);

uint8_t *que_num_initialize(bool is_use_event_que);

bool enque(bool is_use_event_que, data_t enque_data);

data_t unenque(bool is_use_event_que);

data_t deque(bool is_use_event_que);

data_t read_que_head(bool is_use_event_que);

data_t read_que_from_last(bool is_use_event_que, uint8_t from_last);

void que_clear(bool is_use_event_que);

void swap_element_in_array(data_t *array, uint8_t index1, uint8_t index2);

void swap_element_in_que(bool is_use_event_que, uint8_t v_index1, uint8_t v_index2);


