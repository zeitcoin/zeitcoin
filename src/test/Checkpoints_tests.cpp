//
// Unit tests for block-chain checkpoints
//
#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>

#include "../checkpoints.h"
#include "../util.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p11111 = uint256("0x0000000002c6c387c36f8c12a3a3a03a583e93df19f062e5faaa673d612785d0");
    uint256 p134444 = uint256("0x0000000080b1ba89ff9167b611c4ba815aa67c7844908295e1df2f7fd5035366");
    BOOST_CHECK(Checkpoints::CheckHardened(11111, p11111));
    BOOST_CHECK(Checkpoints::CheckHardened(134444, p134444));

    
    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckHardened(11111, p134444));
    BOOST_CHECK(!Checkpoints::CheckHardened(134444, p11111));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckHardened(11111+1, p134444));
    BOOST_CHECK(Checkpoints::CheckHardened(134444+1, p11111));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 134444);
}    

BOOST_AUTO_TEST_SUITE_END()
