#include "ListTypeContainer.hpp"

using namespace std;
template <typename T>
void List<T>::push_back(T data){
    if (head == nullptr){
        head = new Pointer<T>(data);
    }
    else{
        Pointer<T> *new_data = this->head;
        while(new_data->next !=nullptr){
            new_data = new_data->next;
        }
        new_data->next = new Pointer<T>(data);
    }
    size_++;
}

template <typename T>
T& List<T>::operator[](const int index){
    int counter = 0;
    Pointer<T> * current = this->head;
    while(current!=nullptr){

        if(counter==index){
            return current->data;
        }
        current = current->next;
        counter++;
    }
}
template <typename T>
void List<T>::erase(int index_){
    if(index_==0){
        Pointer<T> *temp = head;
	    head = head->pNext;
	    delete temp;
	    size_--;
    }else
    {
        Pointer<T> *previous = this->head;
		for (int i = 0; i < index_ - 1; i++)
		{
			previous = previous->next;
		}		
		Pointer<T> *toDelete = previous->next;
		previous->next = toDelete->next;
		delete toDelete;
		size_--;
    }
}
template <typename T>
void List<T>::insert(int index_, T data){
    if(index_==0){
        head = new Pointer<T>(data, head); 
        size_++;      
    }else
    {
        Pointer<T> *previous = this->head;
		for (int i = 0; i < index_ - 1; i++)
		{
			previous = previous->next;
		}		
		Pointer<T> *newPointer = new Pointer<T>(data, previous->next);
		previous->next = newPointer;
        size_++;
    }
}
int main(){
    List<int> lst;
    lst.push_back(8);
    lst.push_back(4);
    lst.push_back(11);
    lst.push_back(5);
    lst.insert(2 , 77);
    int length = lst.size();
    std::cout << lst[2] << std::endl;
    std::cout << lst[3] << std::endl;
    std::cout << length << std::endl;
}