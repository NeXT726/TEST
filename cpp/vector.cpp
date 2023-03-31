#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;
class LocalSpan {
public:
	LocalSpan()
	    : addr_(0)
	    , span_size_(0){};
	LocalSpan(uint64_t addr, uint32_t span_size)
	    : addr_(addr)
	    , span_size_(span_size){};

	bool operator<(const LocalSpan& p) const {
		return (this->span_size_ < p.span_size_) ||
		       ((this->span_size_ == p.span_size_) &&
		        (this->span_id_ < p.span_id_));
	}
	// uint32_t get_span_size();
	// uint32_t get_free_offset();
	// uint32_t get_object_size();
	// void set_span_size(uint32_t span_size);
	// void set_free_offset(uint32_t offset);
	// void set_object_size(uint32_t span_type);

private:
	uint32_t span_id_;
	uint64_t addr_;
	uint32_t span_size_;
	// 分配给Thread的内存不代表被使用
	// 不能用free_offset_ == span_size_判断span状态
	// 需要在GC的时候遍历当前span的所有对象判断是否有效
	// 这样可以避免每次写入对象都对span进行更改
	uint32_t free_offset_;
	uint32_t object_size_;
};

class LocalSpanManager {
public:
	// 中粒度对象最低为256KB
	constexpr static uint32_t kMediumObjectSize = 0x40000U;
	// 大粒度对象最低为1MB
	constexpr static uint32_t kBigObjectSize = 0x100000U;

private:
	// 本地节点所有可用内存大小，先设为4GB进行测试
	uint64_t total_memory_size = 0x100000000U;

	constexpr static uint32_t kSpanListNum = 128;
	vector<vector<LocalSpan*>> free_spans_{
	    kSpanListNum, vector<LocalSpan*>(1, new LocalSpan())};
	vector<vector<LocalSpan*>> used_spans_{
	    kSpanListNum, vector<LocalSpan*>(1, new LocalSpan())};
	set<LocalSpan*> big_objects_;
};

int main() {
	LocalSpanManager tmp;
	return 0;
}

int main_() {
	vector<int> num = {1, 2, 3, 4, 5};
	using NodePool = std::stack<int, std::vector<int>>;
	NodePool node;
	for (int i = 0; i < 64; i++)
		node.push(i);
	// cout << *(num.end()) << endl;
	cout << sizeof(NodePool) << endl;

	cout << 6 / 2 * 3 << endl;
	return 0;
}