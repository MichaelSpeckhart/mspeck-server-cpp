#include <vector>
#include <unistd.h>
#include <string>

#include "table.h"

#define PERCENTAGETHRESHOLD 75 /*resize if exceeded*/
#define CHAININGTHRESHOLD 5 /*resize if exceeded*/
#define RESIZEPERCENTAGE 50

/**
 * @brief Standard namespace for any classes or methods defined by this program to not interfere with std namespace
 * 
 */
namespace mspeck {


    template <typename K, typename V> class hashtable : public Table<K,V> {
        private:
            size_t size;
            struct Entry {
                std::vector<std::pair<K,V>> bucket;
            };

            std::vector<Entry> *map;

        public:
        // public methods will include constructor and destructor along with the common API calls of get(), set(), and delete() with more to follow

            hashtable(size_t numBuckets) {
                map = new std::vector<Entry>(numBuckets);
            }

            virtual ~hashtable() {
                delete map;
            }

            /**
             * @brief Insert a key-value pair into the table
             * 
             * @param key 
             * @param value 
             * @return true 
             * @return false 
             */
            virtual bool insert(K key, V value) {
                std::hash<K> hasher;
                size_t hashedVal = hasher(key);
                hashedVal = hashedVal % map->size();

                std::vector<std::pair<K,V>> *pairs = &map->at(hashedVal).pairs;

                for (auto iterator = pairs->begin(); iterator != pairs->end(); ++iterator) {
                    if (iterator->first == key) {
                        return false;
                    }
                }

                pairs->push_back(std::make_pair(key, value));

                return true;
            }

            virtual bool 





    };
}