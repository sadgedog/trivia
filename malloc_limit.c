#include <stdlib.h>
#include <stdio.h>

// mallocでアロケートできる限界を知る
// 実際のメモリより多くの容量をアロケートできる
// この段階ではアロケートしているだけでメモリリークは起きない
// http://makiuchi-d.github.io/2019/12/01/qiita-5451ae2aef422dcab3e6.ja.html
// プロセスは仮想アドレスを見る
// 物理アドレスはOSが割り振るので
// mallocで確保した時点ではメモリは使用されていない
// 書き込んだ時点で使用される
int main() {
  // 1GB
  int gb = 1024 * 1024 * 1024;
  // allocated memory size
  int sum = 0;
  for (;;) {
    void *p = malloc(gb);
    if (p == NULL)
      break;
    sum++;
  }
  
  printf("allocated memory %d GB\n", sum);
  
  return 0;
}
