//=============================================================================
//
// file :        Rixs.h
//
// description : Include for the Rixs class.
//
// project :	Lima Rixs Device Specific
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
// copyleft :    Synchrotron SOLEIL 
//               L'Orme des merisiers - Saint Aubin
//		 BP48 - 91192 Gif sur Yvette
//               FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================
#ifndef _RIXS_H
#define _RIXS_H


/**
 * @author	$Author:  $
 * @version	$Revision:  $
 */

//	Add your own constant definitions here.
//-----------------------------------------------

#include "Factory.h"
#include <tango.h>

#include <yat4tango/PropertyHelper.h>
#include <yat/threading/Mutex.h>
#include <yat/utils/XString.h>
#include <yat/time/Timer.h>
#include <yat/utils/StringTokenizer.h>
#include <yat/utils/String.h>

#include "lima/HwInterface.h"
#include "lima/CtControl.h"
#include "lima/CtAcquisition.h"
#include "lima/CtImage.h"
#include "lima/SoftOpId.h"
#include "lima/SoftOpExternalMgr.h"
#include "processlib/Data.h"
#include "processlib/TaskMgr.h"
#include <map>

//- OpenCV
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#define MAX_ATTRIBUTE_STRING_LENGTH 	256
#define CURRENT_VERSION                 "1.0.0"

namespace Rixs_ns
{

    class RixsTask : public LinkTask
    {
    public:

        //-----------------------------------------------
		//ctor
		//-----------------------------------------------
        RixsTask(const std::string& opType, long opValue) :
        LinkTask(true),
        m_operation_type(opType),
        m_operation_value(opValue) { }

        //-----------------------------------------------
		//dtor
		//-----------------------------------------------
        ~RixsTask(){}       
        
        //-----------------------------------------------
		//define the operation type (RIXS)
		//-----------------------------------------------
        void setOperationType(const std::string& opType)
        {            
			m_operation_type = opType;
			transform(m_operation_type.begin(), m_operation_type.end(), m_operation_type.begin(), ::toupper);
        }

        //-----------------------------------------------
		//get the operation type (RIXS)
		//-----------------------------------------------
        const std::string& getOperationType()
        {
            return m_operation_type;
        }
        
        //-----------------------------------------------
		//define the operation value
		//-----------------------------------------------
        void setOperationValue(long opValue)
        {
            m_operation_value = opValue;
        }

        //-----------------------------------------------
		//get the operation value
		//-----------------------------------------------
        long getOperationValue()
        {
            return m_operation_value;
        }
        
        //-----------------------------------------------
		//define the Rixs Draw Centroid Color
		//-----------------------------------------------
        void setRixsDrawCentroidColor(const std::string& rixsColor)
        {            
			//decode rixsColor
			std::vector<std::string> parsed_colors;    
			m_rixs_centroid_colors.clear();
			if(yat::StringUtil::match(rixsColor, "*;*;*", &parsed_colors))
			{	
				m_rixs_centroid_colors.push_back(yat::StringUtil::to_num<double>(parsed_colors[0]));
				m_rixs_centroid_colors.push_back(yat::StringUtil::to_num<double>(parsed_colors[1]));
				m_rixs_centroid_colors.push_back(yat::StringUtil::to_num<double>(parsed_colors[2]));
			}
        }

        //-----------------------------------------------
		//define the Rixs Draw Label Color
		//-----------------------------------------------
        void setRixsDrawClusterColor(const std::string& rixsColor)
        {            
			//decode rixsColor
			std::vector<std::string> parsed_colors;    
			m_rixs_label_colors.clear();
			if(yat::StringUtil::match(rixsColor, "*;*;*", &parsed_colors))
			{	
				m_rixs_label_colors.push_back(yat::StringUtil::to_num<double>(parsed_colors[0]));
				m_rixs_label_colors.push_back(yat::StringUtil::to_num<double>(parsed_colors[1]));
				m_rixs_label_colors.push_back(yat::StringUtil::to_num<double>(parsed_colors[2]));
			}
        }
		
		//-----------------------------------------------
		//enable/disable Draw the Rixs Cluster 
		//-----------------------------------------------
		void setRixsDrawClusterEnabled(bool flag)
		{
			m_rixs_draw_cluster_is_enabled = flag;
		}
		
