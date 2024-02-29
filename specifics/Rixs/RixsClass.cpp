static const char *ClassId    = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL: $";
static const char *HttpServer = "http://www.esrf.fr/computing/cs/tango/tango_doc/ds_doc/";
//+=============================================================================
//
// file :        RixsClass.cpp
//
// description : C++ source for the RixsClass. A singleton
//               class derived from DeviceClass. It implements the
//               command list and all properties and methods required
//               by the Rixs once per process.
//
// project :     TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
//
// $Log:  $
//
// copyleft :   European Synchrotron Radiation Facility
//              BP 220, Grenoble 38043
//              FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================


#ifdef WIN32
#include <tango.h>
#endif

#include <Rixs.h>
#include <RixsClass.h>

#ifndef WIN32
#include <tango.h>
#endif

//+----------------------------------------------------------------------------
/**
 *	Create RixsClass singleton and return it in a C function for Python usage
 */
//+----------------------------------------------------------------------------
extern "C" {
#ifdef WIN32

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_Rixs_class(const char *name) {
		return Rixs_ns::RixsClass::init(name);
	}
}


namespace Rixs_ns
{
//+----------------------------------------------------------------------------
//
// method : 		RemoveOperationCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *RemoveOperationCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "RemoveOperationCmd::execute(): arrived" << endl;

	Tango::DevLong	argin;
	extract(in_any, argin);

	((static_cast<Rixs *>(device))->remove_operation(argin));
	return new CORBA::Any();
}


//+----------------------------------------------------------------------------
//
// method : 		AddOperationCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *AddOperationCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "AddOperationCmd::execute(): arrived" << endl;

	Tango::DevLong	argin;
	extract(in_any, argin);

	((static_cast<Rixs *>(device))->add_operation(argin));
	return new CORBA::Any();
}









//
//----------------------------------------------------------------
//	Initialize pointer for singleton pattern
//----------------------------------------------------------------
//
RixsClass *RixsClass::_instance = NULL;

//+----------------------------------------------------------------------------
//
// method : 		RixsClass::RixsClass(string &s)
// 
// description : 	constructor for the RixsClass
//
// in : - s : The class name
//
//-----------------------------------------------------------------------------
RixsClass::RixsClass(string &s):DeviceClass(s)
{

	cout2 << "Entering RixsClass constructor" << endl;
	set_default_property();
	get_class_property();
	write_class_property();
	
	cout2 << "Leaving RixsClass constructor" << endl;

}
//+----------------------------------------------------------------------------
//
// method : 		RixsClass::~RixsClass()
// 
// description : 	destructor for the RixsClass
//
//-----------------------------------------------------------------------------
RixsClass::~RixsClass()
{
	_instance = NULL;
}

//+----------------------------------------------------------------------------
//
// method : 		RixsClass::instance
// 
// description : 	Create the object if not already done. Otherwise, just
//			return a pointer to the object
//
// in : - name : The class name
//
//-----------------------------------------------------------------------------
RixsClass *RixsClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new RixsClass(s);
		}
		catch (bad_alloc)
		{
			throw;
		}		
	}		
	return _instance;
}

RixsClass *RixsClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}

//+----------------------------------------------------------------------------
//
// method : 		RixsClass::command_factory
// 
// description : 	Create the command object(s) and store them in the 
//			command list
//
//-----------------------------------------------------------------------------
void RixsClass::command_factory()
{
	command_list.push_back(new AddOperationCmd("AddOperation",
		Tango::DEV_LONG, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));
	command_list.push_back(new RemoveOperationCmd("RemoveOperation",
		Tango::DEV_LONG, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));

	//	add polling if any
	for (unsigned int i=0 ; i<command_list.size(); i++)
	{
	}
}

