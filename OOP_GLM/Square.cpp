#include "Square.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

unsigned int Square::vertexBuffer = 0;
unsigned int Square::indexBuffer  = 0;

Square::Square()
{
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 16, vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, indexArr, GL_STATIC_DRAW);

    // Pointer Data Posisi
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, 0);

    // Pointer Data Texture
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)(2 * sizeof(float)));
}

void Square::draw()
{
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void Square::setColor(glm::vec4 newColor)
{
	color = glm::vec4(newColor);
}

void Square::setColor(float red, float green, float blue, float alpha)
{
    setColor(glm::vec4(red, green, blue, alpha));
}

glm::vec4 Square::getColor()
{
    return color;
}

glm::mat4x4 Square::getTransformationMat4x4()
{
    return transformationMat4x4;
}

void Square::setTranslation(glm::vec3 newTranslation)
{
	transformationMat4x4 = glm::translate(transformationMat4x4, newTranslation);
}

void Square::setTranslation(float transX, float transY, float transZ)
{
    setTranslation(glm::vec3(transX, transY, transZ));
}

void Square::setRotation(float angle, glm::vec3 axis)
{
	transformationMat4x4 = glm::rotate(transformationMat4x4, angle, axis);
}

void Square::setScale(glm::vec3 newSclae)
{
	transformationMat4x4 = glm::scale(transformationMat4x4, newSclae);
}

void Square::setScale(float scaleX, float scaleY, float scaleZ)
{
    setScale(glm::vec3(scaleX, scaleY, scaleZ));
}
