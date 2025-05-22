export module Math:Types;

export
{
    /// @brief Equivalent to @c signed @c char.
    using int8_t = signed char;
    /// @brief Equivalent to @c unsigned @c char.
    using uint8_t = unsigned char;

    /// @brief Equivalent to @c signed @c short.
    using int16_t = signed short;
    /// @brief Equivalent to @c unsigned @c short.
    using uint16_t = unsigned short;

    /// @brief Equivalent to @c signed @c int.
    using int32_t = signed int;
    /// @brief Equivalent to @c unsigned @c int.
    using uint32_t = unsigned int;

    /// @brief Equivalent to @c signed @c long @c long.
    using int64_t = signed long long;
    /// @brief Equivalent to @c unsigned @c long @c long.
    using uint64_t = unsigned long long;

    /// @brief Equivalent to @c char.
    ///
    /// We need to manually add this type because it is considered
    /// different to @c int8_t as the latter is the equivalent of @c signed @c char
    /// and not @c char.
    using char_t = char;

    /// @brief Equivalent to @c bool.
    using bool_t = bool;

    /// @brief Equivalent to @c float.
    using float_t = float;
    /// @brief Equivalent to @c double.
    using double_t = double;

    /// @brief Size type. Equivalent to @c uint64_t.
    using size_t = uint64_t;
}
