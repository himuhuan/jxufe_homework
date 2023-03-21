#ifndef SEQLIST_HPP
#define SEQLIST_HPP

#include <cstddef>
#include <iterator>
#include <iostream>


/**
 * @brief ˳����ģ��ʵ��
 * @tparam T ģ��T��������CopyAssignable �� CopyConstructible.
*/
template <typename T> class SeqList {
public:
	/**
	 * @brief ���캯��
	 * @param default_size
	 * Ĭ������Ϊ10, ��Ԫ�ظ���������ʱ, �ڲ���������m_capacity���ռ�.
	 * ����Ŀǰ�������� capacity() �õ�, Ҳ��ʹ��resize����.
	 * capacity һ���������ݾ��޷���С, ����ʹ��resize
	*/
	explicit SeqList(size_t default_size = 10)
		: m_capacity(default_size), m_size(0) {
		m_raw = new T[m_capacity];
	}
	
	~SeqList() {
		delete[] m_raw;
	}
	
	/**
	 * @brief ��pos����Ԫ��
	 * @param pos 
	 * ���pos >= size(), �൱�ڵ���push_back. ����ԭ����posλ���Լ�֮���Ԫ�ر��ƶ�����һλ��
	 * @param t Ҫ�����Ԫ��
	 * @return �����λ��
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
	 * @brief ��vector::push_back��Ϊ����һ��
	 * @param t Ҫ�����Ԫ��
	 * @return �����λ��
	*/
	size_t push_back(const T& t) {
        if (m_size + 1 > m_capacity)
            _expand_capacity(m_capacity);
        m_raw[m_size++] = t;
        return m_size - 1;
    }

	/**
	 * @brief ��������Ϊһ��
	*/
	T& operator[](size_t n) {
        return m_raw[n];
    }
    
	const T& operator[](size_t n) const noexcept {
        return m_raw[n];
    }

	/**
	 * @return ����Ҳ������.
	*/
	/**
	 * C++ 17: C++ attribute: nodiscard
	 * see also: https://en.cppreference.com/w/cpp/language/attributes/nodiscard
	 */
	[[nodiscard]] size_t size() const noexcept { return m_size;}
	[[nodiscard]] size_t capacity() const noexcept { return m_capacity;}
	
	/**
	 * @brief ����ԭʼָ��, ����ʹ��
	*/
	T* data() noexcept {
        return m_raw;
	}

	/**
	 * @brief ���ش�begin��ʼ�ĵ�һ��ʹ��pred�ж�ΪTrue��Ԫ������
	 * @return ��һ��ʹ��pred�ж�ΪTrue��Ԫ������
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
	 * @brief �ȼ��� find_if(0, this->size(), p)
	*/
	template <typename Pred>
	size_t find_if(Pred p) const { return find_if(0, this->size(), p); }

	/**
	 * @brief �ȼ��� find_if(0, this->size(), [=](const T & t) { return t == target; })
	*/
	size_t find(const T & target) const
    {
        return find_if(0, this->size(), [=](const T & t) {
            return t == target;
        });
    }

	/**
	 * @brief ɾ��indexλ�õ�Ԫ��
	 * @param index Ҫɾ����λ��
	*/
	void remove(size_t index) {
        for (size_t i = index + 1; i < m_size; i++)
            m_raw[i - 1] = m_raw[i];
        m_size--;
    }

	/**
	 * @brief ɾ������Ԫ��
	*/
	void clear() {
        m_size = 0;
    }

	/**
	 * @brief �ı���������
	 * @param n n > size() �������, n < size() ��n-1֮�������Ԫ�ؽ����Ƴ�.
	*/
	void resize(size_t n) {
        _expand_capacity(n - m_size);
    }
    
    // ģ��STL: unsafe!!
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
