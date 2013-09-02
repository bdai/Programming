/*
 * myswap.h
 *
 *  Created on: Jun 22, 2013
 *      Author: dai
 */

#ifndef MYSWAP_H_
#define MYSWAP_H_

/**
 * \brief meta programming on personalized swap based on chapter 3 of the book
 */

#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/foreach.hpp>

#include <iostream>
#include <iterator>  // for iterator_traits
#include <utility>   // for swap

namespace metaprg
{

using namespace std;

template <bool use_swap> struct iter_swap_impl; // see text

template <class ForwardIterator1, class ForwardIterator2>
void iter_swap(ForwardIterator1 i1, ForwardIterator2 i2)
{
  typedef iterator_traits<ForwardIterator1> traits1;
  typedef typename traits1::value_type v1;
  typedef typename traits1::reference r1;

  typedef iterator_traits<ForwardIterator2> traits2;
  typedef typename traits2::value_type v2;
  typedef typename traits2::reference r2;

  bool const use_swap = boost::is_same<v1,v2>::value
      && boost::is_reference<r1>::value
      && boost::is_reference<r2>::value;


  iter_swap_impl<use_swap>::do_it(*i1,*i2);

}


template <>
struct iter_swap_impl<true>  // the "fast" one
{
  template <class ForwardIterator1, class ForwardIterator2>
  static void do_it(ForwardIterator1 i1, ForwardIterator2 i2)
  {
    std::cout << "using standard library" << std::endl;
    std::swap(*i1, *i2);
  }
};

template <>
struct iter_swap_impl<false>  // the one that always works
{
  template <class ForwardIterator1, class ForwardIterator2>
  static void do_it(ForwardIterator1 i1, ForwardIterator2 i2)
  {
    std::cout << "using personalized one" << std::endl;
    typename
    iterator_traits<ForwardIterator1>::value_type
    tmp = *i1;
    *i1 = *i2;
    *i2 = tmp;
  }
};


template <class Container>
void print (Container vec)
{
  using std::cout;
  using std::endl;
  BOOST_FOREACH (Container::value_type item, vec)
  {
    cout << item << endl;
  }
  cout << endl;
}

}

#endif /* MYSWAP_H_ */