//+----------------------------------------------------------------------------
//
// method : 		RixsClass::get_class_property
// 
// description : 	Get the class property for specified name.
//
// in :		string	name : The property name
//
//+----------------------------------------------------------------------------
Tango::DbDatum RixsClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		RixsClass::get_default_device_property()
// 
// description : 	Return the default value for device property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum RixsClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//+----------------------------------------------------------------------------
//
// method : 		RixsClass::get_default_class_property()
// 
// description : 	Return the default value for class property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum RixsClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		RixsClass::device_factory
// 
// description : 	Create the device object(s) and store them in the 
//			device list
//
// in :		Tango::DevVarStringArray *devlist_ptr : The device name list
//
//-----------------------------------------------------------------------------
void RixsClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{

	//	Create all devices.(Automatic code generation)
	//-------------------------------------------------------------
	for (unsigned long i=0 ; i < devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
						
		// Create devices and add it into the device list
		//----------------------------------------------------
		device_list.push_back(new Rixs(this, (*devlist_ptr)[i]));							 

		// Export device to the outside world
		// Check before if database used.
		//---------------------------------------------
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(device_list.back());
		else
			export_device(device_list.back(), (*devlist_ptr)[i]);
	}
	//	End of Automatic code generation
	//-------------------------------------------------------------

}
//+----------------------------------------------------------------------------
//	Method: RixsClass::attribute_factory(vector<Tango::Attr *> &att_list)
//-----------------------------------------------------------------------------
void RixsClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	//	Attribute : version
	versionAttrib	*version = new versionAttrib();
	Tango::UserDefaultAttrProp	version_prop;
	version_prop.set_unit(" ");
	version_prop.set_standard_unit(" ");
	version_prop.set_display_unit(" ");
	version_prop.set_description("Display the Version");
	version->set_default_properties(version_prop);
	att_list.push_back(version);

	//	Attribute : operationType
	operationTypeAttrib	*operation_type = new operationTypeAttrib();
	Tango::UserDefaultAttrProp	operation_type_prop;
	operation_type_prop.set_unit(" ");
	operation_type_prop.set_standard_unit(" ");
	operation_type_prop.set_display_unit(" ");
	operation_type_prop.set_description("available types :<br>\nRIXS<br>\nNONE<br>");
	operation_type->set_default_properties(operation_type_prop);
	att_list.push_back(operation_type);

	//	Attribute : operationValue
	operationValueAttrib	*operation_value = new operationValueAttrib();
	Tango::UserDefaultAttrProp	operation_value_prop;
	operation_value_prop.set_unit(" ");
	operation_value_prop.set_display_unit(" ");
	operation_value_prop.set_format("%s");
	operation_value_prop.set_description("Arithmetic available values :<br>\nany numeric value\n\n");
	operation_value->set_default_properties(operation_value_prop);
	att_list.push_back(operation_value);

	//	Attribute : minAreaCluster
	minAreaClusterAttrib	*min_area_cluster = new minAreaClusterAttrib();
	Tango::UserDefaultAttrProp	min_area_cluster_prop;
	min_area_cluster_prop.set_unit(" ");
	min_area_cluster_prop.set_description("Define the Min Area accepted for a Cluster.<CR>\n-1 to disable control of Min Area");
	min_area_cluster->set_default_properties(min_area_cluster_prop);
	att_list.push_back(min_area_cluster);

	//	Attribute : maxAreaCluster
	maxAreaClusterAttrib	*max_area_cluster = new maxAreaClusterAttrib();
	Tango::UserDefaultAttrProp	max_area_cluster_prop;
	max_area_cluster_prop.set_unit(" ");
	max_area_cluster_prop.set_description("Define the Max Area accepted for a Cluster.<CR>\n-1 to disable control of Max Area");
	max_area_cluster->set_default_properties(max_area_cluster_prop);
	att_list.push_back(max_area_cluster);

	//	Attribute : nbClusterValid
	nbClusterValidAttrib	*nb_cluster_valid = new nbClusterValidAttrib();
	Tango::UserDefaultAttrProp	nb_cluster_valid_prop;
	nb_cluster_valid_prop.set_unit(" ");
	nb_cluster_valid_prop.set_description("Nombre of valid clusters");
	nb_cluster_valid->set_default_properties(nb_cluster_valid_prop);
	att_list.push_back(nb_cluster_valid);

	//	Attribute : drawClusterEnabled
	drawClusterEnabledAttrib	*draw_cluster_enabled = new drawClusterEnabledAttrib();
	Tango::UserDefaultAttrProp	draw_cluster_enabled_prop;
	draw_cluster_enabled_prop.set_description("Enable/Disable drawing Rect on Valid Clusters");
	draw_cluster_enabled->set_default_properties(draw_cluster_enabled_prop);
	att_list.push_back(draw_cluster_enabled);

	//	Attribute : drawCentroidEnabled
	drawCentroidEnabledAttrib	*draw_centroid_enabled = new drawCentroidEnabledAttrib();
	Tango::UserDefaultAttrProp	draw_centroid_enabled_prop;
	draw_centroid_enabled_prop.set_description("Enable/Disable drawing Circle on Centroids of Valid Clusters");
	draw_centroid_enabled->set_default_properties(draw_centroid_enabled_prop);
	att_list.push_back(draw_centroid_enabled);

	//	Attribute : pngFilesEnabled
	pngFilesEnabledAttrib	*png_files_enabled = new pngFilesEnabledAttrib();
	Tango::UserDefaultAttrProp	png_files_enabled_prop;
	png_files_enabled_prop.set_unit(" ");
	png_files_enabled_prop.set_description("Enable/Disable writing results in PNG files");
	png_files_enabled->set_default_properties(png_files_enabled_prop);
	att_list.push_back(png_files_enabled);

	//	Attribute : pngFilesPath
	pngFilesPathAttrib	*png_files_path = new pngFilesPathAttrib();
	Tango::UserDefaultAttrProp	png_files_path_prop;
	png_files_path_prop.set_unit(" ");
	png_files_path_prop.set_description("Path of PNG files ");
	png_files_path->set_default_properties(png_files_path_prop);
	att_list.push_back(png_files_path);

	//	Attribute : operationsList
	operationsListAttrib	*operations_list = new operationsListAttrib();
	Tango::UserDefaultAttrProp	operations_list_prop;
	operations_list_prop.set_unit(" ");
	operations_list_prop.set_standard_unit(" ");
	operations_list_prop.set_display_unit(" ");
	operations_list_prop.set_description("Enumerate all Rixs active 'post processing' operations on the image.");
	operations_list->set_default_properties(operations_list_prop);
	att_list.push_back(operations_list);

	//	Attribute : clusterCounter
	clusterCounterAttrib	*cluster_counter = new clusterCounterAttrib();
	Tango::UserDefaultAttrProp	cluster_counter_prop;
	cluster_counter_prop.set_unit(" ");
	cluster_counter_prop.set_standard_unit(" ");
	cluster_counter->set_default_properties(cluster_counter_prop);
	att_list.push_back(cluster_counter);

	//	Attribute : clusterArea
	clusterAreaAttrib	*cluster_area = new clusterAreaAttrib();
	Tango::UserDefaultAttrProp	cluster_area_prop;
	cluster_area_prop.set_unit(" ");
	cluster_area_prop.set_standard_unit(" ");
	cluster_area_prop.set_display_unit(" ");
	cluster_area->set_default_properties(cluster_area_prop);
	att_list.push_back(cluster_area);

	//	Attribute : clusterSum
	clusterSumAttrib	*cluster_sum = new clusterSumAttrib();
	Tango::UserDefaultAttrProp	cluster_sum_prop;
	cluster_sum_prop.set_unit(" ");
	cluster_sum_prop.set_standard_unit(" ");
	cluster_sum_prop.set_display_unit(" ");
	cluster_sum->set_default_properties(cluster_sum_prop);
	att_list.push_back(cluster_sum);

	//	Attribute : clusterCentroidX
	clusterCentroidXAttrib	*cluster_centroid_x = new clusterCentroidXAttrib();
	Tango::UserDefaultAttrProp	cluster_centroid_x_prop;
	cluster_centroid_x_prop.set_unit(" ");
	cluster_centroid_x_prop.set_standard_unit(" ");
	cluster_centroid_x_prop.set_display_unit(" ");
	cluster_centroid_x->set_default_properties(cluster_centroid_x_prop);
	att_list.push_back(cluster_centroid_x);

	//	Attribute : clusterCentroidY
	clusterCentroidYAttrib	*cluster_centroid_y = new clusterCentroidYAttrib();
	Tango::UserDefaultAttrProp	cluster_centroid_y_prop;
	cluster_centroid_y_prop.set_unit(" ");
	cluster_centroid_y_prop.set_standard_unit(" ");
	cluster_centroid_y_prop.set_display_unit(" ");
	cluster_centroid_y->set_default_properties(cluster_centroid_y_prop);
	att_list.push_back(cluster_centroid_y);

	//	End of Automatic code generation
	//-------------------------------------------------------------
}








