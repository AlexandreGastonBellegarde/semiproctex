////////////////////////////////////////////////////////////////////////////////
//
// COMPUTE SHADER
//
// Author(s): Anonymous
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Publication: By-Example Point Process Texture Basis Functions
// Authors: Anonymous
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// VERSION
////////////////////////////////////////////////////////////////////////////////

// OpenGL
#version 460

////////////////////////////////////////////////////////////////////////////////
// MACRO
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// INPUTS
////////////////////////////////////////////////////////////////////////////////

// Block size
// - 8x8 threads
layout( local_size_x = 8, local_size_y = 8 ) in;

////////////////////////////////////////////////////////////////////////////////
// OUTPUTS
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// UNIFORMS
////////////////////////////////////////////////////////////////////////////////

// PPTBF map
layout( r32f, binding = 0 ) uniform writeonly image2D uPPTBFThresholdImage;

// PPTBF map
layout( r32f, binding = 1 ) uniform readonly image2D uPPTBFImage;
 
// Binary structure map
uniform float uThreshold;

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
////////////////////////////////////////////////////////////////////////////////
 
////////////////////////////////////////////////////////////////////////////////
// Main Function
////////////////////////////////////////////////////////////////////////////////

/******************************************************************************
 * main
 ******************************************************************************/
void main()
{
	// Bounds check for unneeded threads
	ivec2 imSize = imageSize( uPPTBFImage );
	ivec2 gid = ivec2( gl_GlobalInvocationID.xy );
	if ( gid.x < imSize.x && gid.y < imSize.y )
	{
		// Fetch deformation (scale, rotation, strecth)
		float pptbf = imageLoad( uPPTBFImage, gid ).x;
		
		// Thresholding
		pptbf = step( uThreshold, pptbf );
		
		// Write deformed position
		imageStore( uPPTBFThresholdImage, gid/*coordinate*/, vec4( pptbf, 0.0, 0.0, 0.0 )/*data*/ );
	}
}
