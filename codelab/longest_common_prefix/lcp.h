#ifndef CODELAB_LONGEST_COMMON_PREFIX_H_
#define CODELAB_LONGEST_COMMON_PREFIX_H_

#include <vector>
#include <string>

namespace codelab {

/*
 * Given a vector of strings, return the longest common prefix.
 *
 * Let n be the number of string, m be the max string length, and k be
 * the length of longest common prefix. Try to have an algorithm run
 * in O(kn) time other than O(mn). Space overhead should be O(1).
 */

std::string longest_common_prefix(const std::vector<std::string>& strs);

}

#endif  // CODELAB_LONGEST_COMMON_PREFIX_H_
