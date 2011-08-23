static const char *RcsId = "$Id $";
//+=============================================================================
//
// file :         LimaDetectorStateMachine.cpp
//
// description :  C++ source for the LimaDetector and its alowed 
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


#include <LimaDetector.h>
#include <LimaDetectorClass.h>
#include <tango.h>

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

namespace LimaDetector_ns
{

//=================================================
//		Attributes Allowed Methods
//=================================================


//+----------------------------------------------------------------------------
//
// method : 		LimaDetector::is_detectorType_allowed
// 
// description : 	Read/Write allowed for detectorType attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_detectorType_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_detectorModel_allowed
// 
// description : 	Read/Write allowed for detectorModel attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_detectorModel_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_depth_allowed
// 
// description : 	Read/Write allowed for depth attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_depth_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_exposureTime_allowed
// 
// description : 	Read/Write allowed for exposureTime attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_exposureTime_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_sensorWidth_allowed
// 
// description : 	Read/Write allowed for sensorWidth attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_sensorWidth_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_sensorHeight_allowed
// 
// description : 	Read/Write allowed for sensorHeight attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_sensorHeight_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_nbFrames_allowed
// 
// description : 	Read/Write allowed for nbFrames attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_nbFrames_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_detectorDescription_allowed
// 
// description : 	Read/Write allowed for detectorDescription attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_detectorDescription_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_acquisitionMode_allowed
// 
// description : 	Read/Write allowed for acquisitionMode attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_acquisitionMode_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_exposureAccTime_allowed
// 
// description : 	Read/Write allowed for exposureAccTime attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_exposureAccTime_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_triggerMode_allowed
// 
// description : 	Read/Write allowed for triggerMode attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_triggerMode_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_fileGeneration_allowed
// 
// description : 	Read/Write allowed for fileGeneration attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_fileGeneration_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_currentFrame_allowed
// 
// description : 	Read/Write allowed for currentFrame attribute.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_currentFrame_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code
		if ( (get_state()==Tango::FAULT || get_state()==Tango::RUNNING )&& type==Tango::READ_REQ )
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
// method : 		LimaDetector::is_DeleteRemainingFiles_allowed
// 
// description : 	Execution allowed for DeleteRemainingFiles command.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_DeleteRemainingFiles_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		LimaDetector::is_Snap_allowed
// 
// description : 	Execution allowed for Snap command.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_Snap_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		LimaDetector::is_Stop_allowed
// 
// description : 	Execution allowed for Stop command.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_Stop_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::INIT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		LimaDetector::is_Start_allowed
// 
// description : 	Execution allowed for Start command.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_Start_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		LimaDetector::is_SetROI_allowed
// 
// description : 	Execution allowed for SetROI command.
//
//-----------------------------------------------------------------------------
bool LimaDetector::is_SetROI_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

}	// namespace LimaDetector_ns
