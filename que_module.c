//
// Created by abata on 2018/12/02.
//

#include "que_module.h"

static data_t event_que[QUE_SIZE];
static data_t hist_que[QUE_SIZE];
static uint8_t event_que_head = 0;
static uint8_t event_que_num = 0;
static uint8_t hist_que_head = 0;
static uint8_t hist_que_num = 0;

data_t *que_data_initialize(bool is_use_event_que) {
    if (is_use_event_que) return event_que;
    else return hist_que;
}

uint8_t *que_head_initialize(bool is_use_event_que) {
    if (is_use_event_que) return &event_que_head;
    else return &hist_que_head;
}

uint8_t *que_num_initialize(bool is_use_event_que) {
    if (is_use_event_que) return &event_que_num;
    else return &hist_que_num;
}

uint8_t que_to_array_index(bool is_use_event_que, unit8_t que_index){
    uint8_t *que_head;
    que_head = que_head_initialize(is_use_event_que);
    return (*que_head + que_index) % QUE_SIZE;
}

bool enque(bool is_use_event_que, data_t enque_data) {
    data_t *que_data;
    que_data = que_data_initialize(is_use_event_que);
    uint8_t *que_head;
    que_head = que_head_initialize(is_use_event_que);
    uint8_t *que_num;
    que_num = que_num_initialize(is_use_event_que);

    if (*que_num < QUE_SIZE) {
        que_data[(*que_head + *que_num) % QUE_SIZE] = enque_data;
        (*que_num)++;
        return true;
    } else {
        return false;
    }
}

data_t unenque(bool is_use_event_que) {
    data_t *que_data;
    que_data = que_data_initialize(is_use_event_que);
    uint8_t *que_head;
    que_head = que_head_initialize(is_use_event_que);
    uint8_t *que_num;
    que_num = que_num_initialize(is_use_event_que);

    data_t unenq_data;
    if (*que_num > 0) {
        unenq_data = que_data[(*que_head + *que_num - 1) % QUE_SIZE];
        (*que_num)--;
        return unenq_data;
    } else {
        return NULL_QUE;
    }
}

data_t deque(bool is_use_event_que) {
    data_t *que_data;
    que_data = que_data_initialize(is_use_event_que);
    uint8_t *que_head;
    que_head = que_head_initialize(is_use_event_que);
    uint8_t *que_num;
    que_num = que_num_initialize(is_use_event_que);

    data_t deq_data;
    if (*que_num > 0) {
        deq_data = que_data[*que_head];
        *que_head = (uint8_t) ((*que_head + 1) % QUE_SIZE);
        (*que_num)--;
        return deq_data;
    } else {
        return NULL_QUE;
    }
}

data_t read_que_head(bool is_use_event_que) {
    data_t *que_data;
    que_data = que_data_initialize(is_use_event_que);
    uint8_t *que_head;
    que_head = que_head_initialize(is_use_event_que);
    uint8_t *que_num;
    que_num = que_num_initialize(is_use_event_que);

    if (*que_num > 0) {
        return que_data[*que_head];
    } else {
        return NULL_QUE;
    }
}

data_t read_que_from_last(bool is_use_event_que, uint8_t from_last) {
    data_t *que_data;
    que_data = que_data_initialize(is_use_event_que);
    uint8_t *que_head;
    que_head = que_head_initialize(is_use_event_que);
    uint8_t *que_num;
    que_num = que_num_initialize(is_use_event_que);

    if (*que_num > 0) {
        uint8_t virtual_que_last_index = (uint8_t) (*que_head + *que_num - 1);
        uint8_t virtual_que_index = virtual_que_last_index - from_last;
        if (virtual_que_index < 0) return NULL_QUE;
        uint8_t real_que_index = (uint8_t) (virtual_que_index % QUE_SIZE);
        return que_data[real_que_index];
    } else {
        return NULL_QUE;
    }
}

void que_clear(bool is_use_event_que) {
    uint8_t *que_head;
    que_head = que_head_initialize(is_use_event_que);
    uint8_t *que_num;
    que_num = que_num_initialize(is_use_event_que);

    *que_head = 0;
    *que_num = 0;
}

void swap_element_in_array(data_t *array, uint8_t index1, uint8_t index2) {
    data_t tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}

void swap_element_in_que(bool is_use_event_que, uint8_t v_index1, uint8_t v_index2) {
    data_t *que_data;
    que_data = que_data_initialize(is_use_event_que);

    uint8_t r_index1 = (uint8_t) (v_index1 % QUE_SIZE);
    uint8_t r_index2 = (uint8_t) (v_index2 % QUE_SIZE);
    swap_element_in_array(que_data, r_index1, r_index2);
}

