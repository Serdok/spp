//
// Created on 1/27/21.
//

#include "SocketPP/Utilities/SocketExceptions.h"

namespace spp {

AddressParseError::AddressParseError( const std::string& faulty_address, const std::string& reason )
: std::logic_error( reason )
{
    m_message = "Failed to parse address '" + faulty_address + "': " + reason;
}

const char * AddressParseError::what() const noexcept {
    return m_message.c_str();
}

}