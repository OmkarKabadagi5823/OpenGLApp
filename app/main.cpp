#include <utility/Window.h>
#include <utility/Mesh.h>
#include <utility/Shader.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

Window win;
std::vector<Mesh*> meshes;
std::vector<Shader> shaders;

static const char* vertexShaderFilePath = "src/shaders/shader.vert";
static const char* fragmentShaderFilePath = "src/shaders/shader.frag";

void CreateObjects()
{
	GLfloat vertices[] = {
			-1.0f, -1.0f,  0.0f,
			 0.0f, -1.0f,  1.0f,
			 1.0f, -1.0f,  0.0f,
			 0.0f,  1.0f,  0.0f
	};

	unsigned int indices[] = {
			0, 3, 1,
			1, 3, 2,
			2, 3, 0,
			0, 1, 2
	};

	Mesh *obj1 = new Mesh();
	obj1->createMesh(vertices, indices, 12, 12);
	meshes.push_back(obj1);

	Mesh *obj2 = new Mesh();
	obj2->createMesh(vertices, indices, 12, 12);
	meshes.push_back(obj2);
}

void CreateShaders()
{
	Shader *shader1 = new Shader();
	shader1->createFromFiles(vertexShaderFilePath, fragmentShaderFilePath);
	shaders.push_back(*shader1);

}

int main()
{
	win = Window(800, 600);
	win.init();

	CreateObjects();
	CreateShaders();

	GLuint uniformModel=0, uniformProjection=0;
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (GLfloat)win.getBufferWidth()/(GLfloat)win.getBufferHeight(), 0.1f, 100.0f);

	while(!win.getShouldClose())
	{
		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shaders[0].useShader();
		uniformModel = shaders[0].getModelLocation();
		uniformProjection = shaders[0].getProjectionLocation();

		glm::mat4 model(1.0f);

		model = glm::translate(model, glm::vec3(0.5f, 0.0f, -2.5f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshes[0]->renderMesh();

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-0.5f, 0.0f, -2.5f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshes[1]->renderMesh();

		glUseProgram(0);

		win.swapBuffers();
	}

	return 0;
}
