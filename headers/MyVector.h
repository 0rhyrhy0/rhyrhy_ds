#ifndef __MY_VECTOR__
#define __MY_VECTOR__
#include <initializer_list>
#include <iostream>
#include <cstdio> // size_t

class MyVector {
public:
    // power of 2 recommended (2, 4, 8, ...)
    MyVector(int size = 8);
    MyVector(std::initializer_list<int> init);
    MyVector(const MyVector& other);
    MyVector(MyVector&& other) noexcept;

    /**
     * @brief Push `value` at the end of the vector.
     * @param value the value to be pushed
     */
    MyVector& push(int value);

    /**
     * @brief remove the last element, returning the value.
     * @return the value which is removed
     */
    int pop_back();

    /**
     * @brief check if the vector contains `value`
     * @param value the value to be checked
     * @return true if the vector contains `value`, else false
     */
    bool contains(int value) const;

    /**
     * @brief search for the value, and erase it if exists
     * @param value the value to be removed
     */
    MyVector& remove(int value);

    /**
     * @brief remove `arr[idx]`, then rearrange the elements
     * @param idx the index to be removed
     */
    MyVector& erase(size_t idx);

    bool is_empty() const            { return !count;      }
    const int* begin() const         { return arr;         }
    const int* end() const           { return arr + count; }
    int* begin()                     { return arr;         }
    int* end()                       { return arr + count; }
    int& operator[](size_t idx)      { return arr[idx];    }
    int operator[](size_t idx) const { return arr[idx];    }
    size_t get_count() const         { return count;       }
    size_t get_size() const          { return size;        }

private:
    int* arr;
    size_t size;
    size_t count;

    /**
     * @brief resize the `arr` and modify `size`.
     * @param new_size new size for `arr` to be resized to.
     */
    void resize(size_t new_size);

    /**
     * @brief (for initializing only) calculates minimum 2^n >= `num`
     * @param num 
     * @return minimum value as written.
     */
    size_t power_of_2_minimum(size_t num) const;

    friend std::ostream& operator<<(std::ostream& os, const MyVector& v);
};

#endif
