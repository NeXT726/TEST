#include <cstdlib>
#include <iostream>
#include <typeinfo>

// #define __inline__ inline
// #define __inline inline
// #define __always_inline inline __attribute__((always_inline))
// #define noinline __attribute__((noinline))

#define ACCESS_ONCE__(x) (*(volatile typeof(x)*)&(x))

// 对不大于8B的数据进行快速拷贝
// 对完整数据类型及小尾端的拷贝没有问题
// 对不完整的数据类型并且大尾端:
// 比如 SmallMemCpy<2>(uint32_t* a, uint32_t* b) 存在问题
template <size_t n>
static __always_inline void SmallMemcpy(void* _dest, const void* _src) {
	static_assert(n <= 8, "helpers::SmallMemcpy is only suitable for n <= 8.");

	uint8_t* dest = reinterpret_cast<uint8_t*>(_dest);
	const uint8_t* src = reinterpret_cast<const uint8_t*>(_src);
	if constexpr (n == 8) {
		ACCESS_ONCE__(*reinterpret_cast<uint64_t*>(dest)) =
		    *reinterpret_cast<const uint64_t*>(src);
		SmallMemcpy<n - 8>(dest + 8, src + 8);
	} else if constexpr (n >= 4) {
		ACCESS_ONCE__(*reinterpret_cast<uint32_t*>(dest)) =
		    *reinterpret_cast<const uint32_t*>(src);
		SmallMemcpy<n - 4>(dest + 4, src + 4);
	} else if constexpr (n >= 2) {
		ACCESS_ONCE__(*reinterpret_cast<uint16_t*>(dest)) =
		    *reinterpret_cast<const uint16_t*>(src);
		SmallMemcpy<n - 2>(dest + 2, src + 2);
	} else if constexpr (n >= 1) {
		ACCESS_ONCE__(*reinterpret_cast<uint8_t*>(dest)) =
		    *reinterpret_cast<const uint8_t*>(src);
		SmallMemcpy<n - 1>(dest + 1, src + 1);
	}
}

int main() {
	uint32_t x = 5;
	uint32_t y = 0;
	SmallMemcpy<2>(&y, &x);
	printf("%d\n", y);
	return 0;
}