#ifndef INCLUDE_UTILITY_MESH_H_
#define INCLUDE_UTILITY_MESH_H_

#include <GL/glew.h>

class Mesh
{
public:
	Mesh();
	virtual ~Mesh();

	void createMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices);
	void renderMesh();
	void clearMesh();

private:
	GLuint vertexArray;
	GLuint vertexBuffer;
	GLuint indexBuffer;

	GLsizei indexCount;
};

#endif /* INCLUDE_UTILITY_MESH_H_ */
