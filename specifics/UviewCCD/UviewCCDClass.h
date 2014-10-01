//=============================================================================
//
// file :         UviewCCDClass.h
//
// description :  Include for the UviewCCDClass root class.
//                This class is the singleton class for
//                the UviewCCD device class.
//                It contains all properties and methods which the 
//                UviewCCD requires only once e.g. the commands.
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

#ifndef _UVIEWCCDCLASS_H
#define _UVIEWCCDCLASS_H

#include <tango.h>
#include <UviewCCD.h>


namespace UviewCCD_ns
{//=====================================
//	Define classes for attributes
//=====================================
class ivsTRoi4InfAttrib: public Tango::SpectrumAttr
{
public:
	ivsTRoi4InfAttrib():SpectrumAttr("ivsTRoi4Inf", Tango::DEV_SHORT, Tango::READ, 10) {};
	~ivsTRoi4InfAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<UviewCCD *>(dev))->read_ivsTRoi4Inf(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<UviewCCD *>(dev))->is_ivsTRoi4Inf_allowed(ty);}
};

class ivsTRoi3InfAttrib: public Tango::SpectrumAttr
{
public:
	ivsTRoi3InfAttrib():SpectrumAttr("ivsTRoi3Inf", Tango::DEV_SHORT, Tango::READ, 10) {};
	~ivsTRoi3InfAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<UviewCCD *>(dev))->read_ivsTRoi3Inf(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<UviewCCD *>(dev))->is_ivsTRoi3Inf_allowed(ty);}
};

class ivsTRoi2InfAttrib: public Tango::SpectrumAttr
{
public:
	ivsTRoi2InfAttrib():SpectrumAttr("ivsTRoi2Inf", Tango::DEV_SHORT, Tango::READ, 10) {};
	~ivsTRoi2InfAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<UviewCCD *>(dev))->read_ivsTRoi2Inf(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<UviewCCD *>(dev))->is_ivsTRoi2Inf_allowed(ty);}
};

class ivsTRoi1InfAttrib: public Tango::SpectrumAttr
{
public:
	ivsTRoi1InfAttrib():SpectrumAttr("ivsTRoi1Inf", Tango::DEV_SHORT, Tango::READ, 10) {};
	~ivsTRoi1InfAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<UviewCCD *>(dev))->read_ivsTRoi1Inf(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<UviewCCD *>(dev))->is_ivsTRoi1Inf_allowed(ty);}
};

class ivsTRoi4Attrib: public Tango::Attr
{
public:
	ivsTRoi4Attrib():Attr("ivsTRoi4", Tango::DEV_FLOAT, Tango::READ) {};
	~ivsTRoi4Attrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<UviewCCD *>(dev))->read_ivsTRoi4(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<UviewCCD *>(dev))->is_ivsTRoi4_allowed(ty);}
};

class ivsTRoi3Attrib: public Tango::Attr
{
public:
	ivsTRoi3Attrib():Attr("ivsTRoi3", Tango::DEV_FLOAT, Tango::READ) {};
	~ivsTRoi3Attrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<UviewCCD *>(dev))->read_ivsTRoi3(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<UviewCCD *>(dev))->is_ivsTRoi3_allowed(ty);}
};

class ivsTRoi2Attrib: public Tango::Attr
{
public:
	ivsTRoi2Attrib():Attr("ivsTRoi2", Tango::DEV_FLOAT, Tango::READ) {};
	~ivsTRoi2Attrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<UviewCCD *>(dev))->read_ivsTRoi2(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<UviewCCD *>(dev))->is_ivsTRoi2_allowed(ty);}
};

class ivsTRoi1Attrib: public Tango::Attr
{
public:
	ivsTRoi1Attrib():Attr("ivsTRoi1", Tango::DEV_FLOAT, Tango::READ) {};
	~ivsTRoi1Attrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<UviewCCD *>(dev))->read_ivsTRoi1(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<UviewCCD *>(dev))->is_ivsTRoi1_allowed(ty);}
};

//=========================================
//	Define classes for commands
//=========================================
class SetAverageImagesCmd : public Tango::Command
{
public:
	SetAverageImagesCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SetAverageImagesCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SetAverageImagesCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<UviewCCD *>(dev))->is_SetAverageImages_allowed(any);}
};



class SetIvsTROICmd : public Tango::Command
{
public:
	SetIvsTROICmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SetIvsTROICmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SetIvsTROICmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<UviewCCD *>(dev))->is_SetIvsTROI_allowed(any);}
};



//
// The UviewCCDClass singleton definition
//

class
#ifdef WIN32
	__declspec(dllexport)
#endif
	UviewCCDClass : public Tango::DeviceClass
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
	static UviewCCDClass *init(const char *);
	static UviewCCDClass *instance();
	~UviewCCDClass();
	Tango::DbDatum	get_class_property(string &);
	Tango::DbDatum	get_default_device_property(string &);
	Tango::DbDatum	get_default_class_property(string &);
	
protected:
	UviewCCDClass(string &);
	static UviewCCDClass *_instance;
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


}	//	namespace UviewCCD_ns

#endif // _UVIEWCCDCLASS_H
