//=============================================================================
//
// file :        UserData.cpp
//
// description : 
//
// project :	XiaDxp Project
//
// $Author: noureddine $
//
// copyleft :    Synchrotron SOLEIL
//               L'Orme des merisiers - Saint Aubin
//               BP48 - 91192 Gif sur Yvette
//               FRANCE
//=============================================================================

#include "UserData.h"
#include <PogoHelper.h>

namespace Xspress3_ns
{
//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
DoubleUserData::DoubleUserData(const std::string& name)
: m_name(name),
m_value(0)
{
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
DoubleUserData::~DoubleUserData()
{
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
const Tango::DevDouble& DoubleUserData::get_value()
{
    yat::MutexLock scoped_lock(m_lock);
    return m_value;
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
void DoubleUserData::set_value(Tango::DevDouble value)
{
    yat::MutexLock scoped_lock(m_lock);
    m_value = value;
}

/////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------	
ULongUserData::ULongUserData(const std::string& name)
: m_name(name),
m_value(0)
{
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
ULongUserData::~ULongUserData()
{
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
const Tango::DevULong& ULongUserData::get_value()
{
    yat::MutexLock scoped_lock(m_lock);
    return m_value;
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
void ULongUserData::set_value(Tango::DevULong value)
{
    yat::MutexLock scoped_lock(m_lock);
    m_value = value;
}

/////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------	
LongUserData::LongUserData(const std::string& name)
: m_name(name),
m_value(0)
{
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
LongUserData::~LongUserData()
{
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
const Tango::DevLong& LongUserData::get_value()
{
    yat::MutexLock scoped_lock(m_lock);
    return m_value;
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
void LongUserData::set_value(Tango::DevLong value)
{
    yat::MutexLock scoped_lock(m_lock);
    m_value = value;
}

//----------------------------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------------------------
BooleanUserData::BooleanUserData(const std::string& name)
: m_name(name),
m_value(false)
{
}

//----------------------------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------------------------
BooleanUserData::~BooleanUserData()
{
}

//----------------------------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------------------------
const Tango::DevBoolean& BooleanUserData::get_value()
{
    yat::MutexLock scoped_lock(m_lock);
    return m_value;
}

//----------------------------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------------------------
void BooleanUserData::set_value(Tango::DevBoolean value)
{
    yat::MutexLock scoped_lock(m_lock);
    m_value = value;
}
/////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------	
StringUserData::StringUserData(const std::string& name)
: m_name(name)
{
    CREATE_DEVSTRING_ATTRIBUTE(m_value, MAX_ATTRIBUTE_STRING_LENGTH);
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
StringUserData::~StringUserData()
{
    DELETE_DEVSTRING_ATTRIBUTE(m_value);
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
const Tango::DevString* StringUserData::get_value()
{
    yat::MutexLock scoped_lock(m_lock);
    return m_value;
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
void StringUserData::set_value(std::string value)
{
    yat::MutexLock scoped_lock(m_lock);
    strcpy(*m_value, value.c_str());
}

/////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
ChannelUserData::ChannelUserData(const std::string& name, int nb_bins)
: m_name(name)
{
    m_data.resize(nb_bins);
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
ChannelUserData::~ChannelUserData()
{
	m_data.clear();
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
const std::vector<Tango::DevULong>& ChannelUserData::get_value()
{
    yat::MutexLock scoped_lock(m_lock);
    return m_data;
}

//----------------------------------------------------------------------------------------------------------------------
//	
//----------------------------------------------------------------------------------------------------------------------
void ChannelUserData::set_value(std::vector<Tango::DevULong> value)
{
    yat::MutexLock scoped_lock(m_lock);
    m_data = value;
}

/////////////////////////////////////////////////////////////////////////////////

} // namespace
