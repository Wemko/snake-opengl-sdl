#include "SimpleBox.h"

float SimpleBox::vertices[] = {
    -0.5f, -0.5f, -0.5f,                0.0f, 1.0f, 0.0f,
    0.5f, -0.5f, -0.5f,                 0.0f, 1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,                 0.0f, 1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,                 0.0f, 1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,                0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,                0.0f, 1.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,                0.0f, 0.0f, 1.0f,
    0.5f, -0.5f,  0.5f,                 0.0f, 0.0f, 1.0f,
    0.5f,  0.5f,  0.5f,                 0.0f, 0.0f, 1.0f,
    0.5f,  0.5f,  0.5f,                 0.0f, 0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,                0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,                0.0f, 0.0f, 1.0f,
     
    -0.5f,  0.5f,  0.5f,                1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,                1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,                1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,                1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,                1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,                1.0f, 0.0f, 0.0f,

    0.5f,  0.5f,  0.5f,                 0.0f, 1.0f, 1.0f,
    0.5f,  0.5f, -0.5f,                 0.0f, 1.0f, 1.0f,
    0.5f, -0.5f, -0.5f,                 0.0f, 1.0f, 1.0f,
    0.5f, -0.5f, -0.5f,                 0.0f, 1.0f, 1.0f,
    0.5f, -0.5f,  0.5f,                 0.0f, 1.0f, 1.0f,
    0.5f,  0.5f,  0.5f,                 0.0f, 1.0f, 1.0f,

    -0.5f, -0.5f, -0.5f,                1.0f, 1.0f, 0.0f,
    0.5f, -0.5f, -0.5f,                 1.0f, 1.0f, 0.0f,
    0.5f, -0.5f,  0.5f,                 1.0f, 1.0f, 0.0f,
    0.5f, -0.5f,  0.5f,                 1.0f, 1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,                1.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,                1.0f, 1.0f, 0.0f,

    -0.5f,  0.5f, -0.5f,                1.0f, 0.0f, 1.0f,
    0.5f,  0.5f, -0.5f,                 1.0f, 0.0f, 1.0f,
    0.5f,  0.5f,  0.5f,                 1.0f, 0.0f, 1.0f,
    0.5f,  0.5f,  0.5f,                 1.0f, 0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,                1.0f, 0.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,                1.0f, 0.0f, 1.0f
};

SimpleBox::SimpleBox() {
    if(&basicShader == NULL) {
        basicShader = BasicShader();
    } 

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
};

void SimpleBox::render() {
    basicShader.use();
    
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, getTransform());

    trans = glm::scale(trans, getScale());
    trans = glm::rotate(trans, ((float)SDL_GetTicks() / 1000) * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

    // TODO make a camera class that handles the view.
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));

    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.1f, 100.0f);

    unsigned int transformLoc = glGetUniformLocation(basicShader.ID, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

    unsigned int viewLoc = glGetUniformLocation(basicShader.ID, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    unsigned int projectionLoc = glGetUniformLocation(basicShader.ID, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}