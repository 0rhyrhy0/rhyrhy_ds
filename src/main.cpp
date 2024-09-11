#include "../headers/headers.h"

int main()
{
    MyVector v{5, 3, 4, 2};
    // MyVector v;
    const MyVector v2{1, 3, 6, 9, 12};

    cout << "My Vector " << (v.is_empty() ? "is empty" : "is not empty") << endl;
    cout << "My Vector " << (v.contains(1) ? "contains 1" : "doesn't contain 1") << endl;
    cout << "My Vector2 " << (v2.is_empty() ? "is empty" : "is not empty") << endl;
    cout << "My Vector2 " << (v2.contains(1) ? "contains 1" : "doesn't contain 1") << endl;

    cout << v << endl << v2 << endl;

    cout << v[2] << ' ' << v2[2] << endl;
    cout << v.get_size() << ' ' << v2.get_size() << endl;
    cout << v.get_count() << ' ' << v2.get_count() << endl;
}