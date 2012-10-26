//=============================================================================
//
// file :         XpadPixelDetectorClass.h
//
// description :  Include for the XpadPixelDetectorClass root class.
//                This class is the singleton class for
//                the XpadPixelDetector device class.
//                It contains all properties and methods which the 
//                XpadPixelDetector requires only once e.g. the commands.
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
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#ifndef _XPADPIXELDETECTORCLASS_H
#define _XPADPIXELDETECTORCLASS_H

#ifdef WIN32
#include <tango.h>
#endif

#include <XpadPixelDetector.h>

#ifndef WIN32
#include <tango.h>
#endif

namespace XpadPixelDetector_ns
{//=====================================
//	Define classes for attributes
//=====================================
class ithlAttrib: public Tango::ImageAttr
{
public:
	ithlAttrib():ImageAttr("ithl", Tango::DEV_ULONG, Tango::READ, 50, 50) {};
	~ithlAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->read_ithl(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<XpadPixelDetector *>(dev))->is_ithl_allowed(ty);}
};

class daclAttrib: public Tango::ImageAttr
{
public:
	daclAttrib():ImageAttr("dacl", Tango::DEV_ULONG, Tango::READ, 100000, 100000) {};
	~daclAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->read_dacl(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<XpadPixelDetector *>(dev))->is_dacl_allowed(ty);}
};

class gp4Attrib: public Tango::Attr
{
public:
	gp4Attrib():Attr("gp4", Tango::DEV_ULONG, Tango::READ_WRITE) {};
	~gp4Attrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->read_gp4(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->write_gp4(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<XpadPixelDetector *>(dev))->is_gp4_allowed(ty);}
};

class gp3Attrib: public Tango::Attr
{
public:
	gp3Attrib():Attr("gp3", Tango::DEV_ULONG, Tango::READ_WRITE) {};
	~gp3Attrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->read_gp3(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->write_gp3(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<XpadPixelDetector *>(dev))->is_gp3_allowed(ty);}
};

class gp2Attrib: public Tango::Attr
{
public:
	gp2Attrib():Attr("gp2", Tango::DEV_ULONG, Tango::READ_WRITE) {};
	~gp2Attrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->read_gp2(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->write_gp2(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<XpadPixelDetector *>(dev))->is_gp2_allowed(ty);}
};

class gp1Attrib: public Tango::Attr
{
public:
	gp1Attrib():Attr("gp1", Tango::DEV_ULONG, Tango::READ_WRITE) {};
	~gp1Attrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->read_gp1(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->write_gp1(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<XpadPixelDetector *>(dev))->is_gp1_allowed(ty);}
};

class pAttrib: public Tango::Attr
{
public:
	pAttrib():Attr("p", Tango::DEV_ULONG, Tango::READ_WRITE) {};
	~pAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->read_p(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->write_p(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<XpadPixelDetector *>(dev))->is_p_allowed(ty);}
};

class nAttrib: public Tango::Attr
{
public:
	nAttrib():Attr("n", Tango::DEV_ULONG, Tango::READ_WRITE) {};
	~nAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->read_n(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->write_n(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<XpadPixelDetector *>(dev))->is_n_allowed(ty);}
};

class ovfAttrib: public Tango::Attr
{
public:
	ovfAttrib():Attr("ovf", Tango::DEV_ULONG, Tango::READ_WRITE) {};
	~ovfAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->read_ovf(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->write_ovf(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<XpadPixelDetector *>(dev))->is_ovf_allowed(ty);}
};

class shutterAttrib: public Tango::Attr
{
public:
	shutterAttrib():Attr("shutter", Tango::DEV_ULONG, Tango::READ_WRITE) {};
	~shutterAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->read_shutter(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->write_shutter(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<XpadPixelDetector *>(dev))->is_shutter_allowed(ty);}
};

class initAttrib: public Tango::Attr
{
public:
	initAttrib():Attr("init", Tango::DEV_ULONG, Tango::READ_WRITE) {};
	~initAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->read_init(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->write_init(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<XpadPixelDetector *>(dev))->is_init_allowed(ty);}
};

