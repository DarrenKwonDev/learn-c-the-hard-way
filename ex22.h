#ifndef _ex22_h
#define _ex22_h

// ex22.c에 있는 THE_SIZE를 해당 header를 include한 다른 .c 에서도 사용가능
extern int THE_SIZE;

int get_age();
void set_age(int age);

double update_ratio(double ratio);

void print_size();

#endif
