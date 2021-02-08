## Peeking Iterator

Given an Iterator class interface with methods: `next()` and `hasNext()`, design and implement a PeekingIterator that support the `peek()` operation -- it essentially peek() at the element that will be returned by the next call to next().

**Example:**

```
Assume that the iterator is initialized to the beginning of the list: [1,2,3].

Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2. 
You call next() the final time and it returns 3, the last element. 
Calling hasNext() after that should return false.
```

**Follow up**: How would you extend your design to be generic and work with all types, not just integer?

#### 判断是否被 peek()：

​		本题给定一个迭代器类的接口，接口包含两个方法： next() 和 hasNext()。需要我们设计并实现一个支持 peek() 操作的顶端迭代器 -- 其本质就是把原本应由 next() 方法返回的元素 peek() 出来。

​		其实 peek() 操作不会像 next() 一样取出元素，而是在不操作迭代器的情况下 “ 提前偷看 ” 了下一个元素是什么，所以当我们不执行 next() 时，不管你执行多少次 peek() 都是返回同一个元素，也就是下一个被 next() 取出的元素。

​		有了以上的理解，我们就知道不需要开一个数组或者队列来保存多次 peek() 出来的元素，只需要一个常数空间进行 peek() 的维护。我们初始化判断是否被 peek() 的变量 ispeek = false。

​		在进行 peek() 时，首先判断当前是否已经被 peek() 过，如果被 peek() 过（ispeek = true），那么直接返回之前 peek() 时保存的下一个元素值 val。如果没有被 peek() 过（ispeek = false），执行迭代器的 next() 取出下一个元素的值并且保存在 val 中，并且标记当前被 peek() 过（ispeek = true）。

​		在进行 next() 时，首先判断当前是否已经被 peek() 过，如果被 peek() 过（ispeek = true），返回保存的下一个元素值 val，并且标记当前没有被 peek() 过（ispeek = false）。如果没有被 peek() 过（ispeek = false），执行迭代器的 next() 取出下一个元素并且返回。

​		在进行 hasNext() 时，需要同时判断 ispeek 和迭代器的 hasNext()，因为此时下一个元素有可能因为 peek() 操作保存在下一个元素值 val 中。

​		具体代码如下：

```c++
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    bool ispeek;
    int val;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    ispeek = false;
        val = 0;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!ispeek)
            val = Iterator::next();
            ispeek = true;
        return val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(ispeek){
            ispeek = false;
            return val;
        }
	    return Iterator::next();
	}
	
	bool hasNext() const {
	    return ispeek || Iterator::hasNext();
	}
};
```

