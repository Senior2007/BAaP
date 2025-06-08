#include "Number.h"

Number::Number(double value) : value(value) {}

double Number::evaluate() const {
    return value;
}