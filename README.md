# Overview

题目：https://github.com/LearningOS/os_course_exercises/blob/2020spring/all/03-2-spoc-discussion.md#%E5%B0%8F%E7%BB%84%E6%80%9D%E8%80%83%E9%A2%98

# Usage

测试环境：MacOS 10.14.6

```bash
# 编译
mkdir build
cd build
cmake ..
make
# 运行
./hw5
```

运行结果：
```
$ ./hw5

Virtual Address 0x6c74:
  --> pde index: 0x1b  pde contents: (valid 1, pfn 0x20)
    --> pte index: 0x3  pte contents: (valid 1, pfn 0x61)
      --> Translates to Physical Address 0xc34 --> Value: 0x6

Virtual Address 0x6b22:
  --> pde index: 0x1a  pde contents: (valid 1, pfn 0x52)
    --> pte index: 0x19  pte contents: (valid 1, pfn 0x47)
      --> Translates to Physical Address 0x8e2 --> Value: 0x1a

Virtual Address 0x3df:
  --> pde index: 0x0  pde contents: (valid 1, pfn 0x5a)
    --> pte index: 0x1e  pte contents: (valid 1, pfn 0x5)
      --> Translates to Physical Address 0xbf --> Value: 0xf

Virtual Address 0x69dc:
  --> pde index: 0x1a  pde contents: (valid 1, pfn 0x52)
    --> pte index: 0xe  pte contents: (valid 0, pfn 0x7f)
      --> Fault (page table entry not valid)

Virtual Address 0x317a:
  --> pde index: 0xc  pde contents: (valid 1, pfn 0x18)
    --> pte index: 0xb  pte contents: (valid 1, pfn 0x35)
      --> Translates to Physical Address 0x6ba --> Value: 0x1e

Virtual Address 0x4546:
  --> pde index: 0x11  pde contents: (valid 1, pfn 0x21)
    --> pte index: 0xa  pte contents: (valid 0, pfn 0x7f)
      --> Fault (page table entry not valid)

Virtual Address 0x2c03:
  --> pde index: 0xb  pde contents: (valid 1, pfn 0x44)
    --> pte index: 0x0  pte contents: (valid 1, pfn 0x57)
      --> Translates to Physical Address 0xae3 --> Value: 0x16

Virtual Address 0x7fd7:
  --> pde index: 0x1f  pde contents: (valid 1, pfn 0x12)
    --> pte index: 0x1e  pte contents: (valid 0, pfn 0x7f)
      --> Fault (page table entry not valid)

Virtual Address 0x390e:
  --> pde index: 0xe  pde contents: (valid 0, pfn 0x7f)
    --> Fault (page directory entry not valid)

Virtual Address 0x748b:
  --> pde index: 0x1d  pde contents: (valid 1, pfn 0x0)
    --> pte index: 0x4  pte contents: (valid 0, pfn 0x7f)
      --> Fault (page table entry not valid)
```