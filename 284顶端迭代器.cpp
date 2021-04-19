#include <vector>

using namespace std;

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        _next = Iterator::hasNext();
        if (Iterator::hasNext()) {
            val = Iterator::next();
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return val;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int cur = val;
        _next = Iterator::hasNext();
        if (Iterator::hasNext()) {
            val = Iterator::next();
        }

        return cur;
    }

    bool hasNext() const {
        return _next;
    }

private:
    int val = 0;
    bool _next = false;
};