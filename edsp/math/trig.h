//
// Created by Mohammed Boujemaoui on 09/10/2017.
//

#ifndef EDSP_TRIG_H
#define EDSP_TRIG_H

#include "../config.h"
#include "../base/constants.h"

#include <algorithm>
#include <numeric>
#include <cmath>

EDSP_BEGIN_NAMESPACE
    namespace math {
        template<typename T>
        constexpr T asinh(const T &x) {
            return static_cast<T>(
                    std::log(x + std::sqrt(x * x + 1)));
        }

        template<typename T>
        constexpr T acosh(const T &x) {
            return static_cast<T>(
                    std::log(x + std::sqrt(x * x - 1)));
        }

        template<typename T>
        constexpr T deg_to_rad(const T &x) {
            return static_cast<T>( x * constants<T>::pi / 180 );
        }

        template<typename T>
        constexpr T rad_to_deg(const T &x) {
            return static_cast<T>( x * constants<T>::pi * 180 );
        }
    }

EDSP_END_NAMESPACE

#endif //EDSP_TRIG_H
