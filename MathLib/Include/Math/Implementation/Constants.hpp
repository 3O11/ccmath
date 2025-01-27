#ifndef MATHLIB_IMPLEMENTATION_CONSTANTS_HPP
#define MATHLIB_IMPLEMENTATION_CONSTANTS_HPP

#include "Base/Types.hpp"
#include "Base/Concepts.hpp"

namespace Math::Constant::Implementation
{
    using namespace Math::Implementation;

    template <typename T>
    struct Pi final
    {};

    template <>
    struct Pi<float> final
    {
        static constexpr float Value = 3.1415926535897932384626433832795028841971693993751058209749445923f;
    };

    template <>
    struct Pi<double> final
    {
        static constexpr double Value = 3.1415926535897932384626433832795028841971693993751058209749445923;
    };

    template <typename T>
    struct Pi<StrongFloatType<T>> final
    {
        static constexpr StrongFloatType<T> Value = Pi<T>::Value;
    };

    template <typename T>
    struct E final
    {};

    template <>
    struct E<float> final
    {
        static constexpr float Value = 2.7182818284590452353602874713526624977572470936999595749669676277f;
    };

    template <>
    struct E<double> final
    {
        static constexpr double Value = 2.7182818284590452353602874713526624977572470936999595749669676277;
    };

    template <typename T>
    struct E<StrongFloatType<T>> final
    {
        static constexpr StrongFloatType<T> Value = E<T>::Value;
    };

    template <typename T>
    struct Phi final
    {};

    template <>
    struct Phi<float> final
    {
        static constexpr float Value = 1.6180339887498948482045868343656381177203091798057628621354486227f;
    };

    template <>
    struct Phi<double> final
    {
        static constexpr double Value = 1.6180339887498948482045868343656381177203091798057628621354486227;
    };

    template <typename T>
    struct Phi<StrongFloatType<T>> final
    {
        static constexpr StrongFloatType<T> Value = Phi<T>::Value;
    };

    template <typename T>
    struct Sqrt2 final
    {};

    template <>
    struct Sqrt2<float> final
    {
        static constexpr float Value = 1.4142135623730950488016887242096980785696718753769480731766797379f;
    };

    template <>
    struct Sqrt2<double> final
    {
        static constexpr double Value = 1.4142135623730950488016887242096980785696718753769480731766797379;
    };

    template <typename T>
    struct Sqrt2<StrongFloatType<T>> final
    {
        static constexpr StrongFloatType<T> Value = Sqrt2<T>::Value;
    };

    template <typename T>
    struct Sqrt3 final
    {};

    template <>
    struct Sqrt3<float> final
    {
        static constexpr float Value = 1.7320508075688772935274463415058723669428052538103806280558069794f;
    };

    template <>
    struct Sqrt3<double> final
    {
        static constexpr double Value = 1.7320508075688772935274463415058723669428052538103806280558069794;
    };

    template <typename T>
    struct Sqrt3<StrongFloatType<T>> final
    {
        static constexpr StrongFloatType<T> Value = Sqrt3<T>::Value;
    };

    template <typename T>
    struct Sqrt5 final
    {};

    template <>
    struct Sqrt5<float> final
    {
        static constexpr float Value = 2.2360679774997896964091736687312762354406183596115257242708972454f;
    };

    template <>
    struct Sqrt5<double> final
    {
        static constexpr double Value = 2.2360679774997896964091736687312762354406183596115257242708972454;
    };

    template <typename T>
    struct Sqrt5<StrongFloatType<T>> final
    {
        static constexpr StrongFloatType<T> Value = Sqrt5<T>::Value;
    };

    template <typename T>
    struct EqualEpsilon final
    {};

    template <Concept::IntegralType T>
    struct EqualEpsilon<T> final
    {
        static constexpr T Value = T(0);
    };

    template <>
    struct EqualEpsilon<float> final
    {
        static constexpr float Value = 1.0e-6f;
    };

    template <>
    struct EqualEpsilon<double> final
    {
        static constexpr double Value = 1.0e-15;
    };

    template <typename T>
    struct EqualEpsilon<StrongIntegerType<T>> final
    {
        static constexpr StrongIntegerType<T> Value = EqualEpsilon<T>::Value;
    };

    template <typename T>
    struct EqualEpsilon<StrongFloatType<T>> final
    {
        static constexpr StrongFloatType<T> Value = EqualEpsilon<T>::Value;
    };

    template <typename T>
    struct GeometryEpsilon final
    {};

    template <>
    struct GeometryEpsilon<float> final
    {
        static constexpr float Value = 1.0e-3f;
    };

    template <>
    struct GeometryEpsilon<double> final
    {
        static constexpr double Value = 1.0e-6;
    };

    template <typename T>
    struct GeometryEpsilon<StrongFloatType<T>> final
    {
        static constexpr StrongFloatType<T> Value = GeometryEpsilon<T>::Value;
    };
}

#endif //MATHLIB_IMPLEMENTATION_CONSTANTS_HPP
