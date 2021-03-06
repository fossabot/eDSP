//
// Created by Mohammed Boujemaoui on 10/12/2017.
//

#ifndef EDSP_FADEIN_H
#define EDSP_FADEIN_H

#include "config.h"
#include <iterator>

EDSP_BEGIN_NAMESPACE
    namespace blocks {
        class FadeIn {
        public:
            FadeIn(double samplerate, double duration);
            ~FadeIn() = default;

            template <class InputIterator, class OutputIterator>
            void compute(InputIterator first, InputIterator last, OutputIterator out) {
                for (; first != last; ++first, ++out) {
                    compute(*first, *out);
                };
            }

            template <typename T>
            void compute(const T in, T& out) {
                if (m_timestamp < m_duration) {
                    out = in * (m_timestamp / m_duration);
                    m_timestamp += m_increment;
                } else {
                    out = in;
                }
            }

            void set_duration(double duration) { m_duration = duration; }
            void set_samplerate(double samplerate);
            void reset() { m_timestamp = 0.; }
        private:
            double m_samplerate{0.};
            double m_duration{0.};
            double m_increment{0.};
            double m_timestamp{0.};
        };
    }
EDSP_END_NAMESPACE

#endif //EDSP_FADEIN_H
