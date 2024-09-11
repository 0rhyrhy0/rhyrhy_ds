#ifndef __MY_VECTOR__
#define __MY_VECTOR__
#include <initializer_list>
#include <iostream>
#include <cstdio> // size_t

class MyVector {
public:
    /**
     * @brief Construct a new MyVector with the specified size.
     * Power of 2 sizes are recommended (2, 4, 8, ...).
     * @param size Initial size of the vector's storage. Defaults to 8.
     */
    MyVector(int size = 8);

    /**
     * @brief Construct a new MyVector from an initializer list.
     * @param init Initializer list to initialize the vector's elements.
     */
    MyVector(std::initializer_list<int> init);

    /**
     * @brief Copy constructor.
     * @param other The MyVector to copy from.
     */
    MyVector(const MyVector& other);

    /**
     * @brief Move constructor.
     * @param other The MyVector to move from.
     */
    MyVector(MyVector&& other) noexcept;

    /**
     * @brief Push `value` at the end of the vector.
     * @param value The value to be pushed.
     * @return Reference to the updated MyVector.
     */
    MyVector& push(int value);

    /**
     * @brief Remove the last element, returning the value.
     * @return The value that was removed.
     */
    int pop_back();

    /**
     * @brief Check if the vector contains `value`.
     * @param value The value to be checked.
     * @return true if the vector contains `value`, false otherwise.
     */
    bool contains(int value) const;

    /**
     * @brief Search for the value, and erase it if it exists.
     * @param value The value to be removed.
     * @return Reference to the updated MyVector.
     * @throws std::logic_error if the value is not in arr.
     */
    MyVector& remove(int value);

    /**
     * @brief Remove `arr[idx]`, then rearrange the elements.
     * @param idx The index of the element to be removed.
     * @return Reference to the updated MyVector.
     * @throws std::out_of_range if idx is out of bounds.
     */
    MyVector& erase(size_t idx);

    // Check if the vector is empty.
    bool is_empty() const { return !count; }

    // Return a const iterator to the beginning.
    const int* begin() const { return arr; }

    // Return a const iterator to the end.
    const int* end() const { return arr + count; }

    // Return a modifiable iterator to the beginning.
    int* begin() { return arr; }

    // Return a modifiable iterator to the end.
    int* end() { return arr + count; }

    // Get the current element count.
    size_t get_count() const { return count; }

    // Get the current storage size.
    size_t get_size() const { return size; }

    // Access the element at the specified index (non-const).
    int& operator[](size_t idx) { return arr[idx]; }

    // Access the element at the specified index (const).
    const int& operator[](size_t idx) const { return arr[idx]; }

    /**
     * @brief Access the element at the specified index with bounds checking (non-const).
     * @param idx The index of the element to access.
     * @return Reference to the element at the specified index.
     * @throws std::out_of_range if idx is out of bounds.
     */
    int& at(size_t idx);

    /**
     * @brief Access the element at the specified index with bounds checking (const).
     * @param idx The index of the element to access.
     * @return Reference to the element at the specified index.
     * @throws std::out_of_range if idx is out of bounds.
     */
    const int& at(size_t idx) const;

private:
    int* arr;
    size_t size;
    size_t count;

    /**
     * @brief Resize the internal storage and modify `size`.
     * If the new size is smaller, the elements beyond `new_size` are discarded.
     * @param new_size The new size for the internal storage.
     */
    void resize(size_t new_size);

    /**
     * @brief (For initialization only) Calculate the minimum power of 2 greater than or equal to `num`.
     * @param num The input number.
     * @return The smallest power of 2 greater than or equal to `num`.
     */
    size_t power_of_2_minimum(size_t num) const;

    friend std::ostream& operator<<(std::ostream& os, const MyVector& v);
};


#endif
