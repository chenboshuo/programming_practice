/*
 * 时间限制 : 1.0s 内存限制 : 256.0MB 本题总分：20 分
 *
 * 【问题描述】
 *
 *     给定一棵包含 N 个节点的完全二叉树，树上每个节点都有一个权值，按从
 *         上到下、从左到右的顺序依次是 A1,
 *     A2,
 *     ··· AN ， 如下图所示：
 *
 *         现在小明要把相同深度的节点的权值加在一起，他想知道哪个深度的节点
 *             权值之和最大？如果有多个深度的权值和同为最大，请你输出其中最小的深度。
 * 注：根的 深* 度是 1。 【输入格式】 第一行包含一个整数 N。 第二行包含 N 个整数
 * A 1, A 2, ··· A N 。
 *
 * 【输出格式】
 *
 *     输出一个整数代表答案。
 *
 * 【样例输入】
 *
 *     7
 *    1 6 5 4 3 2 1
 *
 * 【样例输出】
 *
 *     2
 *
 * 【评测用例规模与约定】 对于所有评测用例，1 ≤ N ≤ 100000，
 * −100000 ≤ Ai ≤ 100000。
 * LLONG_MAX	Maximum value for an object of type long long int
 * 9223372036854775807 (263-1) or greater*
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long long int brute_force(long long *tree, size_t tree_size) {
  long long int max_depth = 1;
  long long int max = 0;
  long long int depth = 1;  // 根的深度定义为1
  long long int sum = 0;    // 当前节点的权的和
  for (size_t i = 0; i < tree_size; ++i) {
    if (i + 1 == pow(2, depth)) {
      if (sum > max) {
        max_depth = depth;
        max = sum;
      }
      sum = 0;
      ++depth;
    }
    sum += tree[i];
  }

  // 处理最后一层不满的情况
  if (sum > max) {
    return depth;
  } else {
    return max_depth;
  }
}

int main(int argc, char const *argv[]) {
  size_t tree_size;
  // long long tree[tree_size];
  long long *tree = (long long *)malloc(sizeof(long long) * tree_size);

  scanf("%lld", &tree_size);
  for (size_t i = 0; i < tree_size; ++i) {
    scanf("%lld", tree + i);
  }

  printf("%lld\n", brute_force(tree, 8));

  return 0;
}