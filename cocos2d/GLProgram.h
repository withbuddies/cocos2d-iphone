//
// Copyright 2011 Jeff Lamarche
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided
// that the following conditions are met:
//	1. Redistributions of source code must retain the above copyright notice, this list of conditions and
//		the following disclaimer.
//
//	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
//		and the following disclaimer in the documentation and/or other materials provided with the
//		distribution.
//
//	THIS SOFTWARE IS PROVIDED BY THE FREEBSD PROJECT ``AS IS'' AND ANY EXPRESS OR IMPLIED
//	WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
//	FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE FREEBSD PROJECT
//	OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
//	OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
//	AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//	NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
//	ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//
// Adapted for cocos2d http://www.cocos2d-iphone.org

#import <Foundation/Foundation.h>

#ifdef __IPHONE_OS_VERSION_MAX_ALLOWED
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#elif defined(__MAC_OS_X_VERSION_MAX_ALLOWED)
#import <OpenGL/gl.h>
#endif // __MAC_OS_X_VERSION_MAX_ALLOWED

enum {
	kCCAttribPosition,
	kCCAttribColor,
	kCCAttribTexCoords,
	
	kCCAttrib_MAX,
};

enum {
	kCCUniformPMatrix,
	kCCUniformMVMatrix,
	kCCUniformSampler,

	kCCUniform_MAX,
};

#define kCCShader_PositionTextureColor		@"ShaderPositionTextureColor"
#define kCCShader_PositionColor				@"ShaderPositionColor"
#define kCCShader_Position1Color			@"ShaderPosition1Color"
#define kCCShader_PositionTexture			@"ShaderPositionTexture"
#define kCCShader_PositionTextureA8Color	@"ShaderPositionTextureA8Color"

// uniform names
#define kCCUniformMVMatrix_s			"u_MVMatrix"
#define kCCUniformPMatrix_s				"u_PMatrix"
#define kCCUniformSampler_s				"u_texture"

// Attribute names
#define	kCCAttributeNameColor			@"a_color"
#define	kCCAttributeNamePosition		@"a_position"
#define	kCCAttributeNameTexCoord		@"a_texCoord"


/** GLProgram
 */
@interface GLProgram : NSObject 
{
@public
	GLuint          program_,
					vertShader_,
					fragShader_;
	
	GLint			uniforms_[kCCUniform_MAX];
}

- (id)initWithVertexShaderFilename:(NSString *)vShaderFilename 
            fragmentShaderFilename:(NSString *)fShaderFilename;
- (void)addAttribute:(NSString *)attributeName index:(GLuint)index;
- (BOOL)link;
- (void)use;
/* It will create 3 uniforms:
	- kCCUniformPMatrix
	- kCCUniformMVMatrix
	- kCCUniformSampler
 
 And it will bind "kCCUniformSampler" to 0

 @since v2.0.0
 */
- (void) updateUniforms;

- (NSString *)vertexShaderLog;
- (NSString *)fragmentShaderLog;
- (NSString *)programLog;
@end
