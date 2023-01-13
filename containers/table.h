

template<typename K, typename V> class Table {
    public:
        virtual ~Map() {}

        virtual void clear() = 0;

        virtual bool insert(K key, V value) = 0;

        //virtual void copyHashTable(std::vector<)


};