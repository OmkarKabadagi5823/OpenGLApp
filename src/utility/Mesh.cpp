#include <utility/Mesh.h>

Mesh::Mesh() :
	vertexArray(0),
	vertexBuffer(0),
	indexBuffer(0),
	indexCount(0)
{

}

Mesh::~Mesh()
{
	clearMesh();
}

void Mesh::createMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices)
{
	indexCount = numOfVertices;

	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0])*numOfIndices, indices, GL_STATIC_DRAW);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices)*numOfVertices, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::renderMesh()
{
	glBindVertexArray(vertexArray);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::clearMesh()
{
	if(indexBuffer != 0)
	{
		glDeleteBuffers(1, &indexBuffer);
		indexBuffer = 0;
	}

	if(vertexBuffer != 0)
	{
		glDeleteBuffers(1, &vertexBuffer);
		vertexBuffer = 0;
	}

	if(vertexArray != 0)
	{
		glDeleteBuffers(1, &vertexArray);
	}

	indexCount = 0;
}
