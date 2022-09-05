#include<iostream>
#include<map>
#include <list>
#include <vector>


using LRUQueue = std::list<uint64_t>;
using FileSegmentMap = std::map<size_t, LRUQueue::iterator>;
using FileSegmentMapPtr = std::shared_ptr<FileSegmentMap>;


int main()
{
    FileSegmentMapPtr fsm = std::make_shared<FileSegmentMap>();
    int n[] = {1, 2, 3, 4, 5};
    LRUQueue lru(n, n+5);
    int n2[] = {6, 7, 8, 9, 10};
    LRUQueue lru2(n2, n2+5);
    fsm->insert(std::pair<size_t, LRUQueue::iterator>{1, lru.begin()});
    fsm->insert(std::pair<size_t, LRUQueue::iterator>{2, lru2.begin()});
    for (auto map_iter : (*fsm)){
        auto segment = *(map_iter.second++);
        std::cout << "FileSegmentMap.first is:" << map_iter.first << std::endl;
        std::cout << "FileSegmentMap.second is:" << segment << std::endl;
    }
}