//
// Created by Mohammed Boujemaoui on 09/12/2017.
//


#ifndef EDSP_TYPES_H
#define EDSP_TYPES_H

#include "config.h"
#include <complex>

EDSP_BEGIN_NAMESPACE
    using ecomplex = std::complex<double>;
    class ComplexPair : public std::pair<ecomplex, ecomplex> {

        EDSP_INLINE bool is_conjugate() const {
            return (first == std::conj(second));
        }

        EDSP_INLINE bool is_real() const  {
            return first.imag() == 0
                   && second.imag() == 0;
        }
    };

    using Pole = ComplexPair;
    using Zero = ComplexPair;

   class PoleZeroPair {
        EDSP_DECLARE_ALL_IMPLICITS(PoleZeroPair)
   public:
        EDSP_DEFAULT_CONSTRUCTOR(PoleZeroPair)
        EDSP_DEFAULT_DESTRUCTOR(PoleZeroPair)

        PoleZeroPair(const Pole &m_pole, const Zero &m_zero) : m_pole(m_pole), m_zero(m_zero) {}
        EDSP_INLINE void set_pole(const Pole& pole) { m_pole = pole; }
        EDSP_INLINE void set_zero(const Zero& zero) { m_zero = zero; }
        EDSP_INLINE const Zero& zero() const { return m_zero; }
        EDSP_INLINE const Pole& pole() const { return m_pole;}
    private:
        Pole m_pole{};
        Zero m_zero{};
    };

EDSP_END_NAMESPACE
#endif //EDSP_TYPES_H


