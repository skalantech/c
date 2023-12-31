#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

struct car_t;

struct car_t* car_new();

void car_ctor(struct car_t*);

void car_dtor(struct car_t*);

void car_start(struct car_t*);
void car_stop(struct car_t*);
double car_get_engine_temperature(struct car_t*);

#endif // CAR_H_INCLUDED
