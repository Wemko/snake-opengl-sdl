#pragma once

#include <glm/glm.hpp>

class GameObject {
    public:
        GameObject();

        glm::vec3 getTransform();
        void setTransform(glm::vec3 t);

        glm::vec3 getScale();
        void setScale(glm::vec3 s);

        glm::vec3 getRotation();
        void setRotation(glm::vec3 r);

    private:
        glm::vec3 transform;
        glm::vec3 scale;
        glm::vec3 rotation;
};