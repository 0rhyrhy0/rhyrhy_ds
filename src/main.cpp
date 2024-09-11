#include "../headers/headers.h"

int main()
{
    // Basic Vector testcases
    MyVector v;
    v.push(3).push(4).push(10);

    const MyVector v2{1, 3, 6, 9, 12};

    cout << "My Vector " << (v.is_empty() ? "is empty" : "is not empty") << endl;
    cout << "My Vector " << (v.contains(1) ? "contains 1" : "doesn't contain 1") << endl;
    cout << "My Vector2 " << (v2.is_empty() ? "is empty" : "is not empty") << endl;
    cout << "My Vector2 " << (v2.contains(1) ? "contains 1" : "doesn't contain 1") << endl;

    cout << v << endl << v2 << endl;

    cout << v[2] << ' ' << v2[2] << endl;
    cout << v.get_size() << ' ' << v2.get_size() << endl;
    cout << v.get_count() << ' ' << v2.get_count() << endl;

    cout << "-----------------------" << endl;

    // Error throw & catch
    MyVector error01;
    const MyVector error02;
    try {
        error01.erase(10);
    } catch(const exception& e) { // out_of_range
        cerr << e.what() << endl;
    }

    try {
        error01.remove(10);
    } catch(const exception& e) { // logic_error (value not found)
        cerr << e.what() << endl;
    }

    try {
        error01.at(100)++;
    } catch(const exception& e) { // out_of_range
        cerr << e.what() << endl;
    }

    try {
        int x = error02.at(100);
        cout << x;
    } catch(const exception& e) { // out_of_range
        cerr << e.what() << endl;
    }
}