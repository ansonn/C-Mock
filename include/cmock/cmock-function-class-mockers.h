// This file was GENERATED by command:
//     pump.py cmock-function-class-mockers.h.pump
// DO NOT EDIT BY HAND!!!

// Copyright 2013, Hubert Jagodziński
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: hubert.jagodzinski@gmail.com (Hubert Jagodziński)

// C Mock - extension to Google Mock framework allowing for writing C mock
// functions.
//
// This file implements C function mockers of various arities.

#ifndef CMOCK_INCLUDE_CMOCK_CMOCK_FUNCTION_CLASS_MOCKERS_H_
#define CMOCK_INCLUDE_CMOCK_CMOCK_FUNCTION_CLASS_MOCKERS_H_

#include <dlfcn.h>

#include <sstream>
#include <stdexcept>

// Allows finding an instance of a class:
//   class Foo : public CMockMocker<Foo> { ... }
//   Foo *p = CMockMocker<Foo>::cmock_get_instance();
template<typename T>
class CMockMocker
{
public:
	CMockMocker()
	{
		instance = (T *)this;
	}

	~CMockMocker()
	{
		instance = (T *)NULL;
	}

	static T *cmock_get_instance() { return instance; }

private:
	static T *instance;
};

template<typename T>
T *CMockMocker<T>::instance = NULL;

// Find the real implementation of a mocked function
static inline void *
cmock_lookup(const char *fname)
{
    return dlsym(RTLD_NEXT, fname);
}

#define CMOCK_MOCK_FUNCTION0(c, n, F) \
static GMOCK_RESULT_(, F) (*__cmock_real_##c##_##n)() = \
	(GMOCK_RESULT_(, F) (*)())cmock_lookup(#n); \
\
GMOCK_RESULT_(, F) n() { \
    c *mock = c::cmock_get_instance(); \
    if (mock != NULL) { \
        return mock->n(); \
    } \
	\
    if (__cmock_real_##c##_##n == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found. Neither mock nor real function is present."; \
        throw std::logic_error(msg.str()); \
    } \
    return __cmock_real_##c##_##n(); \
} \

#define CMOCK_MOCK_FUNCTION1(c, n, F) \
static GMOCK_RESULT_(, F) (*__cmock_real_##c##_##n)(GMOCK_ARG_(, 1, \
    F) cmock_a1) = \
	(GMOCK_RESULT_(, F) (*)(GMOCK_ARG_(, 1, F) cmock_a1))cmock_lookup(#n); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1) { \
    c *mock = c::cmock_get_instance(); \
    if (mock != NULL) { \
        return mock->n(cmock_a1); \
    } \
	\
    if (__cmock_real_##c##_##n == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found. Neither mock nor real function is present."; \
        throw std::logic_error(msg.str()); \
    } \
    return __cmock_real_##c##_##n(cmock_a1); \
} \

#define CMOCK_MOCK_FUNCTION2(c, n, F) \
static GMOCK_RESULT_(, F) (*__cmock_real_##c##_##n)(GMOCK_ARG_(, 1, \
    F) cmock_a1, GMOCK_ARG_(, 2, F) cmock_a2) = \
 (GMOCK_RESULT_(, F) (*)(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
     F) cmock_a2))cmock_lookup(#n); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2) { \
    c *mock = c::cmock_get_instance(); \
    if (mock != NULL) { \
        return mock->n(cmock_a1, cmock_a2); \
    } \
	\
    if (__cmock_real_##c##_##n == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found. Neither mock nor real function is present."; \
        throw std::logic_error(msg.str()); \
    } \
    return __cmock_real_##c##_##n(cmock_a1, cmock_a2); \
} \

#define CMOCK_MOCK_FUNCTION3(c, n, F) \
static GMOCK_RESULT_(, F) (*__cmock_real_##c##_##n)(GMOCK_ARG_(, 1, \
    F) cmock_a1, GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, \
    F) cmock_a3) = \
 (GMOCK_RESULT_(, F) (*)(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
     F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3))cmock_lookup(#n); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3) { \
    c *mock = c::cmock_get_instance(); \
    if (mock != NULL) { \
        return mock->n(cmock_a1, cmock_a2, cmock_a3); \
    } \
	\
    if (__cmock_real_##c##_##n == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found. Neither mock nor real function is present."; \
        throw std::logic_error(msg.str()); \
    } \
    return __cmock_real_##c##_##n(cmock_a1, cmock_a2, cmock_a3); \
} \

#define CMOCK_MOCK_FUNCTION4(c, n, F) \
static GMOCK_RESULT_(, F) (*__cmock_real_##c##_##n)(GMOCK_ARG_(, 1, \
    F) cmock_a1, GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
    GMOCK_ARG_(, 4, F) cmock_a4) = \
 (GMOCK_RESULT_(, F) (*)(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
     F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, \
     F) cmock_a4))cmock_lookup(#n); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, \
    F) cmock_a4) { \
    c *mock = c::cmock_get_instance(); \
    if (mock != NULL) { \
        return mock->n(cmock_a1, cmock_a2, cmock_a3, cmock_a4); \
    } \
	\
    if (__cmock_real_##c##_##n == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found. Neither mock nor real function is present."; \
        throw std::logic_error(msg.str()); \
    } \
    return __cmock_real_##c##_##n(cmock_a1, cmock_a2, cmock_a3, cmock_a4); \
} \