		//-----------------------------------------------
		//enable/disable Draw the Rixs Cluster 
		//-----------------------------------------------
		void setRixsDrawCentroidEnabled(bool flag)
		{
			m_rixs_draw_centroid_is_enabled = flag;
		}
		
        //-----------------------------------------------
		//define the Rixs Max Area Cluster 
		//-----------------------------------------------
        void setRixsMaxAreaCluster(const int max_area)
        {            
			m_rixs_max_area_cluster = max_area;
        }
		
        //-----------------------------------------------
		//define the Rixs Min Area Cluster 
		//-----------------------------------------------
        void setRixsMinAreaCluster(const int min_area)
        {            
			m_rixs_min_area_cluster = min_area;
        }
		
        //-----------------------------------------------
		//define the ResetSpectrumsAtEachFrame Enabled
		//-----------------------------------------------
        void setResetSpectrumsAtEachFrameEnabled(const bool is_enabled)
        {            
			m_reset_spectrums_at_each_frame_is_enabled = is_enabled;
        }		
		
        //-----------------------------------------------
		//define the ResetSpectrumsAtEachFrame Enabled
		//-----------------------------------------------
        void setDefaultValueInSpectrumsIfEmptyEnabled(const bool is_enabled)
        {            
			m_default_value_in_spectrums_enabled = is_enabled;
        }
		
        //-----------------------------------------------
		//define the Rixs Write Files Enabled
		//-----------------------------------------------
        void setRixsWriteFilesEnabled(const bool is_enabled)
        {            
			m_rixs_write_files_enabled = is_enabled;
        }
		
        //-----------------------------------------------
		//define the Rixs Write Files Path
		//-----------------------------------------------
        void setRixsWriteFilesPath(const string& path)
        {            
			m_rixs_write_files_path = path;
        }
		
        //-----------------------------------------------
		//get get_nb_valid_cluster
		//-----------------------------------------------		
		const long get_nb_valid_cluster()
		{
			yat::MutexLock scoped_lock(m_data_lock);
			if(!m_rixs_cluster_counter.empty())
				return m_rixs_cluster_counter.back();
			else
				return 0;
		}
		
        //-----------------------------------------------
		//get cluster counter
		//-----------------------------------------------
		const std::vector<long>& get_cluster_counter()
		{
			yat::MutexLock scoped_lock(m_data_lock);
			return m_rixs_cluster_counter;
		}
		
        //-----------------------------------------------
		//get cluster area
		//-----------------------------------------------
		const std::vector<long>& get_cluster_area()
		{
			yat::MutexLock scoped_lock(m_data_lock);
			return m_rixs_cluster_area;
		}
		
        //-----------------------------------------------
		//get cluster sum
		//-----------------------------------------------
		const std::vector<long>& get_cluster_sum()
		{
			yat::MutexLock scoped_lock(m_data_lock);
			return m_rixs_cluster_sum;
		}
		
        //-----------------------------------------------
		//get CentroidX vector
		//-----------------------------------------------
		const std::vector<double>& get_centroid_x()
		{
			yat::MutexLock scoped_lock(m_data_lock);
			return m_rixs_centroid_x;
		}
		
        //-----------------------------------------------
		//get CentroidY vector
		//-----------------------------------------------
		const std::vector<double>& get_centroid_y()
		{
			yat::MutexLock scoped_lock(m_data_lock);
			return m_rixs_centroid_y;
		}	
				
		//-----------------------------------------------
		//process is called from lima core for each image and apply operation on it
		//-----------------------------------------------
        Data process(Data &aData)
        {
			yat::AutoMutex<> _lock(ControlFactory::instance().get_global_mutex());
			yat::Timer t1;
            Data aNewData;
            switch(aData.type)
            {
                case Data::UINT8: _compute<unsigned char>(aData, aNewData);
                    break;
                case Data::INT8: _compute<char>(aData, aNewData);
                    break;					
                case Data::UINT16: _compute<unsigned short>(aData, aNewData);	
                    break;
                case Data::INT16: _compute<short>(aData, aNewData);
                    break;                    
                case Data::UINT32: _compute<unsigned int>(aData, aNewData);
                    break;
                case Data::INT32: _compute<int>(aData, aNewData);
                    break;   				
				default:
					YAT_INFO<<"Rixs: Undefined image Type : "<< aData.type << std::endl;
					break;
            }
				
			YAT_INFO <<"[Elapsed time total: "<<t1.elapsed_msec()<< " (ms)]"<<std::endl;
			YAT_INFO <<"--------------------------------"<< std::endl;				
            return aNewData;
        }

