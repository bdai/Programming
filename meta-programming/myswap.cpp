/*
 * myswap.cpp
 *
 *  Created on: Jun 22, 2013
 *      Author: dai
 */

#include "myswap.h"

#include <iostream>
#include <list>
#include <vector>

int main()
{
  using std::list;
  using std::vector;
  list<int> num_list;
  vector<int> nums (20, -1);
  int count = 0;
  BOOST_FOREACH (int &num, nums) num = count++;
  BOOST_FOREACH (int num, nums) num_list.push_back(num);

  // try the swap
  metaprg::print(num_list);
  list<int>::iterator list_iter1, list_iter2;
  list_iter1 = list_iter2 = num_list.begin();
  std::advance(list_iter1, 5);
  std::advance(list_iter2, 7);
  metaprg::iter_swap(list_iter1, list_iter2);
  metaprg::print(num_list);

  return 0;
}
