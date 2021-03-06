/*
 * Publication: Semi-Procedural Textures Using Point Process Texture Basis Functions
 *              Computer Graphics Forum (EGSR 2020 special issue)
 * Authors: P. Guehl , R. AllEgre , J.-M. Dischler, B. Benes , and E. Galin
 *
 * Code author: Pascal Guehl
 */

/** 
 * @version 1.0
 */

#ifndef _SPT_BASIC_HVIEW_INTERFACE_H_
#define _SPT_BASIC_HVIEW_INTERFACE_H_

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/

// STL
#include <string>

/******************************************************************************
 ************************* DEFINE AND CONSTANT SECTION ************************
 ******************************************************************************/

/******************************************************************************
 ***************************** TYPE DEFINITION ********************************
 ******************************************************************************/

/******************************************************************************
 ******************************** CLASS USED **********************************
 ******************************************************************************/

namespace hview
{
	template< class T >
	class hvPict;
}

 /******************************************************************************
 ****************************** CLASS DEFINITION ******************************
 ******************************************************************************/

namespace Spt
{

 /**
  * @class SptBasicHviewInterface
  *
  * @brief The SptBasicHviewInterface class provides interface to the hview software texture synthesis api.
  *
  * SptBasicHviewInterface is an wrapper interaface the hview software texture synthesis api.
  */
class SptBasicHviewInterface
{
	/**************************************************************************
	 ***************************** PUBLIC SECTION *****************************
	 **************************************************************************/

public:

	/******************************* INNER TYPES *******************************/

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/
	
	/**
	 * Constructor
	 */
	SptBasicHviewInterface();

	/**
	 * Destructor
	 */
	virtual ~SptBasicHviewInterface();

	/**
	 * Initialize
	 */
	void initialize();

	/**
	 * Finalize
	 */
	void finalize();

	/**
	 * Launch the synthesis pipeline
	 */
	void execute();

	/**
	 * Semi-procedural texture synthesis parameters
	 */
	void setExemplarName( const char* pText );
	void setGUIDE( const float pValue );
	void setSTRENGTH( const float pValue );
	void setINITLEVEL( const int pValue );
	void setBLOCSIZE( const int pValue );
	void setINITERR( const float pValue );
	void setINDEXWEIGHT( const float pValue );

	/**************************************************************************
	 **************************** PROTECTED SECTION ***************************
	 **************************************************************************/

protected:

	/******************************* INNER TYPES *******************************/

	/******************************* ATTRIBUTES *******************************/

	/**
	 * Semi-procedural texture synthesis parameters
	 */

	std::string mExemplarName;
	
	float GUIDE;
	float STRENGTH;
	int INITLEVEL;
	int BLOCSIZE;
	float INITERR;
	float INDEXWEIGHT;

	int padding;

	/******************************** METHODS *********************************/

	void pptbfshader( float pixelzoom, hview::hvPict< float >& pptbfpi, hview::hvPict< float >& ppval );

	/**************************************************************************
	 ***************************** PRIVATE SECTION ****************************
	 **************************************************************************/

private:

	/******************************* INNER TYPES *******************************/

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/


}; // end of class SptBasicHviewInterface

} // end of namespace Spt

/******************************************************************************
 ******************************* INLINE SECTION ******************************
 ******************************************************************************/

#endif // _SPT_BASIC_HVIEW_INTERFACE_H_
