static const char *RcsId = "$Id $";
//+=============================================================================
//
// file :         UfxcStateMachine.cpp
//
// description :  C++ source for the Ufxc and its alowed 
//                methods for commands and attributes
//
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL: $
//
// CVS only:
// $Source:  $
// $Log:  $
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#ifdef WIN32
#include "tango.h"
#endif

#include <Ufxc.h>
#include <UfxcClass.h>

#ifndef WIN32
#include "tango.h"
#endif


/*====================================================================
 *	This file contains the methods to allow commands and attributes
 * read or write execution.
 *
 * If you wand to add your own code, add it between 
 * the "End/Re-Start of Generated Code" comments.
 *
 * If you want, you can also add your own methods.
 *====================================================================
 */

namespace Ufxc_ns
{

//=================================================
//		Attributes Allowed Methods
//=================================================


//+----------------------------------------------------------------------------
//
// method : 		Ufxc::is_libVersion_allowed
// 
// description : 	Read/Write allowed for libVersion attribute.
//
//-----------------------------------------------------------------------------
bool Ufxc::is_libVersion_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT	||
		get_state() == Tango::INIT)
	{
		//	End of Generated Code
		if ( get_state()==Tango::RUNNING && type==Tango::READ_REQ )
		{
           return true;
		}
		
		if ( get_state()==Tango::FAULT && is_device_initialized() )
		{
           return true;
		}	
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		Ufxc::is_firmwareVersion_allowed
// 
// description : 	Read/Write allowed for firmwareVersion attribute.
//
//-----------------------------------------------------------------------------
bool Ufxc::is_firmwareVersion_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT	||
		get_state() == Tango::INIT)
	{
		//	End of Generated Code
		if ( get_state()==Tango::RUNNING && type==Tango::READ_REQ )
		{
           return true;
		}
		
		if ( get_state()==Tango::FAULT && is_device_initialized() )
		{
           return true;
		}	
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		Ufxc::is_detectorTemperature_allowed
// 
// description : 	Read/Write allowed for detectorTemperature attribute.
//
//-----------------------------------------------------------------------------
bool Ufxc::is_detectorTemperature_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT	||
		get_state() == Tango::INIT)
	{
		//	End of Generated Code
		if ( get_state()==Tango::RUNNING && type==Tango::READ_REQ )
		{
           return true;
		}
		
		if ( get_state()==Tango::FAULT && is_device_initialized() )
		{
           return true;
		}	
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		Ufxc::is_thresholdLow_allowed
// 
// description : 	Read/Write allowed for thresholdLow attribute.
//
//-----------------------------------------------------------------------------
bool Ufxc::is_thresholdLow_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT	||
		get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( get_state()==Tango::RUNNING && type==Tango::READ_REQ )
		{
           return true;
		}
		
		if ( get_state()==Tango::FAULT && is_device_initialized() )
		{
           return true;
		}	
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		Ufxc::is_thresholdHigh_allowed
// 
// description : 	Read/Write allowed for thresholdHigh attribute.
//
//-----------------------------------------------------------------------------
bool Ufxc::is_thresholdHigh_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT	||
		get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( get_state()==Tango::RUNNING && type==Tango::READ_REQ )
		{
           return true;
		}
		
		if ( get_state()==Tango::FAULT && is_device_initialized() )
		{
           return true;
		}	
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		Ufxc::is_currentAlias_allowed
// 
// description : 	Read/Write allowed for currentAlias attribute.
//
//-----------------------------------------------------------------------------
bool Ufxc::is_currentAlias_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT	||
		get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( get_state()==Tango::RUNNING && type==Tango::READ_REQ )
		{
           return true;
		}
		
		if ( get_state()==Tango::FAULT && is_device_initialized() )
		{
           return true;
		}	
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		Ufxc::is_triggerAcquisitionFrequency_allowed
// 
// description : 	Read/Write allowed for triggerAcquisitionFrequency attribute.
//
//-----------------------------------------------------------------------------
bool Ufxc::is_triggerAcquisitionFrequency_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT	||
		get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( get_state()==Tango::RUNNING && type==Tango::READ_REQ )
		{
           return true;
		}
		
		if ( get_state()==Tango::FAULT && is_device_initialized() )
		{
           return true;
		}	
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		Ufxc::is_geometricalCorrection_allowed
// 
// description : 	Read/Write allowed for geometricalCorrection attribute.
//
//-----------------------------------------------------------------------------
bool Ufxc::is_geometricalCorrection_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT	||
		get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( get_state()==Tango::RUNNING && type==Tango::READ_REQ )
		{
           return true;
		}
		
		if ( get_state()==Tango::FAULT && is_device_initialized() )
		{
           return true;
		}	
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		Ufxc::is_currentConfigFile_allowed
// 
// description : 	Read/Write allowed for currentConfigFile attribute.
//
//-----------------------------------------------------------------------------
bool Ufxc::is_currentConfigFile_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT	||
		get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( get_state()==Tango::RUNNING && type==Tango::READ_REQ )
		{
           return true;
		}
		
		if ( get_state()==Tango::FAULT && is_device_initialized() )
		{
           return true;
		}	
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		Ufxc::is_countingMode_allowed
// 
// description : 	Read/Write allowed for countingMode attribute.
//
//-----------------------------------------------------------------------------
bool Ufxc::is_countingMode_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT	||
		get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( get_state()==Tango::RUNNING && type==Tango::READ_REQ )
		{
           return true;
		}
		
		if ( get_state()==Tango::FAULT && is_device_initialized() )
		{
           return true;
		}	
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

//=================================================
//		Commands Allowed Methods
//=================================================

//+----------------------------------------------------------------------------
//
// method : 		Ufxc::is_LoadConfigFile_allowed
// 
// description : 	Execution allowed for LoadConfigFile command.
//
//-----------------------------------------------------------------------------
bool Ufxc::is_LoadConfigFile_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::FAULT	||
		get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

}	// namespace Ufxc_ns
