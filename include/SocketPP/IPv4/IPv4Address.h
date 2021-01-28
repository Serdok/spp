//
// Created on 1/27/21.
//

#ifndef SOCKETPP_IPV4ADDRESS_H
#define SOCKETPP_IPV4ADDRESS_H

#include <istream>
#include <ostream>
#include <string>

namespace spp {

    class IPv4Address {
    public:
        explicit IPv4Address( unsigned char b1 = 0, unsigned char b2 = 0, unsigned char b3 = 0, unsigned char b4 = 0 );
        explicit IPv4Address( const std::string& address );

        static bool isValid( const std::string& address );

        const std::string& getAddress() const;
        void setAddress( unsigned char b1 = 0, unsigned char b2 = 0, unsigned char b3 = 0, unsigned char b4 = 0 );
        void setAddress( const std::string& address );

    private:
        std::string m_address;
    };

    std::istream& operator >>( std::istream& in, IPv4Address& address );
    std::ostream& operator <<( std::ostream& out, const IPv4Address& address );
}

#endif // SOCKETPP_IPV4ADDRESS_H
