//
// Created by anatoliy on 9/18/20.
//

#ifndef LINUX_BASIC_COURSE_STACK_H
#define LINUX_BASIC_COURSE_STACK_H
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity);

int pop(struct Stack* stack);

int peek(struct Stack* stack);

void push(struct Stack* stack, int element);

int isEmpty(struct Stack* stack);

int isFull(struct Stack* stack);
#endif //LINUX_BASIC_COURSE_STACK_H
