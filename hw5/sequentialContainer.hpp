#include <iostream>

template<typename T>
class CountainerSTL{
    public:
    T *new_value;
    CountainerSTL() 
    {
        m_size = 0;
        new_value = new T[m_size+1];
    }   
     ~CountainerSTL() { delete[] new_value; }

    void push_back(T value) {
        m_value = new T[m_size+1];
        for (size_t i = 0; i < m_size; ++i) {
            m_value[i] = new_value[i]; 
        }
        m_value[m_size] = value; 
        delete [] new_value; 
        new_value = m_value; 
        m_size += 1; 
    }
    void insert(int position, T value){
        m_value = new T[m_size+1];
        for (size_t i = 0; i < m_size; ++i) {
            if(i == position) {
                m_value[i] = value;
            }else if (i > position){
                m_value[i] = new_value[i-1];
            }else m_value[i] = new_value[i];

        }
        m_value[m_size] = new_value[m_size-1];
        delete [] new_value; 
        new_value = m_value; 
        m_size += 1; 
    }
    void erase(int position){
        m_value = new T[m_size-1];
        for (size_t i = 0; i < m_size; ++i) {             
            if (i > position){
                m_value[i-1] = new_value[i];
            }else if (i < position)m_value[i] = new_value[i];
        }
        m_value[m_size -1] = new_value[m_size];
        delete [] new_value; 
        new_value = m_value; 
        m_size -= 1; 
    }
    size_t size(){
        return m_size;
    }


   // CountainerSTL operator [] (const int counter) const{
       // return *(new_value+ counter-1);
// }

    private:
    T value;
    size_t m_size;
    T *m_value;
};
