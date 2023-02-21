#include <iostream>
#include <bitset> //输出二进制的头文件
using namespace std;

#define	ACCESS_ONCE(x) (*(volatile typeof(x) *)&(x))

uint8_t metadata_[8];

void from_uint64_t(uint64_t val) {
  ACCESS_ONCE(*reinterpret_cast<uint64_t *>(metadata_)) = val;
}
uint64_t to_uint64_t() {
  return ACCESS_ONCE(*reinterpret_cast<const uint64_t *>(metadata_));
}

int main__()
{
    for(int i = 0; i < 4; i++)
    {
        metadata_[7-i] = 0xff;
    }
    metadata_[3] = 0xfc;
    auto tmp = to_uint64_t() >> 26;
    // cout << bitset<sizeof(tmp)*8>(tmp) << endl;
    cout << tmp << endl;
    return 0;
}



int main()
{
    constexpr static uint32_t kPresentClear = 0x100U;
    constexpr static uint64_t kNull = kPresentClear;

    cout << 0x3fffffffff << endl;

    uint64_t tmp = 274877906943;
    from_uint64_t(tmp);
    cout << to_uint64_t() << endl;

    cout << "tmp:" << bitset<sizeof(tmp)*8>(tmp) << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << bitset<sizeof(metadata_[i])*8>(metadata_[i]) << endl;
    }

    return 0;
}