class deadTimeAttrib: public Tango::Attr
{
public:
	deadTimeAttrib():Attr("deadTime", Tango::DEV_ULONG, Tango::READ_WRITE) {};
	~deadTimeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->read_deadTime(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<XpadPixelDetector *>(dev))->write_deadTime(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<XpadPixelDetector *>(dev))->is_deadTime_allowed(ty);}
};

//=========================================
//	Define classes for commands
//=========================================
class DecrementITHLClass : public Tango::Command
{
public:
	DecrementITHLClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	DecrementITHLClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~DecrementITHLClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_DecrementITHL_allowed(any);}
};



class IncrementITHLClass : public Tango::Command
{
public:
	IncrementITHLClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	IncrementITHLClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~IncrementITHLClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_IncrementITHL_allowed(any);}
};



class UploadWaitTimesClass : public Tango::Command
{
public:
	UploadWaitTimesClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	UploadWaitTimesClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~UploadWaitTimesClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_UploadWaitTimes_allowed(any);}
};



class UploadCalibrationCmd : public Tango::Command
{
public:
	UploadCalibrationCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	UploadCalibrationCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~UploadCalibrationCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_UploadCalibration_allowed(any);}
};



class CalibrateOTNSlowCmd : public Tango::Command
{
public:
	CalibrateOTNSlowCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	CalibrateOTNSlowCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~CalibrateOTNSlowCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_CalibrateOTNSlow_allowed(any);}
};



class GetIthlCmd : public Tango::Command
{
public:
	GetIthlCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	GetIthlCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~GetIthlCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_GetIthl_allowed(any);}
};



class GetDaclCmd : public Tango::Command
{
public:
	GetDaclCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	GetDaclCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~GetDaclCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_GetDacl_allowed(any);}
};



class ResetClass : public Tango::Command
{
public:
	ResetClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ResetClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ResetClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_Reset_allowed(any);}
};



class LoadConfigCmd : public Tango::Command
{
public:
	LoadConfigCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	LoadConfigCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~LoadConfigCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_LoadConfig_allowed(any);}
};



class SaveConfigGCmd : public Tango::Command
{
public:
	SaveConfigGCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SaveConfigGCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SaveConfigGCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_SaveConfigG_allowed(any);}
};



class SaveConfigLCmd : public Tango::Command
{
public:
	SaveConfigLCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SaveConfigLCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SaveConfigLCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_SaveConfigL_allowed(any);}
};



class LoadAllConfigGCmd : public Tango::Command
{
public:
	LoadAllConfigGCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	LoadAllConfigGCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~LoadAllConfigGCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_LoadAllConfigG_allowed(any);}
};



class LoadFlatConfigCmd : public Tango::Command
{
public:
	LoadFlatConfigCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	LoadFlatConfigCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~LoadFlatConfigCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<XpadPixelDetector *>(dev))->is_LoadFlatConfig_allowed(any);}
};



//
// The XpadPixelDetectorClass singleton definition
//

class
#ifdef WIN32
	__declspec(dllexport)
#endif
	XpadPixelDetectorClass : public Tango::DeviceClass
{
public:
//	properties member data

//	add your own data members here
//------------------------------------

public:
	Tango::DbData	cl_prop;
	Tango::DbData	cl_def_prop;
	Tango::DbData	dev_def_prop;

//	Method prototypes
	static XpadPixelDetectorClass *init(const char *);
	static XpadPixelDetectorClass *instance();
	~XpadPixelDetectorClass();
	Tango::DbDatum	get_class_property(string &);
	Tango::DbDatum	get_default_device_property(string &);
	Tango::DbDatum	get_default_class_property(string &);
	
protected:
	XpadPixelDetectorClass(string &);
	static XpadPixelDetectorClass *_instance;
	void command_factory();
	void get_class_property();
	void attribute_factory(vector<Tango::Attr *> &);
	void write_class_property();
	void set_default_property();
	string get_cvstag();
	string get_cvsroot();

private:
	void device_factory(const Tango::DevVarStringArray *);
};


}	//	namespace XpadPixelDetector_ns

#endif // _XPADPIXELDETECTORCLASS_H
