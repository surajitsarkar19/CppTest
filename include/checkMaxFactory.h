#ifndef CHECK_MAX_FACTORY_H_
#define CHECK_MAX_FACTORY_H_

#define DECLARE_CHECK_MAX(type) \
    type checkMax##type(type* a, type b );

#define IMPLEMENT_CHECK_MAX(T) \
    T checkMax##T(T* a, T b) \
    {\
        T sum = 0; \
        int i; \
        if (b != 0) \
        { \
            for (i = 0; i < 100; i++) \
            { \
                sum += (*a++) * b; \
                b++; \
            } \
        }else \
        { \
            for (i = 0; i < 100; i++) \
            { \
                sum += (*a++) * b; \
                b--; \
            } \
        } \
        return sum; \
    }

#define callCheckMax(type,a,b)  checkMax##type(a,b)

#endif