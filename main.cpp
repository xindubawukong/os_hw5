#include <stdio.h>
#include <assert.h>
#include <vector>

using namespace std;

unsigned int memory[0x80 * 0x20];
unsigned int base_addr = 0x220;

int main() {

  freopen("../data.txt", "r", stdin);

  for (unsigned int i = 0; i < 0x80; i++) {
    unsigned int p;
    scanf("page %x: ", &p);
    assert(i == p);
    for (unsigned int j = 0; j < 0x20; j++) {
      unsigned int x;
      scanf("%x", &x);
      memory[i * 0x20 + j] = x;
    }
    scanf("\n");
  }

//  printf("memory: ");
//  for (int i = 0; i < 0x80 * 0x20; i++) printf("memory[%x] = %x\n", i, memory[i]);
//  printf("\n");

  vector<unsigned int> testcases = {0x6c74, 0x6b22, 0x03df, 0x69dc, 0x317a, 0x4546, 0x2c03, 0x7fd7, 0x390e, 0x748b};
  for (unsigned int addr : testcases) {
    printf("\nVirtual Address 0x%x:\n", addr);
    unsigned int pde_index = (addr >> 10) & 0x1f;
    unsigned int pde_contents = memory[base_addr + pde_index];
    unsigned int pde_valid = (pde_contents >> 7) & 1;
    unsigned int pde_pfn = pde_contents & 0x7f;
    printf("  --> pde index: 0x%x  pde contents: (valid %x, pfn 0x%x)\n", pde_index, pde_valid, pde_pfn);
    if (pde_valid == 0) {
      printf("    --> Fault (page directory entry not valid)\n");
      continue;
    }

    unsigned int pte_index = (addr >> 5) & 0x1f;
    unsigned int pte_contents = memory[(pde_pfn << 5) + pte_index];
    unsigned int pte_valid = (pte_contents >> 7) & 1;
    unsigned int pte_pfn = pte_contents & 0x7f;
    printf("    --> pte index: 0x%x  pte contents: (valid %x, pfn 0x%x)\n", pte_index, pte_valid, pte_pfn);
    if (pte_valid == 0) {
      printf("      --> Fault (page table entry not valid)\n");
      continue;
    }
    unsigned int real_addr = (pte_pfn << 5) + (addr & 0x1f);
    unsigned int value = memory[real_addr];
    printf("      --> Translates to Physical Address 0x%x --> Value: 0x%x\n", real_addr, value);
  }

  return 0;
}
