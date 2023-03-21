#ifndef SEQLIST_HPP
#define SEQLIST_HPP

#include <cstddef>
#include <iterator>
#include <iostream>


/**
 * @brief 顺序表的模板实现
 * @tparam T 模板T必须满足CopyAssignable 和 CopyConstructible.
*/
template <typename T> class SeqList {
public:
	/**
	 * @brief 构造函数
	 * @param default_size
	 * 默认容量为10, 当元素个数大于它时, 内部数组扩容m_capacity个空间.
	 * 容器目前容量可由 capacity() 得到, 也可使用resize调整.
	 * capacity 一旦发生扩容就无法缩小, 除非使用resize
	*/
	explicit SeqList(size_t default_size = 10)
		: m_capacity(default_size), m_size(0) {
		m_raw = new T[m_capacity];
	}
	
	~SeqList() {
		delete[] m_raw;
	}
	
	/**
	 * @brief 在pos插入元素
	 * @param pos 
	 * 如果pos >= size(), 相当于调用push_back. 否则原本在pos位置以及之后的元素被移动到下一位置
	 * @param t 要插入的元素
	 * @return 插入的位置
	*/
	size_t insert(size_t pos, const T& t) {
		if (pos >= m_size) {
			push_back(t);
			return m_size - 1;
		}
		if (m_size + 1 > m_capacity)
            _expand_capacity(m_capacity);
        for (size_t i = m_size; i >= pos; i--)
            m_raw[i] = m_raw[i - 1];
		m_raw[pos] = t;
		m_size++;
		return pos;
	}

	/**
	 * @brief 与vector::push_back行为基本一致
	 * @param t 要插入的元素
	 * @return 插入的位置
	*/
	size_t push_back(const T& t) {
        if (m_size + 1 > m_capacity)
            _expand_capacity(m_capacity);
        m_raw[m_size++] = t;
        return m_size - 1;
    }

	/**
	 * @brief 与数组行为一致
	*/
	T& operator[](size_t n) {
        return m_raw[n];
    }
    
	const T& operator[](size_t n) const noexcept {
        return m_raw[n];
    }

	/**
	 * @return 这个我不想介绍.
	*/
	/**
	 * C++ 17: C++ attribute: nodiscard
	 * see also: https://en.cppreference.com/w/cpp/language/attributes/nodiscard
	 */
	[[nodiscard]] size_t size() const noexcept { return m_size;}
	[[nodiscard]] size_t capacity() const noexcept { return m_capacity;}
	
	/**
	 * @brief 返回原始指针, 避免使用
	*/
	T* data() noexcept {
        return m_raw;
	}

	/**
	 * @brief 返回从begin开始的第一个使得pred判断为True的元素索引
	 * @return 第一个使得pred判断为True的元素索引
	*/
	template <typename Pred>
	size_t find_if(size_t begin, size_t end, Pred p) const {
        for (auto i = begin; i < end; i++) {
            if (p(m_raw[i]))
                return i;
        }
        
        return (-1);
    }

	/**
	 * @brief 等价于 find_if(0, this->size(), p)
	*/
	template <typename Pred>
	size_t find_if(Pred p) const { return find_if(0, this->size(), p); }

	/**
	 * @brief 等价于 find_if(0, this->size(), [=](const T & t) { return t == target; })
	*/
	size_t find(const T & target) const
    {
        return find_if(0, this->size(), [=](const T & t) {
            return t == target;
        });
    }

	/**
	 * @brief 删除index位置的元素
	 * @param index 要删除的位置
	*/
	void remove(size_t index) {
        for (size_t i = index + 1; i < m_size; i++)
            m_raw[i - 1] = m_raw[i];
        m_size--;
    }

	/**
	 * @brief 删除所有元素
	*/
	void clear() {
        m_size = 0;
    }

	/**
	 * @brief 改变容器容量
	 * @param n n > size() 完成扩容, n < size() 在n-1之后的所有元素将被移除.
	*/
	void resize(size_t n) {
        _expand_capacity(n - m_size);
    }
    
    // 模拟STL: unsafe!!
    int *begin() { return m_raw; }
    int *end() { return m_raw + m_size; }
	
	void display() const {
		std::cout << "{";
		for (int i = 0; i < m_size; i++) {
			std::cout << " " << m_raw[i] << " ";
		}
		std::cout << "}\n";
	}

private:
    
    void _expand_capacity(int expand) {
        m_capacity = m_size + expand;
        T *buf = new T[m_capacity];
        for (size_t i = 0; i < m_capacity; i++)
            buf[i] = m_raw[i];
		if (m_capacity < m_size)
			m_size = m_capacity;
        delete[] m_raw;
        m_raw = buf;
    }
    
	size_t m_size;
	size_t m_capacity;
	T* m_raw;
};

#endif
