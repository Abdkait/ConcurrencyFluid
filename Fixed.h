#ifndef CONCURRENCYFLUID_FIXED_H
#define CONCURRENCYFLUID_FIXED_H

#include <cinttypes>
#include <ostream>

struct Fixed {
    constexpr Fixed(int v, bool) : v(v) {}

    constexpr Fixed(int v) : v(v << 16) {}

    constexpr Fixed(float f) : v(f * (1 << 16)) {}

    constexpr Fixed(double f) : v(f * (1 << 16)) {}

    constexpr Fixed() : v(0) {}

    static constexpr Fixed from_raw(int32_t x) {
        Fixed ret;
        ret.v = x;
        return ret;
    }

    int32_t v;

    auto operator<=>(const Fixed &) const = default;

    bool operator==(const Fixed &) const = default;
};

Fixed operator+(Fixed a, Fixed b) {
    return Fixed::from_raw(a.v + b.v);
}

Fixed operator-(Fixed a, Fixed b) {
    return Fixed::from_raw(a.v - b.v);
}

Fixed operator*(Fixed a, Fixed b) {
    return Fixed::from_raw(((int64_t) a.v * b.v) >> 16);
}

Fixed operator/(Fixed a, Fixed b) {
    return Fixed::from_raw(((int64_t) a.v << 16) / b.v);
}

Fixed &operator+=(Fixed &a, Fixed b) {
    return a = a + b;
}

Fixed &operator-=(Fixed &a, Fixed b) {
    return a = a - b;
}

Fixed &operator*=(Fixed &a, Fixed b) {
    return a = a * b;
}

Fixed &operator/=(Fixed &a, Fixed b) {
    return a = a / b;
}

Fixed operator-(Fixed x) {
    return Fixed::from_raw(-x.v);
}

std::ostream &operator<<(std::ostream &out, Fixed x) {
    return out << x.v / (double) (1 << 16);
}
#endif //CONCURRENCYFLUID_FIXED_H
