/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <memory>
#include <utility>

#include "nkr/maybe_pointer_t.h"

namespace nkr {

    template <typename T>
    inline none_t<T*>::none_t()
    {
    }

    template <typename T>
    inline none_t<T*>::none_t(const none_t& other)
    {
    }

    template <typename T>
    inline none_t<T*>::none_t(none_t&& other) noexcept
    {
    }

    template <typename T>
    inline none_t<T*>& none_t<T*>::operator =(const none_t& other)
    {
        return *this;
    }

    template <typename T>
    inline none_t<T*>& none_t<T*>::operator =(none_t&& other) noexcept
    {
        return *this;
    }

    template <typename T>
    inline none_t<T*>::~none_t()
    {
    }

    template <typename T>
    inline none_t<T*>::operator bool_t() const
    {
        return false;
    }

    template <typename T>
    inline none_t<T*>::operator pointer_t()
    {
        return nullptr;
    }

    template <typename T>
    inline none_t<T*>::operator const pointer_t() const
    {
        return nullptr;
    }

    template <typename T>
    inline bool_t none_t<T*>::operator !() const
    {
        return true;
    }

    template <typename T>
    inline typename none_t<T*>::pointer_t none_t<T*>::operator ()()
    {
        return nullptr;
    }

    template <typename T>
    inline typename const none_t<T*>::pointer_t none_t<T*>::operator ()() const
    {
        return nullptr;
    }

    template <typename T>
    inline maybe_t<T*>::maybe_t() :
        pointer(nullptr)
    {
    }

    template <typename T>
    inline maybe_t<T*>::maybe_t(pointer_t pointer) :
        pointer(pointer)
    {
    }

    template <typename T>
    inline maybe_t<T*>::maybe_t(const maybe_t& other) :
        pointer(other.pointer)
    {
    }

    template <typename T>
    inline maybe_t<T*>::maybe_t(maybe_t&& other) noexcept :
        pointer(std::exchange(other.pointer, nullptr))
    {
    }

    template <typename T>
    inline maybe_t<T*>& maybe_t<T*>::operator =(const maybe_t& other)
    {
        if (this != std::addressof(other)) {
            this->pointer = other.pointer;
        }
        return *this;
    }

    template <typename T>
    inline maybe_t<T*>& maybe_t<T*>::operator =(maybe_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->pointer = std::exchange(other.pointer, nullptr);
        }
        return *this;
    }

    template <typename T>
    inline maybe_t<T*>& maybe_t<T*>::operator =(pointer_t other)
    {
        this->pointer = other;
        return *this;
    }

    template <typename T>
    inline maybe_t<T*>::~maybe_t()
    {
        this->pointer = nullptr;
    }

    template <typename T>
    inline maybe_t<T*>::operator bool_t() const
    {
        return this->pointer != nullptr;
    }

    template <typename T>
    inline maybe_t<T*>::operator pointer_t&()
    {
        return this->pointer;
    }

    template <typename T>
    inline maybe_t<T*>::operator const pointer_t&() const
    {
        return this->pointer;
    }

    template <typename T>
    inline bool_t maybe_t<T*>::operator !() const
    {
        return !static_cast<bool_t>(*this);
    }

    template <typename T>
    inline typename maybe_t<T*>::pointer_t maybe_t<T*>::operator ()()
    {
        return this->pointer;
    }

    template <typename T>
    inline typename const maybe_t<T*>::pointer_t maybe_t<T*>::operator ()() const
    {
        return this->pointer;
    }

    template <typename T>
    inline typename maybe_t<T*>::pointer_t maybe_t<T*>::operator ->()
    {
        return this->pointer;
    }

    template <typename T>
    inline typename const maybe_t<T*>::pointer_t maybe_t<T*>::operator ->() const
    {
        return this->pointer;
    }

    template <typename T>
    inline typename maybe_t<T*>::pointer_t* maybe_t<T*>::operator &()
    {
        return &this->pointer;
    }

    template <typename T>
    inline typename const maybe_t<T*>::pointer_t* maybe_t<T*>::operator &() const
    {
        return &this->pointer;
    }

    template <typename T>
    inline typename maybe_t<T*>::value_t& maybe_t<T*>::operator *()
    {
        return *this->pointer;
    }

    template <typename T>
    inline typename const maybe_t<T*>::value_t& maybe_t<T*>::operator *() const
    {
        return *this->pointer;
    }

    template <typename T>
    inline typename maybe_t<T*>::value_t& maybe_t<T*>::operator [](size_t index)
    {
        return this->pointer[index];
    }

    template <typename T>
    inline typename const maybe_t<T*>::value_t& maybe_t<T*>::operator [](size_t index) const
    {
        return this->pointer[index];
    }

    template <typename T>
    inline some_t<T*>::some_t(pointer_t pointer) :
        pointer(pointer)
    {
    }

    template <typename T>
    inline some_t<T*>::some_t(const some_t& other) :
        pointer(other.pointer)
    {
    }

    template <typename T>
    inline some_t<T*>::some_t(some_t&& other) noexcept :
        pointer(std::exchange(other.pointer, nullptr))
    {
    }

    template <typename T>
    inline some_t<T*>& some_t<T*>::operator =(const some_t& other)
    {
        if (this != std::addressof(other)) {
            this->pointer = other.pointer;
        }
        return *this;
    }

    template <typename T>
    inline some_t<T*>& some_t<T*>::operator =(some_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->pointer = std::exchange(other.pointer, nullptr);
        }
        return *this;
    }

    template <typename T>
    inline some_t<T*>& some_t<T*>::operator =(pointer_t other)
    {
        this->pointer = other;
        return *this;
    }

    template <typename T>
    inline some_t<T*>::~some_t()
    {
        this->pointer = nullptr;
    }

    template <typename T>
    inline some_t<T*>::operator bool_t() const
    {
        return this->pointer != nullptr;
    }

    template <typename T>
    inline some_t<T*>::operator pointer_t&()
    {
        return this->pointer;
    }

    template <typename T>
    inline some_t<T*>::operator const pointer_t&() const
    {
        return this->pointer;
    }

    template <typename T>
    inline bool_t some_t<T*>::operator !() const
    {
        return !static_cast<bool_t>(*this);
    }

    template <typename T>
    inline typename some_t<T*>::pointer_t some_t<T*>::operator ()()
    {
        return this->pointer;
    }

    template <typename T>
    inline typename const some_t<T*>::pointer_t some_t<T*>::operator ()() const
    {
        return this->pointer;
    }

    template <typename T>
    inline typename some_t<T*>::pointer_t some_t<T*>::operator ->()
    {
        return this->pointer;
    }

    template <typename T>
    inline typename const some_t<T*>::pointer_t some_t<T*>::operator ->() const
    {
        return this->pointer;
    }

    template <typename T>
    inline typename some_t<T*>::pointer_t* some_t<T*>::operator &()
    {
        return &this->pointer;
    }

    template <typename T>
    inline typename const some_t<T*>::pointer_t* some_t<T*>::operator &() const
    {
        return &this->pointer;
    }

    template <typename T>
    inline typename some_t<T*>::value_t& some_t<T*>::operator *()
    {
        return *this->pointer;
    }

    template <typename T>
    inline typename const some_t<T*>::value_t& some_t<T*>::operator *() const
    {
        return *this->pointer;
    }

    template <typename T>
    inline typename some_t<T*>::value_t& some_t<T*>::operator [](size_t index)
    {
        return this->pointer[index];
    }

    template <typename T>
    inline typename const some_t<T*>::value_t& some_t<T*>::operator [](size_t index) const
    {
        return this->pointer[index];
    }

}
