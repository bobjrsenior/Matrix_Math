/*
 *   =====================================================================================
 * 
 *          Filename:  matrixMath.h
 *   
 *       Description:  The header file for a C implementation of OpenGL related matrix math.
 *   
 *           Version:  1.0
 *          Revision:  none
 *          Compiler:  gcc
 *   
 *            Author:  Bobjrsenior (BOB), bobjrsenior@gmail.com
 *      Organization:  
 *
 *   =====================================================================================  
 */

//Includes

//Define GLfloat if it isn't already
#ifndef GLfloat
#define GLfloat float
#endif

#include <math.h>
//Allows for allocating memory
#include <stdlib.h>




/*   ===  START_STRUCTS  ===   */

/*
 *   ===  STRUCT  ========================================================================
 *          Name:  mat4
 *   Description:  A struct used to emulate a 4x4 matrix
 *   ===================================================================================== 
 */
typedef struct mat4{
	GLfloat x[4];
	GLfloat y[4];
	GLfloat z[4];
	GLfloat w[4];
}mat4;

/*
 *   ===  STRUCT  ========================================================================
 *          Name:  vec4
 *   Description:  A struct used to emulate a vector with four parts (4x1 matrix)
 *   ===================================================================================== 
 */
typedef struct vec4{
	GLfloat arr[4];
}vec4;

/*
 *   ===  STRUCT  ========================================================================
 *          Name:  vec3
 *   Description:  A struct used to emulate a vector with three parts (3x1 matrix)
 *   ===================================================================================== 
 */
typedef struct vec3{
	GLfloat arr[3];
}vec3;

/*
 *   ===  STRUCT  =======================================================================
 *          Name:  vec3
 *   Description:  A struct used to emulate a vector with two parts (2x1 matrix)
 *   ===================================================================================== 
 */
typedef struct vec2{
	GLfloat arr[2];
}vec2;

/*   ===  END_STRUCTS  ===   */


/*   ===  START_MACROS  ===   */

/*
 *   ===  MACRO  =========================================================================
 *          Name:  IS_VEC_4_EQUAL
 *   Description:  Checks whether two given vec4 structs have the same values stored
 *   ===================================================================================== 
 */
#define IS_VEC_4_EQUAL(x,y) (((x->arr[0]) == (y->arr[0])) && ((x->arr[1]) == (y->arr[1])) && ((x->arr[2]) == (y->arr[2])) && ((x->arr[3]) == (y->arr[3])))

/*
 *   ===  MACRO  =========================================================================
 *          Name:  M_PI
 *   Description:  A constant PI value for calculations
 *   ===================================================================================== 
 */
#define M_PI 3.14159265358979323846

/*   ===  END_MACROS  ===   */

/*   ===  START_FUNCTIONS  ===   */

void getMat4(mat4* matrix);

mat4* getNewMat4();

vec4* makeNewVec4(const GLfloat x, const GLfloat y, const GLfloat z, const GLfloat w);

void setVec4(vec4* vector, const GLfloat x, const GLfloat y, const GLfloat z, const GLfloat w);

void copyVec4(vec4* vector, vec4* values);

void copyArrVec4(vec4* vector, const GLfloat* values);

vec3* makeNewVec3(const GLfloat x, const GLfloat y, const GLfloat z);

void setVec3(vec3* vector, const GLfloat x, const GLfloat y, const GLfloat z);

vec2* makeNewVec2(const GLfloat x, const GLfloat y);

void setVec2(vec2* vector, const GLfloat x, const GLfloat y);

void scaleMat4(mat4* matrix, const vec3* amount);

mat4* scaleNewMat4(const vec3* amount);

void translateMat4(mat4* matrix, vec3* amount);

mat4* translateNewMat4(vec3* amount);

void rotateMat4(mat4* matrix, const GLfloat degrees, const vec3* direction);

mat4* rotateNewMat4(const GLfloat degrees, const vec3* direction);

