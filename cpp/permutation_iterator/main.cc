// STL
#include <array>     /* std::array */
#include <vector>    /* std::vector */
#include <algorithm> /* std::copy */
#include <iostream>  /* std::cout, std::endl */

// Boost
#include <boost/iterator/permutation_iterator.hpp> /* boost::make_permutation_iterator*/

int main(){

    using namespace boost;

    // Vector that contains original data
    std::vector<int>   data(9,0);

    // Array that should be inserted into data
    std::array<int, 3> subData{{1,1,1}};

    // Indices of data where subData should be assigned
    std::array<int, 3> indices{{2,5,8}};

    // Create iterator of data over indices
    auto it_begin = make_permutation_iterator(data.begin(), indices.begin());

    // Copy subData to the right indices
    std::copy(subData.begin(), subData.end(), it_begin);

    // Output data to control copy
    for(int i: data){
	std::cout << i << std::endl;
    }
	
    return 0;
}
