#include "Library.h"

template <class T>
class Vector{
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;
        typedef T &reference;
        typedef const T const_reference;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        T* allocate(size_t);
        void deallocate(T*, size_t);
        void construct(T*, const T&);
        void destroy(T*);

        //Member Functions
        Vector(){create(); } // constructor
        explicit Vector(size_type size, const value_type& value = T{}){create (size, value);} //constructor
        template <class Input>
        Vector(Input first, Input last){create (first, last);} // constructor
        Vector(Vector &&v){
            create(v.begin(), v.end());
            v.swap(*this);
        }
        Vector(std::initializer_list<value_type> &init){ //constructor
            create(init.begin(), init.end());
        }


        Vector(const Vector& v){create(v.begin(), v.end());} //  constructor
        Vector &operator=(const Vector& it){                 //priskyrimo operatorius
        if(&it!=this){
            uncreate();
            create(it.begin(), it.end());
        }
        return *this;
        }

        Vector &operator=(Vector&& it){
                if(&it !=this){
                    uncreate();
                    create(it.begin(), it.end());
                }
                return *this;
        }

        Vector &operator=(std::initializer_list<value_type> ilist){
            if(&ilist!=this){
                uncreate();
                create(ilist.begin(), ilist.end());
            }
            return *this;
        }

        void assign(size_type count, const value_type &value){
            uncreate();
            create(count, value);
        }

        template<class Input>
        void assign(Input first, Input last){
            uncreate();
            create(first, last);
        }

        void assign(std::initializer_list<value_type> ilist){
            uncreate();
            create(ilist);
        }
        
        ~Vector(){uncreate();}//destruktorius

        //element access
        T& operator[](size_type i) {return data[i];}
        const T& operator[](size_type i) const {return data[i];}
        reference at(size_type pos){
            if(pos<0 || pos>=size()){
                throw std::out_of_range("Index out of range");
            }
            return data[pos];
        }

        const_reference at(size_type pos) const{
            if(pos<0 || pos>=size()){
                throw std::out_of_range("Index out of range");
            }
            return data[pos];
        }

        reference front(){
            return data[0];
        }
        const_reference front()const { 
            return data[0];
        }

        reference back(){
            return data[size()-1];
        }

        const_reference back()const{
            return data[size()-1];
        }

        value_type *data_(){
            return data;
        }

        const value_type *data_()const{
            return data;
        }

        //iterators
        iterator begin()noexcept{return data; }
        const_iterator begin() const noexcept{return data;}
        const_iterator cbegin() const noexcept {return begin();}

        iterator end()noexcept{return available;}
        const_iterator end() const noexcept{return available;}
        const_iterator cend()const noexcept {return end();}

        reverse_iterator rbegin() noexcept{return reverse_iterator(end());}
        const_reverse_iterator rbegin() const noexcept{return const_reverse_iterator(end());}
        const_reverse_iterator crbegin() const noexcept{return rbegin();}

        reverse_iterator rend() noexcept{return reverse_iterator(begin());}
        const_reverse_iterator rend() const noexcept{return const_reverse_iterator(begin());}
        const_reverse_iterator crend () const noexcept{return rend();}

         // capacity
         bool empty()const noexcept{return size()==0;}
        size_type size() const noexcept{ return available - data;}
        size_type max_size() const noexcept{
           return std::numeric_limits<size_type>::max();
        }

        void reserve(size_type size){
            if(size>capacity()){
                grow(size);
            }
        }

        size_type capacity()const noexcept{
            return limit-data;
        }
        void shrink_to_fit(){
            if(limit>available){
                limit= available;
            }
        }
       
        //modifiers
        void clear() noexcept{
            uncreate();
        }

        iterator erase(iterator pos){
            if(pos<data || pos>available){
                throw std::out_of_range("Index out of range");
            }
            iterator availability = std::uninitialized_copy(pos+1, available, pos);
            alloc.destroy(available+1);
            available=availability;
            return pos;
        }

        iterator erase (iterator first, iterator last){
            iterator availability = std::uninitialized_copy(last, available, first);
            iterator it = available;
            while(it!=availability){
                alloc.destroy(--it);
            }

            available = availability;
            return last;
        }


        void push_back(const value_type &value){
            if(available==limit){
                grow();
            }
            unchecked_append(value);
        }

        void push_back(const value_type &&value){
            if(available==limit){
                grow();
            }
            unchecked_append(value);
        }


        void pop_back(){
            iterator it = available;
            alloc.destroy(--it);
            available=it;
        }


        void resize(size_type new_cap){
            if(new_cap<size()){
                available=data+new_cap;
                iterator it = limit;
            }
            else if(new_cap>capacity()){
                grow();
                resize(new_cap);
            }
            else if(new_cap>size()){
                available +=new_cap-size();
            }
        }

        void resize(size_type n, const value_type &value) {
        if (n > capacity()) {
            grow();
            resize(n, value);
        } else if (n > size()) {
            size_type i = size();
            available += n - size();

            for (; i < n; i++) {
                data[i] = value;
            }
        } else {
            resize(n);
        }
    }

        void swap(Vector &it){
            swap(data, it.data);
            swap(available, it.available);
            swap(limit, it.limit);
        }

        void swap(Vector<T> &x, Vector<T> &y) {
        std::swap(x, y);
        }

        //Non-member functions
           bool operator==(const Vector<T> &rhs) const {
            return size() == rhs.size() && std::equal(begin(), end(), rhs.begin());
            }

        bool operator!=(const Vector<T> &rhs) {
            return !(*this == rhs);
        }

        bool operator<(const Vector<T> &rhs) {
            return std::lexicographical_compare(begin(), end(), rhs.begin(), rhs.end());
        }

        bool operator>(const Vector<T> &rhs) {
           return std::lexicographical_compare(rhs.begin(), rhs.end(), begin(), end());
        }

        bool operator>=(const Vector<T> &rhs) {
            return !(*this < rhs);
        }

        bool operator<=(const Vector<T> &rhs) {
            return !(*this > rhs);
        }

    private:
        iterator data;
        iterator available;
        iterator limit;

        std::allocator<T> alloc;
        void create(){
            data=available=limit=nullptr;
        }
        
        void create(size_type n, const T& value){
            data=alloc.allocate(n);
            limit=available=data+n;
            std::uninitialized_fill(data, limit, value);
        }

        void create(const_iterator i, const_iterator j){
            data=alloc.allocate(j-i);
            limit=available=std::uninitialized_copy(i,j, data);
        }

        void uncreate(){
            if(data){
                iterator it=available;
                while (it!=data){
                    alloc.destroy(--it);
                }
                alloc.deallocate(data,limit-data);
            }
            data=limit=available=nullptr;
        }

        void grow(){
            size_type new_size = std::max(2*(limit-data), ptrdiff_t(1));
            iterator new_data =alloc.allocate(new_size);
            iterator new_available = std::uninitialized_copy(data, available, new_data);
            uncreate();

            data=new_data;
            available=new_available;
            limit=data+new_size;
        }

        void grow(size_type new_capacity) {
        size_type new_size = std::max(2 * capacity(), new_capacity);
        iterator new_data = alloc.allocate(new_size);
        iterator new_available = std::uninitialized_copy(data, available, new_data);

        uncreate();

        data = new_data;
        available = new_available;
        limit = new_data + new_size;
    }
        
        void unchecked_append(const T& value){
            alloc.construct(available++, value);
        }      
};