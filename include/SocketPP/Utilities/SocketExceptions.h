//
// Created on 1/27/21.
//

#ifndef SOCKETPP_SOCKETEXCEPTIONS_H
#define SOCKETPP_SOCKETEXCEPTIONS_H

#include <stdexcept>

namespace spp {

    class AddressParseError : public std::logic_error {
    public:
        AddressParseError( const std::string& faulty_address, const std::string& reason );

        const char* what() const noexcept override;

    private:
        std::string m_message;
    };

}

#endif // SOCKETPP_SOCKETEXCEPTIONS_H
