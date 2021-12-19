#pragma once

#include <vector>
#include <map>

template<typename K, typename V>
class multimap_view
{
private:
    std::vector<std::map<K,V>*> view;
public:

    struct iterator
    {
        typename std::vector<std::map<K,V>*>::iterator ptr;

        iterator(typename std::vector<std::map<K,V>*>::iterator ptr)
        {
            this->ptr = ptr;
        }

        std::map<K,V>& operator*() const
        {
            return **ptr;
        }

        iterator& operator++() 
        { 
            ptr++; 
            return *this; 
        }

        friend bool operator== (const iterator& a, const iterator& b) 
        { 
            return a.ptr == b.ptr; 
        };
    };

    multimap_view() {}

    multimap_view(const multimap_view<K,V> &mm)
    {
        for(unsigned int i = 0; i < mm.view.size(); ++i)
            this->view.push_back(mm.view[i]);
    }

    template<typename C>
    operator std::multimap<K,V,C>() const 
    { 
        std::multimap<K,V,C> mmap;

        for(unsigned int i = 0; i < view.size(); ++i)
            for (typename std::map<K,V>::iterator it = view[i]->begin(); it != view[i]->end(); ++it)
                mmap.insert(std::pair<K,V>(it->first, it->second));

        return mmap;
    }

    void add(std::map<K,V> &map)
    {
        view.push_back(&map);
    }

    void remove(std::map<K,V> &map)
    {
        std::vector<std::map<K,V>*> tmp = view;

        view.clear();
        for (unsigned int i = 0; i < tmp.size(); i++)
            if(tmp[i] != &map)
                view.push_back(tmp[i]);         
    }

    unsigned int count(K key) const
    {
        unsigned int c = 0;

        for(unsigned int i = 0; i < view.size(); ++i)
            c += view[i]->count(key);

        return c;
    }

    unsigned int erase(K key)
    {   
        unsigned int c = 0;

        for(unsigned int i = 0; i < view.size(); ++i)
            c += view[i]->erase(key);

        return c;
    }

    iterator begin()
    {
        return iterator(view.begin());
    }

    iterator end()
    {
        return iterator(view.end());
    }

};