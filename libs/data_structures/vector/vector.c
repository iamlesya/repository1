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

// проверяет, является ли вектор v пустым
bool isEmpty(vector *v) {
    return (v->size == 0);
}

// проверяет, является ли вектор v полным
bool isFull(vector *v) {
    return (v->size == v->capacity && v->size != 0);
}

// возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t i){
    return (v->data[i]);
}

// добавляет элемент x в конец вектора.
void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v,1);
    if (isFull(v))
        reserve(v,2 * v->capacity);
    v->data[v->size] = x;
    v->size += 1;
}

// удаляет последний элемент из вектора v.
void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector empty");
        exit(1);
    }
    v->size -= 1;
}