    private:
		//OpenCV Helper	
		std::string type_2_str(int type) 
		{
		  std::string str;

		  uchar depth = type & CV_MAT_DEPTH_MASK;
		  uchar chans = 1 + (type >> CV_CN_SHIFT);

		  switch ( depth ) 
		  {
			case CV_8U:  str = "8U"; 
				break;
			case CV_8S:  str = "8S"; 
				break;
			case CV_16U: str = "16U"; 
				break;
			case CV_16S: str = "16S"; 
				break;
			case CV_32S: str = "32S"; 
				break;
			case CV_32F: str = "32F"; 
				break;
			case CV_64F: str = "64F"; 
				break;
			default:     str = "User"; 
				break;
		  }

		  str += "C";
		  str += (chans+'0');

		  return str;
		}
			
		//-----------------------------------------------
		//RIXS ONLY :SUBPIXELLISATION OF IMAGE 
		//-----------------------------------------------		
		template<class INPUT>
		Data rixs(Data &aSrc)
		{			
			/*
			YAT_INFO<<""<<std::endl;
			YAT_INFO<<"-----------------------------"<<std::endl;
			YAT_INFO<<"frameNumber\t : "<<	aSrc.frameNumber<<std::endl;
			YAT_INFO<<"-----------------------------"<<std::endl;
			*/
			YAT_INFO<<"Apply operation [ "<< m_operation_type << " ("<<m_operation_value<<") ]"<<std::endl;		
			//@YAT_INFO<<"[min_area_cluster : "<<m_rixs_min_area_cluster	<<" , "<<"max_area_cluster : "<<m_rixs_max_area_cluster<<"]"<<std::endl;
			
			
			/*
			if (cv::gpu::getCudaEnabledDeviceCount() > 0) 
			{
				std::cout << "OpenCV a été compilé avec la prise en charge CUDA." << std::endl;
			}
			else 
			{
				std::cout << "OpenCV n'a pas été compilé avec la prise en charge CUDA." << std::endl;
			}
			*/
			
			/*std::cout<<cv::getBuildInformation()<<std::endl;*/
			
			yat::Timer t00;
			Data aDst = aSrc.copy();
			aDst.dimensions.clear();
			aDst.dimensions.push_back(aSrc.dimensions[0]/* *10 */);	//image src width  *  pixelisation rate (10 for example)
			aDst.dimensions.push_back(aSrc.dimensions[1]/* *10 */);	//image src height *  pixelisation rate (10 for example)
			int aNbPixel = aDst.dimensions[0] * aDst.dimensions[1];
			//@YAT_INFO<<"[Elapsed time (aSrc.copy()): "<<t00.elapsed_msec()<< " (ms)]"<<std::endl;
			
			
			//create cv::Mat from lima frame
			////yat::Timer t01;
			cv::Mat mat_origin;
			/////////////////////////////////////////////////
			if(aSrc.type == Data::UINT8)//simulator
			{
				mat_origin = cv::Mat(aSrc.dimensions[1], aSrc.dimensions[0], CV_8UC1, (INPUT*) aSrc.data());//for simulator				
			}
			else //dhyana
			if (aSrc.type == Data::UINT16 || aSrc.type == Data::INT16) 
			{
				mat_origin = cv::Mat(aSrc.dimensions[1], aSrc.dimensions[0], CV_16SC1, (INPUT*) aSrc.data());//for dhyana
			}
			else
			{
				//No process until now, so return original image
				return aSrc;
			}	
			////YAT_INFO<<"[Elapsed time (prepare cv::Mat): "<<t01.elapsed_msec()<< " (ms)]"<<std::endl;
			
			////std::cout << "Type de l'image mat_origin : " << mat_origin.type() << std::endl;
			
			if(m_rixs_write_files_enabled)
			{
				cv::imwrite(m_rixs_write_files_path+"\\mat_origin.png", mat_origin);
			}
			
			yat::Timer t02;
			cv::Mat mat_origin_draw;			
			mat_origin_draw = mat_origin.clone();
			////std::cout << "Type de l'image mat_origin_draw : " << type_2_str(mat_origin_draw.type()) << std::endl;
			
			
			//@YAT_INFO<<"[Elapsed time (mat_origin.clone()): "<<t02.elapsed_msec()<< " (ms)]"<<std::endl;
			
			//convert from 8 or 16 bits to 32f bits
			
			yat::Timer t03;
			cv::Mat mat_origin_32f;
			mat_origin.convertTo(mat_origin_32f, CV_32F);
			//@YAT_INFO<<"[Elapsed time (mat_origin.convertTo()): "<<t03.elapsed_msec()<< " (ms)]"<<std::endl;
			
			if(m_rixs_write_files_enabled)
			{		
				cv::imwrite(m_rixs_write_files_path+"\\mat_origin_32f.png", mat_origin_32f);			
			}
			
			//apply the threshold 
			yat::Timer t04;
			cv::Mat mat_threshold_32f;	
			cv::threshold(mat_origin_32f, mat_threshold_32f, m_operation_value, 255, cv::THRESH_BINARY);
			////std::cout << "Type de l'image mat_threshold_32f : " << mat_threshold_32f.type() << std::endl;
			//@YAT_INFO<<"[Elapsed time (threshold): "<<t04.elapsed_msec()<< " (ms)]"<<std::endl;
			
			if(m_rixs_write_files_enabled)
			{				
				cv::imwrite(m_rixs_write_files_path+"\\mat_threshold_32f.png", mat_threshold_32f);
			}
			/////////////////////////////////////////////////

			
			//apply a morpho filtre 
			yat::Timer t05;
			cv::Mat mat_morpho_32f;
			cv::morphologyEx(mat_threshold_32f, mat_morpho_32f,cv::MORPH_DILATE,cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point( -1,-1 )) );	
			//@YAT_INFO<<"[Elapsed time (morphologyEx): "<<t05.elapsed_msec()<< " (ms)]"<<std::endl;
						
