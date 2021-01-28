//
// Created on 1/27/21.
//

#include "SocketPP/IPv4/IPv4Address.h"
#include "SocketPP/Utilities/SocketExceptions.h"

#include <sstream>
#include <regex>

namespace spp {

    IPv4Address::IPv4Address( unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4 ) {
        setAddress( b1, b2, b3, b4 );
    }

    IPv4Address::IPv4Address( const std::string& address ) {
        setAddress( address );
    }

    void IPv4Address::setAddress( unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4 ) {
        std::ostringstream ss;
        ss << b1 << '.' << b2 << '.' << b3 << '.' << b4;
        m_address = ss.str();
    }

    void IPv4Address::setAddress( const std::string& address ) {
        if (not isValid( address )) {
            throw AddressParseError( address, "Invalid IPv4 format" );
        }

        m_address = address;
    }

    bool IPv4Address::isValid( const std::string& address ) {
        // Capturing groups?
        const std::regex address_format( R"(^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$)" );
        if (!std::regex_match( address, address_format )) {
            return false;
        }

        // Correct format, check that each number is 1 byte long
        int index = 0;
        int next = address.find( '.', index );
        while (next != std::string::npos) {
            auto byte_string = address.substr( index, next );
            auto byte = std::stoi( byte_string );
            if (byte > std::numeric_limits< unsigned char >::max()) {
                // Number is over 255
                return false;
            }

            index = next + 1;
            next = address.find( '.', index );
        }

        return true;
    }

    const std::string& IPv4Address::getAddress() const {
        return m_address;
    }


    std::istream& operator >>( std::istream& in, IPv4Address& address ) {
        return in;
    }

    std::ostream& operator <<( std::ostream& out, const IPv4Address& address ) {
        return out;
    }
}