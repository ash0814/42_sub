#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>
#include "iterator.hpp"

namespace ft
{
  template <typename Iterator> struct iterator_traits {
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
  };

  template <typename T> struct iterator_traits<T *> {
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef T *pointer;
    typedef T &reference;
    typedef ft::random_access_iterator_tag iterator_category;
  };

  template <typename T> struct iterator_traits<const T *> {
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef const T *pointer;
    typedef const T &reference;
    typedef ft::random_access_iterator_tag iterator_category;
  };

  template < typename InputIterator >
	typename iterator_traits<InputIterator>::difference_type	distance(InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type	dist = 0;
		while (first != last){
			++first;
			++dist;
		}
		return dist;
	}
}

#endif