			//convert from 32f bits to 8 bits
			yat::Timer t06;
			cv::Mat mat_morpho_8u;
			mat_morpho_32f.convertTo(mat_morpho_8u, CV_8UC1);
			//@YAT_INFO<<"[Elapsed time (mat_morpho_32f.convertTo): "<<t06.elapsed_msec()<< " (ms)]"<<std::endl;
			
			if(m_rixs_write_files_enabled)
			{		
				cv::imwrite(m_rixs_write_files_path+"\\mat_morpho_8u.png", mat_morpho_8u);
			}
			
			//get connected clusters
			yat::Timer t07;
			cv::Mat mat_labels;
			cv::Mat mat_stats;
			cv::Mat mat_centroids;			
			int nb_labels = cv::connectedComponentsWithStats(mat_morpho_8u, mat_labels, mat_stats, mat_centroids);
			//@YAT_INFO<<"[Elapsed time (connectedComponentsWithStats): "<<t07.elapsed_msec()<< " (ms)]"<<std::endl;
			
			
			//prepare spectrum data
			int nb_labels_valid = 0;
			
			{
				//need to clear spectrums at the beginning i.e the for first image  
				if(aSrc.frameNumber == 0 || m_reset_spectrums_at_each_frame_is_enabled)
				{
					yat::MutexLock scoped_lock(m_data_lock);	
					m_rixs_cluster_counter.clear();
					m_rixs_cluster_area.clear();
					m_rixs_cluster_sum.clear();
					m_rixs_centroid_x.clear();
					m_rixs_centroid_y.clear();
				}
			}
			
