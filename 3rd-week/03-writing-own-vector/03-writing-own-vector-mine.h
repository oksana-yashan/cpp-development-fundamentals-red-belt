#pragma once

#include <cstdlib>

using namespace std;

template <typename T>
class SimpleVector {
public:
    SimpleVector() = default;
    // Doubling the size needed, as ArrayList in Java
    explicit SimpleVector(size_t size) {
        this->size = size;
        capacity = size * 2;
        data = new T[capacity];
    }

    ~SimpleVector() {
        delete[] data;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + size;
    }

    [[nodiscard]] const T* begin() const {
        return data;
    }

    [[nodiscard]] const T* end() const {
        return data + size;
    }

    [[nodiscard]] size_t Size() const {
        return size;
    }

    [[nodiscard]] size_t Capacity() const {
        return capacity;
    }
    // If no more capacity left, creating tmp array twice large,
    // copying all elements to it, freeing memory and renaming it back.
    // After all, adding another element
    void PushBack(const T& value) {
        if (size == capacity) {
            auto tmp = new T[(capacity += 1) *= 2];
            for (size_t i = 0; i < size; ++i) {
                tmp[i] = data[i];
            }

            delete[] data;
            data = tmp;
        }
        data[++size - 1] = value;
    }

private:
    T* data = nullptr;
    size_t size = 0, capacity = 0;
};
