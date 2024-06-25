#include <iostream>


template <typename T>
class List{
public:
    List(){
        head = nullptr;
        size_ = 0;
    }
    void push_back(T data);
    void erase(int index);
    void insert(int index, T data);
    int size(){return size_;}
    T& operator[] (const int index);
private:
    template <typename T>
    class Pointer{
    public:
        Pointer *next;
        T data;
        Pointer(T data = T(), Pointer *next = nullptr){
            this->data = data;
			this->next = next;
        }  
    };
    int size_;
    Pointer<T> *head;
};
