//
// Created by Lesya on 07.04.2023.
//
#include "vector.h"

//возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n){
    vector v = (vector){malloc(sizeof(int)* n),0,n};
    if (n == 0)
        v.data = NULL;
    else if (v.data == NULL){
        fprintf(stderr, "bad alloc ");
        exit(1);
    }

    return v;
}

//изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(vector *v, size_t newCapacity) {
    v->capacity = newCapacity;
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    bool flag = newCapacity != 0;
    if (v->data == NULL && flag) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else if (newCapacity < v->size)
        v->size = newCapacity;
}

//удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector *v) {
    v->size = 0;
}

//свобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

//освобождает память, выделенную вектору.
void deleteVector(vector *v) {
    reserve(v, 0);
}