			yat::Timer t08;
			for(int i=0; i<mat_stats.rows;i++)
			{				
				int x = mat_stats.at<int>(i, cv::CC_STAT_LEFT);
				int y = mat_stats.at<int>(i, cv::CC_STAT_TOP);
				int w = mat_stats.at<int>(i, cv::CC_STAT_WIDTH);
				int h = mat_stats.at<int>(i, cv::CC_STAT_HEIGHT);
				int a = mat_stats.at<int>(i, cv::CC_STAT_AREA);
			
				//if Area is 0, Not Valid label NOP
				if(a < 1)
				{
					/*YAT_VERBOSE<<"Cluster  "<<i+1<<"\t: "<<"is Zero, This is a Not Valid Cluster !"<<std::endl;*/
					continue;
				}
				
				//if Area is greater than Max_Area, NOP
				if(a > m_rixs_max_area_cluster && m_rixs_max_area_cluster!=-1)
				{
					/*YAT_VERBOSE<<"Cluster  "<<i+1<<"\t: "<<"is Greater than Accepted Max Area, This is a Not Valid Cluster!"<<std::endl;*/
					continue;
				}
				
				//if Area is lower than Min_Area, NOP
				if(a < m_rixs_min_area_cluster && m_rixs_min_area_cluster!=-1)
				{
					/*YAT_VERBOSE<<"Cluster  "<<i+1<<"\t: "<<"is Lower than Accepted Min Area, This is a Not Valid Cluster!"<<std::endl;*/
					continue;
				}
				
				/*
				//Cluster is valid.
				YAT_INFO<<" "<<std::endl;
				YAT_INFO<<"Cluster  "<<i+1<<"\t: "<<"["<<x<<","<<y<<","<<w<<","<<h<<"]"<<std::endl;
				YAT_INFO<<"Area     "<<i+1<<"\t: "<<"["<<a<<"]"<<std::endl;
				*/
				
				//count only valid clusters/labels
				nb_labels_valid++;
				
				//if needed we draw rectangle bounding labels
				if(m_rixs_draw_cluster_is_enabled)
				{
					cv::Scalar color(m_rixs_label_colors[0],m_rixs_label_colors[1],m_rixs_label_colors[2]);					
					cv::Rect rect(x,y,w,h);
					cv::rectangle(mat_origin_draw, rect, color, 2);
				}

				//compute centroid of the cluster (x,y,w,h) from the image origin
				cv::Mat mat_origin_crop = mat_origin(cv::Rect(x, y, w, h));
				cv::Moments mo = cv::moments(mat_origin_crop);
				cv::Point2d centroid = cv::Point2d(x+mo.m10/mo.m00 , y+mo.m01/mo.m00);//we need centroid coordinates in double
				double sum = cv::sum(mat_origin_crop)[0];				
				
				//fill spectrum data
				{
				yat::MutexLock scoped_lock(m_data_lock);				
				m_rixs_cluster_area.push_back(a);
				m_rixs_cluster_sum.push_back(sum);
				m_rixs_centroid_x.push_back(centroid.x);
				m_rixs_centroid_y.push_back(centroid.y);
				}
				
				
				//if needed we draw CIRCLE on centroid
				if(m_rixs_draw_centroid_is_enabled)				
				{
					cv::Scalar color(m_rixs_centroid_colors[0],m_rixs_centroid_colors[1],m_rixs_centroid_colors[2]);	
					cv::circle(mat_origin_draw, centroid, 3, color, 2);	
				}
				/*
				YAT_INFO<<"centroid "<<i+1<<"\t: "<<"["<<centroid.x<<","<<centroid.y<<"]"<<std::endl;	
				YAT_INFO<<" "<<std::endl;					
				*/
			}
			//@YAT_INFO<<"[Elapsed time (all loop centroid): "<<t08 .elapsed_msec()<< " (ms)]"<<std::endl;
			

			////
			if(m_rixs_write_files_enabled)
			{				
				cv::imwrite(m_rixs_write_files_path+"\\mat_origin_draw.png", mat_origin_draw);
			}			
			
			//fill spectrum data
			{
			yat::MutexLock scoped_lock(m_data_lock);				
			m_rixs_cluster_counter.push_back(nb_labels_valid);
			}			
						
