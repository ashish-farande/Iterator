#include <iostream>

template <class T>
class Node
{
    public: 
        Node * previous;
        Node * next;
        T data;
};

template<class T>
class LinkedListIterator
{
    public:
        LinkedListIterator(Node<T>* itr): itr(itr){}
        LinkedListIterator(LinkedListIterator<Node<T>> lli): itr(lli.itr){}
        LinkedListIterator<T>& operator=(LinkedListIterator other)
        {
            itr = other.itr;
            return *this;
        }
        ~LinkedListIterator(){}
        void operator++(){itr = itr->next; }
        T& operator*(){return itr->data; }
        LinkedListIterator<T> operator++(int)
        {
            if(itr->next!=nullptr)
                itr = itr->next;

            return *this;
        }


    private:
        Node<T>* itr;
};

template <class T>
class linkedlist{

    public:
        typedef LinkedListIterator<T> iterator;
        linkedlist():HEAD(nullptr){}

        ~linkedlist()
        {
            clear();
        }

        void push_back(T data)
        {
            if(HEAD == nullptr)
            {
                HEAD = new Node<T>;
                HEAD->previous = nullptr;
                HEAD->next = nullptr;
                HEAD->data = data;
                return;
            }

            Node<T>* tmp = new Node<T>;
            tmp->data = data;

            Node<T>* it = HEAD;

            while(it->next!= nullptr)
                it = it->next;

            it->next = tmp;
            tmp->previous = it;
            tmp->next = nullptr;
        }

        void pop_back()
        {
            if(HEAD == nullptr) return;

            Node<T>* it = HEAD;
            while(it->next != nullptr)
                it = it->next;

            if(it == HEAD) HEAD = nullptr;
            else it->previous->next = nullptr;
            delete it;
        };

        void push_front(T data)
        {
            if (HEAD == nullptr)
            {
                HEAD = new Node<T>;
                HEAD->next = nullptr;
                HEAD->previous = nullptr;
                HEAD->data = data;
                return;
            }

            Node<T>* tmp = new Node<T>;
            tmp->data = data;
            tmp->next = HEAD;
            tmp->previous = nullptr;
            HEAD = tmp;
            return;
        }


        void pop_front()
        {
            if(HEAD == nullptr) return;

            HEAD = HEAD->next;
            delete HEAD->previous;
            HEAD->previous = nullptr;
        }

        void print()
        {
            if(HEAD == nullptr)
            {
                std::cout<<"List is Empty"<<std::endl;
                return;
            }

            Node<T>* it = HEAD;
            while(it != nullptr)
            {
                std::cout<<it->data<<" ";
                it = it->next;
            }
            std::cout<<std::endl;
        }

        T& front()
        {
            // if (HEAD == nullptr) return;
            return HEAD->data;
        }

        T& back()
        {
            // if (HEAD == nullptr) return;

            Node<T>* it = HEAD;
            while(it->next != nullptr)
                it = it->next;
            return it->data;
        }

        bool empty()
        {
            if (HEAD == nullptr) return true;
            return false;
        }

        size_t size()
        {
            size_t size = 0;

            if(empty()) return size;

            Node<T>* it = HEAD;
            while(it != nullptr)
            {
                size++;
                it = it->next;
            }

            return size;

        }

        void clear()
        {
            if(HEAD == nullptr)
                return;

            Node<T>* it = HEAD;
            while(it->next != nullptr)
            {
                it = it->next;
                delete it->previous;
            }
            delete it;
        }

        iterator begin()
        {
            return  iterator(HEAD);
        }

        iterator end()
        {
            Node<T>* tmp = HEAD;
            while(tmp->next != nullptr)
                tmp = tmp->next;
            return  iterator(tmp);
        }


        T& operator*()
        {
            return itr->data;
        }

        iterator operator+(int n)
        {
            itr = itr->next;
            std::cout<<"I am here"<<std::endl;
            return itr;
        }
    

    protected:
        Node<T>* HEAD;
        Node<T>* itr;

};

int main()
{
    linkedlist<int> myList;

    myList.push_back(10);
    myList.push_back(10);
    myList.push_back(15);
    myList.print();
    myList.pop_front();
    myList.print();   
    linkedlist<int>::iterator it = myList.begin();
    it++;
    it++;
    std::cout<<(*it)<<std::endl;

    return 0;
}