void lookAtMat4(mat4* matrix, const vec3* camera, const vec3* target, const vec3* upVector);

mat4* lookAtNewMat4(const vec3* camera, const vec3* target, const vec3* upVector);

void perspectiveMat4(mat4* matrix, const GLfloat fov, const GLfloat aspectRatio, const GLfloat nearClip, const GLfloat farClip);

mat4* perspectiveNewMat4(const GLfloat fov, const GLfloat aspectRatio, const GLfloat nearClip, const GLfloat farClip);

GLfloat degToRadSin(const GLfloat degrees);

GLfloat degToRadCos(const GLfloat degrees);

GLfloat degToRadTan(const GLfloat degrees);

void normalizeVec3(vec3* vector);

vec3* normalizeNewVec3(const vec3* vector);

GLfloat magnitudeVec3(const vec3* vector);

vec3* subNewVec3(const vec3* first, const vec3* second);

void addVec3(vec3* vector, const vec3* first, const vec3* second);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  addNewVec3
 *   Description:  Adds teo vec3 structs and stores the result in the given destination vec3
 *   ===================================================================================== 
 */
vec3* addNewVec3(const vec3* first, const vec3* second);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  dotVec3
 *   Description:  Computes the dot product of two vec3 structs and returns the result as a GLfloat
 *   ===================================================================================== 
 */
GLfloat dotVec3(const vec3* first, const vec3* second);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  crossVec3
 *   Description:  Computes the cross product of two vec3 structs and stores the result in the given destination vec3
 *   ===================================================================================== 
 */
void crossVec3(vec3* vector, const vec3* first, const vec3* second);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  crossNewVec3
 *   Description:  Computes the cross product of two vec3 structs and returns the result as a pointer to a new vec3
 *   ===================================================================================== 
 */
vec3* crossNewVec3(const vec3* first, const vec3* second);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  addMat4
 *   Description:  Adds two mat4 structs together and stores the result in the given destination vec3
 *   ===================================================================================== 
 */
void addMat4(mat4* matrix, const mat4* first, const mat4* second);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  addNewMat4
 *   Description:  Adds two mat4 structs and returns the result as a pointer to a new mat4
 *   ===================================================================================== 
 */
mat4* addNewMat4(const mat4* first, const mat4* second);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  multMat4
 *   Description:  Multiplies two mat4 structs and stores the result in the given destination mat4
 *   ===================================================================================== 
 */
void multMat4(mat4* matrix, const mat4* first, const mat4* second);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  multNewMat4
 *   Description:  Multiplies two mat4 structs and returns the result as a pointer to a new mat4
 *   ===================================================================================== 
 */
mat4* multNewMat4(const mat4* first, const mat4* second);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  multNewMat4Vec3
 *   Description:  Multiplies a mat4 and vec3 and stores the result in the given destination vec3
 *   ===================================================================================== 
 */
void multMat4Vec3(vec3* vector, const mat4* first, const vec3* second);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  multNewMat4Vec3
 *   Description:  Multiplies a mat4 and vec3 and returns the result as a pointer to a new vec3
 *   ===================================================================================== 
 */
vec3* multNewMat4Vec3(const mat4* first, const vec3* second);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  printMat4
 *   Description:  Prints all the values in a vec3
 *   ===================================================================================== 
 */
void printMat4(const mat4* matrix);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  printVec4
 *   Description:  Prints all the values in a vec4
 *   ===================================================================================== 
 */
void printVec3(const vec4* vector){

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  printVec3
 *   Description:  Prints all the values in a vec3
 *   ===================================================================================== 
 */
void printVec3(const vec3* matrix);

/*
 *   ===  FUNCTION  ======================================================================
 *          Name:  printVec2
 *   Description:  Prints all the values in a vec2
 *   ===================================================================================== 
 */
void printVec2(const vec2* vector);


/*   ===  END_FUNCTIONS  ===   */