#define CMOCK_MOCK_FUNCTION5(c, n, F) \
static GMOCK_RESULT_(, F) (*__cmock_real_##c##_##n)(GMOCK_ARG_(, 1, \
    F) cmock_a1, GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
    GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5) = \
 (GMOCK_RESULT_(, F) (*)(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
     F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
     GMOCK_ARG_(, 5, F) cmock_a5))cmock_lookup(#n); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5) { \
    c *mock = c::cmock_get_instance(); \
    if (mock != NULL) { \
        return mock->n(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5); \
    } \
	\
    if (__cmock_real_##c##_##n == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found. Neither mock nor real function is present."; \
        throw std::logic_error(msg.str()); \
    } \
    return __cmock_real_##c##_##n(cmock_a1, cmock_a2, cmock_a3, cmock_a4, \
        cmock_a5); \
} \

#define CMOCK_MOCK_FUNCTION6(c, n, F) \
static GMOCK_RESULT_(, F) (*__cmock_real_##c##_##n)(GMOCK_ARG_(, 1, \
    F) cmock_a1, GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
    GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, \
    F) cmock_a6) = \
 (GMOCK_RESULT_(, F) (*)(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
     F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
     GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, \
     F) cmock_a6))cmock_lookup(#n); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6) { \
    c *mock = c::cmock_get_instance(); \
    if (mock != NULL) { \
        return mock->n(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
            cmock_a6); \
    } \
	\
    if (__cmock_real_##c##_##n == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found. Neither mock nor real function is present."; \
        throw std::logic_error(msg.str()); \
    } \
    return __cmock_real_##c##_##n(cmock_a1, cmock_a2, cmock_a3, cmock_a4, \
        cmock_a5, cmock_a6); \
} \

#define CMOCK_MOCK_FUNCTION7(c, n, F) \
static GMOCK_RESULT_(, F) (*__cmock_real_##c##_##n)(GMOCK_ARG_(, 1, \
    F) cmock_a1, GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
    GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, \
    F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7) = \
 (GMOCK_RESULT_(, F) (*)(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
     F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
     GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, \
     7, F) cmock_a7))cmock_lookup(#n); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7) { \
    c *mock = c::cmock_get_instance(); \
    if (mock != NULL) { \
        return mock->n(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
            cmock_a6, cmock_a7); \
    } \
	\
    if (__cmock_real_##c##_##n == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found. Neither mock nor real function is present."; \
        throw std::logic_error(msg.str()); \
    } \
    return __cmock_real_##c##_##n(cmock_a1, cmock_a2, cmock_a3, cmock_a4, \
        cmock_a5, cmock_a6, cmock_a7); \
} \

#define CMOCK_MOCK_FUNCTION8(c, n, F) \
static GMOCK_RESULT_(, F) (*__cmock_real_##c##_##n)(GMOCK_ARG_(, 1, \
    F) cmock_a1, GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
    GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, \
    F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, GMOCK_ARG_(, 8, \
    F) cmock_a8) = \
 (GMOCK_RESULT_(, F) (*)(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
     F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
     GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, \
     7, F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8))cmock_lookup(#n); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8) { \
    c *mock = c::cmock_get_instance(); \
    if (mock != NULL) { \
        return mock->n(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
            cmock_a6, cmock_a7, cmock_a8); \
    } \
	\
    if (__cmock_real_##c##_##n == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found. Neither mock nor real function is present."; \
        throw std::logic_error(msg.str()); \
    } \
    return __cmock_real_##c##_##n(cmock_a1, cmock_a2, cmock_a3, cmock_a4, \
        cmock_a5, cmock_a6, cmock_a7, cmock_a8); \
} \

#define CMOCK_MOCK_FUNCTION9(c, n, F) \
static GMOCK_RESULT_(, F) (*__cmock_real_##c##_##n)(GMOCK_ARG_(, 1, \
    F) cmock_a1, GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
    GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, \
    F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8, \
    GMOCK_ARG_(, 9, F) cmock_a9) = \
 (GMOCK_RESULT_(, F) (*)(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
     F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
     GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, \
     7, F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, \
     F) cmock_a9))cmock_lookup(#n); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, \
    F) cmock_a9) { \
    c *mock = c::cmock_get_instance(); \
    if (mock != NULL) { \
        return mock->n(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
            cmock_a6, cmock_a7, cmock_a8, cmock_a9); \
    } \
	\
    if (__cmock_real_##c##_##n == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found. Neither mock nor real function is present."; \
        throw std::logic_error(msg.str()); \
    } \
    return __cmock_real_##c##_##n(cmock_a1, cmock_a2, cmock_a3, cmock_a4, \
        cmock_a5, cmock_a6, cmock_a7, cmock_a8, cmock_a9); \
} \

#define CMOCK_MOCK_FUNCTION10(c, n, F) \
static GMOCK_RESULT_(, F) (*__cmock_real_##c##_##n)(GMOCK_ARG_(, 1, \
    F) cmock_a1, GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
    GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, \
    F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8, \
    GMOCK_ARG_(, 9, F) cmock_a9, GMOCK_ARG_(, 10, F) cmock_a10) = \
 (GMOCK_RESULT_(, F) (*)(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
     F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
     GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, \
     7, F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, \
     F) cmock_a9, GMOCK_ARG_(, 10, F) cmock_a10))cmock_lookup(#n); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, F) cmock_a9, \
    GMOCK_ARG_(, 10, F) cmock_a10) { \
    c *mock = c::cmock_get_instance(); \
    if (mock != NULL) { \
        return mock->n(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
            cmock_a6, cmock_a7, cmock_a8, cmock_a9, cmock_a10); \
    } \
	\
    if (__cmock_real_##c##_##n == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found. Neither mock nor real function is present."; \
        throw std::logic_error(msg.str()); \
    } \
    return __cmock_real_##c##_##n(cmock_a1, cmock_a2, cmock_a3, cmock_a4, \
        cmock_a5, cmock_a6, cmock_a7, cmock_a8, cmock_a9, cmock_a10); \
} \

#endif // CMOCK_INCLUDE_CMOCK_CMOCK_FUNCTION_CLASS_MOCKERS_H_