			//memcopy image draw into image origin 
			yat::Timer t09;
			memcpy(&((INPUT*) aDst.data())[0], &((INPUT*) mat_origin_draw.data)[0], aNbPixel*aDst.depth());
			//@YAT_INFO<<"[Elapsed time (memcpy): "<<t09.elapsed_msec()<< " (ms)]"<<std::endl;
			
			//for each cluster (label) , compute the centroid using the origin image
			YAT_INFO<< "[nb. valid labels : " << nb_labels_valid<<"]"<<std::endl;
			if(nb_labels_valid==0 && m_default_value_in_spectrums_enabled)
			{
				//fill spectrum data
				{
				yat::MutexLock scoped_lock(m_data_lock);				
				m_rixs_cluster_area.push_back(-1);
				m_rixs_cluster_sum.push_back(-1);
				m_rixs_centroid_x.push_back(-1);
				m_rixs_centroid_y.push_back(-1);
				}
			}
		

			return aDst;
		}
		
		
		//-----------------------------------------------
		//called by process method
		//-----------------------------------------------		
        template<class INPUT>
        void _compute(Data &aSrc, Data &aDst)
        {
            INPUT *aSrcPt = (INPUT*) aSrc.data();
            INPUT *aDstPt = (INPUT*) aDst.data();
            int aNbPixel = aSrc.dimensions[0] * aSrc.dimensions[1];
			if(m_operation_type == "RIXS")
			{
                aDst = rixs<INPUT>(aSrc);					
			}
			else
			{
				//NOP
                //m_operation_type == "NONE"
			}
        }

        std::string m_operation_type;
        double m_operation_value;
		std::vector<double> m_rixs_centroid_colors;		
		std::vector<double> m_rixs_centroid_x;
		std::vector<double> m_rixs_centroid_y;
		std::vector<long> m_rixs_cluster_counter;
		std::vector<long> m_rixs_cluster_area;
		std::vector<long> m_rixs_cluster_sum;
		std::vector<double> m_rixs_label_colors;
		bool m_reset_spectrums_at_each_frame_is_enabled;
		bool m_default_value_in_spectrums_enabled;
		bool m_rixs_draw_centroid_is_enabled;
		bool m_rixs_draw_cluster_is_enabled;
		int  m_rixs_max_area_cluster;
		int  m_rixs_min_area_cluster;
		bool m_rixs_write_files_enabled;
		std::string m_rixs_write_files_path;
		yat::Mutex m_data_lock;
		
    };

    /**
     * Class Description:
     * Lima Device Specific for post process image
 */

