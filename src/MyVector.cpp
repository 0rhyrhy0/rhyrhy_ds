#include "../headers/MyVector.h"
#include <algorithm> // copy, min

MyVector::MyVector(int size) : size(size), count(0) {
    arr = new int[size];
}

MyVector::MyVector(std::initializer_list<int> init)
    : size(power_of_2_minimum(init.size())), count(init.size())
{
    arr = new int[size];
    std::copy(init.begin(), init.end(), arr);
}

MyVector::MyVector(const MyVector& other) : size(other.size), count(other.count) {
    arr = new int[size];
    std::copy(other.begin(), other.end(), arr);
}

MyVector::MyVector(MyVector&& other) noexcept
    : arr(other.arr), size(other.size), count(other.count)
{
    other.size = 0;
    other.count = 0;
    other.arr = nullptr;
}

MyVector::~MyVector() {
    delete[] arr;
}

void MyVector::resize(size_t new_size) {
    if(size == new_size) return;

    int* new_arr = new int[new_size];
    std::copy(arr, arr + std::min(size, new_size), new_arr); // copy proper amount
    delete[] arr;
    arr = new_arr;
    size = new_size;

    if (count > new_size) {
        count = new_size;
    }
}

MyVector& MyVector::push(int value) {
    if(count == size) {
        resize(size*2);
    }

    arr[count++] = value;

    return *this;
}

int MyVector::pop_back() {
    int value = arr[--count];

    if ( (size > 8) && (count <= size/2) ) { // minimum size is 8
        resize(size/2);
    }

    return value;
}

bool MyVector::contains(int value) const {
    for(int num : *this) {
        if(num == value) {
            return true;
        }
    }

    return false;
}

MyVector& MyVector::remove(int value) {
    for(size_t i=0 ; i<count ; i++) {
        if(arr[i] == value) {
            erase(i);
            return *this;
        }
    }
    throw std::logic_error("Value was not found.");
}

MyVector& MyVector::erase(size_t idx) {
    if(idx >= count) {
        throw std::out_of_range("Index is out of range.");
    }

    for(size_t i=idx ; i<count-1 ; i++) {
        arr[i] = arr[i+1];
    }
    count--;

    return *this;
}

int& MyVector::at(size_t idx) {
    if (idx >= count) {
        throw std::out_of_range("Index is out of range");
    }
    return arr[idx];
}

const int& MyVector::at(size_t idx) const {
    if (idx >= count) {
        throw std::out_of_range("Index is out of range");
    }
    return arr[idx];
}

size_t MyVector::power_of_2_minimum(size_t num) const {
    size_t ans = 4;
    while(ans < num) {
        ans <<= 1;
    }
    return ans;
}

std::ostream& operator<<(std::ostream& os, const MyVector& v) {
    os << '{';
    if (!v.is_empty()) {
        os << v[0];
        for (size_t i = 1; i < v.get_count(); i++) {
            os << ", " << v[i];
        }
    }
    os << '}';
    return os;
}
