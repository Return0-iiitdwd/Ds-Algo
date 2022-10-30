#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BINARY SEARCH STL
//  Binary_search(startAddress, endAddress, target)
//  Parameters:
//  startaddress: The address of the first element
//                of the array.
//  endaddress: The address of the next contiguous
//              location of the last element of the array.
//  target: The target value which we have to search for.
//  Returns: true if an element equal to valuetofind is found,
//           else false.
//  complexity: Time: - O(logn) space: - O(1)


// UPPER BOUND STL
// upper_bound(startAddress, endAddress, val)
// Parameters:
// startaddress: The address of the first element
//               of the array.
// endaddress: The address of the next contiguous
//             location of the last element of the array.
// val: The value for which we have to find upper bound.
// Returns: An iterator to the upper bound position for val in the range.
// If no element in the range compares greater than val, the function returns endaddress
// complexity: Time: - O(logn) space: - O(1)


// LOWER BOUND STL
// lower_bound(startAddress, endAddress, val)
// Parameters:
// startaddress: The address of the first element
//               of the array.
// endaddress: The address of the next contiguous
//             location of the last element of the array.
// val: The value for which we have to find lower bound.
// Returns: An iterator to the lower bound position for val in the range.
// If no element in the range compares greater than val, the function returns endaddress
// complexity: Time: - O(logn) space: - O(1)

int main()
{
    vector<int> testArr{1, 2, 3, 3, 3, 4, 5, 6, 8};
    cout << binary_search(testArr.begin(), testArr.end(), 3) << endl;
    cout << binary_search(testArr.begin(), testArr.end(), 7) << endl;
    cout << upper_bound(testArr.begin(), testArr.end(), 3) - testArr.begin() << endl;
    cout << upper_bound(testArr.begin(), testArr.end(), 10) - testArr.begin() << endl;
    cout << lower_bound(testArr.begin(), testArr.end(), 3) - testArr.begin() << endl;
    cout << lower_bound(testArr.begin(), testArr.end(), -1) - testArr.begin() << endl;
}