//
// Created on 1/27/21.
//

#include <SocketPP/IPv4/IPv4Address.h>

#include <gtest/gtest.h>


TEST( IPv4, HandlesEmptyInput ) {
    ASSERT_FALSE( spp::IPv4Address::isValid( "" ) );

    ASSERT_ANY_THROW( spp::IPv4Address( "" ) );
}

TEST( IPv4, HandlesRandomInput ) {
    ASSERT_FALSE( spp::IPv4Address::isValid( "Tests are fun. Use them!" ) );
    ASSERT_FALSE( spp::IPv4Address::isValid( "I created this test on 1/27/21" ) );

    ASSERT_ANY_THROW( spp::IPv4Address( "And this uses the constructor. Extra effective!" ) );
}

TEST( IPv4, HandlesMissingBytes ) {
    ASSERT_FALSE( spp::IPv4Address::isValid( "127.0.0" ) );
    ASSERT_FALSE( spp::IPv4Address::isValid( "127" ) );
    ASSERT_FALSE( spp::IPv4Address::isValid( "127.0" ) );

    ASSERT_ANY_THROW( spp::IPv4Address( "192.0.1" ) );
}

TEST( IPv4, HandlesExtraBytes ) {
    ASSERT_FALSE( spp::IPv4Address::isValid( "127.0.0.0.0.1" ) );
    ASSERT_FALSE( spp::IPv4Address::isValid( "127.0.0.0.1" ) );
    ASSERT_FALSE( spp::IPv4Address::isValid( "0.0.0.0." ) );

    ASSERT_ANY_THROW( spp::IPv4Address( "192.168.168.0.1" ) );
}

TEST( IPv4, HandlesInvalidBytes ) {
    ASSERT_FALSE( spp::IPv4Address::isValid( "256.0.0.1" ) );
    ASSERT_FALSE( spp::IPv4Address::isValid( "0.0.1000.2" ) );
    ASSERT_FALSE( spp::IPv4Address::isValid( "2021" ) );

    ASSERT_ANY_THROW( spp::IPv4Address( "256.256.256.256" ) );
}

TEST( IPv4, HandlesValidAddresses ) {
    ASSERT_TRUE( spp::IPv4Address::isValid( "127.0.0.1" ) );
    ASSERT_TRUE( spp::IPv4Address::isValid( "255.255.255.255" ) );
    ASSERT_TRUE( spp::IPv4Address::isValid( "0.0.0.0" ) );
    ASSERT_TRUE( spp::IPv4Address::isValid( "192.168.1.0" ) );
    ASSERT_TRUE( spp::IPv4Address::isValid( "8.8.8.8" ) );

    ASSERT_NO_THROW( spp::IPv4Address( "1.1.1.1" ) );
}