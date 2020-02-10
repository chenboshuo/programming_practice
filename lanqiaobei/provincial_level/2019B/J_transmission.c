/*
 *  灵能传输
 * 时间限制: 1.0s 内存限制: 256.0MB 本题总分：25 分
 *
 * 【题目背景】
 *
 * 在游戏《星际争霸 II》中，高阶圣堂武士作为星灵的重要 AOE 单位，在
 * 游戏的中后期发挥着重要的作用，其技能”灵能风暴“可以消耗大量的灵能对
 * 一片区域内的敌军造成毁灭性的伤害。经常用于对抗人类的生化部队和虫族的
 * 刺蛇飞龙等低血量单位。
 *
 * 【问题描述】
 *
 * 你控制着 n 名高阶圣堂武士，方便起见标为 1,2,··· ,n。每名高阶圣堂武士
 * 需要一定的灵能来战斗， 每个人有一个灵能值 ai 表示其拥有的灵能的多少
 * （ai非负表示这名高阶圣堂武士比在最佳状态下多余了ai点灵能，
 * ai为负则表示这名高阶圣堂武士还需要 −ai 点灵能才能到达最佳战斗状态） 。
 * 现在系统赋予了你的高阶圣堂武士一个能力， 传递灵能，每次你可以选择一个 i ∈
 * [2,n − 1]，若 ai ≥ 0 则其两旁的高阶圣堂武士，也就是 i − 1、i + 1
 * 这两名高阶圣堂武士会从 i 这名高阶圣堂武士这里各抽取 a i 点灵能； 若 ai < 0
 * 则其两旁的高阶圣堂武士， 也就是 i−1,i+1 这两名高阶圣堂武士会给 i
 * 这名高阶圣堂武士 −ai 点灵能。 形式化来讲就是 ai-1 + =ai , ai+1+ = ai, ai − =
 * 2ai 。 灵能是非常高效的作战工具，同时也非常危险且不稳定， 一位高阶圣堂
 * 武士拥有的灵能过多或者过少都不好，定义一组高阶圣堂武士的不稳定度为 max ni=1
 * |ai |， 请你通过不限次数的传递灵能操作使得你控制的这一组高阶圣堂武
 * 士的不稳定度最小。
 *
 * 【输入格式】
 *
 * 本题包含多组询问。输入的第一行包含一个正整数 T 表示询问组数。
 * 接下来依次输入每一组询问。 每组询问的第一行包含一个正整数
 * n，表示高阶圣堂武士的数量。 接下来一行包含 n 个数 a 1 ,a 2 ,··· ,a n 。
 *
 * 【输出格式】
 *
 * 输出 T 行。每行一个整数依次表示每组询问的答案。
 *
 * 【样例输入】
 *
 * 3
 * 3
 * 5 -2 3
 * 4
 * 0 0 0 0
 * 3
 * 1 2 3
 *
 * 【样例输出】
 *
 * 3
 * 0
 * 3
 *
 * 【样例说明】 对于第一组询问： 对 2 号高阶圣堂武士进行传输操作后 a 1 = 3，a 2
 * = 2，a 3 = 1。答案为 3。 对于第二组询问：
 * 这一组高阶圣堂武士拥有的灵能都正好可以让他们达到最佳战斗状态。
 *
 * 【样例输入】
 *
 * 3
 * 4
 * -1 -2 -3 7
 * 4
 * 2 3 4 -8
 * 5
 * -1 -1 6 -1 -1
 *
 * 【样例输出】
 *
 * 5
 * 7
 * 4
 *
 * 【样例输入】
 *
 * 见文件trans3.in。
 *
 * 【样例输出】
 *
 * 见文件trans3.ans。
 *
 * 【数据规模与约定】
 *
 * 对于所有评测用例，T ≤ 3，3 ≤ n ≤ 300000，|a i | ≤ 10 9 。 评测时将使用 25
 * 个评测用例测试你的程序，每个评测用例的限制如下：
 *
 * 评测用例编号	n	ai	特殊性质
 * 1	= 3	≤ 1000	无
 * 2,3	≤ 5	≤ 1000	无
 * 4,5,6,7	≤ 10	≤ 1000	无
 * 8,9,10	≤ 20	≤ 1000	无
 * 11	≤ 100	≤ 10 9	所有 a i 非负
 * 12,13,14	≤ 100	≤ 10 9	无
 * 15,16	≤ 500	≤ 10 9	无
 * 17,18,19	≤ 5000	≤ 10 9	无
 * 20	≤ 5000	≤ 10 9	所有 a i 非负
 * 21	≤ 100000	≤ 10 9	所有 a i 非负
 * 22,23	≤ 100000	≤ 10 9	无
 * 24,25	≤ 300000	≤ 10 9	无
 * 注意：本题输入量较大请使用快速的读入方式。
 *
 */

#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define abs(x) ((x < 0) ? -(x) : (x))

long trans(long *nums, size_t center, long pre_max) {
  if (center < 1) {
    return pre_max;
  }
  long item_1, item_2, item_3, item_max;
  item_1 = nums[center - 1] + nums[center];
  item_2 = -nums[center];
  item_3 = nums[center + 1] + nums[center];
  item_max = max(max(abs(item_1), abs(item_2)), abs(item_3));
  if (item_max < pre_max) {
    nums[center - 1] = item_1;
    nums[center] = item_2;
    nums[center + 1] = item_3;
    return trans(nums, center - 1, item_max);
  }
  return pre_max;
}