/*
 *	Device States Description:
*  Tango::INIT :
*  Tango::STANDBY :
*  Tango::FAULT :
*  Tango::RUNNING :
 */


    class Rixs : public Tango::Device_4Impl
    {
    public:
        //	Add your own data members here
        //-----------------------------------------


        //	Here is the Start of the automatic code generation part
        //-------------------------------------------------------------	
        /**
         *	@name attributes
         *	Attribute member data.
         */
        //@{
		Tango::DevString	*attr_version_read;
		Tango::DevString	*attr_operationType_read;
		Tango::DevString	attr_operationType_write;
		Tango::DevString	*attr_operationValue_read;
		Tango::DevString	attr_operationValue_write;
		Tango::DevLong	attr_minAreaCluster_write;
		Tango::DevLong	attr_maxAreaCluster_write;
		Tango::DevLong	*attr_nbClusterValid_read;
		Tango::DevBoolean	attr_drawClusterEnabled_write;
		Tango::DevBoolean	attr_drawCentroidEnabled_write;
		Tango::DevBoolean	attr_pngFilesEnabled_write;
		Tango::DevString	attr_pngFilesPath_write;
		Tango::DevString	*attr_operationsList_read;
		Tango::DevLong	*attr_clusterCounter_read;
		Tango::DevLong	*attr_clusterArea_read;
		Tango::DevLong	*attr_clusterSum_read;
		Tango::DevDouble	*attr_clusterCentroidX_read;
		Tango::DevDouble	*attr_clusterCentroidY_read;
//@}

        /**
         * @name Device properties
         * Device properties member data.
         */
        //@{
/**
 *	Memorize all operationType declared in the order to process the image.
 */
	vector<string>	memorizedOperationTypes;
/**
 *	Memorize all operationValue associated to the operationType declared in the order to process the image.
 */
	vector<string>	memorizedOperationValues;
/**
 *	Memorize all levels associated to the operationType declared in the order to process the image.
 */
	vector<long>	memorizedOperationLevels;
/**
 *	All Spectrum data wil be reset at each new Frame
 */
	Tango::DevBoolean	resetSpectrumsAtEachFrame;
/**
 *	Set default value (-1) in spectrums if there is 0 Valid Clusters
 */
	Tango::DevBoolean	defaultValueInSpectrumsIfEmpty;
/**
 *	RIXS : Define Color of centroids
 */
	string	rixsDrawCentroidColor;
/**
 *	RIXS : Define Color of Clusters
 */
	string	rixsDrawClusterColor;
//@}

        /**
         *	@name Device properties
         *	Device property member data.
         */
        //@{
        //@}

        /**@name Constructors
         * Miscellaneous constructors */
        //@{
        /**
         * Constructs a newly allocated Command object.
         *
         *	@param cl	Class.
         *	@param s 	Device Name
         */
        Rixs(Tango::DeviceClass *cl, string &s);
        /**
         * Constructs a newly allocated Command object.
         *
         *	@param cl	Class.
         *	@param s 	Device Name
         */
        Rixs(Tango::DeviceClass *cl, const char *s);
        /**
         * Constructs a newly allocated Command object.
         *
         *	@param cl	Class.
         *	@param s 	Device name
         *	@param d	Device description.
         */
        Rixs(Tango::DeviceClass *cl, const char *s, const char *d);
        //@}

        /**@name Destructor
         * Only one destructor is defined for this class */
        //@{

        /**
         * The object destructor.
         */
        ~Rixs()
        {
            delete_device();
        };
        /**
         *	will be called at device destruction or at init command.
         */
        void delete_device();
        //@}


        /**@name Miscellaneous methods */
        //@{
        /**
         *	Initialize the device
         */
        virtual void init_device();
        /**
         *	Always executed method before execution command method.
         */
        virtual void always_executed_hook();

//@}

/**
 * @name Rixs methods prototypes
 */

//@{
/**
 *	Hardware acquisition for attributes.
 */
	virtual void read_attr_hardware(vector<long> &attr_list);
/**
 *	Extract real attribute values for version acquisition result.
 */
	virtual void read_version(Tango::Attribute &attr);
/**
 *	Extract real attribute values for operationType acquisition result.
 */
	virtual void read_operationType(Tango::Attribute &attr);
/**
 *	Write operationType attribute values to hardware.
 */
	virtual void write_operationType(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for operationValue acquisition result.
 */
	virtual void read_operationValue(Tango::Attribute &attr);
/**
 *	Write operationValue attribute values to hardware.
 */
	virtual void write_operationValue(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for minAreaCluster acquisition result.
 */
	virtual void read_minAreaCluster(Tango::Attribute &attr);
/**
 *	Write minAreaCluster attribute values to hardware.
 */
	virtual void write_minAreaCluster(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for maxAreaCluster acquisition result.
 */
	virtual void read_maxAreaCluster(Tango::Attribute &attr);
/**
 *	Write maxAreaCluster attribute values to hardware.
 */
	virtual void write_maxAreaCluster(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for nbClusterValid acquisition result.
 */
	virtual void read_nbClusterValid(Tango::Attribute &attr);
/**
 *	Extract real attribute values for drawClusterEnabled acquisition result.
 */
	virtual void read_drawClusterEnabled(Tango::Attribute &attr);
/**
 *	Write drawClusterEnabled attribute values to hardware.
 */
	virtual void write_drawClusterEnabled(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for drawCentroidEnabled acquisition result.
 */
	virtual void read_drawCentroidEnabled(Tango::Attribute &attr);
/**
 *	Write drawCentroidEnabled attribute values to hardware.
 */
	virtual void write_drawCentroidEnabled(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for pngFilesEnabled acquisition result.
 */
	virtual void read_pngFilesEnabled(Tango::Attribute &attr);
/**
 *	Write pngFilesEnabled attribute values to hardware.
 */
	virtual void write_pngFilesEnabled(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for pngFilesPath acquisition result.
 */
	virtual void read_pngFilesPath(Tango::Attribute &attr);
/**
 *	Write pngFilesPath attribute values to hardware.
 */
	virtual void write_pngFilesPath(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for operationsList acquisition result.
 */
	virtual void read_operationsList(Tango::Attribute &attr);
/**
 *	Extract real attribute values for clusterCounter acquisition result.
 */
	virtual void read_clusterCounter(Tango::Attribute &attr);
/**
 *	Extract real attribute values for clusterArea acquisition result.
 */
	virtual void read_clusterArea(Tango::Attribute &attr);
/**
 *	Extract real attribute values for clusterSum acquisition result.
 */
	virtual void read_clusterSum(Tango::Attribute &attr);
/**
 *	Extract real attribute values for clusterCentroidX acquisition result.
 */
	virtual void read_clusterCentroidX(Tango::Attribute &attr);
/**
 *	Extract real attribute values for clusterCentroidY acquisition result.
 */
	virtual void read_clusterCentroidY(Tango::Attribute &attr);
/**
 *	Read/Write allowed for version attribute.
 */
	virtual bool is_version_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for operationType attribute.
 */
	virtual bool is_operationType_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for operationValue attribute.
 */
	virtual bool is_operationValue_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for minAreaCluster attribute.
 */
	virtual bool is_minAreaCluster_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for maxAreaCluster attribute.
 */
	virtual bool is_maxAreaCluster_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for nbClusterValid attribute.
 */
	virtual bool is_nbClusterValid_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for drawClusterEnabled attribute.
 */
	virtual bool is_drawClusterEnabled_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for drawCentroidEnabled attribute.
 */
	virtual bool is_drawCentroidEnabled_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for pngFilesEnabled attribute.
 */
	virtual bool is_pngFilesEnabled_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for pngFilesPath attribute.
 */
	virtual bool is_pngFilesPath_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for operationsList attribute.
 */
	virtual bool is_operationsList_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for clusterCounter attribute.
 */
	virtual bool is_clusterCounter_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for clusterArea attribute.
 */
	virtual bool is_clusterArea_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for clusterSum attribute.
 */
	virtual bool is_clusterSum_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for clusterCentroidX attribute.
 */
	virtual bool is_clusterCentroidX_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for clusterCentroidY attribute.
 */
	virtual bool is_clusterCentroidY_allowed(Tango::AttReqType type);
/**
 *	Execution allowed for AddOperation command.
 */
	virtual bool is_AddOperation_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for RemoveOperation command.
 */
	virtual bool is_RemoveOperation_allowed(const CORBA::Any &any);
/**
 * Add Lima external operation in order to transform the image acquired from the detector.<br>
 *	User must first define the operationType, operationValue attributes<br>
 *	argin will define the level of operation.
 *	@param	argin	
 *	@exception DevFailed
 */
	void	add_operation(Tango::DevLong);
/**
 * Remove a Lima external operation previously defined at the the level = argin.<br>
 *	@param	argin	
 *	@exception DevFailed
 */
	void	remove_operation(Tango::DevLong);

/**
 *	Read the device properties from database
 */
	 void get_device_property();
//@}

        //	Here is the end of the automatic code generation part
        //-------------------------------------------------------------	
        Tango::DevState dev_state();

        // return true if the device is correctly initialized in init_device

        bool is_device_initialized()
        {
            return m_is_device_initialized;
        };

        void add_external_operation(long level);
        void delete_external_operation(long level);
        void memorize_all_operations(void);

    protected:
        //	Add your own data members here
        //-----------------------------------------
        bool                                m_is_device_initialized;
        stringstream                        m_status_message;
        std::string                         m_operation_type;
        std::string                         m_operation_value;
        
        
        //map used to memorize all active operations
        struct operationParams
        {
            std::string opId;
            std::string operationType;
            std::string operationValue;
        };
        
        std::map<long, operationParams >    m_map_operations; 
        
        //LIMA objects
        lima::CtControl*                m_ct;
        std::vector<RixsTask*>        	m_rixs_tasks;
    };

} // namespace_ns

#endif	// _RIXS_H