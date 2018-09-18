/*
MIT License

Copyright (c) 2018 Lucas Kleiss (LAK132)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <cstddef>

#ifndef DEBUG
#   ifdef NDEBUG
#       define DEBUG(x)
#   else
#       include <iostream>
#       define DEBUG(x) std::cout << __FILE__ << "(" << std::dec << __LINE__ << ") " << x
#   endif
#endif

#ifndef LAK_TYPE_STRING_H
#define LAK_TYPE_STRING_H

namespace lak
{
    template<typename STR>
    static constexpr const size_t c_strlen(STR str, size_t count = 0)
    {
        return (*str == '\0') ? count : c_strlen(str + 1, count + 1);
    }

    template<char ...str>
    struct type_string
    {
        static constexpr const char toString[sizeof...(str)+1] = {str..., '\0'};
    };
    template<char ...str> 
    constexpr const char type_string<str...>::toString[sizeof...(str)+1];

    template<typename TYPE, typename NAME>
    struct bound_type_string;
    template<typename TYPE, char ...str>
    struct bound_type_string<TYPE, type_string<str...>>
    {
        using type_t = TYPE;
        using name_t = type_string<str...>;
    };

    template<size_t count, size_t ...indices>
    struct templ_range
    {
        using result = typename templ_range<count - 1, count - 1, indices...>::result;
    };
    template<size_t ...indices>
    struct templ_range<size_t(0), indices...>
    {
        using result = templ_range<size_t(0), indices...>;
    };

    template<template<size_t...> typename str, typename indc>
    struct type_string_builder;
    template<template<size_t...> typename str, size_t ...indices>
    struct type_string_builder<str, templ_range<0, indices...>>
    {
        using result = str<indices...>;
    };

    #define TSTRDEF(str) template<size_t...ind> using cstrdef_ ## str = type_string<#str[ind]...>

    #define TSTR(str) type_string_builder<cstrdef_ ## str, templ_range<c_strlen(#str)>::result>::result
}

#endif // LAK_TYPE_STRING_H