long transmission(long *nums, size_t nums_size) {
  for (size_t i = 1; i < nums_size - 1; ++i) {
    long local_max = max(max(abs(nums[i]), abs(nums[i - 1])), abs(nums[i + 1]));
    trans(nums, i, local_max);
  }
  long global_max = 0;
  for (size_t i = 0; i < nums_size; ++i) {
    if (abs(nums[i]) > global_max) {
      global_max = abs(nums[i]);
    }
  }
  return global_max;
}

// long transmission(long *nums, size_t left, size_t right) {
//   if (left == right) {
//     return abs(nums[left]);
//   }
//   size_t center = (left + right) / 2;
//   long left_max = transmission(nums, left, center);
//   long right_max = transmission(nums, center + 1, right);
//   long no_trans = max(left_max, right_max);

//   // 数组长度是3, 考虑传输能量
//   if (right - left == 2) {
//     return trans(nums, left + 1, no_trans);
//   }

//   // 不输送能量返回每部分最大值
//   return no_trans;
// }

void test(long (*func)(long *nums, size_t nums_size)) {
  long t1[3] = {5, -2, 3};
  printf("test 1:\n[5,-2,3]\nExpect:\t3\n");
  printf("Output:\t%ld\n\n", (*func)(t1, 3));

  long t2[4] = {0, 0, 0, 0};
  printf("test 2:\n[0, 0, 0, 0]\nExpect:\t0\n");
  printf("Output:\t%ld\n\n", (*func)(t2, 4));

  long t3[3] = {1, 2, 3};
  printf("test 3:\n[1, 2, 3]\nExpect:\t3\n");
  printf("Output:\t%ld\n\n", (*func)(t3, 3));

  long t4[4] = {-1, -2, -3, 7};
  printf("test 4:\n[-1, -2, -3, 7]\nExpect:\t5\n");
  printf("Output:\t%ld\n\n", (*func)(t4, 4));

  long t5[4] = {2, 3, 4, -8};
  printf("test 5:\n[2, 3, 4, -8]\nExpect:\t7\n");
  printf("Output:\t%ld\n\n", (*func)(t5, 4));

  long t6[5] = {-1, -1, 6, -1, -1};
  printf("test 6:\n[-1, -1, 6, -1, -1]\nExpect:\t4\n");
  printf("Output:\t%ld\n\n", (*func)(t6, 5));

  long t7[5] = {6, -4, 2, -7, 3};
  printf("test 7:\n[6, -4, 2, -7, 3]\nExpect:\t5\n");
  printf("Output:\t%ld\n\n", (*func)(t7, 5));

  long t8[10] = {-99, -53, 43, 80, -83, 72, 99, 78, -63, -9};
  printf(
      "test 8:\n[-99, -53, 43, 80, -83, 72, 99, 78, -63, -9]\nExpect:\t88\n");
  printf("Output:\t%ld\n\n", (*func)(t8, 10));

  long t9[100] = {
      373837389,  225627048,  -847064399, 487662607,  579717002,  903937892,
      -89313283,  134706789,  259978604,  399131737,  298183518,  62083619,
      -444218530, 403702220,  358088455,  -973959249, -637339048, -736509394,
      -552801709, -98262597,  -532577703, -393599463, 762744971,  -683270041,
      716127816,  -991756495, 734780346,  27919355,   -421469435, 258728334,
      844409214,  -270792553, -490888330, 133696186,  843888283,  -35439761,
      -73481392,  -118968548, 269164182,  978558860,  522378250,  -979427259,
      -330256906, 235192566,  -652699569, -708569352, -778693386, 241745676,
      583226906,  121065292,  -503683097, 599394257,  405122877,  437067802,
      238539735,  -957745973, -843677563, -690555937, 908484805,  940157941,
      524765035,  730436972,  -17856720,  -530595388, -727773574, 617781285,
      491720304,  -779040285, -298295760, -699402143, 230749576,  404009775,
      126806094,  -140842651, 198136484,  681875881,  997449600,  898972467,
      -239590302, -62193410,  866009412,  -401154712, -276085482, 593177187,
      -236793216, 487533624,  75511548,   -446699920, -869912037, -330666015,
      268937148,  -430325605, -635949275, 361887555,  -855294881, 87004526,
      782523543,  -69083645,  -965396597, -880697065};
  printf("test 9:\n[37387389...]\nExpect:\t88\n");
  printf("Output:\t%ld\n\n", (*func)(t9, 100));

  long t10[5] = {9, 9, -1, 4, 7};
  printf("test 10:\n[9, 9, -1, 4, 7]\nExpect:\t9\n");
  printf("Output:\t%ld\n\n", (*func)(t10, 5));

  long t11[8] = {0, 0, 0, 9, -1, -2, 6, 0};
  printf("test 11:\n[0, 0, 0, 9, -1, -2, 6, 0]\nExpect:\t7\n");
  printf("Output:\t%ld\n\n", (*func)(t11, 8));
}

int main(int argc, char const *argv[]) {
  test(transmission);

  return 0;
}