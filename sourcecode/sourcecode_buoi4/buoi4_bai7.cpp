#include <iostream>
#include <set>
using namespace std;

template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    set<T> res;
    for (T c : b) {
        res.insert(c);
    }
    for (T c : a) {
        res.insert(c);
    }
    return res;
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    set<T> res;
    for (T c : a) {
        if (b.find(c) != b.end()) {
            res.insert(c);
        }
    }
    return res;
}

int main() {
    set<int> a = {1, 2, 3, 5, 7};
    set<int> b = {2, 4, 5, 6, 9};
    set<int> c = set_union(a, b);
    set<int> d = set_intersection(a, b);
    cout << "Union: ";
    for (const int &x : c) {
        cout << x << ' ';
    }
    cout << endl;
    cout << "Intersection: ";
    for (const int &x : d) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}