//+----------------------------------------------------------------------------
//
// method : 		RixsClass::get_class_property()
// 
// description : 	Read the class properties from database.
//
//-----------------------------------------------------------------------------
void RixsClass::get_class_property()
{
	//	Initialize your default values here (if not done with  POGO).
	//------------------------------------------------------------------

	//	Read class properties from database.(Automatic code generation)
	//------------------------------------------------------------------

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_class()->get_property(cl_prop);
	Tango::DbDatum	def_prop;
	int	i = -1;


	//	End of Automatic code generation
	//------------------------------------------------------------------

}

//+----------------------------------------------------------------------------
//
// method : 	RixsClass::set_default_property
// 
// description: Set default property (class and device) for wizard.
//              For each property, add to wizard property name and description
//              If default value has been set, add it to wizard property and
//              store it in a DbDatum.
//
//-----------------------------------------------------------------------------
void RixsClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;

	vector<string>	vect_data;
	//	Set Default Class Properties
	//	Set Default Device Properties
	prop_name = "MemorizedOperationTypes";
	prop_desc = "Memorize all operationType declared in the order to process the image.";
	prop_def  = "NONE";
	vect_data.clear();
	vect_data.push_back("NONE");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedOperationValues";
	prop_desc = "Memorize all operationValue associated to the operationType declared in the order to process the image.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedOperationLevels";
	prop_desc = "Memorize all levels associated to the operationType declared in the order to process the image.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "ResetSpectrumsAtEachFrame";
	prop_desc = "All Spectrum data wil be reset at each new Frame";
	prop_def  = "True";
	vect_data.clear();
	vect_data.push_back("True");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "DefaultValueInSpectrumsIfEmpty";
	prop_desc = "Set default value (-1) in spectrums if there is 0 Valid Clusters";
	prop_def  = "False";
	vect_data.clear();
	vect_data.push_back("False");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "RixsDrawCentroidColor";
	prop_desc = "RIXS : Define Color of centroids";
	prop_def  = "255;0;0";
	vect_data.clear();
	vect_data.push_back("255;0;0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "RixsDrawClusterColor";
	prop_desc = "RIXS : Define Color of Clusters";
	prop_def  = "255;0;0";
	vect_data.clear();
	vect_data.push_back("255;0;0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

}
//+----------------------------------------------------------------------------
//
// method : 		RixsClass::write_class_property
// 
// description : 	Set class description as property in database
//
//-----------------------------------------------------------------------------
void RixsClass::write_class_property()
{
	//	First time, check if database used
	//--------------------------------------------
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("Lima Rixs Device Specific");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("Lima Device Specific for post process image");
	description << str_desc;
	data.push_back(description);
		
	//	put cvs or svn location
	string	filename(classname);
	filename += "Class.cpp";
	
	// Create a string with the class ID to
	// get the string into the binary
	string	class_id(ClassId);
	
	// check for cvs information
	string	src_path(CvsPath);
	start = src_path.find("/");
	if (start!=string::npos)
	{
		end   = src_path.find(filename);
		if (end>start)
		{
			string	strloc = src_path.substr(start, end-start);
			//	Check if specific repository
			start = strloc.find("/cvsroot/");
			if (start!=string::npos && start>0)
			{
				string	repository = strloc.substr(0, start);
				if (repository.find("/segfs/")!=string::npos)
					strloc = "ESRF:" + strloc.substr(start, strloc.length()-start);
			}
			Tango::DbDatum	cvs_loc("cvs_location");
			cvs_loc << strloc;
			data.push_back(cvs_loc);
		}
	}
	// check for svn information
	else
	{
		string	src_path(SvnPath);
		start = src_path.find("://");
		if (start!=string::npos)
		{
			end = src_path.find(filename);
			if (end>start)
			{
				header = "$HeadURL: ";
				start = header.length();
				string	strloc = src_path.substr(start, (end-start));
				
				Tango::DbDatum	svn_loc("svn_location");
				svn_loc << strloc;
				data.push_back(svn_loc);
			}
		}
	}

	//	Get CVS or SVN revision tag
	
	// CVS tag
	string	tagname(TagName);
	header = "$Name: ";
	start = header.length();
	string	endstr(" $");
	
	end   = tagname.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strtag = tagname.substr(start, end-start);
		Tango::DbDatum	cvs_tag("cvs_tag");
		cvs_tag << strtag;
		data.push_back(cvs_tag);
	}
	
	// SVN tag
	string	svnpath(SvnPath);
	header = "$HeadURL: ";
	start = header.length();
	
	end   = svnpath.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strloc = svnpath.substr(start, end-start);
		
		string tagstr ("/tags/");
		start = strloc.find(tagstr);
		if ( start!=string::npos )
		{
			start = start + tagstr.length();
			end   = strloc.find(filename);
			string	strtag = strloc.substr(start, end-start-1);
			
			Tango::DbDatum	svn_tag("svn_tag");
			svn_tag << strtag;
			data.push_back(svn_tag);
		}
	}

	//	Get URL location
	string	httpServ(HttpServer);
	if (httpServ.length()>0)
	{
		Tango::DbDatum	db_doc_url("doc_url");
		db_doc_url << httpServ;
		data.push_back(db_doc_url);
	}

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("Device_4Impl");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	//--------------------------------------------
	get_db_class()->put_property(data);
}

}	// namespace